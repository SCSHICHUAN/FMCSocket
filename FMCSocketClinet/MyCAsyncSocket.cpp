// MyCAsyncSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "FMCSocketClinet.h"
#include "MyCAsyncSocket.h"
#include"FMCSocketClinetDlg.h"//这个不引入不能用指针m_pDlg2

// MyCAsyncSocket

MyCAsyncSocket::MyCAsyncSocket()
{
}

MyCAsyncSocket::~MyCAsyncSocket()
{
}

MyCAsyncSocket::MyCAsyncSocket(CFMCSocketClinetDlg *pDlg)
{
	m_pDlg2 = pDlg;
}






// MyCAsyncSocket 成员函数


void MyCAsyncSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类


	char szRecValue[1024 * 3] = { 0 };
	//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
	if (Receive((void *)szRecValue, 1024 * 3))
	{
		//AfxMessageBox(_T("Receive ok"));
		m_pDlg2->parseCommand(szRecValue);
	}


	CAsyncSocket::OnReceive(nErrorCode);
}


void MyCAsyncSocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CAsyncSocket::OnClose(nErrorCode);
}


void MyCAsyncSocket::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	//AfxMessageBox(_T("链接中..."));
	CAsyncSocket::OnConnect(nErrorCode);
}
