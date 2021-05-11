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
		int angel;
		int property;
		int behavior;
		
		int maxX, maxY;

		bool operator<(const Brick& brs) const;

	public:
		// Constructor
		Brick(int, int, int);
		~Brick();

		// Getter
		int Angle();
		int Property();
		int Height();
		int Width();
		int Top();
		int Left();
		int Buttom();
		int Right();
		
		// Setter
		void SetAngle(int);
		void SetProperty(int);
		void SetMoving(POINT);
		void SetBehavior(int);
		void SetBehavior(int, int, int);

		//
		void OnInit(int);
		void OnMove();
		void OnShow(int scale = DEFAULT_SCALE);
	};

}

#endif