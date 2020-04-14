#include <iostream>

int get_change(int m) {
  //write your code here
	int n=0,rem;
	int dev[] = { 10, 5, 1 };
	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		count = m / dev[i];
		n = n + count;
		m = m - dev[i] * count;
	}
	

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
 // system("pause");
}
