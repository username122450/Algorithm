#include<iostream>
#include<string>
using namespace std;

int main(){
    long long cn2 = 0,cn20 = 0,cn202 = 0,ans = 0;
    for(int i = 1;i <= 2023;i++){
        string s = to_string(i);
        for(char t:s){
            if(t == '2') {
                cn2++;
                cn202+=cn20;
            }
            else if(t == '0') cn20+=cn2;
            else if(t == '3') ans+=cn202;
        }
    }
    cout << ans;
    return 0;
}