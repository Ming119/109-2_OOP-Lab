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
		bool direction;

	public:
		/* Constructor */
		Enemy(int, int);
		~Enemy();

		/* Getter */
		int Angle();
		int Height();
		int Width();
		int Top();
		int Left();
		int Bottom();
		int Right();

		/* Setter */
		void SetAngle(int);
		void SetSpeed(int);
		void SetMoving(POINT);
		void SetTopLeft(int, int);
		void SetTopLeft(POINT);

		/* Member Function */
		void LookingForRefBrick(vector<Brick*>);
		bool CollisionDetection(Brick*);
		void CameraMovement();

		//
		virtual void OnInit(vector<Brick*>) = 0;
		virtual void OnMove() = 0;
		virtual void OnShow(int scale=DEFAULT_SCALE) = 0;
	};



	/* Inheritance Enemy Class */
	class Bamboo : public Enemy {
	public:
		Bamboo(int, int);
		~Bamboo();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Chef : public Enemy {
	public:
		Chef(int, int);
		~Chef();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Earthworm : public Enemy {
	public:
		Earthworm(int, int);
		~Earthworm();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Fly : public Enemy {
	public:
		Fly(int, int);
		~Fly();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};
	
	class Groundhog : public Enemy {
	public:
		Groundhog(int, int);
		~Groundhog();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Insect : public Enemy {
	public:
		Insect(int, int);
		~Insect();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Ladybug : public Enemy {
	public:
		Ladybug(int, int);
		~Ladybug();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	class Mosquito : public Enemy {
	public:
		Mosquito(int, int);
		~Mosquito();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Penguin : public Enemy {
	public:
		Penguin(int, int);
		~Penguin();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class PinkMonster : public Enemy {
	public:
		PinkMonster(int, int);
		~PinkMonster();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Rocket : public Enemy {
	public:
		Rocket(int, int);
		~Rocket();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Shark : public Enemy {
	public:
		Shark(int, int);
		~Shark();

		void OnInit(vector<Brick*>)override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Snails : public Enemy {
	public:
		Snails(int, int);
		~Snails();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Spider : public Enemy {
	public:
		Spider(int, int);
		~Spider();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Blue : public Enemy {
	public:
		Blue(int, int);
		~Blue();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class FlyShield : public Enemy {
	public:
		FlyShield(int, int);
		~FlyShield();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	class Red : public Enemy {
	public:
		Red(int, int);
		~Red();

		void OnInit(vector<Brick*>) override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

}

#endif