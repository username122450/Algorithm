#include<iostream>
#include<vector>
using namespace std;


long long calculate(int h,vector<int >& th){
    long long sum = 0;
    for(int i = 0;i < th.size();i++){
        if(th[i] > h) sum+=th[i]-h;
    }

    return sum;
}

int main(){
    int n,m,num,max = 0;
    cin >> n >> m;
    vector< int > th(n);
    for(int i = 0;i < n;i++){
        cin >> num;
        th[i] = num;
        if(num > max) max = num;
    }
    
    if(m == 0) {
        cout << max ;
        return 0;
    }

    int l = 1,r = max,mid ,res;
    while(l <= r){
        mid = l + (r-l)/2;
        long long sum = calculate(mid,th);
        if(sum >= m ){
            res = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout << res;





    return  0;
}