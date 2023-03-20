#include "pch.h"
#include "Rectangle3D.h"

IMPLEMENT_SERIAL(Rectangle3D, CObject, 1)

Rectangle3D::Rectangle3D()
{
}

Rectangle3D::Rectangle3D(CPoint p1, CPoint p2, COLORREF bkColour, bool bold)
	:RectangleM(p1, p2, bkColour, bold)
{
}

Rectangle3D::~Rectangle3D()
{
}

void Rectangle3D::Draw(CDC* dc)
{
	CBrush bkGround1;
	CPen border1;
	bkGround1.CreateSolidBrush(this->bkColour);
	border1.CreatePen(PS_SOLID, this->bold ? 4 : 1, black);
	dc->SelectObject(border1);
	dc->SelectObject(bkGround1);
	dc->Draw3dRect(p1.x, p1.y, p2.x, p2.y, this->bkColour, this->bkColour);// RGB(255, 147, 0), RGB(2, 147, 0));
}
