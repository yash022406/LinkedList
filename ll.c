#include<stdio.h>
#include<stdlib.h>
// learning deleting last element
struct node {
    int data;
    struct node * next;
};
struct node * head = NULL;
struct node * temp = NULL;
void add_data(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);

    
            
    if(head == NULL){
        head = (struct node *)malloc(sizeof(struct node));
        temp = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head ->next = NULL;
        temp = head;
    }
    else{
        struct node * new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new -> next = NULL;
        temp->next = new;
        temp = new;
    }
}
void display(){
    struct node * temp2=head;
    while(temp2!=NULL){
        printf("%d\t",temp2-> data);
        temp2 = temp2 -> next;
    }
    printf("\n");
}
void delete_last(){
    struct node * temp3=head;
    struct node * temp4=head;
    while(temp3->next != NUll){
        temp4=temp3;
        temp3 = temp3 -> next;
        
    }
    temp4->next = NULL;
    free(temp3);
}

void delete(){
    int d;
    printf("Enter the data to delete: ");
    scanf("%d",&d);

    struct node * x = (struct node *)malloc(sizeof(struct node));
    struct node * y = head;
    struct node * z = (struct node *)malloc(sizeof(struct node));
    while(y->data !=d){
        x=y;
        y=y->next;
    }
    z=y->next;
    x->next = z;
    free(y);

}
void addafter(){
    int prev,da;
    printf("Enter the before data: ");
    scanf("%d",&prev);
    printf("Enter the data to add: ");
    scanf("%d",&da);
    struct node * trip = head;
    struct node * fresh = (struct node *)malloc(sizeof(struct node));
    fresh->data = da;
    while(trip->data!=prev){
        trip=trip->next;

    }
   fresh->next = trip->next;
   trip->next=fresh;


}
int main(){

    int n;
    while(n!=6){

        printf("1. Add item\n2.Display list\n3.Delete last element\n4.Delete\n5.Add After Data\n6.Exit\n");
        scanf("%d",&n);

        if(n==1){

            // adding the data 
            add_data();

        }
        else if(n==2){

            // displaying the data
            display();
        }
        else if(n==3){

            // deleting the last node
            delete_last();

        }
        else if ( n==4){

            // deleting a particular node according the user
            delete();

        }
        else if(n==5){
             addafter();
        }
    }
    return 0;
}