#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
}node;
struct node *list=NULL;
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
int length(){
    struct node *temp=list;
    int ans=0;
    while(temp){
        ans++;
        temp=temp->next;
    }
    return ans;
}
void delete(){
    struct node *temp=list;
    while(temp){
        temp=list->next;
        free(list);
        list=temp;
    }
    printf("\n<<<<<<<< List deleted Succesfully >>>>>>>>\n");
    return ;
}
void addend(){
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        delete();
        return;
    }
    printf("\nEnter the number you want to insert : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(length()==0){
        temp->prev=NULL;
        list=temp;
        printf("\n<<<<<<<< %d succesfully added to the end of the list >>>>>>>>\n",temp->data);
        return;
    }
    struct node *temp2=list;
    while(temp2->next){
        temp2=temp2->next;
    }
    temp->prev=temp2;
    temp2->next=temp;
    printf("\n<<<<<<<< %d succesfully added to the end of the list >>>>>>>>\n",temp->data);
    return;
}
void addbegin(){
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory Allocation Failed >>>>>>>>\n");
        delete();
        return;
    }
    printf("\nEnter the number you want to insert at the beginning : ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=list;
    list=temp;
    printf("\n<<<<<<<< %d succesflly added to the beginning of the list >>>>>>>>\n",temp->data);
    return ;
}
void search(){
    struct node *temp=list;
    int ans=0,key;
    printf("\nEnter the number to search : ");
    scanf("%d",&key);
    while(temp){
        ans++;
        if(temp->data==key){
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\n<<<<<<<< %d not found in the list >>>>>>>>\n",key);
    }
    else{
        printf("\n<<<<<<<< %d is at node %d >>>>>>>>\n",temp->data,ans);
    }
    return ;
}
void addspecific(){
    printf("\nEnter the position at which you want to insert number : ");
    int posi;
    scanf("%d",&posi);
    if(posi<1 || posi>length()+1){
        printf("\n<<<<<<<< Invalid position >>>>>>>>\n");
        return ;
    }
    if(posi==length()+1){
        addend();
        return ;
    }
    if(posi==1){
        addbegin();
        return ;
    }
    posi--;
    struct node *temp=list;
    while(posi){
        temp=temp->next;
        posi--;
    }
    struct node *temp2=malloc(sizeof(node));
    if(temp2==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        delete();
        return ;
    }
    printf("Enter the number you want to insert : ");
    scanf("%d",&temp2->data);
    temp2->next=temp;
    temp2->prev=temp->prev;
    temp->prev->next=temp2;
    temp->prev=temp2;
    printf("\n<<<<<<<< %d added to the list succesfully >>>>>>>>\n",temp2->data);
    return ;
}
void addafternode(){
    printf("\nEnter the number after which you want to add : ");
    int key;
    scanf("%d",&key);
    struct node *trav=list;
    while(trav){
        if(trav->data==key)
            break;
        trav=trav->next;
    }
    if(trav==NULL){
        printf("\n<<<<<<<< %d is not present in the list >>>>>>>>\n",key);
        return ;
    }
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        delete();
        return ;
    }
    printf("\nEnter the number you want to insert : ");
    scanf("%d",&temp->data);
    temp->next=trav->next;
    temp->prev=trav;
    if(trav->next)
        trav->next->prev=temp;
    trav->next=temp;
    printf("\n<<<<<<<< %d added to the list succesfully >>>>>>>>\n",temp->data);
    return ;
}
void deletebegin(){
    struct node *temp=list;
    if(length()){
        temp=temp->next;
        free(list);
        list=temp;
        if(list)
            list->prev=NULL;
    }
    printf("\n<<<<<<<< First node deleted succesfully >>>>>>>>\n");
    return ;
}
void deleteend(){
    if(length()==1){
        free(list);
        list=NULL;
        printf("\n<<<<<<<< Last node deleted Succesfully >>>>>>>>\n");
        return ;
    }
    struct node *temp=list;
    while(temp->next){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    printf("\n<<<<<<<< Last node deleted Succesfully >>>>>>>>\n");
    return ;
}
void deletespecific(){
    printf("\nEnter the node you want to delete : ");
    int posi;
    scanf("%d",&posi);
    if(posi<1 || posi>length()){
        printf("\n<<<<<<<< Invalid Position >>>>>>>>\n");
        return ;
    }
    if(posi==1){
        deletebegin();
        return;
    }
    else if(posi==length()){
        deleteend();
        return ;
    }
    else{
        struct node *temp=list;
        posi--;
        while(posi){
            temp=temp->next;
            posi--;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        printf("\n<<<<<<<< Node deleted Succesfully >>>>>>>>\n");
        return ;
    }
}
void deletedata(){
    printf("\nEnter the number you want to delete from the list : ");
    int key;
    scanf("%d",&key);
    if(list->data==key){
        deletebegin();
        return;
    }
    struct node *temp=list;
    while(temp){
        if(temp->data==key)
            break;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\n<<<<<<<< %d not found in the list >>>>>>>>\n",key);
        return ;
    }
    if(temp->next==NULL){
        deleteend();
        return ;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    printf("\n<<<<<<<< %d deleted succesfully from the list >>>>>>>>\n",key);
    free(temp);
    return ;
}
void reverse(){
    struct node *temp=list,*temp2;
    while(temp){
        temp2=temp->next;
        temp->next=temp->prev;
        temp->prev=temp2;
        if(temp2==NULL)
            list=temp;
        temp=temp2;
    }
    printf("\n<<<<<<<< List reversed succesfully >>>>>>>>\n");
    return ;
}
void sort(){
    int n=length();
    struct node *temp=list;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1 && temp->next;j++){
            if(temp->data>temp->next->data){
                int temp2=temp->data;
                temp->data=temp->next->data;
                temp->next->data=temp2;
            }
            temp=temp->next;
        }
        temp=list;
    }
    printf("\n<<<<<<<< List sorted succesfully >>>>>>>>\n");
    return ;
}
void reversesort(){
    sort();
    reverse();
}
void menu(){
    printf("\nEnter '1' to display the list\nEnter '2' to display list size\nEnter '3' to add number to the list\nEnter '4' to delete the whole list\nEnter '5' to insert number at the beginning of the list\nEnter '6' to search an element in the list\nEnter '7' to insert at a specific node of the list\nEnter '8' to insert after a specific number\nEnter '9' to delete the first node\nEnter 'a' to delete the last node\nEnter 'b' to delete a specific node\nEnter 'c' to delete a specific number\nEnter 'd' to reverse the list\nEnter 'e' to sort the list\nEnter 'f' to reverse sort the list\nEnter '0' to exit\n\nYour choice is : ");
    return;
}
int main(){
    printf("\n");
    for(int i=0;i<27;i++)
        printf("=");
    printf(" Double Linked List ");
    for(int i=0;i<27;i++)
        printf("=");
    while(1){
        char c;
        menu();
        fflush(stdin);
        scanf("%c",&c);
        switch(c){
            case '1':display();
            break;
            case '2':printf("\nList Size = %d\n",length());
            break;
            case '3':addend();
            break;
            case '4':delete();
            break;
            case '5':addbegin();
            break;
            case '6':search();
            break;
            case '7':addspecific();
            break;
            case '8':addafternode();
            break;
            case '9':deletebegin();
            break;
            case 'a':deleteend();
            break;
            case 'b':deletespecific();
            break;
            case 'c':deletedata();
            break;
            case 'd':reverse();
            break;
            case 'e':sort();
            break;
            case 'f':reversesort();
            break;
            default:printf("\n");
                delete();
                for(int i=0;i<75;i++)
                    printf("=");
                printf("\n\n");
                return 0;
        }
    }
}
