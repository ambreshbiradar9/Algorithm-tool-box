#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
	long long  F[60];
	int i,n1,n2;
	
	n1 = (n+1)%60;
	
	if ((n1 == 0) || (n1==59))
	{
		n1 = 59;
		n2 = 0;
	}
	else{
		n1 = n1 - 1;
		n2 = n1 + 1;
	}

	F[0] = 0;
	F[1] = 1;

	for (i = 2; i <60; i++)
	{
		F[i] = (F[i - 1] + F[i - 2]) % 10;
	}

	int prod;
	prod = (F[n1] * F[n2]) % 10;
	return prod;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);

	system("pause");
}
