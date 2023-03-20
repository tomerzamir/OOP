#pragma once
#include "RectangleM.h"

class Rectangle3D : public RectangleM
{
	DECLARE_SERIAL(Rectangle3D)
public:
	Rectangle3D();
	Rectangle3D(CPoint P1, CPoint P2, COLORREF bkColour, bool bold);
	~Rectangle3D();
	void Draw(CDC* dc);
};
