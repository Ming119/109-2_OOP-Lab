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
		posX = x * DEFAULT_SCALE;
		posY = y * DEFAULT_SCALE;
	}

	void Brick::OnInit() {
		switch (id) {
		case 0:
			texture.AddBitmap(OCEAN_1);
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 1:
			texture.AddBitmap(OCEAN_2);
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 2:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 3:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(26);
			break;

		case 4:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 5:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(334);
			break;

		case 6:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 7:
			texture.AddBitmap(OCEAN_ROAD_1);
			texture.AddBitmap(OCEAN_ROAD_2);
			texture.AddBitmap(OCEAN_ROAD_3);
			texture.AddBitmap(OCEAN_ROAD_4);
			texture.AddBitmap(OCEAN_ROAD_5);
			texture.AddBitmap(OCEAN_ROAD_6);
			texture.SetDelayCount(3);

			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 8:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 9:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(26);
			break;

		case 10:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(26);
			break;

		case 11:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(116);
			break;

		case 12:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(206);
			break;

		case 13:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(334);
			break;

		case 14:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 15:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		// loop 1
		case 16:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 17:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(17);
			break;

		case 18:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(45);
			break;

		case 19:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(75);
			break;

		case 20:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 21:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 22:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(90);
			break;
		// end of loop 1

		case 23:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(90);
			break;

		case 24:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(270);
			break;

		// loop 2
		case 25:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 26:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(343);
			break;

		case 27:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(315);
			break;

		case 28:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(285);
			break;

		case 29:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 30:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 31:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(270);
			break;
		// end of loop 2

		// loop 3
		case 32:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 33:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(197);
			break;

		case 34:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(225);
			break;

		case 35:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(225);
			break;

		case 36:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 37:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 38:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(270);
			break;
		// end of loop 3

		// loop 4
		case 39:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 40:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(163);
			break;

		case 41:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(135);
			break;

		case 42:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(105);
			break;

		case 43:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 44:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 45:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(90);
			break;
		// end of loop 4

		//loop top
		case 46:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(180);
			break;

		case 47:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;
		// end of loop top

		case 48:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 49:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 50:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 51:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 52:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 53:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 54:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 55:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 56:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 57:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 58:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 59:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 60:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 61:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 62:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 63:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		// Array
		case 64:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 65:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 66:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 67:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		// Moveable platform
		case 68:
			setProperty(OBSTACLE);
			setBehavior(CIRCULAR, 200, 0, 0.1, 0);
			setAngle(0);
			break;

		// Misc
		case 69:
			setProperty(PASSABLE);
			setBehavior(DEFAULT);
			setAngle(0);
			break;

		case 70:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(90);
			break;

		case 71:
			setProperty(OBSTACLE);
			setBehavior(DEFAULT);
			setAngle(270);
			break;

		case 72:
			setProperty(CLOUD);
			setBehavior(DEFAULT);
			setAngle(0);
			break;
		}


	}

	void Brick::OnMove() {
		texture.SetTopLeft(posX, posY);
		texture.OnMove();
	}

	void Brick::OnShow() {
		texture.OnShow();
	}

	void Brick::setProperty(int p) {
		property = p;
	}

	void Brick::setBehavior(int b) {
		behavior = b;
		maxX = 0;
		maxY = 0;
		speed = 0;
		gravity = 0;
	}

	void Brick::setBehavior(int b, int x, int y, double s, int g) {
		behavior = b;
		maxX = x;
		maxY = y;
		speed = s;
		gravity = g;
	}

	void Brick::setAngle(int ang) {
		angle = ang;
	}
}
