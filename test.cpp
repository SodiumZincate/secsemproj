#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void init_league(string input_string)
    {
    string token;
    int i = 0;
    stringstream tokenStream(input_string);
    vector<string> list;
    while(getline(tokenStream, token, '\n'))
    {
        list.push_back(token);
    }   
    string league_name = list[0];
    int league_id = stoi(list[1]);
    int league_group_stages = stoi(list[2]);
    int league_round_robin = stoi(list[3]);
    int league_qualifiers = stoi(list[4]);
    int league_groups = stoi(list[5]);
    int league_team_number = stoi(list[6]);

    cout << league_name << endl;
    cout << league_id << endl;
    cout << league_group_stages << endl;
    cout << league_round_robin << endl;
    cout << league_qualifiers << endl;
    cout << league_groups << endl;
    cout << league_team_number << endl;
}
int main()
{
    string s = "Ligue 1\n5\n2\n9\n4\n6\n7\n8";
    init_league(s);
}