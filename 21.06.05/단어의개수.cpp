#include <iostream>
using namespace std;
string s;
int answer;

void pro() {
    int left = 0, right = 0;
    while(right != s.size()) {
        if(s[right] == ' ') answer++;
        right++;
    }
    answer++;

    if(s[0] == ' ') answer--;
    if(s[s.size() - 1] == ' ') answer--;

    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, s);
    pro();
}