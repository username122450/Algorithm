#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int xsize = mat.size(),ysize = mat[0].size();
    vector<vector<int>> ans(xsize,vector<int>(ysize,0));
    vector<vector<int>> sum(xsize+1,vector<int>(ysize+1,0));
    for(int i = 1;i <= xsize;i++){
        for(int j = 1;j <= ysize;j++){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i-1][j-1];
        }
    }
    for(int i = 1;i <= xsize;i++){
        for(int j = 1;j <= ysize;j++){
            cout << sum[i][j] << " ";
        }
        cout <<endl;
    }
    for(int i = 0;i < xsize;i++){
        for(int j = 0;j < ysize;j++){
            int tl = max(0,i-k);
            int tr = max(0,j-k);
            int el = min(xsize-1,i+k);
            int er = min(ysize-1,j+k);
            
            ans[i][j] = sum[el+1][er+1] - sum[el+1][tr] - sum[tl][er+1]+sum[tl][tr];           
        }
    }
    return ans;
}
int main(){
    int m, n ,k;
    cin >> m>> n >> k;
    vector<vector<int>> mat(m,vector<int>(n,0));
    for(int i = 0;i < m;i ++){
        for(int j = 0;j < n;j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> ans = matrixBlockSum(mat,k);
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}