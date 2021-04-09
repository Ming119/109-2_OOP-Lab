#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Brick.h"
#include "Level.h"

namespace game_framework {
	Brick::Brick(int _id, int x, int y, POINT spawn) {
		id = _id;
		posX = (x) * DEFAULT_SCALE;
		posY = (y - spawn.y) * DEFAULT_SCALE + SIZE_Y / 2;

		maxSpeed = 50;
		speed = 0;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void Brick::OnInit(int level) {
		if (level == static_cast<int>(LEVELS::BULE_OCEAN_1) || level == static_cast<int>(LEVELS::BULE_OCEAN_2) || level == static_cast<int>(LEVELS::SUPER_BOSS_1) || level == static_cast<int>(LEVELS::TEST)) {
			// OCEAN
			switch (id) {
			case 0:
				texture.AddBitmap(OCEAN_0);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 1:
				texture.AddBitmap(OCEAN_1);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 2:
				texture.AddBitmap(OCEAN_2);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 3:
				texture.AddBitmap(OCEAN_3);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(26);
				break;

			case 4:
				texture.AddBitmap(OCEAN_4);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 5:
				texture.AddBitmap(OCEAN_5);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(334);
				break;

			case 6:
				texture.AddBitmap(OCEAN_6);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 7:
				texture.AddBitmap(OCEAN_7_1);
				texture.AddBitmap(OCEAN_7_2);
				texture.AddBitmap(OCEAN_7_3);
				texture.AddBitmap(OCEAN_7_4);
				texture.AddBitmap(OCEAN_7_5);
				texture.AddBitmap(OCEAN_7_6);
				texture.SetDelayCount(3);

				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 8:
				texture.AddBitmap(OCEAN_8);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 9:
				texture.AddBitmap(OCEAN_9);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(26);
				break;

			case 10:
				texture.AddBitmap(OCEAN_9);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(26);
				break;

			case 11:
				texture.AddBitmap(OCEAN_11);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(116);
				break;

			case 12:
				texture.AddBitmap(OCEAN_12);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(206);
				break;

			case 13:
				texture.AddBitmap(OCEAN_13);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(334);
				break;

			case 14:
				texture.AddBitmap(OCEAN_14);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 15:
				texture.AddBitmap(OCEAN_15);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			// loop 1
			case 16:
				texture.AddBitmap(OCEAN_16);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 17:
				texture.AddBitmap(OCEAN_17);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(17);
				break;

			case 18:
				texture.AddBitmap(OCEAN_18);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(45);
				break;

			case 19:
				texture.AddBitmap(OCEAN_19);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(75);
				break;

			case 20:
				texture.AddBitmap(OCEAN_20);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 21:
				texture.AddBitmap(OCEAN_21);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 22:
				texture.AddBitmap(OCEAN_22);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(90);
				break;
			// end of loop 1

			case 23:
				texture.AddBitmap(OCEAN_23);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(90);
				break;

			case 24:
				texture.AddBitmap(OCEAN_24);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(270);
				break;

			// loop 2
			case 25:
				texture.AddBitmap(OCEAN_25);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 26:
				texture.AddBitmap(OCEAN_26);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(343);
				break;

			case 27:
				texture.AddBitmap(OCEAN_27);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(315);
				break;

			case 28:
				texture.AddBitmap(OCEAN_28);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(285);
				break;

			case 29:
				texture.AddBitmap(OCEAN_29);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 30:
				texture.AddBitmap(OCEAN_30);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 31:
				texture.AddBitmap(OCEAN_31);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(270);
				break;
			// end of loop 2

			// loop 3
			case 32:
				texture.AddBitmap(OCEAN_32);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 33:
				texture.AddBitmap(OCEAN_33);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(197);
				break;

			case 34:
				texture.AddBitmap(OCEAN_34);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(225);
				break;

			case 35:
				texture.AddBitmap(OCEAN_35);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(225);
				break;

			case 36:
				texture.AddBitmap(OCEAN_36);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 37:
				texture.AddBitmap(OCEAN_37);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 38:
				texture.AddBitmap(OCEAN_38);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(270);
				break;
			// end of loop 3

			// loop 4
			case 39:
				texture.AddBitmap(OCEAN_39);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 40:
				texture.AddBitmap(OCEAN_40);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(163);
				break;

			case 41:
				texture.AddBitmap(OCEAN_41);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(135);
				break;

			case 42:
				texture.AddBitmap(OCEAN_42);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(105);
				break;

			case 43:
				texture.AddBitmap(OCEAN_43);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 44:
				texture.AddBitmap(OCEAN_44);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 45:
				texture.AddBitmap(OCEAN_45);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(90);
				break;
			// end of loop 4

			//loop top
			case 46:
				texture.AddBitmap(OCEAN_46);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(180);
				break;

			case 47:
				texture.AddBitmap(OCEAN_47);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;
			// end of loop top

			case 48:
				texture.AddBitmap(OCEAN_48);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 49:
				texture.AddBitmap(OCEAN_49);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 50:
				texture.AddBitmap(OCEAN_50);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 51:
				texture.AddBitmap(OCEAN_51);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 52:
				texture.AddBitmap(OCEAN_52);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 53:
				texture.AddBitmap(OCEAN_53);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 54:
				texture.AddBitmap(OCEAN_54);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 55:
				texture.AddBitmap(OCEAN_55);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 56:
				texture.AddBitmap(OCEAN_56);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 57:
				texture.AddBitmap(OCEAN_57);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 58:
				texture.AddBitmap(OCEAN_58);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 59:
				texture.AddBitmap(OCEAN_59);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 60:
				texture.AddBitmap(OCEAN_60);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 61:
				texture.AddBitmap(OCEAN_61_1);
				texture.AddBitmap(OCEAN_61_2);
				texture.AddBitmap(OCEAN_61_3);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 62:
				texture.AddBitmap(OCEAN_62_1);
				texture.AddBitmap(OCEAN_62_2);
				texture.AddBitmap(OCEAN_62_3);
				texture.AddBitmap(OCEAN_62_4);
				texture.AddBitmap(OCEAN_62_5);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 63:
				texture.AddBitmap(OCEAN_63);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			// Arrows
			case 64:
				texture.AddBitmap(OCEAN_64);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 65:
				texture.AddBitmap(OCEAN_65);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 66:
				texture.AddBitmap(OCEAN_66);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 67:
				texture.AddBitmap(OCEAN_67);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			// Moveable platform
			case 68:
				texture.AddBitmap(OCEAN_68);
				setProperty(OBSTACLE);
				setBehavior(CIRCULAR, 200, 0, 0.1, 0);
				setAngle(0);
				break;

			// Misc
			case 69:
				texture.AddBitmap(OCEAN_69);
				setProperty(PASSABLE);
				setBehavior(DEFAULT);
				setAngle(0);
				break;

			case 70:
				texture.AddBitmap(OCEAN_70);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(90);
				break;

			case 71:
				texture.AddBitmap(OCEAN_71);
				setProperty(OBSTACLE);
				setBehavior(DEFAULT);
				setAngle(270);
				break;

			case 72:
				texture.AddBitmap(OCEAN_72_1);
				texture.AddBitmap(OCEAN_72_2);
				texture.AddBitmap(OCEAN_72_3);
				texture.AddBitmap(OCEAN_72_4);
				texture.AddBitmap(OCEAN_72_5);
				texture.AddBitmap(OCEAN_72_6);
				setProperty(CLOUD);
				setBehavior(DEFAULT);
				setAngle(0);
				break;
			}
		}

		if (level == static_cast<int>(LEVELS::BULE_OCEAN_3)) {
			// OCEAN 2
			//switch (id) {
			//case 0:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 1:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 2:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 3:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(26);
			//	break;

			//case 4:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 5:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(334);
			//	break;

			//case 6:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 7:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 8:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 9:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(26);
			//	break;

			//case 10:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(26);
			//	break;

			//case 11:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(116);
			//	break;

			//case 12:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(206);
			//	break;

			//case 13:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(334);
			//	break;

			//case 14:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 15:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//// loop 1
			//case 16:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 17:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(17);
			//	break;

			//case 18:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(45);
			//	break;

			//case 19:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(75);
			//	break;

			//case 20:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 21:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 22:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(90);
			//	break;
			//// end of loop 1

			//case 23:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(90);
			//	break;

			//case 24:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(270);
			//	break;

			//// loop 2
			//case 25:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 26:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(343);
			//	break;

			//case 27:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(315);
			//	break;

			//case 28:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(285);
			//	break;

			//case 29:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 30:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 31:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(270);
			//	break;
			//// end of loop 2

			//// loop 3
			//case 32:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 33:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(197);
			//	break;

			//case 34:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(225);
			//	break;

			//case 35:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(225);
			//	break;

			//case 36:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 37:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 38:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(270);
			//	break;
			//// end of loop 3

			//// loop 4
			//case 39:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 40:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(163);
			//	break;

			//case 41:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(135);
			//	break;

			//case 42:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(105);
			//	break;

			//case 43:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 44:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 45:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(90);
			//	break;
			//// end of loop 4

			////loop top
			//case 46:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(180);
			//	break;

			//case 47:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;
			//// end of loop top

			//case 48:
			//	setProperty(OBSTACLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 49:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 50:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 51:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 52:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 53:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 54:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 55:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 56:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 57:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 58:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 59:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 60:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 61:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 62:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 63:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//// Arrows
			//case 64:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 65:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 66:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//case 67:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//// Moveable platform
			//case 68:
			//	setProperty(OBSTACLE);
			//	setBehavior(CIRCULAR, 200, 0, 0.1, 0);
			//	setAngle(0);
			//	break;

			//// Misc
			//case 69:
			//	setProperty(PASSABLE);
			//	setBehavior(DEFAULT);
			//	setAngle(0);
			//	break;

			//}
		}

		if (level == static_cast<int>(LEVELS::CHILPOCTLI_TEMPLE)) {
			// DESERT
			/*switch (id) {
			}*/
		}

		if (level == static_cast<int>(LEVELS::EXOTIC_PARADISE_1) || level == static_cast<int>(LEVELS::EXOTIC_PARADISE_2) || level == static_cast<int>(LEVELS::TUTORIAL_1)) {
			// INLAND

			/*switch (id) {
			}*/	 
		}

		if (level == static_cast<int>(LEVELS::EXOTIC_HELL) || level == static_cast<int>(LEVELS::EXOTIC_PARADISE_3) || level == static_cast<int>(LEVELS::TUTORIAL_2)) {
			// INLAND 2
			/*switch (id) {

			}*/
		}

		if (level == static_cast<int>(LEVELS::PROTOTYPE_1)) {
			// PROTOTYPE
			/*switch (id) {

			}*/
		}

		if (level == static_cast<int>(LEVELS::SUPER_BOSS_2)) {
			// INLAND 3
			/*switch (id) {

			}*/
		}

		if (level == static_cast<int>(LEVELS::TEMPLATE)) {
			// TEMPLATE
			/*switch (id) {

			}*/
		}
	}

	void Brick::OnMove() {
		if (isMovingLeft) 
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		texture.SetTopLeft(posX, posY);
		texture.OnMove();
	}

	void Brick::OnShow() {
		texture.OnShow();
	}

	void Brick::SetMoveLeft(bool m) {
		isMovingLeft = m;
	}

	void Brick::SetMoveRight(bool m) {
		isMovingRight = m;
	}

	void Brick::SetMoveUp(bool m) {
		isMovingUp = m;
	}

	void Brick::SetMoveDown(bool m) {
		isMovingDown = m;
	}

	void Brick::setProperty(int p) {
		property = p;
	}

	void Brick::setBehavior(int b) {
		behavior = b;
		maxX = 0;
		maxY = 0;
		speed = 0;
		//gravity = 0;
	}

	void Brick::setBehavior(int b, int x, int y, double s, int g) {
		behavior = b;
		maxX = x;
		maxY = y;
		//speed = s;
		//gravity = g;
	}

	void Brick::setAngle(int ang) {
		angle = ang;
	}
}
