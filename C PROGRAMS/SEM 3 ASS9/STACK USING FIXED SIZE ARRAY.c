#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,n1,top=-1;

scanf("%d",&n);

int *a=(int *)malloc(n*sizeof(int));

char c;

while(1){

	scanf("%c",&c);

	if(c=='i'){

		scanf("%d",&n1);

		if(top!=(n-1)){

		top++;

			*(a+top)=n1;}

			}

	if(c=='d'){

		if(top==-1)

		printf("-1\n");

		else{

			printf("%d\n",*(a+top));

			top--;

			}

			}

	if(c=='e'){

		if(top==-1)

		printf("-1\n");

		else

		printf("1\n");

		}

	if(c=='t')

		break;

		}
    return 0;
}
