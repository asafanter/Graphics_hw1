
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "ParametersDialog.h"

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// defs
public:
	enum class Mode
	{
		VALUES,
		ZEROS
	};

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

private: //methods
	double calcFunction(const int &a, const int &b, const int &s, const int &w, const int &h, 
		const int &x, const int &y);
	COLORREF calcColor(const double &f, const COLORREF &c1, const COLORREF &c2);

private: //members
	ParametersDialog _parameters_dialog;

	Mode _curr_mode;

	// Generated message map functions
protected:
	//Salih: not void OnDraw() override;??
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpenparametersdialog();
	afx_msg void OnUpdateModeZeros(CCmdUI *pCmdUI);
	afx_msg void OnUpdateModeValues(CCmdUI *pCmdUI);
	afx_msg void OnModeZeros();
	afx_msg void OnModeValues();
};

