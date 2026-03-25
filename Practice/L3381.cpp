#include<iostream>
#include<vector>

using namespace std;

long long maxSubarraySum(vector<int>& nums, int k) {
    int size = nums.size();
    vector <long long> nums1(size,0);
    nums1[0] = nums[0];
    for(int i = 1;i < size;i++){
        nums1[i] = nums1[i-1]+nums[i];
        // cout << i << ":" << nums1[i]<<endl;
    }
    long long max = nums1[k-1],temp = 0;
    for(int j = k;j <=size;j+=k){
        cout<< j << endl;
        for(int i = j;i <= size;i++){
            if(i-j == 0) {
                temp = nums1[i-1];
                // cout <<"nums["<<i-1<<"]:"<<nums1[i-1] <<endl;
            }
            else {
                temp = nums1[i-1]-nums1[i-j-1];
                // cout <<"nums["<<i-1<<"]:"<<nums1[i-1] << "-" << "nums["<<i-j<<"]:"<<nums1[i-j]<<" = "<< temp<<endl;
            }
            
            if(max < temp) max = temp;
        }
    }
    
    
    return max;
}

int main(){
    int n,num,k;
    cin >> n >> k;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> num;
        nums[i] = num;
    }
    cout << maxSubarraySum(nums,k);
    return 0;
}