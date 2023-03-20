#include "pch.h"
#include "RoundRectangle.h"

IMPLEMENT_SERIAL(RoundRectangle, CObject, 1)

RoundRectangle::RoundRectangle()
{
}

RoundRectangle::RoundRectangle(CPoint p1, CPoint p2, COLORREF bkColour, bool bold)
	:RectangleM(p1, p2, bkColour, bold)
{
}

RoundRectangle::~RoundRectangle()
{
}

void RoundRectangle::Draw(CDC* dc)
{
	CBrush bkGround1;
	CPen border1;
	bkGround1.CreateSolidBrush(this->bkColour);
	border1.CreatePen(PS_SOLID, this->bold ? 4 : 1, black);
	dc->SelectObject(border1);
	dc->SelectObject(bkGround1);
	dc->RoundRect(p1.x, p1.y, p2.x, p2.y, 20, 20);
}
