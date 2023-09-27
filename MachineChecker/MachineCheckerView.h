
// MachineCheckerView.h : CMachineCheckerView Ŭ������ �������̽�
//

#pragma once
#include "MachineCheckerDoc.h"

#define TIM_SHOW_VIEW		10

class CMachineCheckerView : public CFormView
{
	BOOL m_bTimShowView;
	CString m_sTimShowViewChkExe;

	void InitMenu();
	void SetMenu();
	CString FileBrowse();

	void ShowDlgIO();
	void ShowDlgLight(int nIndex);
	void ShowDlgMotion(CString sPath);
	void ShowDlgCamera(int nIndex);
	void ShowDlgTrigger();
	void ShowDlg2DBarcode();

	void ShowViewAfter(CString sPath);
	BOOL IsOnExe();

	BOOL FindProcess(CString strProcName);
	DWORD KillProcess(CString strProcName);

protected: // serialization������ ��������ϴ�.
	CMachineCheckerView();
	DECLARE_DYNCREATE(CMachineCheckerView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MACHINECHECKER_FORM };
#endif

// Ư���Դϴ�.
public:
	CMachineCheckerDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	void DispIO();
	void DispLight1();
	void DispLight2();
	void DispMotion();
	void DispCamera1();
	void DispCamera2();

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMachineCheckerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MachineCheckerView.cpp�� ����� ����
inline CMachineCheckerDoc* CMachineCheckerView::GetDocument() const
   { return reinterpret_cast<CMachineCheckerDoc*>(m_pDocument); }
#endif

