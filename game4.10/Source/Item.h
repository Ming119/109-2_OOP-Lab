#ifndef _ITEM_H_
#define _ITEM_H_

#include "Actor.h"

namespace game_framework {

	enum class ITEMS_LIST {
		RING,
	};

	class Item {
	protected:
		CAnimation texture;
		CAnimation deadAnimate;
		POINT pos;
		POINT delta;

		Actor* currnetActor;

		int angle;
		int speed;
		int cameraSpeed;

		bool isDead;
		bool isDeadFinish;
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


}

#endif