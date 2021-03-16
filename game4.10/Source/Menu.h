#pragma once

namespace game_framework {
	enum Menu_ID {
		MENU_START_GAME,
		MENU_TUTORIAL,
		MENU_EXTRAS,
		MENU_OPTIONS,
		MENU_EXIT
	};

	class Menu {
	public:
		Menu(int);
		~Menu();

		void chooseUp();
		void chooseDown();
		int getSelection();

	private:
		int total_selection = 0;
		int current_selection = 0;
	};

	class MainMenu : public Menu {

	};

	class Options : public Menu {

	};

	class Extras : public Menu {

	};

}
