#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct car
{
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


void print_menu();
void print_all(struct car array[], int size);
void brand(struct car array[], int size );
void print_russia(struct car array[], int size);


int main()
{
	int switcher = 0;
	int amount = 0;

	printf("Enter amount of cars:\n");
	scanf("%d", &amount);

	struct car* array = malloc(sizeof(struct car) * amount);

	for (int i = 0; i < amount; i++)
	{
		printf("%d car:", i + 1);
		array[i].id = i + 1;
		printf("Enter model ");
		scanf("%s", array[i].model);
		printf("Enter brand ");
		scanf("%s", array[i].brand);
		printf("Enter country_maker ");
		scanf("%s", array[i].country_maker);
		printf("Enter price ");
		scanf("%d", &array[i].price);
		printf("Enter color ");
		scanf("%s", array[i].color);

		char c;

		printf("Enter condition: for new-'n', for second-hand-'s': ");
		scanf(" %c", &c);

		if (c == 'n')
		{
			strcpy(array[i].condition,"New");
		}
		else
		{
			strcpy(array[i].condition,"Second-hand");
		}

		printf("\nEnter kilometrs ");
		scanf("%d", &array[i].kilometrs);
		printf("Enter amount of repairs ");
		scanf("%d", &array[i].amount_repair);
	}

	do
	{
		print_menu();
		printf("Enter number of operation, to exit enter -1: ");
		scanf("%d", &switcher);
		system("cls");
		switch (switcher)
		{
			case 1:  //вывод всех машин
			{
				print_all(array, amount);
				break;
			}

			case 2:  //вывод б/у машин указанной марки с отсутсвием ремонта в указаном ценовом диапазоне
			{
				brand(array, amount);
				break;
			}

			case 3:  //вывод списка всех отечественных автомобилей
			{
				print_russia(array, amount);
				break;
			}

			case 4:  //сортировать по id
			{
				break;
			}

			case 5:  //сортировть по цене
			{
				break;
			}

			case 6:  //сортировать в начале новые потом бу
			{
				break;
			}

			case -1:  //выход из switch
			{
				break;
			}

			default:  //не тот номер команды
			{
				printf("Incorrect number of operation\n");
			}
		}

	} while (switcher != -1);

	return 0;
}


void print_menu()
{
	printf("-------------------------------------------------------------------------------------------------------\n");
	printf("1-Print all cars\n");
	printf("2-Print all second-hand cars define brand without any repairs these price\n");
	printf("3-Print all cars of Russian\n");
	printf("4-Sorting of id\n");
	printf("5-Sorting of price\n");
	printf("6-Sorting of new or second-hand\n");
	printf("-------------------------------------------------------------------------------------------------------\n");
}


void print_all(struct car array[], int size)
{
printf("-------------------------------------------------------------------------------------------------------\n");	
printf("%3s %10s %15s %15s %6s %10s %15s %20s %15s\n","ID:", "Model", "Brand", "Country_maker", "Price", "Color", "Condition", "Kilometres", "Amount_repairs");
	
	for (int i = 0; i < size; i++)
	{
		printf("%3d %10s %15s %15s %6d %10s %15s %20d %15d\n", array[i].id, array[i].model, array[i].brand, array[i].country_maker, array[i].price, array[i].color, array[i].condition, array[i].kilometrs, array[i].amount_repair);
	}

	printf("-------------------------------------------------------------------------------------------------------\n");
}


void brand(struct car array[], int size)
{
	int min_price = 0, max_price = 0;
	char brand1 [20] = "";


	printf("Enter minimal price: \n");
	scanf("%d", &min_price);
	printf("Enter maximum price: \n");
	scanf("%d", &max_price);
	printf("Enter brand: \n");
	scanf("%s", &brand1);

	for (int i = 0; i< size; i++)
	{
		if ((strcmp(array[i].condition,"Second-hand") == 0) && (strcmp(array[i].brand, brand1) == 0))
		{ 
			if ((array[i].amount_repair == 0) && (array[i].price >= min_price))
			{ 
				if (array[i].price <= max_price)
				{
					printf("Define car: %s\n", array[i].model);
				}
			}
		}
	}
}


void print_russia(struct car array[], int size)
{
	printf("%3s %10s %15s %6s %10s %15s %20s %15s\n","ID:", "Model", "Brand","Price", "Color", "Condition", "Kilometres", "Amount_repairs");
	for (int i = 0; i < size; i++) {
		if (strcmp(array[i].country_maker, "Russia") == 0 )
		{
			printf("%3d %10s %15s %6d %10s %15s %20d %15d\n", array[i].id, array[i].model, array[i].brand, array[i].price, array[i].color, array[i].condition, array[i].kilometrs, array[i].amount_repair);
		}
	}
}