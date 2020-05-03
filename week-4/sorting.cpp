#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2_1(vector<int> &a, int l, int r)
{
	int count = 0;
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] <= x)
		{
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

int partition2(vector<int> &a, int l, int r,int &m) 
{
	int count = 0;
  int x = a[l];
  int j = l;
  int cc = 0;
  for (int i = l+1 ; i <= r; i++)
  {
    if (a[i] < x)
	{
		j++;
        swap(a[i], a[j]);
	}
	if (a[i] == x)
	{
		count++;
	}
  }
  swap(a[l], a[j]);
  cc = j;
  for (int i =j+1; i <= r; i++)
  {
	  if (a[i] == x)
	  {
		  swap(a[i], a[j]);
		  j++;
	  }
  }
  m = j-1;
  return cc;
}

void randomized_quick_sort_1(vector<int> &a, int l, int r) {
	if (l >= r)
	{
		return;
	}
	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m;
	m=partition2_1(a, l, r);
	randomized_quick_sort_1(a, l, m - 1);
	randomized_quick_sort_1(a, m + 1, r);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) 
  {
    return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = 0;

  int cc=partition2(a, l, r, m);
  
  randomized_quick_sort(a, l, cc-1);
  randomized_quick_sort(a, m + 1, r);
}



int main()
{
	while (true)
	{
		int n = rand() % 10 + 1;
		std::cout << n << "\n";
		std::vector<int> a, b;
		for (int i = 0; i < n; i++)
		{
			a.push_back(rand() % 20);
			b.push_back(a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			std::cout << a[i] << ' ';
		}
		std::cout << "\n";
		randomized_quick_sort(a, 0, a.size() - 1);
		randomized_quick_sort_1(b, 0, a.size() - 1);
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				std::cout << " wrong answer: " << a[i] << ' ' << b[i] << "\n";
				for (size_t i = 0; i < a.size(); ++i) {
					std::cout << a[i] << ' ';
				}

				std::cout << '\n';

				for (size_t i = 0; i < a.size(); ++i) {
					std::cout << b[i] << ' ';
				}
				std::cout << '\n';
				system("pause");
				//break;
				//system("pause");
			}
			else
			{
				std::cout << "OK\n";
			}
			
		}
	}
}


/*while (true)
{
	int n = rand() % 1000 + 2;
	std::cout << n << "\n";
	std::vector<long long> a;
	for (int i = 0; i < n; i++)
	{
		a.push_back(rand() % 100000);
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << "\n";
	long long res1 = MaxPairwiseProduct(a);
	long long res2 = MaxPairwiseProductfast(a);
	if (res1 != res2)
	{
		std::cout << " wrong answer: " << res1 << ' ' << res2 << "\n";
		break;
	}
	else {
		std::cout << "OK\n";
	}*/
