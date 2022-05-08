//220409
//백준 10828번 스택 (실버 4)
//https://www.acmicpc.net/problem/10828

#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<int> s;

int main() {
	int N;
	string order;
	cin >> N;
	while (N--) {
		cin >> order;
		if (order == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (order == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top();
				s.pop();
			}
		}
		else if (order == "size") {
			cout << s.size();
		}
		else if (order == "empty") {
			if (s.empty()) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		else if (order == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top();
			}
		}
	}
	return 0;
}