#ifndef _ENEMY_H_
#define _ENEMY_H_

namespace game_framework {

	enum class ENEMIES_LIST {
		// *ID (115 ~ 155) Needed to be changed*
		BAMBOO,
		CHEF,

		COUNT
	};


	class Enemy {
	public:
		Enemy();
		Enemy(int, int, int);
		~Enemy();

		int posX, posY;
		int angle;

		void setPos(int, int);
		void setAngle(int);

		virtual void OnInit() = 0;
		virtual void OnMove() = 0;
		virtual void OnShow() = 0;
	};

	class Bamboo : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Bamboo();
		Bamboo(int, int, int);
		~Bamboo();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Chef : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Chef();
		Chef(int, int, int);
		~Chef();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Earthworm : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Earthworm();
		Earthworm(int, int, int);
		~Earthworm();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Fly : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Fly();
		Fly(int, int, int);
		~Fly();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};
	
	class Groundhog : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Groundhog();
		Groundhog(int, int, int);
		~Groundhog();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Insect : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Insect();
		Insect(int, int, int);
		~Insect();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Ladybug : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Ladybug();
		Ladybug(int, int, int);
		~Ladybug();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Mosquito : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Mosquito();
		Mosquito(int, int, int);
		~Mosquito();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Penguin : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Penguin();
		Penguin(int, int, int);
		~Penguin();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class PinkMonster : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		PinkMonster();
		PinkMonster(int, int, int);
		~PinkMonster();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Rocket : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Rocket();
		Rocket(int, int, int);
		~Rocket();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Shark : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Shark();
		Shark(int, int, int);
		~Shark();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Snails : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Snails();
		Snails(int, int, int);
		~Snails();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Spider : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Spider();
		Spider(int, int, int);
		~Spider();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Blue : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Blue();
		Blue(int, int, int);
		~Blue();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class FlyShield : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		FlyShield();
		FlyShield(int, int, int);
		~FlyShield();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

	class Red : public Enemy {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;


	public:
		Red();
		Red(int, int, int);
		~Red();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

}

#endif