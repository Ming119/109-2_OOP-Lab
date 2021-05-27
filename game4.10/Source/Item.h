#ifndef _ITEM_H_
#define _ITEM_H_

#include "Actor.h"

namespace game_framework {

	enum class ITEMS_LIST {
		RING,
		BIG_RING,
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
		GATE_YELLOW,
		SEND,
		SEND_BUTTON,
		LOOP_LEFT,
		LOOR_RING,
		LOOP_TOP,
		LOOP_TOP_HIED,
		LOOP_OFF,
		LOOP_TOP_NOT_U_D,
		LOOP_TOP_UP_DOWN,
		SPIKES_UP,
		SPIKES_DOWN,
		SPIKES_LEFT,
		SPIKES_RING,
	};

	class Item {
	protected:
		CAnimation texture;

		POINT pos;
		POINT delta;

		Actor* currnetActor;

		int angle;
		int speed;
		int cameraSpeed;
		



	public:
		/* Contrustor */
		Item(int, int);

		/* Getter */
		int Width();
		int Height();
		int Top();
		int Left();
		int Buttom();
		int Right();
		bool IsDead();
		
		/* Setter */
		void setAngle(int);
		void SetMoving(POINT);
		void SetCurrentActor(Actor*);
		void setTopLeft(int, int);
		void setTopLeft(POINT);

		/* Member Function */
		void CameraMove();
		bool CollisionDetection(Actor*);

		//
		virtual void OnInit() = 0;
		virtual void OnMove() = 0;
		virtual void OnShow(int scale=DEFAULT_SCALE) = 0;
	};
	
	
	// Ring
	class Ring: public Item {
	private:
		CAnimation deadAnimate;

		bool isDead;
		bool isDeadFinish;

	public: 
		Ring(int, int);
		~Ring();

		bool IsDead();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	// BIG_Ring
	class BIG_Ring : public Item {
	private:
		CAnimation deadAnimate;

		bool isDead;
		bool isDeadFinish;

	public:
		BIG_Ring(int, int);
		~BIG_Ring();
		
		bool IsDead();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_UP
	class RED_SPRING_PADS_UP : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_UP(int, int);
		~RED_SPRING_PADS_UP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_DOWN
	class RED_SPRING_PADS_DOWN : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_DOWN(int, int);
		~RED_SPRING_PADS_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT
	class RED_SPRING_PADS_LEFT : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_LEFT(int, int);
		~RED_SPRING_PADS_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT_U
	class RED_SPRING_PADS_LEFT_U : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_LEFT_U(int, int);
		~RED_SPRING_PADS_LEFT_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT_D
	class RED_SPRING_PADS_LEFT_D : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_LEFT_D(int, int);
		~RED_SPRING_PADS_LEFT_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING
	class RED_SPRING_PADS_RING : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_RING(int, int);
		~RED_SPRING_PADS_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING_U
	class RED_SPRING_PADS_RING_U : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_RING_U(int, int);
		~RED_SPRING_PADS_RING_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING_D
	class RED_SPRING_PADS_RING_D : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_RING_D(int, int);
		~RED_SPRING_PADS_RING_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_UP
	class YELLOW_SPRING_PADS_UP : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_UP(int, int);
		~YELLOW_SPRING_PADS_UP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_DOWN
	class YELLOW_SPRING_PADS_DOWN : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_DOWN(int, int);
		~YELLOW_SPRING_PADS_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT
	class YELLOW_SPRING_PADS_LEFT : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_LEFT(int, int);
		~YELLOW_SPRING_PADS_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT_U
	class YELLOW_SPRING_PADS_LEFT_U : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_LEFT_U(int, int);
		~YELLOW_SPRING_PADS_LEFT_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT_D
	class YELLOW_SPRING_PADS_LEFT_D : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_LEFT_D(int, int);
		~YELLOW_SPRING_PADS_LEFT_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING
	class YELLOW_SPRING_PADS_RING : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_RING(int, int);
		~YELLOW_SPRING_PADS_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING_U
	class YELLOW_SPRING_PADS_RING_U : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_RING_U(int, int);
		~YELLOW_SPRING_PADS_RING_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING_D
	class YELLOW_SPRING_PADS_RING_D : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_RING_D(int, int);
		~YELLOW_SPRING_PADS_RING_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_UP
	class BULE_SPRING_PADS_UP : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_UP(int, int);
		~BULE_SPRING_PADS_UP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_DOWN
	class BULE_SPRING_PADS_DOWN : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_DOWN(int, int);
		~BULE_SPRING_PADS_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT
	class BULE_SPRING_PADS_LEFT : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_LEFT(int, int);
		~BULE_SPRING_PADS_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT_U
	class BULE_SPRING_PADS_LEFT_U : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_LEFT_U(int, int);
		~BULE_SPRING_PADS_LEFT_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT_D
	class BULE_SPRING_PADS_LEFT_D : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_LEFT_D(int, int);
		~BULE_SPRING_PADS_LEFT_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING
	class BULE_SPRING_PADS_RING : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_RING(int, int);
		~BULE_SPRING_PADS_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING_U
	class BULE_SPRING_PADS_RING_U : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_RING_U(int, int);
		~BULE_SPRING_PADS_RING_U();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING_D
	class BULE_SPRING_PADS_RING_D : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_RING_D(int, int);
		~BULE_SPRING_PADS_RING_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};
	
	// GATE_YELLOW
	class GATE_YELLOW : public Item {
	public:
		GATE_YELLOW(int, int);
		~GATE_YELLOW();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// SEND
	class SEND : public Item {
	public:
		SEND(int,int);
		~SEND();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// SEND_BUTTON
	class SEND_BUTTON : public Item {
	public:
		SEND_BUTTON(int, int);
		~SEND_BUTTON();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_LEFT
	class LOOP_LEFT : public Item {
	public:
		LOOP_LEFT(int, int);
		~LOOP_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOR_RING
	class LOOR_RING : public Item {
	public:
		LOOR_RING(int, int);
		~LOOR_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP
	class LOOP_TOP : public Item {
	public:
		LOOP_TOP(int, int);
		~LOOP_TOP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP_HIED
	class LOOP_TOP_HIED : public Item {
	public:
		LOOP_TOP_HIED(int, int);
		~LOOP_TOP_HIED();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_OFF
	class LOOP_OFF : public Item {
	public:
		LOOP_OFF(int, int);
		~LOOP_OFF();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP_NOT_U_D
	class LOOP_TOP_NOT_U_D : public Item {
	public:
		LOOP_TOP_NOT_U_D(int, int);
		~LOOP_TOP_NOT_U_D();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP_UP_DOWN
	class LOOP_TOP_UP_DOWN : public Item {
	public:
		LOOP_TOP_UP_DOWN(int, int);
		~LOOP_TOP_UP_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// SPIKES_UP
	class SPIKES_UP : public Item {
	public:
		SPIKES_UP(int, int);
		~SPIKES_UP();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	// SPIKES_DOWN
	class SPIKES_DOWN : public Item {
	public:
		SPIKES_DOWN(int, int);
		~SPIKES_DOWN();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	// SPIKES_LEFT
	class SPIKES_LEFT : public Item {
	public:
		SPIKES_LEFT(int, int);
		~SPIKES_LEFT();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	// SPIKES_RING
	class SPIKES_RING : public Item {
	public:
		SPIKES_RING(int, int);
		~SPIKES_RING();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

}

#endif