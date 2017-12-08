
// FMCSocketClinetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FMCSocketClinet.h"
#include "FMCSocketClinetDlg.h"
#include "afxdialogex.h"

#include<afxsock.h> //socket

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define hostIP  _T("116.62.11.154")
#define port    443

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


// CFMCSocketClinetDlg 对话框



CFMCSocketClinetDlg::CFMCSocketClinetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FMCSOCKETCLINET_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFMCSocketClinetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFMCSocketClinetDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFMCSocketClinetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFMCSocketClinetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFMCSocketClinetDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CFMCSocketClinetDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CFMCSocketClinetDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CFMCSocketClinetDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CFMCSocketClinetDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CFMCSocketClinetDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CFMCSocketClinetDlg 消息处理程序

BOOL CFMCSocketClinetDlg::OnInitDialog()
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


	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFMCSocketClinetDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFMCSocketClinetDlg::OnPaint()
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
HCURSOR CFMCSocketClinetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
	
}





#pragma warning(disable:4996)//不要有4996错误
#pragma comment(lib,"ws2_32.lib")//lib动态链接库

#include<WinSock2.h>//socket2.2的版本
#include<stdio.h>
#include<stdlib.h>


const char subscribe[] = { 1,1, 0,0,0,14 + 8 + 10 + 8, 1,1, 0,25, 0,0,0,2,
0,0,0,10, 0,0,0,8, 'D','Y','0','9','0','0','0','1','0','5','a','b','c','d','1','2','3','4' };
const char getpic[] = { 1,1, 0,0,0,14 + 4 + 10, 1,1, 0,35, 0,0,0,1,
0,0,0,10, 'D','Y','0','9','0','0','0','1','0','5' };
unsigned char buffer[1000];


WSADATA wsaData;
SOCKET  s;
SOCKADDR_IN ServerAddr;
int     Ret;
int     Port = 443;

int getInt(char buffer[], int index)
{
	//拼接出一个int出来
	//这样写也是可以的 buffer[index] << 24, 但是这样“& 0x000000ff”写是暗含类型转换，如果不这样写会出现正负出错
	return ((buffer[index] & 0x000000ff) << 24)  
		+ ((buffer[index + 1] & 0x000000ff) << 16)
		+ ((buffer[index + 2] & 0x000000ff) << 8)
		+ (buffer[index + 3] & 0x000000ff);
}
int getShort(const unsigned char buffer[], int index)
{
	return (short)(((buffer[index] & 0x00ff) << 8)
		+ (buffer[index + 1] & 0x00ff));
}
int a = 1;
int argLens[10] = { 0 };
char arg[1024*4] = { 0 };
CString str2;

 
char cmd[2];//命令消息
int  GetCmd(char buffer[])
{
	memcpy(cmd, buffer + 8, 2);
	return ((cmd[0] << 8) + (cmd[1] << 0));
}




