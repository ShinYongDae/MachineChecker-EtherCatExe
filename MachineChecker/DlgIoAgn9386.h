#pragma once


// CDlgIoAgn9386 ��ȭ �����Դϴ�.

class CDlgIoAgn9386 : public CDialog
{
	DECLARE_DYNAMIC(CDlgIoAgn9386)

	void Init();
	void Close();

public:
	CDlgIoAgn9386(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgIoAgn9386();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_IO_AGN_9386 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
