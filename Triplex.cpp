#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print Welcome Messages
    std::cout << "\n\n You're a soon to be victim of a serial killer!\n";
    std::cout << "You must enter the correct codes to each door to escape their 5 room kill house... You're currently in room: " << Difficulty << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Generate Code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Sum & Product
    std::cout << "\n- There are 3 numbers to open the combination lock on the door";
    std::cout << "\n - The codes add up to: " << CodeSum;
    std::cout << "\n - The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    std::cout << "\n\nEnter the 3 digits here, separated by spaces and press enter:\n";

    int FirstCode, SecondCode, ThirdCode;
    std::cin >> FirstCode >> SecondCode >> ThirdCode;
    
    int GuessSum = FirstCode + SecondCode + ThirdCode;
    int GuessProduct = FirstCode * SecondCode * ThirdCode;

    //Player guess check
     if (GuessSum == CodeSum && GuessProduct == CodeProduct)
        {
         std::cout << "*** You did it! KEEP GOING!!! ***";
         return true;
    }
    else
        {
        std::cout << "*** Wrong, THEY'RE RIGHT BEHIND YOU! TRY AGAIN!!! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new randome sequence based on time of day

    int LevelDifficulty =  1;
    int const MaxDifficulty =  5;
    
    while (LevelDifficulty <= MaxDifficulty) // Loop game till all levels complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears  any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
        
    }  
    std::cout << "\n*** Great job, you escaped! ***\n";  
       return 0;
} 