#include<iostream>
#include<vector>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int nsize = nums.size();
    vector<int> sum(nsize+1,0);
    for(int i = 1;i <= nsize;i++){
        sum[i] = sum[i-1]+nums[i-1];
    }
    int t;
    for(int i = 2;i <= nsize;i++){
        for(int j = i;j <= nsize;j++){
            t = sum[j] - sum[j-i];
            cout << t/k << " " << t%k <<endl;
            if(t % k == 0)return true;
        }
    }
    return false;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    bool ans = checkSubarraySum(nums,k);
    cout << ans;
    return 0;

}

int kmp(){
    string s1;
    string s2;
    int l1 = s1.size();
    int l2 = s2.size();
    if(l2 > l1) return -1;
    if(l2 == 0) return -1;
    for(int i = 0,j = 0;i <= l1-l2 && j < l2;i++){
        if(s1[i] == s2[j]) {
            j++;
            if (j == l2-1) return i-j;
        }
        else j = 0,i--;
    }
    return -1;
}