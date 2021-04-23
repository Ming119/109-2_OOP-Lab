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
		posY = SIZE_Y / 2;
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
		else {
			moving.Reset();
			lookUp.Reset();
			lookDown.Reset();
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
		else 
			idle.OnShow();
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

}