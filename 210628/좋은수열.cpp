#include <iostream>
using namespace std;
int N;
char arr[81];

bool compare(int s, int e, int s1, int e1){
  int n=e-s;
  for(int i=0; i<n; i++)if(arr[s+i]!=arr[s1+i])return false;

  return true;
}

bool possible(int step, char n){
  int num=step/2;
  arr[step-1]=n;
  while(num){
    if(compare(step-2*num,step-num,step-num,step))return false;
    num--;
  }
  return true;
}

bool recur(int step=1){
  if(step==N+1){
    return true;
  }
  for(int i=1; i<=3; i++)if(possible(step,i+'0')){
    if(recur(step+1))return true;
  }
  return false;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N;
  recur();
  for(int i=0; i<N; i++)cout<<arr[i];
}
