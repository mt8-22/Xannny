#include <stdio.h>


struct car {
	int id;
	char brand[20];
	char country_maker[20];
	int price;
	char color[10];
	char condition[20];
	int kilometrs;
	int amount_repair;	
};


int main()
{
	struct car car_array[8] = {
		{
			1, "BMW", "Germany", 10000, "Black", "New", 0, 0
		},
		{
			2, "Audi", "Germany", 8000, "Yellow", "Second-hand", 7000, 2
		},
		{
			3, "Toyta", "Japan", 9000, "White", "New", 0, 0
		},
		{
		    4, "Hyundai", "South Korea", 7600, "Orange", "Second-hand", 6900, 3
		},
		{
			5, "Honda", "Japan", 6500, "Blue", "Second-hand", 10000, 4
		},
		{
			6, "Ferrari", "Italy", 15000, "Red", "New", 0, 0
		},
		{
			7, "GAZ", "Russia", 6000, "Black", "New", 0, 0
		},
		{
			8, "LADA", "Russia", 4900, "Gray", "Second-hand", 10000, 5
		}
		
	};
	
	
	int switcher = 0;
	
	do {
	   printf("Enter number of operation, to exit enter -1 : ");
	   scanf("%d", &switcher);
	    switch (switcher) 
		{
		   case 1://вывод всех машин
		   {
			   printf("Print all cars\n");
			   break;
		   }
           case 2://вывод бу машин указанной марки с отсутсвием ремонта в указаном ценовом диапазоне
		   {
			   printf("Print all second-hand cars define barnd without any repairs these price\n");
			   break;
		   }
           case 3://вывод списка всех отечественных автомобилей
		   {
			   printf("Print all cars of Russian\n");
			   break;
		   }
           case 4://сортировать по id
		   {
			   printf("Sorting of id\n");
			   break;
		   }
           case 5://сортировть по цене
		   {
			   printf("Sorting of price\n");
			   break;
		   }
           case 6://сортировать в начале новые потом бу
		   {
			   printf("Sorting of new or second-hand\n");
			   break;
		   }
		   case -1:
		   {
		       break;
		   }
           default:
		   {
			   printf("Incorrect number of operation\n");
		   }
    		   
		}
	} while (switcher != -1);
	
	
	return 0;
}