// Setting.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "��������.h"
#include "Setting.h"
#include "afxdialogex.h"


// Setting ��ȭ �����Դϴ�.

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


// Setting �޽��� ó�����Դϴ�.
