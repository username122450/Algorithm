#include<iostream>
#include<vector>
#include<queue>
#define nul -1

using namespace std;

typedef struct SNode{
    int index;
    int Weight;
    struct SNode *next;
}Side;

typedef struct Node{
    char data;//这是点的名称(如a,b等)
    int flag;//这是帮助遍历的标记,0是未访问,1是已访问过
    Side *next;
}GraphNode,*Graph;//这里用邻接表实现有权无向图

Side *CreateSide(int index,int Weight){
    Side *s = (Side *)malloc(sizeof(Side));
    s->index = index;
    s->Weight = Weight;
    s->next = NULL;
    return s;
}

vector< Graph > CreateNode(vector< Graph > g,char data){
    GraphNode *s = (GraphNode *)malloc(sizeof(GraphNode));
    s->data = data;
    s->flag = 0;
    s->next = NULL;
    g.push_back(s);
    return g;
}


int Find(vector< Graph > g,char data){
    for(int i = 0;i < g.size();i++){
        if(g[i]->data == data) return i;
    }
    return -1;
}

vector< Graph > Insert(vector< Graph > g,char data1,char data2,int w){
    int index1 = Find(g,data1);
    int index2 = Find(g,data2);
    cout << data1 << ":"<< index1 << "  "<< data2 << ":"<<index2<<endl;
    Side *p = CreateSide(index2,w);
    p->next = g[index1]->next;
    g[index1]->next = p;
    p = CreateSide(index1,w);
    p->next = g[index2]->next;
    g[index2]->next = p;
    p = NULL;
    free(p);
    return g;
}

void DFS(vector< Graph > g,int index){
    if(g[index]->flag == 1)return ;
    else{
        cout << g[index]->data << " ";
        g[index]->flag = 1;
        Side *p = g[index]->next;
        while(p != NULL){
            DFS(g,p->index);
            p = p->next;
        }
    }
}

void BFS(vector< Graph > g,int index){
    queue< int > q;
    q.push(index);
    g[index] ->flag = 1;
    while( !q.empty()){
        int t = q.front();
        Side *p = g[t]->next;
        while(p != NULL){
            int i = p->index;
            // cout<< i << " " << g[i]->flag <<endl;
            if(g[i]->flag == 0){
                q.push(i);
                g[i]->flag = 1;//注意:!!!要在入队时将其标记,否则会多次入队,因为出队标记时,这个index可能已经再次进队了
            }
            p = p->next;
        }
        cout << g[t]->data << " ";
        q.pop();
    }
}

int main(){

    vector< Graph > g;
    int graphNum;
    cin >> graphNum;//这里是点的个数
    char data1,data2,w;//插入的边两端的点
    for(int i = 0 ;i < graphNum;i++){
        cin >> data1;//这里借用data1作为点创建图的点集
        g = CreateNode(g,data1);
    }
    cin >> graphNum;//这里是边的个数
    int index1,index2;
    for(int i = 0; i < graphNum;i++){
        cin >> data1 >> data2 >> w;
        g = Insert(g,data1,data2,w);
    }

    // DFS(g,0);
    cout << endl;
    BFS(g,0);
    return 0;
}

/*
7
a b c d e f g 
8
a b 1
a d 3
a e 8
b c 6
c f 5
d f 2
e g 4
f g 9
*/
