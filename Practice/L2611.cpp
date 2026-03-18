#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
    int n,k,num;
    cin >> n >> k;
    vector< int > reward1(n,0),reward2(n,0);
    for(int i  =0;i < n;i++){
        cin >> num;
        reward1[i] = num;
    }
    for(int i = 0;i < n;i++){
        cin >> num;
        reward2[i] = num;
    }
    int sum = 0;

    for(int i = 0;i < reward2.size();i++){
        sum+= reward2[i];
    }

    priority_queue<int> diff;

    for(int i = 0; i <n;i++){
        diff.push(reward1[i] - reward2[i]);
    }

    for(int i = 0;i < k; i++){
        sum+=diff.top();
        diff.pop();
    }
    return sum;

    






    return 0;
}