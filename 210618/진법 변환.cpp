#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;
map<char, int> m;
int main()
{
	string str;
	int digit;
	cin >> str >> digit;
	int sum = 0, value = 0;
	for (char ch = '0'; ch <= '9'; ch++) {
		m[ch] = value++;
	}
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		m[ch] = value++;
	}
	for (int i = str.size() - 1; i >= 0; i--) {
		sum += pow(digit, str.size() - i - 1) * m[str[i]];
	}
	printf("%d\n", sum);
	return 0;
}