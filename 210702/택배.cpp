#include<iostream>
using namespace std;
#define MAX 201

int N, M, a, b, c, INF = 987654321;
int garb[MAX][MAX];
int answer[MAX][MAX] = { 0 };


int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		garb[a][b] = c;
		garb[b][a] = c;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (garb[i][j] == 0)
				garb[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (garb[i][j] != 0 && garb[i][j] != INF)
				answer[i][j] = j;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (garb[j][k] > garb[j][i] + garb[i][k]) {
					garb[j][k] = garb[j][i] + garb[i][k];
					answer[j][k] = answer[j][i];
				}
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << "- ";
			else cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}