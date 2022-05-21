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
    printf("\nEnter the number you want to add to the list : ");
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
    if(temp=NULL){
        printf("\n<<<<<<< %d not found in the list >>>>>>>\n",key);
        return ;
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
void deletebegin(){
    if(length()){
        struct node *temp=list->next;
        free(list);
        list=temp;
    }
    return ;
}
void deleteend(){
    if(length()){
        if(length()==1)
            deletebegin();
        else{
            struct node *temp=list,*k=list;
            while(temp->next){
                k=temp;
                temp=temp->next;
            }
            k->next=NULL;
            free(temp);
        }
    }
    return ;
}
void deletespecific(){
    printf("\nEnter the position of the list you want to delete : ");
    int posi;
    scanf("%d",&posi);
    if(posi<1 || posi>length()){
        printf("\n<<<<<<< Invalid Choice >>>>>>>\n");
        return ;
    }
    else if(posi==1)
        deletebegin();
    else if(posi==length())
        deleteend();
    else{
        struct node *temp=list,*j=list;
        posi--;
        while(posi){
            j=temp;
            temp=temp->next;
            posi--;
        }
        if(length()>1){
            struct node *k=temp->next;
            free(temp);
            j->next=k;
        }
    }
    return ;
}
void deletedata(){
    if(length()==0){
        printf("\nList is empty. First add elements to the list\n");
        return ;
    }
    int key;
    printf("\nEnter the number you want to delete : ");
    scanf("%d",&key);
    struct node *temp=list,*k=list;
    while(temp){
        if(temp->data==key)
            break;
        k=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\n<<<<<<< Element not found >>>>>>>\n");
        return ;
    }
    struct node *j=temp->next;
    if(temp==list){
        list=j;
    }
    else
        k->next=j;
    free(temp);
    return ;
}
void search(){
    int ans=1;
    printf("\nEnter the number you want to search : ");
    int key;
    scanf("%d",&key);
    struct node *temp=list;
    while(temp){
        if(temp->data==key){
            break;
        }
        temp=temp->next;
        ans++;
    }
    if(temp==NULL){
        printf("\n <<<<<<<< %d not found in the list >>>>>>>>\n",key);
        return ;
    }
    printf("\n%d is present at node %d\n",key,ans);
    return ;
}
void sort(){
    int n=length();
    if(n<2)
        return ;
    struct node *temp=list;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(temp->data>temp->next->data){
                int tempo=temp->data;
                temp->data=temp->next->data;
                temp->next->data=tempo;
            }
            temp=temp->next;
        }
        temp=list;
    }
    printf("\n\t<<<<<<<< List sorted successfully >>>>>>>>>>\n");
    return ;
}
void reverse(){
    if(length()==1)
        return ;
    struct node *prev=NULL,*cur=list,*nxt=list->next;
    while(cur){
        cur->next=prev;
        prev=cur;
        cur=nxt;
        if(nxt)
            nxt=nxt->next;
    }
    list=prev;
    printf("\n\t<<<<<<<< List reversed successfully >>>>>>>>>>\n");
    return ;
}
void reversesort(){
    sort();
    reverse();
}
int main(){
    printf("\n");
    for(int i=0;i<27;i++)
        printf("=");
    printf(" Linked List ");
    for(int i=0;i<27;i++)
        printf("=");
    while(1){
        printf("\nEnter 1 to insert a number at the end of the list\nEnter 2 to display the list\nEnter 3 to delete the whole list\nEnter 4 for list size\nEnter 5 to insert a number at the beginning of the list\nEnter 6 to insert number at a specific location of the list\nEnter 7 to insert number after a specific node\nEnter 8 to delete first node\nEnter 9 to delete last node\nEnter 'a' to delete at a specific position\nEnter 'b' to delete a specific number\nEnter 'c' to search a number\nEnter 'd' to sort the list\nEnter 'e' to reverse the list\nEnter 'f' to reverse sort the list\nEnter 0 to exit\nYour choice is : ");
        char c;
        fflush(stdin);
        scanf("%c",&c);
        switch(c){
            case '1':addend();
            break;
            case '2':display();
            break;
            case '3':delete();
            break;
            case '4':printf("\nList Size = %d\n",length());
            break;
            case '5':addbegin();
            break;
            case '6':addspecific();
            break;
            case '7':addafternode();
            break;
            case '8':deletebegin();
            break;
            case '9':deleteend();
            break;
            case 'a':deletespecific();
            break;
            case 'b':deletedata();
            break;
            case 'c':search();
            break;
            case 'd':sort();
            break;
            case 'e':reverse();
            break;
            case 'f':reversesort();
            break;
            default:
                delete();
                for(int i=0;i<75;i++)
                    printf("=");
                printf("\n\n");
                return 0;
        }
    }
    delete();
    return 0;
}