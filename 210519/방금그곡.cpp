#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <iostream>

using namespace std;
void substate(string& melody)
{
	string new_melody = "";
	char post;
	for (const auto& c : melody) {
		if (c == '#') {
			new_melody.pop_back();
			new_melody.push_back(post + 32);
			continue;
		}
		new_melody.push_back(c);
		post = c;
	}
	melody = new_melody;
}
string solution(string m, vector<string> musicinfos) {
	string answer = "";
	map<int, string> result;
	string data;
	string start, end, name, melody;
	string music = "";
	int time = 0, len;

	substate(m);
	for (const auto& s : musicinfos) {
		istringstream ss(s);
		getline(ss, start, ',');
		getline(ss, end, ',');
		time = (stoi(end.substr(0, 2)) - stoi(start.substr(0, 2))) * 60 +
			(stoi(end.substr(3, 2)) - stoi(start.substr(3, 2)));
		getline(ss, name, ',');
		getline(ss, melody, ',');
		substate(melody);

		len = melody.length();
		for (int i = 0; i<time; i++)
			music.push_back(melody[i % len]);
		if (music.find(m) != string::npos) {
			if (result.find(time) == result.end()) {
				result[time] = name;
			}
		}
		music.clear();
	}

	for (map<int, string>::iterator it = result.begin(); it != result.end(); it++)
		answer = it->second;
	if (answer.length() == 0)
		answer = "(None)";
	return answer;
}