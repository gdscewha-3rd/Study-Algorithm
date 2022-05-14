//220508
//백준 1157번 단어 공부 (브론즈 1)
//https://www.acmicpc.net/problem/1157


#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000000];
    int i, len, j, count, max, a = 0, k;
    int arr[26];

    scanf("%s", str);
    len = strlen(str);

    for (j = 65; j < 91; j++)
    {
        count = 0;
        for (i = 0; i < len; i++)
        {
            if (str[i] == j || str[i] == j + 32)
            {
                count++;
            }
        }
        arr[j - 65] = count;
    }

    max = arr[0];

    for (i = 1; i < 26; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (max == arr[i])
        {
            a++;
            k = i;
        }
    }

    if (a == 1)
    {
        printf("%c \n", k + 65);
    }
    else if (a > 1)
        printf("? \n");

    return 0;

}