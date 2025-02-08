#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

const int numHorses = 5;  // Number of horses
const int maxPos = 15;    // Max position (finish line)

// Function to print the lanes based on horse positions
void printLanes(int* horses) {
    // For each horse, print its position on a new lane
    for (int i = 0; i < numHorses; ++i) {
        // Print the horse number at its position, and '.' for empty spots
        for (int j = 0; j <= maxPos; ++j) {
            if (horses[i] == j) {
                std::cout << i;  // Print horse number
            } else {
                std::cout << ".";  // Print empty spot
            }
        }
        std::cout << std::endl;  // New line for each horse
    }
}

// Function to advance the horse by one position
void advance(int horseNum, int* horses) {
    if (horses[horseNum] < maxPos) {
        horses[horseNum]++;  // Move the horse forward by one position
    }
}

// Function to check if a horse has won
bool isWinner(int* horses) {
    for (int i = 0; i < numHorses; ++i) {
        if (horses[i] == maxPos) {  // Check if any horse has reached the finish line
            return true;
        }
    }
    return false;
}

int main() {
    int horses[numHorses] = {0, 0, 0, 0, 0};  // Positions of horses (all start at 0)

    // Set up random number generation for coin flip (0 or 1)
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 1);  // Random 0 or 1
    bool coin;

    bool raceOver = false;

    // Game loop
    while (!raceOver) {
        std::cout << "Press enter for another turn";
        std::cin.ignore();  // Wait for the user to press enter

        // Randomly advance horses
        for (int i = 0; i < numHorses; ++i) {
            coin = dist(rd);  // Random coin flip for each horse
            if (coin) {
                advance(i, horses);  // Advance the horse if coin is 1
            }
        }

        // Print the lanes after this round (print one round, all horses' positions)
        printLanes(horses);

        // Check if any horse has won
        raceOver = isWinner(horses);
        if (raceOver) {
            // If a horse has won, display the winner
            for (int i = 0; i < numHorses; ++i) {
                if (horses[i] == maxPos) {
                    std::cout << "Horse " << i << " WINS!!!" << std::endl;
                    break;  // Only print the first winner
                }
            }
        }
    }

    return 0;
}

