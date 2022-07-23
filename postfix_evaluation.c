//Evaluation of Postfix expression
#include <stdio.h>
#include <string.h>
int stk[30],top=-1;
void push(int x){
    top++;
    stk[top]=x;
    return ;
}
int pop(){
    top--;
    return stk[top+1];
}
int main(){
    char exp[30];
    printf("\nEnter the expression : ");
    gets(exp);
    int i=0,n=strlen(exp);
    do{
        if(exp[i]=='+'){
            int a=pop(),b=pop();
            push(a+b);
        }
        else if(exp[i]=='-'){
            int a=pop(),b=pop();
            push(a-b);
        }
        else if(exp[i]=='*'){
            int a=pop(),b=pop();
            push(a*b);
        }
        else if(exp[i]=='/'){
            int a=pop(),b=pop();
            push(a/b);
        }
        else{
            push(exp[i]-'0');
        }
        i++;
    }while(i<n);
    printf("\n%s = %d\n\n",exp,stk[top]);
    return 0;
}
