#include "reaction_game.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h> // For sleep function. Justification: To introduce delays in the game.
#include <stdlib.h> // For rand and srand. Justification: Generating random delays.

/*
    Starts and manages a single round of the reaction time game.
    Includes early press detection and handles game flow based on input.
    Returns 0 for normal round completion, 1 for early press (can be used for game flow).
*/
int play_round(double *reaction_times, int round_count) {
    int start_delay_seconds = (rand() % (MAX_DELAY_SECONDS - MIN_DELAY_SECONDS + 1)) + MIN_DELAY_SECONDS;
    double reaction_time;

    printf("\nWait for the prompt...\n");

    if (detect_early_press(start_delay_seconds)) {
        printf("\nToo early! You pressed a key before 'REACT!'\n");
        return 1; // Early press detected
    }

    sleep(start_delay_seconds);
    printf("\n\nREACT! Press enter key!\n");

    reaction_time = measure_reaction_time(0);
    if (reaction_time >= 0) {
        reaction_times[round_count - 1] = reaction_time;
        printf("\nYour reaction time: %.6f seconds\n", reaction_time);
    } else {
        printf("\nError: Invalid reaction time recorded.\n");
    }

    return 0; // Normal round completion
}

double calculate_average_reaction_time(double *reaction_times, int rounds) {
    double sum = 0.0;
    for (int i = 0; i < rounds; i++) {
        sum += reaction_times[i];
    }
    return (rounds > 0) ? sum / rounds : 0.0;
}


/*
    Measures the user's reaction time (no changes).
*/
double	measure_reaction_time(int start_delay_seconds)
{
	struct timespec	start_ts;
	struct timespec	end_ts;
	double			elapsed_time;

	(void)start_delay_seconds;

	if (clock_gettime(CLOCK_MONOTONIC, &start_ts) != 0) {
		perror("clock_gettime failed (start)");
		return (-1.0);
	}
	wait_for_keypress();
	if (clock_gettime(CLOCK_MONOTONIC, &end_ts) != 0) {
		perror("clock_gettime failed (end)");
		return (-1.0);
	}
	elapsed_time = (double)(end_ts.tv_sec - start_ts.tv_sec) +
				   (double)(end_ts.tv_nsec - start_ts.tv_nsec) / 1000000000.0;
	return (elapsed_time);
}

int detect_early_press(int delay_seconds) {
    fd_set set;
    struct timeval timeout;

    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    timeout.tv_sec = delay_seconds;
    timeout.tv_usec = 0;

    return select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout) == 1;
}

void wait_for_keypress(void) {
    getchar();
}
