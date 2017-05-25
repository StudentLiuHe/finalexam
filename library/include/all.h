#ifndef _CALC_H
#define _CALC_H
typedef struct{
  int *elem;
  int length;
  int listsize;
 }list;
list L;
void Initlist();
int Insertlist(int e);
int Deletelist(int i);
int Locatelist(int e);
void play();
typedef struct node *posnext;
typedef struct node *Stack;
struct node{
	int element;
	posnext next;
};
Stack s;
Stack Initstack();
void Destroystack();
int pop();
int is_empty();
int gettop();
void push(int e);

typedef struct Node{
	int data;
	struct Node  *next;
}Qnode,*queueptr;
typedef struct {
	queueptr front;
	queueptr rear;
}linkqueue;
linkqueue Q;
void Initqueue();
void Destroyqueue();
int dequeue();
int is_empty_queue();
int gethead();
void enqueue(int e);
int queuetraverse();

typedef struct data *tnode;
struct data {
    tnode parent;
    int  element;
    tnode lchild;
    tnode rchild;
};
typedef struct data *TREE;
void print_sorted_tree(TREE);
tnode find_min(TREE);
tnode find_max(TREE);
tnode find_value(TREE,int);
tnode insert_value(TREE,int);
int delete_node(tnode);
static int is_root(tnode);
static int is_leaf(tnode);
static int delete_leaf(tnode);
static void insert_node_to_nonempty_tree(TREE,tnode);

typedef struct Data *pos;
struct Data {
    int element;
    pos next;
};
void insert_edge(pos, int, int);
void print_graph(pos graph, int nv);
#endif //_CALC_H
