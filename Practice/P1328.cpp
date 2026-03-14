#include<iostream>
#include<vector>
using namespace std;

int rs[5][5] = {
    {-1,1,0,0,1},
    {0,-1,1,0,1},
    {1,0,-1,1,0},
    {1,1,0,-1,0},
    {0,0,1,1,-1}
};

int main(){
    vector< int > res(2,0);
    int n,w1,w2,s1,s2,num;
    cin >> n >> w1 >> w2;
    vector< int > statue1(w1);
    vector< int > statue2(w2);
    for(int i = 0;i < w1;i++){
        cin >> num;
        statue1[i] = num;
    }
    for(int i = 0 ;i < w2;i++){
        cin >> num;
        statue2[i] = num;
    }
    for(int i = 0;i < n;i++){
        s1 = i % w1;
        s2 = i % w2;
        if(statue1[s1] == statue2[s2]) continue;
        else{
            res[rs[statue1[s1]][statue2[s2]]]++;
        }
    }
    cout << res[0] << " " << res[1] << endl;
    return 0; 
}
