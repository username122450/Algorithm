#include<iostream>
#include<string>
#include<vector>

using namespace std;

string reverseVowels(string s) {
    int ssize = s.size();
    vector<int> v;
    char temp[10] = {'a','A','e','E','i','I','o','O','u','U'};
    for(int i = 0;i < ssize;i++){
        for(int j = 0;j < 10;j++){
            if(s[i] == temp[j]){
                v.push_back(i);
                break;
            }
        }
    }
    int vsize = v.size();
    char t;
    for(int i = 0;i < vsize/2;i++){
        t = s[v[i]];
        s[v[i]] = s[v[vsize-1-i]];
        s[v[vsize-1-i]] = t;
    }
    return s;
}

int main(){
    string s;
    cin >> s;
    s = reverseVowels(s);
    cout << s;
    return 0;
}