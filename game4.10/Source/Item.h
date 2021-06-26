#ifndef _ITEM_H_
#define _ITEM_H_

#include "Actor.h"

namespace game_framework {

	enum class ITEMS_LIST {
		RING,
		BIG_RING,
		/*RED_SPRING_PADS_UP,
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
		BULE_SPRING_PADS_RING_D,*/
		GATE_YELLOW,
		SEND,
		/*
		SEND_BUTTON,
		LOOP_LEFT,
		LOOR_RING,
		LOOP_TOP,
		LOOP_TOP_HIED,
		LOOP_OFF,
		LOOP_TOP_NOT_U_D,
		LOOP_TOP_UP_DOWN,
		*/
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

		int id;
		
	public:
		/* Contrustor */
		Item(int, int, int);
		~Item();

		/* Getter */
		int ID();
		int Width();
		int Height();
		int Top();
		int Left();
		int Bottom();
		int Right();
		
		/* Setter */
		void SetID(int);
		void SetMoving(POINT);
		void SetCurrentActor(Actor*);
		void setTopLeft(int, int);
		void setTopLeft(POINT);

		/* Member Function */
		void CameraMove();
		bool CollisionDetection(Actor*);

		//
		virtual bool IsChange() = 0;

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
		Ring(int, int, int);
		~Ring();

		bool IsChange() override;

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
		BIG_Ring(int, int, int);
		~BIG_Ring();
		
		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	/*
	// RED_SPRING_PADS_UP
	class RED_SPRING_PADS_UP : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_UP(int, int, int);
		~RED_SPRING_PADS_UP();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_DOWN
	class RED_SPRING_PADS_DOWN : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_DOWN(int, int, int);
		~RED_SPRING_PADS_DOWN();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT
	class RED_SPRING_PADS_LEFT : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_LEFT(int, int, int);
		~RED_SPRING_PADS_LEFT();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT_U
	class RED_SPRING_PADS_LEFT_U : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_LEFT_U(int, int, int);
		~RED_SPRING_PADS_LEFT_U();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_LEFT_D
	class RED_SPRING_PADS_LEFT_D : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_LEFT_D(int, int, int);
		~RED_SPRING_PADS_LEFT_D();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING
	class RED_SPRING_PADS_RING : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_RING(int, int, int);
		~RED_SPRING_PADS_RING();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING_U
	class RED_SPRING_PADS_RING_U : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_RING_U(int, int, int);
		~RED_SPRING_PADS_RING_U();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// RED_SPRING_PADS_RING_D
	class RED_SPRING_PADS_RING_D : public Item {
	private:
		bool isTouch;

	public:
		RED_SPRING_PADS_RING_D(int, int, int);
		~RED_SPRING_PADS_RING_D();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_UP
	class YELLOW_SPRING_PADS_UP : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_UP(int, int, int);
		~YELLOW_SPRING_PADS_UP();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_DOWN
	class YELLOW_SPRING_PADS_DOWN : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_DOWN(int, int, int);
		~YELLOW_SPRING_PADS_DOWN();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT
	class YELLOW_SPRING_PADS_LEFT : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_LEFT(int, int, int);
		~YELLOW_SPRING_PADS_LEFT();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT_U
	class YELLOW_SPRING_PADS_LEFT_U : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_LEFT_U(int, int, int);
		~YELLOW_SPRING_PADS_LEFT_U();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_LEFT_D
	class YELLOW_SPRING_PADS_LEFT_D : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_LEFT_D(int, int, int);
		~YELLOW_SPRING_PADS_LEFT_D();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING
	class YELLOW_SPRING_PADS_RING : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_RING(int, int, int);
		~YELLOW_SPRING_PADS_RING();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING_U
	class YELLOW_SPRING_PADS_RING_U : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_RING_U(int, int, int);
		~YELLOW_SPRING_PADS_RING_U();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// YELLOW_SPRING_PADS_RING_D
	class YELLOW_SPRING_PADS_RING_D : public Item {
	private:
		bool isTouch;

	public:
		YELLOW_SPRING_PADS_RING_D(int, int, int);
		~YELLOW_SPRING_PADS_RING_D();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_UP
	class BULE_SPRING_PADS_UP : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_UP(int, int, int);
		~BULE_SPRING_PADS_UP();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_DOWN
	class BULE_SPRING_PADS_DOWN : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_DOWN(int, int, int);
		~BULE_SPRING_PADS_DOWN();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT
	class BULE_SPRING_PADS_LEFT : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_LEFT(int, int, int);
		~BULE_SPRING_PADS_LEFT();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT_U
	class BULE_SPRING_PADS_LEFT_U : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_LEFT_U(int, int, int);
		~BULE_SPRING_PADS_LEFT_U();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_LEFT_D
	class BULE_SPRING_PADS_LEFT_D : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_LEFT_D(int, int, int);
		~BULE_SPRING_PADS_LEFT_D();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING
	class BULE_SPRING_PADS_RING : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_RING(int, int, int);
		~BULE_SPRING_PADS_RING();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING_U
	class BULE_SPRING_PADS_RING_U : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_RING_U(int, int, int);
		~BULE_SPRING_PADS_RING_U();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// BULE_SPRING_PADS_RING_D
	class BULE_SPRING_PADS_RING_D : public Item {
	private:
		bool isTouch;

	public:
		BULE_SPRING_PADS_RING_D(int, int, int);
		~BULE_SPRING_PADS_RING_D();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};
	*/

