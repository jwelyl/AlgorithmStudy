#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 10001
int N, C, M;
int capacity[2001];
typedef struct node {
	int s, e;
	int w;
};
node arr[MAX_SIZE];
bool cmp(node& n1, node&n2)
{
	if (n1.e == n2.e) {
		return n1.s < n2.s;
	}
	return n1.e < n2.e;
}
int main()
{
	scanf("%d %d %d", &N, &C, &M);
	for (int i = 0; i < M; i++)
		scanf("%d %d %d", &arr[i].s, &arr[i].e, &arr[i].w);
	sort(arr, arr + M, cmp);
	int answer = 0;
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = arr[i].s; j < arr[i].e; j++) {
			cnt = max(cnt, capacity[j]);
		}
		int left = min(arr[i].w, C - cnt);
		answer += left;
		for (int j = arr[i].s; j < arr[i].e; j++) {
			capacity[j] += left;
		}
	}
	cout << answer << "\n";
	return 0;
}