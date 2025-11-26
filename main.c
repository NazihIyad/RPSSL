#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINNING_SCORE 5

int main() {
    srand(time(NULL));
    int player_score, agent_score;

    while (1) {
        char menu;
        printf("(s) Single player, (e) Exit: ");
        scanf(" %c", &menu);

        if (menu == 'e') break;
        if (menu != 's') continue;

        player_score = 0;
        agent_score = 0;

        while (player_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
            char input[10];
            int player, agent;
            printf("Choose a shape (0:Rock 1:Lizard 2:Scissors 3:Paper 4:Spock, e to exit): ");
            scanf("%s", input);

            if (input[0] == 'e') break; 

            player = atoi(input); 
            if (player < 0 || player > 4) {
                printf("Invalid choice.\n");
                continue;
            }

            agent = rand() % 5;
            printf("Agent chose: %d\n", agent);

            if (player == agent) printf("Tie!\n");
            else if ((player==0&&(agent==2||agent==1)) ||
                        (player==1&&(agent==3||agent==4)) ||
                        (player==2&&(agent==1||agent==3)) ||
                        (player==3&&(agent==0||agent==4)) ||
                        (player==4&&(agent==0||agent==2))) {
                player_score++;
                printf("You win this round!\n");
            } else {
                agent_score++;
                printf("Agent wins this round!\n");
            }

            printf("Score - You: %d  Agent: %d\n\n", player_score, agent_score);
        }

        if (player_score == WINNING_SCORE) printf("You won the game!\n");
        else if (agent_score == WINNING_SCORE) printf("Agent won the game!\n");
        else printf("Game exited early.\n");
    }

    printf("Exiting game.\n");
    return 0;
}
