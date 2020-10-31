
// MFCsocket1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCsocket1.h"
#include "MFCsocket1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCsocket1Dlg �Ի���



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


// CMFCsocket1Dlg ��Ϣ�������

BOOL CMFCsocket1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	//��linux�У�ʹ��int server= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	
	//bind() �󶨲��������׽���ip���˿����������
	sockaddr_in serveraddr;	//�����׽��ֵ�ַ���͵Ľṹ�����������Ϊ��������˵�ַ�塢�˿ںš�ip��ַ 
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(12345);	//htons()�Ѳ���ת����tcp/ip�������ֽ�˳�򣬽��������޷��Ŷ�������ת���������ֽ�˳��https://blog.csdn.net/zhuguorong11/article/details/523006808
	serveraddr.sin_addr.s_addr = inet_addr("192.168.1.132");	//���ַ���ת����ULONG
	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//���׽��ֺ��׽��ֵ�ַ��Ϣ
	
	
	//listen() ����
	listen(server, 5);//��һ��������Ҫ�����ķ��������ڶ��������ļ�����Ŀ


	//�첽ѡ��
	HWND hWnd = AfxGetMainWnd()->GetSafeHwnd();//���ھ��
	WSAAsyncSelect(server, hWnd, WM_SOCKET, FD_ACCEPT);		//�����������ھ�������ݵ���Ϣ��ʽ���Լ��궨�壩�������¼�

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCsocket1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
