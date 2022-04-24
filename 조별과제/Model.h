#pragma once


// Model 대화 상자입니다.

class Model : public CDialogEx
{
	DECLARE_DYNAMIC(Model)

public:
	Model(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Model();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Model };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
