#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Brick.h"

namespace game_framework {
	Brick::Brick(int _id, int x, int y) {
		id = _id;
		posX = x;
		posY = y;

		/*switch (id) {
		case 0:
			texture.AddBitmap();
			break;
		case 1:
			texture.AddBitmap();
			break;
		case 2:
			texture.AddBitmap();
			break;

		}*/
	}

	void Brick::OnInit() {

	}

	void Brick::OnMove() {
		texture.SetTopLeft(posX, posY);
		texture.OnMove();
	}

	void Brick::OnShow() {
		texture.OnShow();
	}
}
