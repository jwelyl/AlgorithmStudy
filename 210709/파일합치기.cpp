#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int t;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
	{
		priority_queue<ll, vector<ll>, greater<ll> >pq;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			int x; cin >> x;
			pq.push(x);
		}
		ll ans = 0;
		while (pq.size() > 1) {
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			ans += (a + b);
			pq.push(a + b);
		}
		cout << ans << "\n";
	}
	return 0;
}