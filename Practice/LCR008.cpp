#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,num,listNum;
    cin >> n >> listNum;
    vector< int > nums(listNum+1);
    for(int i = 1;i <=listNum;i++){
        cin >> num;
        nums[i] = num;
    }
    int l = 1,r=1,sum = 0,Len = 0,min = 10000;
    while(r <= listNum){
        sum+=nums[r];
        r++;
        while(sum - nums[l]>= n){
            sum-=nums[l];
            Len--;
            l++;
        }
        if(sum >= n && r-l+1 < min) min = r-l+1;
    }
    if(min == 10000) cout << 0;
    else cout << min;
    return 0;
}
/*
7 6
2 3 1 2 4 3
*/
