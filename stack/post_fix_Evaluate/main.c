// C program to evaluate value of a postfix expression
/*Mohamed khaled*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{

    int top;
    int size;
    int *arr;
};


struct stack *CreatStack(int len)
{

    // Creat stack into Heap
   struct stack *Stack =(struct stack *)malloc(sizeof(struct stack));

   if(!Stack)
     return NULL;

   Stack->size=len;
   Stack->top=-1;

   Stack->arr=(struct stack *)malloc(Stack->size* sizeof(int));

   if(!Stack->arr)
      return NULL;

   return Stack;

}

void push(struct stack *stack, char operand)
{
   stack->arr[++stack->top]=operand;
}

int stackEmpty(struct stack *stack)
{
    if(stack->top ==-1) return 1;
    else
       return 0;
}

char pop(struct stack *stack)
{
    if(!stackEmpty(stack))
         return stack->arr[stack->top--];

    return '$';

}


char peek(struct stack* stack)
{
    return stack->arr[stack->top];
}




int evaluatPostFix(char *post)
{
    int i;
    int len=strlen(post);
    struct stack *STACK=CreatStack(len);

    if (!STACK)
        return -1;

    for(i=0;i<len;i++)
    {
        if(isdigit(post[i]))
        {
           push(STACK, post[i] - '0');


        }
        else
        {
            int val1=pop(STACK);
            int val2=pop(STACK);
            switch (post[i]) {
            case '+':
                push(STACK, val2 + val1);

                break;
            case '-':
                push(STACK, val2 - val1);

                break;
            case '*':
                push(STACK, val2 * val1);

                break;
            case '/':
                push(STACK, val2 / val1);
                break;
            }
        }
    }

  return pop(STACK);

}



int main(void)
{


char exp[] = "231*+9-";

    // Function call
    printf("postfix evaluation: %d", evaluatPostFix(exp));


    return 0;
}
