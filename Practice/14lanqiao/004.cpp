#include<iostream>
#include<vector>

using namespace std;

int getAns(vector<int>& a,vector<int>& b){
    int n = a.size(),m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,100001)); 
    for(int i = 0;i <= n;i++)dp[i][0] = 0;
    for(int i = 0;i <= m;i++)dp[0][i] = 0;
    int i = 1,j =1;
    while(i <= n,j <= m){
        if(a[i] == b[j]){
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            i++;
            j++;
        }
        else if(a[i] < b[j]){
            a[i+1] += a[i];
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            i++;
        }else{
            b[i+1]+=b[i];
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            j++;
        }
    }
    return dp[n][m];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1,0),b(m+1,0);
    for(int i = 1;i <= n;i++){
        cin >>a[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> b[i];
    }
    int ans = getAns(a,b);
    cout << ans;
    return 0;
}