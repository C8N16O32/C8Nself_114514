// ��֤����.cpp : �������̨Ӧ�ó������ڵ㡣
//
#define ��������� 5

#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int xz//����ѡ��k-j+1������ѡ����ѡ�ĵ�t���(ȷ����ѡ��)
(int j, int *f, int t) {
	int i = 0, t0 = 0;
	while (t0 < t) {
		i++; f++;
		if (*f == 0)t0++;
	}
	*f = 1;
	return i;
}
int t//����t�Ա���ѡ��
(int k, int j, int ci) {
	int i = 1, x = 1;
	for (i = 1; i <= k - j; i++)x *= i;
	x = ci / x + 1;
	while (x > k - j + 1)x -= k - j + 1;
	return x;
}
int jc//n�Ľ׳�
(int n) {
	int i = 1, x = 1;
	for (i = 1; i <= n; i++)x *= i;
	return x;
}
double cal//���������ֽ�����������
(double a, double b, int c) {
	double r;
	switch (c){
	case 0: {r = a + b; break; }
	case 1: {r = a - b; break; }
	case 2: {r = a * b; break; }
	case 3: {r = a / b; break; }
	case 4: {r = pow(a, b); break; }
	case 5: {r = a * 10 + b; break; }
	}
	return r;
}
int q//ȡx��l���Ƶĵ�nλ
(int x,int l,int n)
{
	int r=0,i=0,s=1;
	for (i = 1; i < n; i++)s *= l;
	r = fmod(x, s*l) / s;
	return r;
};
int pz//�ж��Ƿ�������
(double n) {
	if (fmod(n+0.1,1) > 0.1001||fmod(n-0.1, 1) < -0.1001)return 0;
	else return 1;
}

