#include<iostream>

using namespace std;


int main(){
    long long ans,a,b,p;
    cin >> a>>b>>p;
    long long res = 1;
    long long x = a,n = b;
    while(n != 0){
        if(n % 2 == 1)res = (res* x)%p;
        n /= 2;
        x = (x * x)%p;
    }
    res %= p;
    cout << a<<"^"<<b<<" mod "<<p<<"="<<res;
    return 0;
}