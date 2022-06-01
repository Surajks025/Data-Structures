#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}node;
struct node *top=NULL;
int length(){
    struct node *temp=top;
    int ans=0;
    while(temp){
        ans++;
        temp=temp->next;
    }
    return ans;
}
void display(){
    if(top==NULL){
        printf("\n<<<<<<<< Stack is empty >>>>>>>>\n");
        return;
    }
    printf("\nStack\n\n");
    struct node *temp=top;
    while(temp){
        printf("* %d *\n",temp->data);
        for(int i=0;i<6;i++)
            printf("*");
        printf("\n");
        temp=temp->next;
    }
    return ;
}
void delete(){
    struct node *temp=top;
    while(temp){
        temp=temp->next;
        free(top);
        top=temp;
    }
    printf("\n<<<<<<<< Stack deleted Succesfully >>>>>>>>\n");
    return;
}
void push(){
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        delete();
        return ;
    }
    printf("\nEnter the number you want to push to the stack : ");
    scanf("%d",&temp->data);
    temp->next=top;
    top=temp;
    printf("\n<<<<<<<< %d pushed to the stack succesfully >>>>>>>>\n",top->data);
    return ;
}
void pop(){
    if(top){
        struct node *temp=top;
        temp=top->next;
        printf("\n<<<<<<<< %d popped from the stack succesfully >>>>>>>>\n",top->data);
        free(top);
        top=temp;
        return ;
    }
    printf("\n<<<<<<<< Stack is empty >>>>>>>>\n");
    return;
}
void menu(){
    printf("\nEnter '1' to push an element to the stack\nEnter '2' to pop the top element from the stack\nEnter '3' to delete the whole stack\nEnter '4' for stack size\nEnter '5' for the top element of the stack\nEnter '6' to view the whole stack\nEnter '0' to exit\n\nYour choice is : ");
    return ;
}
int main(){
    printf("\n");
    for(int i=0;i<27;i++)
        printf("=");
    printf(" Stack ");
    for(int i=0;i<27;i++)
        printf("=");
    printf("\n");
    while(1){
        menu();
        char c;
        fflush(stdin);
        scanf("%c",&c);
        switch(c){
            case '1':push();
            break;
            case '2':pop();
            break;
            case '3':delete();
            break;
            case '4':printf("\nStack size = %d\n",length());
            break;
            case '5':if(top){
                printf("\nTop element = %d\n",top->data);
            }
            else{
                printf("\n<<<<<<<< Stack is Empty >>>>>>>>\n");
            }
            break;
            case '6':display();
            break;
            default:printf("\n");
            delete();
            for(int i=0;i<75;i++){
                printf("=");
            }
            printf("\n\n");
            return 0;
        }
    }
}
