#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x, y, z, i;
	printf("请输入所要求公因子的二个数：");
	scanf("%d%d", &x, &y);
	z =(x>y?y:x);
	for (i = z; i > 0; i--)
	if ((x%i == 0) && (y%i == 0))
	{
		printf("这两个数最大公因子为：%d", i);
		break;
	}
	system("pause");
	return 0;
}