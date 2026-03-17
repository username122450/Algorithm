#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

vector< int > init(string s1,int len){
    vector< int > res(len,0);
    int size = s1.size();
    for(int i = 0;i < size;i++){
        res[i] = s1[size-1-i] - '0';
    }
    return res;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    if(s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)){
        swap(s1,s2);
    }
    int len = s1.size()+ 1;
    vector< int > v1 = init(s1,len-1);
    vector< int > v2 = init(s2,len-1);
    vector< int > ans(len,0);
    for(int i = 0;i < len - 1;i++){
        int num = v1[i] + v2[i];
        ans[i]+= num;
        if(ans[i] >= 10){
            ans[i] -=10;
            ans[i+1]++;
        }
    }
    int index = len-1;
    while(ans[index] == 0 & index >0){
        index -- ;
    }
    for(int i = index;i >= 0;i--){
        // cout << i << ": " << ans[i]<<endl;
        cout <<ans[i] ;
    }
    return 0;
}

