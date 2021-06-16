#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*서로 같은 번호의 손을 잡아야 한다.
	한 문어와 둘 이상의 손을 잡을 수 없다.
	한 손으로 여러 문어의 손을 잡을 수 없다.*/
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		if (i % 2 == 0) cout << "1 ";
		else cout << "2 ";
	}
	if (n % 2 == 0) cout << "2";
	else cout << "3";
	return 0;
}