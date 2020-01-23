/*
 This program is a random number guessing game. The user is able to either play against
 the PC or the user can pick the number in their head and the PC guesses the number.
 */

#include<iostream>
#include"random_number_game.h"

using namespace std;

int main(void)
{
    while(true)
    {
        /* Menu of selections for user. Can choose between playing against
         or with PC. */
        char decision;
        cout << "GUESSING GAME" << endl;
        cout << "------------------------" << endl;
        cout << "(1) Computer Picks the Number" << endl;
        cout << "(2) You Pick the Number" << endl;
        cout << "(3) Exit Program" << endl;
        cout << "------------------------" << endl;
        
        /* This grabs the decision of the user and is in a loop in case some other
         than a 1, 2, or 3 is inputted. At that point, it just gives the user another
         chance to put a selection. */
        while(true)
        {
            cout << "What would you like to do? ";
            cin >> decision;
            cout << endl;
            
            if (decision == '1')
            {
                computer_picks_number();
                break;
            }
            else if (decision == '2')
            {
                user_picks_number();
                break;
            }
            else if (decision == '3')
            {
                return 0;
            }
            else
            {
                cout << "Bad input, try again." << endl;
            }
        }
        
         /* Determines if the user wants to play another game. if yes, it resets the whole program
          back to the menu, since it is all in a loop. If not, it breaks out of the main loop
          and quits the program. */
        bool does_user_wanna_play_again = play_again();
        if (does_user_wanna_play_again == true)
        {
            cout << endl;
            continue;
        }
        else
            break;
    }
    
    return 0;
}
