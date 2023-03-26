#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

using namespace std;


struct PlayerInfo{
    string name; //Name of the Player
    int type; //player type; 0=Batsmen, 1=Baller, 2=Allround;
    float Bat_Avg; //Batting Average
    float Bat_S; //Batting Strike Rate
    float Ball_Avg; //Balling Average
    float Ball_S; //Balling Strike Rate
    float Value; //Price of the player
    bool Availability; //checks if true or false
};
//players data;
void playerData(float** data)
{
    srand(time(NULL));
    int i, j, bat=0, ball=0, all=0;
    float x;
    //player name;
    for(i=0;i<64;i++)
    {
        data[i][0]=i+1; //assigning players number instead of name;
    }
    //player type; 0=Batsmen, 1=Baller, 2=Allround;
    for(i=0;i<64;i++)
    {
        x=rand()%3; //genrating random numbers;
        if(x==0)
        {
            bat++;
            if(bat>22)
            {
                x++;
            }
        }
        if(x==1)
        {
            ball++;
            if(ball>21)
            {
                x++;
            }
        }
        if(x==2)
        {
            all++;
            if(all>21)
            {
                if(bat<22)
                {
                    x=0;
                }
                else if(ball<21)
                {
                    x=1;
                }
            }
        }
        data[i][1]=x;
    }
    // player Batting average;
    for(i=0; i<64; i++)
    {
        if(data[i][1]==0||data[i][1]==2)
        {
            x=(rand()%100);
            x/=100;
            data[i][2]=((rand()%100)+x);
        }
        if(data[i][1]==1)
        {
            data[i][2]=-1;
        }
    }
    //batting strike rate;
    for(i=0; i<64; i++)
    {
        if(data[i][1]==0||data[i][1]==2)
        {
            x=(rand()%100);
            data[i][3]=((rand()%100)+x);
        }
        if(data[i][1]==1)
        {
            data[i][3]=-1;
        }
    }
    //balling average;
    for(i=0; i<64; i++)
    {
        if(data[i][1]==1||data[i][1]==2)
        {
            x=(rand()%100);
            x/=100;
            data[i][4]=((rand()%50)+x);
        }
        if(data[i][1]==0)
        {
            data[i][4]=-1;
        }
    }
    //balling strike rate;
    for(i=0; i<64; i++)
    {
        if(data[i][1]==1||data[i][1]==2)
        {
            x=(rand()%100);
            x/=100;
            data[i][5]=((rand()%50)+x);
        }
        if(data[i][1]==0)
        {
            data[i][5]=-1;
        }
    }
    for(i=0;i<64;i++)
    {
        x=(rand()%100)+1;
        data[i][6]=(x*10000); //assigning values to players;
    }
    for(i=0;i<64;i++)
    {
        data[i][7]=1;
    }
}

void sortPlayers(float** data)
{
    float temp[8];
    int j;
    bool nomoreswaps=false;
    while (nomoreswaps==false)
    {
        nomoreswaps = true;
        for (j = 0; j<64; j++)
        {
            if (data[j][6] < data[j+1][6])
            {
                    for(int i=0; i<8; i++)
                    {
                        temp[i] = data[j][i];
                        data[j][i] = data[j+1][i];
                        data[j+1][i] = temp[i];
                        nomoreswaps = false;
                    }
            }
        }
    }
}

/*void assignRanks(int team[])
{
    int x;
    for(int i=0; i<4; i++)
    {
        x=((rand()%4)+1);
        for(int j=0; j<4; i++)
        {
            if(x==team[i])
            {
                if(x<=4)
                {
                    x--;
                }
                else if (x>=1)
                {
                    x++;
                }
            }
        }
        team[i]=x;
    }
}*/

void teamPicks(int *A1, int *B1, int *C1, int *D1, int* a, int* b, int* c, int* d, int* n)
{
    int R;
    //int n=0;
    cout<<"Team C1 Kindly enter number of players you want to retain: ";
    cin>>R;
    while(R>11||R<7)
    {
        cout<<"Enter a value between 7 and 11!";
        cin>>R;
    }
    *c=16-R;
    for(int i=0; i<R; i++)
    {
        *(C1+i)=*n;
        (*n)++;
    }
    cout<<"Team B1 Kindly enter number of players you want to retain: ";
    cin>>R;
    while(R>11||R<7)
    {
        cout<<"Enter a value between 7 and 11!";
        cin>>R;
    }
    for(int i=0; i<R; i++)
    {
        *(B1+i)=*n;
        (*n)++;
    }
    *b=16-R;
    cout<<"Team D1 Kindly enter number of players you want to retain: ";
    cin>>R;
    while(R>11||R<7)
    {
        cout<<"Enter a value between 7 and 11!";
        cin>>R;
    }
    *d=16-R;
    for(int i=0; i<R; i++)
    {
        *(D1+i)=*n;
        (*n)++;
    }
    cout<<"Team A1 Kindly enter number of players you want to retain: ";
    cin>>R;
    while(R>11||R<7)
    {
        cout<<"Enter a value between 7 and 11!";
        cin>>R;
    }
    *a=16-R;
    for(int i=0; i<R; i++)
    {
        *(A1+i)=*n;
        (*n)++;
    }


}

