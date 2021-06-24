#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <algorithm>
#include <cmath>
#include "audio.h"
#include "gamelib.h"
#include "Actor.h"



namespace game_framework {
	Actor::Actor() {
		velocity = delta = POINT();

		isJumping = isRotating = false;

		isMovingLeft = isMovingRight = isLookingUp = isLookingDown = false;
		isMovingDown = isMovingUp = false;

		refBrick = nullptr;
		debugMODE = false;

		turn = 0;
		pos.x = 100;
		pos.y = SIZE_Y / 3;

		debug.LoadBitmap(IDB_CORNER);
	}

	Actor::~Actor() { }

	POINT Actor::debugMoveing() {
		POINT dt = POINT();

		if (isMovingLeft)
			dt.x = -50;
		if (isMovingRight)
			dt.x = 50;
		if (isMovingUp)
			dt.y = -50;
		if (isMovingDown)
			dt.y = 50;

		return dt;
	}

	POINT Actor::Moving(vector<Brick*> b, vector<Enemy*> e) {
		CheckEnemyCollision(e);

		POINT dt = POINT();
		double theta = 0;

		UpdateRefBrick(b);
		// x-axis
		// dx = v_0 dt + 1/2 a dt^(2)
		if (isMovingLeft) {
			moving.OnMove();
			if (abs(velocity.x) < maxVelocity) velocity.x -= acceleration;

		} else if (isMovingRight) {
			moving.OnMove();
			if (abs(velocity.x) < maxVelocity) velocity.x += acceleration;

		} else {
			// Friction Drug: F_d = 1/2 pv^(2) C_d A
			velocity.x = (long)(velocity.x * friction);
		}

		LookingForRefBrick(b);
		
		if (turn == 1) {		// Right Up
			dt.x = abs(velocity.x);
			dt.y = -abs(velocity.x);
		} else if (turn == 2) {	// Left Up
			dt.x = -abs(velocity.x);
			dt.y = -abs(velocity.x);
		}
		else if (turn == 3) {	// Left Down
			dt.x = -abs(velocity.x);
			dt.y = abs(velocity.x);
		}
		else if (turn == 4) {	// Right Down
			dt.x = abs(velocity.x);
			dt.y = abs(velocity.x);
		}
		else if (turn == 5) {	// Right
			dt.x = abs(velocity.x);
			dt.y = 0;
		}
		else if (turn == 6) {	// Left
			dt.x = -abs(velocity.x);
			dt.y = 0;
		}
		else if (turn == 7) {	// Up
			dt.x = 0;
			dt.y = -abs(velocity.x);
		}
		else if (turn == 8) {	// Down
			dt.x = 0;
			dt.y = abs(velocity.x);
		}
		else if (turn == 0) {	// Leave

			HandleLeftRightCollision(b);

			// y-axis
			// h = 1/2gt
			velocity.y += gravity / 2;
			if (refBrick != nullptr) {
				if (character == 0) {
					TRACE("RefBrick: (x, y): (%d, %d)\n", refBrick->Top(), refBrick->Left());
					TRACE("bottom: %d, %d\n", bottom.x, bottom.y);
				}
				if (refBrick->Angle() == 0) {
					if (IsJumping() && refBrick != nullptr) velocity.y -= jumpStrength;

					else if (this->Bottom() == refBrick->Top())
						velocity.y = 0;

					else if (this->Bottom() + gravity > refBrick->Top())
						velocity.y = refBrick->Top() - this->Bottom();

				}
				else {
					theta = (double)refBrick->Angle() * M_PI / 180;
					velocity.y = 0;
				}

				dt.x = (long)(velocity.x * std::cos(theta) + velocity.y * std::sin(theta));
				dt.y = (long)(velocity.y * std::cos(theta) - velocity.x * std::sin(theta));
			}
			else {
				TRACE("NULL RefBrick\n");

				dt.x = velocity.x;
				dt.y = velocity.y;
			}
		}

		if (dt.x != 0) moving.OnMove();
		
		return dt;
	}

