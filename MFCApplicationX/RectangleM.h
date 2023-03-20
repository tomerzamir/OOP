#include"pch.h"
#pragma once
#include"Figure.h"

class RectangleM :public Figure
{
	DECLARE_SERIAL(RectangleM)
public:
	RectangleM();
	RectangleM(CPoint p1, CPoint p2, COLORREF bkColour,bool bold);
	virtual ~RectangleM();
	virtual void Draw(CDC* dc);
};
