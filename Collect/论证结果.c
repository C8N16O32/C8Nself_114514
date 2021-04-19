// 论证结果.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"

int main()
{
	int cn = 0, ct = 0, type = 0,n=0;
	double max[2] = { 0 }, min[2] = { 0 }, now = 0;
	char temp[32] = { '\0' };
	struct dssq {
		int count;
		char c[32];
		int cl;
	}dssq[400] = { {0,{'\0'},100} };
	for (cn = 0; cn < 400; cn++)dssq[cn].cl=100;
	FILE *fp = NULL; fp = fopen("input.txt", "r");
	/*while (!feof(fp)) {
		fscanf(fp, "%s\t%lf\t%d\n", temp, &now, &type);
		if (max[type] < now&&now < 10000) { max[type] = now; printf("new%dmax:%s\t%.2lf\n",type,temp,now); }
		if (min[type] > now&&now>-10000){min[type] = now; printf("new%dmin:%s\t%.2lf\n", type, temp, now);}
		if (cn % 1000000 == 0)printf("%s\t%lf\t%d\t\tmin/maxf:%.2lf/%.2lf i:%.0lf/%.0lf 第%d次\n", temp, now, type, min[0], max[0], min[1], max[1], cn + 1);
		cn++;
	};*/
	while (!feof(fp)) {
		memset(temp, 0, 32);
		fscanf(fp, "%s\t%lf\t%d\n", temp, &now, &type);
		if (type == 1) {
			if(now>=-0.5)n = (int)(now+0.1);
			else n= (int)(now - 0.1);
			dssq[n + 159].count++;
			if (strlen(temp) < dssq[n + 159].cl && strstr(temp,"\0")>8) {
				dssq[n + 159].cl = strlen(temp);
				memset(dssq[n + 159].c, 0, 32);
				strncpy(dssq[n + 159].c, temp, 32);
			}
		}
		if (cn % 1 == 0)printf("第%d次\n", cn + 1);
		cn++;
	}
	for (ct = 0; ct < 400; ct++)
		printf("%s\t%d\t%d\t%d\n",dssq[ct].c, dssq[ct].cl,ct-159,dssq[ct].count );
    return 0;
}

