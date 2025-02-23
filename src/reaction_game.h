#ifndef FT_REACTION_GAME_H
# define FT_REACTION_GAME_H

# include <stdlib.h> // For standard library functions. Justification: General utility functions.
# include <time.h>   // For time related functions. Justification: Reaction time measurement and delays.
# include <stdio.h>  // For standard input/output functions (printf, etc.). Justification: Terminal output.
# include <unistd.h>

// Function Prototypes

int		main(void);
int		start_game_round(void);
double	measure_reaction_time(int start_delay_seconds);
void	wait_for_keypress(void);
void	display_instructions(void);

#endif