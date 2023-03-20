#include "pch.h"
#include "RectangleM.h"

IMPLEMENT_SERIAL(RectangleM, CObject, 1)

RectangleM::RectangleM()
{
}

RectangleM::RectangleM(CPoint p1, CPoint p2, COLORREF bkColour, bool bold)
	:Figure(p1, p2, bkColour, bold)
{
}

void RectangleM::Draw(CDC* dc)
{
	CBrush bkGround1;
	CPen border1;
	bkGround1.CreateSolidBrush(this->bkColour);
	border1.CreatePen(PS_SOLID, this->bold ? 4 : 1, black);
	dc->SelectObject(border1);
	dc->SelectObject(bkGround1);
	dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}

RectangleM::~RectangleM()
{
}

