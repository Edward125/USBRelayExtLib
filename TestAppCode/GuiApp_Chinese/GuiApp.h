#pragma once

#include "resource.h"

#include "GuiApp.h"

struct usb_relay_device_info;


class CUSBRelayWnd : public CXEventMsg
{
public:
	CUSBRelayWnd():m_pDeviceList(NULL), m_hCurDevice(0), m_bOpened(FALSE), m_hCureDeviceIndex(0)
	{

	}
	BOOL Create();

	//�����豸��ť�¼�
	BOOL OnFindDeviceBtnClick(HELE hEle,HELE hEleEvent);
	//���豸��ť�¼�
	BOOL OnOpenDeviceBtnClick(HELE hEle,HELE hEleEvent);
	//�ر��豸��ť�¼�
	BOOL OnCloseDeviceBtnClick(HELE hEle,HELE hEleEvent);

	//��ĳ·�̵�����ť�¼�
	BOOL OnOpenRelayBtnClick(HELE hEle, HELE hEleEvent);
	//�ر�ĳ·�̵�����ť�¼�
	BOOL OnCloseRelayBtnClick(HELE hEle, HELE hEleEvent);
	//�����м̵�����ť�¼�
	BOOL OnOpenAllRelayBtnClick(HELE hEle, HELE hEleEvent);
	//�ر����м̵�����ť�¼�
	BOOL OnCloseAllRelayBtnClick(HELE hEle, HELE hEleEvent);
	


public:
	HWINDOW m_hWindow; //���ھ��

	HELE    m_hFindDeviceBtn; //�����豸���
	HELE	m_hDeviceListBox; //�豸�б��

	HELE    m_hOpenDeviceBtn;
	HELE	m_hOpenStatus;
	BOOL    m_bOpened;
	HELE	m_hCloseDeviceBtn;

	HELE    m_hRelayText[8];
	HELE	m_hRelayOpenBtn[8];
	HELE	m_hRelayCloseBtn[8];
	HELE	m_hRelayStatusLabel[8];

	HELE	m_hOpenAllRelayBtn;
	HELE	m_hCloseAllRelayBtn;

	/*****************************/
	struct usb_relay_device_info *m_pDeviceList;
	int m_hCurDevice;
	int m_hCureDeviceIndex;

	std::map<std::wstring, struct usb_relay_device_info*> m_mapIndexToDevice;
};