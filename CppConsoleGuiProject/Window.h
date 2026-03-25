#pragma once
#include "View.h"
class Window : public View
{
	std::string title;
	BorderStyle style;
protected:
	void BufferViewedInit() override;
public:
	Window(Position position,
		Size size,
		Colors backColor,
		Colors foreColor,
		std::string title,
		BorderStyle style);


};

