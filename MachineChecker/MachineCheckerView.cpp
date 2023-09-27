
// MachineCheckerView.cpp : CMachineCheckerView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MachineChecker.h"
#endif

#include "MainFrm.h"
#include "MachineCheckerDoc.h"
#include "MachineCheckerView.h"

#include "DlgIO.h"
#include "DlgIoAgn9386.h"

#include "DlgLight.h"
#include "DlgLightPlusTeck4Ch.h"
#include "DlgLightPlusTeck8Ch.h"

#include "DlgMotion.h"
#include "DlgMotionEtherCat.h"

#include "DlgCamera.h"
#include "DlgCameraBasler1CCD.h"
#include "DlgCameraViewWorks12k.h"

#include <tlhelp32.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMachineCheckerView

IMPLEMENT_DYNCREATE(CMachineCheckerView, CFormView)

BEGIN_MESSAGE_MAP(CMachineCheckerView, CFormView)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CMachineCheckerView::OnBnClickedBtnOpen)
END_MESSAGE_MAP()

// CMachineCheckerView 생성/소멸

CMachineCheckerView::CMachineCheckerView()
	: CFormView(IDD_MACHINECHECKER_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMachineCheckerView::~CMachineCheckerView()
{
}

void CMachineCheckerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMachineCheckerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMachineCheckerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	InitMenu();
}


// CMachineCheckerView 진단

#ifdef _DEBUG
void CMachineCheckerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMachineCheckerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMachineCheckerDoc* CMachineCheckerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMachineCheckerDoc)));
	return (CMachineCheckerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMachineCheckerView 메시지 처리기
void CMachineCheckerView::InitMenu()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_bAutoMenuEnable = FALSE;
	CMenu *pMenu = pFrame->GetMenu();
	//pMenu->CheckMenuItem(ID_IO, MF_CHECKED);//MF_UNCHECKED

	CMenu *pSubMenu = pMenu->GetSubMenu(1); // 0:도움말, 1:Devices
	pSubMenu->EnableMenuItem(ID_IO, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_LIGHT1, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_LIGHT2, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_MOTION, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_CAMERA1, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_CAMERA2, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);


	//pSubMenu->EnableMenuItem(ID_APP_ABOUT, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	//pSubMenu->EnableMenuItem(ID_IO, MF_GRAYED);
	//pSubMenu->ModifyMenu(ID_IO, MF_BYPOSITION, MF_POPUP, _T("Input/Output"));
}

