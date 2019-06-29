#include <reg52.h>
#include <intrins.h>
#include <math.h>

typedef unsigned char byte;

/*******************************
���ƣ�scanKey
������ɨ��������̼�������̣���ĳ���������򷵻ظü���ֵ��
			��û�м������£��򷵻�0���޷�ʶ���ֵ�򷵻�1
����ֵ��unsigned char��
*******************************/
byte scanKey(void)
{
	byte key,value,x,y;
//---------��������ɨ�迪ʼ---------
	P3 = 0xFF;
	if(P3 != 0xFF)
	{
		key = P3;
		while(P3 != 0xFF)//���ּ��
			P3 = 0xFF;
		switch(key)//��ȡ��ֵ
		{
			case 	0xFE:	value = 2;	break;
			case 	0xFD:	value = 3;	break;
			case 	0xFB:	value = 4;	break;
			case 	0xF7:	value = 5;	break;
			default:		value = 1;
		}
		return value;
	}
//---------��������ɨ�����------------
	
//---------�������ɨ�迪ʼ------------
	P3 = 0xF0;//��ɨ��
	if(P3 != 0xF0)
	{
		key = P3;
		key |= 0x0F;
		key = ~key;
		y = log(key)/log(2) -4;
		P3 = 0x0F;//��ɨ��
		if(P3 == 0x0F)
			return 0;
		key = P3;
		key |= 0xF0;
		key = ~key;
		x = log(key)/log(2);		
		value = x*4 + y +6;//��ֵ����
		while(P3 != 0x0F)//���ּ��
			P3 = 0x0F;		
		return value;
	}
//--------�������ɨ�����-------------
	return 0;
}