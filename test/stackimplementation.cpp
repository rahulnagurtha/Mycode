#include <stdio.h>
int main()
{
	int a[10],num,option;
	int position=-1;
	while(1)
	{
		printf("1.push the element into stack\n");
		printf("2.pop the element\n");
		printf("3.size of the stack\n");
		printf("4.to exit\n");
		printf("choose any of the above operation:\n");
		scanf("%d",&option);
		if(option==4) break;
		switch(option)
		{
			case 1:
				if(position==9) printf("stack is full\n");
				else{
					printf("enter the number:\n");
					position++;
					scanf("%d",&num);
					a[position]=num;
				}
				break;\
			case 2:
				if(position==-1) printf("the stack is empty\n");
				else{
					printf("%d is popped out\n",a[position--]);
				}
				break;
			case 3:
				printf("the size of the stack is %d\n",position+1);
				break;
			case 4:
				printf("thank you for testing my programme\n");
				break;
		}
		printf("the elements of the stack are: ");
		for (int i = 0; i <= position; ++i) printf("%d ", a[i]);
			printf("\n");
	}
}