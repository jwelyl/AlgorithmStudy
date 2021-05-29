#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <bitset>
using namespace std;
int solution(int n)
{
	int ans = 0;
	bitset<32> bit(n);
	for (int i = 0; i < bit.size(); i++) {
		if (bit[i] == 1) {
			ans++;
		}
	}
	return ans;
}