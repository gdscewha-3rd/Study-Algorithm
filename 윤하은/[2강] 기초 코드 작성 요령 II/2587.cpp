//220323
//백준 2587번 대푯값2
//https://www.acmicpc.net/problem/2587
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	const int NUM_OF_INPUT = 5;
	vector<int> numList(NUM_OF_INPUT);
	double sum = 0;

	for (int i = 0; i < NUM_OF_INPUT; i++)
	{
		scanf("%d", &numList[i]);
		sum += numList[i];
	}

	sort(numList.begin(), numList.end());
	printf("%.0lf\n", sum / NUM_OF_INPUT);
	printf("%d", numList[NUM_OF_INPUT / 2]);
}