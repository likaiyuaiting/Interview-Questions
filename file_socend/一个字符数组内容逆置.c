/*
��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student".
Ҫ��
����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
*/
#include<stdio.h>
#include<stdlib.h>
//�������
void print(char str[], int left, int rigth)
{
	while (left < rigth)
	{
		printf("%c",str[left++]);
	}
}
int main(void)
{
	char str[] = "student a am i";
	int sum[5] = { 0 }, i = 0, j = 0, left, rigth,num=0;
	int sz=sizeof(str)/sizeof(char);
	//���ԭ�ַ���
	print(str,0,sz-1);
	printf("\n");
	//ͳ�Ʋ�������ַ����пո��λ��
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			j++;
			//continue;
		}
		sum[j]++;
	}
	//��ӡ�����ַ���
	for (i = 0; i < j + 1; i++)
	{
		num += sum[j - i];
		left = sz -1- num;
		rigth = left+sum[j-i];
		print(str,left,rigth);
		printf(" ");
		//sz--;//��ȥ�ո�������С��Ӱ��
	}
	system("pause");
	return 0;
}