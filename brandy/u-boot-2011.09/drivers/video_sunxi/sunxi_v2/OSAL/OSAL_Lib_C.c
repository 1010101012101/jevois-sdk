/*
*************************************************************************************
*                               eBsp
*            Operation System Adapter Layer
*
*       (c) Copyright 2006-2010, All winners Co,Ld.
*             All Rights Reserved
*
* File Name   : OSAL_Lib_C.h
*
* Author    : javen
*
* Description   : C�⺯��
*
* History     :
*      <author>       <time>        <version >        <desc>
*       javen          2010-09-07          1.0          create this word
*   holi       2010-12-03      1.1      ������OSAL_io_remap
*************************************************************************************
*/

#include "OSAL.h"

extern int kdb_trap_printk;

/* ��ͨ�ڴ���� */
void * OSAL_malloc (__u32 Size)
{
  void * addr;
  
  addr = malloc (Size);
  if (addr)
  { memset (addr, 0, Size); }
  return addr;
}

void OSAL_free (void * pAddr)
{
  free (pAddr);
  
  return;
}

/* �����������ڴ���� */
void * OSAL_PhyAlloc (__u32 Size)
{
  void * addr;
  
  addr = malloc (Size);
  return addr;
}

void OSAL_PhyFree (void * pAddr, __u32 Size)
{
  free (pAddr);
  
  return;
}


/* �����ڴ�������ڴ�֮���ת�� */
unsigned int OSAL_VAtoPA (void * va)
{
  
  return (unsigned int) va;
}

void * OSAL_PAtoVA (unsigned int pa)
{
  return (void *) pa;
}





int OSAL_putchar (int value)
{
  return 0;
}
int OSAL_puts (const char * value)
{
  return 0;
}
int OSAL_getchar (void)
{
  return 0;
}
char * OSAL_gets (char * value)
{
  return NULL;
}

/* �ַ���ת������ */
long OSAL_strtol (const char * str, const char ** err, int base)
{
  return 0;
}

/* �з���ʮ��������ת�ַ���*/
void OSAL_int2str_dec (int input, char * str)
{
}

/* ʮ����������ת�ַ���*/
void OSAL_int2str_hex (int input, char * str, int hex_flag)
{
}

/* �޷���ʮ��������ת�ַ���*/
void OSAL_uint2str_dec (unsigned int input, char * str)
{
}



