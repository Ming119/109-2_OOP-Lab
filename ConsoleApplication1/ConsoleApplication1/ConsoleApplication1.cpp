// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool Guess(int number) {

	static int target = -1;
	
	srand(time(NULL));
	if (target == -1) {
		target = rand() % 100 + 1;
	}

	if (number == target) {
		std::cout << "Correct !!";
		target = -1;
		return true;
	}
	else if (number > target) std::cout << "Smaller" << std::endl;
	else if (number < target) std::cout << "Bigger" << std::endl;
	return false;
}

int main() {


	int guess;
	do {
		cout << "Choose a number between 1- 100 :";
		cin >> guess;
	} while (!Guess(guess));

	return 0;
}