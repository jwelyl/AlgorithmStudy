#include <bits/stdc++.h>

using namespace std;

string getHead(string s) {
    string tmp;
    int left = 0, right = 0;
    while(right != s.size()) {
        if('0' <= s[right] && s[right] <= '9') {
            tmp = s.substr(left, right - left);
            break;
        }
        right++;
    }
    transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    return tmp;
}

string getNumber(string s) {
    int first_idx = 0;
    int right = 0;
    string tmp;
    while(right != s.size()) {
        if('0' <= s[right] && s[right] <= '9') {
            first_idx = right;
            break;
        }
        right++;
    }
    
    int second_idx = 0;
    while(right != s.size()) {
        if('0' > s[right] && s[right] > '9') {
            second_idx = right;
            break;
        }
        right++;
    }
    tmp = s.substr(first_idx, second_idx - first_idx);
    return tmp;
}

bool cmp(string a, string b) {
    string aHead = getHead(a);
    string bHead = getHead(b);
    
    if(aHead == bHead) {
        string aNum = getNumber(a);
        string bNum = getNumber(b);
        return stoi(aNum) < stoi(bNum);
    }
    return aHead < bHead;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    
    
    return files;
}