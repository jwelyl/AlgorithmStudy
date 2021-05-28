#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0; i < numbers.size(); i++) {
        long long num = numbers[i];
        if(num % 2 == 0) answer.push_back(num + 1);
        else {
            long long zeroBit = (num + 1) & (~num);
            long long result = (num | zeroBit) & (~(zeroBit >> 1));
            answer.push_back(result);
        }
    }
    return answer;
}