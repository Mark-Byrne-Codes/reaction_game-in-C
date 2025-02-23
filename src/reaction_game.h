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
void	display_results(double reaction_time);
void	end_game_round(void);
void	display_instructions(void);
void	display_prompt_wait(void);
void	display_prompt_react(void);
// void	display_too_early_message(void);
// void	wait_for_keypress(void);
// int		check_early_keypress(void);

#endif