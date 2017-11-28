/*
�������ܣ�ʵ�ֶ�һ��8bit���ݣ�unsigned char ���ͣ���
		  ָ��Ϊ�������Nλ����0����1����������������Ϊ����
����ԭ�ͣ�void bit_set(unsigned char *p_data,unsigned char position,int flag)
��������˵����p_data��ָ����Դ���ݣ�position��ָ��λ��ȡֵ��Χ1~8����flog��ʾ����0������1����

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