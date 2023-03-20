#pragma once
using namespace std;

class Figure : public CObject //this gives the option for serialization 
{
	DECLARE_SERIAL(Figure)
protected:
public:
	CPoint p1;
	CPoint p2;
	CPoint c;
	CPen border;
	bool bold;
	COLORREF black = RGB(0, 0, 0);
	COLORREF bkColour;
	CBrush bkGround;
	Figure();
	Figure(CPoint p1, CPoint p2, COLORREF bkColour, bool bold)
		: p1(p1), p2(p2), bold(bold)
	{
		this->bkColour = bkColour;
		border.CreatePen(PS_SOLID, bold ? 4 : 1,black);
		bkGround.CreateSolidBrush(bkColour);
	}
	void Serialize(CArchive& ar);
	void Redefine(CPoint p1, CPoint p2) {this->p1 = p1; this->p2 = p2; }
	bool isInside(const CPoint& P) const;
	virtual void Draw(CDC* dc);
	void bigger();
	void smaller();
	const Figure& operator=(const Figure& d);
	virtual ~Figure(void);
};
