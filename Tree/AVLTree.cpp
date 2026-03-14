#include<iostream>
#include<stdlib.h>
#define nul -1
using namespace std;

typedef struct Node{
    int data;
    int h;
    struct Node *l;
    struct Node *r;
}AVLNode,*AVLTree;

int geth(AVLNode *t){
    if(t == NULL) return 0;
    return t->h;
}
int calculateh(AVLNode *t){
    if(t == NULL) return 0;
    return geth(t->l) > geth(t->r) ? geth(t->l) + 1:geth(t->r)+1;
}


AVLNode *CreateNode(int data){
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->h = 1;
    node->l = node->r = NULL;
    return node;
}

AVLNode *LL(AVLTree t){
    AVLNode *s = t->l;
    t->l = s->r;
    s->r = t;
    t->h = calculateh(t);
    s->h = calculateh(s);
    return s;
}
AVLNode *RR(AVLTree t){
    AVLNode *s = t->r;
    t->r = s->l;
    s->l = t;
    t->h = calculateh(t);
    s->h = calculateh(s);
    return s;
}

AVLNode *LR(AVLTree t){
    t->l = RR(t->l);
    return LL(t);
}
AVLNode *RL(AVLTree t){
    t->r = LL(t->r);
    return RR(t);
}

AVLNode *Insert(AVLTree t,int data){
    if(t == NULL) return CreateNode(data);//这里使递归终点
    if(data > t->data ){
        t->r = Insert(t->r,data);
        if(geth(t->r)-geth(t->l) > 1){
            AVLNode *right = t->r;
            if(data > right->data  ) t = RR(t);
            else if(data < right->data  ) t = RL(t);
        }
    }else if(data < t->data ){
        t->l = Insert(t->l,data);
        if(geth(t->l) - geth(t->r) > 1){
            AVLNode *left = t->l;
            if(data > left->data )t = LR(t);
            else if(data < left->data )t =LL(t);
        }
    }
    t->h = calculateh(t);//这里t不是开始的t,这是经过旋转过后最小的node
    return t;
}

void InOrder(AVLTree t){
    if(t == NULL) return ;
    InOrder(t->l);
    cout << t->data << " ";
    InOrder(t->r);
}

int leafNum;

int main(){
    cin >> leafNum;
    AVLTree t = NULL;
    int num;
    for(int i = 0;i < leafNum;i++){
        cin >> num;
        t = Insert(t,num);
    }

    InOrder(t);

    return 0;
}

/*
7
19 10 43 76 50 20 3
*/