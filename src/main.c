#include "reaction_game.h"

/*
    Entry point of the reaction time game.
    Manages the game loop and overall program flow.
    Returns 0 on successful execution.
*/
int main(void) {
    int game_status = 0;
    int round_count = 0;
    char play_again = 'y';

    srand(time(NULL));
    display_instructions();

    while (play_again == 'y' || play_again == 'Y') {
        round_count++;
        printf("\n--- Round %d ---\n", round_count);

        game_status = play_round();
        if (game_status == 1)
            printf("Oops! You pressed too early.\n");

        printf("\nPlay again? (y/n): ");
        play_again = getchar();
        while (getchar() != '\n'); // Clear input buffer
    }

    printf("\nThanks for playing!\n");
    return 0;
}