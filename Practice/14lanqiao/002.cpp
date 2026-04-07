#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int right = sqrt(23333333333333);
    cout << right<<endl;
    vector<int> zhishu;
    int sum = 0,count = 0;
    vector<int> flag(right+1,0);
    for(int i = 2;i <= sqrt(right);i++){
        if(flag[i] == 0){
            sum++;
            flag[i] = 1;
            zhishu.push_back(i);
        }
        for(int j = 0;j < sum;j++){
            int t = i*zhishu[j];
            if(t > right) break;
            if(flag[t] == 0) flag[t] = 1;
            if(i % zhishu[j] == 0) break;
        }
    }
    sum-=2;
    long long ans = (sum-1)*sum/2;
    cout <<ans;
    return 0;
}