#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct cmp{
    bool operator () (string s1,string s2){
        if(s1.size() != s2.size()) return s1.size() < s2.size();
        return s1 < s2;
    }
};
string kthLargestNumber(vector<string>& nums, int k) {
    priority_queue<string,vector<string> ,cmp> q;
    // q.push(nums[i]);
    
    for(string num:nums){
        q.push(num);
        // cout << "当前最大是" << q.top()<<endl;
    }
    
    int size = q.size();
    for(int i = 0;i < k-1;i++){//删除前k-1个数据
        // cout << "删除" << q.top() << endl;
        q.pop();
        // cout << "当前最大是" << q.top()<<endl;
    }
    return q.top();

}

int main(){
    int n,k;
    cin >> n >> k;

    vector<string> nums(n,"");
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    string ans = kthLargestNumber(nums,k);
    cout << ans;
    return 0;
}