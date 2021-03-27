#ifndef _BRICK_H
#define _BRICK_H

#define BRICK_MAXVALUES	3

namespace game_framework {
	/*int brick_images = {

	};*/
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
		BRICKBEHAVIOR_MAXARGS

	};

	class BrickData {
	private:
		CMovingBitmap texture;
		int property;
		int behavior;
		int angel;		// Degrees, 0 <= angle <= 360
		float zindex;	// 0.0(background) <= z-index <= 1.0(foreground)
		float behavior_arg[BRICKBEHAVIOR_MAXARGS];

	public:
		void Load();
		BrickData* getBrickData(int);
		int BrickDataSize();

	};

	
	class Brick {
	private:
		BrickData brickRef;

		int x, y;
		int sx, sy;
		bool enable;
		float value[BRICK_MAXVALUES];

		int id;
		int width;
		int height;


	public:
		Brick();
		Brick(int, int, int);
		
		void LoadBitmap();
		void OnMove();
		void OnShow();

		int ID();
		int X();
		int Y();
		int Width();
		int Height();

	};

	class BrickList {
	private:

	public:
		Brick* data;
		BrickList* next;
	};

	
}

#endif