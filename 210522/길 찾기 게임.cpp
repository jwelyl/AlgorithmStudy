#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node {
	int value;
	int x;
	int y;
	node* left;
	node* right;
}node;

bool cmp(const node& a, const  node& b) {
	return a.y > b.y;
}
void add(node* n1, node* n2) {
	if (n1->x > n2->x) {
		if (n1->left == NULL) {
			n1->left = n2;
		}
		else {
			add(n1->left, n2);
		}
	}
	else {
		if (n1->right == NULL) {
			n1->right = n2;
		}
		else {
			add(n1->right, n2);
		}
	}
}
void preorder(node* node, vector<vector<int>>& answer) {
	if (node) {
		answer[0].push_back(node->value);
		preorder(node->left, answer);
		preorder(node->right, answer);
	}
}
void postorder(node* node, vector<vector<int>>& answer) {
	if (node) {
		postorder(node->left, answer);
		postorder(node->right, answer);
		answer[1].push_back(node->value);
	}
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer(2);
	vector<node> data;
	for (int i = 0; i < nodeinfo.size(); i++) {
		node in;
		in.x = nodeinfo[i][0];
		in.y = nodeinfo[i][1];
		in.left = NULL;
		in.right = NULL;
		in.value = i + 1;
		data.push_back(in);
	}
	sort(data.begin(), data.end(), cmp);
	node* nodes;

	nodes = &data[0];

	for (int i = 1; i < data.size(); i++) {
		add(nodes, &data[i]);
	}
	preorder(&data[0], answer);
	postorder(&data[0], answer);
	return answer;
}