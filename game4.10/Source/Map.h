#pragma once

namespace framework {

	class Map {
	public:
		Map();
		void LoadBitmap();
		void OnShow();

		void OnMove();
		~Map();

	protected:
		int map[4][5];
		const int X, Y;
		const int MW, MH;
	};

}