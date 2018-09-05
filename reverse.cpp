#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void reverse(struct node **head){
	struct node *current =*head;
	struct node *prev=NULL;
	struct node *next=NULL;
	while (current != NULL)
        {
            // Store next
            next = current->next;
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        *head=prev;
	return ;
}
void print(struct node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
struct node* insert(struct node* head,int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	struct node *temp=head;
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		return head;
	}while(temp->next!=NULL){
		temp=temp->next;
	}temp->next=newnode;
	return head;
}
int main(){
	struct node *head=NULL;
	int n,x,key;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		head=insert(head,x);
    }
     reverse(&head);
     print(head);
	return 0;
}
