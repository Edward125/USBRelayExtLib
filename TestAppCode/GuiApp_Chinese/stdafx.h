// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#ifdef _DEBUG
#pragma comment(lib, "../../xcgui/XCGUId.lib")
#pragma comment(lib, "../../usb_relay_dll/usb_relay_device.lib")
#else
#pragma comment(lib, "../../xcgui/XCGUI.lib")
#pragma comment(lib, "../../usb_relay_dll/usb_relay_device.lib")
#endif

#include "../../xcgui/xcgui.h"
#include "../../usb_relay_dll/usb_relay_device.h"

#include "str_tools.h"

#include <map>
using namespace std;
