#pragma once

#include "Devices/RS232.h"


// CDlgLightPlusTeck8Ch ��ȭ �����Դϴ�.

class CDlgLightPlusTeck8Ch : public CDialog
{
	DECLARE_DYNAMIC(CDlgLightPlusTeck8Ch)

	void Init();
	void Close();

public:
	CDlgLightPlusTeck8Ch(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgLightPlusTeck8Ch();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LIGHT_PLUSTEK_8CH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
