#include <iostream>
using namespace std;

string s, key;
string answer;
void pro() {
    int idx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') answer += ' ';
        else if((s[i] - 'a' + 1) - (key[idx] - 'a' + 1) <= 0) {
            answer += (s[i] - 'a' + 1) - (key[idx] - 'a' + 1) + 26 - 1 + 'a';
        }
        else if((s[i] - 'a' + 1) - (key[idx] - 'a' + 1) > 0) {
            answer += (s[i] - 'a' + 1) - (key[idx] - 'a' + 1) - 1 + 'a';
        }
        idx = (idx + 1) % key.size();
    }
    cout << answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, s);
    cin >> key;
    pro();
}