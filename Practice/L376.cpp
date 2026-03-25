#include<iostream>
#include<vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    
        
}

int main(){
    int n,num;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin>> num;
        nums.push_back(num);
    }
    int maxx = wiggleMaxLength(nums);
    cout << maxx;

    return 0;
}