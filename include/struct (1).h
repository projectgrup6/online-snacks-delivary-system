#include<macros.h>
typedef struct food
{
	int price,item_code;
	char food_item[Max];
	struct food *link;
}food;

typedef struct order
{
	char name[Max];
	int qty,item_code;
	struct order *link;
}orders;





