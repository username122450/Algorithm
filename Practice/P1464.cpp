#include<iostream>
#include<vector>

using namespace std;

struct node{
    long long x,y,z;
};

long long w(node t,vector<vector<vector<long long>>>& mem){
    if(t.x <=0 || t.y <= 0|| t.z <= 0) return 1;
    else if(t.x > 20 || t.y > 20 || t.z > 20) return w({20,20,20},mem);
    if(mem[t.x][t.y][t.z] != -1) return mem[t.x][t.y][t.z];
    else if(t.x < t.y && t.y < t.z) {
        // if(mem[t.x][t.y][t.z-1] == -1){
        //     mem[t.x][t.y][t.z-1] = w({t.x,t.y,t.z-1},mem);
        // }
        // if(mem[t.x][t.y-1][t.z-1] == -1){
        //     mem[t.x][t.y-1][t.z-1] = w({t.x,t.y-1,t.z-1},mem);
        // }
        // if(mem[t.x][t.y-1][t.z]==-1){
        //     mem[t.x][t.y-1][t.z] = w({t.x,t.y-1,t.z},mem);
        // } 
        // return mem[t.x][t.y][t.z-1] + mem[t.x][t.y-1][t.z-1] - mem[t.x][t.y-1][t.z];

        mem[t.x][t.y][t.z] = w({t.x,t.y,t.z-1},mem) + 
                            w({t.x,t.y-1,t.z-1},mem) -
                            w({t.x,t.y-1,t.z},mem);
        
    }
    else {
        // if(mem[t.x-1][t.y][t.z] == -1){
        //     mem[t.x-1][t.y][t.z] = w({t.x-1,t.y,t.z},mem);
        // }
        // if(mem[t.x-1][t.y-1][t.z] == -1){
        //     mem[t.x-1][t.y-1][t.z] = w({t.x-1,t.y-1,t.z},mem);
        // }
        // if(mem[t.x-1][t.y][t.z-1] == -1){
        //     mem[t.x-1][t.y][t.z-1] = w({t.x-1,t.y,t.z-1},mem);
        // }
        // if(mem[t.x-1][t.y-1][t.z-1] == -1){
        //     mem[t.x-1][t.y-1][t.z-1] = w({t.x-1,t.y-1,t.z-1},mem);
        // }
        // return mem[t.x-1][t.y][t.z]+mem[t.x-1][t.y-1][t.z]+mem[t.x-1][t.y][t.z-1]-mem[t.x-1][t.y-1][t.z-1];
        mem[t.x][t.y][t.z] = w({t.x-1,t.y,t.z},mem) +
                            w({t.x-1,t.y-1,t.z},mem) +
                            w({t.x-1,t.y,t.z-1},mem) -
                            w({t.x-1,t.y-1,t.z-1},mem);
    }
    return mem[t.x][t.y][t.z];
}

int main(){

    vector<node> v;
    long long x,y,z;
    while(1){
        cin >> x >> y >> z;
        if(x == y  && y== z && z == -1) break;
        v.push_back({x,y,z});
    }

    vector<vector<vector<long long>>> mem(21,vector<vector<long long>>(21,vector<long long>(21,-1)));

    for(int i = 0;i < v.size();i++){
        cout << "w(" << v[i].x << ", " << v[i].y << ", " << v[i].z << ") = " << w(v[i],mem)<<endl;
    }

    
    return 0;
}