
/* infix to postfix */
/*Mohamed_Khlaed*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100



int isoperator(char ch)
{
      return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
            || ch == '^');
}





int check_Associativity(char p)
{


   switch(p)
   {

    case '+':
    case '-':
       return 1;
    case '*':
    case '/':
       return 2;
    case '^':
       return 3;
    default:
       return -1;

   }


}


char *infixToPostfix(char *infix )
{

    int len=strlen(infix);
    char *post =(char *)malloc(sizeof(char) * (len+2));
    char stack[MAX_EXPR_SIZE];
    int top=-1;
    int i,j;
    for(i=0,j=0;i<len;i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

       if(isalnum(infix[i]))
       {
           post[j++]=infix[i];
       }
       else
         {

          if(infix[i]=='(')
          {
            stack[++top]=infix[i];

          }
          else if(infix[i]==')')
          {

            while(top> -1 && stack[top]!='(')
                 post[j++]=stack[top--];
            top--;
          }
          else if(isoperator(infix[i]))
          {

            while (top> -1 && check_Associativity(stack[top])>=check_Associativity(infix[i]))
            {
                post[j++]=stack[top--];
            }

            stack[++top]=infix[i];

          }

         }


    }

    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        post[j++] = stack[top--];
    }
    post[j] = '\0';
    return post;

}


int main()
{
    char infix[MAX_EXPR_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";

    // Function call
    char* postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    free(postfix);

return 0;
}
