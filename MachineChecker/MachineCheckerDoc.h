
// MachineCheckerDoc.h : CMachineCheckerDoc Ŭ������ �������̽�
//


#pragma once

#define MAX_LIGHT	4
#define MAX_CAMERA	4


struct stInfo
{
	CString sProgramVersion, sMachineName, sConfigFileVersion;

	stInfo()
	{
		sProgramVersion = _T(""); sMachineName = _T(""); sConfigFileVersion = _T("");
	}
};

struct stDevices
{
	int nNumLight, nNumCamera;
	CString sIO, sLight[MAX_LIGHT], sMotion, sCamera[MAX_CAMERA], sTrigger, s2DBarcode;

	stDevices()
	{
		int i;
		nNumLight = 0; nNumCamera = 0;
		sIO = _T(""); sMotion = _T(""); sTrigger = _T(""); s2DBarcode = _T("");		
		for (i = 0; i < MAX_LIGHT; i++) sLight[i] = _T("");
		for (i = 0; i < MAX_CAMERA; i++) sCamera[i] = _T("");
	}
};

struct stConfig
{
	stInfo Info;
	stDevices Devices;
};

class CMachineCheckerDoc : public CDocument
{
	stConfig m_stConfig;
	CString m_sPathPrevConfigFolder, m_sNamePrevConfigFile;

protected: // serialization������ ��������ϴ�.
	CMachineCheckerDoc();
	DECLARE_DYNCREATE(CMachineCheckerDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	CString GetPathPrevConfigFolder();
	CString GetNamePrevConfigFile();
	void SetPathPrevConfigFolder(CString sPath);
	void SetNamePrevConfigFile(CString sName);

	BOOL LoadConfig(CString sPath, CString& sData);
	CString GetProgramVersion();
	CString GetConfigFileVersion();
	CString GetMachineName();
	CString GetDeviceNameIO();
	CString GetDeviceNameLight(int nIndex);
	CString GetDeviceNameMotion();
	CString GetDeviceNameCamera(int nIndex);
	CString GetDeviceNameTrigger();
	CString GetDeviceName2DBarcode();

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMachineCheckerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
