#pragma once

//#include "Devices/EtherCat.h"

enum OnOffAction { OFF, ON };

// CDlgMotionEtherCat ��ȭ �����Դϴ�.

class CDlgMotionEtherCat : public CDialog
{
	DECLARE_DYNAMIC(CDlgMotionEtherCat)

	//CEtherCat *m_pEtherCat;

	void Init();
	void Close();

public:
	CDlgMotionEtherCat(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMotionEtherCat();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MOTION_ETHERCAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
};
