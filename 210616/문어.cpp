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

	/*���� ���� ��ȣ�� ���� ��ƾ� �Ѵ�.
	�� ����� �� �̻��� ���� ���� �� ����.
	�� ������ ���� ������ ���� ���� �� ����.*/
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