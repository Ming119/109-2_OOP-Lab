#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Brick.h"

namespace game_framework {
	Brick::Brick() {
		id = -1;
		x = 0;
		y = 0;
	}

	Brick::Brick(int _id, int _x, int _y) {
		id = _id;
		x = _x;
		y = _y;
	}

	void Brick::LoadBitmap() {
		if (id != -1) {

		}
	}

	void Brick::OnMove() {

	}

	void Brick::OnShow() {

	}

	int Brick::ID() {
		return id;
	}

	int Brick::Angle() {
		return angle;
	}

	int Brick::Width() {
		return width;
	}

	int Brick::Height() {
		return height;
	}

	int Brick::X() {
		return x;
	}

	int Brick::Y() {
		return y;
	}


}
