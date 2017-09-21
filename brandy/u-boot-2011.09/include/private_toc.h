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

#ifndef  __toc_v2_h
#define  __toc_v2_h


#include "spare_head.h"

#define  TOC0_MAGIC             "TOC0.GLH"
#define  TOC_MAIN_INFO_MAGIC    0x89119800


#define  SECURE_SWITCH_OTHER   0
#define  SECURE_SWITCH_NORMAL  1
#define  SECURE_NON_SECUREOS   2

typedef struct
{
	u8  name[8];	  //�ַ��������Ը��ģ�û��������
	u32 magic;	      //������0x89119800
	u32 check_sum;    //�������ݵ�У��ͣ��ο�����boot0����

	u32 serial_num;   //���кţ����Ը��ģ�û������
	u32 status;       //���Ը��ģ�û������

	u32 items_nr;	  //�ܵ���Ŀ��������TOC0��˵��������2
	u32 length;	      //TOC0�ĳ���
	u8  platform[4];  //toc_platform[0]��ʾ��������
	u32 reserved[2];  //����λ
	u32 end;          //��ʾͷ���ṹ�������������0x3b45494d

}
toc0_private_head_t;

typedef struct sbrom_toc1_head_info
{
	char name[16]	;
	u32  magic	;
	u32  add_sum	;

	u32  serial_num	;
	u32  status		;

	u32  items_nr;
	u32  valid_len;
	u32  reserved[5];
	u32  end;
}
sbrom_toc1_head_info_t;


typedef struct sbrom_toc1_item_info
{
	char name[64];		
	u32  data_offset;
	u32  data_len;
	u32  encrypt;		
	u32  type;			
	u32  run_addr;         
	u32  index;            
	u32  reserved[69];	  
	u32  end;
}sbrom_toc1_item_info_t;


typedef struct sbrom_toc0_config
{
	unsigned char    	config_vsn[4];
	unsigned int      	dram_para[32];  	// dram����
	int				  	uart_port;      	// UART���������
	normal_gpio_cfg   	uart_ctrl[2];    	// UART������GPIO
	int              	enable_jtag;    	// JTAGʹ��
	normal_gpio_cfg   	jtag_gpio[5];    	// JTAG������GPIO
	normal_gpio_cfg  	storage_gpio[50]; 	// �洢�豸 GPIO��Ϣ
	char   				storage_data[384];  // 0-159,�洢nand��Ϣ��160-255,��ſ���Ϣ
	unsigned int        secure_dram_mbytes;
	unsigned int        drm_start_mbytes;  
	unsigned int        drm_size_mbytes;   
	unsigned int        boot_cpu;          
	special_gpio_cfg  a15_power_gpio; 
	unsigned int        next_exe_pa;
        unsigned int        secure_without_OS;  
        unsigned int        debug_mode;        
	unsigned int      	res[3];   			// �ܹ�1024�ֽ�

}
sbrom_toc0_config_t;

#endif    

/* end of toc.h */
