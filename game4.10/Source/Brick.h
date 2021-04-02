#ifndef _BRICK_H_
#define _BRICK_H_

#define BRICK_MAXVALUES	3

namespace game_framework {

	enum PROPERTY {
		NONE,
		OBSTACLE,
		PASSABLE,
	};

	enum BEHAVIOR {
		DEFAULT,
		CIRCULAR,
		BREAKABLE,
		FALL,
		BRICKBEHAVIOR_MAXARGS = 5,

	};
	
	enum THEME {
		OCEAN,
		OCEAN2,
		DESERT1,
		ISLAND,
		ISLAND2,
		ISLAND3,
	};

	class Brick {
	private:
		CMovingBitmap texture;

		int property;
		int behavior;
		int angel;		// Degrees, 0 <= angle <= 360

		float behavior_arg[BRICKBEHAVIOR_MAXARGS];
		float value[BRICK_MAXVALUES];
		bool enable;


	public:
		Brick(int, int);
	};

	// TEMP
	int BricksOcean1[][4] = {
		// {id, propety, behavior, angle}
		{IDB_BITMAP101, OBSTACLE, DEFAULT, 0}, 
		{IDB_BITMAP102, OBSTACLE, DEFAULT, 0},
		{IDB_BITMAP103, OBSTACLE, DEFAULT, 0}
	};

	// TEMP
	int BricksOcean2[][4] = {
		// {id, propety, behavior, angle}
		{IDB_BITMAP101, OBSTACLE, DEFAULT, 0},
		{IDB_BITMAP102, OBSTACLE, DEFAULT, 0},
		{IDB_BITMAP103, OBSTACLE, DEFAULT, 0}
	};

	// TEMP
	vector<int**> themes = { BricksOcean1, BricksOcean2 };

}

#endif