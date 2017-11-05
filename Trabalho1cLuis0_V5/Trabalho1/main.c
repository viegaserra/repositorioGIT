#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

#define MAX_NAME_PLAYER 100
#define PLAYER_INITIAL_ENERGY 100
#define PLAYER_INITIAL_CELL 0
#define PLAYER_INITIAL_OBJECT -1
#define PLAYER_INITIAL_TREASURE -1

#define MAX_CELL_DESCRIPYION 500
#define MAX_CELLS 100

#define MAX_NAME_OBJECT 100
#define MAX_OBJECTS 6

#define MAX_NAME_MONSTER 100
#define MONSTER_INITIAL_ENERGY 100
#define MONSTER_INITIAL_CELL 0
#define MONSTER_INITIAL_OBJECT -1

#define MAX_LIN 80


//versao 0.0 Nuno Maruques inicialização do mapa

struct Player{
    char name[MAX_NAME_PLAYER];
    int energy;
    int cell;
    int object;
    int treasure;
};

struct Cell{
    int north;
    int south;
    int west;
    int east;
    int up;
    int down;
    char description[MAX_CELL_DESCRIPYION];
    int object;
    int treasure;
};

struct Monster{
    char name[MAX_NAME_MONSTER];
    int energy;
    int cell;
    int object;
};

struct Object{
    char name[MAX_NAME_OBJECT];
    int cell;
    int power;
  };

void InitialPlayer(struct Player *pplayer);
void PrintPlayer(struct Player *pplayer);

void InitializeMap(struct Cell cells[]);
void InitializeMapFile(struct Cell cells[]);
void PrintMap(struct Cell cells[], int nCells);

void InitialMonster(struct Monster *pmonster);
void PrintMonter(struct Monster *pmonster);

int InitialObjects(struct Object objects[]);
void PrintObject(struct Object objects[], int nObjects);

void avaiableDoors(struct Player *pplayer, struct Cell cells[], int cell);
void PlayerMove(struct Player *pplayer, int nCells, struct Cell cells[]);

void CheckTreasure(struct Player *player, struct Cell cells[]);

void CheckObject(struct Player *pplayer, struct Monster *pmonster, struct Cell cells[], struct Object Object[]);

void FightMonster(struct Player *pplayer, struct Monster *pmonster, int nCells, struct Cell cells[]);

void EndGame(struct Player *pplayer, struct Monster *pmonster, int nCells, struct Cell cells[]);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Player player;
    struct Cell cells [MAX_CELLS];
    struct Monster monster;
    struct Object objects[MAX_OBJECTS];
    int nCells, nObjects;

    printf(" -----------------------------------------------------------\n");
	printf("|             WELCOME TO THE VIKINGS WORLD                  |\n");
	printf("|            DO YOU WANT TO BE THE NEXT RAGNAR?             |\n");
	printf("|          LET ME WARN YOU THAT THE SEA HAS MANY            |\n");
	printf("|                    !!!DANGERS!!!                          |\n");
	printf(" -----------------------------------------------------------\n\n\n");

    InitialPlayer(&player);
    printf("Good Luck! %s\n", player.name);
    printf("\n");

    nCells = 18;
    //InitializeMap(cells);
    //PrintMap(cells, nCells);
    InitializeMapFile(cells);

    InitialMonster(&monster);
    printf("You are mine!!! %s hahahaha...\n\n", player.name);

    nObjects = InitialObjects(objects);

    PrintObject(objects, nObjects);
    PrintPlayer(&player);
    PrintMonster(&monster);

    avaiableDoors(&player, cells, player.cell);

    PlayerMove(&player, nCells, cells);

    CheckTreasure(&player, cells);

    CheckObject(&player, &monster, cells, objects);

    FightMonster(&player, &monster, nCells, cells);

    return 0;
}

void InitialPlayer(struct Player *pplayer){
    printf("Hello young man! Please enter your name:\n");
    scanf("%s", (*pplayer).name);

    if ((strcmp((*pplayer).name, "ragnar") == 0) || (strcmp((*pplayer).name, "RAGNAR") == 0)){

    (*pplayer).energy = PLAYER_INITIAL_ENERGY + 100000;
    (*pplayer).cell = PLAYER_INITIAL_CELL;
    (*pplayer).object = PLAYER_INITIAL_OBJECT + 3;
    (*pplayer).treasure = PLAYER_INITIAL_TREASURE;

    }else{
    (*pplayer).energy = PLAYER_INITIAL_ENERGY;
    (*pplayer).cell = PLAYER_INITIAL_CELL;
    (*pplayer).object = PLAYER_INITIAL_OBJECT;
    (*pplayer).treasure = PLAYER_INITIAL_TREASURE;
    }
}

