#include<iostream>
#include<vector>

using namespace std;

int digui(int A,int B,int num){
    if(B == 0) return 0;
    if(B % 2 == 1) {
        return (A << num) + digui(A,B>>1,num+1);
        //思路参考快速幂
    }else {
        return digui(A,B>>1,num+1);
    }
}

int multiply(int A, int B) {
    return digui(A,B,0);
}
int main(){
    int A,B;
    cin >> A >> B;
    int ans = multiply(A,B);
    return 0;
}
