#ifndef _ITEM_H_
#define _ITEM_H_

namespace game_framework {

	enum class ITEMS_LIST {
		RING,
	};

	class Item {
	protected:
		CAnimation texture;
		int posX, posY;
		int angle;

	public:
		Item();
		Item(int, int, int);
		~Item();

		void setPos(int, int);
		void setAngle(int);

		virtual void OnInit() = 0;
		virtual void OnMove() = 0;
		virtual void OnShow() = 0;
	};
	
	class Ring: public Item {
	public: 
		Ring();
		Ring(int, int, int);
		~Ring();

		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

}

#endif