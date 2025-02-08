# Horse-Race pseudocode

CONSTANT numHorses = 5    // Number of horses
CONSTANT maxPos = 15      // Maximum position (finish line)

printLanes(horses):
    for each horse (i = 0 to numHorses - 1):
        for each position (j = 0 to maxPos):
            if horse i is at position j:
                print horse number (i)
            else:
                print "."
        print newline for the next lane

advance(horseNum, horses):
    if horseNum has not reached maxPos:
        Increment horse's position by 1

isWinner(horses):
    for each horse (i = 0 to numHorses - 1):
        if horse i's position is at maxPos:
            return TRUE  // A horse has won
    return FALSE  // No winner yet

MAIN:
    Initialize horses array with 0s (All horses start at position 0)
    Setup random number generator for coin flip (0 or 1)

    Set raceOver to FALSE

    while raceOver is FALSE:
        print "Press enter for another turn"
        Wait for user to press Enter

        // Randomly advance each horse based on a coin flip
        for each horse (i = 0 to numHorses - 1):
            Generate random coin flip (0 or 1)
            if coin flip is 1:
                Call advance function for horse i

        // Print the lanes after this round
        Call printLanes to print the positions of all horses

        // Check if any horse has won
        Call isWinner to check if race is over
        if a horse has won:
            print the winning horse number
            Set raceOver to TRUE  // End the race

    END PROGRAM

