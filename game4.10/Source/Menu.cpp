#include "stdafx.h"
#include "Menu.h"

namespace game_framework {
	Menu::Menu(int _total_selection) {
		total_selection = _total_selection;
	}

	Menu::~Menu() {

	}

	void Menu::chooseUp() {
		current_selection--;
		if (current_selection == -1) {
			current_selection = total_selection - 1;
		}
	}

	void Menu::chooseDown() {
		current_selection++;
		current_selection %= total_selection;
	}

	int Menu::getSelection() {
		return current_selection;
	}
}