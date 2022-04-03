//220323
//백준 2490번 윷놀이 문제 (브론즈 3)
//https://www.acmicpc.net/problem/2490
#include <iostream>
using namespace std;

int main(void)
{
    int total, result;
    const int STICK_NUM = 4;
    const int TIMES = 3;

    for (int i = 0; i < TIMES; i++)
    {
        total = 0;
        result = 0;

        for (int j = 0; j < STICK_NUM; j++)
        {
            scanf("%d", &result);
            if (result == 0) total++;
        }

        char ch;
        switch (total)
        {
        case 0:
            ch = 'E';
            break;
        case 1:
            ch = 'A';
            break;
        case 2:
            ch = 'B';
            break;
        case 3:
            ch = 'C';
            break;
        case 4:
            ch = 'D';
            break;
        }

        printf("%c\n", ch);
    }
}