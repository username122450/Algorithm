#include<iostream>
#include<vector>

using namespace std;

bool isArraySpecial(vector<int>& nums) {
    int l = 0,r = 1;
    vector<int> t(2,0);
    while(r < nums.size()){
        t[nums[l]%2]++;
        t[nums[r]%2]++;
        if(t[0] != 1 && t[1] != 1) return false;
        t[0] = 0;
        t[1] = 0;
        l++;
        r++;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    bool ans = isArraySpecial(nums);
    cout << ans<<endl;

    return 0;
}