void  CFMCSocketClinetDlg::parseCommand(char  buffer[])
{
	int argNum = getInt(buffer, 10);
	int command = GetCmd(buffer);



	for (int i = 0, offset = 0; i < argNum; i++) {
		int len = getInt(buffer, 14 + i * 4);
		offset += argLens[i];
		memcpy(arg, buffer + 14 + 4 * argNum + offset, len);
	



		//解决乱码问题,把字符串转换为宽字符
		wchar_t *pwText = NULL;
		DWORD dwNum = MultiByteToWideChar(CP_UTF8, 0, arg, -1, NULL, 0);    //返回原始ASCII码的字符数目       
		pwText = new wchar_t[dwNum];                                        //根据ASCII码的字符数分配UTF8的空间
		MultiByteToWideChar(CP_UTF8, 0, arg, -1, pwText, dwNum);

		CString str;
		str.Format(
		_T("       command = %d\r\nparameterCont = %d\r\n          nlength = %d\r\n      parameter = %s\r\n\r\n"), 
			command,argNum,len, pwText);
		str2 += str;
		
		

		if (command == 56 && i == 1) {
			for (int c = 0; c <13; c++) {
				str.Format(_T("status = %u \r\n"), arg[c]);
				str2 += str;
			}
		}

			//SetDlgItemText(IDC_EDIT1, str2);
	
		//用于子线程中刷新UI
		::SetDlgItemText(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_EDIT1, str2);

		//AfxMessageBox(str);
		//str.Format(_T("%s"), pwText);
		//SendDlgItemMessage(IDC_EDIT1, WM_VSCROLL, SB_BOTTOM, 0);

		//子线程中滚动edit control
		::SendDlgItemMessage(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_EDIT1, WM_VSCROLL, SB_BOTTOM,0);

		
		if (command == 15 && len > 80)
		{
			//ShellExecute(NULL, NULL, pwText, NULL, NULL, SW_NORMAL);//打开网页
			//ShellExecute(NULL, NULL, pwText, NULL, NULL, SW_SHOWMAXIMIZED);
			ShellExecute(NULL, _T("open"), _T("IEXPLORE"), pwText, NULL, SW_SHOWMAXIMIZED);
			//ShellExecute(NULL, _T("open"), _T("EDGE"), pwText, NULL, SW_SHOWMAXIMIZED);


			
		}

		
		
		

		argLens[i + 1] = len;
	}
}
UINT DomeB(LPVOID pParam);
void  CFMCSocketClinetDlg::oldSocket()
{

	
	//1.加载和初始化网络库
	if ((Ret = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
	{
		printf("WSAStarup faiked with error. %d\n", Ret);
	}

	//2.创建套接字
	if ((s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		printf("socket filed with error. %d\n", WSAGetLastError());
		WSACleanup();
	}

	//3.开始链接
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(Port); //链接的端口
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("116.62.11.154"); // 

	  // printf("We are trying to  connect to %s:%d...\n", inet_ntoa(ServerAddr.sin_addr), htons(ServerAddr.sin_port));

																  //4.链接
	if ((connect(s, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr))) == SOCKET_ERROR)
	{
		printf("connect failed with error. %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();

	}
	else
	{
		printf("和服务器链接成功!\n");
	}



	//5.向服务器注册socket
	if ((Ret = send(s, subscribe, sizeof(subscribe), 0)) == SOCKET_ERROR)
	{
		printf("Sent failed with error %d.\n", WSAGetLastError());


		closesocket(s);
		WSACleanup();
	}
	else
	{
		printf("已经发送的数据!\n");
	}


	//接收http返回
	char DataBuffer[10240] = {0};//缓存客服端发送的数据
						   //6.用客服端的套接字去接收,客服端的数据,函数“recv”


	if ((Ret = recv(s, DataBuffer, sizeof(DataBuffer), 0)) == SOCKET_ERROR)
	{
		printf("recv failed with error %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
	}
	//到这一行http请求返回的数据已经存入DataBuffer中
	else
	{ 
		//子线程中处理数据
		AfxBeginThread(DomeB, NULL);

	}
	

}
UINT DomeB(LPVOID pParam)
{
	CFMCSocketClinetDlg *pThis = (CFMCSocketClinetDlg *)pParam;

	// TODO: 在此添加控件通知处理程序代码

	while (1)
	{
		char DataBuffer[10240] = { 0 };
		recv(s, DataBuffer, sizeof(DataBuffer), 0);
		pThis->parseCommand(DataBuffer);
		
	}

	return 0;
}

UINT DomeC(LPVOID pParam)
{
	CFMCSocketClinetDlg *pThis = (CFMCSocketClinetDlg *)pParam;

	// TODO: 在此添加控件通知处理程序代码
	pThis->Cscket();
	return 0;
}




void CFMCSocketClinetDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	oldSocket();
	//LPCWSTR ff = _T("http://iotguard.oss-cn-hangzhou.aliyuncs.com/eedb549c-0898-41d1-8deb-97a2d9b4ed25.jpg");
	//ShellExecute(0, NULL, ff, NULL, NULL, SW_NORMAL);	
}






//创建 CSocket 对象
void CFMCSocketClinetDlg::Cscket()
{

	

	AfxSocketInit();

	CSocket m_aSocket;



	//CSocket m_aSocket;
	if (!m_aSocket.Create())
	{	
		CString str;
		str.Format(_T("create faild: %d"), m_aSocket.GetLastError());
		return;
	}
	else
	{
	//	AfxMessageBox(_T("create ok"));
	}


	//连接指定的地址和端口
	if (m_aSocket.Connect(hostIP, port))
	{

		//AfxMessageBox(_T("link ok"));

		char szRecValue[1024 * 3] = { 0 };

		//发送内容给服务器
		if (m_aSocket.Send(subscribe, sizeof(subscribe))) {
			//AfxMessageBox(_T("Send ok"));
		}

		if (m_aSocket.Send(getpic, sizeof(getpic))) {
			//AfxMessageBox(_T("Send ok"));
		}



		//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
		while (1)
		{
			{
				char szRecValue[1024 * 3] = { 0 };
				//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
				if (m_aSocket.Receive((void *)szRecValue, 1024 * 3))
				{
					//AfxMessageBox(_T("Receive ok"));
					parseCommand(szRecValue);
				}
			}

		}
		

	}
	else
	{
		CString str;
		str.Format(_T("create faild: %d"), m_aSocket.GetLastError());
	}

	//关闭
	//aSocket.Close();
}

void CFMCSocketClinetDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//Cscket();
	AfxBeginThread(DomeC, NULL);
}


void takePhoto(SOCKET s)
{
	send(s, getpic, sizeof(getpic), 0);
}

void CFMCSocketClinetDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	takePhoto(s);
}



void takePhoto2(MySocket *mySocket)
{

	//发送内容给服务器


	if (mySocket->Send(getpic, sizeof(getpic))) {
		//AfxMessageBox(_T("Send ok"));
	}


	
}

void CFMCSocketClinetDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	takePhoto2(m_pCSocket);
}

