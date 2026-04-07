#include<iostream>
#include<vector>

using namespace std;

int maxAscendingSum(vector<int>& nums) {
    int maxSum = nums[0],tmax = nums[0];
    for(int i = 1;i < nums.size();i++){
        if(nums[i] > nums[i-1]){
            tmax += nums[i];
        }else tmax = nums[i];
        if(maxSum < tmax)maxSum = tmax;
    }
    return maxSum;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    int ans = maxAscendingSum(nums);
    cout << ans;

    return 0;
}