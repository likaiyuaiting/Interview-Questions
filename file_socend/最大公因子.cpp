#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x, y, z, i;
	printf("��������Ҫ�����ӵĶ�������");
	scanf("%d%d", &x, &y);
	z =(x>y?y:x);
	for (i = z; i > 0; i--)
	if ((x%i == 0) && (y%i == 0))
	{
		printf("���������������Ϊ��%d", i);
		break;
	}
	system("pause");
	return 0;
}