#include <string>
#include <unordered_map>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	unordered_map<string, int> m1;
	unordered_map<string, int> m2;

	string temp = "";
	for (int i = 0; i < str1.size(); i++) {
		str1[i] = toupper(str1[i]);

	}
	for (int i = 0; i < str2.size(); i++) {
		str2[i] = toupper(str2[i]);
	}

	for (int i = 0; i < str1.size() - 1; i++) {
		if ('A' <= str1[i] && str1[i] <= 'Z' && 'A' <= str1[i + 1] && str1[i + 1] <= 'Z') {
			m1[str1.substr(i, 2)]++;
		}
	}

	for (int i = 0; i < str2.size() - 1; i++) {
		if ('A' <= str2[i] && str2[i] <= 'Z' && 'A' <= str2[i + 1] && str2[i + 1] <= 'Z') {
			m2[str2.substr(i, 2)]++;
		}
	}

	unordered_map<string, int> temp_m;
	int Union = 0, inter = 0;

	for (auto it = m1.begin(); it != m1.end(); it++) {
		if (m2[it->first] > 0) {
			if (it->second > m2[it->first]) {
				temp_m[it->first] = m2[it->first];
			}
			else {
				temp_m[it->first] = it->second;
			}
		}
	}
	for (auto it = temp_m.begin(); it != temp_m.end(); it++) {
		inter += it->second;
	}

	for (auto it = m2.begin(); it != m2.end(); it++) {
		if (m1[it->first] < it->second) {
			m1[it->first] = it->second;
		}
	}
	for (auto it = m1.begin(); it != m1.end(); it++) {
		Union += it->second;
	}

	if (Union == 0) return 65536;
	double a = (double)inter / (double)Union * 65536;
	answer = a;
	return answer;
}