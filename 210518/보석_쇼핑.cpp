#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAX=100001;
unordered_map<string,int> hm;
int check[MAX];
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int totalNum=0, n=1;
    for(auto str : gems)if(hm[str]==0){hm[str]=n++;totalNum++;}
    int tst=0,ten=-1,st=0,en=MAX,currNum=0;
    while(ten<(int)gems.size()-1&&currNum<totalNum){
        check[hm[gems[++ten]]]++;
        if(check[hm[gems[ten]]]==1)currNum++;
    }
    while(currNum==totalNum){
        if(ten-tst<en-st){
                en=ten;st=tst;
        }
        check[hm[gems[tst]]]--;
        if(check[hm[gems[tst++]]]==0)currNum--;
    }
    while(ten<(int)gems.size()-1){
        check[hm[gems[++ten]]]++;
        if(check[hm[gems[ten]]]==1)currNum++;
        while(currNum==totalNum){
            if(ten-tst<en-st){
                en=ten;st=tst;
            }
            check[hm[gems[tst]]]--;
            if(check[hm[gems[tst++]]]==0)currNum--;
        }
    }
    answer.push_back(st+1);
    answer.push_back(en+1);
    return answer;
}