#pragma once

//#include <syslib.h>/* ���� <ctype.h> */
#include <ctype.h> /* ���� <ctype.h> */

//////////////////////////////////////////////////////////////////////////
//
//�������ĺ�������ӵĺ���
//////////////////////////////////////////////////////////////////////////
/*��ʼ���֧����Ӣ�ı�����*/
/*��ΪLS->current��int����!*/


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
			save_and_next(ls); //������һ�������ַ�   
		}
		else
		{
			save_and_next(ls); //����Ӣ���ַ������»���   
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
		save_and_next(ls); //����Ӣ���ַ������»���   
	} while (isChineseCode(ls->current) || ls->current == '_' || isalnum(ls->current));
}
#endif  


//////////////////////////////////////////////////////////////////////////
//
//���������ı��������庯��
//
//////////////////////////////////////////////////////////////////////////
