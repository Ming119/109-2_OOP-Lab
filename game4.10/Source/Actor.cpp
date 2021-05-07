#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Actor.h"

namespace game_framework {
	Actor::Actor() {
		spawnPoint.x = 0;
		spawnPoint.y = 0;
		angle = 0;
		speed.x = 0;
		speed.y = 0;
		maxSpeed = 0;
		acceleration = 0;
		jumpStrength = 0;
		isJumping = false;
		ignoreHorizontal = false;

		acceleration = 0;
		isMovingLeft = isMovingRight = isLookingUp = isLookingDown = false;
		pos.x = 100;
		pos.y = SIZE_Y / 3+40;
	}

	Actor::~Actor() { }

	int Actor::Top() {
		return idle.Top();
	}

	int Actor::Left() {
		return idle.Left();
	}

	int Actor::Buttom() {
		return Top() + Height();
	}

	int Actor::Right() {
		return Left() + Width();
	}

	int Actor::Height() {
		return idle.Height();
	}

	int Actor::Width() {
		return idle.Width();
	}

	void Actor::setTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;
	}

	void Actor::setTopLeft(POINT xy) {
		pos = xy;
	}

	void Actor::SetMoveLeft(bool m) {
		isMovingLeft = m;
	}

	void Actor::SetMoveRight(bool m) {
		isMovingRight = m;
	}

	void Actor::SetIsLookingUp(bool m) {
		isLookingUp = m;
	}

	void Actor::SetIsLookingDown(bool m) {
		isLookingDown = m;
	}

	void Actor::SetIsJumping(bool m) {
		isJumping = m;
	}

	bool Actor::IsJumping() {
		return isJumping;
	}



	// Sonic
	Sonic::Sonic() : Actor::Actor() {}
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

		jump.AddBitmap(ACTOR_1_ROLL_1);
		jump.AddBitmap(ACTOR_1_ROLL_2);
		jump.AddBitmap(ACTOR_1_ROLL_3);
		jump.AddBitmap(ACTOR_1_ROLL_4);
		jump.AddBitmap(ACTOR_1_ROLL_5);
		jump.SetDelayCount(3);
		jump.SetTopLeft(pos.x, pos.y);
	}

	void Sonic::OnMove() {
		velocity.x = (long)(velocity.x * friction);
		velocity.y += gravity;

		if (isMovingLeft) {
			velocity.x--;
			moving.OnMove();
		}
		else if (isMovingRight) {
			velocity.x++;
			moving.OnMove();
		}
		else if (isLookingUp) {
			if (!lookUp.IsFinalBitmap())
				lookUp.OnMove();
		}
		else if (isLookingDown) {
			if (!lookDown.IsFinalBitmap())
				lookDown.OnMove();
		}
		else if (isJumping) {
			speed.y -= 10;
			jump.OnMove();
		}
		else {
			moving.Reset();
			lookUp.Reset();
			lookDown.Reset();
			jump.Reset();
			idle.OnMove();
		}
		/*if (isMovingUp)
			position.y += maxSpeed;
		if (isMovingDown)
			position.y -= maxSpeed;*/
	}

	void Sonic::OnShow() {
		lookUp.SetTopLeft(pos.x, pos.y);
		lookDown.SetTopLeft(pos.x, pos.y);
		moving.SetTopLeft(pos.x, pos.y);
		idle.SetTopLeft(pos.x, pos.y);

		if (isMovingLeft || isMovingRight)
			moving.OnShow();
		else if (isLookingUp) {
			lookUp.OnShow();
		}
		else if (isLookingDown) {
			lookDown.OnShow();
		}
		else if (isJumping) {
			jump.OnShow();
		}
		else
			idle.OnShow();
	}



	// Miles
	Miles::Miles() : Actor::Actor() { }
	Miles::~Miles() { }

	void Miles::OnInit() {
		pos.x -= 50;
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

		jump.AddBitmap(ACTOR_1_ROLL_1);
		jump.AddBitmap(ACTOR_1_ROLL_2);
		jump.AddBitmap(ACTOR_1_ROLL_3);
		jump.AddBitmap(ACTOR_1_ROLL_4);
		jump.AddBitmap(ACTOR_1_ROLL_5);
		jump.SetDelayCount(3);
		jump.SetTopLeft(pos.x, pos.y);
	}
	
	void Miles::OnMove() {
		velocity.x = (long)(velocity.x * friction);
		velocity.y += gravity;

		if (isMovingLeft) {
			velocity.x--;
			moving.OnMove();
		}
		else if (isMovingRight) {
			velocity.x++;
			moving.OnMove();
		}
		else if (isLookingUp) {
			if (!lookUp.IsFinalBitmap())
				lookUp.OnMove();
		}
		else if (isLookingDown) {
			if (!lookDown.IsFinalBitmap())
				lookDown.OnMove();
		}
		else if (isJumping) {
			speed.y -= 10;
			jump.OnMove();
		}
		else {
			moving.Reset();
			lookUp.Reset();
			lookDown.Reset();
			jump.Reset();
			idle.OnMove();
		}
		/*if (isMovingUp)
			position.y += maxSpeed;
		if (isMovingDown)
			position.y -= maxSpeed;*/
	}

	void Miles::OnShow() {
		lookUp.SetTopLeft(pos.x, pos.y);
		lookDown.SetTopLeft(pos.x, pos.y);
		moving.SetTopLeft(pos.x, pos.y);
		idle.SetTopLeft(pos.x, pos.y);

		if (isMovingLeft || isMovingRight)
			moving.OnShow();
		else if (isLookingUp) {
			lookUp.OnShow();
		}
		else if (isLookingDown) {
			lookDown.OnShow();
		}
		else if (isJumping) {
			jump.OnShow();
		}
		else
			idle.OnShow();
	}



	//Knuckles
	Knuckles::Knuckles() : Actor::Actor() { }
	Knuckles::~Knuckles() {	}

	void Knuckles::OnInit() {

	}

	void Knuckles::OnMove() {

	}

	void Knuckles::OnShow() {

	}

}