#include<iostream>
#include<vector>
#include<queue>
#define nul -1

using namespace std;

typedef struct SNode{
    int index;
    int Weight;
    struct SNode *next;
    friend bool operator < (const SNode s1,const SNode s2){
        return s1.Weight > s2.Weight;
    }
}Side;

typedef struct Node{
    Side *next;
}GraphNode,*Graph;//这里用邻接表实现有权无向图

Side *CreateSide(int index,int Weight){
    Side *s = (Side *)malloc(sizeof(Side));
    s->index = index;
    s->Weight = Weight;
    s->next = NULL;
    return s;
}

void CreateNode(vector< Graph >& g,int num){
    GraphNode *s;
    for(int i = 0;i < num+1;i++){
        s = (GraphNode *)malloc(sizeof(GraphNode));
        s->next = NULL;
        g.push_back(s);
    }
}

vector< Graph > Insert(vector< Graph > g,int data1,int data2,int w){
    // cout << data1 << ":"<< index1 << "  "<< data2 << ":"<<index2<<endl;
    Side *p = CreateSide(data2,w);
    p->next = g[data1]->next;
    g[data1]->next = p;
    p = CreateSide(data1,w);
    p->next = g[data2]->next;
    g[data2]->next = p;
    return g;
}

void InitVector(vector< int >& dis,vector< int >& flag,vector< int >& pre,int num){
    for(int i = 0;i < num+1;i++){
        dis.push_back(10000);
        flag.push_back(0);
        pre.push_back(-1);
    }
}

void Dijkstra(vector< Graph > g,int num,int start){
    cout << "Dijkstra"<<endl;
    vector< int > dis;
    vector< int > flag;
    vector< int > pre;
    InitVector(dis,flag,pre,num);
    priority_queue< Side > q;

    dis[start] = 0;
    flag[start] = 1;
    Side *p = g[start]->next;
    while(p != NULL){
        q.push(*p);
        // cout << "push:" << p->Weight << endl;
        dis[p->index] = p->Weight;
        pre[start] = 0;
        p = p->next;
    }
    while(!q.empty()){
        Side s = q.top();
        q.pop();
        // cout << "pop:" << s.Weight << endl;
        if(flag[s.index] != 0) continue;
        flag[s.index] = 1;
        if(dis[pre[s.index]] + s.Weight < dis[s.index]){
            dis[s.index] = dis[pre[s.index]] + s.Weight;
        }
        p = g[s.index]->next;
        while(p != NULL){
            if(dis[p->index] > dis[s.index] + p->Weight ) {
                dis[p->index] = dis[s.index] + p->Weight;
                pre[p->index] = s.index;
                q.push(*p);//在判断更新后dis能更小就将side入队
            }
            p = p->next;
        }
        cout << start << "->" << s.index << ":"<< dis[s.index]<<endl;
    }
}

int main(){

    vector< Graph > g;
    int graphNum;
    cin >> graphNum;//这里是点的个数
    CreateNode(g,graphNum);
    int data1,data2,w;//插入的边两端的点
    cin >> graphNum;//这里是边的个数
    int index1,index2;
    for(int i = 0; i < graphNum;i++){
        cin >> data1 >> data2 >> w;
        g = Insert(g,data1,data2,w);
    }
    Dijkstra(g,graphNum,1);

    return 0;
}

/*
9
15
9 1 3
9 5 4
1 6 6
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 5 7
6 7 9
6 3 14
7 3 6
7 4 1
3 4 10
5 4 18
*/

/*
7
8
1 2 1
1 4 3
1 5 8
2 3 6
3 6 5
4 6 2
5 7 4
6 7 9
*/
