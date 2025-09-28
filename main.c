#include <stdio.h>

enum { SPOCK, SCISSORS, PAPER, ROCK, LIZARD, SHAPE_COUNT } player1, player2;

const char *SHAPE_STRINGS[] = {"🖖", "✂️", "️🗒️", "🪨", "🦎"};

int main() {
    for (size_t player1 = SPOCK; player1 < SHAPE_COUNT; ++player1) {
    for (size_t player2 = SPOCK; player2 < SHAPE_COUNT; ++player2) {
        printf("If player1: %s  and player2: %s  => ",
                SHAPE_STRINGS[player1], SHAPE_STRINGS[player2]);

        if (player1 == player2) {
        printf("Tie.\n");
        } else {
        int diff = (int)player2 - (int)player1;

        if (diff < 0) {
            diff += SHAPE_COUNT;  
        }

        if (diff == 1 || diff == 3) {
            printf("Player1 wins.\n");
        } else {
            printf("Player1 looses.\n");
        }
    }
    }
    puts("");
    }
}
