#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct cmp{
    bool operator ()(pair<int,int> p1,pair<int,int>p2){
        return p1.first<p2.first;
    }
};

int minStoneSum(vector<int>& piles, int k) {
    int psize = piles.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
    for(int i = 0;i < psize;i++){
        q.push({piles[i],i});
    }
    for(int i = 0;i < k;i++){
        pair<int,int> t = q.top();
        q.pop();
        piles[t.second] -= floor(t.first/2);
        q.push({piles[t.second],t.second}); 
    }
    int ans = 0;
    for(int i = 0;i < psize;i++){
        ans+=piles[i];
    }
    return ans;

}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> piles(n,0);
    for(int i = 0;i < n;i++){
        cin >> piles[i];
    }
    int ans = minStoneSum(piles,k);
    cout << ans;
    return 0;
}