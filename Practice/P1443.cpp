#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> flag(n,vector<int>(m,-1));

    vector<int> dx = {-2,-2,2,2,-1,-1,1,1};
    vector<int> dy = {-1,1,-1,1,-2,2,-2,2};

    x--;
    y--;
    flag[x][y] = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int, int> index = q.front();
        q.pop();
        int tx = index.first,ty = index.second;
        for(int i = 0;i < 8;i++){
            int tempx = tx+ dx[i],tempy = ty+dy[i];
            if(tempx>=0 && tempx < n && tempy >= 0 && tempy < m){
                if(flag[tempx][tempy] == -1){
                    q.push({tempx,tempy});
                    flag[tempx][tempy] = flag[tx][ty]+1;

                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << flag[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}