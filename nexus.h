#ifndef NEXUS_H_INCLUDED
#define NEXUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void picnic_maze();
int picnic (int points);
void turn_off_light();
int home(int points);
int picnic();
void start ();

void start ()
{
	printf ("\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO QUEST ADVENTURES\n\t\t\t\t\t\t(press any key to start)\n");
	getchar ();
}

int shop (int points, int money)
{
	char c1, c2, c3;
	system("cls");
	printf ("| \033[0;33m_____________\033[0m\n");
	printf ("| \033[0;33m|[\033[0;31mOOOOOOOOO\033[0m\033[0;33m]|\033[0m\n");
	printf ("| \033[0;33m|[\033[1;35mQQQQQQQQQ\033[0m\033[0;33m]|    \033[0;90m ___\033[0m  (^-^)\n");
	printf ("| \033[0;33m|[\033[0;94mRRRRRRRRR\033[0m\033[0;33m]|   _\033[0;90m|___|\033[0m_/|_|\\__\n");
	printf ("| \033[0;33m|[\033[1;92mEEEEEEEEE\033[0m\033[0;33m]|   |\033[0;36m-----------\033[0;33m|\033[0m\n");
	printf ("| \033[0;33m|___________|   |\033[0;36m-----------\033[0;33m|\033[0m\n");
	printf ("|");
	printf ("\n");
	printf ("Shopkeeper: \n");
	printf ("\tHi there!\n");
	printf ("\tYou looking for something?\n");
	printf ("\tA. Yes, I'm looking for something to eat.\n");
	printf ("\tB. No, nothing thank you.\n");
	printf ("\tEnter your choice: ");
	scanf (" %c", &c1);
	
	if (c1 == 'a' || c1 =='A'){
		printf ("\tWell we have a variety of meals you can choose form:\n");
		printf ("\tA. This one includes enough food for 3 people for $50.\n");
		printf ("\tB. This one includes enough food for 2 people for $30.\n");
		printf ("\tC. This one includes enough food for 1 person for $20.\n");
		printf ("\tEnter Your choice: ");
		scanf (" %c", &c2);
		
		if (c2 == 'a' || c2 == 'A'){
			money -= 50;
		}
		else if (c2 == 'b' || c2 == 'B'){
			money -= 30;
		}
		else if (c2 == 'c' || c2 == 'C'){
			money -= 20;
		}
		else{
			printf ("\tEnter the correct option.\n");
			return points;
		}
		
		printf ("\tWould you like your stuff in a plastic or a cloth bag?\n");
		printf ("\tA. Cloth Bag\n");
		printf ("\tB. Plastic Bag\n");
		printf ("\tEnter your choice: ");
		scanf (" %c", &c3);
		if (c3 == 'a' || c3 == 'A'){
			points += 10;
		}
		if (c3 == 'b' || c3 == 'B'){
			points -= 10;
		}
		printf ("\tThank you and Come again!\n");
		printf ("You have $%d left.\n", money);
		printf ("You have %d points.\n", points);
		return points;
	}
	if (c1 == 'b' || c1 == 'B'){
		printf ("\tI see....You can come back whenever you want to. :) \n");
	}
		
	printf ("\tThank you and Come again!\n");
	return points;
}

#define SIZE 11

void generateMaze(char maze[][SIZE], int row, int col) {
    int directions[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
    int dirOrder[] = {0, 1, 2, 3};

    for (int i = 0; i < 4; ++i) {
        int r = rand() % 4;
        int temp = dirOrder[r];
        dirOrder[r] = dirOrder[i];
        dirOrder[i] = temp;
    }

    for (int i = 0; i < 4; ++i) {
        int dx = directions[dirOrder[i]][0];
        int dy = directions[dirOrder[i]][1];

        int nx = col + dx;
        int ny = row + dy;

        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && maze[ny][nx] == '#') {
            maze[row + dy / 2][col + dx / 2] = '.';
            maze[ny][nx] = '.';
            generateMaze(maze, ny, nx);
        }
    }
}

