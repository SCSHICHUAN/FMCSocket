// MySocket.cpp : 实现文件
//

#include "stdafx.h"
#include "FMCSocketClinet.h"
#include "MySocket.h"
#include"FMCSocketClinetDlg.h"

// MySocket

MySocket::MySocket()
{
}

MySocket::~MySocket()
{
	
}

MySocket::MySocket(CFMCSocketClinetDlg *pDlg)
{
	m_pDlg = pDlg;
}
// MySocket 成员函数

//当CSocket有数据来时会自动的调用这个方法
void MySocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	//在一个类中使用另一个类的public方法
	//CFMCSocketClinetDlg *pDlg = new CFMCSocketClinetDlg;
	//m_pDlg->parseCommand(szRecValue);

	
	char szRecValue[1024 * 3] = { 0 };
	if (Receive(szRecValue, 1024 * 3))
	{	
		m_pDlg->parseCommand(szRecValue);
	}

	CSocket::OnReceive(nErrorCode);

}


void MySocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	AfxMessageBox(_T("CSocket 断开"));
	CSocket::OnClose(nErrorCode);
}
