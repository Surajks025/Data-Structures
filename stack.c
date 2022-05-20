#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node *next;
}node;
struct node *stack=NULL;
int stacksize(){
    struct node *temp=stack;
    int ans=0;
    while(temp){
        ans++;
        temp=temp->next;
    }
    return ans;
}
void display(){
    struct node *temp=stack;
    printf("\nStack = ");
    while(temp){
        printf("%d,",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}
void delete(){
    struct node *temp;
    while(stack){
        temp=stack->next;
        free(stack);
        stack=temp;
    }
    display();
    return ;
}
void push(){
    int ele;
    printf("Enter the element you want to push : ");
    scanf("%d",&ele);
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        delete();
        printf("\nFailed to push\n Stack deleted Successfully.\n");
        return ;
    }
    temp->data=ele;
    temp->next=NULL;
    if(stacksize()){
        struct node *k=stack;
        while(k->next){
            k=k->next;
        }
        k->next=temp;
    }
    else{
        stack=temp;
    }
    printf("\n%d Successfully pushed to the stack\n",ele);
    display();
    return ;
}
void pop(){
    if(stacksize()){
        struct node *temp=stack,*k=stack;
        while(temp->next){
            k=temp;
            temp=temp->next;
        }
        printf("\n%d popped Successfully.\n",temp->data);
        free(temp);
        if(k==stack)
            stack=NULL;
        else
            k->next=NULL;
    }
    else{
        printf("\nStack is already empty.\n");
    }
    display();
    return;
}
int main(){
    for(int i=0;i<70;i++){
        printf("=");
    }
    printf("\nStack\n");
    bool flag=true;
    while(flag){
        printf("\nEnter 1 to push\nEnter 2 to pop\nEnter 3 to display the stack\nEnter 4 to print stack size\nPress 5 to delete the stack\nEnter 0 to exit\nYour choice is : ");
        fflush(stdin);
        char c;
        scanf("%c",&c);
        if(c<48 || c>57){
            for(int i=0;i<70;i++){
                printf("=");
            }
            return 0;
        }
        switch(c){
            case '1':push();
            break;
            case '2':pop();
            break;
            case '3':display();
            break;
            case '4':printf("\nStack size = %d\n",stacksize());
            break;
            case '5':delete();
            break;
            default:flag=false;
        }
        for(int i=0;i<70;i++){
            printf("=");
        }
    }
    return 0;
}