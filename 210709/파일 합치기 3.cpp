//그리디 정당성 밝히기
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
typedef long long ll;
int N;
int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		cin >> N;
		ll temp, answer = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lld", &temp);
			pq.push(temp);
		}
		while (pq.size() >= 2) {
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			answer += (a + b);
			pq.push(a + b);
		}
		cout << answer << endl;
	}
	return 0;
}