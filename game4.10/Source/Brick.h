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
		POINT delta;

		int id;
		int angle;
		int property;
		int behavior;

	public:
		/* Constructor */
		Brick(int, int, int);

		/* Getter */
		int ID();
		int Angle();
		int Property();
		int Behavior();
		int Height();
		int Width();	
		int Top();
		int Left();
		int Bottom();
		int Right();
		/* End of Getter */
		

		/* Setter */
		void SetAngle(int);
		void SetProperty(int);
		void SetMoving(POINT);
		void SetTopLeft(int, int);
		void SetTopLeft(POINT);
		void SetBehavior(int);
		void SetBehavior(int, int, int, double, int);
		/* End of Setter */


		//
		void OnInit(int);
		void OnMove();
		void OnShow(int scale = DEFAULT_SCALE);
		// 
	};

}

#endif