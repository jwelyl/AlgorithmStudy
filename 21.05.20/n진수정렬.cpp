#include <bits/stdc++.h>

using namespace std;
/*
0 0
1 1
2 10
3 11
4 100
5 101
6 110
7 111

진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p 가 주어진다.
튜브가 말해야 하는 숫자 t개를 공백 없이 차례대로 나타낸 문자열. 
단, 10~15는 각각 대문자 A~F로 출력한다.
*/

string convert(int d, int n) {
    string res = "";
    char code[]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    while(d / n != 0) {
        res = code[d % n] + res;
        d /= n;
    }
    res = code[d % n] + res;
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    
    for(int i = 0; i < t * m; i++) tmp += convert(i, n);
    
    int cnt = 0;
    //0 1 10 11 100 101 110 111
    for (int i = p-1;  i < tmp.size(); i += m) {
        answer += tmp[i];
        if (cnt + 1 == t) break;
        cnt += 1;
    }
    
    return answer;
}
