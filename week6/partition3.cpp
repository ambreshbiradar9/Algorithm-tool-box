#include <iostream>
#include <vector>
//#include <algorithm>
#include <numeric>
using std::vector;
using namespace std; 

int partition3(vector<int> &A)
{
  int sum=accumulate(A.begin(),A.end(),0);
    if(sum%3)
    { 
    return 0;
    }
    int n=A.size();
    vector<vector<int> > value(sum/3+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        int wi=A[i-1];
        for(int w=1;w<=sum/3;w++) 
        {
            value[w][i]=value[w][i-1];
            if(w>=wi)
            {
                value[w][i]=max(value[w-wi][i-1]+wi,value[w][i-1]);                    
            }
        }
     }
    return value[sum/3][n]==sum/3; 
}

  

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) 
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
