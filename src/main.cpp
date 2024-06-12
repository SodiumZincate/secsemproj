#include<iostream>

class Team{
    private:
        std::string name;
        int position;
        int points;
        int matches;
        int win;
        int loss;
        int draw;
    public:
        Team(std::string, int);
        void displayteam();

        int Getpoints();
        int Getposition();
        std::string Getname();
};

Team::Team(std::string x="default_name", int default_position=0){
    name = x;;
    points = 0;
    matches = 0;
    win = 0;
    loss = 0;
    draw = 0;
    position = default_position;
}

void Team::displayteam(){
    std::cout<<"Name = "<<name<<std::endl;
    std::cout<<"Position = "<<position<<std::endl;
    std::cout<<"Points = "<<points<<std::endl;
    std::cout<<"Mathches = "<<matches<<std::endl;
    std::cout<<"Wins = "<<win<<std::endl;
    std::cout<<"Losses = "<<loss<<std::endl;
    std::cout<<"Draws = "<<draw<<std::endl;
}

std::string Team::Getname(){
    return name;
}
int Team::Getposition(){
    return position;
}
int Team::Getpoints(){
    return points;
}

int main(void)
{
    int no_of_teams;
    std::string team_name;
    std::cout<<"Enter the number of teams: ";
    std::cin>>no_of_teams;
    std::cout<<std::endl<<"Team Entry:"<<std::endl<<std::endl;

    Team *teams = new Team[no_of_teams];

    for(int i=0; i<no_of_teams; i++){
        std::cout<<"Name = ";
        std::cin>>team_name;
        teams[i] = Team(team_name, i+1);
    }

    std::cout<<std::endl<<"Team Details:"<<std::endl<<std::endl;
    for(int i=0; i<no_of_teams; i++){
        teams[i].displayteam();
        std::cout<<std::endl;
    }

    return 0;
}
