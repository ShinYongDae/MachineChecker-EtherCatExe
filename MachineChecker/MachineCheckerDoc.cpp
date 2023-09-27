
// MachineCheckerDoc.cpp : CMachineCheckerDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MachineChecker.h"
#endif

#include "MachineCheckerDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMachineCheckerDoc

IMPLEMENT_DYNCREATE(CMachineCheckerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMachineCheckerDoc, CDocument)
END_MESSAGE_MAP()


// CMachineCheckerDoc ����/�Ҹ�

CMachineCheckerDoc::CMachineCheckerDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	m_sPathPrevConfigFolder = _T("");
}

CMachineCheckerDoc::~CMachineCheckerDoc()
{
}

BOOL CMachineCheckerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMachineCheckerDoc serialization

void CMachineCheckerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMachineCheckerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMachineCheckerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMachineCheckerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMachineCheckerDoc ����

#ifdef _DEBUG
void CMachineCheckerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMachineCheckerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMachineCheckerDoc ���
CString CMachineCheckerDoc::GetPathPrevConfigFolder()
{
	return m_sPathPrevConfigFolder;
}

CString CMachineCheckerDoc::GetNamePrevConfigFile()
{
	return m_sNamePrevConfigFile;
}

void CMachineCheckerDoc::SetPathPrevConfigFolder(CString sPath)
{
	m_sPathPrevConfigFolder = sPath;
}

void CMachineCheckerDoc::SetNamePrevConfigFile(CString sName)
{
	m_sNamePrevConfigFile = sName;
}

CString CMachineCheckerDoc::GetProgramVersion()
{
	return m_stConfig.Info.sProgramVersion;
}

CString CMachineCheckerDoc::GetConfigFileVersion()
{
	return m_stConfig.Info.sConfigFileVersion;
}

CString CMachineCheckerDoc::GetMachineName()
{
	return m_stConfig.Info.sMachineName;
}

CString CMachineCheckerDoc::GetDeviceNameIO()
{
	return m_stConfig.Devices.sIO;
}

CString CMachineCheckerDoc::GetDeviceNameLight(int nIndex)
{
	if (nIndex >= MAX_LIGHT)
		return _T("");

	return m_stConfig.Devices.sLight[nIndex];
}

CString CMachineCheckerDoc::GetDeviceNameMotion()
{
	return m_stConfig.Devices.sMotion;
}

CString CMachineCheckerDoc::GetDeviceNameCamera(int nIndex)
{
	if (nIndex >= MAX_CAMERA)
		return _T("");

	return m_stConfig.Devices.sCamera[nIndex];
}

CString CMachineCheckerDoc::GetDeviceNameTrigger()
{
	return m_stConfig.Devices.sTrigger;
}

CString CMachineCheckerDoc::GetDeviceName2DBarcode()
{
	return m_stConfig.Devices.s2DBarcode;
}


BOOL CMachineCheckerDoc::LoadConfig(CString sPath, CString& sData)
{
	int i;
	CString str, sItem;
	TCHAR szData[MAX_PATH];
	sData = _T("");

	sData += _T("[Info]");
	sData += _T("\r\n");

	m_stConfig.Info.sProgramVersion = PROGRAM_VERSION;

	if (0 < ::GetPrivateProfileString(_T("Info"), _T("File Version"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Info.sConfigFileVersion = CString(szData);
	else
		m_stConfig.Info.sConfigFileVersion = _T("");

	str.Format(_T("%s: %s"), _T("File Version"), m_stConfig.Info.sConfigFileVersion);
	sData += str;
	sData += _T("\r\n");

	if (0 < ::GetPrivateProfileString(_T("Info"), _T("Machine Name"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Info.sMachineName = CString(szData);
	else
		m_stConfig.Info.sMachineName = _T("");

	str.Format(_T("%s: %s"), _T("Machine Name"), m_stConfig.Info.sMachineName);
	sData += str;
	sData += _T("\r\n");

	sData += _T("\r\n");
	sData += _T("[Devices Name]");
	sData += _T("\r\n");
	if (0 < ::GetPrivateProfileString(_T("Devices Name"), _T("IO"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.sIO = CString(szData);
	else
		m_stConfig.Devices.sIO = _T("");

	str.Format(_T("%s: %s"), _T("IO"), m_stConfig.Devices.sIO);
	sData += str;
	sData += _T("\r\n");

	if (0 < ::GetPrivateProfileString(_T("Devices Name"), _T("Light Num"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.nNumLight = _ttoi(szData);
	else
		m_stConfig.Devices.nNumLight = 0;

	for (i = 0; i < m_stConfig.Devices.nNumLight; i++)
	{
		sItem.Format(_T("Light%d"), i + 1);
		if (0 < ::GetPrivateProfileString(_T("Devices Name"), sItem, NULL, szData, sizeof(szData), sPath))
			m_stConfig.Devices.sLight[i] = CString(szData);
		else
			m_stConfig.Devices.sLight[i] = _T("");

		str.Format(_T("%s: %s"), sItem, m_stConfig.Devices.sLight[i]);
		sData += str;
		sData += _T("\r\n");
	}

	if (0 < ::GetPrivateProfileString(_T("Devices Name"), _T("Motion"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.sMotion = CString(szData);
	else
		m_stConfig.Devices.sMotion = CString(szData);

	str.Format(_T("%s: %s"), _T("Motion"), m_stConfig.Devices.sMotion);
	sData += str;
	sData += _T("\r\n");

	if (0 < ::GetPrivateProfileString(_T("Devices Name"), _T("Camera Num"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.nNumCamera = _ttoi(szData);
	else
		m_stConfig.Devices.nNumCamera = 0;

	for (i = 0; i < m_stConfig.Devices.nNumCamera; i++)
	{
		sItem.Format(_T("Camera%d"), i + 1);
		if (0 < ::GetPrivateProfileString(_T("Devices Name"), sItem, NULL, szData, sizeof(szData), sPath))
			m_stConfig.Devices.sCamera[i] = CString(szData);
		else
			m_stConfig.Devices.sCamera[i] = _T("");

		str.Format(_T("%s: %s"), sItem, m_stConfig.Devices.sCamera[i]);
		sData += str;
		sData += _T("\r\n");
	}

	if (0 < ::GetPrivateProfileString(_T("Devices Name"), _T("Trigger"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.sTrigger = CString(szData);
	else
		m_stConfig.Devices.sTrigger = CString(szData);

	str.Format(_T("%s: %s"), _T("Trigger"), m_stConfig.Devices.sTrigger);
	sData += str;
	sData += _T("\r\n");

	if (0 < ::GetPrivateProfileString(_T("Devices Name"), _T("2D Barcode"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.s2DBarcode = CString(szData);
	else
		m_stConfig.Devices.s2DBarcode = CString(szData);

	str.Format(_T("%s: %s"), _T("2D Barcode"), m_stConfig.Devices.s2DBarcode);
	sData += str;
	sData += _T("\r\n");

	return TRUE;
}
