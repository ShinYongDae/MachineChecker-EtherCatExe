// DlgLightPlusTeck8Ch.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgLightPlusTeck8Ch.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/RS232DLL.lib")

// CDlgLightPlusTeck8Ch ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgLightPlusTeck8Ch, CDialog)

CDlgLightPlusTeck8Ch::CDlgLightPlusTeck8Ch(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_LIGHT_PLUSTEK_8CH, pParent)
{

}

CDlgLightPlusTeck8Ch::~CDlgLightPlusTeck8Ch()
{
	Close();
}

void CDlgLightPlusTeck8Ch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLightPlusTeck8Ch, CDialog)
END_MESSAGE_MAP()


// CDlgLightPlusTeck8Ch �޽��� ó�����Դϴ�.


BOOL CDlgLightPlusTeck8Ch::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgLightPlusTeck8Ch::Init()
{
}

void CDlgLightPlusTeck8Ch::Close()
{
}
