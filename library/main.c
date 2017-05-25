#include <stdio.h>
#include <stdlib.h>
#include "include/library.h"
#define NUM_V 5
int main(void)
{
  //test list
	Initlist();
	printf("%d %d\n",L.length,L.listsize);
	int a[5]={1,2,3,4,5};
	int i,j;
	for(i=0;i<5;i++)
	{
		j=Insertlist(a[i]);
		if(j==0)
		{
			printf("Error\n");
		}
	}
	printf("numbers in the list are: "); 
	play();
	printf("\n");
	j=Deletelist(2);
	printf("after delete the numbers in list are: ");
	play();
	//test locate
	j=Locatelist(6);
	if(j==0)
		printf("\nnot found\n");
	else{
		printf("%d\n",j);
	}
	j=Locatelist(3);
        if(j==0)
		printf("\nnot found\n");
	else{
		printf("the index is %d\n",j);
	}
  //test stack
	s=Initstack();
	push(1);
        push(2); 
        push(4);
	printf("Stack is empty? %d\n", is_empty());
	while(!is_empty())
	{
		printf("%d ",gettop());
		pop();
        }
       printf("\nStack is empty? %d\n",is_empty());
	push(3);
	push(6);
	printf("Stack is empty? %d\n",is_empty());
   Destroystack();
  printf("Stack is empty? %d\n",is_empty());
  //test queue
	Initqueue();
	printf("the queue is empty? %d\n",is_empty());
	enqueue(1);
	enqueue(2);
	enqueue(4);
	printf("the queue is empty? %d\n",is_empty());
	printf("the length of queue is :%d\n",queuetraverse());
	printf("top number in the queue is %d\n",gethead());
	printf("dequeue number is %d\n",dequeue());
	Destroyqueue();
	printf("the queue is empty? %d\n",is_empty());
  //test tree
  TREE tr;
    tnode np;
    int element;
    tr = NULL;
    tr = insert_value(tr, 8);
    tr = insert_value(tr, 5);
    tr = insert_value(tr, 2); 
    tr = insert_value(tr, 7);
    tr = insert_value(tr, 1);
    tr = insert_value(tr, 10);
    printf("Original:\n");
    print_sorted_tree(tr);
    np = find_value(tr, 8);
    if(np != NULL) {
        delete_node(np);
        printf("After deletion:\n");
        print_sorted_tree(tr);
    }
    //test graph
    struct node graph[NUM_V];
    int i;

    for(i=1; i<NUM_V; i++) {
        (graph+i)->element = i;
        (graph+i)->next = NULL;
    }

    insert_edge(graph,1,3);
    insert_edge(graph,1,4);
    insert_edge(graph,2,3);
    insert_edge(graph,4,2);
    insert_edge(graph,4,3);

    print_graph(graph,NUM_V);
       
  

}
