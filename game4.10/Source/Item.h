#ifndef _ITEM_H_
#define _ITEM_H_

namespace game_framework {

	enum class ITEMS_LIST {
		RING,
	};

	class Item {
	public:
		Item();
		Item(int, int, int);
		~Item();

		int posX, posY;
		int angle;

		void setPos(int, int);
		void setAngle(int);

		virtual void OnInit() = 0;
		virtual void OnMove() = 0;
		virtual void OnShow() = 0;
	};
	
	class Ring: public Item {
	private:
		CAnimation texture;
		int posX, posY;
		int angle;

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