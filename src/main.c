#include "reaction_game.h"

/*
    Entry point of the reaction time game.
    Manages the game loop and overall program flow.
    Returns 0 on successful execution.
*/
int	main(void)
{
	int		game_status;
	int		play_again;

	game_status = 0;
	play_again = 1;

	display_instructions();

	while (play_again == 1)
	{
		game_status = start_game_round();
		if (game_status != 0)
			break ;

		printf("--- Round Ended ---\n");
		printf("Press Enter to play again.");
		wait_for_keypress();
		play_again = 0;
	}

	return (0);
}