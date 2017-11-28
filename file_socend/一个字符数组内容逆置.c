/*
有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student".
要求：
不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。
*/
#include<stdio.h>
#include<stdlib.h>
//输出函数
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
	//输出原字符串
	print(str,0,sz-1);
	printf("\n");
	//统计并计算出字符串中空格的位置
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			j++;
			//continue;
		}
		sum[j]++;
	}
	//打印最终字符串
	for (i = 0; i < j + 1; i++)
	{
		num += sum[j - i];
		left = sz -1- num;
		rigth = left+sum[j-i];
		print(str,left,rigth);
		printf(" ");
		//sz--;//减去空格对数组大小的影响
	}
	system("pause");
	return 0;
}