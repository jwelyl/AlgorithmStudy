#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct info {
	string head;
	string number;
	string tail;
};

bool cmp(const info& p1, const info& p2) {

	info info1 = p1, info2 = p2;

	for (int i = 0; i < info1.head.size(); i++) {
		info1.head[i] = toupper(info1.head[i]);
	}

	for (int i = 0; i < info2.head.size(); i++) {
		info2.head[i] = toupper(info2.head[i]);
	}
	if (info1.head < info2.head) {
		return true;
	}
	else if (info1.head > info2.head) {
		return false;
	}
	else {
		int n1 = stoi(info1.number);
		int n2 = stoi(info2.number);
		if (n1 < n2) {
			return true;
		}
		return false;
	}
}

vector<string> solution(vector<string> files) {
	vector<string>answer;
	vector<info>result;
	for (int i = 0; i < files.size(); i++) {
		string temp = "";
		string h = "", n = "", t = "";
		bool headchk = true;
		bool numberchk = true;
		int cnt = 0;
		for (int j = 0; j < files[i].size(); j++) {

			if (headchk && ('0' > files[i].at(j) || '9' < files[i].at(j))) {
				temp += files[i].at(j);
			}
			else if (numberchk && ('0' <= files[i].at(j) && '9' >= files[i].at(j))) {
				if (headchk) {
					h = temp;
					headchk = false;
					temp = "";
				}
				cnt++;
				temp += files[i].at(j);
				if (cnt == 5 || j == files[i].size() - 1) {
					n = temp;
					numberchk = false;
					temp = "";
				}
			}
			else {
				if (numberchk) {
					n = temp;
					numberchk = false;
					temp = "";
				}
				temp += files[i].at(j);
			}
		}
		t = temp;
		result.push_back({ h,n,t });
	}

	stable_sort(files.begin(), files.end(), cmp);

	for (int i = 0; i < result.size(); i++) {
		answer.push_back(result[i].head + result[i].number + result[i].tail);
	}
	return answer;
}