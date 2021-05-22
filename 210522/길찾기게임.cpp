#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
  int x,y,idx;
    node(int xx, int yy, int ii):x(xx),y(yy),idx(ii){}
    bool operator < (const node& t)const{
        if(y==t.y&&x==t.x)return t.idx<idx;
        else if(y==t.y)return t.x<x;
        else return t.y<y;
    }
};
struct Tree{
    int x,idx;
    Tree* left,* right;
    Tree(){idx=-1,x=-1,left=nullptr,right=nullptr;}
};



void insertTree(Tree* root, const node& n){
    if(root->x<n.x){
        if(root->right==nullptr){
            Tree *temp = new Tree();
            temp->x=n.x;
            temp->idx=n.idx;
            root->right=temp;
            return;
        }
        else{insertTree(root->right,n);}
    }
    else{
        if(root->left==nullptr){
            Tree *temp = new Tree();
            temp->x=n.x;
            temp->idx=n.idx;
            root->left=temp;
            return;
        }
        else{insertTree(root->left,n);}
    }
}
void deleteTree(Tree * root){
    if(root->left!=nullptr)deleteTree(root->left);
    if(root->right!=nullptr)deleteTree(root->right);
    delete root;
}
void preorder(const Tree* root,vector<vector<int>>& n){
    n[0].push_back(root->idx+1);
    if(root->left!=nullptr)preorder(root->left,n);
    if(root->right!=nullptr)preorder(root->right,n);
}
void postorder(const Tree* root,vector<vector<int>>& n){
    if(root->left!=nullptr)postorder(root->left,n);
    if(root->right!=nullptr)postorder(root->right,n);
    n[1].push_back(root->idx+1);
}

vector<vector<int>> solution(vector<vector<int>> n) {
    vector<vector<int>> answer(2);
    vector<node> v;
    for(int i=0; i<n.size(); i++){
        int x=n[i][0], y=n[i][1];
        v.emplace_back(x,y,i);
    }
    sort(v.begin(),v.end());
    Tree *root = new Tree();
    root->x=v[0].x;
    root->idx=v[0].idx;
    for(int i=1; i<v.size(); i++)insertTree(root,v[i]);
    preorder(root,answer);
    postorder(root,answer);

    deleteTree(root);
    return answer;
}