#include<stdio.h>
int main(void)
{
	int i=9,j=5,k=14;
	int b[9]={2,3,4,5,6,8,10,10,12};
	int a[5]={3,3,5,7,8};
	int c[100];
	for(i=9,j=5,k=14;k>0||i>0||j>0;)
	{
		(a[i]>b[j])?(c[--k]=a[--i]):(c[--k]=b[--j]);
		printf("%4d%2d%2d\n",c[k],i,j);
	}
	//while(j<5||i<9)
	//{
	//	(a[i]<=b[j])?(c[k]=a[i++]):(c[k]=b[j++]);
	//	    printf("%4d%2d%2d\n",c[k],i,j);
	//	k++;
	//	}
	for(i=0;i<k;i++)
		printf("%4d",c[i]);
	printf("\n");
	printf("\n");
	return 0;
}