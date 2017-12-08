#pragma once

// MyCAsyncSocket 命令目标

class CFMCSocketClinetDlg;


class MyCAsyncSocket : public CAsyncSocket
{
public:
	MyCAsyncSocket(CFMCSocketClinetDlg *pDlg);//相当于代理方法
	CFMCSocketClinetDlg *m_pDlg2;

	


	MyCAsyncSocket();
	virtual ~MyCAsyncSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
};


