#pragma once


// CDlgCameraViewWorks12k ��ȭ �����Դϴ�.

class CDlgCameraViewWorks12k : public CDialog
{
	DECLARE_DYNAMIC(CDlgCameraViewWorks12k)

	void Init();
	void Close();

public:
	CDlgCameraViewWorks12k(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgCameraViewWorks12k();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA_VIEWWORKS_12K };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
