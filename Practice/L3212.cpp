#include<iostream>
#include<vector>

using namespace std;

int numberOfSubmatrices(vector<vector<char>>& grid) {
    int xside = grid.size(),yside = grid[0].size();
    vector<vector<int>> nums(xside,vector<int>(yside,0));
    vector<vector<int>> sum(xside+1,vector<int>(yside+1,0));
    vector<vector<int>> onum(xside+1,vector<int>(yside+1,0));
    for(int i = 0;i < xside;i++){
        for(int j = 0; j < yside;j++){
            if(grid[i][j] == 'X') nums[i][j] = 1;
            else if(grid[i][j] == 'Y') nums[i][j] = 2;
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j]-sum[i][j] + nums[i][j];
            if(nums[i][j] == 0) onum[i+1][j+1]++;
            onum[i+1][j+1] +=onum[i][j+1]+onum[i+1][j]-onum[i][j]; 
        }
    }
    int size = 0;
    int ans = 0;
    for(int i = 1;i <= xside;i++){
        for(int j =1 ;j <= yside;j++){
            size = i*j - onum[i][j];
            if(size == 0) continue;
            if(sum[i][j] *2 /size  == 3 && sum[i][j]*2%size == 0) ans++;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m,' '));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    int ans = numberOfSubmatrices(grid);
    cout << ans;

    return 0;
}