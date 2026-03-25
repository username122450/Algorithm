#include<iostream>
#include<vector>
using namespace std;

vector<int> getPrime(int n){
    vector< int > isprime(n,0);
    vector<int> prime;
    int sum = 0;
    for(int i = 2;i < n;i++){
        if(isprime[i] == 0){
            sum++;
            prime.push_back(i);
        }
        for(int j = 0;j < sum;j++){
            int a = prime[j]*i;
            if( a >= n) break;
            isprime[a] = 1;
            if(i % prime[j] == 0) break;

        }
    }
    return prime;
}

void insert(vector<vector<int>>& ans,int l,int r){
    vector<int> x(2);
    x[0] = l;
    x[1] = r;
    ans.push_back(x);
    cout << l << "=>" << r << endl;
}

vector<vector<int>> findPrimePairs(int n) {
    vector<vector<int>> ans;
    if(n <= 3) return ans;
    vector< int > prime = getPrime(n);
    int l = 0,r = prime.size()-1;
    while(l <= r){
        int a = prime[l]+prime[r];
        if(a == n) {
            insert(ans,prime[l],prime[r]);
            l++;
            r--;
            if(l > r)break;
        }else if(a < n){
            l++;
        }else r--;
    }
    return ans;  
}

int main(){
    int n ;
    cin >> n ;
    vector<vector<int>> ans = findPrimePairs(n);
    return 0;
}