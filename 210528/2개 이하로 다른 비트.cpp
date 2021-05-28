#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <bitset>
#include <limits>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (int i = 0; i < numbers.size(); i++) {

		if (numbers[i] % 2 == 0) {
			answer.push_back(numbers[i] + 1);
		}
		else {
			bitset<numeric_limits<unsigned long long>::digits> bit(numbers[i]);

			for (int j = 0; j < bit.size(); j++) {
				if (bit[j] == 1 && bit[j + 1] == 0) {
					bit[j + 1] = 1;
					bit[j] = 0;
					answer.push_back(bit.to_ullong());
					break;
				}
			}

		}
	}
	return answer;
}