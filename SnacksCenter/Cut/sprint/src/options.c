#include<stdio.h>
#include<stdlib.h>
#include<functions.h>
void options( )
{
	int choice;
	while(1)
	{
		clear( );
		printf("\nPress 1 for Admin ");
		printf("\nPress 2 for Customer ");
		printf("\nPress 3 for Exit ");
		printf("\nPlease Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: int result = admin( );
			if(result == 1)
				menu_admin( );
			else
				printf("\nUsername and password is incorrect ");
			break;
		case 2:menu_user();
			break;
		case 3: exit(0);
		}
	}
}