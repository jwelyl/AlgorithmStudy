#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	//n �׷��� ���� s start A ��� B ���
	//[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], 
	//[2, 4, 66], [2, 3, 22], [1, 6, 25]]

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1000000));

	for (int i = 0; i < fares.size(); i++) {
		graph[fares[i][0]][fares[i][1]] = fares[i][2];
		graph[fares[i][1]][fares[i][0]] = fares[i][2];
	} //�Ÿ����� ���� 

	//�÷��̵� �ͼ� �˰���
	for (int k = 1; k <= n; k++) { //���İ��� ���
		for (int i = 1; i <= n; i++) {//���� ���
			for (int j = 1; j <= n; j++) {//���� ���
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					if (i == j) {
						graph[i][j] = 0;
						continue;
					}
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	answer = graph[s][a] + graph[s][b];
	for (int i = 1; i <= n; i++) {
		if (graph[s][i] + graph[i][a] + graph[i][b] < answer) {
			answer = graph[s][i] + graph[i][a] + graph[i][b];
		}
	}


	return answer;
}