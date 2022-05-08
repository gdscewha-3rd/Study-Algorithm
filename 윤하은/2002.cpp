//2022.05.07
//boj 2002 추월 문제(실버 1)
//boj.kr/2002
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	map<string, int> carsIn;
	vector<string> carsOut(n);
	
	//터널 들어가는 순서 맵에 저장
	for (int i = 0; i < n; i++)
	{
	    string s;
	    cin >> s;
	    carsIn[s] = i;
	}

	int result = 0;
	
	//터널 나온 순서 vector에 저장
	for (int i = 0; i < n; i++)
	    cin >> carsOut[i];
	
	for(int i = 0; i<n; i++)
	{
	    for(int j =i+1; j<n; j++)
	    {
	        if(carsIn[carsOut[i]] > carsIn[carsOut[j]])
	        {
	            result++;
	            break;
	        }
	    }
	}
	cout << result;
}
