#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int maximumPossibleSize(vector<int>& nums) {
    int nsize = nums.size();
    if(nsize == 1) return 1;
    stack<int> s;
    s.push(nums[nsize-1]);
    int t;
    for(int i = nsize-2;i >= 0;i--){
        while(!s.empty()){
            t = s.top();
            if(t< nums[i])s.pop();
            else break;
        }
        s.push(nums[i]);
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans.size();

}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    int ans = maximumPossibleSize(nums);
    cout << ans;
    return 0;
}