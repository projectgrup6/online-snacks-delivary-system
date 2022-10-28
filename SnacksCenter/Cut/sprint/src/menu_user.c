#include<functions.h>
#include<struct.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int generate_orderID()
{
	int orderID;
	FILE *f = fopen("../data/gen.txt", "r");
	FILE *t = fopen("../data/temp.txt", "w");

	fscanf(f, "%d", &orderID);
	//printf("\n%d", orderID);
	int oid=orderID;
	orderID=orderID+ 1;
	
	fprintf(t, "%d", orderID);
	fclose(f);
	fclose(t);
	remove("../data/gen.txt");
	rename("../data/temp.txt","../data/gen.txt");
	
	return oid;
}
void order_menu()
{
	
	int distance,qty,item_code;
	long long int mobilenumber; 
	char name[Max];
	printf("\n\nEnter your name :");
	scanf("%s",name);
	printf("\n\nEnter Mobile Number :");
	scanf("%lld",&mobilenumber);
	printf("\n\nEnter the distance between the snack center and your address : ");
	scanf("%d",&distance);
	int id=generate_orderID( );
	int ic , p ,q;
	char in[Max];
	int flag =0;
	int total=0;
	if(distance<=10)
	{
		FILE *fw = fopen("../data/order.txt","a");
		FILE *fr = fopen("../data/food.txt","r");		
		printf("\n\nEnter the food by item_code :");
		scanf("%d",&item_code);
		printf("\n\nEnter quantity : ");
		scanf("%d",&qty);
		
		fscanf(fr,"%d%s%d%d",&ic,in,&p,&q);
		while(!feof(fr))
		{
			if ( item_code == ic)
			{
				printf("\n\nOrdered food item :%s",in);
				total = p * qty;
				flag = 1;
				fprintf(fw,"%d %s %lld %d %d\n",id,name,mobilenumber,item_code,qty);
				
			}
			fscanf(fr,"%d%s%d%d",&ic,in,&p,&q);
		}
		fclose(fr);
		fclose(fw);

		if (flag == 0)
			printf("\n\nItem code is not present in the menu ");
		else
		{
			fw = fopen("../data/temp.txt","w");
			fr = fopen("../data/food.txt","r");		
			fscanf(fr,"%d%s%d%d",&ic,in,&p,&q);
		while(!feof(fr))
		{
			if ( item_code == ic)
				q = q - qty;
			fprintf(fw,"%d %s %d %d\n",ic,in,p,q);
			fscanf(fr,"%d%s%d%d",&ic,in,&p,&q);
		}	
		fclose(fw);
		fclose(fr);
		remove("../data/food.txt");
		rename("../data/temp.txt","../data/food.txt");	
			printf("\n\nTotal Bill is = %d",total);
			printf("\n\nTHANK YOU FOR ORDERING");
			printf("\n\nYour order is confirmed, Will deliver your food shortly"); 	
		}	
	}
	else
		printf("Apologies.We can deliver orders only for 10km range");
}
void menu_user()
{
	int choice;
	food *head=NULL;
	while(1)
	{

		printf("\n1:Display Menu");
		printf("\n2:Order Snacks");
		printf("\n3:Back to Main Menu");
		printf("\nEnter Your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: display( );
				break;
			case 2: order_menu( );
				break;
			case 3: options( );
				
		}
	}
	
}
