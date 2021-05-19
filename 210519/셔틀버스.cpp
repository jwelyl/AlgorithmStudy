#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int Str2Int(const string& time)
{
	int total = 0;
	total += stoi(time.substr(0, 2)) * 60;
	total += stoi(time.substr(3, 2));
	return total;
}
string Int2Str(const int time)
{
	int hour = time / 60;
	int min = time % 60;
	string str_hour = to_string(hour);
	string str_min = to_string(min);
	if (str_hour.length() < 2)
		str_hour.insert(str_hour.begin(), '0');
	if (str_min.length() < 2)
		str_min.insert(str_min.begin(), '0');
	string result = str_hour + ":" + str_min;
	return result;
}
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int idx = 0;
	int cutLine = 540;
	sort(timetable.begin(), timetable.end());
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = idx; j < timetable.size(); j++) {
			if (Str2Int(timetable[j]) <= cutLine) {
				idx++;
				cnt++;
				if (cnt == m)
					break;
			}
		}
		if (i == n - 1) {
			if (cnt == m) {
				int time = Str2Int(timetable[idx - 1]) - 1;
				answer = Int2Str(time);
			}
			else {
				answer = Int2Str(cutLine);
			}

		}
		cutLine += t;
	}
	return answer;
}