#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;  
	struct node *next;
}node;



node* insertAtIntermediatePosition(int node_data , int position , node* start)
{
	node *p , *q , *new_node;
	int i=0;
	p= start;
	
	while(i<position-1)
	{
		p=p->next;
		i++;
	}
	
	new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	new_node->data = node_data;
	
	q = p->next;
	p->next = new_node;
	new_node->next = q;
	
	return start;
	
}


int main()
{	
	int a , i = 1 , n ,r , node_data , position;     //   i = 0  is also ok....
	node *p,*q,*start;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	printf("Enter node %d  \n",i);   //  you can also start with i = 0
	p = (node*)malloc(sizeof(node));
	scanf("%d",&a);
	p->data = a;
	p->next = NULL;
	start = p; 
		
	for(i=2;i<=n;i++)                //if i=0 , then for ( i = 1; i < n; i++ )
	 	{
	 		printf("Enter node %d  \n",i);
		 	q = (node*)malloc(sizeof(node));
			scanf("%d",&a);
			q->data = a;
			q->next = NULL;			 	
		 	p->next = q;
		 	p = p->next;		 	
	 	
		}

	p = start;
	while(p!=NULL)
	{
		printf("\t %d", p->data);
		p = p->next;
	}

	
	printf("\nEnter the value of the node which you want to inset at Intermediate place : ");
	scanf("%d",&node_data);
	
	printf("\nEnter the position at which you want to place node");
	scanf("%d",&position);
	
	
	start = insertAtIntermediatePosition(node_data , position , start);

	printf("\n");
	p=start;
	while(p!=NULL)
	{
		printf("\t%d",p->data);
		p = p->next;	
	}	
	

return 0;
}
