#include <stdio.h>
#include <string.h>


struct car {
	int id;
	char model[20];
	char brand[20];
	char country_maker[20];
	int price;
	char color[10];
	char condition[20];
	int kilometrs;
	int amount_repair;	
};


void print_all(struct car c_array[]);
void brand(struct car c_array[]);
void print_russia(struct car c_array[]);



int main()
{
	struct car car_array[10] = {
		{
			1, "X6", "BMW", "Germany", 10000, "Black", "New", 0, 0
		},
		{
			2, "E-tron", "Audi", "Germany", 8000, "Yellow", "Second-hand", 7000, 2
		},
		{
			3, "Corrola", "Toyta", "Japan", 9000, "White", "New", 0, 0
		},
		{
		    4, "Solaris", "Hyundai", "South Korea", 7600, "Orange", "Second-hand", 6900, 3
		},
		{
			5, "CR-V", "Honda", "Japan", 6500, "Blue", "Second-hand", 10000, 4
		},
		{
			6, "488 GNB", "Ferrari", "Italy", 15000, "Red", "New", 0, 0
		},
		{
			7, "Gazel", "GAZ", "Russia", 6000, "Black", "New", 0, 0
		},
		{
			8, "Granta",  "LADA", "Russia", 4900, "Gray", "Second-hand", 10000, 5
		},
		{
			9, "X5",  "BMW", "Germany", 7000, "Yellow", "Second-hand", 6500, 0
		}
		
	};
	
	
	int switcher = 0;
	
	printf("-------------------------------------------------------------------------------------------------------\n");
	printf("1-Print all cars\n");
	printf("2-Print all second-hand cars define brand without any repairs these price\n");
	printf("3-Print all cars of Russian\n");
	printf("4-Sorting of id\n");
	printf("5-Sorting of price\n");
	printf("6-Sorting of new or second-hand\n");
	printf("-------------------------------------------------------------------------------------------------------\n");
	do {
	   printf("Enter number of operation, to exit enter -1: ");
	   scanf("%d", &switcher);
	    switch (switcher) 
		{
		   case 1://вывод всех машин
		   {
			   print_all(car_array);
			   break;
		   }
           case 2://вывод бу машин указанной марки с отсутсвием ремонта в указаном ценовом диапазоне
		   {
			   brand(car_array);
			   break;
		   }
           case 3://вывод списка всех отечественных автомобилей
		   {
			   print_russia(car_array);
			   break;
		   }
           case 4://сортировать по id
		   {
			   break;
		   }
           case 5://сортировть по цене
		   {
			   break;
		   }
           case 6://сортировать в начале новые потом бу
		   {
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


void print_all(struct car c_array[])
{
    printf("-------------------------------------------------------------------------------------------------------\n");	
	printf("%3s %10s %15s %15s %6s %10s %15s %20s %15s\n","ID:", "Model", "Brand", "Country_maker", "Price", "Color", "Condition", "Kilometres", "Amount_repairs");
	for (int i = 0; i <= 8; i++){		
		printf("%3d %10s %15s %15s %6d %10s %15s %20d %15d\n", c_array[i].id, c_array[i].model, c_array[i].brand, c_array[i].country_maker, c_array[i].price, c_array[i].color, c_array[i].condition, c_array[i].kilometrs, c_array[i].amount_repair);
	}
	printf("-------------------------------------------------------------------------------------------------------\n");
}


void brand(struct car c_array[])
{
	int min_price = 0, max_price = 0;
	char brand1 [20] = "";
	
	
	printf("Enter minimal price: \n");
	scanf("%d", &min_price);
	printf("Enter maximum price: \n");
	scanf("%d", &max_price);
	printf("Enter brand: \n");
	scanf("%s", &brand1);
	for (int i = 0; i<= 8; i++){
		if ((strcmp(c_array[i].condition,"Second-hand") == 0) && (strcmp(c_array[i].brand, brand1) == 0)){ 
	       if ((c_array[i].amount_repair == 0) && (c_array[i].price >= min_price)){ 
			   if (c_array[i].price <= max_price){
	              printf("Define car: %s\n", c_array[i].model);
		       }
		   }
		}   	
	}
}

void print_russia(struct car c_array[])
{
	printf("%3s %10s %15s %6s %10s %15s %20s %15s\n","ID:", "Model", "Brand","Price", "Color", "Condition", "Kilometres", "Amount_repairs");
	for (int i = 0; i <= 8; i++) {
		if (strcmp(c_array[i].country_maker, "Russia") == 0 )
		{
			printf("%3d %10s %15s %6d %10s %15s %20d %15d\n", c_array[i].id, c_array[i].model, c_array[i].brand, c_array[i].price, c_array[i].color, c_array[i].condition, c_array[i].kilometrs, c_array[i].amount_repair);
		}
	}
}
