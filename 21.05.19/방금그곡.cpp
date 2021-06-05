#include<bits/stdc++.h>

using namespace std;
// C, C#, D, D#, E, F, F#, G, G#, A, A#, B
vector<int> starts, finishs;
vector<string> names, melodys;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if(a.second < b.second) return true;
    else return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    for(int i = 0; i < m.size(); i++) {
        int idx = 0;
        while(m.find("#", idx) != string::npos) {
            idx = m.find("#", idx);
            char alphabet = m[idx - 1] - 'A' + 'a';
            string alph; alph = alphabet;
            m.replace(idx - 1, 2, alph);
        }
    }
    
    for(int i = 0; i < musicinfos.size(); i++) {
        int idx = 0;
        while(musicinfos[i].find("#", idx) != string::npos) {
            idx = musicinfos[i].find("#", idx);
            char alphabet = musicinfos[i][idx - 1] - 'A' + 'a';
            string alph; alph = alphabet;
            musicinfos[i].replace(idx - 1, 2, alph);
        }
    }
    
    
    // 데이터 정리
    for(int i = 0; i < musicinfos.size(); i++) {
        int start_time = 0;
        int end_time = 0;
        
        string hour = musicinfos[i].substr(0, 2);
        string min = musicinfos[i].substr(3, 2);
        start_time = stoi(hour) * 60 + stoi(min);
        
        hour = musicinfos[i].substr(6, 2);
        min = musicinfos[i].substr(9, 2);
        end_time = stoi(hour) * 60 + stoi(min);
        
        starts.push_back(start_time);
        finishs.push_back(end_time);
        
        string name;
        int j = 0;
        for(j = 12; musicinfos[i][j] != ','; j++) name += musicinfos[i][j];
        names.push_back(name);
        j++;
        
        string melody;
        for(int k = j; k < musicinfos[i].size(); k++) melody += musicinfos[i][k];
        melodys.push_back(melody);
    }

    
    
    int max_play = 0;
    vector<pair<string, int> > ret;
    for(int i = 0; i < starts.size(); i++) {
        int diff = finishs[i] - starts[i];
        string check_melody;
        
        for(int j = 0; j < diff; j++) check_melody += melodys[i][j % melodys[i].size()];
        cout << check_melody << " " << m << "\n";
        
        
        if(check_melody.find(m) != string::npos) {
            if(diff > max_play) {
                ret.clear();
                max_play = diff;
                ret.push_back({names[i], i});
            }
            else if(diff == max_play) ret.push_back({names[i], i});
        }
    }
    
    if(ret.size() == 0) answer = "(None)";
    else if(ret.size() == 1) answer = ret[0].first;
    else {
        sort(ret.begin(), ret.end(), cmp);
        answer = ret[0].first;
    }
    return answer;
}