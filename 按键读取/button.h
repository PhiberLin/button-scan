/*******************************
名称：scanKey
描述：扫描独立键盘及矩阵键盘，若某键被按下则返回该键键值，
			若没有键被按下，则返回0，无法识别键值则返回1
返回值：unsigned char型
*******************************/
unsigned char scanKey(void);