//Infix to Postfix using stack
#include <stdio.h>
#include <string.h>
char stk[50];
int top=0;
void push(char c){
    top++;
    stk[top]=c;
    return ;
}
int prior(char c){
    if(c=='+' || c=='-')
        return 0;
    else if(c=='%')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
}
int main(){
    stk[0]='(';
    char exp[50];
    printf("\nEnter the expression : ");
    gets(exp);
    int n=strlen(exp);
    exp[n]=')',exp[n+1]='\0';
    printf("\n(%s = ",exp);
    for(int i=0;i<=n;i++){
        if(exp[i]==' ')
            continue;
        else if(exp[i]==')'){
            while(stk[top]!='('){
                printf("%c",stk[top]);
                top--;
            }
            top--;
        }
        else if(exp[i]=='(' || stk[top]=='(')
            push(exp[i]);
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^' || exp[i]=='%'){
            int on=prior(stk[top]),co=prior(exp[i]);
            while(co<=on && top>0 && stk[top]!='('){
                printf("%c",stk[top]);
                top--;
                on=prior(stk[top]);
            }
            push(exp[i]);
        }
        else
            printf("%c",exp[i]);
    }
    printf("\n\n");
    return 0;
}
