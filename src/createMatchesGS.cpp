#include "logic.h"

//this file is used to create matches 

void createMatchesGS(League L)
{
    Match Mgs[MAX_MATCHES_GT];

    //for group stage matches
    int i, j, k;
    if (L.league_groups != 0)
    {
        if (L.league_round_robin == 2)
        {
            for (i = 0; i < L.league_team_number; i++)
            {
                k = 0;
                for (j = 0; j < L.league_team_number; j++)
                {
                    if ((i != j) && (L.T[i].team_group == L.T[j].team_group))
                    {
                        L.T[i].M[k]->T2 = L.T[j];
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
                k = 0;
                for (j = i; j < L.league_team_number; j++)
                {
                    if ((i != j) && (L.T[i].team_group == L.T[j].team_group))
                    {
                        L.T[i].M[k]->T2 = L.T[j];
                        Mgs[k].T1 = L.T[i];
                        Mgs[k].T2 = L.T[j];
                        k++;
                    }
                }
            }
        }
    }

    // int s = sizeof(Mgs) / sizeof(Match);
    // shuffleArray(Mgs, k);

    // string str;

    // for (i = 0; i < k; i++)
    // {
    //     str = to_string(L.league_user_id) + "\n" + to_string(L.league_id) + "\n" +
    //     to_string(Mgs[i].T1.team_id) + "\n" + to_string(Mgs[i].T2.team_id) + "\n" + "0" + "\n" + "0" + "\n" + "0";
    //     stringstream temp;
    //     // int errorDatabase = updateDatabase(str, "insert_match", temp);

    //     // if (errorDatabase!=0)
    //     // {
    //     //     std::cout << "\nError initializing database" << std::endl;
    //     // }
    //     // else
    //     // {
    //     //     std::cout << "\nData inserted successfully" << std::endl;
    //     // }
    //     // str.clear();
    // }
}

void shuffleArray(Match arr[], int size)
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Shuffle the array
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}