void PrintPlayer(struct Player *pplayer){
    printf("**** Player ****\n");
    printf("Name: %s\n", pplayer->name);
    printf("Energy: %d\n", pplayer->energy);
    printf("Cell: %d\n", pplayer->cell);
    printf("Object: %d\n", pplayer->object);
    printf("Treasure: %d\n", pplayer->treasure);
}

void InitializeMap(struct Cell cells[]){
    //Cell 0
   cells[0].north = -1;
   cells[0].south =-1;
   cells[0].west = -1;
   cells[0].east= 1;
   cells[0].up = -1;
   cells[0].down= -1;
   strcpy(cells[0].description, "//TODO");
   cells[0].object = -1;
   cells[0].treasure = -1;

   //Cell 1
   cells[1].north = 7;
   cells[1].south =2;
   cells[1].west = 14;
   cells[1].east= -1;
   cells[1].up = -1;
   cells[1].down= -1;
   strcpy(cells[1].description, "//TODO");
   cells[1].object = -1;
   cells[1].treasure = -1;

   //Cell 2
   cells[2].north = 1;
   cells[2].south =3;
   cells[2].west = -1;
   cells[2].east= -1;
   cells[2].up = 5;
   cells[2].down= -1;
   strcpy(cells[2].description, "//TODO");
   cells[2].object = -1;
   cells[2].treasure = -1;

   //Cells 3
   cells[3].north = 2;
   cells[3].south =-1;
   cells[3].west = -1;
   cells[3].east= 4;
   cells[3].up = -1;
   cells[3].down= -1;
   strcpy(cells[3].description, "//TODO");
   cells[3].object = -1;
   cells[3].treasure = -1;

   //Cell 4
   cells[4].north = -1;
   cells[4].south =-1;
   cells[4].west = 3;
   cells[4].east= -1;
   cells[4].up = -1;
   cells[4].down= -1;
   strcpy(cells[4].description, "//TODO");
   cells[4].object = 0;
   cells[4].treasure = -1;

   //Cell 5
   cells[5].north = -1;
   cells[5].south =-1;
   cells[5].west = -1;
   cells[5].east= 6;
   cells[5].up = -1;
   cells[5].down= 2;
   strcpy(cells[5].description, "//TODO");
   cells[5].object = -1;
   cells[5].treasure = -1;

   //Cell 6
   cells[6].north = -1;
   cells[6].south =-1;
   cells[6].west = -1;
   cells[6].east= 5;
   cells[6].up = -1;
   cells[6].down= -1;
   strcpy(cells[6].description, "//TODO");
   cells[6].object = 1;
   cells[6].treasure = -1;

   //Cell 7
   cells[7].north = -1;
   cells[7].south =1;
   cells[7].west = -1;
   cells[7].east= -1;
   cells[7].up = -1;
   cells[7].down= 8;
   strcpy(cells[7].description, "//TODO");
   cells[7].object = -1;
   cells[7].treasure = -1;

   //Cells 8
   cells[8].north = -1;
   cells[8].south =-1;
   cells[8].west = 9;
   cells[8].east= 11;
   cells[8].up = 7;
   cells[8].down= -1;
   strcpy(cells[0].description, "//TODO");
   cells[8].object = -1;
   cells[8].treasure = -1;

   //Cell 9
   cells[9].north = 10;
   cells[9].south =-1;
   cells[9].west = -1;
   cells[9].east= 8;
   cells[9].up = -1;
   cells[9].down= -1;
   strcpy(cells[0].description, "//TODO");
   cells[9].object = -1;
   cells[9].treasure = -1;


   //Cell 10
   cells[10].north = -1;
   cells[10].south =9;
   cells[10].west = -1;
   cells[10].east= 13;
   cells[10].up = -1;
   cells[10].down= -1;
   strcpy(cells[10].description, "//TODO");
   cells[10].object = -1;
   cells[10].treasure = -1;

   //Cell 11
   cells[11].north = 12;
   cells[11].south =-1;
   cells[11].west = 8;
   cells[11].east= -1;
   cells[11].up = -1;
   cells[11].down= -1;
   strcpy(cells[11].description, "//TODO");
   cells[11].object = -1;
   cells[11].treasure = -1;

   //Cell 12
   cells[12].north = -1;
   cells[12].south =11;
   cells[12].west = 13;
   cells[12].east= -1;
   cells[12].up = -1;
   cells[12].down= -1;
   strcpy(cells[12].description, "//TODO");
   cells[12].object = -1;
   cells[12].treasure = -1;

   //Cell 13
   cells[13].north = -1;
   cells[13].south =8;
   cells[13].west = -1;
   cells[13].east= -1;
   cells[13].up = -1;
   cells[13].down= -1;
   strcpy(cells[13].description, "//TODO");
   cells[13].object = 2;
   cells[13].treasure = -1;

   //Cell 14
   cells[14].north = -1;
   cells[14].south =-1;
   cells[14].west = 15;
   cells[14].east= 1;
   cells[14].up = -1;
   cells[14].down= -1;
   strcpy(cells[14].description, "//TODO");
   cells[14].object = -1;
   cells[14].treasure = -1;

   //Cell 15
   cells[15].north = 16;
   cells[15].south =17;
   cells[15].west = -1;
   cells[15].east= 14;
   cells[15].up = -1;
   cells[15].down= -1;
   strcpy(cells[15].description, "//TODO");
   cells[15].object = -1;
   cells[15].treasure = -1;

   //Cell 16
   cells[16].north = -1;
   cells[16].south =-1;
   cells[16].west = 18;
   cells[16].east= -1;
   cells[16].up = -1;
   cells[16].down= -1;
   strcpy(cells[16].description, "//TODO");
   cells[16].object = -1;
   cells[16].treasure = -1;

   //Cell 17
   cells[17].north = -1;
   cells[17].south =-1;
   cells[17].west = 18;
   cells[17].east= -1;
   cells[17].up = -1;
   cells[17].down= -1;
   strcpy(cells[17].description, "//TODO");
   cells[17].object = -1;
   cells[17].treasure = -1;

   //Cell 18
   cells[18].north = -1;
   cells[18].south =-1;
   cells[18].west = -1;
   cells[18].east= 15;
   cells[18].up = -1;
   cells[18].down= -1;
   strcpy(cells[18].description, "//TODO");
   cells[18].object = -1;
   cells[18].treasure = 0;

}
void InitializeMapFile(struct Cell cells[]){
    int i = 0, line = 1;
	char direcao[] = "c:\\teste\\mapa1.txt";
	char l[MAX_LIN];
	FILE *f;
	f = fopen(direcao,"r");

    while(fgets(l, MAX_LIN, f) != NULL){
        //fputs(l, stdout); // imprime texto do ficheiro
        switch (line)
		{
		case 1:
			cells[i].north = atoi(l);
			break;
		case 2:
			cells[i].south = atoi(l);
			break;
		case 3:
			cells[i].west = atoi(l);
			break;
		case 4:
			cells[i].east = atoi(l);
			break;
		case 5:
			cells[i].up = atoi(l);
			break;
		case 6:
			cells[i].down = atoi(l);
			break;
		case 7:
			cells[i].object = atoi(l);
			break;
        case 8:
			cells[i].treasure = atoi(l);
			break;
		case 9:
			strcpy(cells[i].description , l);
			break;
        default:
			line = 0;
			i++;
			break;
		}
		line++;
	}
	fclose(f);
}

