#pragma once
#include "RectangleView.h"
class Window : public RectangleView
{
protected:
	std::string title{ "" };
	bool shadow{ false };
	BorderStyle borderStyle{ BorderStyle::None };

	void BufferViewedInit() override;
	
};

