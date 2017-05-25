#include "include/all.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stddef.h"
void Initlist()
 {
    L.elem=(int*)malloc(10*sizeof(int));
    if(!L.elem){
      return ;
      }
    L.length=5;
    L.listsize=10;
 }
 int Insertlist(int e)
 {
      
       int *q = L.elem;
        while(*q!=0)
            q++;
       *q=e;
       ++L.length;
       return 1;
  }
  int Deletelist(int i)
  {
      if((i<1)||(i>L.length))
          return 0;
      int *p,*q,e;
      p=L.elem+(i-1);
      e=*p;
      q=L.elem+L.length-1;
      for(++p;p<=q;++p)
      {
          *(p-1)=*p;
      }
      --L.length;
      return 1;
 }
 int Locatelist(int e)
 {
    int i=1;
    int *p;
    p=L.elem;
    while(i<=L.length&&e!=*(p++))
        ++i;
     if(i<=L.length)
         return i;
     return 0;
  }
void play()
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d ",*(L.elem+i));
	}
}
//stack
Stack Initstack()
{
	posnext p;
	p=(posnext) malloc(sizeof(struct node));
	p->next=NULL;
        s=p;
	return s;
}
void Destroystack()
{
	while(!is_empty())
		pop();
 	free(s);
}
int pop()
{
	int element;
	posnext top,newtop;
	if(is_empty()){
		printf("the stack is empty");
		return 0;
	}
	else{
	top = s->next;
	element=top->element;
	newtop = top->next;
        s->next = newtop;
        free(top);
        return element;
    }
}
int is_empty()
{
       if(s->next==NULL)	
	  return 1;
       else 
	return 0;
}
int gettop()
{	
	return(s->next->element);
}
void push(int e)
{
	posnext p,oldtop;
	oldtop=s->next;
	p = (posnext) malloc(sizeof(struct node));
        p->element = e;
        p->next = s->next;
        s->next = p;
}
//queue
void  Initqueue()
{
	Q.front=Q.rear=(queueptr)malloc(sizeof(Qnode));
	if(!Q.front)
	   return ;
	Q.front->next=NULL;
	
}
void Destroyqueue()
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
}
int dequeue()
{	
	if(is_empty())
		return 0;
	Qnode *p=NULL;
	p=Q.front->next;
	int e;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return e;
}
int is_empty()
{
	if(Q.front==Q.rear)
		return 1;
	else 
		return 0;
}
int gethead()
{
	if(is_empty())
	{
		return 0;
	}
	Qnode *p=NULL;
	p=Q.front->next;
	int e;
	e=p->data;
	return e;
}	
void enqueue(int e)
{
	Qnode *p=NULL;
	p=(queueptr)malloc(sizeof(Qnode));	
	if(!p)
	{
		exit(0);
	}
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
int queuetraverse()
{
	Qnode *p=NULL;
        int i=0;
	p=Q.front->next;
	while(p!=Q.rear)
	{	
		printf("%d ",p->data);
		p=p->next;
		i=i+1;
	}
	printf("%d\n",p->data);
	printf("the length of the queue %d\n",i+1);
	return i+1;
}
//tree
void print_sorted_tree(TREE tr)
{
    if (tr == NULL) return;
    print_sorted_tree(tr->lchild);
    printf("%d \n", tr->element);
    print_sorted_tree(tr->rchild);
}
tnode find_min(TREE tr)
{
   tnode np;
    np = tr;
    if (np == NULL) return NULL;
    while(np->lchild != NULL) {
        np = np->lchild;
    }
    return np;
}
tnode find_max(TREE tr)
{
    tnode np;
    np = tr;
    if (np == NULL) return NULL;
    while(np->rchild != NULL) {
        np = np->rchild;
    }
    return np;
}
tnode find_value(TREE tr,int value) 
{
    if (tr == NULL) return NULL; 

    if (tr->element == value) {
        return tr;
    }
    else if (value < tr->element) {
        return find_value(tr->lchild, value);
    }
    else {
        return find_value(tr->rchild, value);
    }
}
int  delete_node(tnode np) 
{
    tnode replace;
    int  element;
    if (is_leaf(np)) {
        return delete_leaf(np);
    }   
    else{
        replace = (np->lchild != NULL) ? find_max(np->lchild) : find_min(np->rchild);
        element = np->element;
        np->element = delete_node(replace);
        return element;
    }
}
tnode insert_value(TREE tr,int value) {
    tnode np;
    np =(tnode) malloc(sizeof(struct node));
    np->element = value;
    np->parent  = NULL;
    np->lchild  = NULL;
    np->rchild  = NULL;
 
    if (tr == NULL) tr = np;
    else {
        insert_node_to_nonempty_tree(tr, np);
    }
    return tr;
}
static int is_root(tnode np)
{
    return (np->parent == NULL);
}
static int is_leaf(tnode np)
{
    return (np->lchild == NULL && np->rchild == NULL);
}
static int delete_leaf(tnode np)
{
    int element;
    tnode parent;
    element = np->element;
    parent  = np->parent;
    if(!is_root(np)) {
        if (parent->lchild == np) {
            parent->lchild = NULL;
        }
        else {
            parent->rchild = NULL;
        }
    }
    free(np);
    return element;
}
static void insert_node_to_nonempty_tree(TREE tr,tnode np)
{
 
    if(np->element <= tr->element) {
        if (tr->lchild == NULL){ 
            tr->lchild = np;
            np->parent = tr;
            return;
        }
        else {
            insert_node_to_nonempty_tree(tr->lchild, np);
        }
    }
    else if(np->element > tr->element) {
               if (tr->rchild == NULL) {
                      tr->rchild = np;
                      np->parent = tr;
                      return;
              }
        else {
            insert_node_to_nonempty_tree(tr->rchild, np);
        }
    }
}
//graph
void print_graph(pos graph, int nv) {
    int i;
    pos p;
    for(i=1; i<nv; i++) {
        p = (graph + i)->next;
        printf("From %d: ",i);
        while(p != NULL) {
            printf("%d->%d; ", i, p->element);
            p = p->next;
        }
        printf("\n");
    }
}
void insert_edge(pos graph,int from, int to)
{
    pos np;
    pos nodeAdd;

    np = graph + from;

    nodeAdd = (pos) malloc(sizeof(struct node));
    nodeAdd->element = to;
    nodeAdd->next    = np->next;
    np->next = nodeAdd;
}

