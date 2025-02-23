#include "reaction_game.h"
/*
    Displays the instructions for the reaction time game.
    Displayed at the start of the program.
    Returns void.
*/
void	display_instructions(void)
{
	printf("----------------------------------------\n");
	printf("        Reaction Time Game\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("Test your reaction time!\n");
	printf("\n");
	printf("Instructions:\n");
	printf("1. Wait for the 'REACT!' prompt.\n");
	printf("2. Press enter key as quickly as possible when you see 'REACT!'\n");
	printf("\n");
	printf("Press enter key to start...\n");
	wait_for_keypress();
}

/*
    Displays a prompt to the user to wait for the 'REACT!' signal.
    Displayed before the reaction time measurement begins.
    Returns void.
*/
void	display_prompt_wait(void)
{
	printf("\nWait for the prompt...\n");
}

/*
    Displays the 'REACT!' prompt to the user.
    Signals the user to press a key as quickly as possible.
    Returns void.
*/
void	display_prompt_react(void)
{
	printf("\n\nREACT! Press enter key!\n");
}

/*
    Displays a message indicating the user pressed a key too early.
    Shown when early key press is detected.
    Returns void.
*/
void	display_too_early_message(void)
{
	printf("\nToo early! Wait for the 'REACT!' prompt.\n");
}

/*
    Displays reaction time (no changes).
*/
void	display_results(double reaction_time)
{
	printf("\nYour reaction time: %.6f seconds\n", reaction_time);
}

/*
    Ends game round (no changes).
*/
void	end_game_round(void)
{
	printf("--- Round Ended ---\n");
}

