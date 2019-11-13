// ParametersDialog.cpp : implementation file
//

#include "stdafx.h"
#include "HW1.h"
#include "ParametersDialog.h"
#include "afxdialogex.h"




// ParametersDialog dialog

IMPLEMENT_DYNAMIC(ParametersDialog, CDialog)



ParametersDialog::ParametersDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(PARAMETERS_DIALOG, pParent),
	_c1(RGB(0, 0, 0)),
	_c2(RGB(255, 255, 255)),
	_a(1),
	_b(1),
	_s(1)
{	

}


void ParametersDialog::initSByWidth(int const width) {

	_s = width / 10;
}


ParametersDialog::~ParametersDialog()
{
}

//Salih: huh?
void ParametersDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, txt_a);
	DDX_Control(pDX, IDC_EDIT3, txt_b);
	DDX_Control(pDX, IDC_EDIT2, txt_s);
	DDX_Text(pDX, IDC_EDIT1, _a);
	DDX_Text(pDX, IDC_EDIT3, _b);
	DDX_Text(pDX, IDC_EDIT2, _s);
}


BEGIN_MESSAGE_MAP(ParametersDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &ParametersDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ParametersDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &ParametersDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// ParametersDialog message handlers
//Salih: not working, not updating the screen on click



void ParametersDialog::OnBnClickedButton1()
{
	CColorDialog color_dialog;
	if (color_dialog.DoModal() == IDOK)
	{
		_c1 = color_dialog.GetColor();
	}
}


void ParametersDialog::OnBnClickedButton2()
{
	CColorDialog color_dialog;
	if (color_dialog.DoModal() == IDOK)
	{
		_c2 = color_dialog.GetColor();
	}
}


void ParametersDialog::OnBnClickedOk()
{
	CString a_str;
	CString b_str;
	CString s_str;

	txt_a.GetWindowTextW(a_str);
	txt_b.GetWindowTextW(b_str);
	txt_s.GetWindowTextW(s_str);
	
	int a = _wtoi(a_str);
	int b = _wtoi(b_str);
	int s = _wtoi(s_str);

	if (a_str.IsEmpty() || b_str.IsEmpty() || s_str.IsEmpty())
	{
		AfxMessageBox(_T("all parameters must be set"), MB_OK);
		return;
	}

	if (a <= 0 || b <= 0 || s <= 0)
	{
		AfxMessageBox(_T("only positive numbers are allowed"), MB_OK);
		return;
	}


	CDialog::OnOK();

	GetParent()->RedrawWindow();
}
