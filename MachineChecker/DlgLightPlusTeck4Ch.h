#pragma once

#include "Devices/RS232.h"


// CDlgLightPlusTeck4Ch ��ȭ �����Դϴ�.

class CDlgLightPlusTeck4Ch : public CDialog
{
	DECLARE_DYNAMIC(CDlgLightPlusTeck4Ch)

	void Init();
	void Close();

public:
	CDlgLightPlusTeck4Ch(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgLightPlusTeck4Ch();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LIGHT_PLUSTEK_4CH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
