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
		posX = 0;
		posY = 0;
		angle = 0;

	}

	Item::Item(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;


		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	Item::~Item() {
	}

	void Item::setPos(int x, int y) {
		posX = x;
		posY = y;
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


	// Ring
	//Ring::Ring() : Item::Item() {}

	Ring::Ring(int x, int y, int ang) : Item::Item(x, y, ang) {}

	void Ring::OnInit() {

		texture.AddBitmap(ITEMS_YELLOW_RING_1);
		texture.AddBitmap(ITEMS_YELLOW_RING_2);
		texture.AddBitmap(ITEMS_YELLOW_RING_3);
		texture.AddBitmap(ITEMS_YELLOW_RING_4);
		texture.AddBitmap(ITEMS_YELLOW_RING_5);
		texture.AddBitmap(ITEMS_YELLOW_RING_6);
		texture.AddBitmap(ITEMS_YELLOW_RING_7);
		texture.AddBitmap(ITEMS_YELLOW_RING_8);
		texture.SetDelayCount(8);
		texture.SetTopLeft(posX, posY);
		//LookingForRefBrick(b);

	}

	void Ring::OnMove() {

		// Camera Move
		if (isMovingLeft) {
			posX += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			posX -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			posY += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			posY -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}
		//texture.SetTopLeft(pos);
		texture.OnMove();
	}

	void Ring::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// 
}

