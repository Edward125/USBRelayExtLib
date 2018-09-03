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

	//查找设备按钮事件
	BOOL OnFindDeviceBtnClick(HELE hEle,HELE hEleEvent);
	//打开设备按钮事件
	BOOL OnOpenDeviceBtnClick(HELE hEle,HELE hEleEvent);
	//关闭设备按钮事件
	BOOL OnCloseDeviceBtnClick(HELE hEle,HELE hEleEvent);

	//打开某路继电器按钮事件
	BOOL OnOpenRelayBtnClick(HELE hEle, HELE hEleEvent);
	//关闭某路继电器按钮事件
	BOOL OnCloseRelayBtnClick(HELE hEle, HELE hEleEvent);
	//打开所有继电器按钮事件
	BOOL OnOpenAllRelayBtnClick(HELE hEle, HELE hEleEvent);
	//关闭所有继电器按钮事件
	BOOL OnCloseAllRelayBtnClick(HELE hEle, HELE hEleEvent);
	


public:
	HWINDOW m_hWindow; //窗口句柄

	HELE    m_hFindDeviceBtn; //查找设备句柄
	HELE	m_hDeviceListBox; //设备列表框

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