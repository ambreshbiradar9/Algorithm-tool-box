#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n=w.size();
  //int d[n+1][W+1];
  vector< vector< int> >  d(n + 1,vector< int>(W + 1));

  for (int i = 0; i <= W; i++) 
    {
      d[0][i]=0;
    }
  for (int j = 0; j <= n; j++) 
    {
      d[j][0]=0;
    }
  for(int j=1;j<=n;j++)
  {
    for (int i=1;i<=W;i++) 
    { 
      if(i>=w[j-1])
      {
      d[j][i]=std::max(d[j-1][i],w[j-1]+d[j-1][i-w[j-1]]);
      }
      else
      {
         d[j][i]=d[j-1][i];
      }
    }
  }
  return d[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
