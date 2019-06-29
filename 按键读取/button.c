#include <reg52.h>
#include <intrins.h>
#include <math.h>

typedef unsigned char byte;

/*******************************
名称：scanKey
描述：扫描独立键盘及矩阵键盘，若某键被按下则返回该键键值，
			若没有键被按下，则返回0，无法识别键值则返回1
返回值：unsigned char型
*******************************/
byte scanKey(void)
{
	byte key,value,x,y;
//---------独立键盘扫描开始---------
	P3 = 0xFF;
	if(P3 != 0xFF)
	{
		key = P3;
		while(P3 != 0xFF)//松手检测
			P3 = 0xFF;
		switch(key)//读取键值
		{
			case 	0xFE:	value = 2;	break;
			case 	0xFD:	value = 3;	break;
			case 	0xFB:	value = 4;	break;
			case 	0xF7:	value = 5;	break;
			default:		value = 1;
		}
		return value;
	}
//---------独立键盘扫描结束------------
	
//---------矩阵键盘扫描开始------------
	P3 = 0xF0;//行扫描
	if(P3 != 0xF0)
	{
		key = P3;
		key |= 0x0F;
		key = ~key;
		y = log(key)/log(2) -4;
		P3 = 0x0F;//列扫描
		if(P3 == 0x0F)
			return 0;
		key = P3;
		key |= 0xF0;
		key = ~key;
		x = log(key)/log(2);		
		value = x*4 + y +6;//键值计算
		while(P3 != 0x0F)//松手检测
			P3 = 0x0F;		
		return value;
	}
//--------矩阵键盘扫描结束-------------
	return 0;
}