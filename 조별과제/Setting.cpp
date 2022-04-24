// Setting.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "조별과제.h"
#include "Setting.h"
#include "afxdialogex.h"


// Setting 대화 상자입니다.

IMPLEMENT_DYNAMIC(Setting, CDialog)

Setting::Setting(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_Setting, pParent)
{

}

Setting::~Setting()
{
}

void Setting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Setting, CDialog)
END_MESSAGE_MAP()


// Setting 메시지 처리기입니다.
