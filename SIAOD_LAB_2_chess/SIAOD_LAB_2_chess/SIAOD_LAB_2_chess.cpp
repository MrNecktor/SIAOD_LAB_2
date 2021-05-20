
#include <iostream>
#include "Chess.cpp"


using namespace std;


int main()
{
    chess table;

    vector<figure> board;

    board = table.solve();
    table.printBoard(board);
    for (auto i : board)
        cout << i.getx() << " " << i.gety() << "; ";
}


