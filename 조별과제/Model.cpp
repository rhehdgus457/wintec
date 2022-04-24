// Model.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "조별과제.h"
#include "Model.h"
#include "afxdialogex.h"


// Model 대화 상자입니다.

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


// Model 메시지 처리기입니다.


void Model::OnBnClickedCheckOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if (m_checkOne == TRUE)
		m_strEdit = "하나가 선택되었습니다.";
	else
		m_strEdit = "하나가 해체되었습니다.";

	UpdateData(FALSE);

}


void Model::OnBnClickedCheckTwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if (m_checkTwo == TRUE)
		m_strEdit = "둘이 선택되었습니다.";
	else
		m_strEdit = "둘이 해체되었습니다.";

	UpdateData(FALSE);
}


void Model::OnBnClickedCheckThree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if (m_checkThree == TRUE)
		m_strEdit = "셋이 선택되었습니다.";
	else
		m_strEdit = "셋이 해체되었습니다.";

	UpdateData(FALSE);
}


void Model::OnBnClickedCheckFour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if (m_checkFour == TRUE)
		m_strEdit = "넷이 선택되었습니다.";
	else
		m_strEdit = "넷이 해체되었습니다.";

	UpdateData(FALSE);
}


void Model::OnBnClickedCheckFive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if (m_checkFive == TRUE)
		m_strEdit = "다섯이 선택되었습니다.";
	else
		m_strEdit = "다섯이 해체되었습니다.";

	UpdateData(FALSE);
}


void Model::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
