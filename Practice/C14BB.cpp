#include<cmath>
#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main(){
    vector< int > flag(sqrt(23333333333333),0);
    int sum = 0;
    long long x;
    for(int i = 2;i < sqrt(23333333333333);i++){
        if(flag[i] == 0){
            sum++;
            flag[sum] = i;
        }
        for(int j = 1;j <= sum;j++){
            x = i * flag[j];
            if(x > sqrt(23333333333333))break;
            flag[x] = 1;
            if(i % flag[j] == 0) break;
        }
    }
    int min = 10000,max = 0;
    for(int i = 0;i < sum;i++){
        if(flag[i] * flag[i+1] > sqrt(2333)){
            min = i;
            break;
        }
    }
    for(int i = sum-2; i >=0;i--){
        if(flag[i] * flag[i+1] < sqrt(23333333333333)){
            max = i;
            break;
        }
    }
    cout<<"min:"<<min <<" "<<"max:"<<max<<endl;
    x = 1;
    for(int i = max;i >=max-1;i--){
        x*=i;
    }
    cout << x;
    
    return 0;
}