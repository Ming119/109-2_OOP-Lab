#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Brick.h"

namespace game_framework {
	Brick::Brick(int theme, int id) {
		texture.LoadBitmap(themes[theme][id][0]);
		property = themes[theme][id][1];
		behavior = themes[theme][id][2];
		angel = themes[theme][id][3];
	}
}
