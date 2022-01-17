//A170
#include <stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*prv;
 struct node*next;
};
struct node*head=NULL;
struct node*getnode();
void create(int n);
void display();
void insert_begin();
void insert_end();
void delete_begin();
void delete_end();
void insert_p();
void delete_p();
struct node* count();
void reverse();
int main()
{
 int ch,n;
 do{
 printf("\nenter choice\n1.create\n2.display\n3.insert at
beginning\n4.insert at end\n5.delete at beginning\n6.delete 
at end\n7.insert at given position\n8.delete at given
position\n9.Count the length of node\n10.Reverse:");
 scanf("%d",&ch);

 switch(ch)
 {
 case 1:
 printf("enter no of nodes:");
 scanf("%d",&n);
 create(n);
 display();
 break;

 case 2:
 display();
 break;

 case 3:
 insert_begin();
 display();
 break;

 case 4:
 insert_end();
 display();
 break;

 case 5:
 delete_begin();
 display();
 break;

 case 6:
 delete_end();
 display();
 break;

 case 7:
 insert_p();
 display();
 break;

 case 8:
 delete_p();
 display();
 break;

 case 9:
 count();
 break;

 case 10:
 reverse();
 break;


 }
 }while(ch);
 return 0;
}
struct node*getnode()
{
 struct node*new=(struct node*)malloc(sizeof(struct
node));
 printf("enter data:");
 scanf("%d",&new->data);
 new->prv=NULL;
 new->next=NULL;
 return new;
}
void create(int n)
{
int i;
struct node *new;
struct node *temp;
for(i = 0; i < n; i++)
{
new= getnode();
if(head== NULL)
{
head= new;
}
else
{
temp = head;
while(temp -> next)
{
temp = temp -> next;
}
temp -> next = new;
new-> prv = temp;
}
}
}
void display()
{
 struct node*temp;
 temp=head;
 while(temp!=NULL)
 {
 printf("%d\n",temp->data);
 temp=temp->next;
 }
}
void insert_begin()
{
struct node *new;
new = getnode();
if(head == NULL)
head = new;
else
{
new -> next= head;
head ->prv = new;
head = new;
}
}
void insert_end()
{
 struct node*new,*temp;
 new=getnode();
 if(head==NULL)
 head=new;
 else
 {
 temp=head;
 while(temp->next!=NULL)
 temp=temp->next;
 temp->next=new;
 new->prv=temp;

 }
}
void delete_begin()
{
 struct node*temp;
 if(head==NULL)
 printf("EMPTY");
 else
 {
 temp=head;
 head=head->next;
 head->prv=NULL;
 free(temp);
 }
}
void delete_end()
{
 struct node*temp;
 if(head==NULL)
 printf("EMPTY");
 else
 {
 temp=head;
 while(temp->next!=NULL)
 temp=temp->next;
 temp->prv->next=NULL;
 free(temp);
 temp=NULL;
 }
}
void insert_p()
{

 struct node *ptr = (struct node *)malloc(sizeof(struct
node));
 struct node *temp,*new;
 int i, loc;
 new=getnode();
 if(ptr == NULL)
 {
 printf("\n OVERFLOW");
 }
 else
 {
 printf("\nEnter the location\n");
 scanf("%d",&loc);
 temp=head;
 for(i=0;i<loc-2;i++)
 {
 temp = temp->next;
 if(temp == NULL) 
 {
 printf("\ncan't insert\n");
 return;
 }
 }
 ptr=new;
 ptr->next = temp->next;
 ptr -> prv = temp;
 temp->next = ptr;
 temp->next->prv=ptr;
 printf("Node Inserted\n");
 }
}
void delete_p( )
{
struct node *temp;
int i,p;
printf("position:");
 scanf("%d",&p);
temp = head;
for(i=0; i<p-1; i++)
{
temp = temp->next;
}
if(temp != NULL)
{
temp->prv->next = temp->next;
temp->next->prv = temp->prv;
free(temp);
}
else
{
printf("Invalid position!\n");
}}
struct node* count()
{
 int count=0;
 while(head!=NULL)
 {
 head=head->next;
 count++;
 }
 printf("\n No of nodes:%d ", count);
}
void reverse()
{
struct node *temp;
temp = head;
if(head == NULL)
printf("\nEmpty");
else
{
while(temp -> next != NULL)
temp = temp -> next;
}
while(temp != NULL)
{
printf("\t%d", temp -> data);
temp = temp -> prv;
}
}
