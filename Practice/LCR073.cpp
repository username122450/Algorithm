#include<iostream>
#include<vector>

using namespace std;

int calculate(vector< int > piles,int v,int h){
    int sum = 0;
    for(int i = 0;i < piles.size() ;i++){
        sum+=piles[i]/v;
        if(piles[i]%v != 0)sum++;
        if(sum > h) return sum;
    }
    return sum;
}
int main(){
    int n,num,h,max = 0;
    cin >> n >> h;
    vector< int > piles(n);
    for(int i = 0;i < n;i++){
        cin >> num;
        if(num > max) max = num;
        piles[i] = num;
    }
    int l = 1,r = max,mid,t,ans = max;
    while(l <= r){
        mid = (l+r)/2;
        t = calculate(piles,mid,h);
        if(t <= h){
            ans = mid;
            r = mid-1;
        }else l = mid+1;
    }
    cout << ans;

    return 0;
}