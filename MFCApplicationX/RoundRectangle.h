#pragma once
#include "RectangleM.h"

class RoundRectangle :public RectangleM
{
	DECLARE_SERIAL(RoundRectangle)
public:
	RoundRectangle();
	RoundRectangle(CPoint, CPoint, COLORREF bkColour, bool bold);
	~RoundRectangle();
	void Draw(CDC* dc);
};
