#pragma once


// ParametersDialog dialog

class ParametersDialog : public CDialog
{
	DECLARE_DYNAMIC(ParametersDialog) 

public:
	ParametersDialog(CWnd* pParent = nullptr);   // standard constructor
	COLORREF getColor1() const { return _c1; }
	COLORREF getColor2() const { return _c2; }
	COLORREF getA() const { return _a; }
	COLORREF getB() const { return _b; }
	COLORREF getS() const { return _s; }
	void setS(const int& new_s) { _s = new_s; }
	virtual ~ParametersDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PARAMETERS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP() 
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit txt_a;
	CEdit txt_b;
	CEdit txt_s;
	afx_msg void OnBnClickedOk();
	void initSByWidth(int width);//needed since the dialog cons' is called before the childView cons' (width is got from)
private:
	COLORREF _c1;
	COLORREF _c2;
	int _a;
	int _b;
	int _s;

};
