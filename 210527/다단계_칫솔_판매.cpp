#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string,int> hm;
int num=1;
int par[10001];
int cost[10001];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    hm["-"]=num++;
    for(auto s : enroll){
        hm[s]=num++;
    }
    for(int i=0; i<referral.size(); i++){
        par[hm[enroll[i]]]=hm[referral[i]];
    }
    for(int i=0; i<seller.size(); i++){
        int c=amount[i]*100;
        int curr=hm[seller[i]];
        while((int)c*(0.1)&&par[curr]){
            int tc=c-(int)(c*0.1);
            c*=0.1;
            cost[curr]+=tc;
            curr=par[curr];
        }
        cost[curr]+=c;
    }
    for(int i=2; i<num; i++)answer.push_back(cost[i]);
    return answer;
}