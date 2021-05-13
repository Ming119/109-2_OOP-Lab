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
		angle = 0;
		velocity = acceleration = delta= POINT();
		jumpStrength = 0;

		isJumping = false;
		ignoreHorizontal = false;

		isMovingLeft = isMovingRight = isLookingUp = isLookingDown = false;

		refBrick = nullptr;

		pos.x = 100;
		pos.y = SIZE_Y / 3;
	}

	Actor::~Actor() { }

	POINT Actor::Moving(vector<Brick*> b) {
		// checkLevingRefBrick();
		LookingForRefBrick(b);
		//TRACE("RefBrick:\n\tID: %d\n\tAngle: %d\n\tProperty: %d\n", refBrick->ID(), refBrick->Angle(), refBrick->Property());
		


		// x-axis
		// dx = v_0 dt + 1/2 a dt^(2)

		if (isMovingLeft) {
			moving.OnMove();
			if (abs(acceleration.x) < maxAcceleration) acceleration.x--;
			if (abs(velocity.x) < maxVelocity) velocity.x += acceleration.x/2;

		} else if (isMovingRight) {
			moving.OnMove();
			if (abs(acceleration.x) < maxAcceleration) acceleration.x++;
			if (abs(velocity.x) < maxVelocity) velocity.x += acceleration.x/2;

		} else {
			if (abs(acceleration.x) > 0 && acceleration.x > 0) acceleration.x--;
			else if (abs(acceleration.x) > 0 && acceleration.x < 0) acceleration.x++;


			// Friction Drug: F_d = 1/2 pv^(2) C_d A
			velocity.x = (long)(velocity.x * friction);
		}
			

		// y-axis
		if (refBrick != nullptr) {
			if (refBrick->Angle() == 0) {
				if (this->Buttom() == refBrick->Top())
					velocity.y = 0;
				else if (this->Buttom() + gravity > refBrick->Top()) 
					velocity.y = refBrick->Top() - this->Buttom();
				else 
					velocity.y += gravity/2;	// g = 1/2gt
			} else {

				double theta = (double)refBrick->Angle() * M_PI / 180;
				
				TRACE("\n\ttheta: %d\n\trad: %f\n\tsin: %f\n\tcos: %f\n\ttan: %f\n", refBrick->Angle(), theta, std::sin(theta), std::cos(theta), std::tan(theta));

				velocity.y = -(long)(velocity.x * std::tan(theta));

				//if (0 <= refBrick->Angle() && refBrick->Angle() < 90) {
				//	//velocity.x = (long)(velocity.x * std::cos(theta));
				//	velocity.y = -(long)(velocity.x * std::tan(theta));
				//}

				//if (90 < refBrick->Angle() && refBrick->Angle() <= 180) {
				//	velocity.x = -velocity.x;
				//	velocity.y = -(long)(velocity.x * std::tan(theta));
				//}
				//
				//if (180 < refBrick->Angle() && refBrick->Angle() <= 270) {
				//	velocity.x = -velocity.x;
				//	velocity.y = -(long)(velocity.x * std::tan(theta));
				//}

				//if (270 < refBrick->Angle() && refBrick->Angle() <= 360) {
				//	//velocity.x = (long)(velocity.x * std::cos(theta));
				//	velocity.y = -(long)(velocity.x * std::tan(theta));
				//}
				
			}
		}


		if (velocity.x != 0) moving.OnMove();
		return velocity;
	}

	bool comparetor(Brick b1, Brick b2) { return (b1.Top() < b2.Top()); }

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

	void Actor::checkLevingRefBrick() {
		if (this != nullptr && refBrick != nullptr)
			if (this->Left() > refBrick->Right() || this->Right() < refBrick->Left()) refBrick = nullptr;
	}

	int Actor::Top() { return idle.Top(); }

	int Actor::Left() {	return idle.Left(); }

	int Actor::Buttom() { return Top() + Height(); }

	int Actor::Right() { return Left() + Width(); }
	
	int Actor::Width() { return idle.Width() * DEFAULT_SCALE; }

	int Actor::Height() { return idle.Height() * DEFAULT_SCALE; }

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

	

	// Sonic
	Sonic::Sonic() : Actor::Actor() {
		pos.y += 5 * DEFAULT_SCALE;
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
	}

	void Sonic::OnMove(vector<Brick*> b) {
		delta = Moving(b);

		
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
	}



	// Miles
	Miles::Miles() : Actor::Actor() { }
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
	}
	
	void Miles::OnMove(vector<Brick*> b) {
		delta = Moving(b);

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
	Knuckles::Knuckles() : Actor::Actor() { }
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
	
	}

	void Knuckles::OnMove(vector<Brick*> b) {
		delta = Moving(b);

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