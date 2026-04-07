#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    vector<int> flag(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
        flag[i]++;
    }
    int count =0;
    for(int i = 0;i < n;i++){
        if(flag[i] == 2 || flag[i] == 0) continue;
        if(flag[i] == 1)count++;
        else count+= flag[i]-2;
    }
    cout << count /2 ;


    return 0;
}