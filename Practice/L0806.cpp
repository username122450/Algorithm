#include<iostream>
#include<vector>

using namespace std;

void hanota(int x,vector<int>& A, vector<int>& B, vector<int>& C) {
    if(x == 1) {
        int num = A.back();
        A.pop_back();
        B.push_back(num);
        return ;
    }
    hanota(x-1,A,C,B);
    int num = A.back();
    A.pop_back();
    B.push_back(num);
    hanota(x-1,C,B,A);
}

int main(){
    int n,num;
    cin >> n;
    vector< int> a,b,c;
    for(int i = 0;i < n;i++){
        cin >> num;
        a.push_back(num);
    }
    hanota(n,a,c,b);
    return 0;
}