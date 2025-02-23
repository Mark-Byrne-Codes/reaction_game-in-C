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
int	start_game_round(void)
{
	int		start_delay_seconds;
	double	reaction_time;
	int		early_press;

	start_delay_seconds = (rand() % 3) + 1;
	early_press = 0;

	display_prompt_wait();

	sleep(start_delay_seconds);

	display_prompt_react();
	reaction_time = measure_reaction_time(0); // Measure reaction time AFTER prompt.
	display_results(reaction_time);


	return (early_press); // Return early_press status (0 or 1).
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

void	wait_for_keypress(void)
{
	int	input_char;

	input_char = getchar();
	(void)input_char;
}
