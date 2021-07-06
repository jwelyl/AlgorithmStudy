#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
int min_num = 1e9;
int max_num = -1;

int odd(int n){ // 홀수의 개수를 구하는 함수
    int odd_num = 0;
    while(n > 0){
        int num = n % 10;
        if (num % 2 == 1) 
            odd_num++;
        n /= 10;
    }
    return odd_num;
}

void recursive(int x , int result){
    
    if (x < 10){ // 한 자리 수 일때
        min_num = min(result,min_num);
        max_num = max(result,max_num);
        return;
    }

    else if (x < 100){ // 두 자리 수일때
        int new_num = x / 10 + x % 10; // 두개로 나눠서 합을 구함
        recursive(new_num , result + odd(new_num));
    }

    else{ // 세자리 수일때
        string three_digit = to_string(x); // int형 x를 string으로 변환
        int len = three_digit.length();
        for(int i = 1; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                string s1 = three_digit.substr(0,i); // 0부터 i까지 문자열 저장
                string s2 = three_digit.substr(i,j-i);
                string s3 = three_digit.substr(j,len-j);
                int sum = stoi(s1) + stoi(s2) + stoi(s3); // string에서 int형으로 변환
                recursive(sum , result + odd(sum));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    recursive(n,odd(n));
    cout << min_num << ' ' << max_num;
    
}

//999 999 999 = 2997
// 29 + 9 + 7 = 45
// 4 + 5 = 9
