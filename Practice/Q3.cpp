#include<iostream>
#include<vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int size = nums.size();
    int ans = 0,maxx = 0;
    for(int i = 0;i< size;i++){
        if(nums[i] == 1){
            maxx++;
            if(maxx > ans)ans = maxx;
        }
        else maxx = 0;
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    int ans = findMaxConsecutiveOnes(nums);
    cout <<ans;
    return 0;
}