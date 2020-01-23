/* random_number_game.cpp */

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<limits>
#include "random_number_game.h"

using namespace std;

/* Code for user guessing PC's number. */
void computer_picks_number()
{
    int num_being_guessed = random_num_between(0, 100); // Number being guessed by user.
    int user_guess; // The user's guesses throughout the function.
    
    /* Asking for that first guess, while making sure it is within the 0 to
     100 range. */
    while(true)
    {
        cout << "What number am I thinking of between 0 and 100? ";
        cin >> user_guess;
        
        cout << endl;
        
        if (user_guess < 0 || user_guess > 100)
        {
            cout << "Incorrect Input, please try again." << endl;
            continue;
        }
        else
            break;
    }
    
    /* Lets the user know if that first guess was high, low, or right. And then
     proceeds to keep asking for guesses until it's right. Also checks if
     the guesses are within the 0 to 100 range. */
    while(true)
    {
        if (user_guess == num_being_guessed)
        {
            cout << "Congrats! You guessed right!" << endl;
            break;
        }
        else if (user_guess > num_being_guessed )
        {
            cout << user_guess << " is too high! Guess again: ";
            cin >> user_guess;
        }
        else if (user_guess < num_being_guessed )
        {
            cout << user_guess << " is too low! Guess again: ";
            cin >> user_guess;
        }
        else if (user_guess < 0 || user_guess > 100)
        {
            cout << "Not within range! Guess again: ";
            cin >> user_guess;
        }
    }
}

/* Code for PC guessing user's number. */
void user_picks_number()
{
    /* Explaining the rules to the user.
     
     If the PC's guess is...
     TOO LOW - type an L
     TOO HIGH - type an H
     CORRECT - type a C
     
     Then waits for the user to be ready by waiting for an ENTER
     key to be pushed, which starts the game. */
    cout << "Think of a number between 0 and 100." << endl;
    cout << "Let me know if my guess is too high, too low or just right!" << endl;
    cout << "Use H for high, L for low, and R for right." << endl;
    cout << "Press ENTER when you are ready...";
    cin.ignore(999, '\n');
    cin.ignore(999, '\n');
    
    int PC_guess = random_num_between(0, 100);  // The PC's first guess.
    
    int pc_range_low = 0;   // Initial lowest number that the user's number could be.
    int pc_range_high = 100;    // Initial highest number that the user's number could be.
    
    char response;  // That H, L, or R input by the user.
    
    /* If the user tells the PC that their guess is too low then the PC
     updates the pc_range_low and the uses the random_num_between function
     with that new integer to return a more accurate guess. Same for too high.
     The right user input ends the game. */
    while(true)
    {
        cout << "Is " << PC_guess << " your number? ";
        cin >> response;
        if (response == 'H' || response == 'h')
        {
            pc_range_high = PC_guess;
            PC_guess = random_num_between(pc_range_low, pc_range_high);
            
        }
        else if (response == 'L' || response == 'l')
        {
            pc_range_low = PC_guess;
            PC_guess = random_num_between(pc_range_low, pc_range_high);
        }
        else if (response == 'R' || response == 'r')
        {
            cout << "Yay I guessed right!" << endl;
            break;
        }
        else
        {
            cout << "Bad input. Please try again." << endl;
            continue;
        }
        
        /* This if statement is here in case the user tries to cheat the PC by
         saying the number is too high or too low when the PC guesses the user's
         number. This happens when pc_range_high is equal to it's low counterpart.
         This ends the game too. */
        if (pc_range_high == pc_range_low)
        {
            cout << "You're cheating! I don't want to play anymore." << endl;
            break;
        }
    }
}
/* Checking if the user wants to play again. */
bool play_again()
{
    bool does_user_wanna_play_again;    // The bool that determines if the user wants to
                                        // again or not.
    char yesOrNo;   // The user's yes or no decision
    
    /* Asking the user if they want to play again or not. If the
     input is something other than a yes or no, it restarts the loop. */
    while(true)
    {
        cout << "Would you like to play again (Y or N)? ";
        cin >> yesOrNo;
        
        if (yesOrNo == 'y' || yesOrNo == 'Y')
        {
            does_user_wanna_play_again = true;
            break;
        }
        else if (yesOrNo == 'n' || yesOrNo == 'N')
        {
            does_user_wanna_play_again = false;
            break;
        }
        else
        {
            cout << "Bad Input. Try again." << endl;
            continue;
        }
    }
    
    return does_user_wanna_play_again;  // Returned to main which then starts the whole loop again if
                                        // this bool is true.
}

/* Making a random number between a certain range. */
int random_num_between(int x, int y)
{
    srand(time(NULL));  // Restarts the time to make sure rand() isn't
                        // outputting the same number as last time.
    return x + (rand() % (y - x + 1 ) );    // The formula:
                                            // rand() % (y + 1) ---> 0 to y range
                                            // rand() % (y - x + 1) ---> 0 to (y - x) range
                                            // x + (rand() % (y - x + 1)) ---> x to y range
}
