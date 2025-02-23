#ifndef FT_REACTION_GAME_H
# define FT_REACTION_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/select.h>

#define MIN_DELAY_SECONDS 1
#define MAX_DELAY_SECONDS 3
#define MAX_ROUNDS 100

// Function Prototypes

int		main(void);
int     play_round(double *reaction_times, int round_count);
double	measure_reaction_time(int start_delay_seconds);
int     detect_early_press(int delay_seconds);
double   calculate_average_reaction_time(double *reaction_times, int rounds);
void	wait_for_keypress(void);
void	display_instructions(void);

#endif