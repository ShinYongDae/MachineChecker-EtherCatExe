#pragma once


// CDlgCamera ��ȭ �����Դϴ�.

class CDlgCamera : public CDialog
{
	DECLARE_DYNAMIC(CDlgCamera)

	void Init();
	void Close();

public:
	CDlgCamera(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgCamera();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
