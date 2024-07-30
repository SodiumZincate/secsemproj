#include "logic.h"

//this file is used to create matches 

void createMatchesGS(League L)
{
    Match Mgs[MAX_MATCHES_GT];

    //for group stage matches
    int i, j, k = 0;
    if (L.league_groups != 0)
    {
        if (L.league_round_robin == 2)
        {
            for (i = 0; i < L.league_team_number; i++)
            {
                for (j = 0; j < L.league_team_number; j++)
                {
                    if ((i != j) && (L.T[i].team_group == L.T[j].team_group))
                    {
                        Mgs[k].T1 = L.T[i];
                        Mgs[k].T2 = L.T[j];
                        k++;
                    }
                }
            }
        }
        if (L.league_round_robin == 1)
        {
            for (i = 0; i < L.league_team_number; i++)
            {
                for (j = i; j < L.league_team_number; j++)
                {
                    if ((i != j) && (L.T[i].team_group == L.T[j].team_group))
                    {
                        Mgs[k].T1 = L.T[i];
                        Mgs[k].T2 = L.T[j];
                        k++;
                    }
                }
            }
        }
    }

    shuffleArray(Mgs, k);
    rearrangeMatches(Mgs, k);

	// Check and print the results
    if (hasConsecutiveMatches(Mgs, k)) {
        std::cout << "Consecutive matches involving the same team found!" << std::endl;
    } else {
        std::cout << "No consecutive matches involving the same team." << std::endl;
    }

    string str;
    for (i = 0; i < k; i++)
    {
        str = to_string(L.league_user_id) + "\n" + to_string(L.league_id) + "\n" +
        to_string(Mgs[i].T1.team_id) + "\n" + to_string(Mgs[i].T2.team_id) + "\n" + "0" + "\n" + "0" + "\n" + "0";
        stringstream temp;
        int errorDatabase = updateDatabase(str, "insert_match", temp);
        if (errorDatabase!=0)
        {
            std::cout << "\nError initializing database" << std::endl;
        }
        else
        {
            std::cout << "\nData inserted successfully" << std::endl;
        } 
        str.clear();
    }
}

// Check if the current match results in consecutive matches for any team
bool hasConsecutiveMatches(const Match arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i].T1.team_id == arr[i-1].T1.team_id ||
            arr[i].T1.team_id == arr[i-1].T2.team_id ||
            arr[i].T2.team_id == arr[i-1].T1.team_id ||
            arr[i].T2.team_id == arr[i-1].T2.team_id) {
            return true;
        }
    }
    return false;
}

// Rearrange matches to avoid consecutive matches
void rearrangeMatches(Match arr[], int size) {
    bool fixed;
    do {
        fixed = true;
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i].T1.team_id == arr[i+1].T1.team_id ||
                arr[i].T1.team_id == arr[i+1].T2.team_id ||
                arr[i].T2.team_id == arr[i+1].T1.team_id ||
                arr[i].T2.team_id == arr[i+1].T2.team_id) {
                // Try to find a non-conflicting match to swap with
                bool swapped = false;
                for (int j = i + 2; j < size; ++j) {
                    if (arr[j].T1.team_id != arr[i].T1.team_id &&
                        arr[j].T2.team_id != arr[i].T1.team_id &&
                        arr[j].T1.team_id != arr[i].T2.team_id &&
                        arr[j].T2.team_id != arr[i].T2.team_id) {
                        std::swap(arr[i+1], arr[j]);
                        swapped = true;
                        fixed = false; // Set to false to continue checking
                        break;
                    }
                }
                if (swapped) {
                    break; // Restart the process after a successful swap
                }
            }
        }
    } while (!fixed);
}

// Shuffle the array using the Fisher-Yates algorithm
void shuffleArray(Match arr[], int size) {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Shuffle the array
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}