#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n) {
    if(n < 2) return 0;
    vector<bool> flag(n,0);
    vector<int> primes;
    for(int i = 2;i < n;i++){
        if(flag[i] == 0){
            primes.push_back(i);
            flag[i] = 1;
            
        }
        for(int j = 0;j < primes.size();j++){
            int t = primes[j] *i;
            if(t >= n) break;
            flag[t] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    return primes.size();
}

int main(){
    int n;
    cin >> n;
    int sum = countPrimes(n);
    cout << sum;
    return 0;

}
