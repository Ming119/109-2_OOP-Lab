#ifndef _ITEM_H_
#define _ITEM_H_

namespace game_framework {

	enum class ITEMS_LIST {
		RING,
	};

	class Item {
	protected:
		CAnimation texture;
		POINT spawn;
		POINT pos;

		int posX, posY;
		int angle;
		int speed;
		int cameraSpeed;

		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;

	public:
		Item();
		Item(int, int, int);
		~Item();

		void setPos(int, int);
		void setAngle(int);


		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetMoveUp(bool);
		void SetMoveDown(bool);

		virtual void OnInit() = 0;
		virtual void OnMove() = 0;
		virtual void OnShow(int scale = DEFAULT_SCALE) = 0;
	};
	
	class Ring: public Item {
	public: 
		Ring();
		Ring(int, int, int);
		~Ring();

		void OnInit() override;
		void OnMove() override;
		void OnShow(int scale = DEFAULT_SCALE) override;
	};


}

#endif