#include "pch.h"
#include "Figure.h"
IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure(void) :p1(0, 0), p2(0, 0), bkColour(bkColour ? bkColour : black), bold(false)
{
}

Figure::~Figure(void)
{
}

const Figure& Figure::operator=(const Figure& d)
{
	this->p1 = d.p1;
	this->p2 = d.p2;
//	this->p3 = d.p3;
//	this->p4 = d.p4;
	return d;
}

void Figure::Draw(CDC* dc)
{
	dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}

bool Figure::isInside(const CPoint& P) const
{
	return (p1.x <= P.x && P.x <= p2.x || p1.x >= P.x && P.x >= p2.x) &&
		(p1.y <= P.y && P.y <= p2.y || p1.y >= P.y && P.y >= p2.y);
}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << p1;
		ar << p2;
		ar << bkColour;
		ar << bold;
	}
	else
	{
		ar >> p1;
		ar >> p2;
		ar >> bkColour;
		ar >> bold;

	}
}

void Figure::bigger()
{
	if (this)
	{
		if ((p2.x - p1.x) < (p2.y - p1.y))
		{
			this->p1.x += 10;
			this->p1.y -= 10;
			this->p2.x -= 10;
			this->p2.y += 10;
		}
		else
		{
			this->p1.x -= 10;
			this->p1.y -= 10;
			this->p2.x += 10;
			this->p2.y += 10;
		}
	}
}

void Figure::smaller()
{
	if (this)
	{
		if ((p2.x - p1.x) < (p2.y - p1.y))
		{
			this->p1.x -= 10;
			this->p1.y += 10;
			this->p2.x += 10;
			this->p2.y -= 10;
		}
		else
		{
			this->p1.x += 10;
			this->p1.y += 10;
			this->p2.x -= 10;
			this->p2.y -= 10;
		}
	}
}
