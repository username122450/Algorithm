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
    int len = s1.size()+ s2.size()+ 1,product;
    vector< int > v1 = init(s1,len-1);
    vector< int > v2 = init(s2,len-1);
    vector< int > ans(len,0);
    for(int i = 0;i < s2.size();i++){
        for(int j = 0;j < s1.size();j++){
            product = v1[j] * v2[i];
            ans[i+j] += product;
            if(ans[i+j] >=10){
                ans[i+j+1]+= ans[i+j]/10;
                ans[i+j] %= 10;
            }
        }
    }
    int index = len-1;
    while(ans[index] == 0 & index >0){
        index -- ;
    }
    for(int i = index;i >= 0;i--){
        cout <<ans[i] ;
    }
    return 0;
}

