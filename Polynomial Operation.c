#include <stdio.h>
#include <stdlib.h>
struct node{
    int co,ex;
    struct node *next;
}node;
struct node *pone=NULL,*ptwo=NULL,*ans=NULL,*prod=NULL;
int length(struct node *trav){
    int len=0;
    while(trav){
        len++;
        trav=trav->next;
    }
    return len;
}
void sort(struct node *trav,short p){
    int n;
    struct node *ctrav=trav;
    if(p==1)
        n=length(pone);
    else 
        n=length(ptwo);
    for(int i=0;i<n;i++){
        trav=ctrav;
        for(int j=0;j<n-i-1;j++){
            if(trav->ex<trav->next->ex){
                int tempco=trav->co,tempex=trav->ex;
                trav->co=trav->next->co;
                trav->ex=trav->next->ex;
                trav->next->co=tempco;
                trav->next->ex=tempex;
            }
            trav=trav->next;
        }
    }
    return ;
}
void show(struct node *trav, short p){
    if(p==1)
        printf("\nP1 : ");
    else if(p==2)
        printf("\nP2 : ");
    else if(p==3)
        printf("\nSUM : ");
    else
        printf("\nPRODUCT : ");
    if(trav==NULL)
        printf("0 ");
    while(trav){
        if(trav->ex==0)
            printf("%d ",trav->co);
        else if(trav->co)
            printf("%dx^%d ",trav->co,trav->ex);
        trav=trav->next;
    }
    printf("\n");
    return ;
}
void delete(){
    struct node *trav=pone;
    while(trav){
        trav=trav->next;
        free(pone);
        pone=trav;
    }
    trav=ptwo;
    while(trav){
        trav=trav->next;
        free(ptwo);
        ptwo=trav;
    }
    trav=ans;
    while(trav){
        trav=trav->next;
        free(ans);
        ans=trav;
    }
    trav=prod;
    while(trav){
        trav=trav->next;
        free(prod);
        prod=trav;
    }
    printf("\n<<<<<<<< Polynomials deleted successfully >>>>>>>>\n");
    return ;
}
void add(struct node *trav,short p){
    while(trav && trav->next){
        trav=trav->next;
    }
    struct node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
        delete();
        return ;
    }
    if(trav)
        trav->next=temp;
    else if(p==1)
        pone=temp;
    else
        ptwo=temp;
    printf("\nEnter the EXPONENT of the term : ");
    scanf("%d",&temp->ex);
    printf("\nEnter the COEFFICIENT of the term : ");
    scanf("%d",&temp->co);
    printf("\nAdded term to the polynomial is %dX^%d\n",temp->co,temp->ex);
    temp->next=NULL;
    return ;
}
void sum(){
    sort(pone,1);
    sort(ptwo,2);
    struct node *one=pone,*two=ptwo,*trav=ans;
    while(one || two){
        struct node *temp=malloc(sizeof(node));
        if(temp==NULL){
            printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
            delete();
            return ;
        }
        temp->next=NULL;
        if(one == NULL){
            temp->co=two->co;
            temp->ex=two->ex;
            two=two->next;
        }
        else if(two == NULL){
            temp->co=one->co;
            temp->ex=one->ex;
            one=one->next;
        }
        else{
            if(one->ex>two->ex){
                temp->ex=one->ex;
                temp->co=one->co;
                one=one->next;
            }
            else if(one->ex<two->ex){
                temp->ex=two->ex;
                temp->co=two->co;
                two=two->next;
            }
            else{
                temp->ex=one->ex;
                temp->co=one->co+two->co;
                one=one->next;
                two=two->next;
            }
        }
        if(temp->co==0){
            free(temp);
            continue;
        }
        if(trav==NULL){
            ans=temp;
            trav=ans;
        }else{
            trav->next=temp;
            trav=temp;
        }
    }
    show(ans,3);
    return ;
}
void product(){
    sort(pone,1);
    sort(ptwo,2);
    struct node *one=pone,*two=ptwo;
    while(one){
        two=ptwo;
        while(two){
            struct node *temp=malloc(sizeof(node));
            if(temp==NULL){
                printf("\n<<<<<<<< Memory allocation failed >>>>>>>>\n");
                delete();
                return ;
            }
            temp->co=one->co*two->co;
            temp->ex=one->ex+two->ex;
            struct node *trav=prod,*ptrav=prod;
            while(trav){
                if(trav->ex==temp->ex){
                    trav->co+=temp->co;
                    free(temp);
                    break;
                }
                if(trav->ex<temp->ex){
                    temp->next=trav;
                    ptrav->next=temp;
                    break;
                }
                ptrav=trav;
                trav=trav->next;
            }
            if(prod==NULL){
                prod=temp;
                temp->next=NULL;
            }
            else if(trav==NULL){
                ptrav->next=temp;
                temp->next=NULL;
            }
            two=two->next;
        }
        one=one->next;
    }
    show(prod,4);
    return ;
}
int main(){
    printf("\n");
    for(int i=0;i<27;i++)
        printf("=");
    printf(" Polynomial Operation ");
    for(int i=0;i<27;i++)
        printf("=");
    printf("\n");
    while(1){
        printf("\nEnter '1' to add terms to the first polynomial\nEnter '2' to add terms to the second polynomial\nEnter '3' to display the polynomials \nEnter '4' to delete the polynomials\nEnter '5' to find the sum of the polynomials\nEnter '6' to find the product of the Polynomials\nEnter '0' to exit\nYour choice is : ");
        char c;
        fflush(stdin);
        scanf("%c",&c);
        switch(c){
            case '1':add(pone,1);
            break;
            case '2':add(ptwo,2);
            break;
            case '3':show(pone,1);
            show(ptwo,2);
            show(ans,3);
            show(prod,4);
            break;
            case '4':delete();
            break;
            case '5':sum();
            break;
            case '6':product();
            break;
            default:printf("\n");
            delete();
            for(int i=0;i<76;i++)
                printf("=");
            printf("\n\n");
            return 0;
        }
    }
}
