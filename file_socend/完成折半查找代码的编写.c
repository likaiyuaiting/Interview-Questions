//完成折半查找代码的编写
#include<stdio.h>
#include<stdlib.h>

int second_search(int a[], int key, int leaf, int right)
{
	while (leaf <= right)
	{
		int m = (leaf + right) / 2;
		if (a[m] == key)
			return m;
		else if(a[m] < key)
			leaf = m;
		else right = m;
	}
	return -1;
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 0, leaf = 0,right=sizeof(a)/sizeof(a[0])-2,num;
	printf("请输入查找数:");
	scanf("%d", &key);
	num=second_search(a, key, leaf, right);
	if (num == -1)
		printf("\n该数组中没有该数\n");
	else printf("\n该数在数组的第%d位处\n",num);
	system("pause");
	return 0;
}