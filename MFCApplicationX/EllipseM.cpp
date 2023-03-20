#include "pch.h"
#include "EllipseM.h"


IMPLEMENT_SERIAL(EllipseM, CObject, 1)

EllipseM::EllipseM()
{
}

EllipseM::EllipseM(CPoint p1, CPoint p2, COLORREF bkColour, bool bold)
	:Figure(p1, p2, bkColour, bold)
{
}

void EllipseM::Draw(CDC* dc)
{
	CBrush bkGround1;
	CPen border1;
	bkGround1.CreateSolidBrush(this->bkColour);
	border1.CreatePen(PS_SOLID, this->bold ? 4 : 1, black);
	dc->SelectObject(border1);
	dc->SelectObject(bkGround1);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}

