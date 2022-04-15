#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH 70
#define MIN_PATH 10
#define MULTIPLE_OF 5
#define MIN_LIVES 1
#define MAX_LIVES 10
#include <stdio.h>

struct PlayerInfo //
{
    int lives; //
    char symbol;
    int num_treasure;
    int position[MAX_PATH];
};

struct GameInfo
{
    int moves;
    int pathlength;
    int bomb[MAX_PATH][5];
    int treasure[MAX_PATH][5];
};

int main ()
{
    struct PlayerInfo player;
    struct GameInfo game;
    int row, j, i;
    
    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);
    
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        
        if (player.lives > MAX_LIVES || player.lives < MIN_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
        
    } while (player.lives > MAX_LIVES || player.lives < MIN_LIVES);
    
    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathlength);
        
        if (game.pathlength > MAX_PATH || game.pathlength < MIN_PATH || game.pathlength % 5 != 0 )
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }else{
            row = game.pathlength / 5;
        }

    } while (game.pathlength > MAX_PATH || game.pathlength < MIN_PATH || game.pathlength % 5 != 0);
    
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        
        if (game.moves <= player.lives || game.moves >= (int)(game.pathlength * 0.75))
        {
            printf("    Value must be between %d and %d\n", player.lives,(int)(game.pathlength * 0.75));
        }
        
    } while (game.moves <= player.lives || game.moves >= (int)(game.pathlength * 0.75));
    
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);
    
    for (i = 0 ; i < row ; i++)
    {
        
        printf("   Positions [%2d-%2d]: ", (i*5)+1, (i+1)*5);
        for (j = 0 ; j < 5; j++){
            scanf("%d", &game.bomb[i][j]);
        }
        
    }

    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!", game.pathlength);
    printf("\n");
    
    for (i = 0 ; i < row ; i++)
    {
        printf("   Positions [%2d-%2d]: ",(i*5)+1, (i+1)*5);
        for (j = 0 ; j < 5; j++){
            scanf("%d", &game.treasure[i][j]);
        }
        
    }

    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d", game.pathlength);
    printf("\n");
    printf("   Bombs      : ");
    
    for (i = 0 ; i < row ; i++)
    {
        for (j = 0 ; j < 5; j++){
            printf("%d", game.bomb[i][j]);
        }
    }
    
    printf("\n");
    printf("   Treasure   : ");
    
    for (i = 0 ; i < row ; i++)
    {
        for (j = 0 ; j < 5; j++){
            printf("%d", game.treasure[i][j]);
        }
        
    }
    
    printf("\n");
    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    
    return 0;
}