	// GATE_YELLOW
	class GATE_YELLOW : public Item {
	public:
		GATE_YELLOW(int, int, int);
		~GATE_YELLOW();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// SEND
	class SEND : public Item {
	public:
		SEND(int, int,int);
		~SEND();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	/*
	// SEND_BUTTON
	class SEND_BUTTON : public Item {
	public:
		SEND_BUTTON(int, int, int);
		~SEND_BUTTON();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};
	

	// LOOP_LEFT
	class LOOP_LEFT : public Item {
	public:
		LOOP_LEFT(int, int, int);
		~LOOP_LEFT();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_RIGHT
	class LOOP_RIGHT : public Item {
	public:
		LOOP_RIGHT(int, int, int);
		~LOOP_RIGHT();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP
	class LOOP_TOP : public Item {
	public:
		LOOP_TOP(int, int, int);
		~LOOP_TOP();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP_HIED
	class LOOP_TOP_HIED : public Item {
	public:
		LOOP_TOP_HIED(int, int, int);
		~LOOP_TOP_HIED();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_OFF
	class LOOP_OFF : public Item {
	public:
		LOOP_OFF(int, int, int);
		~LOOP_OFF();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP_NOT_U_D
	class LOOP_TOP_NOT_U_D : public Item {
	public:
		LOOP_TOP_NOT_U_D(int, int, int);
		~LOOP_TOP_NOT_U_D();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	// LOOP_TOP_UP_DOWN
	class LOOP_TOP_UP_DOWN : public Item {
	public:
		LOOP_TOP_UP_DOWN(int, int, int);
		~LOOP_TOP_UP_DOWN();

		bool IsChange() override;

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};

	*/

	// SPIKES_UP
	class SPIKES_UP : public Item {
	private:
		bool isShow;
		int counter;

	public:
		SPIKES_UP(int, int, int);
		~SPIKES_UP();

		bool IsChange() override;
		bool IsShow();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	// SPIKES_DOWN
	class SPIKES_DOWN : public Item {
	private:
		bool isShow;
		int counter;

	public:
		SPIKES_DOWN(int, int, int);
		~SPIKES_DOWN();

		bool IsChange() override;
		bool IsShow();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	// SPIKES_LEFT
	class SPIKES_LEFT : public Item {
	private:
		bool isShow;
		int counter;

	public:
		SPIKES_LEFT(int, int, int);
		~SPIKES_LEFT();

		bool IsChange() override;
		bool IsShow();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};

	// SPIKES_RIGHT
	class SPIKES_RIGHT : public Item {
	private:
		bool isShow;
		int counter;

	public:
		SPIKES_RIGHT(int, int, int);
		~SPIKES_RIGHT();

		bool IsChange() override;
		bool IsShow();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale=DEFAULT_SCALE) override;
	};
}

#endif