UINT DomeD(LPVOID pParam)
{
	CFMCSocketClinetDlg *pThis = (CFMCSocketClinetDlg *)pParam;

	//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
	while (1)
	{
		{
			char szRecValue[1024 * 3] = { 0 };
			//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
			if ((pThis->m_pCSocket)->Receive(szRecValue, 1024 * 3))
			{
				//AfxMessageBox(_T("Receive ok"));
				pThis->parseCommand(szRecValue);
			}
		}

	}
	return 0;
}
void CFMCSocketClinetDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxSocketInit();
	m_pCSocket = new MySocket(this);
	m_pCSocket->Create();
	if (m_pCSocket->Connect(hostIP, port))
	{
		//AfxMessageBox(_T("链接成功"));
		if (m_pCSocket->Send(subscribe, sizeof(subscribe))) {
			//AfxMessageBox(_T("Send ok"));
			char szRecValue[1024 * 3] = { 0 };
			//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
			if ((m_pCSocket)->Receive((void *)szRecValue, 1024 * 3))
			{
				//AfxMessageBox(_T("Receive ok"));
				parseCommand(szRecValue);
			}
		}
	}
	else
	{
		delete m_pCSocket;
		AfxMessageBox(_T("链接失败"));
	}

	
	//AfxBeginThread(DomeD,this);

}


void CFMCSocketClinetDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	AfxSocketInit();
	m_pAsyncSocket = new MyCAsyncSocket(this);
	m_pAsyncSocket->Create();

	if (m_pAsyncSocket->Connect(hostIP, port) || GetLastError() == 10035) {
		AfxMessageBox(_T("m_pAsyncSocket 链接成功"));
	}
	else
	{
		CString str;
		str.Format(_T("error %d"), GetLastError());
		AfxMessageBox(str);
	}


}


void CFMCSocketClinetDlg::OnBnClickedButton7()
{
	
	//AfxMessageBox(_T("链接成功"));
	if (m_pAsyncSocket->Send(subscribe, sizeof(subscribe))) {
		//AfxMessageBox(_T("Send ok"));
		char szRecValue[1024 * 3] = { 0 };
		//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
		if ((m_pAsyncSocket)->Receive((void *)szRecValue, 1024 * 3))
		{
			//AfxMessageBox(_T("Receive ok"));
			parseCommand(szRecValue);
		}
	}


}


void CFMCSocketClinetDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxMessageBox(_T("链接成功"));
	if (m_pAsyncSocket->Send(getpic, sizeof(getpic))) {
		//AfxMessageBox(_T("Send ok"));
		char szRecValue[1024 * 3] = { 0 };
		//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
		if ((m_pAsyncSocket)->Receive((void *)szRecValue, 1024 * 3))
		{
			//AfxMessageBox(_T("Receive ok"));
			parseCommand(szRecValue);
		}
	}
}
