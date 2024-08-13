#include <cctype>
#include <iostream>
#include <map>
#include <random>
#include <string>


static std::map<int, std::string> gameOptions = {{1, "rock"}, {2, "paper"}, {3, "scissors"}};

/*

Rules of this map:

- Rock smashes Scissors.
- Scissors cutting Paper.
- Paper covers Rock.

It's a map of map: <Player1, <Player2, Boolean information: Player1 beats Player2>>
This code uses the fact that if Player1 beats Player2, then Player2 will lose against Player1.
It's a numeric version map, based on the map: gameOptions.
*/
static std::map<int, std::map<int, bool>> winningGameCases = {
        {
            1, {
                {3, true},
                {2, false}
            }
        },
        {
            2, {
                {1, true},
                {3, false}
            }
        },
        {
            3, {
                {1, false},
                {2, true}
            }
        }
    };

/*

Similar to the previous map, this map addresses the game-win messages.

Note: all the messages are:

- Rock smashes Scissors.
- Scissors cutting Paper.
- Paper covers Rock.

.

*/
static std::map<int, std::map<int, std::string>> gameWinMessages = {
        {
            1, {
                {3, "Rock smashes Scissors."},
                {2, "Paper covers Rock."}
            }
        },
        {
            2, {
                {1, "Paper covers Rock."},
                {3, "Scissors cutting Paper."}
            }
        },
        {
            3, {
                {1, "Rock smashes Scissors."},
                {2, "Scissors cutting Paper."}
            }
        }
    };


int getComputerChoiceAsInt() {
    /*std::random_device rd;   // Seed with a real random value, if available
    std::mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()

    // Generate and return a random number between 1 and quantity of options.
    int random_choice = gen() % static_cast<int>(gameOptions.size()) + 1;*/
    int random_choice = 2; // Paper
    return random_choice;
}

std::string getComputerChoiceAsString(int computerChoiceAsInt) {
    std::string computerChoiceStr = gameOptions[computerChoiceAsInt];
    char firstChar = computerChoiceStr[0];
    if (std::islower(firstChar)) {
        computerChoiceStr[0] = std::toupper(firstChar);
    }

    return computerChoiceStr;
}

int getIntValueForGameOption(std::string str) {
    std::map<int, std::string>::iterator optionIterator;

    for (optionIterator = gameOptions.begin(); optionIterator != gameOptions.end(); optionIterator++) {
        if (optionIterator->second == str) {
            return optionIterator->first;
        }
    }

    return -1;
}

int getIntValueFromNumericStringForGameOption(std::string str) {
    int choice = std::stoi(str);
    if (choice > 0 && choice < static_cast<int>(gameOptions.size()) + 1) {
        return choice;
    } else {
        return -1;
    }
}

int getPlayerChoiceAsInt(std::string playerChoiceAsStr) {
    if (std::isdigit(playerChoiceAsStr[0])) {
        return getIntValueFromNumericStringForGameOption(playerChoiceAsStr);
    }

    char firstChar = playerChoiceAsStr[0];
    if (std::isupper(firstChar)) {
        playerChoiceAsStr[0] = std::tolower(firstChar);
    }

    return getIntValueForGameOption(playerChoiceAsStr);
}

int getPlayerChoice() {
    std::string playerChoiceAsStr;

    std::cout << "Choose your move:" << std::endl;
    std::cout << "1 - Rock," << std::endl;
    std::cout << "2 - Paper," << std::endl;
    std::cout << "3 - Scissors" << std::endl;
    std::cin >> playerChoiceAsStr;
    std::cout << "> " << playerChoiceAsStr << std::endl;
    return getPlayerChoiceAsInt(playerChoiceAsStr);
}


int main() {
    int computerChoice = getComputerChoiceAsInt();
    int playerChoice;

    std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
    std::cout << std::endl;

    playerChoice = getPlayerChoice();
    if (playerChoice == -1) {
        std::cout << "Invalid move. Please enter Rock, Paper, or Scissors." << std::endl;
    } else {
        std::cout << "The computer chose " << getComputerChoiceAsString(computerChoice) << ". ";

        if (playerChoice == computerChoice) {
            std::cout << "It's a draw." << std::endl;
        } else {
            std::cout << gameWinMessages[playerChoice][computerChoice];

            if (winningGameCases[playerChoice][computerChoice]) {
                std::cout << " You win!" << std::endl;
            } else {
                std::cout << " Sorry, you lost." << std::endl;
            }
        }
    }

    return 0;
}
