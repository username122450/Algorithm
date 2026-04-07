#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// struct cmp{
//     bool operator()(int a,int b){
//         return a>b;
//     }
// }
int smallestDifference(vector<int>& a, vector<int>& b) {
    int asize = a.size();
    int bsize = b.size();
    cout << "sort"<<endl;
    sort(a.begin(),a.end(),less());
    sort(b.begin(),b.end(),less());
    long long min = abs(a[0]- b[0]);
    int l = 0,r = 0;
    long long diff;
    while(l < asize && r < bsize){
        cout <<l << " "<<r<<endl;
        diff = abs(a[l] - b[r]);
        if(diff == 0) return 0;
        if(diff < min){ 
            min = diff;
            // cout << min <<endl;
        }
        if(a[l] < b[r])l++;
        else r++;
    }

    return min;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n,0);
    vector<int > b(n,0);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    int ans = smallestDifference(a,b);
    cout << ans;
    return 0;
}