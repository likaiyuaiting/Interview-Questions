#include<stdio.h>
#include<stdlib.h>
/*
sum=N!+(N-1)!.......+2!+1!
*/
int fac(int n)
{
	int i, sum = 0,num=1;

	for (i = 1; i <= n; i++)
	{ 
		num = i*num;
		sum +=num ;
	}
	return sum;
}
int main(void)
{
	printf("%d\n",fac(3));
	system("pause");
	return 0;
}