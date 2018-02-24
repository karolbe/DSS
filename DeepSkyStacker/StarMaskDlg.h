#pragma once


// CStarMaskDlg dialog

class CStarMaskDlg : public CDialog
{
	DECLARE_DYNAMIC(CStarMaskDlg)

public:
	CStarMaskDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStarMaskDlg();

	void	SetBaseFileName(LPCTSTR szOutputFile)
	{
		TCHAR				szDrive[_MAX_DRIVE];
		TCHAR				szDir[_MAX_DIR];

		_splitpath(szOutputFile, szDrive, szDir, NULL, NULL);

		m_strOutputFile = szDrive;
		m_strOutputFile += szDir;
		m_strOutputFile += "StarMask";
	};

	void	GetOutputFileName(CString & strOutputFile, BOOL & bFits)
	{
		strOutputFile = m_strOutputFile;
		bFits		  = m_bOutputFITS;
	};

// Dialog Data
	enum { IDD = IDD_STARMASK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnStarShapeChange( );

	virtual BOOL OnInitDialog();
	virtual void OnOK();

	DECLARE_MESSAGE_MAP()
private :
	void	UpdateTexts();
	void	UpdateStarShapePreview();
	BOOL	AskOutputFile();

private :
	CString					m_strOutputFile;
	BOOL					m_bOutputFITS;
	CString					m_StarThresholdMask;
	CString					m_MinSizeMask;
	CString					m_MaxSizeMask;
	CString					m_PercentMask;
	CString					m_PixelsMask;

	CComboBox				m_StarShape;
	CStatic					m_StarShapePreview;
	CStatic					m_StarThresholdText;
	CSliderCtrl				m_StarThreshold;
	CButton					m_HotPixels;
	CStatic					m_MinSizeText;
	CSliderCtrl				m_MinSize;
	CStatic					m_MaxSizeText;
	CSliderCtrl				m_MaxSize;
	CStatic					m_PercentText;
	CSliderCtrl				m_Percent;
	CStatic					m_PixelsText;
	CSliderCtrl				m_Pixels;
};
