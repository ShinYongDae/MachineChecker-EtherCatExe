// DlgIO.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgIO.h"
#include "afxdialogex.h"


// CDlgIO ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgIO, CDialog)

CDlgIO::CDlgIO(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_IO, pParent)
{

}

CDlgIO::~CDlgIO()
{
	Close();
}

void CDlgIO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgIO, CDialog)
END_MESSAGE_MAP()


// CDlgIO �޽��� ó�����Դϴ�.


BOOL CDlgIO::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgIO::Init()
{
}

void CDlgIO::Close()
{
}
