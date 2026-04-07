#include<iostream>
#include<vector>
using namespace std;
bool carPooling(vector<vector<int>>& trips, int capacity) {
    int tsize = trips.size();
    vector<int> sum(1001,0);
    for(int i = 0;i <tsize;i++){
        if(trips[i][1]>trips[i][2])return false;
        if(trips[i][0]>capacity)return false;
        sum[trips[i][1]]+=trips[i][0];//表示在trips[i][1]位置上上车trips[i][0]个乘客
        sum[trips[i][2]]-=trips[i][0];//表示在trips[i][2]位置上上车trips[i][0]个乘客
    }
    for(int i = 1;i < 1001;i++){
        sum[i] = sum[i]+sum[i-1];
        if(sum[i]>capacity)return false;
    }
    return true;
}

int main(){
    int n,capacity;
    cin >> n>> capacity;
    vector<vector<int>> trips(n,vector(3,0));
    for(int i = 0;i < n;i++){
        cin >> trips[i][0]>>trips[i][1]>>trips[i][2];
    }
    bool ans = carPooling(trips,capacity);
    cout <<ans;
    return 0;
}