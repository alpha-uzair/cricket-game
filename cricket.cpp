#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cricket.h"
using namespace std;

Team::Team():totalplayers(3),score(0),name("None"),rrP1(0),rrP2(0),rrP3(0){}
Team::Team(string n):totalplayers(3),score(0),rrP1(0),rrP2(0),rrP3(0){name=n;}

Play::Play(){
    Comp.name="Computer";
    User.name="User";
    balls=6;
}


void Play::UserInning(){
    cout<<"\nPLAYING TEAM: "<<User.name<<endl;
    int s;
    unsigned seed=time(0);
    srand(seed);
    int i=1;
    int tempscore,tempballs;
    while(balls!=0 && User.totalplayers!=0){
        int x=rand()%8;
        if(x==7){
            cout<<"\nBall :"<<i<<" |Runs on this ball :"<<x<< " | Current score :"<<User.score;
            cout<<"\nPlayer is out!!";
            User.totalplayers--;
            if(User.totalplayers=2){
                User.rrP1=User.score/i;
                tempscore=User.score;
                tempballs=i;
            }else if(User.totalplayers=1){
                User.rrP2=tempscore/(i-tempballs);
                tempscore=User.score-tempscore;
                tempballs=i-tempballs;
            }else{
                User.rrP3=tempscore/(i-tempballs);
            }
            balls=balls-1;
            i++;
        }else{
            User.score=User.score+x;
            cout<<"\nBall :"<<i<<" | Runs on this ball :"<<x<< " | Current score :"<<User.score;
            balls=balls-1;
            i++;
            if (User.totalplayers==3){
                User.rrP1=User.score/6;
            }
        }
    }

}
void Play::CompInning(){
    cout<<"\nPLAYING TEAM: "<<Comp.name<<endl;
    int s;
    unsigned seedd=time(0);
    srand(seedd);
    int i=1;
    int tempscore,tempballs;
    while(balls!=0 && Comp.totalplayers!=0){
        int y=1+(rand()%6);
        if(y==7){
            cout<<"\nBall :"<<i<<" |Runs on this ball :"<<y<< "  | Current score :"<<Comp.score;
            cout<<"\nPlayer is out!!";
            Comp.totalplayers--;
            if(Comp.totalplayers=2){
                Comp.rrP1=Comp.score/i;
                tempscore=Comp.score;
                tempballs=i;
            }else if(Comp.totalplayers=1){
                Comp.rrP2=tempscore/(i-tempballs);
                tempscore=Comp.score-tempscore;
                tempballs=i-tempballs;
            }else{
                Comp.rrP3=tempscore/(i-tempballs);
            }
            balls=balls-1;
            i++;
        }else{
            Comp.score=Comp.score+y;
            cout<<"\nBall :"<<i<<" | Runs on this ball :"<<y<< " | Current score :"<<Comp.score;
            balls=balls-1;
            i++;
            if (Comp.totalplayers==3){
                Comp.rrP1=Comp.score/6;
            }
        }
    }
}
void Play::secondinning(){
    balls=6;
    cout<<"\n\n------Second Innings------\n";
    if (comp==true){UserInning();}else{CompInning();}
}
void Play::Toss(){
    cout<<"\n\n------Game On!!------\n";
    int r,n;
    srand(time(0));
    r=1+(rand()%2);
    cout<<"\nPress 1 or 2 for toss: ";cin>>n;
    srand(time(0));
    r=1+(rand()%2);
    cout<<"\n(random number generated for toss is "<<r<<" )\n";
    if(n==r){
        int x;
        cout<<"\nYou won the toss!!\n";
        cout<<"\nPress 1 to bat or Press 2 to bowl: ";cin>>x;
        if(x==1){
            cout<<"\nYou have chosen to bat!!\n";
            cout<<"\n\n------First Innings------\n";
            UserInning();
            user=true;
            comp=false;
        }else{
            cout<<"\nYou have chosen to bowl!!\n";
            cout<<"\n\n------First Innings------\n";
            CompInning();
            comp=true;
            user=false;
        }

    }else{
        cout<<"\nYou lost the toss\n";
        CompInning();
        comp=true;
        user=false;
    }
}

void Play::summary(){
    if(User.score>Comp.score){winningteam=User;loosingteam=Comp;}
    else if(User.score<Comp.score){winningteam=Comp;loosingteam=User;}
    else{cout<<"\n\nMATCH DRAWN!!\n";exit(0);}
    cout<<"\n\n------Summary of the Match------\n";
    cout<<"\nWinning Team :"<<winningteam.name;
    cout<<"\nPlayers left :"<<winningteam.totalplayers;
    cout<<"\nWon by "<<winningteam.score-loosingteam.score<<" runs!!";
    cout<<"\nRunrate of player one :"<<winningteam.rrP1;
    string playerofthematch;
    if(winningteam.rrP2==0){
        playerofthematch="Player One";
        cout<<"\nRunrate of player two : 0 (not played)";
        cout<<"\nRunrate of player three : 0 (not played)";
    }else{
        cout<<"\nRunrate of player two :"<<winningteam.rrP2;
        if(winningteam.rrP1>winningteam.rrP2){playerofthematch="Player One";}else{playerofthematch="Player Two";}
        if(winningteam.rrP3==0){
            cout<<"\nRunrate of player three : 0 (not played)";
        }else{
            cout<<"\nRunrate of player three :"<<winningteam.rrP3;
        }
    }
    cout<<"\nMan of the match is "<<playerofthematch;
}



