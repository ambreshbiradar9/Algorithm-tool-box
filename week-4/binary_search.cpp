#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int bsearch(const vector<int> &a, int x, int left, int right)
{
	int mid = 0;
	mid = left + (right - left) / 2;
	if (right<left)
	{
		return -1;
	}

	if (a[mid] == x)
	{
		return mid;
	}

	else if (a[mid] > x)
	{
		return bsearch(a, x, mid + 1, right);
	}

	else
	{
		return bsearch(a, x, left, mid - 1);
	}

}


int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  int mid;
  right = right - 1;

  return bsearch(a, x, left, right);

}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) 
  {
    if (a[i] == x) 
		return i;
  }
  return -1;
}


int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) 
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    //replace with the call to binary_search when implemented
	  std::cout << binary_search(a, b[i]) << ' ';
  }
  system("pause");
}
