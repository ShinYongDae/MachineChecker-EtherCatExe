
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "MachineChecker.h"

#include "MainFrm.h"
#include "MachineCheckerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_IO, &CMainFrame::OnIo)
	ON_COMMAND(ID_LIGHT1, &CMainFrame::OnLight1)
	ON_COMMAND(ID_LIGHT2, &CMainFrame::OnLight2)
	ON_COMMAND(ID_MOTION, &CMainFrame::OnMotion)
	ON_COMMAND(ID_CAMERA1, &CMainFrame::OnCamera1)
	ON_COMMAND(ID_CAMERA2, &CMainFrame::OnCamera2)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����


void CMainFrame::OnIo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispIO();
}

void CMainFrame::OnLight1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispLight1();
}

void CMainFrame::OnLight2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispLight2();
}

void CMainFrame::OnMotion()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispMotion();
}

void CMainFrame::OnCamera1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispCamera1();
}

void CMainFrame::OnCamera2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispCamera2();
}
