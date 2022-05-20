#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}node;
struct node *list=NULL;
void delete(){
    struct node *temp=list;
    while(list){
        temp=list->next;
        free(list);
        list=temp;
    }
}
int length(){
    int ans=0;
    struct node *temp=list;
    while(temp){
        temp=temp->next;
        ans++;
    }
    return ans;
}
void display(){
    struct node *temp=list;
    printf("\nList = [");
    while(temp){
        printf("%d,",temp->data);
        temp=temp->next;
    }
    printf("]\n");
    return ;
}
void addend(){
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        delete();
        printf("\nMemory allocation failed.List deleted succesfully.");
        return ;
    }
    printf("Enter the number you want to add to the list : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(length()){
        struct node *trav=list;
        while(trav->next){
            trav=trav->next;
        }
        trav->next=temp;
    }
    else{
        list=temp;
    }
}
void addbegin(){
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\nMemory allocation failed\nList deleted Succesfully");
        delete();
        return;
    }
    printf("\nEnter the number you want to enter at the beginning of the list : ");
    scanf("%d",&temp->data);
    temp->next=list;
    list=temp;
}
void addspecific(){
    printf("\nEnter the position at which you want to insert the number : ");
    int posi;
    scanf("%d",&posi);
    struct node *temp=list;
    if(posi<1 || posi>length()+1){
        printf("\n<<<<<<< Invalid Position >>>>>>>\n");
        return ;
    }
    else if(posi==1)
        addbegin();
    else if(posi==length()+1)
        addend();
    else{
        posi-=2;
        while(posi){
            temp=temp->next;
            posi--;
        }
        struct node *k=temp->next,*temp2=malloc(sizeof(node));
        if(temp2==NULL){
            printf("\nMemory alloction failed.List deleted succesfully");
            delete();
            return ;
        }
        printf("\nEnter the number you want to insert : ");
        scanf("%d",&temp2->data);
        temp2->next=k;
        temp->next=temp2;
        return ;
    }
}
void addafternode(){
    printf("\nEnter the number after which you want to insert a number : ");
    int key;
    scanf("%d",&key);
    struct node *temp=list;
    while(temp){
        if(temp->data==key){
            break;
        }
        temp=temp->next;
    }
    struct node *k=temp->next;
    struct node *temp2=malloc(sizeof(node));
    if(temp2==NULL){
        printf("\nMemory allocation failed.List deleted succesfully");
        delete();
        return ;
    }
    printf("\nEnter the number you want to insert : ");
    scanf("%d",&temp2->data);
    temp2->next=k;
    temp->next=temp2;
    return ;
}
int main(){
    printf("\n");
    for(int i=0;i<27;i++)
        printf("=");
    printf(" Linked List ");
    for(int i=0;i<27;i++)
        printf("=");
    while(1){
        printf("\nEnter 1 to insert a number at the end of the list\nEnter 2 to display the list\nEnter 3 to delete the whole list\nEnter 4 for list size\nEnter 5 to insert a number at the beginning of the list\nEnter 6 to insert number at a specific location of the list\nEnter 7 to insert number after a specific node\nEnter 0 to exit\nYour choice is : ");
        int c;
        scanf("%d",&c);
        switch(c){
            case 1:addend();
            break;
            case 2:display();
            break;
            case 3:delete();
            break;
            case 4:printf("\nList Size = %d\n",length());
            break;
            case 5:addbegin();
            break;
            case 6:addspecific();
            break;
            case 7:addafternode();
            break;
            default:
                delete();
                for(int i=0;i<75;i++)
                    printf("=");
                printf("\n\n");
                return 0;
        }
    }
    return 0;
}