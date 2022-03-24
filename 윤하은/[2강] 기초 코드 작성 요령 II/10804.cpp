//220324
//백준 10804번 카드 역배치 문제 (브론즈 2)
//https://www.acmicpc.net/problem/10804
#include <bits/stdc++.h>
using namespace std;

void ReverseArr(int start, int end, int* arr)
{
    int numOfNum = end - start + 1;
    for(int i = 0; i<numOfNum/2; i++)
        swap(arr[start+i], arr[end-i]);
    return;
}
void printArr(int* arr)
{
    for(int i =0; i<20; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main(void)
{
    int arr[20] = {0,};
    int size = 20;
    const int INPUT_NUM = 10;
    
    for(int i = 0; i<size; i++)
        arr[i] = i+1;
    
    //printArr(arr);
    
    for(int i =0; i<INPUT_NUM; i++)
    {
        int start =0, end =0;
        scanf("%d %d", &start, &end);
        ReverseArr(start-1, end-1, arr);
        //printArr(arr);
    }
    printArr(arr);
}