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

	void Item::LookingForRefBrick() {

		/*const int bs = bricks.size();

		do {
			for (int b = 0; b < bs; b++) {
				if (CollisionDetection(bricks.at(b))) {
					this->refBrick = bricks.at(b);
					break;
				}
			}

			if (this->refBrick == nullptr) spawn.y++;
		} while (this->refBrick == nullptr);*/




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

		LookingForRefBrick();

		setTopLeft(pos);
	}

	void Ring::OnMove() {
		texture.OnMove();
	}

	void Ring::OnShow() {
		texture.OnShow(scale);
	}

	// 
}

