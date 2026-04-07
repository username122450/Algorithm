#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    vector<vector<int>> flag(m,vector<int>(n,0));
    int maxx = 0;

    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(grid[i][j] == 1 && flag[i][j] == 0){
                int tmax = 0;
                queue<pair<int ,int>> q;
                q.push({i,j});
                flag[i][j] = 1;
                tmax++;
                while(!q.empty()){
                    pair t = q.front();
                    q.pop();
                    for(int k = 0;k < 4;k++){
                        int tx = t.first+ dx[k];
                        int ty = t.second+ dy[k];
                        if(tx >=0 && tx < m && ty >= 0 && ty < n &&
                            grid[tx][ty] == 1 && flag[tx][ty] == 0){
                            q.push({tx,ty});
                            flag[tx][ty] = 1;
                            tmax++;
                        }
                    }
                }
                if(tmax > maxx)maxx = tmax;
            }

        }
    }
    return maxx;
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    int t;

    for(int i = 0;i < m;i++){
        for(int j = 0 ;j < n;j++){
            cin >> t;
            grid[i][j] = t;
        }
    }

    int maxx = maxAreaOfIsland(grid);
    cout << maxx;

    return 0;
}