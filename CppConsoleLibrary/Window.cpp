#include "Window.h"

void Window::BufferViewedInit()
{
	RectangleView::BufferViewedInit();

	if (borderStyle == BorderStyle::None) return;

	int* border = (borderStyle == BorderStyle::Single) ? Border::Single : Border::Double;

	int index{};

}