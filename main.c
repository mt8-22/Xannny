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
	struct car car_array[6] = {
		{
			1, "BMV", "Germany", 10000, "Black", "New", 0, 0
		},
		{
			1, "Audi", "Germany", 8000, "Yellow", "Second-hand", 7000, 2
		},
		{
			1, "Toyta", "Japan", 9000, "White", "New", 0, 0
		},
		{
		    1, "Hyundai", "South Korea", 7600, "Orange", "Second-hand", 6900, 3
		},
		{
			1, "Honda", "Japan", 6500, "Blue", "Second-hand", 10000, 4
		},
		{
			1, "Ferrari", "italy", 15000, "Red", "New", 0, 0
		}
		
	};
	return 0;
}