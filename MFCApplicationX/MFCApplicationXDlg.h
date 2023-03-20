
// MFCApplicationXDlg.h : header file
//

#pragma once
#include "Figure.h"
#include "RectangleM.h"
#include "RoundRectangle.h"
#include "Rectangle3D.h"
#include "EllipseM.h"

using namespace std;

// CMFCApplicationXDlg dialog
class CMFCApplicationXDlg : public CDialogEx
{
// Construction
public:
	CMFCApplicationXDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATIONX_DIALOG };
#endif
	//void ClearScreen();
	enum class FIGURES { RECTANGLE, ELLIPSE, ROUND_RECT, RECT3D };
	FIGURES futureFigKIND;
	Figure* f, * s;
	bool warning;

	CTypedPtrArray<CObArray, Figure*> figs; // figs structure holds all the shapes. MFC type. 
//
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	int futureFigureKind = 1;

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void ClearScreen();
	void undo();
	void moveObject();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool isPressed = false; //event driven 
	CPoint startP;
	CPoint endP;
	COLORREF colour1;
	BOOL isBold = false;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	//afx_msg void OnBnClickedButton6();
	//afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedCheck2();
	bool isMoving = false;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
//	afx_msg void OnBnClickedMfccolorbutton1();
	COLORREF colourZ = RGB(0, 0, 0);
	COLORREF inColour;
	afx_msg void OnBnClickedMfccolorbutton2();
//	CMFCColorButton Lcolour;
	CMFCColorButton Bcolour;
	bool flag = false;
	//bool resize = false;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton9();

	afx_msg void OnBnClickedButton10();
};
