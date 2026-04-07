#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> vf(n+1,vector(n+1,0));
    vector<vector<int>> v(n+1,vector<int>(2,0));
    vector<int> w(n+1,0);
    for(int i = 1;i <= n;i++){
        cin >> w[i];
        w[i] += w[i-1];
    }
    int start,end;
    for(int i = 1;i <= m;i++){
        cin >> start >> end;
        vf[start][end] ++;
        vf[end][start] ++;
        v[i][0] = start;
        v[i][1] = end;
    }
    long long ans = LONG_LONG_MAX,diff ;
    for(int i = 1;i <= m;i++){
        start = v[i][0];
        end = v[i][1];
        if(vf[start][end] == 1) {
            diff = abs(w[n]-2*w[min(start,end)]);
            if(diff < ans)ans = diff;
        }
    }
    if(ans == LONG_LONG_MAX) cout << -1;
    else cout << ans;
    return 0;
}