	void Actor::LookingForRefBrick(vector<Brick*> bricks) {
		POINT center;
		center.x = (Left() + Right()) / 2;
		center.y = (Top() + Bottom()) / 2;

		const int bs = bricks.size();
		for (int b = 0; b < bs; b++) {
			if (bricks.at(b)->ID() < 100) continue;
			if (bricks.at(b)->Left() < Right() && Left() < bricks.at(b)->Right() &&
				bricks.at(b)->Top() < Bottom() && Top() < bricks.at(b)->Bottom()) {
				switch (bricks.at(b)->ID()) {
				case 101:	// Right Up
					if (turn != 1 && bricks.at(b)->Left() < center.x) turn = 1;
					if (turn == 1 && center.x < bricks.at(b)->Right()) turn = 0;
					break;

				case 102:	// Left Up
					turn = 2;
					break;

				case 103:	// Left Down
					turn = 3;
					break;

				case 104:	//Right Down
					turn = 4;
					break;
				
				case 105:	// Right
					turn = 5;
					break;

				case 106:	// Left
					turn = 6;
					break;

				case 107:	// Up
					turn = 7;
					break;

				case 108:	// Down
					turn = 8;
					break;

				case 109:
					CGame::Instance()->SetFinish(true);
					break;

				case 110:	// Leave
					turn = 0;
					break;
				}
			}
		}
	}

	void Actor::CheckEnemyCollision(vector<Enemy*> e) {
		const int es = e.size();

		for (int i = 0; i < es; i++) {
			POINT em = POINT();
			em.x = (e.at(i)->Left() + e.at(i)->Right()) / 2;
			em.y = (e.at(i)->Top() + e.at(i)->Bottom()) / 2;

			if (Left() < em.x && em.x < Right()&&
				Top() < em.y && em.y < Bottom()) {
				CGame::Instance()->SetDead(true);
			}
		}
	}

	void Actor::checkLeavingBrick() {

		if (refBrick != nullptr) {
			if (bottom.x < refBrick->Left() || bottom.x > refBrick->Right() ||
				bottom.y < refBrick->Top() || bottom.y > refBrick->Bottom())
				refBrick = nullptr;
		}
	}

	void Actor::UpdateRefBrick(vector<Brick*> bricks) {
		checkLeavingBrick();

		const int bs = bricks.size();
		boolean ang = false;

		if (refBrick == nullptr) {
				bottom.x = (this->Left() + this->Right()) / 2;
				bottom.y = this->Bottom();
		}
		else {
			angle = refBrick->Angle();
			if (angle != 0) ang = true;

			if (343 < angle && angle < 17) {
				bottom.x = (this->Left() + this->Right()) / 2;
				bottom.y = this->Bottom();
			}

			if (17 <= angle && angle <= 75) {
				bottom.x = this->Right();
				bottom.y = this->Bottom();
			}

			if (75 < angle && angle < 105) {
				bottom.x = this->Right();
				bottom.y = (this->Top() + this->Bottom()) / 2;
			}

			if (105 <= angle && angle <= 163) {
				bottom.x = this->Right();
				bottom.y = this->Top();
			}

			if (163 < angle && angle < 97) {
				bottom.x = (this->Left() + this->Right()) / 2;
				bottom.y = this->Top();
			}

			if (197 <= angle && angle <= 255) {
				bottom.x = this->Left();
				bottom.y = this->Top();
			}

			if (255 < angle && angle < 285) {
				bottom.x = this->Left();
				bottom.y = (this->Top() + this->Bottom()) / 2;
			}

			if (285 <= angle && angle <= 343) {
				bottom.x = this->Left();
				bottom.y = this->Bottom();
			}
		}


		debug.SetTopLeft(bottom.x, bottom.y);

		for (int b = 0; b < bs; b++) {
			if (bricks.at(b)->Left() < bottom.x && bottom.x < bricks.at(b)->Right() &&
				bricks.at(b)->Top() < bottom.y && bottom.y < bricks.at(b)->Bottom() &&
				bricks.at(b)->Property() != PASSABLE) {
				if (ang && bricks.at(b)->Angle() == 0) continue;
				refBrick = bricks.at(b);
				break;
			}
		}

	}

