// 论证数字.cpp : 定义控制台应用程序的入口点。
//
#define 运算符总数 5

#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int xz//在能选的k-j+1个数里选择能选的第t大的(确保能选到)
(int j, int *f, int t) {
	int i = 0, t0 = 0;
	while (t0 < t) {
		i++; f++;
		if (*f == 0)t0++;
	}
	*f = 1;
	return i;
}
int t//计算t以便于选择
(int k, int j, int ci) {
	int i = 1, x = 1;
	for (i = 1; i <= k - j; i++)x *= i;
	x = ci / x + 1;
	while (x > k - j + 1)x -= k - j + 1;
	return x;
}
int jc//n的阶乘
(int n) {
	int i = 1, x = 1;
	for (i = 1; i <= n; i++)x *= i;
	return x;
}
double cal//对两个数字进行四则运算
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
int q//取x的l进制的第n位
(int x,int l,int n)
{
	int r=0,i=0,s=1;
	for (i = 1; i < n; i++)s *= l;
	r = fmod(x, s*l) / s;
	return r;
};
int pz//判断是否是整数
(double n) {
	if (fmod(n+0.1,1) > 0.1001||fmod(n-0.1, 1) < -0.1001)return 0;
	else return 1;
}

int main() {
	FILE *fp = NULL;
	fp = fopen("output.txt","w");
	int dssq_base[7] = {1919810,1,1,4,5,1,4 };
	struct c_base {
		int l[运算符总数];
		char c[运算符总数];
	}cb = {{0,0,1,1,2},{'+','-','*','/','^'} };
	struct dssq {
		double n;//值
		int c;//运算符
		int l;//运算优先级
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
	//循环变量
	int i = 0, j = 0, level = 0, f = 0, count = 0;
	//选择排序循环
	//pick.k = 6;
	//for (pick.ci = 0; pick.ci < jc(pick.k); pick.ci++) {//第ci次穷举 总共6!次
	//	for (pick.i = 1; pick.i <= 6; pick.i++)//刷新数列
	//	{
	//		pick.n[pick.i] = 0; pick.f[pick.i] = 0;
	//	}
	//	for (pick.j = 1; pick.j <= pick.k; pick.j++)//正在处理数列第j个空位
	//		pick.n[pick.j] = xz(pick.j, pick.pf, t(pick.k, pick.j, pick.ci));
	//	dssq_base[0] = 0;
	//	dssq_base[pick.n[1]] = 1; dssq_base[pick.n[2]] = 1;
	//	dssq_base[pick.n[3]] = 4; dssq_base[pick.n[4]] = 5;
	//	dssq_base[pick.n[5]] = 1; dssq_base[pick.n[6]] = 4;

		//四层括号的循环
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
						//总数^5种运算符号的循环
						for (i = 0; i < pow(运算符总数, 5); i++) {
							//初始化数字，运算符号，计算非括号下运算等级
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
								dssq[k.i[0]].n = dssq_base[k.i[0]];
								dssq[k.i[0]].c = q(i, 运算符总数, k.i[0] - 1);
								dssq[k.i[0]].l = cb.l[dssq[k.i[0]].c];
							};
							//计算比括号更优先的部分：直接拼合
							/*for (k.i[0] = 2; k.i[0] <= 6; k.i[0]++)
								if (dssq[k.i[0]].l == -2) {
									dssq_base[0] = k.i[0] - 1;
									while (dssq_base[0] > 1 && dssq[dssq_base[0]].c<0)dssq_base[0]--;
									dssq[dssq_base[0]].n = cal(dssq[dssq_base[0]].n, dssq[k.i[0]].n, dssq[k.i[0]].c);
									dssq[k.i[0]].c = -1;
								};*/
							//增加括号的优先级
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
								dssq[k.i[0]].l = 运算符总数*(k.a[k.i[1]][k.i[0] - 1] + k.b[k.i[2]][k.i[0] - 1]
										+ k.c[k.i[3]][k.i[0] - 1] + k.d[k.i[4]][k.i[0] - 1]);
							};
							//向控制台打印算式：操作符，左括号，数字，右括号
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
							//向文档打印算式
							for (k.i[0] = 1; k.i[0] <= 6; k.i[0]++) {
								if (k.i[0] > 1&& dssq[k.i[0]].c!=5)fprintf(fp, "%c", cb.c[dssq[k.i[0]].c]);
								if (k.i[0] < 6)if (dssq[k.i[0] + 1].l / 运算符总数 > dssq[k.i[0]].l / 运算符总数)
									for (j = 0; j < dssq[k.i[0] + 1].l / 运算符总数 - dssq[k.i[0]].l / 运算符总数; j++)
										fprintf(fp, "(");
								fprintf(fp, "%d", dssq_base[k.i[0]]);
								if (k.i[0] > 1 && k.i[0] < 6) if (dssq[k.i[0] + 1].l / 运算符总数 < dssq[k.i[0]].l / 运算符总数)
									for (j = 0; j < dssq[k.i[0]].l / 运算符总数 - dssq[k.i[0] + 1].l / 运算符总数; j++)
										fprintf(fp, ")");
								if (k.i[0] == 6) if (0 < dssq[k.i[0]].l / 运算符总数)
									for (j = 0; j < dssq[k.i[0]].l / 运算符总数; j++)
										fprintf(fp, ")");
							}
							fprintf(fp, "\t");
							//从最高等级开始往下计算
							for (level = 运算符总数 * 5; level >= 0; level--)
								for (k.i[0] = 2; k.i[0] <= 6; k.i[0]++)
									if (dssq[k.i[0]].l == level&&dssq[k.i[0]].c!=-1) {
										dssq_base[0] = k.i[0] - 1;
										while (dssq_base[0] > 1 && dssq[dssq_base[0]].c<0)dssq_base[0]--;
										dssq[dssq_base[0]].n = cal(dssq[dssq_base[0]].n, dssq[k.i[0]].n, dssq[k.i[0]].c);
										dssq[k.i[0]].c = -1;
									};
							//向控制台打印计算结果
							if (count % 1000 == 0) {
							if(pz(dssq[1].n))printf("\t第%d次 论证%.0lf\n", count, dssq[1].n);
							else printf("\t第%d次 %.2lf\n", count, dssq[1].n);
							}
							//向文档打印计算结果
							if (pz(dssq[1].n))fprintf(fp, "%.0lf\t1\n", dssq[1].n);
							else fprintf(fp, "%.3lf\t0\n", dssq[1].n);
							count++;
						}
					}
				}
			}
		};
	//	//向控制台打印进度
	//	if (pick.ci%jc(pick.k - 3) == 0) {
	//		printf("排列%d个数 第%d/%d轮（总第%d次）：", pick.k, pick.ci + 1, jc(pick.k),count);
	//		for (pick.j = 1; pick.j <= pick.k; pick.j++) {
	//			printf(" %d", dssq_base[pick.j]);
	//		}
	//		printf("\n");
	//	}
	//}
	fclose(fp);
	return 0;
}

