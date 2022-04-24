// Model.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "��������.h"
#include "Model.h"
#include "afxdialogex.h"


// Model ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Model, CDialogEx)

Model::Model(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Model, pParent)
	, m_strEdit(_T(""))
	, m_checkOne(FALSE)
	, m_checkTwo(FALSE)
	, m_checkThree(FALSE)
	, m_checkFour(FALSE)
	, m_checkFive(FALSE)
{

}

Model::~Model()
{
}

void Model::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_strEdit);
	DDX_Check(pDX, IDC_CHECK_One, m_checkOne);
	DDX_Check(pDX, IDC_CHECK_Two, m_checkTwo);
	DDX_Check(pDX, IDC_CHECK_Three, m_checkThree);
	DDX_Check(pDX, IDC_CHECK_Four, m_checkFour);
	DDX_Check(pDX, IDC_CHECK_Five, m_checkFive);
}


BEGIN_MESSAGE_MAP(Model, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_One, &Model::OnBnClickedCheckOne)
	ON_BN_CLICKED(IDC_CHECK_Two, &Model::OnBnClickedCheckTwo)
	ON_BN_CLICKED(IDC_CHECK_Three, &Model::OnBnClickedCheckThree)
	ON_BN_CLICKED(IDC_CHECK_Four, &Model::OnBnClickedCheckFour)
	ON_BN_CLICKED(IDC_CHECK_Five, &Model::OnBnClickedCheckFive)
	ON_BN_CLICKED(IDC_BUTTON_Exit, &Model::OnBnClickedButtonExit)
END_MESSAGE_MAP()


// Model �޽��� ó�����Դϴ�.


void Model::OnBnClickedCheckOne()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_checkOne == TRUE)
		m_strEdit = "�ϳ��� ���õǾ����ϴ�.";
	else
		m_strEdit = "�ϳ��� ��ü�Ǿ����ϴ�.";

	UpdateData(FALSE);

}


void Model::OnBnClickedCheckTwo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_checkTwo == TRUE)
		m_strEdit = "���� ���õǾ����ϴ�.";
	else
		m_strEdit = "���� ��ü�Ǿ����ϴ�.";

	UpdateData(FALSE);
}


void Model::OnBnClickedCheckThree()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_checkThree == TRUE)
		m_strEdit = "���� ���õǾ����ϴ�.";
	else
		m_strEdit = "���� ��ü�Ǿ����ϴ�.";

	UpdateData(FALSE);
}


void Model::OnBnClickedCheckFour()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_checkFour == TRUE)
		m_strEdit = "���� ���õǾ����ϴ�.";
	else
		m_strEdit = "���� ��ü�Ǿ����ϴ�.";

	UpdateData(FALSE);
}


void Model::OnBnClickedCheckFive()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_checkFive == TRUE)
		m_strEdit = "�ټ��� ���õǾ����ϴ�.";
	else
		m_strEdit = "�ټ��� ��ü�Ǿ����ϴ�.";

	UpdateData(FALSE);
}


void Model::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