void PrintMap(struct Cell cells[], int nCells){
    int i;
    for (i=0; i<=nCells;i++){
        printf("%i %i %i %i %i %i\n %s\n %i %i\n\n", cells[i].north, cells[i].south, cells[i].west, cells[i].east, cells[i].up, cells[i].down, cells[i].description, cells[i].object, cells[i].treasure);
    }
}

void InitialMonster(struct Monster *pmonster){
    (*pmonster).energy = MONSTER_INITIAL_ENERGY;
    (*pmonster).cell = MONSTER_INITIAL_CELL;
    (*pmonster).object = MONSTER_INITIAL_OBJECT;
}

void PrintMonster(struct Monster *pmonster){
    char name[20] = "kraken";
    printf("**** Monster ****\n");
    printf("Name: %c\n", name);
    printf("Energy: %d\n", pmonster->energy);
    printf("Cell: %d\n", pmonster->cell);
    printf("Object: %d\n", pmonster->object);
}

int InitialObjects(struct Object objects[]){

    strcpy(objects[0].name,"object0");
    objects[0].cell = 4;
    objects[0].power = 5;

    strcpy(objects[1].name,"object1");
    objects[1].cell = 6;
    objects[1].power = 5;

    strcpy(objects[2].name,"object2");
    objects[2].cell = 13;
    objects[2].power = 5;

    return 2;
}

