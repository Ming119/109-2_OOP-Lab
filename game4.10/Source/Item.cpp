#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Item.h"

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

	// Ring
	Ring::Ring() : Item::Item() {
	}

	Ring::Ring(int x, int y, int ang) : Item::Item(x, y, ang) {
	}

	void Ring::OnInit() {
		
	}

	void Ring::OnMove() {
		texture.OnMove();
	}

	void Ring::OnShow() {
		texture.OnShow();
	}

	// 
}

