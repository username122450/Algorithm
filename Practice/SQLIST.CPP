#include<iostream>
#include "malloc.h"

using namespace std;

class sqList
{
    int *L;    
    int max;  
    int used; 
public:
    
    sqList(int n);              
    ~sqList();                   
    int	insert(int pos,int e);  
    int del_pos(int pos);       
    void out();                 
    int search_first(int x);    
    void sort();       
            
    int del_value(int x);     
    int search_all(int x);    
};

sqList::sqList(int n)
{ 
    L=(int *)malloc(n*sizeof(int));
    if(L==0){printf("�ڴ�ռ䲻��");return;}
    max=n;
    used=0;
}

sqList::~sqList()
{
    if(L!=0) 
    {
        free(L);
        L=0;
    }
}

int sqList::insert(int pos,int e)
{
    if(used>=max){return 0;}
    if(pos>used+1||pos<=0){return 0;}
    for(int i=used-1;i>=pos-1;i--)
        L[i+1]=L[i];    

        L[pos-1]=e;    

        used++;
        return 1;
}

int sqList::del_pos(int pos)
{
    if(used==0)return 0;
    if(pos>used||pos<=0)return 0;

    for(int i=pos;i<=used-1;i++)
        L[i-1]=L[i];
    
    used--;
    return 1;
}

void sqList::out()
{
    for(int i=0;i<used;i++)
      printf("%d  ",L[i]);
        
        printf("\n");
}

void sqList::sort()
{
    int  i,j;
    for(i=1;i<used;i++)
        for(j=0;j<used-i;j++)
        {
            if(L[j]>L[j+1]){int t;t=L[j];L[j]=L[j+1];L[j+1]=t;}
        }
}

int sqList::search_first(int x)
{
    for(int i=0;i<used;i++)
    {
        if(L[i]==x)
        {
            printf("%d is at %d\n",x,i+1);
            return i+1;
        }
    }

    printf("%d is not at the list\n",x);
    return 0;
}

int sqList::del_value(int x)     
{
    int index = search_first(x);
    if (x > 0){
        del_pos(index);
        return 1;
    }
    return 0;
}

int sqList::search_all(int x)    
{
    int count = 0;
    for (int i = 0; i < used; i++) {
        if(L[i] == x){
            printf("%d is at %d\n",x,i+1);
            count++;
        }
    }
    if (count != 0) return 1;
    return 0;
}

/*
    10  20  10  10  50
    20  10  10  50
    10 is at 2
    10 is at 3
*/

int main()
    {
        sqList x(10);
        x.insert(1,10);
        x.insert(2,20);
        x.insert(3,10);
        x.insert(4,10);
        x.insert(5,50);
        x.out(); 
        x.del_value(10);
        x.out();          
        x.search_all(10); 
        return 0;
    }

