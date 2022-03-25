//220325
//백준 15552번 빠른 A+B 문제
//https://www.acmicpc.net/problem/15552
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  cin.tie(NULL);
  cout.tie(NULL);
  
  int test = 0;
  cin >> test;

  for(int i =0; i<test; i++)
  {
    int a =0, b=0;
    cin >> a >> b;
    cout << a+b << "\n";
  }
  
}