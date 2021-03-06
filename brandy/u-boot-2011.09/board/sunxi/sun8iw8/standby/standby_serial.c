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
#include "standby_i.h"
#include <stdarg.h>
/*
************************************************************************************************************
*
*                                             function
*
*    函数名称：
*
*    参数列表：
*
*    返回值  ：
*
*    说明    ：
*
*
************************************************************************************************************
*/
void standby_serial_putc(char c)
{
	__u32 reg_val;

	do
	{
		reg_val = *(volatile unsigned int *)(0x01c2807C);
	}	while (!(reg_val & 0x02));

	*(volatile unsigned int *)(0x01c28000) = c;
}
#if 0
/*
************************************************************************************************************
*
*                                             function
*
*    函数名称：
*
*    参数列表：
*
*    返回值  ：
*
*    说明    ：
*
*
************************************************************************************************************
*/
void standby_int_to_string_dec( int input , char * str)
{
	char stack[16];
	int sign_flag = 0 ;
	int i ;
	int j ;

	if( input == 0 )
	{
		str[0] = '0';
		str[1] = '\0';                  
		return ;
	}

	if( input < 0 )                     
	{
		sign_flag = -1 ;
		input = -input ;
	}

	for( i = 0; input > 0; ++i )
	{
		stack[i] = input%10 + '0';     
		input /= 10;
	}                                  

    j = 0;
	if( sign_flag == -1 )
		str[j++] = '-';		           
	for( --i  ; i >= 0; --i, ++j )
		str[j] = stack[i];
	str[j] = '\0';				       


	return;
}
/*
************************************************************************************************************
*
*                                             function
*
*    函数名称：
*
*    参数列表：
*
*    返回值  ：
*
*    说明    ：
*
*
************************************************************************************************************
*/
void standby_int_to_string_hex( int input, char * str )
{
	int i;
	static char base[] = "0123456789abcdef";

	for( i = 9; i > 1; --i )
	{
		str[i] = base[input&0x0f];
		input >>= 4;
	}

	str[0] = '0';
	str[1] = 'x';                        
	str[10] = '\0';                      

	return;
}
/*
************************************************************************************************************
*
*                                             function
*
*    函数名称：
*
*    参数列表：
*
*    返回值  ：
*
*    说明    ：
*
*
************************************************************************************************************
*/
static void standby_serial_puts( const char * str )
{
	while( *str != '\0' )
	{
		if( *str == '\n' )                     
			standby_serial_putc( '\r' );

		standby_serial_putc( *str++ );
	}
}
/*
************************************************************************************************************
*
*                                             function
*
*    函数名称：
*
*    参数列表：
*
*    返回值  ：
*
*    说明    ：
*
*
************************************************************************************************************
*/
void standby_printf( const char * str, ...)
{
	char string[16];
	char *p;
	va_list argp;

	va_start( argp, str );

	while( *str )
	{
		if( *str == '%' )
		{
			++str;
			p = string;
			switch( *str )
			{
				case 'd': standby_int_to_string_dec( va_arg( argp,  __s32 ), string );
                          standby_serial_puts( p );
						  ++str;
						  break;
				case 'x':
				case 'X': standby_int_to_string_hex( va_arg( argp,  __s32 ), string );
						  standby_serial_puts( p );
                          ++str;
						  break;
				case 'c': standby_serial_putc( va_arg( argp,  __s32 ) );
						  ++str;
						  break;
				case 's': standby_serial_puts( va_arg( argp, char * ) );
						  ++str;
						  break;
				default : standby_serial_putc( '%' );      
						  standby_serial_putc( *str );     
						  ++str;                                        
			}
		}
		else
		{
			if( *str == '\n' )                     
				standby_serial_putc( '\r' );

			standby_serial_putc( *str++ );
		}
	}

	va_end( argp );

	return;
}

#endif

