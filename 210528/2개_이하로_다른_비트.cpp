#include <string>
#include <vector>

using namespace std;

long long find(long long num){
    int n;
    for(n=0;n<64; n++)if(!(num&(1LL<<n)))break;
    
    if(n>0)return (1LL<<n)|(num^(1LL<<(n-1)));
    return (1LL<<n)|num;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto num : numbers)
        answer.push_back(find(num));
    return answer;
}