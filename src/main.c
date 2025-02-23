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
    double reaction_times[MAX_ROUNDS] = {0};

    srand(time(NULL));
    display_instructions();

    while (play_again == 'y' || play_again == 'Y') {
        round_count++;
        if (round_count > MAX_ROUNDS) {
            printf("\nMaximum number of rounds reached.\n");
            break;
        }
        printf("\n--- Round %d ---\n", round_count);
        game_status = play_round(reaction_times, round_count);
        if (game_status == 1)
            printf("Oops! You pressed too early.\n");
        printf("\nPlay again? (y/n): ");
        play_again = getchar();
        while (getchar() != '\n'); // Clear input buffer
    }
    double avg_reaction_time = calculate_average_reaction_time(reaction_times, round_count);
    printf("\nYour average reaction time: %.6f seconds\n", avg_reaction_time);
    printf("\nThanks for playing!\n");
    return 0;
}