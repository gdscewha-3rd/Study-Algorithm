//220323
//백준 2576번 홀수 문제 (브론즈 3)
//https://www.acmicpc.net/problem/2576
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int result = 0, minNum = 99;
    const int INPUT_NUM = 7;

    for (int i = 0; i < INPUT_NUM; i++)
    {
        int num = 0;
        scanf("%d", &num);
        if (num % 2 == 1)
        {
            result += num;
            minNum = min(minNum, num);
        }
    }

    if (result != 0) printf("%d\n%d", result, minNum);
    else printf("-1");
}