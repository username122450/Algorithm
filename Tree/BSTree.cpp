#include<iostream>
#include<stdlib.h>
#define nul -1

using namespace std;

int leafNum;

typedef struct Node{
    int data;
    struct Node *l;
    struct Node *r;
}BSTNode,*BSTree;

BSTree TreeInitialization(int data){
    BSTree t = (BSTree)malloc(sizeof(BSTNode));
    t->data = data;
    t->l =  t->r = NULL;
    return t;
}

BSTNode *CreateNode(int data){
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = data;
    node->l = node->r = NULL;
    return node;
}

void Insert(BSTree t,int data){
    BSTNode *s = CreateNode(data);
    if(t == NULL) t = s;
    BSTNode *pre = NULL;
    BSTNode *p = t;
    while(p != NULL){
        pre = p;
        if(p->data < s->data) p = p->r;
        else if(p->data > s->data) p = p->l;
        else {
            cout << "元素重复,插入失败" << endl;
            free(s);
            return ;
        }
    }
    if(s->data < pre->data) pre->l = s;
    else pre->r = s;
    
}

BSTNode *Find(BSTree t,int target){
    if(t == NULL) {
        cout << "这是空树,查找失败"<<endl;
        return t;
    }
    BSTNode *p = t;
    while(p->data != target||p == NULL){
        if(p->data < target){
            p = p->r;
        }else if(p->data > target){
            p = p->l;
        }else cout << "元素存在" ;
    }
    if(p != NULL) cout << ",查找成功"<<endl;
    else cout << "元素不存在" <<endl;
    return p; 
}

void InOrder(BSTree t){
    if(t == NULL) return ;
    InOrder(t->l);
    cout << t->data << " ";
    InOrder(t->r);
}



int main(){
    cin >> leafNum;
    BSTree t;
    int num;
    for(int i = 0;i < leafNum;i++){
        cin >> num;
        if(i == 0){
            t = TreeInitialization(num);
        }else{
            Insert(t,num);
        }
    }
    InOrder(t);
    return 0;
}

/*
7
19 10 43 76 50 20 3
*/