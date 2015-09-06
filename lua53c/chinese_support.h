#pragma once

//#include <syslib.h>/* 包含 <ctype.h> */
#include <ctype.h> /* 包含 <ctype.h> */

//////////////////////////////////////////////////////////////////////////
//
//这是中文函数名添加的函数
//////////////////////////////////////////////////////////////////////////
/*开始添加支持中英文变量名*/
/*因为LS->current是int类型!*/


#define USE_CHINESE_NAME   
#ifdef USE_CHINESE_NAME   
#define isChineseCode(charint)   (charint > 0x80)   
#define readxxname(ls) readChinesename(ls)   
void readChinesename(LexState *ls)
{
	do
	{
		if (isChineseCode(ls->current))
		{
			save_and_next(ls);
			save_and_next(ls); //处理了一个中文字符   
		}
		else
		{
			save_and_next(ls); //处理英文字符或者下划线   
		}
	} while (isChineseCode(ls->current) || ls->current == '_' || isalnum(ls->current));
}
#else   
#define isChineseCode(charint) 0   
#define readxxname(ls) readname(ls)   
void readname(LexState *ls)
{
	do
	{
		save_and_next(ls); //处理英文字符或者下划线   
	} while (isChineseCode(ls->current) || ls->current == '_' || isalnum(ls->current));
}
#endif  


//////////////////////////////////////////////////////////////////////////
//
//以上是中文变量名定义函数
//
//////////////////////////////////////////////////////////////////////////
