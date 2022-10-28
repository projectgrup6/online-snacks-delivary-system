#include<functions.h>
#include<stdlib.h>
#include<stdio.h>
#include<struct.h>
#include<string.h>
food *head = NULL;
void add_record( )
{
	FILE *fp = fopen("../data/food.txt","a");
	int item_code , stock , price ;
	char food_item[30];
	printf("\n\nEnter th item_code : ");
	scanf("%d",&item_code);
	printf("\n\nEnter the food_item : ");
	scanf("%s",food_item);
	printf("\n\nEnter the price : ");
	scanf("%d",&price);
	printf("\n\nEnter the stock : ");
	scanf("%d",&stock);	
	fprintf(fp,"%d %s %d %d\n",item_code,food_item,price,stock);
		
fclose(fp);
}


void display( )
{
	FILE *fr = fopen("../data/food.txt","r");
	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		
		char food_item[Max];
		int price,item_code,s;
		printf("\n**************************************************************\n");
		printf("\n*              		 FOOD ITEMS MENU               	      *\n");
		printf("\n**************************************************************\n");
		printf("%-10s%-20s%-20s%s","item_code","food_item","price","Stock");
		fscanf(fr,"%d%s%d%d",&item_code,food_item,&price,&s);
		while(!feof(fr))
		{
			printf("\n%-10d%-20s%-20d%d",item_code,food_item,price,s);
			fscanf(fr,"%d%s%d%d",&item_code,food_item,&price,&s);	
		}
		fclose(fr);
	}
}
void display_orders()
{
	FILE *fr = fopen("../data/order.txt","r");
	if(fr == NULL)
	{
		printf("\n\nFile does not exists: ");
	}
	else
	{
		
		char name[Max];
		long long int mobilenumber;
		int id,item_code,qty;
		printf("\n****************************************************************\n");
		printf("\n*                   CUSTOMER ORDERS LIST                       *\n");
		printf("\n****************************************************************\n");
		printf("%-10s%-10s%-20s%-10s%s","id","name","mobilenumber","item_code","qty");
		fscanf(fr,"%d%s%lld%d%d",&id,name,&mobilenumber,&item_code,&qty);
		while(!feof(fr))
		{
			printf("\n%-10d%-10s%-20lld%-10d%d",id,name,mobilenumber,item_code,qty);
			fscanf(fr,"%d%s%ld%d%d",&id,name,&mobilenumber,&item_code,&qty);
		}
	}
}
void delete()
{
	FILE *fr = fopen("../data/food.txt","r");
	FILE *fw = fopen("../data/foods.txt","w");
	int item_code,price,no,stock;
	char food_item[Max];
	
	printf("\n\nEnter the item_code to be deleted: ");
	scanf("%d",&no);
	fscanf(fr,"%d%s%d%d",&item_code,food_item,&price,&stock);
	while(!feof(fr))
	{
		if(item_code!=no)
	
			fprintf(fw,"%d %s %d %d\n",item_code,food_item,price,stock);
			fscanf(fr,"%d%s%d%d",&item_code,food_item,&price,&stock);
	
		
	}
	fclose(fr);
	fclose(fw);
	remove("../data/food.txt");
	rename("../data/foods.txt","../data/food.txt");
}

void delete_orders()
{
	FILE *fr = fopen("../data/order.txt","r");
	FILE *fw = fopen("../data/orders.txt","w");
	long long int mobilenumber;
	int id,item_code,qty,no;
	char name[Max];
	
	printf("\n\nEnter the orderId to be deleted: ");
	scanf("%d",&no);
	fscanf(fr,"%d%s%d%d%d",&id,name,&mobilenumber,&item_code,&qty);
	while(!feof(fr))
	{
		if(id!=no)
	
			fprintf(fw,"%d %s %lld %d %d\n",id,name,mobilenumber,item_code,qty);
			fscanf(fr,"%d%s%lld%d%d",&id,name,&mobilenumber,&item_code,&qty);
	
		
	}
	fclose(fr);
	fclose(fw);
	remove("../data/order.txt");
	rename("../data/orders.txt","../data/order.txt");
}
		
void update()
{
     FILE *fr = fopen("../data/food.txt","r");
	FILE *fw = fopen("../data/foods.txt","w");
	int item_code,price,no,no1,price1,stock;
	char food_item[Max],food_item1[Max];
	
	printf("\n\nEnter the item_code to be updated: ");
	scanf("%d",&no);
	fscanf(fr,"%d%s%d%d",&item_code,food_item,&price,&stock);
	while(!feof(fr))
	{
		if(item_code!=no)
		
			fprintf(fw,"%d %s %d %d\n",item_code,food_item,price,stock);
			
		
		else
		{
			printf("\n\nEnter food_item: ");
			scanf("%s",food_item1);
			printf("\n\nEnter the price: ");
			scanf("%d",&price1);
			fprintf(fw,"%d %s %d %d\n",item_code,food_item1,price1,stock);
		}
		fscanf(fr,"%d%s%d%d",&item_code,food_item,&price,&stock);
		
	}

	fclose(fr);
	fclose(fw);
	remove ("../data/food.txt");
	rename("../data/foods.txt","../data/food.txt");
}

	

void menu_admin( )
{
	int choice;
	food *head = NULL;
	while(1)
	{
		printf("\n\n1:Add the menu\n\n2:Display the menu\n\n3:Display the orders\n\n4:delete the item\n\n5:delete the orders\n\n6:update the order\n\n7:Back to main menu");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: add_record();
				break;
			case 2: display();
				break;
			case 3:display_orders( );
				break;
			case 4: delete();
				break;
			case 5:delete_orders( );
				break;
			case 6:update();
				break;
			case 7: options();
				
		}
	}
}

