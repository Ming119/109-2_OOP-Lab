#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Item.h"
#include "Level.h"

namespace game_framework {
	// Item
	Item::Item() {
		pos.x = 0;
		pos.y = 0;
		angle = 0;
		cameraSpeed = 50;
	}

	Item::Item(int x, int y) {
		pos.x = x;
		pos.y = y;
		angle = 0;
		cameraSpeed = 50;

		isDead = isDeadFinish =false;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}


	int Item::Top() {
		return texture.Top();
	}

	int Item::Left() {
		return texture.Left();
	}

	int Item::Height() {
		return texture.Height();
	}

	int Item::Width() {
		return texture.Width();
	}

	void Item::setTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;

		texture.SetTopLeft(pos.x, pos.y);
		deadAnimate.SetTopLeft(pos.x, pos.y);
	}

	void Item::setTopLeft(POINT xy) {
		pos = xy;

		texture.SetTopLeft(pos.x, pos.y);
		deadAnimate.SetTopLeft(pos.x, pos.y);
	}

	void Item::setAngle(int ang) {
		angle = ang;
	}

	void Item::SetMoveLeft(bool m) {
		isMovingLeft = m;
	}

	void Item::SetMoveRight(bool m) {
		isMovingRight = m;
	}

	void Item::SetMoveUp(bool m) {
		isMovingUp = m;
	}

	void Item::SetMoveDown(bool m) {
		isMovingDown = m;
	}

	void Item::SetCurrentActor(Actor* actor) {
		currnetActor = actor;
	}
	
	bool Item::CollisionDetection(Actor* actor) {
		if ((this->Left()) < (actor->Left() + actor->Width() * DEFAULT_SCALE) &&
			(this->Left() + this->Width() * DEFAULT_SCALE) > (actor->Left()) &&
			(this->Top()) < (actor->Top() + actor->Height() * DEFAULT_SCALE) &&
			(this->Top() + this->Height() * DEFAULT_SCALE) > (actor->Top())) {

				return true;
		}
		
		return false;
	}
	

	bool Item::IsDead() {
		return isDeadFinish;
	}

	// Ring
	Ring::Ring() : Item::Item() {}

	Ring::Ring(int x, int y) : Item::Item(x, y) {}

	Ring::~Ring() {}

	void Ring::OnInit() {
		texture.AddBitmap(ITEMS_YELLOW_RING_1);
		texture.AddBitmap(ITEMS_YELLOW_RING_2);
		texture.AddBitmap(ITEMS_YELLOW_RING_3);
		texture.AddBitmap(ITEMS_YELLOW_RING_4);
		texture.AddBitmap(ITEMS_YELLOW_RING_5);
		texture.AddBitmap(ITEMS_YELLOW_RING_6);
		texture.AddBitmap(ITEMS_YELLOW_RING_7);
		texture.AddBitmap(ITEMS_YELLOW_RING_8);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_1);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_2);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_3);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_4);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void Ring::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
		}

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.IsFinalBitmap()) {
				isDeadFinish = true;
			}
			deadAnimate.OnMove();
		} else {
			texture.OnMove();
		}

		
		
		
		
	}

	void Ring::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		} else {
			texture.OnShow(scale);
		}
	}

	
}

