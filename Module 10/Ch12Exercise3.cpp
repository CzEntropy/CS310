// Cristian Taylor
// 5-17-2024
// This program will store candidates and their vote count within a dynamic array
#include <iostream>
#include <string>
#include <iomanip> // for setw and setprecision

using namespace std;

// Structure to hold candidate information
struct Candidate {
    string lastName;
    int votes;
    float percentage;
};

int main() {
    int numCandidates;

    // Ask the user for the number of candidates
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // Dynamically allocate an array of candidates
    Candidate* candidates = new Candidate[numCandidates];

    // Input candidate names and votes
    for (int i = 0; i < numCandidates; ++i) {
        cout << "Enter candidate's last name: ";
        cin >> candidates[i].lastName;
        cout << "Enter number of votes received by " << candidates[i].lastName << ": ";
        cin >> candidates[i].votes;
    }

    // Calculate total number of votes
    int totalVotes = 0;
    for (int i = 0; i < numCandidates; ++i) {
        totalVotes += candidates[i].votes;
    }

    // Calculate percentage of votes for each candidate
    for (int i = 0; i < numCandidates; ++i) {
        candidates[i].percentage = (static_cast<float>(candidates[i].votes) / totalVotes) * 100;
    }

    // Find the winner
    int maxVotes = 0;
    string winner;
    for (int i = 0; i < numCandidates; ++i) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winner = candidates[i].lastName;
        }
    }

    // Output results with proper format
    cout << "\nResults:\n";
    cout << setw(15) << left << "Candidate" << setw(15) << left << "Votes Received" << setw(15) << left << "% of Total Votes" << endl;
    for (int i = 0; i < numCandidates; ++i) {
        cout << setw(15) << left << candidates[i].lastName << setw(15) << left << candidates[i].votes << setw(15) << left << fixed << setprecision(2) << candidates[i].percentage << endl;
    }

    cout << "\nThe winner of the election is: " << winner << endl;

    // Free the dynamically allocated memory
    delete[] candidates;

    return 0;
}
