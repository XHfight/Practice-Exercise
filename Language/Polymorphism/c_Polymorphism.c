/*************************************************************************
	> File Name: c_Polymorphism.c
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/ 6 11:06:09 2017
 ************************************************************************/

#include<stdio.h>

typedef void (*PFUN) ();

void fun_b()
{
	 printf("fun_b");
}

void fun_d()
{
	printf("fun_d");
}

struct Base
{
	PFUN* f;
	int _b;
};

struct Derive
{
	struct Base _base;
	int _d;
};

void fun(struct Base *pb)
{
	pb->f();
}

int main()
{
	struct Base b;
	b.f = fun_b;
	fun(&b);
}
