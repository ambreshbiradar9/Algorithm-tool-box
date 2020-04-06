#include <iostream>

long long gcd_naive(long a, long b) {
	long long current_gcd = 1, d = 0, r = 0;
	if (a >= b)
	{
		r = a%b;
		d = b;
	}
	else
	{
		r = b%a;
		d =a;
	}
	if (r == 0)
	{
		return d;
	}
	else
	{
		d = gcd_naive(r, d);
	}

}




int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  system("pause");
  return 0;
  
}
