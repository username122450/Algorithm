#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k,listNum,num;
    cin >> k >> listNum;
    vector< int > nums(listNum);
    for(int i = 0; i < listNum;i++){
        cin >>num;
        nums[i] = num;
    }

    if(k == 0) cout << 0;

    int l = 0,r = 0,res = 1,count = 0;
    while(r < listNum){
        res *= nums[r];
        while(l <= r && res >= k){
            res/=nums[l];
            l++;
        }
        count += r-l+1;
        r++;
    }
    cout << count;

    return 0;
}