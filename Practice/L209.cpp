#include<iostream>
#include<vector>
using namespace std;

int main(){
    int target,n,num;
    cin >>target >> n;
    vector< int > nums(n);
    for(int i = 0;i < n;i++){
        cin >> num;
        nums[i] = num;
    }
    int l = 0,r = 0,sum = 0,Len = 0,min = 100000;
    while(r < n){
        sum+=nums[r];
        Len++;
        while(l <= r &&sum >= target){
            if(Len < min) min = Len;
            sum -= nums[l];
            l++;
            Len--;
        }
        r++;
    }
    if(min == 10000) cout<<0;
    else cout << min;
    return 0;
}