#include <bits/stdc++.h>
using namespace std;
const int ARR_MAX_SIZE(10);

bool isFull(int arr[], int &len)
{
    if(len == ARR_MAX_SIZE) return true;
    else return false;
}
bool doNotExist(int idx, int arr[], int& len)
{
    if(idx >= len) return true;
    else return false;
}
void insert(int idx, int num, int arr[], int& len)
{
    if(isFull(arr, len))
    {
        printf("array is full.\n");
        return;
    }
    else
    {
        for(int i = len-1; i>= idx; i--)
            arr[i+1] = arr[i];
        arr[idx] = num;
        len++;
        return;
    }
    
}
void erase(int idx, int arr[], int &len)
{
    if(doNotExist(idx, arr, len))
    {
        printf("arr[idx] do not Exist.\n");
        return;
    }
    else
    {
        for(int i = idx; i<len-1; i++)
            arr[i] = arr[i+1];
        len--;
        return;
    }
}

void printArr(int arr[], int len)
{
    for(int i =0; i<len; i++)
        printf("%d ", arr[i]);
        
    printf("\n");
}
int main(void)
{
    int arr[ARR_MAX_SIZE] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    printArr(arr, len);
    insert(3, 60, arr, len);
    
    printArr(arr, len);
    erase(4, arr, len);
    
    printArr(arr, len);
    
}
