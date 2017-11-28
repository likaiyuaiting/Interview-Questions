//用牛顿迭代法 求方程 2*x*x*x-4*x*x+3*x-6 的根
/* 牛顿迭代法 */
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Epsilon 1.0E-6 /*控制解的精度*/

int main(void)
{
	float x1, x0 = 1.5;
	x1 = x0 - (2 * x0*x0*x0 - 4 * x0*x0 + 3 * x0 - 6) / (6 * x0*x0 - 8 * x0 + 3);
	while (fabs(x1 - x0) >= Epsilon)
	{
		x0 = x1;
		x1 = x0 - (2 * x0*x0*x0 - 4 * x0*x0 + 3 * x0 - 6) / (6 * x0*x0 - 8 * x0 + 3);
	}
	printf("方程的根为%f\n", x1);
	system("pause");
	return 0;
}
#endif

#if 1
//代码有问题。。。
//用二分法求上题
/* 二分法 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Epsilon 1.0E-5 /*控制解的精度*/

int main()
{
	float x1=1.5, x2=1.6, x0, f1=1.5, f2, f0;
	x0 = (x1 + x2) / 2;
	f0 = 2 * x0*x0*x0 - 4 * x0*x0 + 3 * x0 - 6; /* 求中点的函数值 */
	while (fabs(f0) >= Epsilon)
	{
		if (f0*f1<0)
		{
			x2 = x0;
			f2 = 2 * x2*x2*x2 - 4 * x2*x2 + 3 * x2 - 6;
		}
		if (f0*f2<0)
		{
			x1 = x0;
			f1 = 2 * x1*x1*x1 - 4 * x1*x1 + 3 * x1 - 6;
		}
		x0 = (x1 + x2) / 2;
		f0 = 2 * x0*x0*x0 - 4 * x0*x0 + 3 * x0 - 6;
	}
	printf("用二分法求得方程的根：%f\n", x0);
	system("pause");
	return 0;
}

#endif
