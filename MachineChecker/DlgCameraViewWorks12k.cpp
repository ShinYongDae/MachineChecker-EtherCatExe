// DlgCameraViewWorks12k.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCameraViewWorks12k.h"
#include "afxdialogex.h"


// CDlgCameraViewWorks12k ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgCameraViewWorks12k, CDialog)

CDlgCameraViewWorks12k::CDlgCameraViewWorks12k(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_CAMERA_VIEWWORKS_12K, pParent)
{

}

CDlgCameraViewWorks12k::~CDlgCameraViewWorks12k()
{
}

void CDlgCameraViewWorks12k::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCameraViewWorks12k, CDialog)
END_MESSAGE_MAP()


// CDlgCameraViewWorks12k �޽��� ó�����Դϴ�.


BOOL CDlgCameraViewWorks12k::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgCameraViewWorks12k::Init()
{
}

void CDlgCameraViewWorks12k::Close()
{
}
