#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <sstream>
#include <vector>


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


std::string tolower(std::string str) {
    std::string result(str);
    int size = static_cast<int>(str.size());
    for (int i = 0; i < size; i++) {
        result[i] = std::tolower(str[i]);
    }
    return result;
}

int getComputerChoiceAsInt() {
    /*std::random_device rd;   // Seed with a real random value, if available
    std::mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()

    // Generate and return a random number between 1 and quantity of options.
    int random_choice = gen() % static_cast<int>(gameOptions.size()) + 1;*/
    int random_choice = 2; // Paper
    return random_choice;
}

std::string getGameChoiceAsString(int gameChoiceAsInt) {
    std::string gameChoiceStr = gameOptions[gameChoiceAsInt];
    char firstChar = gameChoiceStr[0];
    gameChoiceStr[0] = std::toupper(firstChar);
    return gameChoiceStr;
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

std::vector<std::string> split (const std::string &str) {
    std::vector<std::string> strvector;
    std::stringstream strstream(str);
    std::string item;
    char delim = ' ';
    while (getline (strstream, item, delim)) {
        strvector.push_back (item);
    }

    return strvector;
}

int playRound(int roundNumber, int playerChoice, std::string playerName) {
    int computerChoice = getComputerChoiceAsInt();

    // Round 1: Computer chose Scissors, Emily chose Rock. Winner: Emily.
    std::cout << "Round " << roundNumber << ": ";
    std::cout << "Computer chose " << getGameChoiceAsString(computerChoice) << ", ";
    std::cout << playerName << " chose " << getGameChoiceAsString(playerChoice) << ". ";

    if (playerChoice == computerChoice) {
        std::cout << "It's a draw." << std::endl;
        return 2;
    } else if (winningGameCases[playerChoice][computerChoice]) {
            std::cout << "Winner: " << playerName << "." << std::endl;
            return 0;
    } else {
        std::cout << "Winner: Computer." << std::endl;
        return 1;
    }
}

bool playGame() {
    std::string newGameChoice;
    int playerPoints = 0;
    int computerPoints = 0;
    std::string playerName;
    int roundQuantity;

    std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
    std::cout << std::endl;

    std::cout << "Please enter your name, number of repetitions," << std::endl;
    std::cout << "and your chosen steps" << std::endl;
    std::cout << "1 - Rock," << std::endl;
    std::cout << "2 - Paper," << std::endl;
    std::cout << "3 - Scissors:" << std::endl;

    getline(std::cin, newGameChoice);
    std::cout << std::endl;

    std::cout << "> " << newGameChoice << std::endl;
    std::cout << std::endl;
    std::vector<std::string> vectorOptions = split(newGameChoice);

    playerName = vectorOptions[0];
    roundQuantity = std::stoi(vectorOptions[1]);

    std::cout << "Game Start!" << std::endl;
    for (int i = 1; i <= roundQuantity; i++) {
        int playerChoice = getPlayerChoiceAsInt(vectorOptions[i + 1]);
        int roundResult = playRound(i, playerChoice, playerName);
        if (roundResult == 0) {
            playerPoints++;
        } else if (roundResult == 1) {
            computerPoints++;
        } else if (roundResult == 2) {
            i--;
        }
    }

    std::cout << std::endl;
    std::cout << "Game Over!" << std::endl;
    std::cout << "Total Score - " << playerName << ": ";
    std::cout << playerPoints << ", Computer: " << computerPoints << std::endl;
    std::cout << "Would you like to play again? (yes/no)" << std::endl;
    std::cin >> newGameChoice;
    return tolower(newGameChoice) == "yes";
}


int main() {
    // while (playGame()); // for the future as specified in the objectives of this stage.
    playGame();
    return 0;
}
