
// ��������Dlg.h : ��� ����
//

#pragma once


// C��������Dlg ��ȭ ����
class C��������Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	C��������Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.

protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedStaticOne();
	afx_msg void OnBnClickedButtonExit();
	CString m_EditDate;
	CString m_EditTime;
	CString m_strModel;
	afx_msg void OnBnClickedButtonVideo();
	afx_msg void OnBnClickedButtonSelect();
//	CString m_EditPoint;
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonSetting();
	CRect m_MLCCImage;
	CRect m_Back;
	CImage m_Img;
	
	afx_msg void OnBnClickedButtonStart();
};
