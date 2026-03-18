#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int n,num;
    cin >> n;
    vector< int > v;
    for(int i = 0;i < n;i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    long long sum = 0,h=0;
    int l = 0,r = v.size()-1;
    while(l <= r){
        sum += (v[r] - h)*(v[r] - h);
        h = v[r];
        r--;
        sum += (h - v[l])*(h - v[l]);
        h = v[l];
        l++;
    }
    cout << sum;
    return 0;
}