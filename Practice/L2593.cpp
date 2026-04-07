#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int data;
    int index;
};
struct cmp{
    bool operator ()(node n1,node n2){
        return n1.data > n2.data;
    }
};

long long findScore(vector<int>& nums) {
    long long ans = 0;
    vector<bool> flag(nums.size(),0);
    priority_queue<node,vector<node>,cmp> q;
    int size = nums.size();
    for(int i = 0;i < size;i++){
        q.push({nums[i],i});
    }
    while(!q.empty()){
        node n = q.top();
        q.pop();
        if(flag[n.index] == 0){
            flag[n.index] = 1;
            int l = n.index -1;
            int r = n.index +1;
            if( l>=0)flag[l] = 1;
            if(r < nums.size()) flag[r] = 1;
            ans+=n.data;
        }
    }
    return ans;

    
}
int main(){
    int n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    long long ans = findScore(nums);
    cout << ans;
    return 0;
}