int main() {
	FILE *fp = NULL;
	fp = fopen("output.txt","w");
	int dssq_base[7] = {1919810,1,1,4,5,1,4 };
	struct c_base {
		int l[���������];
		char c[���������];
	}cb = {{0,0,1,1,2},{'+','-','*','/','^'} };
	struct dssq {
		double n;//ֵ
		int c;//�����
		int l;//�������ȼ�
	}dssq[7] = { {0} };
	struct k {
		int d[3][6];
		int c[4][6];
		int b[6][6];
		int a[13][6];
		int i[5];
	}k={ { { 0,0,0,0,0,0 },{ 0,1,1,1,1,0 },{ 0,0,1,1,1,1 } }
		,{ { 0,0,0,0,0,0 },{ 0,1,1,1,0,0 },{ 0,0,1,1,1,0 },{ 0,0,0,1,1,1 } }
		,{ { 0,0,0,0,0,0 },{ 0,1,1,0,1,1 },{ 0,1,1,0,0,0 },{ 0,0,1,1,0,0 },{ 0,0,0,1,1,0 },{ 0,0,0,0,1,1 } }
		,{ { 0,0,0,0,0,0 },{ 0,1,0,0,0,0 },{ 0,0,1,0,0,0 },{ 0,0,0,1,0,0 },{ 0,0,0,0,1,0 },{ 0,0,0,0,0,1 },{ 0,1,0,0,0,1 },{ 0,0,1,0,0,1 },{ 0,0,0,1,0,1 },{ 0,1,0,1,0,0 },{ 0,1,0,0,1,0 },{ 0,0,1,0,1,0 },{ 0,1,0,1,0,1 } }
		,{0,0,0,0} };
	struct pick {
		int n[7],f[7];
		int i , j , k , ci;
		int *pn ;
		int *pf ;
	}pick = { {0},{0},0,0,0,0,&pick.n[1],&pick.f[0] };
	//ѭ������
	int i = 0, j = 0, level = 0, f = 0, count = 0;
	//ѡ������ѭ��
	//pick.k = 6;
	//for (pick.ci = 0; pick.ci < jc(pick.k); pick.ci++) {//��ci����� �ܹ�6!��
	//	for (pick.i = 1; pick.i <= 6; pick.i++)//ˢ������
	//	{
	//		pick.n[pick.i] = 0; pick.f[pick.i] = 0;
	//	}
	//	for (pick.j = 1; pick.j <= pick.k; pick.j++)//���ڴ������е�j����λ
	//		pick.n[pick.j] = xz(pick.j, pick.pf, t(pick.k, pick.j, pick.ci));
	//	dssq_base[0] = 0;
	//	dssq_base[pick.n[1]] = 1; dssq_base[pick.n[2]] = 1;
	//	dssq_base[pick.n[3]] = 4; dssq_base[pick.n[4]] = 5;
	//	dssq_base[pick.n[5]] = 1; dssq_base[pick.n[6]] = 4;

		//�Ĳ����ŵ�ѭ��
		for (k.i[1] = 0; k.i[1] < 13; k.i[1]++) {
			for (k.i[2] = 0; k.i[2] < 6; k.i[2]++) {
				if (k.i[2] != 0) {
					f = 0;
					for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
						dssq[k.i[0]].l = (
							k.a[k.i[1]][k.i[0] - 1]);
					};
					for (k.i[0] = 0; k.i[0] <= 5; k.i[0]++) {
						if (k.b[k.i[2]][k.i[0]] == 0 && k.b[k.i[2]][k.i[0] + 1] == 1) {
							i = k.i[0];
							while (!(k.b[k.i[2]][i] == 1 && k.b[k.i[2]][i + 1] == 0) && i <= 5)i++;
							if (dssq[k.i[0] + 1].l - dssq[k.i[0] + 2].l>0 || dssq[i + 1].l - dssq[i + 2].l<0)f++;
							else if (dssq[k.i[0] + 1].l != dssq[i + 1].l)f++;
							else for (j = k.i[0]; j < i; j++)if (dssq[k.i[0] + 1].l>dssq[j + 1].l)f++;
						}
					};
					if (f != 0)continue;
				}
				for (k.i[3] = 0; k.i[3] < 4; k.i[3]++) {
					if (k.i[3] != 0) {
						f = 0;
						for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
							dssq[k.i[0]].l = (
								k.a[k.i[1]][k.i[0] - 1]
								+ k.b[k.i[2]][k.i[0] - 1]);
						};
						for (k.i[0] = 0; k.i[0] <= 5; k.i[0]++) {
							if (k.c[k.i[3]][k.i[0]] == 0 && k.c[k.i[3]][k.i[0] + 1] == 1) {
								i = k.i[0];
								while (!(k.c[k.i[3]][i] == 1 && k.c[k.i[3]][i + 1] == 0) && i <= 5)i++;
								if (dssq[k.i[0] + 1].l - dssq[k.i[0] + 2].l>0 || dssq[i + 1].l - dssq[i + 2].l<0)f++;
								else if (dssq[k.i[0] + 1].l != dssq[i + 1].l)f++;
								else for (j = k.i[0]; j < i; j++)if (dssq[k.i[0] + 1].l>dssq[j + 1].l)f++;
							}
						};
						if (f != 0)continue;
					}
					for (k.i[4] = 0; k.i[4] < 3; k.i[4]++) {
						if (k.i[4] != 0) {
							f = 0;
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
								dssq[k.i[0]].l = (
									k.a[k.i[1]][k.i[0] - 1]
									+ k.b[k.i[2]][k.i[0] - 1]
									+ k.c[k.i[3]][k.i[0] - 1]);
							};
							for (k.i[0] = 0; k.i[0] <= 5; k.i[0]++) {
								if (k.d[k.i[4]][k.i[0]] == 0 && k.d[k.i[4]][k.i[0] + 1] == 1) {
									i = k.i[0];
									while (!(k.d[k.i[4]][i] == 1 && k.d[k.i[4]][i + 1] == 0) && i <= 5)i++;
									if (dssq[k.i[0] + 1].l - dssq[k.i[0] + 2].l>0 || dssq[i + 1].l - dssq[i + 2].l<0)f++;
									else if (dssq[k.i[0] + 1].l != dssq[i + 1].l)f++;
									else for (j = k.i[0]; j < i; j++)if (dssq[k.i[0] + 1].l>dssq[j + 1].l)f++;
								}
							};
							if (f != 0)continue;
						}
						//����^5��������ŵ�ѭ��
						for (i = 0; i < pow(���������, 5); i++) {
							//��ʼ�����֣�������ţ����������������ȼ�
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
								dssq[k.i[0]].n = dssq_base[k.i[0]];
								dssq[k.i[0]].c = q(i, ���������, k.i[0] - 1);
								dssq[k.i[0]].l = cb.l[dssq[k.i[0]].c];
							};
							//��������Ÿ����ȵĲ��֣�ֱ��ƴ��
							/*for (k.i[0] = 2; k.i[0] <= 6; k.i[0]++)
								if (dssq[k.i[0]].l == -2) {
									dssq_base[0] = k.i[0] - 1;
									while (dssq_base[0] > 1 && dssq[dssq_base[0]].c<0)dssq_base[0]--;
									dssq[dssq_base[0]].n = cal(dssq[dssq_base[0]].n, dssq[k.i[0]].n, dssq[k.i[0]].c);
									dssq[k.i[0]].c = -1;
								};*/
							//�������ŵ����ȼ�
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
								dssq[k.i[0]].l = ���������*(k.a[k.i[1]][k.i[0] - 1] + k.b[k.i[2]][k.i[0] - 1]
										+ k.c[k.i[3]][k.i[0] - 1] + k.d[k.i[4]][k.i[0] - 1]);
							};
							//�����̨��ӡ��ʽ���������������ţ����֣�������
							/*if (count % 1000 == 0) {
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
							if (k.i[0] > 1)printf("%c", cb.c[dssq[k.i[0]].c]);
							if (k.i[0] < 6)if (dssq[k.i[0] + 1].l / 4 > dssq[k.i[0]].l / 4)
							for (j = 0; j < dssq[k.i[0] + 1].l / 4 - dssq[k.i[0]].l / 4; j++)
							printf("(");
							printf("%d", dssq_base[k.i[0]]);
							if (k.i[0] > 1 && k.i[0] < 6) if (dssq[k.i[0] + 1].l / 4 < dssq[k.i[0]].l / 4)
							for (j = 0; j < dssq[k.i[0]].l / 4 - dssq[k.i[0] + 1].l / 4; j++)
							printf(")");
							if (k.i[0] == 6) if (0 < dssq[k.i[0]].l / 4)
							for (j = 0; j < dssq[k.i[0]].l / 4; j++)
							printf(")");
							}
							printf("\t");

							}*/
							//���ĵ���ӡ��ʽ
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
								if (k.i[0] > 1&& dssq[k.i[0]].c!=5)fprintf(fp, "%c", cb.c[dssq[k.i[0]].c]);
								if (k.i[0] < 6)if (dssq[k.i[0] + 1].l / ��������� > dssq[k.i[0]].l / ���������)
									for (j = 0; j < dssq[k.i[0] + 1].l / ��������� - dssq[k.i[0]].l / ���������; j++)
										fprintf(fp, "(");
								fprintf(fp, "%d", dssq_base[k.i[0]]);
								if (k.i[0] > 1 && k.i[0] < 6) if (dssq[k.i[0] + 1].l / ��������� < dssq[k.i[0]].l / ���������)
									for (j = 0; j < dssq[k.i[0]].l / ��������� - dssq[k.i[0] + 1].l / ���������; j++)
										fprintf(fp, ")");
								if (k.i[0] == 6) if (0 < dssq[k.i[0]].l / ���������)
									for (j = 0; j < dssq[k.i[0]].l / ���������; j++)
										fprintf(fp, ")");
							}
							fprintf(fp, "\t");
							//����ߵȼ���ʼ���¼���
							for (level = ��������� * 5; level >= 0; level--)
								for (k.i[0] = 2; k.i[0] <= 6; k.i[0]++)
									if (dssq[k.i[0]].l == level&&dssq[k.i[0]].c!=-1) {
										dssq_base[0] = k.i[0] - 1;
										while (dssq_base[0] > 1 && dssq[dssq_base[0]].c<0)dssq_base[0]--;
										dssq[dssq_base[0]].n = cal(dssq[dssq_base[0]].n, dssq[k.i[0]].n, dssq[k.i[0]].c);
										dssq[k.i[0]].c = -1;
									};
							//�����̨��ӡ������
							if (count % 1000 == 0) {
							if(pz(dssq[1].n))printf("\t��%d�� ��֤%.0lf\n", count, dssq[1].n);
							else printf("\t��%d�� %.2lf\n", count, dssq[1].n);
							}
							//���ĵ���ӡ������
							if (pz(dssq[1].n))fprintf(fp, "%.0lf\t1\n", dssq[1].n);
							else fprintf(fp, "%.3lf\t0\n", dssq[1].n);
							count++;
						}
					}
				}
			}
		};
	//	//�����̨��ӡ����
	//	if (pick.ci%jc(pick.k - 3) == 0) {
	//		printf("����%d���� ��%d/%d�֣��ܵ�%d�Σ���", pick.k, pick.ci + 1, jc(pick.k),count);
	//		for (pick.j = 1; pick.j <= pick.k; pick.j++) {
	//			printf(" %d", dssq_base[pick.j]);
	//		}
	//		printf("\n");
	//	}
	//}
	fclose(fp);
	return 0;
}