	void Actor::HandleLeftRightCollision(vector<Brick*> b) {
		if (angle != 0) return;

		const int bs = b.size();
		for (int i = 0; i < bs; i++) {
			if (b.at(i)->Angle() != 0 || b.at(i)->Property() != OBSTACLE) continue;

			POINT p = POINT();
			p.y = (this->Top() + this->Bottom()) / 2;
			if (Left() < b.at(i)->Right() && Right() > b.at(i)->Left() &&
				b.at(i)->Top() < p.y && Top() < b.at(i)->Bottom()) {
				velocity.x = -velocity.x;
				break;
			}
		}
	}

	int Actor::Top() { return idle.Top(); }

	int Actor::Left() { return idle.Left(); }

	int Actor::Bottom() { return Top() + Height(); }

	int Actor::Right() { return Left() + Width(); }

	int Actor::Width() { return idle.Width() * DEFAULT_SCALE; }

	int Actor::Height() { return idle.Height() * DEFAULT_SCALE; }

	int Actor::Character() { return character; }

	POINT Actor::getDelta() { return delta; }

	void Actor::setTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;
	}

	void Actor::setTopLeft(POINT xy) { pos = xy; }

	void Actor::SetMoveLeft(bool m) { isMovingLeft = m; }

	void Actor::SetMoveRight(bool m) { isMovingRight = m; }

	void Actor::SetMoveUp(bool m) { isMovingUp = m; }

	void Actor::SetMoveDown(bool m) { isMovingDown = m; }

	void Actor::SetIsLookingUp(bool m) { isLookingUp = m; }

	void Actor::SetIsLookingDown(bool m) { isLookingDown = m; }

	void Actor::SetIsJumping(bool m) { isJumping = m; }

	bool Actor::IsJumping() { return isJumping; }

	void Actor::CameraMove(POINT d) {
		pos.x -= d.x;
		pos.y -= d.y;
	}

	void Actor::SetDebug(bool flag) {
		this->debugMODE = flag;
	}

	// Sonic
	Sonic::Sonic() : Actor::Actor() {
		pos.y += 5 * DEFAULT_SCALE;
		character = static_cast<int>(CHARACTERS::SONIC);
	}

	Sonic::~Sonic() { }

	void Sonic::OnInit() {
		idle.AddBitmap(ACTOR_1_STAND_1);
		idle.SetTopLeft(pos.x, pos.y);

		//lookUp.AddBitmap(ACTOR_1_LOOKUP_1);
		//lookUp.AddBitmap(ACTOR_1_LOOKUP_2);
		lookUp.AddBitmap(ACTOR_1_LOOKUP_3);
		lookUp.AddBitmap(ACTOR_1_LOOKUP_4);
		lookUp.SetDelayCount(5);
		lookUp.SetTopLeft(pos.x, pos.y);

		lookDown.AddBitmap(ACTOR_1_LOOKDOWN_1);
		lookDown.AddBitmap(ACTOR_1_LOOKDOWN_2);
		lookDown.SetDelayCount(3);
		lookDown.SetTopLeft(pos.x, pos.y);

		moving.AddBitmap(ACTOR_1_RUN_1);
		moving.AddBitmap(ACTOR_1_RUN_2);
		moving.AddBitmap(ACTOR_1_RUN_3);
		moving.AddBitmap(ACTOR_1_RUN_4);
		moving.AddBitmap(ACTOR_1_RUN_5);
		moving.AddBitmap(ACTOR_1_RUN_6);
		moving.AddBitmap(ACTOR_1_RUN_7);
		moving.SetDelayCount(3);
		moving.SetTopLeft(pos.x, pos.y);

		jumping.AddBitmap(ACTOR_1_ROLL_1);
		jumping.AddBitmap(ACTOR_1_ROLL_2);
		jumping.AddBitmap(ACTOR_1_ROLL_3);
		jumping.AddBitmap(ACTOR_1_ROLL_4);
		jumping.SetDelayCount(3);
		jumping.SetTopLeft(pos.x, pos.y);

		//acceleration = 250;
		maxSpeed = 700;
		jumpStrength = 5;
	}

	void Sonic::OnMove(vector<Brick*> b, vector<Enemy*> e, int a) {
		if (character == static_cast<int>(CHARACTERS::SONIC)) {
			if (debugMODE) delta = debugMoveing();
			else delta = Moving(b, e);
		}

		if (isLookingUp) {
			if (!lookUp.IsFinalBitmap())
				lookUp.OnMove();
		}
		else if (isLookingDown) {
			if (!lookDown.IsFinalBitmap())
				lookDown.OnMove();
		}
		else if (isJumping) {
			velocity.y -= 10;
			jumping.OnMove();
		}
		else {
			lookUp.Reset();
			lookDown.Reset();
			jumping.Reset();
			idle.OnMove();
		}
	}

	void Sonic::OnShow() {
		idle.SetTopLeft(pos.x, pos.y);
		lookUp.SetTopLeft(pos.x, pos.y);
		lookDown.SetTopLeft(pos.x, pos.y);
		moving.SetTopLeft(pos.x, pos.y);
		jumping.SetTopLeft(pos.x, pos.y);

		if (isMovingLeft || isMovingRight)
			moving.OnShow();
		else if (isLookingUp) {
			lookUp.OnShow();
		}
		else if (isLookingDown) {
			lookDown.OnShow();
		}
		else if (isJumping) {
			jumping.OnShow();
		}
		else
			idle.OnShow();

		debug.ShowBitmap();
	}



	// Miles
	Miles::Miles() : Actor::Actor() {
		character = static_cast<int>(CHARACTERS::MILES);
	}

	Miles::~Miles() { }

	void Miles::OnInit() {
		pos.x -= 50;
		idle.AddBitmap(ACTOR_2_STAND_1);
		idle.AddBitmap(ACTOR_2_STAND_2);
		idle.AddBitmap(ACTOR_2_STAND_3);
		idle.AddBitmap(ACTOR_2_STAND_4);
		idle.SetTopLeft(pos.x, pos.y);

		//lookUp.AddBitmap(ACTOR_1_LOOKUP_1);
		//lookUp.AddBitmap(ACTOR_1_LOOKUP_2);
		lookUp.AddBitmap(ACTOR_2_LOOKUP_1);
		lookUp.SetDelayCount(5);
		lookUp.SetTopLeft(pos.x, pos.y);

		lookDown.AddBitmap(ACTOR_2_LOOKDOWN_1);

		lookDown.SetDelayCount(3);
		lookDown.SetTopLeft(pos.x, pos.y);

		moving.AddBitmap(ACTOR_2_RUN_1);
		moving.AddBitmap(ACTOR_2_RUN_2);
		moving.AddBitmap(ACTOR_2_RUN_3);
		moving.AddBitmap(ACTOR_2_RUN_4);
		moving.AddBitmap(ACTOR_2_RUN_5);
		moving.SetDelayCount(3);
		moving.SetTopLeft(pos.x, pos.y);

		jumping.AddBitmap(ACTOR_2_ROLL_1);
		jumping.AddBitmap(ACTOR_2_ROLL_2);
		jumping.AddBitmap(ACTOR_2_ROLL_3);
		jumping.AddBitmap(ACTOR_2_ROLL_4);
		jumping.SetDelayCount(3);
		jumping.SetTopLeft(pos.x, pos.y);


		//acceleration = 200;
		maxSpeed = 600;
		jumpStrength = 5;

	}

	void Miles::OnMove(vector<Brick*> b, vector<Enemy*> e, int a) {
		if (character == static_cast<int>(CHARACTERS::MILES)) {
			if (debugMODE) delta = debugMoveing();
			else delta = Moving(b, e);
		}

		if (isLookingUp) {
			if (!lookUp.IsFinalBitmap())
				lookUp.OnMove();
		}
		else if (isLookingDown) {
			if (!lookDown.IsFinalBitmap())
				lookDown.OnMove();
		}
		else if (isJumping) {
			velocity.y -= 10;
			jumping.OnMove();
		}
		else {
			lookUp.Reset();
			lookDown.Reset();
			jumping.Reset();
			idle.OnMove();
		}
	}

	void Miles::OnShow() {
		idle.SetTopLeft(pos.x, pos.y);
		lookUp.SetTopLeft(pos.x, pos.y);
		lookDown.SetTopLeft(pos.x, pos.y);
		moving.SetTopLeft(pos.x, pos.y);
		jumping.SetTopLeft(pos.x, pos.y);

		if (isMovingLeft || isMovingRight)
			moving.OnShow();
		else if (isLookingUp) {
			lookUp.OnShow();
		}
		else if (isLookingDown) {
			lookDown.OnShow();
		}
		else if (isJumping) {
			jumping.OnShow();
		}
		else
			idle.OnShow();
	}



	//Knuckles
	Knuckles::Knuckles() : Actor::Actor() {
		character = static_cast<int>(CHARACTERS::KNUCKLES);
	}
	Knuckles::~Knuckles() {	}

	void Knuckles::OnInit() {
		pos.x -= 100;
		idle.AddBitmap(ACTOR_3_STAND_1);
		idle.SetTopLeft(pos.x, pos.y);

		//lookUp.AddBitmap(ACTOR_1_LOOKUP_1);
		//lookUp.AddBitmap(ACTOR_1_LOOKUP_2);
		lookUp.AddBitmap(ACTOR_3_LOOKUP_1);
		lookUp.AddBitmap(ACTOR_3_LOOKUP_2);
		lookUp.SetDelayCount(5);
		lookUp.SetTopLeft(pos.x, pos.y);

		lookDown.AddBitmap(ACTOR_3_LOOKDOWN_1);
		lookDown.AddBitmap(ACTOR_3_LOOKDOWN_2);
		lookDown.SetDelayCount(3);
		lookDown.SetTopLeft(pos.x, pos.y);

		moving.AddBitmap(ACTOR_3_RUN_1);
		moving.AddBitmap(ACTOR_3_RUN_2);
		moving.AddBitmap(ACTOR_3_RUN_3);
		moving.AddBitmap(ACTOR_3_RUN_4);
		moving.AddBitmap(ACTOR_3_RUN_5);
		moving.AddBitmap(ACTOR_3_RUN_6);
		moving.AddBitmap(ACTOR_3_RUN_7);
		moving.SetDelayCount(3);
		moving.SetTopLeft(pos.x, pos.y);

		jumping.AddBitmap(ACTOR_3_ROLL_1);
		jumping.AddBitmap(ACTOR_3_ROLL_2);
		jumping.AddBitmap(ACTOR_3_ROLL_3);
		jumping.AddBitmap(ACTOR_3_ROLL_4);
		jumping.SetDelayCount(3);
		jumping.SetTopLeft(pos.x, pos.y);

		//acceleration = 200;
		maxSpeed = 600;
		jumpStrength = 5;

	}

	void Knuckles::OnMove(vector<Brick*> b, vector<Enemy*> e, int a) {
		if (character == static_cast<int>(CHARACTERS::KNUCKLES)) {
			if (debugMODE) delta = debugMoveing();
			else delta = Moving(b, e);
		}

		if (isLookingUp) {
			if (!lookUp.IsFinalBitmap())
				lookUp.OnMove();
		}
		else if (isLookingDown) {
			if (!lookDown.IsFinalBitmap())
				lookDown.OnMove();
		}
		else if (isJumping) {
			velocity.y -= 10;
			jumping.OnMove();
		}
		else {
			lookUp.Reset();
			lookDown.Reset();
			jumping.Reset();
			idle.OnMove();
		}
	}

	void Knuckles::OnShow() {
		idle.SetTopLeft(pos.x, pos.y);
		lookUp.SetTopLeft(pos.x, pos.y);
		lookDown.SetTopLeft(pos.x, pos.y);
		moving.SetTopLeft(pos.x, pos.y);
		jumping.SetTopLeft(pos.x, pos.y);

		if (isMovingLeft || isMovingRight)
			moving.OnShow();
		else if (isLookingUp) {
			lookUp.OnShow();
		}
		else if (isLookingDown) {
			lookDown.OnShow();
		}
		else if (isJumping) {
			jumping.OnShow();
		}
		else
			idle.OnShow();
	}

}