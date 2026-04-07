#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
string getSmallestString(int n, int k) {
    string ans = "";
    while(n != 0){
        int t = max(1,k-26*(n-1));
        ans+=(char)('a'+ t-1);
        k-=t;
        n--;
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n>> k;
    string ans = getSmallestString(n,k);
    cout <<ans;
    return 0;
}