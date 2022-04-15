#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH 70
#define MIN_PATH 10
#define MULTIPLE_OF 5
#define MIN_LIVES 1
#define MAX_LIVES 10
#define UNDISCOVERED '-'
#define BOMB_SYMBOL '!'
#define TREASURE_SYMBOL '$'
#define BOTH_SYMBOL '&'
#define NOTHING_SYMBOL '.'
#include <stdio.h>

struct PlayerInfo
{
    int lives;
    char symbol;
    int num_treasure;
    int position[MAX_PATH];
};

struct GameInfo
{
    int moves;
    int pathlength;
    int bomb[MAX_PATH];
    int treasure[MAX_PATH];
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
            scanf("%d", &game.bomb[j + (i*5)]);
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
            scanf("%d", &game.treasure[j + (i*5)]);
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
    
    for (i = 0 ; i < game.pathlength ; i++)
    {
        printf("%d", game.bomb[i]);
    }
    
    printf("\n");
    printf("   Treasure   : ");
    
    for (i = 0 ; i < game.pathlength ; i++)
    {
        printf("%d", game.treasure[i]);
    }
    
    printf("\n");
    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    printf("\n");
    printf("  ");
    
    char map[game.pathlength];
    
    for(i = 0; i < game.pathlength;i++){
        
        map[i] = '-';
        printf("%c",map[i]);
        
    }
    printf("\n");
    printf("  ");
    for(i = 1; i <= game.pathlength;i++){
        if(i % 10 == 0){
            printf("%d",i/10);
        }else{
            printf("|");
        }
    }
    
    printf("\n");
    printf("  ");
    for(i = 1; i <= game.pathlength;i++){
        if(i % 10 == 0){
            printf("%d",0);
        }else{
            printf("%d",i%10);
        }
    }
    
    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",player.lives, player.num_treasure,game.moves);
    printf("+---------------------------------------------------+\n");
    
    while(player.lives > 0 && game.moves > 0){
        
        int playermove = 0;
        
        do
        {
            printf("Next Move [1-20]: ");
            scanf("%d", &playermove);
            
            if (playermove <= 0 || playermove > game.pathlength)
            {
                printf("  Out of Range!!!\n");
                
            }else{
                //check tresure and bomb range
                printf("\n");
                if(player.position[playermove-1] == 1){
                    printf("===============> Dope! You've been here before!\n");
                }else if (game.treasure[playermove-1] == 1 && game.bomb[playermove-1] == 0){
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                    player.num_treasure++;
                    map[playermove-1] = TREASURE_SYMBOL;
                    game.moves--;
                }else if(game.treasure[playermove-1] == 1 && game.bomb[playermove-1] == 1){
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                    player.lives--;
                    player.num_treasure++;
                    map[playermove-1] = BOTH_SYMBOL;
                    game.moves--;
                }else if (game.treasure[playermove-1] == 0 && game.bomb[playermove-1] == 1){
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                    player.lives--;
                    map[playermove-1] = BOMB_SYMBOL;
                    game.moves--;
                }else{
                    printf("===============> [.] ...Nothing found here... [.]\n");
                    map[playermove-1] = NOTHING_SYMBOL;
                    game.moves--;
                }
                player.position[playermove-1] = 1;
            }
            
        } while (playermove <= 0 || playermove > game.pathlength);
        
        if (player.lives == 0){
            printf("\n");
            printf("No more LIVES remaining!\n");
        }
        
        printf("\n");
        printf("  ");
        for(i = 0; i < game.pathlength;i++){
            if((i+1) == playermove){
                printf("%c",player.symbol);
            }else{
                printf(" ");
            }
        }
        
        printf("\n");
        printf("  ");
        for(i = 0; i < game.pathlength;i++){
            printf ("%c",map[i]);
        }
        
        printf("\n");
        printf("  ");
        for(i = 1; i <= game.pathlength;i++){
            if(i % 10 == 0){
                printf("%d",i/10);
            }else{
                printf("|");
            }
        }
        printf("\n");
        printf("  ");
        for(i = 1; i <= game.pathlength;i++){
            if(i % 10 == 0){
                printf("%d",0);
            }else{
                printf("%d",i%10);
            }
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",player.lives, player.num_treasure,game.moves);
        printf("+---------------------------------------------------+\n");
    }
    
    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}
