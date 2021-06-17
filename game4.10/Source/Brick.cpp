#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Brick.h"
#include "Level.h"

namespace game_framework {

	/* Constructor */
	Brick::Brick(int _id, int x, int y) {
		id = _id;
		pos.x = x;
		pos.y = y;
		delta = POINT();
	}

	/* Getter */
	int Brick::ID() { return id; }

	int Brick::Angle() { return angle; }

	int Brick::Property() { return property; }

	int Brick::Behavior() { return behavior; }

	int Brick::Height() { return texture.Height() * DEFAULT_SCALE; }

	int Brick::Width() { return texture.Width() * DEFAULT_SCALE; }

	int Brick::Top() { return texture.Top(); }

	int Brick::Left() { return texture.Left(); }

	int Brick::Bottom() { return this->Top() + this->Height(); }

	int Brick::Right() { return this->Left() + this->Width(); }

	/* Setter */
	void Brick::SetAngle(int ang) { angle = ang; }

	void Brick::SetProperty(int p) { property = p; }

	void Brick::SetMoving(POINT _delta) { delta = _delta; }

	void Brick::SetTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;

		texture.SetTopLeft(pos.x, pos.y);
	}

	void Brick::SetTopLeft(POINT xy) {
		pos = xy;

		texture.SetTopLeft(pos.x, pos.y);
	}

	void Brick::SetBehavior(int b) {
		behavior = b;
		maxX = 0;
		maxY = 0;
	}

	// Non finish
	void Brick::SetBehavior(int b, int x, int y, double g, int speed) {
		behavior = b;
		maxX = x;
		maxY = y;

	}
	
	//
	void Brick::OnInit(int level) {
		if (level == static_cast<int>(LEVELS::BULE_OCEAN_1) || level == static_cast<int>(LEVELS::BULE_OCEAN_2)) {
			// OCEAN
			switch (id) {
			case 0:
				texture.AddBitmap(OCEAN_0);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 1:
				texture.AddBitmap(OCEAN_1);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 2:
				texture.AddBitmap(OCEAN_2);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 3:
				texture.AddBitmap(OCEAN_3);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(26);
				break;

			case 4:
				texture.AddBitmap(OCEAN_4);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 5:
				texture.AddBitmap(OCEAN_5);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(334);
				break;

			case 6:
				texture.AddBitmap(OCEAN_6);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 7:
				texture.AddBitmap(OCEAN_7_1);
				texture.AddBitmap(OCEAN_7_2);
				texture.AddBitmap(OCEAN_7_3);
				texture.AddBitmap(OCEAN_7_4);
				texture.AddBitmap(OCEAN_7_5);
				texture.AddBitmap(OCEAN_7_6);
				texture.SetDelayCount(3);

				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 8:
				texture.AddBitmap(OCEAN_8);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 9:
				texture.AddBitmap(OCEAN_9);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(26);
				break;

			case 10:
				texture.AddBitmap(OCEAN_9);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(26);
				break;

			case 11:
				texture.AddBitmap(OCEAN_11);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(116);
				break;

			case 12:
				texture.AddBitmap(OCEAN_12);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(206);
				break;

			case 13:
				texture.AddBitmap(OCEAN_13);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(334);
				break;

			case 14:
				texture.AddBitmap(OCEAN_14);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 15:
				texture.AddBitmap(OCEAN_15);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			// loop 1
			case 16:
				texture.AddBitmap(OCEAN_16);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 17:
				texture.AddBitmap(OCEAN_17);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(17);
				break;

			case 18:
				texture.AddBitmap(OCEAN_18);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(45);
				break;

			case 19:
				texture.AddBitmap(OCEAN_19);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(75);
				break;

			case 20:
				texture.AddBitmap(OCEAN_20);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 21:
				texture.AddBitmap(OCEAN_21);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 22:
				texture.AddBitmap(OCEAN_22);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;
			// end of loop 1

			case 23:
				texture.AddBitmap(OCEAN_23);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;

			case 24:
				texture.AddBitmap(OCEAN_24);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;

			// loop 2
			case 25:
				texture.AddBitmap(OCEAN_25);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 26:
				texture.AddBitmap(OCEAN_26);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(343);
				break;

			case 27:
				texture.AddBitmap(OCEAN_27);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(315);
				break;

			case 28:
				texture.AddBitmap(OCEAN_28);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(285);
				break;

			case 29:
				texture.AddBitmap(OCEAN_29);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 30:
				texture.AddBitmap(OCEAN_30);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 31:
				texture.AddBitmap(OCEAN_31);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;
			// end of loop 2

			// loop 3
			case 32:
				texture.AddBitmap(OCEAN_32);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 33:
				texture.AddBitmap(OCEAN_33);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(197);
				break;

			case 34:
				texture.AddBitmap(OCEAN_34);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(225);
				break;

			case 35:
				texture.AddBitmap(OCEAN_35);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(225);
				break;

			case 36:
				texture.AddBitmap(OCEAN_36);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 37:
				texture.AddBitmap(OCEAN_37);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 38:
				texture.AddBitmap(OCEAN_38);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;
			// end of loop 3

			// loop 4
			case 39:
				texture.AddBitmap(OCEAN_39);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 40:
				texture.AddBitmap(OCEAN_40);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(163);
				break;

			case 41:
				texture.AddBitmap(OCEAN_41);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(135);
				break;

			case 42:
				texture.AddBitmap(OCEAN_42);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(105);
				break;

			case 43:
				texture.AddBitmap(OCEAN_43);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 44:
				texture.AddBitmap(OCEAN_44);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 45:
				texture.AddBitmap(OCEAN_45);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;
			// end of loop 4

			//loop top
			case 46:
				texture.AddBitmap(OCEAN_46);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(180);
				break;

			case 47:
				texture.AddBitmap(OCEAN_47);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			// end of loop top

			case 48:
				texture.AddBitmap(OCEAN_48);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 49:
				texture.AddBitmap(OCEAN_49);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 50:
				texture.AddBitmap(OCEAN_50);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 51:
				texture.AddBitmap(OCEAN_51);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 52:
				texture.AddBitmap(OCEAN_52);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 53:
				texture.AddBitmap(OCEAN_53);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 54:
				texture.AddBitmap(OCEAN_54);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 55:
				texture.AddBitmap(OCEAN_55);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 56:
				texture.AddBitmap(OCEAN_56);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 57:
				texture.AddBitmap(OCEAN_57);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 58:
				texture.AddBitmap(OCEAN_58);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 59:
				texture.AddBitmap(OCEAN_59);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 60:
				texture.AddBitmap(OCEAN_60);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 61:
				texture.AddBitmap(OCEAN_61_1);
				texture.AddBitmap(OCEAN_61_2);
				texture.AddBitmap(OCEAN_61_3);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 62:
				texture.AddBitmap(OCEAN_62_1);
				texture.AddBitmap(OCEAN_62_2);
				texture.AddBitmap(OCEAN_62_3);
				texture.AddBitmap(OCEAN_62_4);
				texture.AddBitmap(OCEAN_62_5);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 63:
				texture.AddBitmap(OCEAN_63);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			// Arrows
			case 64:
				texture.AddBitmap(OCEAN_64);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 65:
				texture.AddBitmap(OCEAN_65);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 66:
				texture.AddBitmap(OCEAN_66);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 67:
				texture.AddBitmap(OCEAN_67);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			// Moveable platform
			case 68:
				texture.AddBitmap(OCEAN_68);
				SetProperty(OBSTACLE);
				SetBehavior(CIRCULAR, 200, 0, 0.1, 0);
				SetAngle(0);
				break;

			// Misc
			case 69:
				texture.AddBitmap(OCEAN_69);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 70:
				texture.AddBitmap(OCEAN_70);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;

			case 71:
				texture.AddBitmap(OCEAN_71);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;

			case 72:
				texture.AddBitmap(OCEAN_72_1);
				texture.AddBitmap(OCEAN_72_2);
				texture.AddBitmap(OCEAN_72_3);
				texture.AddBitmap(OCEAN_72_4);
				texture.AddBitmap(OCEAN_72_5);
				texture.AddBitmap(OCEAN_72_6);
				SetProperty(CLOUD);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 90:
				texture.AddBitmap(Ping);
				SetProperty(CLOUD);

			case 101:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 102:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 103:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 104:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 105:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 106:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 107:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 108:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 110:
				texture.AddBitmap(Ping);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			default:
				break;
			}
		}

		if (level == static_cast<int>(LEVELS::CHILPOCTLI_TEMPLE)) {
			// DESERT
			switch (id) {
			case 0:
				texture.AddBitmap(DESERT_0);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 1:
				texture.AddBitmap(DESERT_1);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 2:
				texture.AddBitmap(DESERT_2);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 3:
				texture.AddBitmap(DESERT_3);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(340);
				break;

			case 4:
				texture.AddBitmap(DESERT_4);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 6:
				texture.AddBitmap(DESERT_6);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 7:
				texture.AddBitmap(DESERT_7);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 8:
				texture.AddBitmap(DESERT_8);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 9:
				texture.AddBitmap(DESERT_9);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 10:
				texture.AddBitmap(DESERT_10);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 11:
				texture.AddBitmap(DESERT_11);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 12:
				texture.AddBitmap(DESERT_12);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(317);
				break;

			case 13:
				texture.AddBitmap(DESERT_13);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 14:
				texture.AddBitmap(DESERT_14);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 15:
				texture.AddBitmap(DESERT_15);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 16:
				texture.AddBitmap(DESERT_16);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(43);
				break;

			case 17:
				texture.AddBitmap(DESERT_17);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 18:
				texture.AddBitmap(DESERT_18);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			// Sign - X
			case 19:
				texture.AddBitmap(DESERT_19);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 20:
				texture.AddBitmap(DESERT_20);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 21:
				texture.AddBitmap(DESERT_21);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 22:
				texture.AddBitmap(DESERT_22);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 23:
				texture.AddBitmap(DESERT_23);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 24:
				texture.AddBitmap(DESERT_24);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 25:
				texture.AddBitmap(DESERT_25);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 26:
				texture.AddBitmap(DESERT_26);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 27:
				texture.AddBitmap(DESERT_27);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			// arrows
			case 28:
				texture.AddBitmap(DESERT_28);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(285);
				break;

			case 29:
				texture.AddBitmap(DESERT_29);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 30:
				texture.AddBitmap(DESERT_30);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 31:
				texture.AddBitmap(DESERT_31);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			case 32:
				texture.AddBitmap(DESERT_32);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			case 33:
				texture.AddBitmap(DESERT_33);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(-10);
				break;

			case 34:
				texture.AddBitmap(DESERT_34);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 35:
				texture.AddBitmap(DESERT_35);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(10);
				break;

			case 36:
				texture.AddBitmap(DESERT_36);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			case 39:
				texture.AddBitmap(DESERT_39);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(10);
				break;

			case 40:
				texture.AddBitmap(DESERT_40);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 41:
				texture.AddBitmap(DESERT_41);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(-20);
				break;

			case 42:
				texture.AddBitmap(DESERT_42);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(135);
				break;

			case 43:
				texture.AddBitmap(DESERT_43);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(20);
				break;

			case 44:
				texture.AddBitmap(DESERT_44);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(163);
				break;

			case 45:
				texture.AddBitmap(DESERT_45);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(-30);
				break;

			case 46:
				texture.AddBitmap(DESERT_46);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 47:
				texture.AddBitmap(DESERT_47);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(30);
				break;

			case 48:
				texture.AddBitmap(DESERT_48);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 49:
				texture.AddBitmap(DESERT_49);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(-45);
				break;

			case 50:
				texture.AddBitmap(DESERT_50);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 51:
				texture.AddBitmap(DESERT_51);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(45);
				break;

			case 52:
				texture.AddBitmap(DESERT_52);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 53:
				texture.AddBitmap(DESERT_53);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			case 54:
				texture.AddBitmap(DESERT_54);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 55:
				texture.AddBitmap(DESERT_55);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 56:
				texture.AddBitmap(DESERT_56);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 57:
				texture.AddBitmap(DESERT_57);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 58:
				texture.AddBitmap(DESERT_58);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(45);
				break;

			case 59:
				texture.AddBitmap(DESERT_59);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 60:
				texture.AddBitmap(DESERT_60);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			case 61:
				texture.AddBitmap(DESERT_61);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 62:
				texture.AddBitmap(DESERT_62);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(-45);
				break;

			case 63:
				texture.AddBitmap(DESERT_63);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 64:
				texture.AddBitmap(DESERT_64);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 65:
				texture.AddBitmap(DESERT_65);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 66:
				texture.AddBitmap(DESERT_66);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 67:
				texture.AddBitmap(DESERT_67);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 68:
				texture.AddBitmap(DESERT_68);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 69:
				texture.AddBitmap(DESERT_69);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 70:
				texture.AddBitmap(DESERT_70);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;


			case 71:
				texture.AddBitmap(DESERT_71);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 72:
				texture.AddBitmap(DESERT_72);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 73:
				texture.AddBitmap(DESERT_73);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 74:
				texture.AddBitmap(DESERT_74);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 75:
				texture.AddBitmap(DESERT_75);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 76:
				texture.AddBitmap(DESERT_76);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 77:
				texture.AddBitmap(DESERT_77);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 78:
				texture.AddBitmap(DESERT_78);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 79:
				texture.AddBitmap(DESERT_79);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 80:
				texture.AddBitmap(DESERT_80);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 81:
				texture.AddBitmap(DESERT_81);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 82:
				texture.AddBitmap(DESERT_82);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 83:
				texture.AddBitmap(DESERT_83);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 84:
				texture.AddBitmap(DESERT_84);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(18);
				break;

			case 85:
				texture.AddBitmap(DESERT_85);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(9);
				break;

			case 86:
				texture.AddBitmap(DESERT_86);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(45);
				break;

			case 87:
				texture.AddBitmap(DESERT_87);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(40);
				break;

			case 88:
				texture.AddBitmap(DESERT_88);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(72);
				break;

			case 89:
				texture.AddBitmap(DESERT_89);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;

			case 90:
				texture.AddBitmap(DESERT_90);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(50);
				break;

			case 92:
				texture.AddBitmap(DESERT_92);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(108);
				break;

			case 93:
				texture.AddBitmap(DESERT_93);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;

			case 94:
				texture.AddBitmap(DESERT_94);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(130);
				break;

			case 95:
				texture.AddBitmap(DESERT_95);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(180);
				break;

			case 96:
				texture.AddBitmap(DESERT_96);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(135);
				break;

			case 97:
				texture.AddBitmap(DESERT_97);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(140);
				break;

			case 98:
				texture.AddBitmap(DESERT_98);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(162);
				break;

			case 99:
				texture.AddBitmap(DESERT_99);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(180);
				break;

			case 100:
				texture.AddBitmap(DESERT_100_118);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;

			case 101:
				texture.AddBitmap(DESERT_101);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(180);
				break;

			case 102:
				texture.AddBitmap(DESERT_102);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(198);
				break;

			case 103:
				texture.AddBitmap(DESERT_103);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(180);
				break;

			case 104:
				texture.AddBitmap(DESERT_104);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(225);
				break;

			case 105:
				texture.AddBitmap(DESERT_105);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(220);
				break;

			case 106:
				texture.AddBitmap(DESERT_106);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(252);
				break;

			case 107:
				texture.AddBitmap(DESERT_107);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;

			case 108:
				texture.AddBitmap(DESERT_108);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(230);
				break;

			case 109:
				texture.AddBitmap(DESERT_109);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(180);
				break;

			case 110:
				texture.AddBitmap(DESERT_110);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(288);
				break;

			case 111:
				texture.AddBitmap(DESERT_111);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;

			case 112:
				texture.AddBitmap(DESERT_112);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(310);
				break;

			case 113:
				texture.AddBitmap(DESERT_113);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 114:
				texture.AddBitmap(DESERT_114);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(315);
				break;

			case 115:
				texture.AddBitmap(DESERT_115);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(320);
				break;

			case 116:
				texture.AddBitmap(DESERT_116);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(342);
				break;
			
			case 117:
				texture.AddBitmap(DESERT_117);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 118:
				texture.AddBitmap(DESERT_100_118);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;


			default:
				break;

			}	 
		}

		if (level == static_cast<int>(LEVELS::EXOTIC_PARADISE_1) || level == static_cast<int>(LEVELS::EXOTIC_PARADISE_2) || level == static_cast<int>(LEVELS::TUTORIAL_1)) {
			// INLAND
			switch (id) {
			case 0:
				texture.AddBitmap(ISLAND_PARADISE_0);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 1:
				texture.AddBitmap(ISLAND_PARADISE_1);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 2:
				texture.AddBitmap(ISLAND_PARADISE_2);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 3:
				texture.AddBitmap(ISLAND_PARADISE_3);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(340);
				break;

			case 4:
				texture.AddBitmap(ISLAND_PARADISE_4);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 5:
				texture.AddBitmap(ISLAND_PARADISE_5);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(20);
				break;

			case 6:
				texture.AddBitmap(ISLAND_PARADISE_6);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 7:
				texture.AddBitmap(ISLAND_PARADISE_7);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 8:
				texture.AddBitmap(ISLAND_PARADISE_8);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 9:
				texture.AddBitmap(ISLAND_PARADISE_9);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 10:
				texture.AddBitmap(ISLAND_PARADISE_10);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 11:
				texture.AddBitmap(ISLAND_PARADISE_11);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 12:
				texture.AddBitmap(ISLAND_PARADISE_12);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(317);
				break;

			case 13:
				texture.AddBitmap(ISLAND_PARADISE_13);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 14:
				texture.AddBitmap(ISLAND_PARADISE_14);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 15:
				texture.AddBitmap(ISLAND_PARADISE_15);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 16:
				texture.AddBitmap(ISLAND_PARADISE_16);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(43);
				break;

			case 17:
				texture.AddBitmap(ISLAND_PARADISE_17);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 18:
				texture.AddBitmap(ISLAND_PARADISE_18);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 19:
				texture.AddBitmap(ISLAND_PARADISE_19);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 20:
				texture.AddBitmap(ISLAND_PARADISE_20);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 21:
				texture.AddBitmap(ISLAND_PARADISE_21);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 22:
				texture.AddBitmap(ISLAND_PARADISE_22);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 23:
				texture.AddBitmap(ISLAND_PARADISE_23);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 24:
				texture.AddBitmap(ISLAND_PARADISE_24);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 25:
				texture.AddBitmap(ISLAND_PARADISE_25);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 26:
				texture.AddBitmap(ISLAND_PARADISE_26);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 27:
				texture.AddBitmap(ISLAND_PARADISE_27);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			// arrows
			case 28:
				texture.AddBitmap(ISLAND_PARADISE_28);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(285);
				break;

			case 29:
				texture.AddBitmap(ISLAND_PARADISE_29);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 30:
				texture.AddBitmap(ISLAND_PARADISE_30);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 31:
				texture.AddBitmap(ISLAND_PARADISE_31);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			// moveable platform
			case 32:
				texture.AddBitmap(ISLAND_PARADISE_32);
				SetProperty(CLOUD);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			// loop (right -> up)
			case 33:
				texture.AddBitmap(ISLAND_PARADISE_33);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(17);
				break;

			case 34:
				texture.AddBitmap(ISLAND_PARADISE_34);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 35:
				texture.AddBitmap(ISLAND_PARADISE_35);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(45);
				break;

			case 36:
				texture.AddBitmap(ISLAND_PARADISE_36);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 37:
				texture.AddBitmap(ISLAND_PARADISE_37);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(73);
				break;

			case 38:
				texture.AddBitmap(ISLAND_PARADISE_38);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 39:
				texture.AddBitmap(ISLAND_PARADISE_39);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(90);
				break;

			// loop (up -> left)
			case 40:
				texture.AddBitmap(ISLAND_PARADISE_40);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(107);
				break;

			case 41:
				texture.AddBitmap(ISLAND_PARADISE_41);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 42:
				texture.AddBitmap(ISLAND_PARADISE_42);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(135);
				break;

			case 43:
				texture.AddBitmap(ISLAND_PARADISE_43);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 44:
				texture.AddBitmap(ISLAND_PARADISE_44);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(163);
				break;

			case 45:
				texture.AddBitmap(ISLAND_PARADISE_45);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 46:
				texture.AddBitmap(ISLAND_PARADISE_46);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(180);
				break;

			case 47:
				texture.AddBitmap(ISLAND_PARADISE_47);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			// loop (left -> down)
			case 48:
				texture.AddBitmap(ISLAND_PARADISE_48);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(197);
				break;

			case 49:
				texture.AddBitmap(ISLAND_PARADISE_49);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 50:
				texture.AddBitmap(ISLAND_PARADISE_50);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 51:
				texture.AddBitmap(ISLAND_PARADISE_51);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(225);
				break;

			case 52:
				texture.AddBitmap(ISLAND_PARADISE_52);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(253);
				break;

			case 53:
				texture.AddBitmap(ISLAND_PARADISE_53);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			case 54:
				texture.AddBitmap(ISLAND_PARADISE_54);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(270);
				break;
			
			// loop (down -> right)
			case 55:
				texture.AddBitmap(ISLAND_PARADISE_55);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(287);
				break;

			case 56:
				texture.AddBitmap(ISLAND_PARADISE_56);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 57:
				texture.AddBitmap(ISLAND_PARADISE_57);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(315);
				break;

			case 58:
				texture.AddBitmap(ISLAND_PARADISE_58);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 59:
				texture.AddBitmap(ISLAND_PARADISE_59);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(343);
				break;

			case 60:
				texture.AddBitmap(ISLAND_PARADISE_60);
				SetProperty(PASSABLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;
			
			// misc
			case 61:
				texture.AddBitmap(ISLAND_PARADISE_61);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 62:
				texture.AddBitmap(ISLAND_PARADISE_62);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			case 63:
				texture.AddBitmap(ISLAND_PARADISE_63);
				SetProperty(OBSTACLE);
				SetBehavior(DEFAULT);
				SetAngle(0);
				break;

			// special
			// behavior BREAKABLE (int x-partition) (int y-partition)
			case 64:
				texture.AddBitmap(ISLAND_PARADISE_64);
				SetProperty(OBSTACLE);
				SetBehavior(BREAKABLE,3,3,0,0);
				SetAngle(0);
				break;

			case 65:
				texture.AddBitmap(ISLAND_PARADISE_65);
				SetProperty(CLOUD);
				SetBehavior(FALL,6,3,1,0);
				SetAngle(0);
				break;

			case 66:
				texture.AddBitmap(ISLAND_PARADISE_65);
				SetProperty(CLOUD);
				SetBehavior(FALL,6,3,0,0);
				SetAngle(0);
				break;

			case 67:
				texture.AddBitmap(ISLAND_PARADISE_32);
				SetProperty(CLOUD);
				SetBehavior(CIRCULAR, 100, 200, 0.1,0);
				SetAngle(0);
				break;
			case 68:
				texture.AddBitmap(ISLAND_PARADISE_32);
				SetProperty(CLOUD);
				SetBehavior(CIRCULAR,100,200,0.1,0);
				SetAngle(0);
				break;

			default:
				break;

			}
		}

		if (level == static_cast<int>(LEVELS::EXOTIC_HELL) || level == static_cast<int>(LEVELS::TUTORIAL_2)) {
			// INLAND 2
			/*switch (id) {

			}*/
		}

		texture.SetTopLeft(pos.x, pos.y);
	}

	void Brick::OnMove() {
		// Camera Movement
		pos.x -= delta.x;
		pos.y -= delta.y;

		SetTopLeft(pos);
		texture.OnMove();
	}

	void Brick::OnShow(int scale) {
		texture.OnShow(scale);
	}
}
