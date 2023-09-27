// DlgMotion.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgMotion.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/EtherCatDLL.lib")

#include "MainFrm.h"
#include "MachineCheckerDoc.h"
#include "MachineCheckerView.h"

// CDlgMotion 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMotion, CDialog)

CDlgMotion::CDlgMotion(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_MOTION, pParent)
{
	//m_pEtherCat = NULL;
}

CDlgMotion::~CDlgMotion()
{
	Close();
}

void CDlgMotion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMotion, CDialog)
END_MESSAGE_MAP()


// CDlgMotion 메시지 처리기입니다.


BOOL CDlgMotion::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgMotion::Init()
{
	//if (!m_pEtherCat)
	//{
	//	m_pEtherCat = new CEtherCat(this);
	//	m_pEtherCat->LoadParam(PATH_MOTION_PARAM);
	//	if (!m_pEtherCat->InitBoard())
	//	{
	//		AfxMessageBox(_T("XMP 보드 초기화 실패, 다시 시작하세요.!!!"));
	//		PostMessage(WM_CLOSE);
	//	}
	//}
}

void CDlgMotion::Close()
{
	//if (m_pEtherCat)
	//{
	//	delete m_pEtherCat;
	//	m_pEtherCat = NULL;
	//}
}
