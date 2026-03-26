#pragma once
#include "View.h"
class Window : public View
{
protected:
	std::string title;
	BorderStyle style;

	void BufferViewedInit() override;
public:
	Window(Position position,
		Size size,
		Colors backColor,
		Colors foreColor,
		std::string title,
		BorderStyle style);

	Window();
};

