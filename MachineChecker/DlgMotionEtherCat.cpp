// DlgMotionEtherCat.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgMotionEtherCat.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/EtherCatDLL.lib")

// CDlgMotionEtherCat ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgMotionEtherCat, CDialog)

CDlgMotionEtherCat::CDlgMotionEtherCat(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_MOTION_ETHERCAT, pParent)
{

}

CDlgMotionEtherCat::~CDlgMotionEtherCat()
{
}

void CDlgMotionEtherCat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMotionEtherCat, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, &CDlgMotionEtherCat::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CDlgMotionEtherCat::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDlgMotionEtherCat::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CDlgMotionEtherCat::OnBnClickedCheck4)
END_MESSAGE_MAP()


// CDlgMotionEtherCat �޽��� ó�����Դϴ�.


BOOL CDlgMotionEtherCat::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgMotionEtherCat::Init()
{
	//LoadParam();
}

void CDlgMotionEtherCat::Close()
{
}


void CDlgMotionEtherCat::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(0, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}


void CDlgMotionEtherCat::OnBnClickedCheck2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(1, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}


void CDlgMotionEtherCat::OnBnClickedCheck3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(2, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}


void CDlgMotionEtherCat::OnBnClickedCheck4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(3, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}
