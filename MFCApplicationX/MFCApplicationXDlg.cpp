
// MFCApplicationXDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplicationX.h"
#include "MFCApplicationXDlg.h"
#include "afxdialogex.h"
#include "message.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplicationXDlg dialog

CMFCApplicationXDlg::CMFCApplicationXDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATIONX_DIALOG, pParent)
	, isBold(FALSE)
	, isMoving(false)
	
{
	futureFigKIND = FIGURES::RECTANGLE;
	colour1 = RGB(50, 200, 255);
	inColour = RGB(50, 200, 255);
	f = NULL;
	s = NULL;
	isPressed = false;
	warning = false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, isBold);
	//  DDX_Control(pDX, IDC_CHECK2, isMoving);
	//	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, colourB);
	//DDX_Control(pDX, IDC_MFCCOLORBUTTON2, inColour);
	//DDX_Control(pDX, IDC_MFCCOLORBUTTON1, Lcolour);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, Bcolour);
	//  DDX_Control(pDX, IDC_BUTTON6, bigger);
	//  DDX_Control(pDX, IDC_BUTTON9, smaller);
	//  DDX_Control(pDX, IDC_BUTTON6, bigger);
	//  DDX_Control(pDX, IDC_BUTTON9, smaller);
}

BEGIN_MESSAGE_MAP(CMFCApplicationXDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationXDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationXDlg::OnBnClickedButton2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_BN_CLICKED(IDC_CHECK1, &CMFCApplicationXDlg::OnBnClickedCheck1)
ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplicationXDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplicationXDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplicationXDlg::OnBnClickedButton5)
//ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplicationXDlg::OnBnClickedButton6)
//ON_WM_RBUTTONDOWN()
//ON_WM_RBUTTONUP()
ON_BN_CLICKED(IDC_CHECK2, &CMFCApplicationXDlg::OnBnClickedCheck2)
ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplicationXDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplicationXDlg::OnBnClickedButton8)
//ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMFCApplicationXDlg::OnBnClickedMfccolorbutton1)
ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CMFCApplicationXDlg::OnBnClickedMfccolorbutton2)
ON_WM_LBUTTONDBLCLK()
//ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFCApplicationXDlg::OnDeltaposSpin1)
ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplicationXDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplicationXDlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplicationXDlg::OnBnClickedButton10)
END_MESSAGE_MAP()

// CMFCApplicationXDlg message handlers

BOOL CMFCApplicationXDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplicationXDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if (!figs.IsEmpty())
		{
			int i;
			CPaintDC dc(this);
			for (i = 0; i < figs.GetSize(); i++)
				figs[i]->Draw(&dc);
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplicationXDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplicationXDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	s = NULL;
	if (!figs.IsEmpty())
	{
		for (int i = 0; i < figs.GetSize(); i++)
		{
			if (figs[i]->isInside(point))
			{
				s = figs[i];
				if (isMoving)
				{
					flag = true;
					endP = startP = point;
					return;
				}
			}
		}
	}
	endP = startP = point;
	isPressed = true;
	CDialog::OnLButtonDown(nFlags, point);

}

void CMFCApplicationXDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(isMoving)
	{
		if (flag)
		{
			s->p1 += point - startP;
			s->p2 += point - startP;
			endP += point - startP;
			moveObject();
		}
	}
	if (isPressed)
	{
		Figure temp;
		endP = point;
		isPressed = false;
		UpdateData(true);
		switch (futureFigKIND)
		{
		case FIGURES::RECTANGLE:
			figs.Add(new RectangleM(startP, endP, inColour,isBold));
			break;
		case FIGURES::ROUND_RECT:
			figs.Add(new RoundRectangle(startP, endP, inColour, isBold));
			break;
		case FIGURES::ELLIPSE:
			figs.Add(new EllipseM(startP, endP, inColour, isBold));
			break;
		case FIGURES::RECT3D:
			figs.Add(new Rectangle3D(startP, endP, inColour, isBold));
			break;
		}
		CClientDC dc(this);

	}
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CMFCApplicationXDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	if (isPressed)
	{
		CPen myPen(PS_SOLID, isBold ? 4 : 1, colourZ);
		//UpdateData(false);
		UpdateData(true);
		CBrush myBrush(inColour);
		dc.SelectObject(&myBrush);
		dc.SelectObject(&myPen);
		dc.SetROP2(R2_NOTXORPEN);
		switch (futureFigKIND)
		{
		case FIGURES::RECTANGLE:
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			break;
		case FIGURES::ELLIPSE:
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			break;
		case FIGURES::ROUND_RECT:
			dc.RoundRect(startP.x, startP.y, endP.x, endP.y, 20, 20);
			endP = point;
			dc.RoundRect(startP.x, startP.y, endP.x, endP.y, 20, 20);
			break;
		case FIGURES::RECT3D:
			dc.Draw3dRect(startP.x, startP.y, endP.x, endP.y, inColour, inColour);
			endP = point;
			dc.Draw3dRect(startP.x, startP.y, endP.x, endP.y, inColour, inColour);
			break;
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCApplicationXDlg::ClearScreen() 
{
	figs.RemoveAll();
	Invalidate();
}

void CMFCApplicationXDlg::undo()
{
	CPaintDC dc(this);
	Invalidate();
	if (!figs.IsEmpty())
	{
		int i;
		for (i = 0; i < figs.GetSize() - 1; i++)
			figs[i]->Draw(&dc);

		figs.RemoveAt(i, 1);
	}
}

void CMFCApplicationXDlg::moveObject() //refresh
{
	Invalidate();
	if (!figs.IsEmpty())
	{
		CPaintDC dc(this);
		int i = 0;
		for (i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
	}
	flag = false;
}

void CMFCApplicationXDlg::OnBnClickedCheck1() //isBold
{
	if (!isBold)
		isBold = true;
	else isBold = false;
}

void CMFCApplicationXDlg::OnBnClickedButton1() //rectangle
{
	futureFigKIND = FIGURES::RECTANGLE;
}

void CMFCApplicationXDlg::OnBnClickedButton2() //round rectangle
{
	futureFigKIND = FIGURES::ROUND_RECT;
}

void CMFCApplicationXDlg::OnBnClickedButton3() //ellipse
{
	futureFigKIND = FIGURES::ELLIPSE;
}

void CMFCApplicationXDlg::OnBnClickedButton4() //Clear
{
	ClearScreen();	
}


void CMFCApplicationXDlg::OnBnClickedButton5() //Undo
{
	undo();
}

//void CMFCApplicationXDlg::OnBnClickedButton6() 
//{
//
//}

void CMFCApplicationXDlg::OnBnClickedCheck2() //Move
{
	if (!isMoving)
	{
		isPressed = false;
		isMoving = true;
	}
	else isMoving = false;
}

void CMFCApplicationXDlg::OnBnClickedButton7() //save
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}

void CMFCApplicationXDlg::OnBnClickedButton8() //load
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		CPaintDC dc(this);

		moveObject(); //refresh

	}
}

void CMFCApplicationXDlg::OnBnClickedMfccolorbutton2() //Colour
{
	inColour = Bcolour.GetColor();
}

void CMFCApplicationXDlg::OnLButtonDblClk(UINT nFlags, CPoint point) //delete
{
	if (!figs.IsEmpty())
	{
		for (int i = 0; i < figs.GetSize(); i++)
		{
			if (figs[i]->isInside(point))
				figs.RemoveAt(i, 1);
		}
		CPaintDC dc(this);
		Invalidate();
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);

		CDialogEx::OnLButtonDblClk(nFlags, point);
	}
}

void CMFCApplicationXDlg::OnBnClickedButton6() //+
{
	if (s)
	{
		s->bigger();
		moveObject();
	}
}

void CMFCApplicationXDlg::OnBnClickedButton9() //-
{
	if (s)
	{
		s->smaller();
		moveObject();
	}
}

void CMFCApplicationXDlg::OnBnClickedButton10() //3D Rectangle
{
	futureFigKIND = FIGURES::RECT3D;
	if (!warning)
	{
		message mes;
		mes.DoModal();
		warning = true;
	}
}