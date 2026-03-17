#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

vector< int > init(string s1){
    vector< int > res(s1.size(),0);
    for(int i = 0;i < s1.size();i++){
        res[i] = s1[i] - '0';
    }
    return res;
}

bool judgment(vector< int > s1,vector< int > s2){
    while (s1.size() > 1 && s1[0] == 0) s1.erase(s1.begin());
    while (s2.size() > 1 && s2[0] == 0) s2.erase(s2.begin());
    if(s1.size() != s2.size()) return s1.size() > s2.size()? true:false;
    for(int i = 0;i < s1.size();i++){
        if(s1[i]!=s2[i]) return s1[i] > s2[i]? true:false;
    }
    return true;
}

vector< int > sub(vector< int >& s1,vector< int >& s2){
    while (s1.size() > 1 && s1[0] == 0) s1.erase(s1.begin());
    while (s2.size() > 1 && s2[0] == 0) s2.erase(s2.begin());
    int num;
    for(int i = s1.size()-1,j = s2.size()-1;j >= 0 ;i--,j--){
        num = s1[i]-s2[j];
        if(num < 0){
            s1[i-1]--;
            num+=10;
        }
        s1[i] = num;
    }
    while (s1.size() > 1 && s1[0] == 0) s1.erase(s1.begin());
    return s1;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    if(s1.size() < s2.size()) {
        cout<< 0;
        return 0;
    }else if(s1 == s2){
        cout << 1;
        return 0;
    }else if(s2 == "1"){
        cout << s1;
        return 0;
    }else if(s2 == "0"){
        cout << "∞";
        return 0;
    }else if(s1 == "0"){
        cout << 0;
        return 0;
    }

    vector< int > v1 = init(s1);
    vector< int > v2 = init(s2);
    vector< int > ans(s1.size(),0);
    vector< int > rem;

    for(int i = 0;i < v1.size();i++){
        rem.push_back(v1[i]);
        while(rem.size() > 1 && rem[0] == 0)rem.erase(rem.begin());
        int temp = 0;
        while(judgment(rem,v2)){
            temp++;
            sub(rem,v2);
        }
        ans[i] = temp;
    }

    while(ans.size() > 1 && ans[0] == 0) ans.erase(ans.begin());
    for(int i = 0;i < ans.size();i++){
        cout << ans[i];
    }

    
    return 0;
}