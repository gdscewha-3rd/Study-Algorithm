#include <bits/stdc++.h>
using namespace std;

int n, m;
int resulArr[10];
//두개쓰지말고 pair로 isUsed하나로 해결할 수 있게 수정하기
vector<int> nums;
bool isUsed[10001];

void func(int k)
{
  if(k==m)
  {
    for(int i =0; i<m; i++)
      cout << resultArr[i];
    cout << "\n";
    return;
  }
  else{
    for(int i = 0; i<n; i++)
      {
        int target = nums[i];
        if(!isUsed[target])
        {
          isUsed[target] = true;
          arr[k] = target;
          func(k+1);
          isUsed[target] = false;
        }
      }
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for(int i = 0; i<n; i++){
    int num;
    nums.push_back(num);
  }  

  sort(nums.begin(), nums.end());

  func(0);

  

  

  

  
}
