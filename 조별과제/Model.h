#pragma once


// Model ��ȭ �����Դϴ�.

class Model : public CDialogEx
{
	DECLARE_DYNAMIC(Model)

public:
	Model(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Model();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Model };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strEdit;
	BOOL m_checkOne;
	BOOL m_checkTwo;
	BOOL m_checkThree;
	BOOL m_checkFour;
	BOOL m_checkFive;
	afx_msg void OnBnClickedCheckOne();
	afx_msg void OnBnClickedCheckTwo();
	afx_msg void OnBnClickedCheckThree();
	afx_msg void OnBnClickedCheckFour();
	afx_msg void OnBnClickedCheckFive();
	afx_msg void OnBnClickedButtonExit();
};
