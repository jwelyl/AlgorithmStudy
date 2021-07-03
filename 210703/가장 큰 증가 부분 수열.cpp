#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[1002];
int dp[1002]; // 최댓값을 저장하는 배열
int mx = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    
    for(int i = 0; i < n; i++){
        dp[i] = arr[i];
        for(int j = 0; j < i; j++){
            if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];
        }
        if (mx < dp[i])
            mx = dp[i];
    }
    cout << mx;
    return 0;
}