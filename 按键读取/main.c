#include <display.h>
#include <button.h>

typedef unsigned char byte;

byte num = 0;

void main()
{
	while(1)
	{
		byte key;
		key = scanKey();
		if(key != 0)
			num = key;
		displayInt(num);
	}
}

