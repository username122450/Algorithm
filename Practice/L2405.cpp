#include<iostream>
#include<vector>

using namespace std;

int partitionString(string s) {
    if(s.size() == 0) return 0;
    int ans = 1;
    vector<int> flag(27,0);
    for(char t:s){
        if(flag[t-'a'] == 0){
            flag[t-'a']++;
        }else{
            ans++;
            for(int i = 0;i < 27;i++){
                flag[i] = 0;
            }
            flag[t-'a']++;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >>s;
    int ans = partitionString(s);
    cout << ans;
    return 0;
}