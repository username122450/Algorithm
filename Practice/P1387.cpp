#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m,num;
    cin >> n >> m;
    vector< vector< int> > nums(n+1,vector< int >(m+1,0));
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j++){
            cin >> num;
            nums[i][j] = num;
        }
    }
    vector< vector< int> > dis(n+1,vector< int >(m+1,0));
    dis[1][1] = nums[1][1];
    for(int i = 1;i <=n;i++){
        for(int j = 1;j <= m;j++){
            dis[i][j] = dis[i-1][j]+ dis[i][j-1]-dis[i-1][j-1]+nums[i][j];
        }
    }
    
    int min = n < m? n:m;
    int s,distence;
    while(min > 0){
        s = min *min;
        for(int i = min;i <= n;i++){
            for(int j = min;j <= m;j++){
                distence = dis[i][j]-dis[i-min][j]-dis[i][j-min]+dis[i-min][j-min];
                if(distence == s){
                    cout << min;
                    return 0;
                } 

            }
        }
        min--;

    }
    cout << 0;
    return 0;
}