#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size(),m = grid[0].size();
    vector<vector<pair<int,int>>> flag(n,vector<pair<int,int>>(m,{0,0}));
    for(int l = 0;l < m/2;l++){
        int r = m-1-l;
        int t = l;
        int e = n-1-t;
        int x = t,y = l;
        int count = 0;
        while(count < (r-l)*4){
            int diff = t % ((r-l)*4);
            int tx = x,ty = y;
            if(y != l && x  == t){
                while(ty<=r && diff-- !=0) ty++;
                while(tx <= t && diff-- !=0) tx++;
                while(ty>=l && diff-- != 0) ty--;
                while(tx >= t && diff-- != 0)tx--;
                flag[x][y] = {tx,ty};
                y--;
            }
            else if(y != l && x == e){
                while(ty>=l && diff-- != 0) ty--;
                while(tx <= t && diff-- !=0) tx++;
                while(ty<=r && diff-- !=0) ty++;
                while(tx >= t && diff-- != 0)tx--;
                flag[x][y] = {tx,ty};
                y++;
            }
            else if(x !=t && y == l){
                while(tx <= t && diff-- !=0) tx++;
                while(ty<=r && diff-- !=0) ty++;
                while(tx >= t && diff-- != 0)tx--;
                while(ty>=l && diff-- != 0) ty--;
                flag[x][y] = {tx,ty};
                x--;
            }
            else{
                while(tx >= t && diff-- != 0)tx--;
                while(ty>=l && diff-- != 0) ty--;
                while(tx <= t && diff-- !=0) tx++;
                while(ty<=r && diff-- !=0) ty++;
                flag[x][y] = {tx,ty};
                x++;
            }
            count++;
        }
    }
    for(int i = 0;i < n;i++){
        int temp = grid[i][i];
        for(int j = 0;j < m;j++){
            if(flag[i][j].first == i && flag[i][j].second == i) grid[i][j] = temp;
            else grid[i][j] = grid[flag[i][j].first][flag[i][j].second];
        }
    }
    return grid;
}
int main(){
    int n,m,k;
    cin >>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ans = rotateGrid(grid,k);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << ans[i][j] <<" ";

        }
        cout << endl;
    }

    return 0;
}