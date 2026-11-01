#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include "sorting.h"

int main(){
    system("chcp 65001 > nul");

    // RANDOM ARRAY
    const int size = 100;
    int randomArray[size];

    srand(time(0));

    for (int i = 0; i < size; ++i) {
        randomArray[i] = rand() % 100 + 1;
    }

    std::cout << "Unsorted Random Array: \n";
    displayArray(randomArray, size);

    // ILO A.1: BUBBLE SORT
    std::cout << "\n\nBubble Sort: \n";
    bubbleSort<int>(randomArray, size);
    displayArray(randomArray, size);

    // ILO A.2: SELECTION SORT
    std::cout << "\n\nSelection Sort: \n";
    selectionSort<int>(randomArray, size);
    displayArray(randomArray, size);

    // ILO A.3: INSERION SORT
    std::cout << "\n\nInsertion Sort: \n";
    insertionSort<int>(randomArray, size);
    displayArray(randomArray, size);

    // SUPPLEMENTARY ACTIVITY
    const int voteSize = 100;
    int votes[voteSize];

    // Candidate names
    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    // Generate random votes from 1 to 5
    srand(12345);

    for (int i = 0; i < voteSize; i++) {
        votes[i] = rand() % 5 + 1;
    }

    // Display unsorted votes
    std::cout << "\n\nUnsorted Votes:\n";
    displayArray(votes, voteSize);
    std::cout << "\n\n";

    // Sort votes using insertion sort
    insertionSort(votes, voteSize);

    // Display sorted votes
    std::cout << "Sorted Votes:\n";
    displayArray(votes, voteSize);
    std::cout << "\n\n";

    // Count votes for each candidate
    int voteCount[5] = {0};

    for (int i = 0; i < voteSize; i++) {
        voteCount[votes[i] - 1]++;
    }

    // Display election results
    std::cout << "===== ELECTION RESULTS =====\n";

    int winner = 0;

    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << i + 1 << ": "
                  << candidates[i] << " - "
                  << voteCount[i] << " votes\n";

        if (voteCount[i] > voteCount[winner]) {
            winner = i;
        }
    }

    // Display winner
    std::cout << "\nWINNER:\n";
    std::cout << candidates[winner]
              << " with " << voteCount[winner]
              << " votes.\n";

    return 0;
}