#include<iostream>
#include<vector>
using namespace std;


long long countCompleteDayPairs(vector<int>& hours) {
    int hsize = hours.size();
    vector<long long> nums(24,0);
    for(int i = 0;i < hsize;i++){
        nums[hours[i]%24]++;
    }
    long long ans = 0;
    if(nums[0]!= 0) ans += ((long long)(nums[0]-1)*nums[0])/2;
    if(nums[12]!= 0)ans += ((long long)(nums[12]-1)*nums[12])/2;
    for(int i = 1;i < 12;i++){
        int t = 24-i;
        int x = nums[i],y = nums[t];
         ans+=(long long)x * y;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> hours(n,0);
    for(int i = 0;i < n;i++){
        cin >> hours[i];
    }
    long long ans = countCompleteDayPairs(hours);
    cout <<ans;
    return 0;
}