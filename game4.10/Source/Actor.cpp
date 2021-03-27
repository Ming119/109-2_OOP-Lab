#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Actor.h"
#include "Brick.h"

namespace game_framework {
	Actor::Actor() {
		spawnPoint.x = 0;
		spawnPoint.y = 0;
		position.x = spawnPoint.x;
		position.y = spawnPoint.y;
		angle = 0;
		speed.x = 0;
		speed.y = 0;
		maxSpeed = 0;
		acceleration = 0;
		jumpStrength = 0;
		isJumping = false;
		ignoreHorizontal = false;
	}

	Actor::~Actor() {
	
	}


}