
// ��������Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "��������.h"
#include "��������Dlg.h"
#include "afxdialogex.h"
#include "Model.h"
#include "Setting.h"
#include "atlimage.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2\opencv.hpp>
#include <iostream>
#include <stdio.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//opencv
using namespace cv;
using namespace std;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
	CFont newFont;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C��������Dlg ��ȭ ����



C��������Dlg::C��������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_EditDate(_T(""))
	, m_EditTime(_T(""))
	, m_strModel(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Date, m_EditDate);
	DDX_Text(pDX, IDC_EDIT_Time, m_EditTime);
	DDX_CBString(pDX, IDC_COMBO_Model, m_strModel);
	//  DDX_Text(pDX, IDC_EDIT_Point, m_EditPoint);
}

BEGIN_MESSAGE_MAP(C��������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Exit, &C��������Dlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_Video, &C��������Dlg::OnBnClickedButtonVideo)
	ON_BN_CLICKED(IDC_BUTTON_Select, &C��������Dlg::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_Setting, &C��������Dlg::OnBnClickedButtonSetting)
	ON_BN_CLICKED(IDC_BUTTON_Start, &C��������Dlg::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// C��������Dlg �޽��� ó����

BOOL C��������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//CRect ��
	m_MLCCImage = CRect(20, 20, 890, 700);
	m_Back = CRect(522, 20, 672, 100);
	
	//Back Draw
	//��ǥ ���� �ʿ�



	//���� �� ��¥, �ð� editcontrol�� ������ (��Ʈ, ���� ũ��, ��� ���� �ʿ�)
	SetTimer(1,100,NULL);
	char DateText[100];
	char TimeText[100];
	
	SYSTEMTIME sT;
	GetLocalTime(&sT);
	//��¥ (��-��-��)
	sprintf(DateText, "%d-%d-%d", sT.wYear, sT.wMonth, sT.wDay);
	m_EditDate = DateText;
	//�ð� (��:��)
	sprintf(TimeText, "%d:%d", sT.wHour, sT.wMinute);
	m_EditTime = TimeText;


	//�˻� �� combo box (���� �ʿ�) // �˻� �� ����, ���ÿ� ���� ����
	//���̾�α� ���� �����Ǵ� ���� �߰��Ͽ� �� ���̾�α׿� ����
	if (m_strModel == "�ϳ�")
		MessageBox("�ϳ�");
	else if (m_strModel == "��")
		MessageBox("��");
	else if (m_strModel == "��")
		MessageBox("��");
	else if (m_strModel == "��")
		MessageBox("��");
	else if (m_strModel == "�ټ�")
		MessageBox("�ټ�");



	//�˻� �� 
	static int check_count;
	
	
	
	
	
	UpdateData(FALSE);




	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void C��������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void C��������Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR C��������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void C��������Dlg::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void C��������Dlg::OnBnClickedButtonVideo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//�������� img �Լ� �����ϴ� ���� �߰� �ʿ�
	//�ݺ��� Ȥ�� ��ư�� �̿��Ͽ� �߰����� �̹��� �߰� �ʿ�
	

	// CImage�� jpg��������
	CClientDC dc(this);
	m_Img.Load("./res/001-1.jpg");
	m_Img.StretchBlt(dc, m_MLCCImage.left, m_MLCCImage.top, m_MLCCImage.right, m_MLCCImage.bottom, SRCCOPY);

	



}


void C��������Dlg::OnBnClickedButtonSelect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Model dlg;
	dlg.DoModal();

}


void C��������Dlg::OnBnClickedButtonSetting()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Setting dlg;
	dlg.DoModal();
}


void C��������Dlg::OnBnClickedButtonStart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CImage to Mat
	//Mat �̹��� ũ�� ��ȯ �߰�
	Mat contour_img;
	contour_img = imread("./res/001-1.jpg");
	
	//contour_img = Mat(m_MLCCImage.Height(), m_MLCCImage.Width(), CV_8U, 50);
	//contour_img.copyTo(copy_img);

	imshow("imgae", contour_img);
	
	

	//Edge ����, ������ȯ, Blob, ���� ó��

	//findcontour
	/*vector<vector<Point>> contours;
	findContours(contour_img, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	Mat dst;
	cvtColor(contour_img, dst, COLOR_GRAY2BGR);

	Scalar c(0, 0, 255);

	for (int i = 0; i < contours.size(); i++) {
	drawContours(dst, contours, i, c, 3);
	}

	imshow("contour_img", contour_img);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();*/
}