void initializeMaze(char maze[][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = '#';
        }
    }

    maze[2][2] = '.';
    generateMaze(maze, 2, 2);
}

void printMaze(char maze[][SIZE]) {
    // Print the maze
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}
void picnic_maze() {
    char maze[SIZE][SIZE];
    int playerRow = 1, playerCol = 1;

    initializeMaze(maze);

    maze[playerRow][playerCol] = 'P';

    srand(time(NULL));

    int exitRow = rand() % (SIZE - 2) + 1;
    int exitCol = rand() % (SIZE - 2) + 1;
    maze[exitRow][exitCol] = 'E';

    printMaze(maze);

    printf("\nUse 'W', 'A', 'S', 'D' to move. Enter 'Q' to quit.\n");

    char move;
    while (1) {
        scanf(" %c", &move);
        system("cls");
        
        switch (move) {
        	case 'w':
            case 'W':
                if (maze[playerRow - 1][playerCol] != '#') {
                    maze[playerRow][playerCol] = '.';
                    playerRow--;
                }
                break;
            case 'a':
            case 'A':
                if (maze[playerRow][playerCol - 1] != '#') {
                    maze[playerRow][playerCol] = '.';
                    playerCol--;
                }
                break;
            case 's':
            case 'S':
                if (maze[playerRow + 1][playerCol] != '#') {
                    maze[playerRow][playerCol] = '.';
                    playerRow++;
                }
                break;
            case 'd':
            case 'D':
                if (maze[playerRow][playerCol + 1] != '#') {
                    maze[playerRow][playerCol] = '.';
                    playerCol++;
                }
                break;
            case 'q':
            case 'Q':
                printf("You Quit! :(\n");
                exit(0);
            default:
                printf("Invalid move. Use 'W', 'A', 'S', 'D' to move. Enter 'Q' to quit.\n");
        }

        // if the player reached the exit
        if (playerRow == exitRow && playerCol == exitCol) {
            printf("Congratulations! You reached the exit.\n");
            break;
        }

        maze[playerRow][playerCol] = 'P';

        printMaze(maze);
    }

    return;
}

int picnic (int points)
{
	char c6, c7;
	system("cls");
	printf ("A. Car\n");
	printf("    \033[0;31m_________\033[0m\n");
	printf(" \033[0;31m__/\033[0;36m|__| |__|\033[0;31m\\___\033[0m\n");
	printf("\033[0;31m/__\033[0;90m(@)\033[0;31m____\033[0;90m(@)\033[0;31m___\033[1;33m*\033[0;31m\\\033[0m\n\n");
	printf ("B. Bicycle?\n");
	printf("      \033[0;34m__\033[0m\n");
  printf(" \033[0;34m__l__/\033[0m\n");
  printf("\033[0;90m(@)  (@)\033[0m\n");
  printf ("Enter your choice: ");
  scanf (" %c", &c6);
  if (c6 == 'a' || c6 == 'A'){
    points -=10;
	}
    if (c6 == 'b' || c6 == 'B'){
		points +=10;
	}
	printf ("Lets go!\n");
	system ("cls");
	picnic_maze();
	
	printf ("\tWe're here!\n");
	printf ("\n");
	printf("\033[1;32m    ^^^^       \033[0;36m_______________\033[0m  \033[1;32m^^^\033[0m\n");
	printf("\033[1;32m              \033[0;36m/ \033[0;92m(QQQ)\033[0m       \033[0;36m  /\033[0m\n");
	printf("\033[1;32m      ^^^^^  \033[0;36m/      U       /\033[0m  \033[1;32m^^\033[0m\n");
  printf("\033[1;32m            \033[0;36m/   U   \033[1;33m(YYYY)\033[0;36m /\033[0m\n");
  printf("\033[1;32m^^^^^^^^^^^\033[0;36m/______________/\033[0m\033[1;32m^^^^^^^^^^\033[0m\n");
  printf("\033[1;32m^^^^^              ^^^           ^^^^\033[0m\n");
  printf ("Clean up the place before you leave, ok?\n");
  printf ("A. Clean Up.\n");
  printf ("B. Nah.\n");
  scanf (" %c", &c7);
  if (c7 == 'a' || c7 == 'A'){
  	points += 10;
	}
	if (c7 == 'b' || c7 == 'B'){
		points -= 10;
	}
	printf ("You have &d points.\n", points);
	return points;
}

