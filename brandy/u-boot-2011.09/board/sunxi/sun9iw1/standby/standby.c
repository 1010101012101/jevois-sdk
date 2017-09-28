/*
 * (C) Copyright 2007-2013
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Jerry Wang <wangflord@allwinnertech.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <common.h>
#include "standby_i.h"
#include "standby.h"

DECLARE_GLOBAL_DATA_PTR;

static int boot_early_standby_mode(void);


int boot_standby_mode(void)
{
	int status;


	boot_store_sp();
	boot_set_sp();

	status = boot_early_standby_mode();

	boot_restore_sp();

	return status;
}
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
static int boot_early_standby_mode(void)
{
#if 0
	__s32 key_status, usb_status;
	__s32 status;

	key_status = standby_axp_probe_key();
	if(key_status & 0x01)			//������������£����ܵ�Դ�Ƿ��Ƴ���ֱ�ӽ���ϵͳ
	{
		if(standby_flag)
		{
			boot_mod_exit_standby();
		}
		return 3;
	}
	if(standby_axp_probe_power_exist() <= 0)
	{
		if(standby_flag)
		{
			boot_mod_exit_standby();
		}
		return 4;
	}
	if(key_status & 0x02)			//�̰���ѹ����������£���ʾ��綯��
	{
		if(standby_flag)
		{
			boot_mod_exit_standby();
		}
		return 2;
	}
	if(!standby_flag)
	{
		boot_mod_enter_standby();      //����ģ�����standby
	}
	usb_status = standby_axp_probe_usb();
	if(usb_status > 0)
	{
		return 8;
	}
	status = -1;
	do
	{
		boot_halt();
		status = boot_standby_detect();
	}
	while(status <= 0);
	boot_exit_standby();
	if(status != 8)
	{
		boot_mod_exit_standby();
		standby_flag = 0;
	}
	else
	{
		standby_flag = 1;
	}

	return status;
#else
	return 0;
#endif
}
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/




