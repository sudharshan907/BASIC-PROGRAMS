#include <stdio.h>
#include <stdlib.h>
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};
int isFull(struct Stack* stack)
{  return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack) {
    if(stack->top == -1)
    	return 1;
	else
	return -1;
	}
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}
void push(struct Stack* stack, int j)
{
    if (isFull(stack))
		return;
    else
	stack->array[++stack->top] = j;   }
int pop(struct Stack* stack)
{
    if (isEmpty(stack)==1)
	    return -1;
    else
	return stack->array[stack->top--];
}
int main()
{     int g;
    scanf("%d",&g);
    struct Stack* stack = createStack(g);
    int k;
    char b;
    while(1){
    	scanf("%c",&b);
			if(b=='e')
			printf("%d",-isEmpty(stack));
				if(b=='i'){
    			scanf("%d",&k);
    			push(stack,k);	}
    		if(b=='d')
				printf("%d",pop(stack));
    		if(b=='t')
				break;
	    }
    return 0;
}
