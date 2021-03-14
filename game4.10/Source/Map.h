#pragma once

namespace framework {
	class Map {
	public:
		Map();
		void LoadBitmap();
		void OnShow();

		void OnMove();
		void OnKeyDown(UINT);
		void RandomBouncingBall();
		void InitializeBouncingBall(int, int, int);
		~Map();

	protected:
		CMovingBitmap blue, green;
		int map[4][5];
		const int X, Y;
		const int MW, MH;

		CBouncingBall* bballs;
		int random_num;
	};

}