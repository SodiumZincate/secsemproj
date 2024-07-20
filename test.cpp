#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "logic.h"
#include <cmath>

using namespace std;

int main()
{
    League L;
    L.league_team_number = 18;
    L.league_groups = 4;
    char group[20];
    int i, j, k;
    for (i = 0; i < L.league_groups; i++)
    {
        group[i] = (char) (65 + i);
    }
    
    j = 0, k = 0;
    for(int j = 0; j < L.league_groups; j++)
    {
    
    for (i = j; i < L.league_team_number; i += L.league_groups)
    {
        L.T[i].team_group = group[j];
    }
    k++;
    }

    for (j = 0; j < L.league_team_number; j++)
    {
        cout << "Team: " << j << " Group: " << L.T[j].team_group << endl;
    } 
}