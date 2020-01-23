/* random_number_game.h */

#ifndef random_number_game_h
#define random_number_game_h

#include <stdio.h>

void computer_picks_number();   // Code for user guessing PC's number.

void user_picks_number();   // Code for PC guessing user's number.

bool play_again();  // Checking if the user wants to play again.

int random_num_between(int x, int y);   // Making a random number between a certain
                                        // range.

#endif
