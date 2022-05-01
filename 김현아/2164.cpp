//220409
//���� 2164�� ī��2 (�ǹ� 4)
//https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> cards;
	int N;
	int topCard;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cards.push(i);
	}

	while (cards.size() != 1) {
		cards.pop();
		topCard = cards.front();
		cards.push(topCard);
		cards.pop();
	}

	cout << cards.front();

	return 0;
};