#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
#include<cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char a = 'A';

	string str;
	int num;
	cin >> str >> num;
	int ans = 0;
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if ('A' <= str.back() && str.back() <= 'Z') {
			ans += (str.back() - 55) * pow(num, i);
		}
		else {
			ans += (str.back() - '0') * pow(num, i);
		}

		str.pop_back();
	}
	cout << ans << endl;
	return 0;
}