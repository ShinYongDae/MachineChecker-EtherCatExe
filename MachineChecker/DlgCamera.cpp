// DlgCamera.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCamera.h"
#include "afxdialogex.h"


// CDlgCamera ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgCamera, CDialog)

CDlgCamera::CDlgCamera(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_CAMERA, pParent)
{

}

CDlgCamera::~CDlgCamera()
{
}

void CDlgCamera::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCamera, CDialog)
END_MESSAGE_MAP()


// CDlgCamera �޽��� ó�����Դϴ�.


BOOL CDlgCamera::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgCamera::Init()
{
}

void CDlgCamera::Close()
{
}
