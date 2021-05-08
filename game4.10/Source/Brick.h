#ifndef _BRICK_H_
#define _BRICK_H_

#define BRICK_MAXVALUES	3

namespace game_framework {

	enum PROPERTY {
		NONE,
		OBSTACLE,
		CLOUD,
		PASSABLE,
	};

	enum BEHAVIOR {
		DEFAULT,
		CIRCULAR,
		BREAKABLE,
		FALL,
		BRICKBEHAVIOR_MAXARGS = 5,

	};

	class Brick {
	private:
		CAnimation texture;
		POINT pos;
		int id;
		int angle;

		int property;
		int behavior;
		int angel;		// Degrees, 0 <= angle <= 360
		
		int maxX, maxY;
		// double speed, gravity;
		int maxSpeed, speed;

		POINT delta;

		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;

		bool isCollisingLeft;
		bool isCollisingRight;
		bool isCollisingTop;
		bool isCollisingBottom;

	public:
		Brick(int, int, int);

		int Top();
		int Left();
		int Angle();
		int Height();
		int Width();
		int Property();

		void OnInit(int);
		void OnMove();
		void OnShow(int scale=DEFAULT_SCALE);

		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetMoveUp(bool);
		void SetMoveDown(bool);
		void SetMoving(POINT);

		void setProperty(int);
		void setBehavior(int);
		void setBehavior(int, int, int, double, int);
		void setAngle(int);

		void SetCollisionLeft(bool);
		void SetCollisionRight(bool);
		void SetCollisionTop(bool);
		void SetCollisionBottom(bool);
	};

}

#endif