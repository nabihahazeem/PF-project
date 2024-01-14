#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "nexus.h"

void picnic_maze();
int picnic (int points);
void turn_off_light();
int home(int points);
int picnic();
void start ();

int main ()
{
	char choice;
	int points = 50;
	int money = 50;
	for (int i = 1; i < 6; i++){
		system("cls");
		start ();
		system("cls");
		printf ("\t\t\t\t\033[1;32m[[[QUEST ADVENTURES]]]\033[0m\n\n");
		printf ("\t\t DAY %d\t\t\t HEALTH: \033[0;31m%d\033[0m\t\t\t\tMONEY: \033[1;32m$%d\033[0m", i, points, money);
		printf ("\n");
		printf("\033[1;33m  \\__/ \033[0m                       @@@@@@@            @@@@@@\n");
		printf("\033[1;33m__/  \\__ \033[0m                    @@@@@@@@@@         @@@@@@@@\n");
		printf("\033[1;33m  \\__/ \033[0m                       @@@@@@@                @@@@@\n");
		printf("\033[1;33m  /  \\ \033[0m   @@       @@@@@@\n");
		printf("       @@@@       @@@@@@     @@                            \033[1;90m(     )\033[0m        \n");
		printf("       @@@@@                          \033[1;90m\\/                  (     )       \\/\033[0m\n");
		printf("                                                           \033[1;90m(   )\033[0m\n");
		printf("     \033[1;90m\\/                \\/\033[0m                                 \033[0;31m _____\033[0m\n");
	  printf(" \033[0;34m  _____________________ \033[0m                      \033[0;31m____________|___|__\033[0m\n");
	  printf("\033[0;34m  /  /  /  / | \\  \\  \\  \\  \033[0;32m @@@@             \033[0;31m /___|____|____|_____\\  \033[0;32m@@@@@@\033[0m\n");
	  printf("\033[0;34m /  /  /  /  |  \\  \\  \\  \\\033[0m \033[0;32m@@@@@@\033[0m          \033[0;31m  /______|___|____|_____\\\033[0m\033[0;32m@@@@@@@\033[0m\n");
	  printf("\033[0;34m/__/__/__/___|___\\__\\__\\__\\\033[0m\033[0;32m@@@@@@@@ \033[0m       \033[0;31m /___|____|_________|____\\\033[0m\033[0;32m@@@@@@@@\033[0m\n");
	  printf("\033[0;36m|   /   |    |    |       |\033[0;32m@@@@@@@\033[0m          |  \033[0;36m______ \033[0;33m______ \033[0;36m______ \033[0m|\033[0;32m@@@@@@@\033[0m\n");
	  printf("\033[0;36m|  //   |    |    |   //  |\033[0;32m @|@|@ \033[0m          |  \033[0;36m|____| \033[0;33m|    | \033[0;36m|____| \033[0m|\033[0;32m@|@|@\033[0m     \n");
	  printf("\033[0;36m|_______|___*|*___|_______| \033[0;33m | |   \033[0;32m @@@@@@@@\033[0m|  \033[0;36m|____| \033[0;33m|    | \033[0;36m|____|\033[0m | \033[0;33m| |\033[0m\n");
	  printf("|-------\033[0;36m|    |    |\033[0m-------| \033[0;33m | |  \033[0;32m@@@@@@@@@@\033[0m|         \033[0;33m|   *|\033[0m        | \033[0;33m| |\033[0m    \n");
	  printf("|_______\033[0;36m|____|____|\033[0m_______|  \033[0;33m| |\033[0;32m^^@@@@@@@@@@\033[0m|_________\033[0;33m|____|\033[0m________| \033[0;33m| |\033[0m\033[0;32m^^^^^^^^\033[0m\n\n");
		printf ("\tA. Shop\t\t\t\t\t\tB. Home\n");
		printf ("Choose an option:\n");
		printf ("Enter your choice:");
		scanf (" %c", &choice);
		switch (choice)
		{
			case 'a':
			case 'A':{
				shop (points, money);
				getchar ();
				break;
			}
			case 'b':
			case 'B':{
				home (points);
				getchar ();
				break;
			}
		}
		system ("cls");
		printf ("\t\t\t\tDAY %d ENDS!\n\n", i);
		getchar ();
	}
	return 0;
}
