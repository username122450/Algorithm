#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define nul -1

using namespace std;

typedef struct s{
    int point1;
    int point2;
    int Weight;
    friend bool operator < (const s& s1,const s& s2){
        return s1.Weight  > s2.Weight;
    }
}side;//这是单独作为边,用边集数组储存

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


int Find(vector< Graph > g,char data,int graphNum){
    for(int i = 0;i < graphNum;i++){
        if(g[i]->data == data) return i;
    }
    return -1;
}
side Createside(vector< Graph > g,char p1,char p2,int w,int graphNum){
    side s ;

    s.point1 = Find(g,p1,graphNum);
    s.point2 = Find(g,p2,graphNum);
    s.Weight = w;
    return s;
}

vector< Graph > Insert(vector< Graph > g,char data1,char data2,int w,int graphNum){
    int index1 = Find(g,data1,graphNum);
    int index2 = Find(g,data2,graphNum);
    // cout << data1 << ":"<< index1 << "  "<< data2 << ":"<<index2<<endl;
    Side *p = CreateSide(index2,w);
    p->next = g[index1]->next;
    g[index1]->next = p;
    p = CreateSide(index1,w);
    p->next = g[index2]->next;
    g[index2]->next = p;
    p = NULL;
    return g;
}

int KFind(vector< int >& f,int index){
    if(f[index] == index) return index;
    f[index] = KFind(f,f[index]);
    return f[index];
}

int Kruskal(vector< Graph > g,priority_queue< side >& sides ,int graphNum){
    int sum = 0;
    vector< int > f;
    vector< int > h;
    for(int i = 0;i < graphNum;i++){
        f.push_back(i);
        h.push_back(1);
    }
    int cnt = 0;
    while(!sides.empty() && cnt < graphNum-1){
        side s = sides.top();
        int root1 = KFind(f,s.point1);
        int root2 = KFind(f,s.point2);
        if(root1 != root2){
            if(h[root1] > h[root2]){
                f[root2] = root1;
            }else if(h[root2] > h[root1]){
                f[root1] =root2;
            }else{
                f[root2] = root1;
                h[root1]++;
            }
            sum += s.Weight;
            cout << s.point1 << "->" << s.point2 << ":" << sum<<endl;
        }
        sides.pop();
        cnt++;
    }
    return sum;
}

int main(){
    vector< Graph > g;
    priority_queue< side > sides;
    int graphNum;
    cin >> graphNum;//这里是点的个数
    char data1,data2;//插入的边两端的点
    int w;
    for(int i = 0 ;i < graphNum;i++){
        cin >> data1;//这里借用data1作为点创建图的点集
        g = CreateNode(g,data1);
    }
    cin >> graphNum;//这里是边的个数
    for(int i = 0; i < graphNum;i++){
        cin >> data1 >> data2 >> w;
        g = Insert(g,data1,data2,w,graphNum);
        sides.push(Createside(g,data1,data2,w,graphNum));
    }

    int sum = Kruskal(g,sides,graphNum);
    cout << sum;

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