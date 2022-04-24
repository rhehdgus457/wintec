
// 조별과제Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "조별과제.h"
#include "조별과제Dlg.h"
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

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// C조별과제Dlg 대화 상자



C조별과제Dlg::C조별과제Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_EditDate(_T(""))
	, m_EditTime(_T(""))
	, m_strModel(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C조별과제Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Date, m_EditDate);
	DDX_Text(pDX, IDC_EDIT_Time, m_EditTime);
	DDX_CBString(pDX, IDC_COMBO_Model, m_strModel);
	//  DDX_Text(pDX, IDC_EDIT_Point, m_EditPoint);
}

BEGIN_MESSAGE_MAP(C조별과제Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Exit, &C조별과제Dlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_Video, &C조별과제Dlg::OnBnClickedButtonVideo)
	ON_BN_CLICKED(IDC_BUTTON_Select, &C조별과제Dlg::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_Setting, &C조별과제Dlg::OnBnClickedButtonSetting)
	ON_BN_CLICKED(IDC_BUTTON_Start, &C조별과제Dlg::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// C조별과제Dlg 메시지 처리기

BOOL C조별과제Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//CRect 값
	m_MLCCImage = CRect(20, 20, 890, 700);
	m_Back = CRect(522, 20, 672, 100);
	
	//Back Draw
	//좌표 수정 필요



	//실행 시 날짜, 시간 editcontrol에 나오기 (폰트, 글자 크기, 배경 수정 필요)
	SetTimer(1,100,NULL);
	char DateText[100];
	char TimeText[100];
	
	SYSTEMTIME sT;
	GetLocalTime(&sT);
	//날짜 (년-월-일)
	sprintf(DateText, "%d-%d-%d", sT.wYear, sT.wMonth, sT.wDay);
	m_EditDate = DateText;
	//시간 (시:분)
	sprintf(TimeText, "%d:%d", sT.wHour, sT.wMinute);
	m_EditTime = TimeText;


	//검사 모델 combo box (수정 필요) // 검사 모델 정보, 선택에 따른 변경
	//다이얼로그 간의 연동되는 변수 추가하여 모델 다이얼로그에 연동
	if (m_strModel == "하나")
		MessageBox("하나");
	else if (m_strModel == "둘")
		MessageBox("둘");
	else if (m_strModel == "셋")
		MessageBox("셋");
	else if (m_strModel == "넷")
		MessageBox("넷");
	else if (m_strModel == "다섯")
		MessageBox("다섯");



	//검사 수 
	static int check_count;
	
	
	
	
	
	UpdateData(FALSE);




	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C조별과제Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void C조별과제Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR C조별과제Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void C조별과제Dlg::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void C조별과제Dlg::OnBnClickedButtonVideo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//가져오는 img 함수 저장하는 변수 추가 필요
	//반복문 혹은 버튼을 이용하여 추가적인 이미지 추가 필요
	

	// CImage로 jpg가져오기
	CClientDC dc(this);
	m_Img.Load("./res/001-1.jpg");
	m_Img.StretchBlt(dc, m_MLCCImage.left, m_MLCCImage.top, m_MLCCImage.right, m_MLCCImage.bottom, SRCCOPY);

	



}


void C조별과제Dlg::OnBnClickedButtonSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Model dlg;
	dlg.DoModal();

}


void C조별과제Dlg::OnBnClickedButtonSetting()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Setting dlg;
	dlg.DoModal();
}


void C조별과제Dlg::OnBnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CImage to Mat
	//Mat 이미지 크기 변환 추가
	Mat contour_img;
	contour_img = imread("./res/001-1.jpg");
	
	//contour_img = Mat(m_MLCCImage.Height(), m_MLCCImage.Width(), CV_8U, 50);
	//contour_img.copyTo(copy_img);

	imshow("imgae", contour_img);
	
	

	//Edge 검출, 허프변환, Blob, 오류 처리

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
