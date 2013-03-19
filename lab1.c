#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define N 6

struct hospital_info
{
	int hospital_num;
	char hospital_addr[20];
	char hospital_doctor[20];
};

struct child_disease
{
	char disease[20];
	char local_doctor[20];
	struct hospital_info hos;
};

struct child_info
{
	char surname[20];
	char name[20];
	int birthyear;
	struct child_disease dis_info;
} list[N] = {
	{"Worldson", "Michael", 2009, {"angina", "Sheperd", {39, "Wallstreet-15", "Sykes"} } },
	{"Walker", "John", 2005, {"influenza", "Emery"} },
	{"Wild", "Sue", 2008, {"pneumonia", "Burns", {83, "Kazinca-90", "Averyanov"} } },
	{"Braker", "Jessica", 2006, {"pneumonia", "Burns", {83, "Kazinca-90", "Averyanov"} } },
	{"Smith", "Ahmed", 2007, {"angina", "Burns"} },
	{"Kerrigan", "Sarah", 2331, {"pneumonia", "Burns", {83, "Kazinca-90", "Averyanov"} } }
	};

int alphabet_sort();
int print_surnames();
int print_table();

int main()
{	
	printf("\n---------------lab1.4------------\n\n");

	print_table();

	alphabet_sort();

	print_surnames();

	printf("\n---------------------------------\n\n");

	return 0;
}

int alphabet_sort()
{
	int i, j;

	struct child_info temp;

	for(i=0; i<N-1; i++)
	{
		for(j=i; j<N; ++j)
		{
			if(strcmp(list[j].surname, list[i].surname)<0)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}

	return 0;
}

int print_surnames()
{

	char disease[15];

	printf("\n\nEnter the name of disease: ");
	scanf("%s", disease);

	int i=0, j=1, head=1, exist=0;

	while(i<N)
	{
		if(disease[0] == list[i].dis_info.disease[0])
		{
			j=1;
			while(disease[j] == list[i].dis_info.disease[j] && disease[j] && list[i].dis_info.disease[j])
			{
				j++;
			}
			if(!disease[j] && !list[i].dis_info.disease[j])
			{
				if(head == 1) 
				{
					printf("\nChildren with %s:\n\n", disease);
					head = 0;
				}
				printf("%s %s\n", list[i].surname, list[i].name);
				exist = 1;				
			}
		}
		i++;
	}

	if(exist == 0)
	{
		printf("\nChildren with %s are not found", disease);
	}

	return 0;
}

int print_table()
{
	while(1)
	{
		char answer;

		printf("Do you want to print table? (requires full-screen mode) (y/n) ");	

		answer = getchar();

		__fpurge(stdin);

		if(answer == 'y' || answer == 'Y')	
		{
			int i;
			printf("\n%15s %10s %7s %15s %15s %15s %20s %15s\n", "Name", "Surname", "Year", "Disease", "Loc. doctor", "Hospital #", "Hospital addr.", "Hos. doctor");
			for(i=0;i<N;i++)
			{
				printf("\n");
				printf("%15s %10s %7d %15s %15s", list[i].surname, list[i].name, list[i].birthyear, list[i].dis_info.disease, list[i].dis_info.local_doctor);
				if(list[i].dis_info.hos.hospital_num != 0) 
				{
					printf("%15d %20s %15s", list[i].dis_info.hos.hospital_num, list[i].dis_info.hos.hospital_addr, list[i].dis_info.hos.hospital_doctor);
				}
			}
			break;
		}
		if(answer == 'n' || answer == 'N') break;
	}
	return 0;
}


#ifdef __cplusplus
}
#endif
