#include <iostream>
#include "RectangleView.h"

int main()
{
	Console* console = new Console("Hello world");
	
	RectangleView* rv = new RectangleView(
		console,
		Point(5, 5),
		Size(20, 5),
		Colors::Magenta);
	rv->Show();
	console->GetChar();

	RectangleView* rv2 = new RectangleView(
		console,
		Point(7, 7),
		Size(20, 5),
		Colors::Yellow);
	rv2->Show();
	console->GetChar();

	rv2->Hide();
	console->GetChar();
	
}