void turn_off_light ()
{
	system ("cls");
	printf("| \033[0;36m ______        \033[0;90m|\033[0m\n");
  printf("|  \033[0;36m|@@@ |       \033[0;90m/_\\\033[0m\n");
  printf("|  \033[0;36m|/--\\|         \033[0;36m         |\\\033[0m\n");
  printf("|  \033[0;36m||__||                 \033[0;36m | \\\033[0m\n");
  printf("|  \033[0;36m|____|                 \033[0;36m |  |\033[0m\n");
	printf("| \033[0;33m __________    | \033[0;36m        | *|\033[0m\n");
	printf("|  \033[0;33m |      |  ___| \033[0;36m        \\  |\033[0m\n");
	printf("|  \033[0;33m |      |  |  |  \033[0;36m        \\ |\033[0m\n");
	printf("|                            \033[0;36m\\|\033[0m\n");
}

int home (int points)
{
	char c3, c4, c5;
	system("cls");
	printf("| \033[0;36m ______        \033[0;90m|\033[0m\n");
  printf("|  \033[0;36m|@@@ |       \033[0;90m/_\\\033[0m\n");
  printf("|  \033[0;36m|/--\\|       \033[0;93m''' \033[0;36m       |\\\033[0m\n");
  printf("|  \033[0;36m||__||      \033[0;93m' ' '      \033[0;36m | \\\033[0m\n");
  printf("|  \033[0;36m|____|                 \033[0;36m |  |\033[0m\n");
	printf("| \033[0;33m __________    | \033[0;36m        | *|\033[0m\n");
	printf("|  \033[0;33m |      |  ___| \033[0;36m        \\  |\033[0m\n");
	printf("|  \033[0;33m |      |  |  |  \033[0;36m        \\ |\033[0m\n");
	printf("|                            \033[0;36m\\|\033[0m\n");
	
	printf ("Oh no! You left the tap running! Turn it off?\n");
	printf ("A. Yes.\n");
	printf ("B. No.\n");
	printf ("Enter your choice: ");
	scanf (" %c", &c3);
	if (c3 == 'a' || c3 == 'A'){
		points +=10;
	}
	if (c3 == 'b' || c3 == 'B'){
		printf ("You should not waste water.\n");
		points -= 10;
	}
	
	printf ("It's day-time. Turn off the light?\n");
	printf ("A. Yes.\n");
	printf ("B. No.\n");
	printf ("Enter your choice: ");
	scanf (" %c", &c4);
	if (c4 == 'a' || c4 == 'A'){
		turn_off_light();
	}
	if (c4 == 'b' || c4 == 'B'){
		printf ("You should try to conserve energy.\n");
	}
	printf ("How about you go for a picnic?\n");
	printf ("A. Yes.\n");
	printf ("B. No.\n");
	printf ("Enter your choice: ");
	scanf (" %c", &c5);
	if (c5 == 'a' || c5 == 'A'){
		system ("cls");
		printf ("Lets go!");
		picnic (points);
	}
	if (c5 == 'b' || c5 == 'B'){
		printf ("You're such a boring person. (-_-)\n");
		printf ("You have &d points.\n", points);
	}
	return points;
}
#endif // NEXUS_H_INCLUDED
