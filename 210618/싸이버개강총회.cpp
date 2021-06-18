//문자열로된 시간을 정수로 바꿔주면 계산이 편하다
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, pair<int, int>> m;
int start, ass_end, stream_end;
int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	start = stoi(s1.substr(0, 2)) * 60 + stoi(s1.substr(3));
	ass_end = stoi(s2.substr(0, 2)) * 60 + stoi(s2.substr(3));
	stream_end = stoi(s3.substr(0, 2)) * 60 + stoi(s3.substr(3));
	string log_time, name;
	int time = 0;
	while (!cin.eof()) {
		cin >> log_time >> name;
		time = stoi(log_time.substr(0, 2)) * 60 + stoi(log_time.substr(3));
		if (m.find(name) == m.end())
			m.insert({ name,{ 0, 0 } });
		if (time <= start) {
			m[name].first = 1;
		}
		else if (ass_end <= time && time <= stream_end) {
			m[name].second = 1;
		}
	}
	int answer = 0;
	for (const auto& it : m) {
		if (it.second.first == 1 && it.second.second == 1) {
			answer++;
		}
	}
	printf("%d\n", answer);
	return 0;
}