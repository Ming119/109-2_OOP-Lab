#ifndef _ITEM_H_
#define _ITEM_H_

namespace game_framework {
	//int item_list[] = {
	//	// id

	//};

	class Item {
	public:
		Item();
		Item(int, int);
		~Item();

		virtual void OnInit() = 0;
		virtual void OnMove() = 0;
		virtual void OnShow() = 0;
	};
	
	class Ring: public Item {
	public: 
		void OnInit() override;
		void OnMove() override;
		void OnShow() override;
	};

}

#endif