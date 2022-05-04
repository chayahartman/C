#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct {

	int day;
	int month;
	int year;
	лл
}date;

typedef struct {

	int code;
	char name[12];
	float price;
	date finalDate;

}product;



void addProd(product* p)
{
	date d = p->finalDate;
	printf("Please enter details for new product-(name,code,price,finalSaleDate(day,month,year))");
	scanf("%s", (&(*p).name));
	scanf("%d%f", (&(*p).code),(&(*p).price));
	scanf("%d%d%d", &d.day, &d.month, &d.year);
	(*p).finalDate = d;

}


void printProd(product* p)
{
	printf("product details:\nname:%s\ncode:%d\nprice:%f\nfinaSalelDate:%d/%d/%d\n", p->name, p->code, p->price, p->finalDate.day, p->finalDate.month, p->finalDate.year);
}

void prodArr(product * arr)
{
	int count = 0;
	int op=0;
	do
	{
		addProd(&arr[count]);
		count++;
		printf("to finish enter 1 to continue enter 2:\n");
		scanf("%d", &op);

	} 
	while (op != 1);

	for (int i = 0; i < count; i++)
	{
		printProd(&arr[i]);
	}
	
}

void printByDate(product* arr)
{
	bool flag = 0;
	date d;
	printf("Please enter current date:(day,month,year)\n");
	scanf("%d%d%d", &d.day, &d.month, &d.year);
	for (int i = 0; i < 10; i++)
	{
		if (arr[i].finalDate.year < d.year)
			flag = 1;
		else 
			if (arr[i].finalDate.year == d.year)
            {
				if (arr[i].finalDate.month < d.month)
					flag = 1;
				else
					if (arr[i].finalDate.month == d.month && arr[i].finalDate.day < d.day)
				flag = 1;
			}
		if (flag)
			printProd(&arr[i]);
	}
}

////void main()
////{
////	/*product p;
////	addProd(&p);
////	printProd(&p);*/
////	product prod[10];
////	prodArr(prod);
////	printByDate(prod);
////}