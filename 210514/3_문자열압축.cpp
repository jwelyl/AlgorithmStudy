#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ans = s.length();

    for (int i = 1; i <= s.length() / 2; ++i) {
        int pos = 0;
        int len = s.length();  // 압축됬을때 길이

        while (1) {
            string cut = s.substr(pos, i);  // 압축단위 1~s.length()/2 까지 체크
            pos += i;
            if (pos >= s.length()) break;

            int cnt = 0;
            while (1) {
                if (cut.compare(s.substr(pos, i))) break;  // 다음 컷끼리 다르면 종료

                ++cnt;
                pos += i;
            }

            if (cnt) {
                len -= i * cnt;  // 압축된만큼 빼주고 압축된 길이의 자릿수만큼 더해주기
                if (cnt < 9)
                    len += 1;
                else if (cnt < 99)
                    len += 2;
                else if (cnt < 999)
                    len += 3;
                else
                    len += 4;
            }
        }

        if (ans > len) {
            ans = len;
        }
    }

    return ans;
}
