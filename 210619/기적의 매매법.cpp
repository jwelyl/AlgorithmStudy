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
	int cash;
	cin >> cash;
	int hyun = cash;
	int min = cash;

	int have[2] = { 0 };
	int up = 0, down = 0;
	int up_cnt = 0, down_cnt = 0;

	for (int i = 1; i <= 14; i++) {
		int trade;
		cin >> trade;
		if (i == 1) {
			up = trade;
			down = trade;

		}
		else {
			if (up < trade) {
				up = trade;
				down = trade;
				up_cnt++;
				down_cnt = 0;
			}
			else if (down > trade) {
				down = trade;
				up = trade;
				down_cnt++;
				up_cnt = 0;
			}

			if (up_cnt == 3) {
				min += have[1] * trade;
				have[1] = 0;
				up_cnt = 0;
			}
			else if (down_cnt >= 3) {
				if (min / trade >= 1) {
					have[1] += min / trade;
					min %= trade;
					//down_cnt = 0;
				}
			}
		}

		if (hyun / trade >= 1) {
			have[0] += hyun / trade;
			hyun %= trade;
		}

		if (i == 14) {
			hyun += have[0] * trade;
			min += have[1] * trade;
			if (hyun > min) cout << "BNP" << endl;
			else if (hyun < min) cout << "TIMING" << endl;
			else cout << "SAMESAME" << endl;
			//cout << hyun <<" "<<min << endl;
		}
	}

	return 0;
}