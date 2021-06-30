#include <iostream>
using namespace std;
int arr[202];
int dp[202];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j <= i; j++){
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] += 1;
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= n; i++)
        result = max(result , dp[i]);
    cout << n - result;
    return 0;
}