void PrintObject(struct Object objects[], int nObjects){
    int i =0;
    printf("**** Object ****\n");
    for(i=0; i<nObjects;i++){
    printf("Type: %s\n", objects[i].name);
    printf("Cell: %d\n", objects[i].cell);
    printf("Power: %d\n", objects[i].power);}
}

void avaiableDoors(struct Player *pplayer, struct Cell cells[], int i){
    printf("\n\nYou are in the: %i", (*pplayer).cell);
    printf("\n");
    printf("\nPorta aberta para:\n");

    if(cells[i].north != -1){
        printf("\t\t  North\n ");
      }
    if(cells[i].south != -1){
        printf("\t\t  South\n ");
      }
    if(cells[i].west != -1){
        printf("\t\t  West\n ");
      }
    if(cells[i].east != -1){
        printf("\t\t  East\n ");
      }
    if(cells[i].up != -1){
        printf("\t\t  Up\n ");
      }
    if(cells[i].down != -1){
        printf("\t\t  Down\n ");
      }
}

void PlayerMove(struct Player *pplayer, int nCells, struct Cell cells[]){
    char gate;
   // printf("\n\nEncontra-se na sala : %i", (*player).cell);
    printf("\n\nWath Direction do you want to follow - (N);(S);(W);(E);(U);(D)? ");
    fflush(stdin);
    scanf("%c", &gate);

    if(gate == 'N'){
        (*pplayer).cell = cells[(*pplayer).cell].north;
    }
    if(gate == 'S'){
        (*pplayer).cell = cells[(*pplayer).cell].south;
    }
    if(gate == 'W'){
        (*pplayer).cell = cells[(*pplayer).cell].west;
    }
    if(gate == 'E'){
        (*pplayer).cell = cells[(*pplayer).cell].east;
    }
    if(gate == 'U'){
        (*pplayer).cell = cells[(*pplayer).cell].up;
    }
    if(gate == 'D'){
        (*pplayer).cell = cells[(*pplayer).cell].down;
    }
    printf("\n\nEncontra-se na sala : %i\n\n", (*pplayer).cell);
}

void CheckTreasure(struct Player *pplayer, struct Cell cells[]){

    if((*pplayer).cell = cells[(*pplayer).cell].treasure){
       (*pplayer).energy = PLAYER_INITIAL_ENERGY + 100000;
       (*pplayer).treasure = PLAYER_INITIAL_TREASURE + 1;
    }
}

void CheckObject(struct Player *pplayer, struct Monster *pmonster, struct Cell cells[], struct Object Object[]){

    if((*pplayer).cell = cells[(*pplayer).cell].object){
       (*pplayer).object = PLAYER_INITIAL_OBJECT + 1;
    }
    if((*pmonster).cell = cells[(*pmonster).cell].object){
       (*pplayer).object = MONSTER_INITIAL_OBJECT + 1;
}

void FightMonster(struct Player *pplayer, struct Monster *pmonster, int nCells, struct Cell cells[]){

    if((*pplayer).cell = (*pmonster).cell){

        if((*pmonster).energy > (*pplayer).energy && (*pplayer).object <= 0){
        printf(" -------------------------------------------/n");
		printf("|              Player Health: %d            |\n");
		printf("|             You LOSE!!! HAHAHAH...        |\n");
		printf(" -------------------------------------------/n");
        }
        if((*pplayer).energy > (*pmonster).energy && (*pplayer).object >= 1){
        printf(" --------------------------------------------/n");
		printf("|              Monster Health: %d            |\n");
		printf("|                  You WIN!!!                |\n");
		printf(" --------------------------------------------/n");
        }
    }
    EndGame(&pplayer, &pmonster, nCells, cells);
}
void EndGame(struct Player *pplayer, struct Monster *pmonster, int nCells, struct Cell cells[]){

    if((*pplayer).cell == 0 && (*pmonster).energy <= 0){
        printf(" --------------------------------------------------------------------------------\n");
        printf("|            Congrats!!! you are the new **Ragnar** The King of the Sea          |\n");
		printf("|                               Final Credits                                    |\n");
		printf("|                  Game produced by Luis Serra and Nuno Marques                  |\n");
		printf("|    Game proposed in course SO - Operation Systems, by professor Luis Gracia    |\n");
		printf("|                             Tanks for playing                                  |\n");
		printf(" --------------------------------------------------------------------------------\n");
		//PlayerMove(&pplayer, nCells, cells);
	}else{
          PlayerMove(&pplayer, nCells, cells);//the game continues;
	}
}

