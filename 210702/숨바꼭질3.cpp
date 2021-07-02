#include <iostream>
#include <deque>
using namespace std;
#define MAX_SIZE 100001
int visit[MAX_SIZE] = { 0, };
int N, K;
struct pos {
	int cost;
	int cord;
};
int main()
{
	fill(&visit[0], &visit[MAX_SIZE - 1], -1);
	cin >> N >> K;
	if (N == K) {
		printf("%d\n", 0);
		return 0;
	}
	deque<pos> dq;
	struct pos p, np;
	p.cord = N;
	p.cost = 0;
	visit[N] = 0;
	visit[K] = -1;
	dq.push_back(p);

	while (!dq.empty()) {
		p = dq.front();
		dq.pop_front();
		if (p.cord == K) {
			printf("%d\n", visit[p.cord]);
			break;
		}
		if (p.cord * 2 < MAX_SIZE && visit[p.cord * 2] == -1 && N < K) {
			np.cost = 0;
			np.cord = p.cord * 2;
			visit[np.cord] = visit[p.cord];
			dq.push_front(np);
		}
		if (p.cord - 1 >= 0 && visit[p.cord - 1] == -1) {
			np.cost = 1;
			np.cord = p.cord - 1;
			visit[np.cord] = visit[p.cord] + 1;
			dq.push_back(np);
		}
		if (p.cord + 1 < MAX_SIZE && visit[p.cord + 1] == -1 && N < K) {
			np.cost = 1;
			np.cord = p.cord + 1;
			visit[np.cord] = visit[p.cord] + 1;
			dq.push_back(np);
		}
	}
	return 0;
}