//����۰���Ҵ���ı�д
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
	printf("�����������:");
	scanf("%d", &key);
	num=second_search(a, key, leaf, right);
	if (num == -1)
		printf("\n��������û�и���\n");
	else printf("\n����������ĵ�%dλ��\n",num);
	system("pause");
	return 0;
}