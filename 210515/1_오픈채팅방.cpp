#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> umap;
    string cmd, uid, nickname;

    for (string& s : record) {
        stringstream ss(s);
        ss >> cmd >> uid >> nickname;

        if (cmd.compare("Enter") == 0 || cmd.compare("Change") == 0) {
            umap[uid] = nickname;
        }
    }

    for (string& s : record) {
        stringstream ss(s);
        ss >> cmd >> uid >> nickname;
        if (cmd.compare("Enter") == 0) {
            answer.push_back(umap[uid] + "님이 들어왔습니다.");
        } else if (cmd.compare("Leave") == 0) {
            answer.push_back(umap[uid] + "님이 나갔습니다.");
        }
    }

    return answer;
}
