// DlgCameraBasler1CCD.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCameraBasler1CCD.h"
#include "afxdialogex.h"


// CDlgCameraBasler1CCD ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgCameraBasler1CCD, CDialog)

CDlgCameraBasler1CCD::CDlgCameraBasler1CCD(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_CAMERA_BASLER_1CCD, pParent)
{

}

CDlgCameraBasler1CCD::~CDlgCameraBasler1CCD()
{
}

void CDlgCameraBasler1CCD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCameraBasler1CCD, CDialog)
END_MESSAGE_MAP()


// CDlgCameraBasler1CCD �޽��� ó�����Դϴ�.


BOOL CDlgCameraBasler1CCD::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgCameraBasler1CCD::Init()
{
}

void CDlgCameraBasler1CCD::Close()
{
}
