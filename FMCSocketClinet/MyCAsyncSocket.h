#pragma once

// MyCAsyncSocket ����Ŀ��

class CFMCSocketClinetDlg;


class MyCAsyncSocket : public CAsyncSocket
{
public:
	MyCAsyncSocket(CFMCSocketClinetDlg *pDlg);//�൱�ڴ�����
	CFMCSocketClinetDlg *m_pDlg2;

	


	MyCAsyncSocket();
	virtual ~MyCAsyncSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
};


