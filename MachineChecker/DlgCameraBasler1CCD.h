#pragma once


// CDlgCameraBasler1CCD ��ȭ �����Դϴ�.

class CDlgCameraBasler1CCD : public CDialog
{
	DECLARE_DYNAMIC(CDlgCameraBasler1CCD)

	void Init();
	void Close();

public:
	CDlgCameraBasler1CCD(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgCameraBasler1CCD();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA_BASLER_1CCD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
