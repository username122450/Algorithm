#include<iostream>
#include<vector>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(2*n,0);
    int sum = 0;
    for(int i = 0;i < n;i++){
        ans[sum++] = nums[i];
        ans[sum++] = nums[i+n];
    }
    return ans;
}

int main(){
    int n;
    vector<int> nums(2*n,0);
    for(int i = 0;i < 2*n;i++){
        cin >> nums[i];
    }

    vector<int> ans = shuffle(nums,n);
    for(int i = 0;i < 2*n;i++){
        cout << nums[i];
    }



    return 0;
}