#include <string>
#include <vector>
#include <map>
using namespace std;
typedef struct Node {
	string parent;
	int sum = 0;
};
map<string, Node> m;
void recur(string name, int price)
{
	int benefit = price / 10;
	m[name].sum += (price - benefit);
	if (benefit < 1)
		return;
	if (m[name].parent.length() != 0) {
		recur(m[name].parent, benefit);
	}
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	Node n;
	n.parent = "";
	n.sum = 0;
	m["-"] = n;
	for (int i = 0; i < enroll.size(); i++) {
		n.parent = referral[i];
		n.sum = 0;
		m[enroll[i]] = n;
	}
	for (int i = 0; i < seller.size(); i++) {
		int price = amount[i] * 100;
		recur(seller[i], price);
	}
	for (int i = 0; i < enroll.size(); i++) {
		answer.push_back(m[enroll[i]].sum);
	}

	return answer;
}