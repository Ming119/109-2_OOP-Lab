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

		isJumping = false;
		ignoreHorizontal = false;

		isMovingLeft = isMovingRight = isLookingUp = isLookingDown = false;

		refBrick = nullptr;

		pos.x = 100;
		pos.y = SIZE_Y / 3;

		debug.LoadBitmap(IDB_CORNER);
	}

	Actor::~Actor() { }

	POINT Actor::Moving(vector<Brick*> b) {
		POINT dt = POINT();
		double theta = 0;

		UpdateRefBrick(b);
		// TRACE("ref %d\n", refBrick->Angle());

		// x-axis
		// dx = v_0 dt + 1/2 a dt^(2)
		if (isMovingLeft) {
			moving.OnMove();
			if (abs(velocity.x) < maxVelocity) velocity.x -= acceleration;

		}
		else if (isMovingRight) {
			moving.OnMove();
			if (abs(velocity.x) < maxVelocity) velocity.x += acceleration;

		}
		else {
			// Friction Drug: F_d = 1/2 pv^(2) C_d A
			velocity.x = (long)(velocity.x * friction);
		}


		// y-axis
		// h = 1/2gt
		velocity.y += gravity / 2;
		if (refBrick != nullptr) {
			
			// DEBUG
			if (this->character == 0)
				TRACE("\n\tid: %d\ttheta: %d\t(x, y): (%d, %d)\n", refBrick->ID(), refBrick->Angle(), refBrick->Left(), refBrick->Top());
			
			if (refBrick->Angle() == 0) {
				if (IsJumping()) velocity.y -= jumpStrength;
				
				else if (this->Buttom() == refBrick->Top())
					velocity.y = 0;
				
				else if (this->Buttom() + gravity > refBrick->Top())
					velocity.y = refBrick->Top() - this->Buttom();
				
			} else {
				theta = (double)refBrick->Angle() * M_PI / 180;
				velocity.y = 0;
				//velocity.y = (long)(velocity.x * std::tan(theta));

				// TRACE("\n\ttheta: %d\n\trad: %f\n\tsin: %f\n\tcos: %f\n\ttan: %f\n", refBrick->Angle(), theta, std::sin(theta), std::cos(theta), std::tan(theta));	
			}
		}
		else {
			TRACE("\n\tNULL REFBRICK\n");
		}
		if (velocity.x != 0) moving.OnMove();
		

		

		//dt.x = velocity.x;
		//dt.y = (long)(velocity.x * std::tan(theta));

		// if (angle = 0) {
		// dt.x = (long)(velocity.x * std::cos(theta));
		// dt.y = -(long)(velocity.x * std::sin(theta));

			dt.x = (long)(velocity.x * std::cos(theta) + velocity.y * std::sin(theta));
			dt.y = (long)(velocity.y * std::cos(theta) - velocity.x * std::sin(theta));
		// }
		// else {
		//	dt.x = velocity.x;
		//	dt.y = (long)(velocity.x * std::tan(theta));
		// }

		return dt;
	}

	void Actor::LookingForRefBrick(vector<Brick*> bricks) {
		const int bs = bricks.size();

		vector<Brick*> tmpb;
		for (int b = 0; b < bs; b++) {
			if (this->Right() > bricks.at(b)->Left() &&
				this->Left() < bricks.at(b)->Right() &&
				bricks.at(b)->Property() == OBSTACLE) {
				if (this->Top() <= bricks.at(b)->Buttom())
					tmpb.push_back(bricks.at(b));
			}
		}

		std::sort(tmpb.begin(), tmpb.end(), [](Brick* b1, Brick* b2) -> bool { return b1->Top() < b2->Top(); });
		if (tmpb.size())
			refBrick = tmpb.at(0);
	}

	void Actor::checkLeavingBrick() {

		if (refBrick != nullptr) {
			if (pt.x < refBrick->Left() || pt.x > refBrick->Right() ||
				pt.y < refBrick->Top() || pt.y > refBrick->Buttom())
				refBrick = nullptr;
		}
	}

	void Actor::UpdateRefBrick(vector<Brick*> bricks) {
		checkLeavingBrick();

		const int bs = bricks.size();
		boolean ang = false;

		if (refBrick == nullptr) {
			// LookingForRefBrick(bricks);
			pt.x = (this->Left() + this->Right()) / 2;
			pt.y = this->Buttom();

		}
		else {
			const int angle = refBrick->Angle();
			if (angle != 0) ang = true;

			if (343 < angle && angle < 17) {
				pt.x = (this->Left() + this->Right()) / 2;
				pt.y = this->Buttom();
			}

			if (17 <= angle && angle <= 75) {
				pt.x = this->Right();
				pt.y = this->Buttom();
			}

			if (75 < angle && angle < 105) {
				pt.x = this->Right();
				pt.y = (this->Top() + this->Buttom()) / 2;
			}

			if (105 <= angle && angle <= 163) {
				pt.x = this->Right();
				pt.y = this->Top();
			}

			if (163 < angle && angle < 97) {
				pt.x = (this->Left() + this->Right()) / 2;
				pt.y = this->Top();
			}

			if (197 <= angle && angle <= 255) {
				pt.x = this->Left();
				pt.y = this->Top();
			}

			if (255 < angle && angle < 285) {
				pt.x = this->Left();
				pt.y = (this->Top() + this->Buttom()) / 2;
			}

			if (285 <= angle && angle <= 343) {
				pt.x = this->Left();
				pt.y = this->Buttom();
			}
		}


		debug.SetTopLeft(pt.x, pt.y);

		for (int b = 0; b < bs; b++) {
			if (bricks.at(b)->Left() < pt.x && pt.x < bricks.at(b)->Right() &&
				bricks.at(b)->Top() < pt.y && pt.y < bricks.at(b)->Buttom() &&
				bricks.at(b)->Property() != PASSABLE) {
				if (ang && bricks.at(b)->Angle() == 0) continue;
				refBrick = bricks.at(b);
				break;
			}
		}
	}

	int Actor::Top() { return idle.Top(); }

	int Actor::Left() { return idle.Left(); }

	int Actor::Buttom() { return Top() + Height(); }

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

	void Actor::SetIsLookingUp(bool m) { isLookingUp = m; }

	void Actor::SetIsLookingDown(bool m) { isLookingDown = m; }

	void Actor::SetIsJumping(bool m) { isJumping = m; }

	bool Actor::IsJumping() { return isJumping; }

	void Actor::CameraMove(POINT d) {
		pos.x -= d.x;
		pos.y -= d.y;
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

	void Sonic::OnMove(vector<Brick*> b, int a) {
		if (character == static_cast<int>(CHARACTERS::SONIC)) delta = Moving(b);

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

	void Miles::OnMove(vector<Brick*> b, int a) {
		if (character == static_cast<int>(CHARACTERS::MILES))delta = Moving(b);

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

	void Knuckles::OnMove(vector<Brick*> b, int a) {
		if (character == static_cast<int>(CHARACTERS::KNUCKLES)) delta = Moving(b);

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