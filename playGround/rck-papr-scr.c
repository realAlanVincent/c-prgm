#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Variable to store the user's input
    int user_input;
    printf("Enter your choice: 1 for rock, 2 for paper, 3 for scissors: ");

    // Read the user's choice and check if it's valid
    if (scanf("%d", &user_input) != 1 || user_input < 1 || user_input > 3)
    {
        printf("Invalid input. Please enter 1, 2, or 3.\n");
        return 1;
    }

    // Convert user's input (1-3) to choice (0-2)
    int user_choice = user_input - 1;

    // Generate computer's choice (0 for rock, 1 for paper, 2 for scissors)
    int computer_choice = rand() % 3;

    // Array to map choices to their names
    char *choices[] = {"rock", "paper", "scissors"};

    // Display the choices
    printf("You chose %s, computer chose %s.\n", choices[user_choice], choices[computer_choice]);

    // Determine the winner
    if (user_choice == computer_choice)
    {
        printf("It's a tie!\n");
    }
    else if ((user_choice == 0 && computer_choice == 2) ||
             (user_choice == 1 && computer_choice == 0) ||
             (user_choice == 2 && computer_choice == 1))
    {
        printf("You win!\n");
    }
    else
    {
        printf("Computer wins!\n");
    }

    return 0;
}