void playerSelection(int* n, int booked[], int* a, int* A1, float** data)
{
    int x;
    bool book=true;
    //(*a)--;

    while(book==true)
    {
        if((*a)==0)
        {
            cout<<"Your team is full!"<<endl;
            exit;
        }
        cout<<"Select a player: "<<endl;
        cin>>x;
        x--;
        while(x<0||x>64)
        {
            cout<<"Enter players between 1-64! Renter: \n";
            cin>>x; x--;
        }
        book=false;
        for(int i=0; i<64; i++)
        {

            if(booked[i]==data[x][0])
            {
                cout<<"Player ALready booked!"<<endl;
                book=true;
                //break;
                goto s1;
            }
        }
        s1:;
    }
    (*n)++;
    booked[*n]=data[x][0];

    data[x][7]=0;
    int i=16-*a;
    (*a)--;
    *(A1+i)=data[x][0];

}


float teamCost(int A[], float** data)
{
    int i, y;
    float x=0;
    for(i=0; i<16; i++)
    {
        y=A[i];
        x+=data[y][6];
    }
    return x;
}

int main()
{
    //int y;
    float** data =new float*[64];
    for(int i=0; i<64; i++)
        data[i]=new float [8];

    //float data [64][8];
    PlayerInfo PlayerI[64];
    int booked[64];
    playerData(data);
    string name[64]={"Sir Naveed", "Nia Fitzpatrick", "Adrienne Hutchinson", "Megan Lewis",
                    "Ahmed English", "Moiz Payi", "Dakota Davenport", "Kali Wheeler",
                    "Ingrid Cowan", "Pablo Cochran", "Saif Ur", "Davon Hooper", "Tucker Meza",
                    "Aileen Hester", "Miracle Wade", "Cassius Short", "Alvaro Davies",
                    "Deandre Marshall", "Saniya Baxter", "Kanwar Danial", "All Abduallah", "Niko Beard",
                    "Andre Shaw", "Olive Marquez", "Emilie Andrade", "Patrick Blair", "Andreas Erickson",
                    "Jorge Mclaughlin", "Porter Barber", "Reginald Hendrix", "Braydon Collins",
                    "Madalyn Guzman", "Angelica Archer", "All Umar", "Cierra Pruitt", "Krystal Chavez",
                    "Odin Zhang", "Hamza Munoz", "Helena Cole", "Genesis Hanson", "Augustus Baxter",
                    "Jay Leblanc", "Michelle Mills", "Aylin House", "Andy Kramer", "Beau Saunders",
                    "Serenity Little", "Lukas Newman", "Brenton Oliver", "Milo Perez","Kane Gillespie",
                    "Jerimiah Chandler", "Arjun Allen", "Griffin Neal", "Rowan Beck", "Salvador Trujillo",
                    "Madyson Calhoun", "Joel Mcmillan", "Nevaeh Ballard", "Hudson Rowland", "Yousuf Khan",
                    "Muhammad Bilal", "Musa Haroon", "Sohaib Ahmed"};
    string tname[4]={"A1", "B1", "C1", "D1"};
    int A1[16];
    int B1[16];
    int C1[16];
    int D1[16];
    int team[4]={4,2,1,3}, a=0, b=0, c=0, d=0, n=1, y;
    int* a1=&a;
    int* b1=&b;
    int* c1=&c;
    int* d1=&d;
    int* n1=&n;
    int* y1=&y;

    for(int i=0; i<64; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(j==0)
            {
                y=static_cast<int>(data[i][0])-1;
                PlayerI[i].name=name[y];
            }
            if(j==1)
            {
                PlayerI[i].type=data[i][1];
            }
            if(j==2)
            {
                PlayerI[i].Bat_Avg=data[i][2];
            }
            if(j==3)
            {
                PlayerI[i].Bat_S=data[i][3];
            }
            if(j==4)
            {
                PlayerI[i].Ball_Avg=data[i][4];
            }
            if(j==5)
            {
                PlayerI[i].Ball_S=data[i][5];
            }
            if(j==6)
            {
                PlayerI[i].Value=data[i][6];
            }
            if(j==7)
            {
                PlayerI[i].Availability=true;
            }
        }
    }

    /*for(int i=0; i<64; i++)
    {
        cout<<"---------------------------------------------\n";
        cout<<PlayerI[i].name<<endl;
        cout<<"Type: "<<PlayerI[i].type<<endl;
        cout<<"Batting Average: "<<PlayerI[i].Bat_Avg<<endl;
        cout<<"Batting Strike Rate: "<<PlayerI[i].Bat_S<<endl;
        cout<<"Balling Average: "<<PlayerI[i].Ball_Avg<<endl;
        cout<<"Balling Strike Rate: "<<PlayerI[i].Ball_S<<endl;
        cout<<"Value: $"<<PlayerI[i].Value<<endl;
        cout<<"Availability: "<<PlayerI[i].Availability<<endl;
        cout<<"---------------------------------------------\n";
        cout<<endl<<endl;
    }
    system("PAUSE");
    system("CLS");*/

    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"                                                                 PSL PLAYERS";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n\n";
    cout<<"Sr Name                          Type             Batting Average  Batting Strike   Balling Average  Balling Strike   Value            Availability"<<endl;
    cout<<"                                                                   Rate                              Rate"<<endl<<endl;;
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(j==0)
            {
                y=static_cast<int>(data[i][j])-1;
                cout<<setw(2)<<left<<i+1<<"  "<<left<<setw(30)<<name[y];
                continue;
            }
            if(j==7)
            {
                if(data[i][j]==1)
                    cout<<"true";
                else
                    cout<<"false";
                continue;
            }
            if(j==6)
            {
                cout<<setw(17)<<fixed<<left<<setprecision(0)<<data[i][j];
            }
            else if (j==1)
            {
                cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
            }
            else if (data[i][j]<2)
            {
                cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
            }
            else
            {
                cout<<setw(17)<<left<<fixed<<setprecision(2)<<data[i][j];
            }
        }
        cout<<endl;
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    system("PAUSE");
    system("CLS");

    system("color F");
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"                                                                 PSL PLAYERS";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n\n";
    sortPlayers(data);
    //assignRanks(t);
    cout<<"Sr  Name                          Type             Batting Average  Batting Strike   Balling Average  Balling Strike   Value            Availability"<<endl;
    cout<<"                                                                    Rate                              Rate"<<endl<<endl;;
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(j==0)
            {
                y=static_cast<int>(data[i][j])-1;
                cout<<setw(2)<<left<<i+1<<"  "<<left<<setw(30)<<name[y];
                continue;
            }
            if(j==7)
            {
                if(data[i][j]==1)
                    cout<<"true";
                else
                    cout<<"false";
                continue;
            }
            if(j==6)
            {
                cout<<setw(17)<<fixed<<left<<setprecision(0)<<data[i][j];
            }
            else if (j==1)
            {
                cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
            }
            else if (data[i][j]<2)
            {
                cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
            }
            else
            {
                cout<<setw(17)<<left<<fixed<<setprecision(2)<<data[i][j];
            }
        }
        cout<<endl;
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl<<endl;
    system("PAUSE");
    system("CLS");
        for(int i=0; i<64; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(j==0)
            {
                y=static_cast<int>(data[i][0])-1;
                PlayerI[i].name=name[y];
            }
            if(j==1)
            {
                PlayerI[i].type=data[i][1];
            }
            if(j==2)
            {
                PlayerI[i].Bat_Avg=data[i][2];
            }
            if(j==3)
            {
                PlayerI[i].Bat_S=data[i][3];
            }
            if(j==4)
            {
                PlayerI[i].Ball_Avg=data[i][4];
            }
            if(j==5)
            {
                PlayerI[i].Ball_S=data[i][5];
            }
            if(j==6)
            {
                PlayerI[i].Value=data[i][6];
            }
            if(j==7)
            {
                PlayerI[i].Availability=true;
            }
        }
    }

    /*for(int i=0; i<64; i++)
    {
        cout<<"---------------------------------------------\n";
        cout<<PlayerI[i].name<<endl;
        cout<<"Type: "<<PlayerI[i].type<<endl;
        cout<<"Batting Average: "<<PlayerI[i].Bat_Avg<<endl;
        cout<<"Batting Strike Rate: "<<PlayerI[i].Bat_S<<endl;
        cout<<"Balling Average: "<<PlayerI[i].Ball_Avg<<endl;
        cout<<"Balling Strike Rate: "<<PlayerI[i].Ball_S<<endl;
        cout<<"Value: $"<<PlayerI[i].Value<<endl;
        cout<<"Availability: "<<PlayerI[i].Availability<<endl;
        cout<<"---------------------------------------------\n";
        cout<<endl<<endl;
    }
    system("PAUSE");
    system("CLS");*/
    /*for(int i=0; i<11; i++)
        cout<<A1[i]<<endl;*/

    cout<<endl<<endl;
    //assignRanks(team);
    cout<<setw(5)<<left<<"Team"<<setw(5)<<left<<"Rank"<<endl;
    for(int i=0; i<4; i++)
    {
        cout<<setw(5)<<tname[i]<<setw(5)<<team[i]<<endl;
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    teamPicks(A1, B1, C1, D1, a1, b1, c1, d1, n1);
    for(int i=0; i<16; i++)
    cout<<A1[i]<<endl;
    for (int i=0; i<n; i++)
    {
        booked[i]=i;
        for(int j=0; j<64; j++)
        {
            if (data[j][0]==booked[i])
            {
                data[j][7]=0;
            }
        }
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"                                                                 PSL PLAYERS";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n\n";
    cout<<"Sr  Name                          Type             Batting Average  Batting Strike   Balling Average  Balling Strike   Value            Availability"<<endl;
    cout<<"                                                                    Rate                              Rate"<<endl<<endl;;
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(j==0)
            {
                y=static_cast<int>(data[i][j])-1;
                cout<<setw(2)<<left<<i+1<<"  "<<left<<setw(30)<<name[y];
                goto start;
            }
            if(j==7)
            {
                if(data[i][j]==1)
                    cout<<"true";
                else if(data[i][j]==0)
                    cout<<"false";
                goto start;
            }
            if(j==6)
            {
                cout<<setw(17)<<fixed<<left<<setprecision(0)<<data[i][j];
            }
            else if (j==1)
            {
                cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
            }
            else if (data[i][j]<2)
            {
                cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
            }
            else
            {
                cout<<setw(17)<<left<<fixed<<setprecision(2)<<data[i][j];
            }
            start:
        ;}
        cout<<endl;
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl<<endl;

    while(n<=64)
    {

            if(*c1<=16)
            {
                playerSelection(n1,booked,c1,C1,data);
                //C1[*c1]=*y1;
            }
            if(*b1<=16)
            {
                playerSelection(n1,booked,b1,B1,data);
                //B1[*b1]=*y1;
            }
            if(*d1<=16)
            {
                playerSelection(n1,booked,d1,D1,data);
                //D1[*d1]=*y1;
            }
            if(*a1<=16)
            {
                playerSelection(n1,booked,a1,A1,data);
                //A1[*a1]=*y1;
            }



            system("PAUSE");
            system("CLS");
            system("color F");
            cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout<<"                                                                 PSL PLAYERS";
            cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\n\n";
            sortPlayers(data);
            //assignRanks(t);
            cout<<"Sr  Name                          Type             Batting Average  Batting Strike   Balling Average  Balling Strike   Value            Availability"<<endl;
            cout<<"                                                                    Rate                              Rate"<<endl<<endl;;
            for(int i=0; i<64; i++)
            {
                for(int j=0; j<8; j++)
                {
                    if(j==0)
                    {
                        y=static_cast<int>(data[i][0])-1;
                        cout<<setw(2)<<left<<i+1<<"  "<<left<<setw(30)<<name[y];
                        goto start1;
                    }
                    if(j==7)
                    {
                        if(data[i][j]==1)
                            cout<<"true";
                        else
                            cout<<"false";
                        goto start1;
                    }
                    if(j==6)
                    {
                        cout<<setw(17)<<fixed<<left<<setprecision(0)<<data[i][j];
                    }
                    else if (j==1)
                    {
                        cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
                    }
                    else if (data[i][j]<2)
                    {
                        cout<<setw(17)<<setprecision(0)<<left<<data[i][j];
                    }
                    else
                    {
                        cout<<setw(17)<<left<<fixed<<setprecision(2)<<data[i][j];
                    }
                    start1:
                ;}
                cout<<endl;
            }
            cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout<<endl<<endl;
            //system("PAUSE");
            //system("CLS");
    }
    /*for(int i=0; i<16; i++)
    cout<<A1[i]<<endl;*/
    cout<<"Teams            Value"<<endl;
    cout<<"A1               $"<<teamCost(A1,data)<<endl;
    cout<<"B1               $"<<teamCost(B1,data)<<endl;
    cout<<"C1               $"<<teamCost(C1,data)<<endl;
    cout<<"D1               $"<<teamCost(D1,data)<<endl;


    for(int i=0; i<64; i++)
        delete[] data[i];
    delete [] data;

    return 0;
}










