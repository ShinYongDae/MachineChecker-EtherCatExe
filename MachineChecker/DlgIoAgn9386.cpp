// DlgIoAgn9386.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgIoAgn9386.h"
#include "afxdialogex.h"


// CDlgIoAgn9386 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgIoAgn9386, CDialog)

CDlgIoAgn9386::CDlgIoAgn9386(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_IO_AGN_9386, pParent)
{

}

CDlgIoAgn9386::~CDlgIoAgn9386()
{
	Close();
}

void CDlgIoAgn9386::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgIoAgn9386, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlgIoAgn9386 �޽��� ó�����Դϴ�.


BOOL CDlgIoAgn9386::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	//SetTimer(0, 100, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgIoAgn9386::Init()
{
}

void CDlgIoAgn9386::Close()
{
}


void CDlgIoAgn9386::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 0)
	{
		KillTimer(nIDEvent);
	}

	CDialog::OnTimer(nIDEvent);
}
