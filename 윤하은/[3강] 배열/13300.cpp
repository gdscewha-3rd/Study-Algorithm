//220329
//백준 13300번 방 배정 문제 (브론즈 2)
//boj.kr/13300
#include <bits/stdc++.h>
using namespace std;
int calculateRoomNum(vector<vector<int>> v, int max)
{
    int result =0;
    for(int i =1; i<=6; i++)
    {
        for(int j = 0; j<2; j++)
        {    
            result += (int)ceil((double)v[i][j]/max);
            //cout <<result << "\n";
        }
    }
    return result;
}
void printV(vector<vector<int>> v)
{
    for(int i =1; i<=6; i++)
    {
        printf("%d학년 여자:%d 남:%d\n", i, v[i][0], v[i][1]);
            
    }
}
int main(void)
{
    int totalStuNum =0;
    int maxRoomPeople = 0;
    scanf("%d %d", &totalStuNum, &maxRoomPeople);
    
    vector<vector<int>> stuList(7, vector<int>(2));
    
    int sex = 0 , grade = 0;
    for(int i = 0; i<totalStuNum; i++)
    {
        scanf("%d %d", &sex, &grade);
        stuList[grade][sex]++;
    }
    //printV(stuList);
    
    int result = calculateRoomNum(stuList, maxRoomPeople);
    printf("%d", result);
}
