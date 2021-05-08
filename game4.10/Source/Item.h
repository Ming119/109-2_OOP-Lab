#ifndef _ITEM_H_
#define _ITEM_H_

#include "Actor.h"

namespace game_framework {

	enum class ITEMS_LIST {
		RING,
		RED_SPRING_PADS_UP,
		RED_SPRING_PADS_DOWN,
		RED_SPRING_PADS_LEFT,
		RED_SPRING_PADS_LEFT_U,
		RED_SPRING_PADS_LEFT_D,
		RED_SPRING_PADS_RING,
		RED_SPRING_PADS_RING_U,
		RED_SPRING_PADS_RING_D,
		YELLOW_SPRING_PADS_UP,
		YELLOW_SPRING_PADS_DOWN,
		YELLOW_SPRING_PADS_LEFT,
		YELLOW_SPRING_PADS_LEFT_U,
		YELLOW_SPRING_PADS_LEFT_D,
		YELLOW_SPRING_PADS_RING,
		YELLOW_SPRING_PADS_RING_U,
		YELLOW_SPRING_PADS_RING_D,
		BULE_SPRING_PADS_UP,
		BULE_SPRING_PADS_DOWN,
		BULE_SPRING_PADS_LEFT,
		BULE_SPRING_PADS_LEFT_U,
		BULE_SPRING_PADS_LEFT_D,
		BULE_SPRING_PADS_RING,
		BULE_SPRING_PADS_RING_U,
		BULE_SPRING_PADS_RING_D,

	};

	class Item {
	protected:
		CAnimation texture;
		CAnimation deadAnimate;
		CAnimation bounceAnimate;
		POINT pos;
		POINT delta;

		Actor* currnetActor;

		int angle;
		int speed;
		int cameraSpeed;

		bool isDead;
		bool isDeadFinish;
		bool isBounce;
		bool isBounceFinish;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;

	public:
		Item(int, int);

		int Top();
		int Left();
		int Height();
		int Width();



		void setTopLeft(int, int);
		void setTopLeft(POINT);
		void setAngle(int);

		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetMoveUp(bool);
		void SetMoveDown(bool);
		void SetMoving(POINT);

		void SetCurrentActor(Actor*);

		bool CollisionDetection(Actor*);
		bool IsDead();
		bool IsBounce();

		virtual void OnInit() = 0;
		virtual void OnMove() = 0;
		virtual void OnShow(int scale = DEFAULT_SCALE) = 0;
	};
	

