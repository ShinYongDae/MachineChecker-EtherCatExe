#pragma once

// CDlgIO ��ȭ �����Դϴ�.

class CDlgIO : public CDialog
{
	DECLARE_DYNAMIC(CDlgIO)

	void Init();
	void Close();

public:
	CDlgIO(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgIO();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_IO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
