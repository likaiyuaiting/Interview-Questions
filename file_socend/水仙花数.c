//���0��999֮������С�ˮ�ɻ��������������ˮ�ɻ�������ָһ����λ����
//���λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3

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
			printf("%d��ˮ�ɻ���\n",num);
	}
	printf("%d\t",sum);
	system("pause");
	return 0;
}