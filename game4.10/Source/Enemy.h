#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Brick.h"

namespace game_framework {

	enum class ENEMIES_LIST {
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
	protected:
		CAnimation texture;
		POINT spawn;
		POINT pos;
		POINT delta;

		Brick* refBrick;

		int angle;
		int speed;
		int cameraSpeed;
		int movingRange;
		bool direction;
		
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;

		bool isCollisingLeft;
		bool isCollisingRight;
		bool isCollisingTop;
		bool isCollisingBottom;

	public:
		Enemy(int, int);

		void setTopLeft(POINT);
		void setTopLeft(int, int);
		void setAngle(int);

		int Top();
		int Left();
		int Angle();
		int Height();	
		int Width();

		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetMoveUp(bool);
		void SetMoveDown(bool);
		void SetMoving(POINT);

		void LookingForRefBrick(vector<Brick*>);
		bool CollisionDetection(Brick*);

		void SetCollisionLeft(bool);
		void SetCollisionRight(bool);
		void SetCollisionTop(bool);
		void SetCollisionBottom(bool);

		virtual void OnInit(vector<Brick*>) {};
		virtual void OnMove()=0;
		virtual void OnShow(int scale = DEFAULT_SCALE)=0;
	};

	class Bamboo : public Enemy {
	public:
		Bamboo();
		Bamboo(int, int);
		~Bamboo();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Chef : public Enemy {
	public:
		Chef();
		Chef(int, int);
		~Chef();

		void OnInit(vector<Brick*>);
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Earthworm : public Enemy {
	public:
		Earthworm();
		Earthworm(int, int);
		~Earthworm();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Fly : public Enemy {
	public:
		Fly();
		Fly(int, int);
		~Fly();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};
	
	class Groundhog : public Enemy {
	public:
		Groundhog();
		Groundhog(int, int);
		~Groundhog();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Insect : public Enemy {
	public:
		Insect();
		Insect(int, int);
		~Insect();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Ladybug : public Enemy {
	public:
		Ladybug();
		Ladybug(int, int);
		~Ladybug();

		void OnInit(vector<Brick*>);
		void OnMove();
		void OnShow(int scale = DEFAULT_SCALE);
	};

	class Mosquito : public Enemy {
	public:
		Mosquito();
		Mosquito(int, int);
		~Mosquito();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Penguin : public Enemy {
	public:
		Penguin();
		Penguin(int, int);
		~Penguin();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class PinkMonster : public Enemy {
	public:
		PinkMonster();
		PinkMonster(int, int);
		~PinkMonster();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Rocket : public Enemy {
	public:
		Rocket();
		Rocket(int, int);
		~Rocket();

		void OnInit(vector<Brick*>) ;
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Shark : public Enemy {
	public:
		Shark();
		Shark(int, int);
		~Shark();

		void OnInit(vector<Brick*>);
		void OnMove() ;
		void OnShow(int scale = DEFAULT_SCALE) ;
	};

	class Snails : public Enemy {
	public:
		Snails();
		Snails(int, int);
		~Snails();

		void OnInit(vector<Brick*>);
		void OnMove();
		void OnShow(int scale = DEFAULT_SCALE);
	};

	class Spider : public Enemy {
	private:
	public:
		Spider();
		Spider(int, int);
		~Spider();

		void OnInit(vector<Brick*>);
		void OnMove();
		void OnShow(int scale = DEFAULT_SCALE);
	};

	class Blue : public Enemy {
	public:
		Blue();
		Blue(int, int);
		~Blue();

		void OnInit(vector<Brick*>);
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	class FlyShield : public Enemy {
	public:
		FlyShield();
		FlyShield(int, int);
		~FlyShield();

		void OnInit(vector<Brick*>);
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	class Red : public Enemy {
	public:
		Red();
		Red(int, int);
		~Red();

		void OnInit(vector<Brick*>);
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};
}

#endif