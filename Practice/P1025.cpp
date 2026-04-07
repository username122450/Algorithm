#include<iostream>
#include<vector>

using namespace std;

int dfs(int start,int end,int k,int n,int ans){
    if(k == 1){
        if(n >= start && n <= end){
            return ans+1;
        }else return ans;
    }
    for(int i = start;i <= end;i++){
        if(i > n) break;
        ans = dfs(i,n-i-k+2,k-1,n-i,ans);
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;

    int ans = dfs(1,n-k+1,k,n,0);
    cout << ans;

    return 0;
}