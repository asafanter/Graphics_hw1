
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "HW1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView


CChildView::CChildView() :
	_parameters_dialog(this),
	_curr_mode(Mode::ZEROS),
	m_firstTime(TRUE)
{

//	CRect rect;
	//GetClientRect(rect);
	//int w = rect.Width();
}



CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_OPENPARAMETERSDIALOG, &CChildView::OnFileOpenparametersdialog)
	ON_UPDATE_COMMAND_UI(ID_MODE_ZEROS, &CChildView::OnUpdateModeZeros)
	ON_UPDATE_COMMAND_UI(ID_MODE_VALUES, &CChildView::OnUpdateModeValues)
	ON_COMMAND(ID_MODE_ZEROS, &CChildView::OnModeZeros)
	ON_COMMAND(ID_MODE_VALUES, &CChildView::OnModeValues)
	ON_COMMAND(ID_TEST, &CChildView::OnFileOpenparametersdialog)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}





void CChildView::OnPaint() 
{
	CPaintDC dc(this); 



	CRect rect;
	this->GetClientRect(rect);

	auto width = rect.Width();
	auto height = rect.Height();

	//init the _s on first time
	if (m_firstTime) {
		_parameters_dialog.initSByWidth(width);
		m_firstTime = FALSE;
	}

	auto c1 = _parameters_dialog.getColor1();
	auto c2 = _parameters_dialog.getColor2();

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			auto f = calcFunction(_parameters_dialog.getA(), _parameters_dialog.getB(), _parameters_dialog.getS(), width, height, x, y);
			auto color = calcColor(f, c1, c2);
			dc.SetPixel(x, y, color);
		}	
	}
}


double CChildView::calcFunction(const int & a, const int & b, const int & s, const int &w, const int &h,
	const int & x, const int & y)
{
	auto numerator = pow(a * (x - w / 2), 4) + pow(b * (y - h / 2), 4);
	auto denomirator = pow(s, 3);

	return cos(numerator / denomirator);
}

COLORREF CChildView::calcColor(const double & f, const COLORREF & c1, const COLORREF & c2)
{
	if (_curr_mode == Mode::ZEROS)
	{
		return f > 0 ? c1 : c2;
	}

	auto t = (f + 1) / 2;

	return c1 * (1 - t) + c2 * t;
}

void CChildView::OnFileOpenparametersdialog()
{
	_parameters_dialog.DoModal();
}


void CChildView::OnUpdateModeZeros(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(_curr_mode == Mode::ZEROS);
}


void CChildView::OnUpdateModeValues(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(_curr_mode == Mode::VALUES);
}


void CChildView::OnModeZeros()
{
	_curr_mode = Mode::ZEROS;
	RedrawWindow();
}


void CChildView::OnModeValues()
{
	_curr_mode = Mode::VALUES;
	RedrawWindow();
}
