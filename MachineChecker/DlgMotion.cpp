// DlgMotion.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgMotion.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/EtherCatDLL.lib")

#include "MainFrm.h"
#include "MachineCheckerDoc.h"
#include "MachineCheckerView.h"

// CDlgMotion ��ȭ �����Դϴ�.

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


// CDlgMotion �޽��� ó�����Դϴ�.


BOOL CDlgMotion::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgMotion::Init()
{
	//if (!m_pEtherCat)
	//{
	//	m_pEtherCat = new CEtherCat(this);
	//	m_pEtherCat->LoadParam(PATH_MOTION_PARAM);
	//	if (!m_pEtherCat->InitBoard())
	//	{
	//		AfxMessageBox(_T("XMP ���� �ʱ�ȭ ����, �ٽ� �����ϼ���.!!!"));
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
