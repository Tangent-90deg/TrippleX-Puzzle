#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty)
{
    cout << "You are entered into a level " << Difficulty;
    cout << " secure server room...\nEnter the correct code to continue....\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "+ There are 3 numbers in the code\n";
    cout << "+ The code adds up to: " << CodeSum << endl;
    cout << "+ The code multiplies to give: " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cout << "\nGuess the 3 numbers in the code:\n";
    cin >> GuessA >> GuessB >> GuessC;

    cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n*** Well done agent! You have extracted a file! Keep going! ***\n";
        return true;
    }
    else
    {
        cout << "\n*** You entered the wrong code! Careful agent! Try again! ***\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();  // Clear any errors
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard remaining input

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    cout << "\n\n*** Great work agent! You got all the files! Now get out of there ***\n";
    return 0;
}
