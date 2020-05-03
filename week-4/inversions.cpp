#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t ave, size_t right)
{
	int l, r;
	l = ave - left + 1;
	r = right - ave;
	int j = left;
	vector <int> lh(l), rh(r);

	for (int i = 0; i < l; i++)
	{
		lh[i] = a[j];
		j++;
	}

	for (int i = 0; i < r; i++)
	{
		rh[i] = a[j];
		j++;
	}
	int constant = 0;
	int	i = 0;
	j = 0;
	int count = left;

	long long number_of_inversions = 0;

	while ((i<l)&&(j<r))
	{
		if (lh[i] > rh[j])
		{
			a[count] = rh[j];
			number_of_inversions +=l-i;
			j++;
			count++;
		}
		else
		{
			a[count] = lh[i];
			i++;
			count++;
		}
	}

	while (i < l)
	{
		a[count] = lh[i];
		i++;
		count++;
	}
	while (j < r)
	{
		a[count] = rh[j];
		j++;
		count++;
	}

	return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left ) 
  {
	  return number_of_inversions;
  }
	  size_t ave = left + (right - left) / 2;

	  number_of_inversions += get_number_of_inversions(a, b, left, ave);
     
	  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  //write your code here
	  number_of_inversions += merge(a, b, left, ave, right);
	  return number_of_inversions;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, (a.size()-1)) << '\n';
 // for (size_t i = 0; i < a.size(); i++) {
//	  std::cout << a[i] <<'\n';
 // }
 system("pause");
}
