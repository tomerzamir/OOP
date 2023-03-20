#pragma once


// message dialog

class message : public CDialogEx
{
	DECLARE_DYNAMIC(message)

public:
	message(CWnd* pParent = nullptr);   // standard constructor
	virtual ~message();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
