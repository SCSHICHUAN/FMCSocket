#pragma once

// MySocket ����Ŀ��

class CFMCSocketClinetDlg;

class MySocket : public CSocket
{
public:
	MySocket(CFMCSocketClinetDlg *pDlg);//�൱�ڴ�����
	CFMCSocketClinetDlg *m_pDlg;

	MySocket();
	virtual ~MySocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


