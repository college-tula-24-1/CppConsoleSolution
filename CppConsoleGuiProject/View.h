#pragma once
#include "Console.h"

class View
{
protected:
	static Console* console;
	static int globalId;

	int id;
	Position position;
	Size size;
	Colors backColor;
	Colors foreColor;

	bool isVisible{};

	CHAR_INFO* bufferViewed{};
	CHAR_INFO* bufferSaved{};

	virtual void BufferViewedInit();
	virtual void BufferSavedInit();

public:
	View(Position position, Size size, Colors backColor, Colors foreColor);
	View(Position position, Size size);
	View();

	virtual ~View();

	int Id() const;

	static Console* GetConsole();

	Position GetPosition() const;
	int Row() const;
	int Column() const;

	Size GetSize() const;
	int Width() const;
	int Height() const;

	Colors BackColor() const;
	void BackColor(Colors backColor);

	Colors ForeColor() const;
	void ForeColor(Colors foreColor);

	bool IsVisible() const;

	virtual void Move(Position position);
	virtual void Move(int row, int column);

	virtual void Resize(Size size);
	virtual void Resize(int width, int height);

	virtual void Show();
	virtual void Hide();
};
