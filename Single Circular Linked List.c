#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}node;
struct node *list=NULL;
int length(){
    int ans=0;
    if(list==NULL)
        return 0;
    struct node *temp=list;
    do{
        ans++;
        temp=temp->next;
    }while(temp!=list);
    return ans;
}
void display(){
    printf("\nList = [");
    if(list){
        struct node *temp=list;
        do{
            printf("%d,",temp->data);
            temp=temp->next;
        }while(temp!=list);
    }
    printf("]\n");
    return ;
}
void delete(){
    if(list==NULL){
        printf("\n<<<<<<<< List deleted succesfully >>>>>>>>\n");
        return ;
    }
    struct node *temp=list->next,*temp2=temp;
    while(temp!=list){
        temp=temp->next;
        free(temp2);
        temp2=temp;
    }
    free(list);
    list=NULL;
    printf("\n<<<<<<<< List deleted succesfully >>>>>>>>\n");
    return ;
}
void addend(){
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        delete();
        return ;
    }
    printf("\nEnter the number you want to insert : ");
    scanf("%d",&temp->data);
    if(list==NULL){
        list=temp;
        temp->next=temp;
        printf("\n<<<<<<<< %d added to the end of the list succesfully >>>>>>>>\n",temp->data);
        return ;
    }
    struct node *trav=list;
    while(trav->next!=list){
        trav=trav->next;
    }
    trav->next=temp;
    temp->next=list;
    printf("\n<<<<<<<< %d added to the end of the list succesfully >>>>>>>>\n",temp->data);
    return ;
}
void addbegin(){
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        delete();
        return;
    }
    printf("\nEnter the number to insert at the beginning of the list : ");
    scanf("%d",&temp->data);
    if(list==NULL){
        temp->next=temp;
        list=temp;
        printf("\n<<<<<<<< %d added to the beginning of the list succesfully >>>>>>>>\n",temp->data);
        return ;
    }
    temp->next=list;
    struct node *trav=list;
    while(trav->next!=list){
        trav=trav->next;
    }
    trav->next=temp;
    list=temp;
    printf("\n<<<<<<<< %d added to the beginning of the list succesfully >>>>>>>>\n",temp->data);
    return ;
}
void addspecific(){
    printf("\nEnter the position at which you want to insert a number : ");
    int posi,n=length();
    scanf("%d",&posi);
    if(posi<1 || posi>n){
        printf("\n<<<<<<<< Invalid Position >>>>>>>>\n");
        return ;
    }
    if(posi==1){
        addbegin();
        return;
    }
    if(posi==n){
        addend();
        return ;
    }
    posi-=2;
    struct node *trav=list;
    while(posi){
        trav=trav->next;
        posi--;
    }
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        return ;
    }
    printf("\nEnter the number you want to insert : ");
    scanf("%d",&temp->data);
    temp->next=trav->next;
    trav->next=temp;
    printf("\n<<<<<<<< %d inserted succesfully to the list >>>>>>>>\n",temp->data);
    return ;
}
void addafternode(){
    int key;
    printf("\nEnter the number after which you want to insert : ");
    scanf("%d",&key);
    if(list==NULL){
        printf("\n<<<<<<<< The list is empty. First add some numbers to the list >>>>>>>>\n");
        return ;
    }
    struct node *trav=list;
    while(trav->next!=list){
        if(trav->data==key)
            break;
        trav=trav->next;
    }
    if(trav->next==list && trav->data==key){
        addend();
        return ;
    }
    if(trav->next!=list){
        struct node *temp=malloc(sizeof(node));
        if(temp==NULL){
            printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
            return ;
        }
        printf("\nEnter the number you want to insert : ");
        scanf("%d",&temp->data);
        temp->next=trav->next;
        trav->next=temp;
        printf("\n<<<<<<<< %d inserted to the list succesfully >>>>>>>>\n",temp->data);
        return ;
    }
    if(trav->next==list){
        printf("\n<<<<<<<< %d not found in the list >>>>>>>>\n",key);
        return ;
    }
}
void deletebegin(){
    if(list){
        if(length()==1){
            free(list);
            list=NULL;
        }
        else{
            struct node *temp=list,*trav=list;
            while(trav->next!=list){
                trav=trav->next;
            }
            list=list->next;
            trav->next=list;
            free(temp);
        }
    }
    printf("\n<<<<<<<< First node deleted succesfully >>>>>>>>\n");
    return ;
}
void deleteend(){
    if(list){
        if(length()==1){
            free(list);
            list=NULL;
        }else{
            struct node *temp=list;
            while(temp->next->next!=list){
                temp=temp->next;
            }
            free(temp->next);
            temp->next=list;
        }
    }
    printf("\n<<<<<<<< Last node deleted succesfully >>>>>>>>\n");
    return ;
}
void deletespecific(){
    printf("\nEnter the node to be deleted : ");
    int posi,n=length();
    scanf("%d",&posi);
    if(posi<1 || posi>n){
        printf("\n<<<<<<<< Invalid position >>>>>>>>\n");
        return ;
    }
    if(posi==1){
        deletebegin();
        return ;
    }
    if(posi==n){
        deleteend();
        return ;
    }
    posi-=2;
    struct node *trav=list;
    while(posi){
        trav=trav->next;
        posi--;
    }
    struct node *temp=trav->next;
    trav->next=temp->next;
    free(temp);
    printf("\n<<<<<<<< Node deleted Succesfully >>>>>>>>\n");
    return ;
}
void deletedata(){
    printf("\nEnter the number you want to delete from the list : ");
    int key;
    scanf("%d",&key);
    if(list->data==key){
        deletebegin();
        return ;
    }
    struct node *trav=list;
    while(trav->next!=list){
        if(trav->next->data==key)
            break;
        trav=trav->next;
    }
    if(trav->next!=list){
        struct node *temp=trav->next;
        trav->next=temp->next;
        printf("\n<<<<<<<< %d deleted succesfully >>>>>>>>\n",temp->data);
        free(temp);
        return ;
    }
    if(trav->next==list){
        printf("\n<<<<<<<< %d not found in the list >>>>>>>>\n",key);
        return ;
    }
}
void search(){
    printf("\nEnter the number you want to search in the list : ");
    int key,ans=1;
    scanf("%d",&key);
    struct node *trav=list;
    do{
        if(trav->data==key)
            break;
        trav=trav->next;
        ans++;
    }while(trav!=list);
    if(trav==list && trav->data!=key){
        printf("\n<<<<<<<< %d not found in the list >>>>>>>>\n",key);
        return ;
    }
    printf("\n<<<<<<<< %d is present at node %d >>>>>>>>\n",key,ans);
    return ;
}
void sort(){
    int n=length();
    for(int i=0;i<n;i++){
        struct node *trav=list;
        for(int j=0;j<n-i-1;j++){
            if(trav->data>trav->next->data){
                int temp=trav->data;
                trav->data=trav->next->data;
                trav->next->data=temp;
            }
            trav=trav->next;
        }
    }
    printf("\n<<<<<<<< List sorted succesfully >>>>>>>>\n");
    return ;
}
void reverse(){
    int n=length();
    if(n==2){
        list=list->next;
    }
    else if(n>2){
        struct node *prev=list,*cur=prev->next,*after=cur->next;
        do{
            cur->next=prev;
            prev=cur;
            cur=after;
            after=after->next;
        }while(prev!=list);
        list=prev->next;
    }
    printf("\n<<<<<<<< List reversed succesfully >>>>>>>>\n");
    return ;
}
void reversesort(){
    sort();
    reverse();
    return;
}
void menu(){
    printf("\nEnter '1' to add number to the end of the list\nEnter '2' for list size\nEnter '3' to delete the whole list\nEnter '4' to display the list\nEnter '5' to add number to the beginning of the list\nEnter '6' to delete the first node of the list\nEnter '7' to delete the last node\nEnter '8' to insert at a specific position of the list\nEnter '9' to insert after a specific number in the list\nEnter 'a' to delete a specific node\nEnter 'b' to delete a number from the list\nEnter 'c' to search a number in the list\nEnter 'd' to sort the list\nEnter 'e' to reverse the list\nEnter 'f' to reverse sort the list\nEnter '0' to exit\n\nYour choice is : ");
    return ;
}
int main(){
    printf("\n");
    for(int i=0;i<27;i++)
        printf("=");
    printf(" Circular Link List ");
    for(int i=0;i<27;i++)
        printf("=");
    printf("\n");
    while(1){
        menu();
        char c;
        fflush(stdin);
        scanf("%c",&c);
        switch(c){
            case '1':addend();
            break;
            case '2':printf("\nList Size = %d\n",length());
            break;
            case '3':delete();
            break;
            case '4':display();
            break;
            case '5':addbegin();
            break;
            case '6':deletebegin();
            break;
            case '7':deleteend();
            break;
            case '8':addspecific();
            break;
            case '9':addafternode();
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
            default:printf("\n");
            delete();
            for(int i=0;i<75;i++)
                printf("=");
            printf("\n");
            return 0;
        }
    }
}
