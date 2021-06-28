#include <iostream>
#include <string>
using namespace std;
int N;
//N = 4, 1111
//1112, 1113
//1121, 1122
bool IsRight(string& str)
{
	int len = str.length();
	int start = len - 1;
	for (int i = 1; i <= len / 2; i++) {
		string first = str.substr(start - i, i);
		string second = str.substr(start, i);
		if (first.compare(second) == 0)
			return false;
		--start;
	}
	return true;
}
void backtracking(int idx, string& str)
{
	if (idx == N) {
		cout << str.c_str();
		exit(0);
	}
	for (char ch = '1'; ch <= '3'; ch++) {
		str.push_back(ch);
		if (IsRight(str))
			backtracking(idx + 1, str);
		str.pop_back();
	}
}
int main()
{
	cin >> N;
	string str;
	backtracking(0, str);
	return 0;
}