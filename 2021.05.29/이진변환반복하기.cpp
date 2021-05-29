#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(2);
    int cnt = 0;
    int turn = 0;
    
    while(s != "1") {
        string temp = "";
        int temp_size = 0;
        turn++;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') cnt++;
            else temp += '1';
        }
        
        temp_size = temp.size();
        s = "";
        while(temp_size > 0) {
            s += to_string(temp_size % 2);
            temp_size /= 2;
        }
    }
    
    answer[0] = turn;
    answer[1] = cnt;
    return answer;
}