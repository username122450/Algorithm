#include<iostream>
#include<vector>
using namespace std;
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int nsize = nums.size();
        sum = vector<int>(nsize+1,0);
        for(int i = 1;i <= nsize;i++){
            sum[i] = sum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right+1]-sum[left];
    }
};
int main(){

    return 0;
}
