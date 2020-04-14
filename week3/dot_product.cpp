#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;


vector<int> merge(vector<int> &v, const vector<int> &left, const vector<int> &right){

	vector<int> temp;

	// left and right ittorators 
	int li = 0;
	int ri = 0;

	while (li < left.size() && ri < right.size()){
		if (left[li] < right[ri]){
			temp.push_back(left[li]);
			li++;
		}
		else {
			temp.push_back(right[ri]);
			ri++;
		}
	} // end while

	while (li < left.size()){
		// push the rest of the values back because they are sorted
		temp.push_back(left[li]);
		li++;
	}

	while (ri < right.size()){
		// do the same for the right
		temp.push_back(right[ri]);
		ri++;
	}

	v = temp;
	return v;
}

vector<int> ms(vector<int> &v){
	// base case, we are done!
	if (v.size() == 1)
		return v;

	// find the middle
	vector<int>::iterator mid = v.begin() + (v.size() / 2);

	// cut this guy in half
	vector<int> left(v.begin(), mid);
	vector<int> right(mid, v.end());

	// wow look recursion!
	left = ms(left);
	right = ms(right);

	// merge!
	return merge(v, left, right);
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
	int n, m;
	n = a.size();
	m = b.size();

	vector <int> c(n);
	vector <int> d(m);
	
	c=ms(a);
	d=ms(b);
	long long result = 0;
  for (int i = 0; i < a.size(); i++) {
    result += ((long long) c[i]) * d[i];
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  system("pause");
}
