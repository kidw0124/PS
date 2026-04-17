// obb.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//


#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double s(double* v) {
	return sqrt(v[0]*v[0] + v[1]*v[1]);
}
double dp(double* a, double* b) {
	return a[0] * b[0] + a[1] * b[1];
}
int obb(double a1x, double a1y, double a2x, double a2y, double a3x, double a3y, double a4x, double a4y, double b1x, double b1y, double b2x, double b2y, double b3x, double b3y, double b4x, double b4y) {
	
	double h1[2] = { (a2x - a1x),(a2y - a1y) };
	double w1[2] = { (a3x - a2x),(a3y - a2y) };
	double h2[2] = { (b2x - b1x),(b2y - b1y) };
	double w2[2] = { (b3x - b2x),(b3y - b2y) };
	double di[2] = { (b1x + b3x - a1x - a3x),(b1y + b3y - a1y - a3y) };
	double u[4][2] = { {h1[0]/s(h1),h1[1]/s(h1)},
	{w1[0]/s(w1),w1[1]/s(w1)},
	{h2[0]/s(h2),h2[1]/s(h2)},
	{w2[0]/s(w2),w2[1]/s(w2)} };
	double t=0;
	for (int ii = 0; ii < 4; ii++) {
		t += (fabs(dp(h1, u[ii]))+fabs(dp(w1,u[ii]))
			+fabs(dp(h2,u[ii]))+fabs(dp(w2,u[ii]))
			-fabs(dp(di,u[ii]))>0.00000001);
	}

	if(t==4) return 1;
	else return 0;

}

int main()
{
	int t = 0;
	//double v[2] = { 3,4 };
	//double w[2] = { 4,5 };
	//printf("%.3f %.3f", s(v),dp(v,w));
	int a[8]; int b[8];
	for (int i=0; i < 8; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%d", b + i);
	}

	t = obb(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]); //<-여기다 넣고

	//sprintf로 output에출력   가능? ?

	printf("%d", t);

	return 0;
}

