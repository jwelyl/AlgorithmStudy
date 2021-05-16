#include <string>
#include <vector>
 
using namespace std;
 
string solution(string w) {
    string answer = "";
    int left = 0, right = 0;
    bool check = false;
    
    if(w.size() == 0) return "";
    
    for(int i=0; i < w.size(); i++){
        if(w[i] == '(') left++;
        if(w[i] == ')') right++;
        
        if(right > left) check = true;
        
        if(left == right){
            if(check){
                answer += "(";
                answer += solution(w.substr(i+1));
                answer += ")";
                for(int j=1; j<i; j++){
                    if(w[j] == '(') answer += ")";
                    else if(w[j] == ')') answer += "(";
                }
                return answer;
            }
            else{
                answer = answer + w.substr(0, i+1);
                answer = answer + solution(w.substr(i+1));
                
                return answer;
            }
        }
    }
}
