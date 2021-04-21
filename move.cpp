#include <iostream>
using namespace std;

struct S1
{
    int i;
    char j;
    int a;
    double b;
};

struct wk
{
   int a;
   int d;     //不能使用
   int b;
   int c;
};

int main(int argc, char const *argv[])
{
	cout << sizeof(S1);
	cout << sizeof(wk);

	return 0;
}