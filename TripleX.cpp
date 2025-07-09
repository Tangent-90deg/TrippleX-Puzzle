#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintIntroduction(int Difficulty)
{
    printf("You are entered into a level %d", Difficulty);
    printf(" secure server room...\nEnter the correct code to continue....\n\n");
}

int PlayerGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int Codesum = CodeA + CodeB + CodeC;
    const int Codeproduct = CodeA * CodeB * CodeC;

    printf("+ There are 3 numbers in the code\n");
    printf("+ The code add-up to: %d\n", Codesum);
    printf("+ The code multiplies to give: %d\n", Codeproduct);

    int GuessA, GuessB, GuessC;
    
    printf("\nGuess the 3 numbers in the code:\n");
    scanf("%d %d %d", &GuessA, &GuessB, &GuessC);
    
    printf("You entered: %d %d %d\n", GuessA, GuessB, GuessC);

    int Guesssum = GuessA + GuessB + GuessC;
    int Guessproduct = GuessA * GuessB * GuessC;

    if (Guesssum == Codesum && Guessproduct == Codeproduct)
    {
        printf("\n*** Well done agent! You have extracted a file! Keep going! ***\n");
        return 1; // true
    }
    else
    {
        printf("\n*** You entered the wrong code! Careful agent! Try again! ***\n");
        return 0; // false
    }
}

int main()
{
    srand(time(NULL)); // Initialize random seed based on time
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels completed
    {
        int bLevelComplete = PlayerGame(LevelDifficulty);

        // Clear the input buffer
        while (getchar() != '\n'); // To discard remaining characters

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    printf("\n\n*** Great work agent! You got all the files! Now get out of there ***\n");
    return 0;
}