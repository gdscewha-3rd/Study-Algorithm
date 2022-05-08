//220408
//백준 10808번 알파벳 개수 (브론즈 2)
//https://www.acmicpc.net/problem/10808


#include <iostream>
#include <string>

using namespace std;

int alphabet[26];

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		alphabet[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << ' ';
	}

	return 0;
}
