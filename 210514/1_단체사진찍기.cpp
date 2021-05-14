#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<string> data) {
    int ans = 0;
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    do {
        bool flag = true;

        for (int i = 0; i < n; ++i) {
            string s = data[i];
            int dist = abs(find(v.begin(), v.end(), s[0]) - find(v.begin(), v.end(), s[2])) - 1;
            char sign = s[3];
            int range = s[4] - '0';

            if (sign == '>' && dist > range)
                continue;
            else if (sign == '=' && dist == range)
                continue;
            else if (sign == '<' && dist < range)
                continue;

            flag = false;
            break;
        }
        if (flag) ans++;

    } while (next_permutation(v.begin(), v.end()));

    return ans;
}
