#pragma once
#include "Rect.h"
#include "Console.h"

class RectangleView : public Rect
{
protected:
	Console* console{};

	CHAR_INFO* bufferViewed{};
	CHAR_INFO* bufferSaved{};

	virtual void BufferViewedInit();
	void BufferSavedInit();
public:
	RectangleView(Console* console,
				Point position,
				Size size,
				Colors backColor = Colors::Black,
				Colors foreColor = Colors::White)
				: Rect(position, size, backColor, foreColor),
		console{ console }
	{
		this->bufferViewed =
			new CHAR_INFO[this->size.width * this->size.height]{};
		this->bufferSaved =
			new CHAR_INFO[this->size.width * this->size.height]{};
	}

	void Show();
	void Hide();
};

