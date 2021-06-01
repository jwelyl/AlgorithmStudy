#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<string> solution(vector<string> s) {
	vector<string> answer;
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0;
		string temp = "";
		for (int j = 0; j < s[i].length(); j++)
		{
			temp += s[i][j];
			if (temp.length() >= 3)
			{
				if (temp.substr(temp.length() - 3, 3) == "110")
				{
					cnt++;
					temp.erase(temp.length() - 3, temp.length());
				}
			}
		}

		int loc = temp.rfind("0");
		if (loc == -1) {
			while (cnt > 0) {
				temp.insert(0, "110");
				cnt--;
			}
			answer.push_back(temp);
		}
		else {
			while (cnt > 0) {
				loc = temp.rfind("0");
				temp.insert(loc + 1, "110");
				cnt--;
			}
			answer.push_back(temp);
		}
	}

	return answer;
}