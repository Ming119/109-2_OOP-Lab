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

		int id;
		int posX, posY;
		int angle;

		int property;
		int behavior;
		int angel;		// Degrees, 0 <= angle <= 360
		
		int maxX, maxY;
		// double speed, gravity;
		int maxSpeed, speed;

		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;

	public:
		Brick(int, int, int, POINT);

		void OnInit(int);
		void OnMove();
		void OnShow();

		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetMoveUp(bool);
		void SetMoveDown(bool);

		void setProperty(int);
		void setBehavior(int);
		void setBehavior(int, int, int, double, int);
		void setAngle(int);
	};

}

#endif