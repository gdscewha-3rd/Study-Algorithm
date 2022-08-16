#include <bits/stdc++.h>
using namespace std;

void printStr(string& str)
{
    for(int i = 0; i<str.length(); i++)
    {
        cout << str[i] << " ";
    }
    cout << "\n";
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int inputNum, arrLength;
    cin >> inputNum >> arrLength;

    int arr[10];
    int inputNums[10];
    for(int i = 0; i<inputNum; i++)
        cin >> inputNums[i];

    //사전순 출력을 위한 정렬
    sort(inputNums, inputNums+inputNum);


    for(int i = 0; i<arrLength; i++)
        arr[i] = 0;
    for(int i = arrLength; i<inputNum; i++)
        arr[i] = 1;

    vector<string> strings;
    do
    {
        vector<char> result;
        int j = 0;
        for(int i = 0; i<inputNum; i++)
        {
            //inputNums[i]가 뽑힘
            if(arr[i] == 0)
                result.push_back((char)(inputNums[i]+'0'));
        }
        sort(result.begin(), result.end());
        string str(result.begin(), result.end());
        strings.push_back(str);

    }while(next_permutation(arr, arr+inputNum));

    printStr(strings[0]);
    for(int i = 1; i<strings.size(); i++)
    {
        if(strings[i-1] != strings[i])
            printStr(strings[i]);
    }
}