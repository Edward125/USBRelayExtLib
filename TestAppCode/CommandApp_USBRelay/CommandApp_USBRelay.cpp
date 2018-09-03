// CommandApp_USBRelay.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>

using namespace std;

/*
ʹ�÷���˵����
CommandApp_USBRelay [�豸���к�]  [��������]  [�̵�������]

�豸���кţ�ÿ���豸��һ��Ψһ�����к�
�������ͣ�  open--�򿪼̵����� close-- �رռ̵���
�̵������أ�01��ʾ��һ���̵�����02��ʾ�ڶ����̵�����... 255��ʾ���м̵�������

���磺
1. �����к�afEd5�豸�ĵ�һ·�̵���
CommandApp_USBRelay  afEd5 open 01
2. �����к�afEd5�豸�����м̵���
CommandApp_USBRelay  afEd5 open 255
3. �ر����к�afEd5�豸�ĵ�һ·�̵���
CommandApp_USBRelay  afEd5 close 01
4. �ر����к�afEd5�豸�����м̵���
CommandApp_USBRelay  afEd5 close 255

�����й���ִ������������û�д����򷵻�0�� ���򷵻� 1
�����߿��Ը��ݸ�ֵ�ж�ִ���Ƿ���ȷ
*/

#pragma comment(lib, "setupapi.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	//argv[1] is the serial number
	if (argc != 4)
	{
		return 1;
	}

	unsigned int relay_index = atoi(argv[3]);
	
	usb_relay_init();

	/*
	struct usb_relay_device_info *device_info = usb_relay_device_enumerate();

	struct usb_relay_device_info *current_info =  device_info;
	struct usb_relay_device_info *find_info = NULL;

	 while (current_info != NULL) 
	{
		if (0 == strcmp(argv[1], (char*)(current_info->serial_number)))
		{
			find_info = current_info;
			break;
		}
		current_info = current_info->next;
	}

	current_info = NULL;

	if (find_info == NULL)
	{
		return 1;
	}

	*/
	//int hd = usb_relay_device_open(find_info);
	int hd = usb_relay_device_open_with_serial_number(argv[1], strlen(argv[1]));

	if (hd == 0)
	{
		return 1;
	}

	int ret = 0;

	if (strcmp(argv[2], "open") == 0)
	{
		if ((relay_index > 0) && (relay_index < 255) )
		{
			ret = usb_relay_device_open_one_relay_channel(hd, relay_index);
		}
		else if (relay_index == 255)
		{
			ret = usb_relay_device_open_all_relay_channel(hd);
		}
		else
		{
			ret =  1;
		}
	}
	else if (strcmp(argv[2], "close") == 0)
	{
		if ((relay_index > 0) && (relay_index < 255) )
		{
			ret = usb_relay_device_close_one_relay_channel(hd, relay_index);
		}
		else if (relay_index == 255)
		{
			ret = usb_relay_device_close_all_relay_channel(hd);
		}
		else
		{
			ret = 1;
		}
	}
	else
	{
		ret = 1;
	}


	//usb_relay_device_free_enumerate(device_info);
	//device_info = NULL;
	usb_relay_exit();

	return ret;
}

