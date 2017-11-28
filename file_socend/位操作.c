/*
函数功能：实现对一个8bit数据（unsigned char 类型）的
		  指定为（例如第N位）置0或置1操作，并保持其他为不变
哈数原型：void bit_set(unsigned char *p_data,unsigned char position,int flag)
函数参数说明：p_data是指定的源数据，position是指定位（取值范围1~8）；flog表示是置0还是置1操作

*/
#include<stdio.h>
#include<stdlib.h>

void bit_set(unsigned char *p_data, unsigned char position, int flag)
{
	if (flag == 1) 
		(*p_data) |= (1 << (position-1));
	else   
		(*p_data) &= (~(1 << (position - 1)));
}
void test()
{
	unsigned char a = 10;
	bit_set(a,3,1);
	printf("%d\n",a);
}
int main(void)
{
	test();
	system("pause");
	return 0;
}