
// MFCsocket1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCsocket1.h"
#include "MFCsocket1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
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


// CMFCsocket1Dlg 对话框



CMFCsocket1Dlg::CMFCsocket1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCSOCKET1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCsocket1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCsocket1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SOCKET, &CMFCsocket1Dlg::OnSocket)
END_MESSAGE_MAP()


// CMFCsocket1Dlg 消息处理程序

BOOL CMFCsocket1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	//在linux中，使用int server= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	
	//bind() 绑定操作，将套接字ip、端口与服务器绑定
	sockaddr_in serveraddr;	//创建套接字地址类型的结构体变量，并且为变量填充了地址族、端口号、ip地址 
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(12345);	//htons()把参数转换成tcp/ip的网络字节顺序，将主机的无符号短整形数转换成网络字节顺序。https://blog.csdn.net/zhuguorong11/article/details/523006808
	serveraddr.sin_addr.s_addr = inet_addr("192.168.1.132");	//把字符串转换成ULONG
	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//绑定套接字和套接字地址信息
	
	
	//listen() 监听
	listen(server, 5);//第一个参数是要监听的服务器，第二个是最大的监听数目


	//异步选择
	HWND hWnd = AfxGetMainWnd()->GetSafeHwnd();//窗口句柄
	WSAAsyncSelect(server, hWnd, WM_SOCKET, FD_ACCEPT);		//服务器，窗口句柄，传递的消息形式（自己宏定义），连接事件

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCsocket1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCsocket1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCsocket1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



afx_msg LRESULT CMFCsocket1Dlg::OnSocket(WPARAM wParam, LPARAM lParam)
{
	if (WSAGETSELECTERROR(lParam)) {
		closesocket(wParam);
		return -1;
	}
	SOCKET client;
	sockaddr_in clientaddr;
	int len = sizeof(clientaddr);
	switch (WSAGETSELECTERROR(lParam)) {
	case FD_ACCEPT:

	case FD_READ:

	case FD_CLOSE:

	}
	return 0;
}
