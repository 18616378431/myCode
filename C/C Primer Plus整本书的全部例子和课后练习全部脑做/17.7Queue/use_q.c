#include<stdio.h>
#include"queue.h"

int main()
{
	Item temp;
	Queue line;
	char ch;

	InitializeQueue(&line);
	puts("Testing th queue interface.Type a to add a value,");
	puts("type d to delete a value,and type q to quit.");
	while((ch = getchar()) != 'q')
	{
		delMore();
		if(ch != 'a' && ch != 'd')
			continue;
		if(ch == 'a')
		{
			printf("Integer to add:");
			scanf("%d",&temp);
			delMore();
			if(!QueueIsFull(&line))
			{
				printf("Putting %d into queue.\n",temp);
				EnQueue(temp,&line);
			}
			else
			{
				puts("Queue is full!");
			}
		}
		else if(ch == 'd')
		{
			if(QueueIsEmpty(&line))
			{
				puts("Nothing to delete.");
			}
			else
			{
				DeQueue(&temp,&line);
				printf("Removing %d from queue.\n",temp);
			}
		}
		printf("%d items in queue.\n",QueueItemCount(&line));
		puts("Type a to add,d to delete,q to quit:");
	}
	EmptyQueue(&line);
	puts("Bye!");
	return 0;
}