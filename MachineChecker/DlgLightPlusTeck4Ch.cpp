// DlgLightPlusTeck4Ch.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgLightPlusTeck4Ch.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/RS232DLL.lib")

// CDlgLightPlusTeck4Ch ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgLightPlusTeck4Ch, CDialog)

CDlgLightPlusTeck4Ch::CDlgLightPlusTeck4Ch(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_LIGHT_PLUSTEK_4CH, pParent)
{

}

CDlgLightPlusTeck4Ch::~CDlgLightPlusTeck4Ch()
{
	Close();
}

void CDlgLightPlusTeck4Ch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLightPlusTeck4Ch, CDialog)
END_MESSAGE_MAP()


// CDlgLightPlusTeck4Ch �޽��� ó�����Դϴ�.


BOOL CDlgLightPlusTeck4Ch::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgLightPlusTeck4Ch::Init()
{
}

void CDlgLightPlusTeck4Ch::Close()
{
}
