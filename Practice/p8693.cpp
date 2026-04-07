#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct node{
    int x,y;
    int r;
    int time;
};

bool isTrue(int nx,int ny,int nr,vector<string>& mapp){
    int s = mapp.size();
    for(int i = nx-nr;i <= nx+nr;i++){
        if(i < 0 || i >= s) return 0;
        for(int j  =ny-nr;j <= ny+nr;j++){
            if(j < 0 || j >= s || mapp[i][j] == '*') return 0;
        }
    }
    return 1;
}

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    vector<string> mapp(n);
    for(int i = 0;i < n;i++){
        cin >> s;
        mapp[i] = s;
    }
    vector<vector< bool>> flag(n,vector<bool>(n,0));

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    queue<node> q;
    q.push({2,2,2,0});
    flag[2][2] = 1;
    int endx = n-3,endy = n-3;
    while(!q.empty()){
        node now = q.front();
        q.pop();
        //结束条件
        if(now.x == endx && now.y == endy ){
            cout << now.time <<endl;
            break;
        }
        //原地条件
        
        if(now.r > 0 ){
            int nt = now.time+1;
            int nr;
            if(nt < k) nr = 2;
            else if(nt >= k && nt < 2* k )nr = 1;
            else nr = 0;
            q.push({now.x,now.y,nr,nt});
        }

        for(int i = 0;i < 4;i++){
            int nx = now.x+dx[i];
            int ny = now.y+dy[i];   
            if(isTrue(nx, ny, now.r, mapp) && !flag[nx][ny]){
                flag[nx][ny] = true;
                int nt = now.time + 1;
                int nr;
                if(nt < k) nr = 2;
                else if(nt < 2*k) nr = 1;
                else nr = 0;
                q.push({nx, ny, nr, nt});
            }
        }
    }
    return 0;
}