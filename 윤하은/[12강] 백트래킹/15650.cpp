#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

//arr[k]를 결정하는 함수
void func(int k)
{
    //수열이 완성됨 -> 출력해야함
    if(k == m+1)
    {
        for(int i = 1; i< m+1; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 1; i<=n; i++)
    {
        //현재 수열에서 i가 사용되지 않았을 경우
        if(!isUsed[i] && arr[k-1] < i)
        {
            arr[k] = i;
            isUsed[i] = true;
            //arr[k+1] 을 결정
            func(k+1);
            //func(k+1)이 반환되어 이 줄에 다시 도착했다면
            //arr[0] arr[1]... arr[k-1] arr[k]를 포함하는 가능한 수열이 모두 출력됐음을 뜻함
            isUsed[i] = false;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    func(1);
    
}
