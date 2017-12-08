#pragma once

// MySocket 命令目标

class CFMCSocketClinetDlg;

class MySocket : public CSocket
{
public:
	MySocket(CFMCSocketClinetDlg *pDlg);//相当于代理方法
	CFMCSocketClinetDlg *m_pDlg;

	MySocket();
	virtual ~MySocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


