//220324
//백준 10804번 카드 역배치 문제 (브론즈 2)
//https://www.acmicpc.net/problem/10804

//STL reverse 함수 활용해보기
#include <bits/stdc++.h>
using namespace std;

void printArr(int* arr)
{
    for(int i =1; i<21; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main(void)
{
    int arr[21] = {0,};
    int size = 21;
    const int INPUT_NUM = 10;
    
    for(int i = 1; i<size; i++)
        arr[i] = i;
    
    printArr(arr);
    
    for(int i =0; i<INPUT_NUM; i++)
    {
        int start = 0, end =0;
        scanf("%d %d", &start, &end);
        reverse(arr+start, arr+end+1);
        printArr(arr);
    }
    printArr(arr);
}