void CMachineCheckerView::SetMenu()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();
	CMenu *pMenu = pFrame->GetMenu();
	CMenu *pSubMenu = pMenu->GetSubMenu(1); // 0:도움말, 1:Devices

	if (!pDoc->GetDeviceNameIO().IsEmpty())
	{
		pMenu->ModifyMenu(ID_IO, MF_BYCOMMAND, ID_IO, pDoc->GetDeviceNameIO());
		pSubMenu->EnableMenuItem(ID_IO, MF_BYCOMMAND | MF_ENABLED);
	}
	else
	{
		pMenu->ModifyMenu(ID_IO, MF_BYCOMMAND, ID_IO, _T("IO"));
		pSubMenu->EnableMenuItem(ID_IO, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	if (!pDoc->GetDeviceNameLight(0).IsEmpty())
	{
		pMenu->ModifyMenu(ID_LIGHT1, MF_BYCOMMAND, ID_LIGHT1, pDoc->GetDeviceNameLight(0));
		pSubMenu->EnableMenuItem(ID_LIGHT1, MF_BYCOMMAND | MF_ENABLED);
	}
	else
	{
		pMenu->ModifyMenu(ID_LIGHT1, MF_BYCOMMAND, ID_LIGHT1, _T("Light1"));
		pSubMenu->EnableMenuItem(ID_LIGHT1, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	if (!pDoc->GetDeviceNameLight(1).IsEmpty())
	{
		pMenu->ModifyMenu(ID_LIGHT2, MF_BYCOMMAND, ID_LIGHT2, pDoc->GetDeviceNameLight(1));
		pSubMenu->EnableMenuItem(ID_LIGHT2, MF_BYCOMMAND | MF_ENABLED);
	}
	else
	{
		pMenu->ModifyMenu(ID_LIGHT2, MF_BYCOMMAND, ID_LIGHT2, _T("Light2"));
		pSubMenu->EnableMenuItem(ID_LIGHT2, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	if (!pDoc->GetDeviceNameMotion().IsEmpty())
	{
		pMenu->ModifyMenu(ID_MOTION, MF_BYCOMMAND, ID_MOTION, pDoc->GetDeviceNameMotion());
		pSubMenu->EnableMenuItem(ID_MOTION, MF_BYCOMMAND | MF_ENABLED);
	}
	else
	{
		pMenu->ModifyMenu(ID_MOTION, MF_BYCOMMAND, ID_MOTION, _T("Motion"));
		pSubMenu->EnableMenuItem(ID_MOTION, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	if (!pDoc->GetDeviceNameCamera(0).IsEmpty())
	{
		pMenu->ModifyMenu(ID_CAMERA1, MF_BYCOMMAND, ID_CAMERA1, pDoc->GetDeviceNameCamera(0));
		pSubMenu->EnableMenuItem(ID_CAMERA1, MF_BYCOMMAND | MF_ENABLED);
	}
	else
	{
		pMenu->ModifyMenu(ID_CAMERA1, MF_BYCOMMAND, ID_CAMERA1, _T("Camera1"));
		pSubMenu->EnableMenuItem(ID_CAMERA1, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	if (!pDoc->GetDeviceNameCamera(1).IsEmpty())
	{
		pMenu->ModifyMenu(ID_CAMERA2, MF_BYCOMMAND, ID_CAMERA2, pDoc->GetDeviceNameCamera(1));
		pSubMenu->EnableMenuItem(ID_CAMERA2, MF_BYCOMMAND | MF_ENABLED);
	}
	else
	{
		pMenu->ModifyMenu(ID_CAMERA2, MF_BYCOMMAND, ID_CAMERA2, _T("Camera2"));
		pSubMenu->EnableMenuItem(ID_CAMERA2, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}
}

void CMachineCheckerView::OnBnClickedBtnOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	CString sPath = FileBrowse();

	if (sPath.IsEmpty())
		return;

	GetDlgItem(IDC_STC_PATH)->SetWindowText(sPath);
	CString sData;
	if (!pDoc->LoadConfig(sPath, sData))
		AfxMessageBox(_T("LoadConfig failed!"));
	GetDlgItem(IDC_EDIT_CONFIG)->SetWindowText(sData);
	SetMenu();
}

CString CMachineCheckerView::FileBrowse()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	/* Load from file */
	CString FilePath;
	CFileFind finder;
	CString SrchPath, filePos, strTitleMsg, strErrMsg;

	CWaitCursor mCursor;

	CString DirPath[10];
	CString strWorkDir;
	BOOL bResult;

	CString strMcNum, sPath=_T("");
	int nAoiMachineNum = 0;

	// File Open Filter 
	static TCHAR BASED_CODE szFilter[] = _T("Config Files (*.cfg;*.ini)|*.cfg;*.ini|All Files (*.*)|*.*||");

	// CFileDialog 
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);

	// Win2k Style FileDialog Box
	dlg.m_ofn.lStructSize = sizeof(OPENFILENAME) + 12; // +12를 Win2k Style로 다이얼로그 박스가 Open됨.

	// Open Directory
	TCHAR strPrevDir[MAX_PATH];
	DWORD dwLength = GetCurrentDirectory(MAX_PATH, strPrevDir);

	if (!pDoc->GetPathPrevConfigFolder().IsEmpty())
	{
		filePos = pDoc->GetPathPrevConfigFolder() + _T("\\*.*");
		strWorkDir = filePos;
	}
	else
	{
		strWorkDir = strPrevDir;
	}
	dlg.m_ofn.lpstrInitialDir = strWorkDir;

	bResult = 0;

	// Dialog Open
	if (dlg.DoModal() == IDOK)
	{
		sPath = FilePath = dlg.GetPathName();

		CString sFileName;
		int nPos = FilePath.ReverseFind('\\');
		sFileName = FilePath.Right(FilePath.GetLength() - nPos - 1);
		pDoc->SetNamePrevConfigFile(sFileName);
		pDoc->SetPathPrevConfigFolder(FilePath.Left(nPos));
		return sPath;
	}

	return sPath;
}

void CMachineCheckerView::DispIO()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	ShowDlgIO();
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispLight1()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	ShowDlgLight(0);
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispLight2()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	ShowDlgLight(1);
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispMotion()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	ShowDlgMotion();
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispCamera1()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	ShowDlgCamera(0);
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispCamera2()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	ShowDlgCamera(1);
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::ShowDlgIO()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	if (pDoc->GetDeviceNameIO().MakeLower() == _T("io"))
	{
		CDlgIO Dlg;
		Dlg.DoModal();
	}
	else if (pDoc->GetDeviceNameIO().MakeLower() == _T("ethercat io agn-9386"))
	{
		CDlgIoAgn9386 Dlg;
		Dlg.DoModal();
	}
}

void CMachineCheckerView::ShowDlgLight(int nIndex)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	if (pDoc->GetDeviceNameLight(nIndex).MakeLower() == _T("light"))
	{
		CDlgLight Dlg;
		Dlg.DoModal();
	}
	else if (pDoc->GetDeviceNameLight(nIndex).MakeLower() == _T("plustek-4ch"))
	{
		CDlgLightPlusTeck4Ch Dlg;
		Dlg.DoModal();
	}
	else if (pDoc->GetDeviceNameLight(nIndex).MakeLower() == _T("plustek-8ch"))
	{
		CDlgLightPlusTeck8Ch Dlg;
		Dlg.DoModal();
	}
}

void CMachineCheckerView::ShowDlgMotion()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	if (pDoc->GetDeviceNameMotion().MakeLower() == _T("motion"))
	{
		//CDlgMotion Dlg;
		//Dlg.DoModal();
		if (FindProcess(_T("DlgMotion.exe")) == 0)
		{
			CFileFind finder;

			if (finder.FindFile(_T("DlgMotion.exe")) == 1)
			{
				SHELLEXECUTEINFO info;
				ZeroMemory(&info, sizeof(info));
				info.cbSize = sizeof(SHELLEXECUTEINFO);
				info.hwnd = NULL;
				info.lpVerb = _T("open");
				info.lpFile = _T("DlgMotion.exe");
				info.lpParameters = NULL;
				info.lpDirectory = NULL;
				info.nShow = SW_SHOWNORMAL; // SW_SHOWMAXIMIZED
				info.hInstApp = NULL;
				ShellExecuteEx(&info);
			}

		}
		else
		{
			KillProcess(_T("DlgMotion.exe"));

			CFileFind finder;

			if (finder.FindFile(_T("DlgMotion.exe")) == 1)
			{
				SHELLEXECUTEINFO info;
				ZeroMemory(&info, sizeof(info));
				info.cbSize = sizeof(SHELLEXECUTEINFO);
				info.hwnd = NULL;
				info.lpVerb = _T("open");
				info.lpFile = _T("DlgMotion.exe");
				info.lpParameters = NULL;
				info.lpDirectory = NULL;
				info.nShow = SW_SHOWNORMAL; // SW_SHOWMAXIMIZED
				info.hInstApp = NULL;
				ShellExecuteEx(&info);
			}

		}

	}
	else if (pDoc->GetDeviceNameMotion().MakeLower() == _T("ethercat motion"))
	{
		CDlgMotionEtherCat Dlg;
		Dlg.DoModal();
	}
}

void CMachineCheckerView::ShowDlgCamera(int nIndex)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	if (pDoc->GetDeviceNameCamera(nIndex).MakeLower() == _T("camera"))
	{
		CDlgCamera Dlg;
		Dlg.DoModal();
	}
	else if (pDoc->GetDeviceNameCamera(nIndex).MakeLower() == _T("viewworks 12k linescan camera"))
	{
		CDlgCameraViewWorks12k Dlg;
		Dlg.DoModal();
	}
	else if (pDoc->GetDeviceNameCamera(nIndex).MakeLower() == _T("basler 1ccd area camera"))
	{
		CDlgCameraBasler1CCD Dlg;
		Dlg.DoModal();
	}
}

void CMachineCheckerView::ShowDlgTrigger()
{

}

void CMachineCheckerView::ShowDlg2DBarcode()
{

}



BOOL CMachineCheckerView::FindProcess(CString strProcName)
{
	HANDLE         hProcessSnap = NULL;
	DWORD          Return = FALSE;
	PROCESSENTRY32 pe32 = { 0 };
	CString strMsg;

	int pcount = 0;
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return FALSE;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	BOOL bFind = FALSE;

	if (Process32First(hProcessSnap, &pe32))
	{
		DWORD Code = 0;
		DWORD dwPriorityClass;
		do
		{
			HANDLE hProcess;
			// Get the actual priority class. 
			hProcess = OpenProcess(MAXIMUM_ALLOWED, FALSE, pe32.th32ProcessID);
			dwPriorityClass = GetPriorityClass(hProcess);

			CString Temp = pe32.szExeFile;
			Temp.MakeLower();
			strProcName.MakeLower();
			if (Temp == strProcName)
			{
				CloseHandle(hProcess);
				bFind = TRUE;
				break;
			}
			bFind = FALSE;
			CloseHandle(hProcess);
		} while (Process32Next(hProcessSnap, &pe32));
	}
	else
		bFind = FALSE; // could not walk the list of processes 

	CloseHandle(hProcessSnap); // Do not forget to clean up the snapshot object. 
	return bFind;
}

DWORD CMachineCheckerView::KillProcess(CString strProcName)
{
	HANDLE         hProcessSnap = NULL;
	DWORD          Return = FALSE;
	PROCESSENTRY32 pe32 = { 0 };
	CString strMsg;
	DWORD nCurPID = GetCurrentProcessId();
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return (DWORD)INVALID_HANDLE_VALUE;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hProcessSnap, &pe32))
	{
		DWORD Code = 0;
		DWORD dwPriorityClass;
		do
		{
			HANDLE hProcess;
			// Get the actual priority class. 
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
			dwPriorityClass = GetPriorityClass(hProcess);

			if (nCurPID == pe32.th32ProcessID)
			{
				CloseHandle(hProcess);
				continue;
			}

			CString Temp = pe32.szExeFile;
			Temp.MakeLower();
			strProcName.MakeLower();
			if (Temp == strProcName)
			{
				int checkval = 0;
#ifndef _WIN64
				DWORD ret;
#else
				DWORD_PTR ret;
#endif
				checkval = SendMessageTimeout((HWND)hProcess, WM_NULL, 0,//널 메세지를 보내본다
					0, SMTO_ABORTIFHUNG | SMTO_BLOCK, 500, &ret);

				//	AfxMessageBox(strMsg);
				if (TerminateProcess(hProcess, 0))
					GetExitCodeProcess(hProcess, &Code);
				else
					return Return;

			}

			CloseHandle(hProcess);
		} while (Process32Next(hProcessSnap, &pe32));
		Return = TRUE;
	}
	else
		Return = FALSE; // could not walk the list of processes 

	CloseHandle(hProcessSnap); // Do not forget to clean up the snapshot object. 
	return Return;
}
