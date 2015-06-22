// Workshop 3 - Callback Functions

#include <iostream>
using namespace std;

bool isEven(void* x, void* z);
bool isEven(void* x, void* z)
{
	int* even = (int*)x;
	int* sum = (int*)z;
	int total;
	if ((*even) % 2 == 0)
	{
		total = (*sum) + (*even);
		*(int*)z = total;
		return true;
	}

		return false;
}
bool isPrime(void* x, void* z);
bool isPrime(void* x, void* z)
{
	int* prime = (int*)x;
	int* sum = (int*)z;
	int total;
	bool flag = true;
	for (int i = 2; i < 9; i++)
	{
		if (*prime != i && *prime % i == 0)
		{
			flag = false;
			break;
		}
	}
	if (flag && *prime != 1)
	{
		total = (*sum) + (*prime);
		*(int*)z = total;
		return true;
	}
	return false;
}

int sum(void* x, int n, int s,
	bool(*)(void*, void*), void*);

int sum(void* x, int n, int s, bool(*f)(void*, void*), void*);

void display(const char* c, int* x, int f, int t, int n) {
	cout << f << ' ' << c << " found in {";
	for (int i = 0; i < n - 1; i++)
		cout << x[i] << ',';
	cout << x[n - 1] << "} sum is " << t << endl;
}

int main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int e = 0, p = 0, n;
	//e & p sum value , n is total number of even or prime
	n = sum(a, 11, sizeof(int), isEven, &e);
	display("evens", a, n, e, 11);

	n = sum(a, 11, sizeof(int), isPrime, &p);
	display("primes", a, n, p, 11);
}


int sum(void*x, int totalnum, int size, bool(*f)(void* , void* ), void* e)
{
	int total = 0;
	for (int i = 0; i < totalnum; i++)
	if (f(((int*)x + i), (int*)e )) total++;

	return total;
}