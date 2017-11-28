//求出0～999之间的所有“水仙花数”并输出。“水仙花数”是指一个三位数，
//其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int sum = 0, num;
	for (int i = 100; i < 1000; i++)
	{
		sum = 0;
		num = i;
		while (i)
		{
			int j = i % 10;
			sum += j*j*j;
			//sum +=  (i%10)*(i%10)*(i%10);
			i /= 10;
		}
		if (num == sum)
			printf("%d是水仙花数\n",num);
	}
	printf("%d\t",sum);
	system("pause");
	return 0;
}