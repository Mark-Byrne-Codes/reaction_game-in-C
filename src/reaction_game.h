#ifndef FT_REACTION_GAME_H
# define FT_REACTION_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/select.h>

#define MIN_DELAY_SECONDS 1
#define MAX_DELAY_SECONDS 3

// Function Prototypes

int		main(void);
int     play_round(void);
double	measure_reaction_time(int start_delay_seconds);
int     detect_early_press(int delay_seconds);
void	wait_for_keypress(void);
void	display_instructions(void);

#endif