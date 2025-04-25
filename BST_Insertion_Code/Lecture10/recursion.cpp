#include <iostream>
using namespace std;


void d2B(int n)
{
	if (n > 0)
	{
		d2B(n / 2);
		cout << n % 2;
	}
}

long long fib(int n)
{
	if (n > 2)
		return fib(n - 1) + fib(n - 2);

	else if (n == 2)
		return 1;

	else if (n == 1)
		return 0;
}

int main()
{
	d2B(13);
	cout << endl;
	return 0;
}




