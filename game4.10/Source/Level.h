#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Brick.h"

namespace game_framework {

	enum class LEVELS {
		BULE_OCEAN_1,
		BULE_OCEAN_2,
		BULE_OCEAN_3,
		CHILPOCTLI_TEMPLE,
		EXOTIC_HELL,
		EXOTIC_PARADISE_1,
		EXOTIC_PARADISE_2,
		EXOTIC_PARADISE_3,
		PROTOTYPE_1,
		SUPER_BOSS_1,
		SUPER_BOSS_2,
		TEMPLATE,
		TEST,
		TUTORIAL_1,
		TUTORIAL_2,
		COUNT
	};

	class Level {
	private:
		int max_x;
		int max_y;
		int spawnPoint;

		CMovingBitmap background;
		
		vector<Brick> bricks;
		vector<Item> items;
		vector<Enemy> enemies;

	public:
		void OnInit(int);
		void OnMove();
		void OnShow();
	};

	int test[][][3] = {

	};
}

#endif