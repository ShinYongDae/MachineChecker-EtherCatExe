#pragma once

//#include "Devices/EtherCat.h"



// CDlgMotion ��ȭ �����Դϴ�.

class CDlgMotion : public CDialog
{
	DECLARE_DYNAMIC(CDlgMotion)

	//CEtherCat *m_pEtherCat;

	void Init();
	void Close();

public:
	CDlgMotion(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMotion();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MOTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
