#include<iostream>
#include<vector>

using namespace std;
int minOperations(string s1, string s2, int x) {
    int ssize = s1.size();
    vector<int> cnt(2,0);
    for(int i = 0;i < ssize;i++){
        if(s1[i] == '1') cnt[0]++;
        if(s2[i] == '1')cnt[1]++;
    }
    if(cnt[0] != cnt[1])return-1;
    int count = 0;
    vector<vector<int>> dp(ssize+1,vector<int>(ssize+1,0));
    for(int i = 1;i <= ssize;i++){
        for(int j = 1;j <= ssize;j++){
            if(s1[i] == s2[i])dp[i][j] = dp[i-1][j-1];
            else{
                
            }
        }
    }

}
int main(){
    string s1,s2;
    int x;
    cin >>s1>>s2>>x;
    int ans = minOperations(s1,s2,x);
    cout <<ans;
    return 0;
}