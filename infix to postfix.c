#include<stdio.h>
#include<string.h>

int temp,length=0,inx=0,pos=0,top=-1;
char symbol,infix[20],postfix[20],stack[30];

void push(char);
char pop();
int precedence(char);
void infix_to_postfix(char[]);


int main()
{
        printf("\nEnter an infix expression:\n");
        gets(infix);
        infix_to_postfix(infix);
        printf("\nThe equivalent postfix expression:\n");
        puts(postfix);
        return 0;
}
void push(char symbol)
{
        top=top+1;
        stack[top]=symbol;
}

char pop()
{
        temp=stack[top];
        top=top-1;
        return temp;
}
int precedence(char symbol)
{
        int priority;
        switch(symbol)
        {
                case '#':
                                priority=0;
                                break;

                case '(':
                case ')':
                                priority=1;
                                break;

                case '+':
                case '-':
                                priority=2;
                                break;

                case '*':
                case '/':
                                priority=3;
                                break;
                case '^':
                                priority=4;
                                break;
        }
        return priority;
}
void infix_to_postfix(char infix[])
{
        length=strlen(infix);
        push('#');
        while(inx<length)
        {
                symbol=infix[inx++];
                switch(symbol)
                {
                        case '(':
                                        push(symbol);
                                        break;
                        case ')':
                                        temp=pop();
                                        while(temp!='(')
                                        {
                                                postfix[pos++]=temp;
                                                temp=pop();
                                        }//end of while()
                                        break;
                        case '-':
                        case '+':
                        case '*':
                        case '/':
                        case '^':
                                        while(precedence(stack[top])>=precedence(symbol))
                                        {
                                                temp=pop();
                                                postfix[pos++]=temp;
                                        }
                                        push(symbol);
                                        break;
                        default:
                                        postfix[pos++]=symbol;
                                        break;
                }
        }

        while(top>0)
        {
                temp=pop();
                postfix[pos++]=temp;
                postfix[pos]='\0';

        }
}


