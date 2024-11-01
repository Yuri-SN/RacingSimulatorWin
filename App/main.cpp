#include <Windows.h>
#include <iostream>

int main() {
//	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Проверка русского языка в консоли." << std::endl;

	return 0;
}
