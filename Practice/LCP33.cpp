#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int storeWater(vector<int>& bucket, vector<int>& vat) {
    int size = bucket.size();
    int ans = 0;
    for(int i = 0;i < size;i++){
        
    }
    return ans;

}

int main(){
    int n,num;
    cin >> n;
    vector<int> bucket(n,0);
    vector<int> vat(n,0);
    for(int i = 0;i < n;i++){
        cin >> num;
        bucket[i] = num;
    }
    for(int i = 0;i < n;i++){
        cin >> num;
        vat[i] = num;
    }

    int ans = storeWater(bucket,vat);
    cout << ans <<endl;

    return 0;
}