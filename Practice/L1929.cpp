#include<iostream>
#include<vector>

using namespace std;
vector<int> getConcatenation(vector<int>& nums) {
    int size = nums.size();
    vector<int > doubleNum(2*size,0);
    for(int i = 0;i <size;i++){
        doubleNum[i] = doubleNum[i+size] = nums[i];
    }
    return doubleNum;
    }

int main(){
    int n,num;
    cin >> n;
    vector<int> nums;
    for(int i = 0;i < n;i++){
        cin >> num;
        nums[i] = num;
    }
    getConcatenation(nums);
    return 0;
}