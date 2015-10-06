#include <stdio.h>
#include <iostream>
using namespace std;
void test(char);
void test(int);
int main()
{
	test('a');
	test(4);
}

void test(char c)
{
	printf("%c\n",c);
}

void test(int a)
{
	printf("%d\n",a);
}
