// message.cpp : implementation file
//

#include "pch.h"
#include "MFCApplicationX.h"
#include "message.h"
#include "afxdialogex.h"


// message dialog

IMPLEMENT_DYNAMIC(message, CDialogEx)

message::message(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

message::~message()
{
}

void message::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(message, CDialogEx)
END_MESSAGE_MAP()


// message message handlers
