//Cristian Taylor
//5-5-2024
//This program will store candidates and their vote count within an array
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Candidate {
    string lastName;
    int votes;
    float percentage;
};

int main() {
    // Initialize vector to store candidates
    vector<Candidate> candidates(5);

    // Input candidate names and votes
    for (int i = 0; i < 5; ++i) {
        cout << "Enter candidate's last name: ";
        cin >> candidates[i].lastName;
        cout << "Enter number of votes received by " << candidates[i].lastName << ": ";
        cin >> candidates[i].votes;
    }

    // Calculate total number of votes
    int totalVotes = 0;
    for (const auto& candidate : candidates) {
        totalVotes += candidate.votes;
    }

    // Calculate percentage of votes for each candidate
    for (auto& candidate : candidates) {
        candidate.percentage = (static_cast<float>(candidate.votes) / totalVotes) * 100;
    }

    // Find the winner
    int maxVotes = 0;
    string winner;
    for (const auto& candidate : candidates) {
        if (candidate.votes > maxVotes) {
            maxVotes = candidate.votes;
            winner = candidate.lastName;
        }
    }

    // Output results with proper format.
    cout << "\nResults:\n";
    cout << setw(15) << left << "Candidate" << setw(15) << left << "Votes Received" << setw(15) << left << "% of Total Votes" << endl;
    for (const auto& candidate : candidates) {
        cout << setw(15) << left << candidate.lastName << setw(15) << left << candidate.votes << setw(15) << left << fixed << setprecision(2) << candidate.percentage << endl;
    }

    cout << "\nThe winner of the election is: " << winner << endl;
   
    getch();
    return 0;
}
