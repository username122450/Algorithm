#include<iostream>
#include<vector>

using namespace std;

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int nsize = nums.size();
    int qsize = queries.size();
    long long sum = 0;
    for(int i = 0;i < nsize;i++){
        sum += nums[i];
    }
    if(sum ==0) return 0;
    for(int i = 0;i <qsize;i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];
        for(int j = l;j <= r;j++){
            int minn = min(nums[j],val);
            nums[j]-=minn;
            sum-=minn;
        }
        if(sum == 0) return i+1;
    }
    return -1;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> nums(n,0);
    vector<vector<int>> queries(m,vector<int>(3,0));
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < 3;j++){
            cin >> queries[i][j];
        }
    }
    int ans = minZeroArray(nums,queries);
    cout << ans;
    return 0;
}