#pragma once


// ModelDialog ��ȭ �����Դϴ�.

class ModelDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ModelDialog)

public:
	ModelDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ModelDialog();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Model };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
