#include <iostream>
#include<vector>
#include<random>
#include<utility>
using namespace std;
double sprung=0;
int low=1;
int high=25;
void init_sim(vector<vector<bool>> &trap, vector<unsigned int> &ballCycles);
void print_grid(const vector<vector<bool>> &traps, const unsigned &clock, const unsigned &noballsinair);
void print_stat(const vector<vector<bool>> &traps, const unsigned &maximumballs,const unsigned &clock);
unsigned release_balls(vector<vector<bool>> &traps, vector<unsigned int> &ballCycles);
void update_cycles(vector<unsigned int> &ballCycles);
void print_grid(const vector<vector<bool>> &trap, const unsigned &clock, const unsigned &noballsinair)
{
            cout<<"\n"<<"clock: "<<clock<<" No. of balls in air: "<<noballsinair<<"\n";
            for(int i=0;i<25;i++)
             {
             for(int j=0;j<25;j++)
                {
                if(trap[i][j]!=true)
                    {
                    cout<<"X ";  
                    }
                    else 
                    {
                    cout<<". "; 
                    }
             cout<<"\n";
                }
             }
}
void print_stat(const vector<vector<bool>> &trap, const unsigned &maximumballs,const unsigned &clock) 
{
            for(int i=0;i<25;i++)
                {
                for(int j=0;j<25;j++)
                     {
                     if(trap[i][j]!=true)
                     sprung=sprung+1;
                     }
                 }
             double completeGrid =625;
             double NumSprung = (sprung / completeGrid) * 100.0; 
             cout <<"\n"<<"Maximum balls that were in air:    " << maximumballs<< endl; 
             cout << "\n"<<"Percentage of the traps sprung:   " << NumSprung << "%" << endl;
             cout <<"\n"<< "Total times units elapsed:        " << clock << endl;
}

int main()
{
           vector<vector<bool>> trap;
           vector<unsigned int> ballCycles;
           init_sim(trap,ballCycles);
           release_balls(trap,ballCycles);
           return 0;
}
void init_sim(vector<vector<bool>> &trap, vector<unsigned int> &ballCycles)
{
           int noballsinAir=0;
           int timeElapsed=0;
           vector<bool> grid;
           for(unsigned int i=0;i<25;i++)
                 {
                  for(unsigned int j=0;j<25;j++)
                     {
                       grid.push_back(true);
                     }
                 }
                 trap.push_back(grid);
            print_grid(trap,timeElapsed,noballsinAir);
            srand(1);
            ballCycles.push_back(1);
}
unsigned release_balls(vector<vector<bool>> &trap, vector<unsigned int> &ballCycles)
{           
            int maximumballs=0; 
            int size=ballCycles.size();
            int noballsinAir=0;
            int timeElapsed= 0;
            while(size)
                 {
                  timeElapsed=timeElapsed+1;
                  for(auto i=ballCycles.begin();i!=ballCycles.end();++i)
                         {
                       if(ballCycles[*i]>0)
                          {
                       ballCycles[*i]--;
                          }
                       else
                     {
                      pair<int,int> p;
                      p.first=rand()%25;
                      p.second=rand()%25;
                      ballCycles.erase(ballCycles[0]+i);
                      if(trap[p.first][p.second] ==true)
                       {
                      trap[p.first][p.second]=false;
                      update_cycles(ballCycles);
                       }
                       (size>maximumballs)?(maximumballs=size):(maximumballs=0);
                     }
                  }
               if(timeElapsed%10==0)
               print_grid(trap,timeElapsed,size);
                 }  
               print_grid(trap,timeElapsed,size);
               print_stat(trap,maximumballs,timeElapsed);
                 }
void update_cycles(vector<unsigned int> &ballCycles)
{
               ballCycles.push_back((rand()%(high-low+1))+low);
               ballCycles.push_back((rand()%(high-low+1))+low); 
}

