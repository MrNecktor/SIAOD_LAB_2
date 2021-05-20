#include <vector>
#include <iostream>
using namespace std;

class figure
{
private:
    int x;
    int y;

public:
    figure() {x=0; y=0;}
    figure(int xNew, int yNew) {x=xNew; y=yNew; }

    int getx() { return x;}

    int gety() { return y;}

    void setx(int xNew) { x=xNew;}

    void sety(int yNew) { y=yNew;}
};

class chess
{
private:
    bool board[8][8]={true, };

public:
    chess(){reset();}

    void reset()
    {
        for (int i=0; i<8; i++)
        {
            for (int j=0; j<8; j++)
            {
                board[i][j]=true;
            }
        }
    }

    void removePositions(int i, int j)
    {
        //cols and rows
        for (int k=0; k<8; k++)
        {
            board[i][k]=false;
            board[k][j]=false;
        }

        int tempi=i;
        int tempj=j;

        //main diag
        while (tempi!=0 && tempj!=0)
        {
            tempi--;
            tempj--;
        }

        while (tempi!=7 && tempj!=7)
        {
            board[tempi][tempj]=false;
            tempi++;
            tempj++;
        }

        while(i!=7 && j!=7)
        {
            i++;
            j--;
        }

        while (i!=0 && j!=7)
        {
            board[i][j]=false;
            i--;
            j++;
        }
    }

    vector<figure> solve()
    {
        figure place;
        vector<figure> places;
        int i=0;
        int j=0;
        while(places.size()!=8)
        {
            if (board[i][j])
            {
                place.setx(j);
                place.sety(i);
                places.push_back(place);
                removePositions(i, j);
                i+=2;
                j++;
            }
            if (i>7)
            {
                i = 0;
            }
            while(!board[i][j])
            {
                i++;
            }
        }
        return places;
    }

    bool check(figure temp, vector<figure> table)
    {
        for (auto i: table)
            if (i.getx()==temp.getx() && i.gety()==temp.gety())
                return true;
        return false;
    }

    void printBoard(vector<figure> table)
    {
        figure quieen;

        for (int i=0; i<8; i++)
        {
            for (int j=0; j<8; j++)
            {
                quieen.setx(j);
                quieen.sety(i);

                if (check(quieen, table))
                {
                    cout <<"Q ";
                }
                else if (board[i][j])
                    cout << "+ ";
                else
                    cout <<"- ";
            }
            cout<<endl;
        }
    }
};