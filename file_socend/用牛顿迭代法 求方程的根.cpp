//��ţ�ٵ����� �󷽳� 2*x*x*x-4*x*x+3*x-6 �ĸ�
/* ţ�ٵ����� */
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Epsilon 1.0E-6 /*���ƽ�ľ���*/

int main(void)
{
	float x1, x0 = 1.5;
	x1 = x0 - (2 * x0*x0*x0 - 4 * x0*x0 + 3 * x0 - 6) / (6 * x0*x0 - 8 * x0 + 3);
	while (fabs(x1 - x0) >= Epsilon)
	{
		x0 = x1;
		x1 = x0 - (2 * x0*x0*x0 - 4 * x0*x0 + 3 * x0 - 6) / (6 * x0*x0 - 8 * x0 + 3);
	}
	printf("���̵ĸ�Ϊ%f\n", x1);
	system("pause");
	return 0;
}
#endif

#if 1
//���������⡣����
//�ö��ַ�������
/* ���ַ� */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Epsilon 1.0E-5 /*���ƽ�ľ���*/

int main()
{
	float x1=1.5, x2=1.6, x0, f1=1.5, f2, f0;
	x0 = (x1 + x2) / 2;
	f0 = 2 * x0*x0*x0 - 4 * x0*x0 + 3 * x0 - 6; /* ���е�ĺ���ֵ */
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
	printf("�ö��ַ���÷��̵ĸ���%f\n", x0);
	system("pause");
	return 0;
}

#endif
