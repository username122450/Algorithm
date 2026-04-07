#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node{
    int x;
    int y;
    int count;
};

int bfs(vector<vector<char>>& mapp,int k,int num){
    int n = mapp.size(),m = mapp[0].size();
    vector<vector<bool>> flag(n+1,vector(m,false));
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int i = 1,j = 1;
    queue<node> q;
    q.push({0,0,0});
    while(!q.empty()){
        node t = q.front();
        int x = t.x,y = t.y, count= t.count;
        flag[x][y] = 1;
        count++;
        if(count == 6)count = 0;
        q.pop();
        for(int i = 0;i < 4;i++){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx >=1 && tx <=n &&ty>=1 && ty <=m && flag[tx]){
                if(count >=0 && count <= 3 && mapp[tx][ty] == 'A'){
                    q.push({tx,ty,count});
                }else if(count >= 3 &&count < 6 && mapp[tx][ty] == 'B'){
                    q.push({tx,ty,count});
                }
            }
        }
    }
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>> mapp(n+1,vector(m,' '));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> mapp[i][j];
        }
    }
    int ans = dfs(mapp,k,0);
    cout << ans;
    return 0;
}