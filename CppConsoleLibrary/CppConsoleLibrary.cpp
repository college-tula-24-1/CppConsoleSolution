#include <iostream>
#include "Console.h"

int main()
{
	Console* console = new Console("Hello world");

	console->CursorPosition(3, 10);
	console->CursorSize(1);
	console->Write("Hello world");

	char c;
	std::cin >> c;
}
