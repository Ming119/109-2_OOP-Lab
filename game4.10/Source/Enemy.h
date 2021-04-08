#ifndef _ENEMY_H_
#define _ENEMY_H_

namespace game_framework {

	enum class ENEMIES_LIST {
		// *ID (115 ~ 155) Needed to be changed*
		LADYBUG,
		FLY,
		BAMBOO,
		SPIDER,
		ROCKET,
		SHARK,
		MOSQUITO,
		GROUNDHOG,
		RED,
		CHEF,

		EARTHWORM,
		INSECT,
		PENGUIN,
		PINKMONSTER,
		SNAILS,
		BLUE,
		FLYSHIELD,
		COUNT
	};

	class Enemy {
		// Data for all enemies
		//int enemiesData[2][MAX_ENEMY_SIZE][3]{
		//	// Level 1
		//	{	// {id, x, y}
		//		{2, 831, 2046},
		//		{0, 2943, 1028},
		//		{4, 7820, 420},
		//		{2, 2122, 777},
		//		{0, 1745, 1198},
		//		{0, 1931, 1056},
		//		{4, 1722, 1473},
		//		{2, 6167, 712},
		//		{2, 3075, 979},
		//		{2, 2371, 1925}
		//	},
		//	// Level 2
		//	{
		//		// {id, x, y}
		//		{4, 2651, 2063},
		//		{2, 7542, 1721},
		//		{2, 7543, 2003},
		//		{4, 8079, 1505},
		//		{4, 7786, 2505},
		//		{4, 8227, 2014},
		//		{4, 8115, 2131},
		//		{4, 7985, 2301},
		//		{4, 7890, 2441},
		//		{4, 5794, 2629},
		//		{2, 7839, 2659},
		//		{2, 5580, 2629},
		//		{1, 5968, 2191},
		//		{1, 5968, 2341},
		//		{1, 5968, 2774},
		//		{0, 5537, 2426},
		//		{4, 5390, 2632},
		//		{0, 5042, 2473},
		//		{0, 5123, 2205},
		//		{3, 2775, 2020},
		//		{3, 3031, 2021},
		//		{0, 1105, 3010},
		//		{0, 1370, 3010},
		//		{2, 1020, 2972},
		//		{4, 3460, 1928},
		//		{4, 7755, 2307},
		//		{4, 8205, 1572},
		//		{4, 8206, 1406},
		//		{4, 8206, 1756},
		//		{4, 8206, 1856},
		//		{4, 8206, 1966},
		//		{4, 8206, 2151},
		//		{4, 8516, 2126},
		//		{4, 8516, 2031},
		//		{4, 8516, 1911},
		//		{4, 8516, 1806},
		//		{4, 8516, 1691},
		//		{4, 8516, 1586},
		//		{4, 8516, 1486},
		//		{4, 8516, 1371},
		//		{4, 8672, 1255},
		//		{4, 8672, 1330},
		//		{4, 8672, 1435},
		//		{4, 8672, 1540},
		//		{4, 8672, 1650},
		//		{4, 8672, 1760},
		//		{4, 8672, 1885},
		//		{4, 8642, 2000},
		//		{4, 8642, 2094},
		//		{4, 8764, 1687},
		//		{4, 8764, 1542},
		//		{4, 8764, 1407},
		//		{4, 8764, 1257},
		//		{4, 8764, 1112}
		//	}

		//};

	protected:
		CAnimation texture;
		int posX, posY;
		int angle;
		bool direction;

	public:
		Enemy();
		Enemy(int, int, int);

		void setTopLeft(int, int);
		void setAngle(int);

		int Top();
		int Left();
		int Angle();
		int Height();	
		int Width();

		//void getEnemiesData(int (&array)[][MAX_ENEMY_SIZE][3]);
		//void getEnemiesData(int (&array)[][3], int);

		virtual void OnInit() = 0;
		void OnMove();
		void OnShow();
	};

	class Bamboo : public Enemy {
	public:
		Bamboo();
		Bamboo(int, int, int);
		~Bamboo();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Chef : public Enemy {
	public:
		Chef();
		Chef(int, int, int);
		~Chef();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Earthworm : public Enemy {
	public:
		Earthworm();
		Earthworm(int, int, int);
		~Earthworm();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Fly : public Enemy {
	public:
		Fly();
		Fly(int, int, int);
		~Fly();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};
	
	class Groundhog : public Enemy {
	public:
		Groundhog();
		Groundhog(int, int, int);
		~Groundhog();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Insect : public Enemy {
	public:
		Insect();
		Insect(int, int, int);
		~Insect();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Ladybug : public Enemy {
	public:
		Ladybug();
		Ladybug(int, int, int);
		~Ladybug();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Mosquito : public Enemy {
	public:
		Mosquito();
		Mosquito(int, int, int);
		~Mosquito();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Penguin : public Enemy {
	public:
		Penguin();
		Penguin(int, int, int);
		~Penguin();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class PinkMonster : public Enemy {
	public:
		PinkMonster();
		PinkMonster(int, int, int);
		~PinkMonster();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Rocket : public Enemy {
	public:
		Rocket();
		Rocket(int, int, int);
		~Rocket();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Shark : public Enemy {
	public:
		Shark();
		Shark(int, int, int);
		~Shark();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Snails : public Enemy {
	public:
		Snails();
		Snails(int, int, int);
		~Snails();

		void OnInit();
		void OnMove();
		void OnShow();
	};

	class Spider : public Enemy {
	private:
	public:
		Spider();
		Spider(int, int, int);
		~Spider();

		void OnInit();
		void OnMove();
		void OnShow();
	};

	class Blue : public Enemy {
	public:
		Blue();
		Blue(int, int, int);
		~Blue();

		void OnInit();
		void OnMove();
		void OnShow();
	};

	class FlyShield : public Enemy {
	public:
		FlyShield();
		FlyShield(int, int, int);
		~FlyShield();

		void OnInit() ;
		void OnMove() ;
		void OnShow() ;
	};

	class Red : public Enemy {
	public:
		Red();
		Red(int, int, int);
		~Red();

		void OnInit();
		void OnMove();
		void OnShow();

	};

}

#endif