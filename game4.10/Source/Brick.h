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
		double speed, gravity;
		

	public:
		Brick(int, int, int);

		void OnInit(int);
		void OnMove();
		void OnShow();

		void setProperty(int);
		void setBehavior(int);
		void setBehavior(int, int, int, double, int);
		void setAngle(int);
	};

	// TEMP
	//int BricksOcean1[][4] = {
	//	// {id, propety, behavior, angle}
	//	{IDB_BITMAP101, OBSTACLE, DEFAULT, 0}, 
	//	{IDB_BITMAP102, OBSTACLE, DEFAULT, 0},
	//	{IDB_BITMAP103, OBSTACLE, DEFAULT, 0}
	//};

	//// TEMP
	//int BricksOcean2[][4] = {
	//	// {id, propety, behavior, angle}
	//	{IDB_BITMAP101, OBSTACLE, DEFAULT, 0},
	//	{IDB_BITMAP102, OBSTACLE, DEFAULT, 0},
	//	{IDB_BITMAP103, OBSTACLE, DEFAULT, 0}
	//};

	// TEMP
	//vector<int**> themes = { BricksOcean1, BricksOcean2 };

}

#endif