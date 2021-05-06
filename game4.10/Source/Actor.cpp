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
		posX = 100;
		posY = SIZE_Y / 3+40;
	}

	Actor::~Actor() {
		
	}

	void Actor::OnInit() {
		idle.AddBitmap(ACTOR_1_STAND_1);
		idle.SetTopLeft(posX, posY);

		//lookUp.AddBitmap(ACTOR_1_LOOKUP_1);
		//lookUp.AddBitmap(ACTOR_1_LOOKUP_2);
		lookUp.AddBitmap(ACTOR_1_LOOKUP_3);
		lookUp.AddBitmap(ACTOR_1_LOOKUP_4);
		lookUp.SetDelayCount(5);
		lookUp.SetTopLeft(posX, posY);

		lookDown.AddBitmap(ACTOR_1_LOOKDOWN_1);
		lookDown.AddBitmap(ACTOR_1_LOOKDOWN_2);
		lookDown.SetDelayCount(3);
		lookDown.SetTopLeft(posX, posY);

		moving.AddBitmap(ACTOR_1_RUN_1);
		moving.AddBitmap(ACTOR_1_RUN_2);
		moving.AddBitmap(ACTOR_1_RUN_3);
		moving.AddBitmap(ACTOR_1_RUN_4);
		moving.AddBitmap(ACTOR_1_RUN_5);
		moving.AddBitmap(ACTOR_1_RUN_6);
		moving.AddBitmap(ACTOR_1_RUN_7);
		moving.SetDelayCount(3);
		moving.SetTopLeft(posX, posY);

		/*jump.AddBitmap(ACTOR_1_ROLL_1);
		jump.AddBitmap(ACTOR_1_ROLL_2);
		jump.AddBitmap(ACTOR_1_ROLL_3);
		jump.AddBitmap(ACTOR_1_ROLL_4);
		jump.AddBitmap(ACTOR_1_ROLL_5);*/
		jump.AddBitmap(IDB_BITMAP210);
		jump.AddBitmap(IDB_BITMAP211);
		jump.AddBitmap(IDB_BITMAP212);
		jump.AddBitmap(IDB_BITMAP213);
		jump.AddBitmap(IDB_BITMAP214);
		jump.SetDelayCount(3);
		jump.SetTopLeft(posX, posY);

	}

	void Actor::OnMove() {
		velocity.x = (long)(velocity.x * friction);
		velocity.y += gravity;

		if (isMovingLeft) {
			acceleration--;
			moving.OnMove();
		}
		else if (isMovingRight) {
			acceleration++;
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

	void Actor::OnShow() {
		lookUp.SetTopLeft(posX, posY);
		lookDown.SetTopLeft(posX, posY);
		moving.SetTopLeft(posX, posY);
		idle.SetTopLeft(posX, posY);

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

	int Actor::Top() {
		return idle.Top();;
	}

	int Actor::Left() {
		return idle.Left();
	}

	int Actor::Height() {
		return idle.Height();
	}

	int Actor::Width() {
		return idle.Width();
	}

	void Actor::setTopLeft(int x, int y) {
		posX = x;
		posY = y;
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

}