	// Ring
	class Ring: public Item {
	public: 
		Ring(int, int);
		~Ring();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_UP
	class RED_SPRING_PADS_UP : public Item {
	public:
		RED_SPRING_PADS_UP();
		RED_SPRING_PADS_UP(int, int);
		~RED_SPRING_PADS_UP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_DOWN
	class RED_SPRING_PADS_DOWN : public Item {
	public:
		RED_SPRING_PADS_DOWN();
		RED_SPRING_PADS_DOWN(int, int);
		~RED_SPRING_PADS_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT
	class RED_SPRING_PADS_LEFT : public Item {
	public:
		RED_SPRING_PADS_LEFT();
		RED_SPRING_PADS_LEFT(int, int);
		~RED_SPRING_PADS_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT_U
	class RED_SPRING_PADS_LEFT_U : public Item {
	public:
		RED_SPRING_PADS_LEFT_U();
		RED_SPRING_PADS_LEFT_U(int, int);
		~RED_SPRING_PADS_LEFT_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT_D
	class RED_SPRING_PADS_LEFT_D : public Item {
	public:
		RED_SPRING_PADS_LEFT_D();
		RED_SPRING_PADS_LEFT_D(int, int);
		~RED_SPRING_PADS_LEFT_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING
	class RED_SPRING_PADS_RING : public Item {
	public:
		RED_SPRING_PADS_RING();
		RED_SPRING_PADS_RING(int, int);
		~RED_SPRING_PADS_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING_U
	class RED_SPRING_PADS_RING_U : public Item {
	public:
		RED_SPRING_PADS_RING_U();
		RED_SPRING_PADS_RING_U(int, int);
		~RED_SPRING_PADS_RING_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING_D
	class RED_SPRING_PADS_RING_D : public Item {
	public:
		RED_SPRING_PADS_RING_D();
		RED_SPRING_PADS_RING_D(int, int);
		~RED_SPRING_PADS_RING_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_UP
	class YELLOW_SPRING_PADS_UP : public Item {
	public:
		YELLOW_SPRING_PADS_UP();
		YELLOW_SPRING_PADS_UP(int, int);
		~YELLOW_SPRING_PADS_UP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_DOWN
	class YELLOW_SPRING_PADS_DOWN : public Item {
	public:
		YELLOW_SPRING_PADS_DOWN();
		YELLOW_SPRING_PADS_DOWN(int, int);
		~YELLOW_SPRING_PADS_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT
	class YELLOW_SPRING_PADS_LEFT : public Item {
	public:
		YELLOW_SPRING_PADS_LEFT();
		YELLOW_SPRING_PADS_LEFT(int, int);
		~YELLOW_SPRING_PADS_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT_U
	class YELLOW_SPRING_PADS_LEFT_U : public Item {
	public:
		YELLOW_SPRING_PADS_LEFT_U();
		YELLOW_SPRING_PADS_LEFT_U(int, int);
		~YELLOW_SPRING_PADS_LEFT_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT_D
	class YELLOW_SPRING_PADS_LEFT_D : public Item {
	public:
		YELLOW_SPRING_PADS_LEFT_D();
		YELLOW_SPRING_PADS_LEFT_D(int, int);
		~YELLOW_SPRING_PADS_LEFT_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING
	class YELLOW_SPRING_PADS_RING : public Item {
	public:
		YELLOW_SPRING_PADS_RING();
		YELLOW_SPRING_PADS_RING(int, int);
		~YELLOW_SPRING_PADS_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING_U
	class YELLOW_SPRING_PADS_RING_U : public Item {
	public:
		YELLOW_SPRING_PADS_RING_U();
		YELLOW_SPRING_PADS_RING_U(int, int);
		~YELLOW_SPRING_PADS_RING_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING_D
	class YELLOW_SPRING_PADS_RING_D : public Item {
	public:
		YELLOW_SPRING_PADS_RING_D();
		YELLOW_SPRING_PADS_RING_D(int, int);
		~YELLOW_SPRING_PADS_RING_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_UP
	class BULE_SPRING_PADS_UP : public Item {
	public:
		BULE_SPRING_PADS_UP();
		BULE_SPRING_PADS_UP(int, int);
		~BULE_SPRING_PADS_UP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_DOWN
	class BULE_SPRING_PADS_DOWN : public Item {
	public:
		BULE_SPRING_PADS_DOWN();
		BULE_SPRING_PADS_DOWN(int, int);
		~BULE_SPRING_PADS_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT
	class BULE_SPRING_PADS_LEFT : public Item {
	public:
		BULE_SPRING_PADS_LEFT();
		BULE_SPRING_PADS_LEFT(int, int);
		~BULE_SPRING_PADS_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT_U
	class BULE_SPRING_PADS_LEFT_U : public Item {
	public:
		BULE_SPRING_PADS_LEFT_U();
		BULE_SPRING_PADS_LEFT_U(int, int);
		~BULE_SPRING_PADS_LEFT_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT_D
	class BULE_SPRING_PADS_LEFT_D : public Item {
	public:
		BULE_SPRING_PADS_LEFT_D();
		BULE_SPRING_PADS_LEFT_D(int, int);
		~BULE_SPRING_PADS_LEFT_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING
	class BULE_SPRING_PADS_RING : public Item {
	public:
		BULE_SPRING_PADS_RING();
		BULE_SPRING_PADS_RING(int, int);
		~BULE_SPRING_PADS_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING_U
	class BULE_SPRING_PADS_RING_U : public Item {
	public:
		BULE_SPRING_PADS_RING_U();
		BULE_SPRING_PADS_RING_U(int, int);
		~BULE_SPRING_PADS_RING_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING_D
	class BULE_SPRING_PADS_RING_D : public Item {
	public:
		BULE_SPRING_PADS_RING_D();
		BULE_SPRING_PADS_RING_D(int, int);
		~BULE_SPRING_PADS_RING_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

}

#endif