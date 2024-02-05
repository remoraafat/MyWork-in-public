#include"BoardGame_Classes.hpp"
#include<iostream>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;

pyramid_X_O_Board::pyramid_X_O_Board() {
    n_rows =  3;
    n_cols =  5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool pyramid_X_O_Board::update_board(int x, int y, char mark){
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0)
    &&!((x==0 && y==0) || (x==0 && y==1) || (x==1 && y==0))
      &&!((x==0 && y==3) || (x==0 && y==4) || (x==1 && y==4))) {
        board[x][y] = (mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void pyramid_X_O_Board::display_board(){

    for (int i: {0,1,2}) {
        cout << "\n ";
        for (int j: {0,1,2,3,4}) {
            if((i==0 && j ==0) ||(i==0 && j ==3) ||(i==0 && j ==4) ||(i==1 && j ==4))
            {
                cout<<"        ";
            }
            else if((i==0 && j ==1) ||(i==1 && j ==0))
            {
                cout<<"       |";
            }
            else {
                if (board[i][j] == 0) {
                    if(i==2&&j==0) cout << "|(" << i << "," << j << ")" << " |";
                    else cout << " (" << i << "," << j << ")" << " |";
                }
                else cout << "  [" << board[i][j] << "]" << "  |";
            }
        }
        cout << "\n------------------------------------------";
    }
    cout<<endl;
}
bool pyramid_X_O_Board::is_winnerX(){
    char winning[7][3][2] = {
        {{0 , 2} , {1 , 2} , {2 , 2}},
        {{0 , 2} , {1 , 3} , {2 , 4}},
        {{0 , 2} , {1 , 1} , {2 , 0}},
        {{1 , 1} , {1 , 2} , {1 , 3}},
        {{2 , 0} , {2 , 1} , {2 , 2}},
        {{2 , 1} , {2 , 2} , {2 , 3}},
        {{2 , 2} , {2 , 3} , {2 , 4}}
    };
    for (int i : {0, 1, 2, 3, 4, 5, 6})
    {
        if (board[winning[i][0][0]][winning[i][0][1]] == board[winning[i][1][0]][winning[i][1][1]]
            && board[winning[i][0][0]][winning[i][0][1]] == board[winning[i][2][0]][winning[i][2][1]]
            && board[winning[i][0][0]][winning[i][0][1]] == 'X')
            return true;
    }
    return false;
}
bool pyramid_X_O_Board::is_winnerO(){
    char winning[7][3][2] = {
    {{0 , 2} , {1 , 2} , {2 , 2}},
    {{0 , 2} , {1 , 3} , {2 , 4}},
    {{0 , 2} , {1 , 1} , {2 , 0}},
    {{1 , 1} , {1 , 2} , {1 , 3}},
    {{2 , 0} , {2 , 1} , {2 , 2}},
    {{2 , 1} , {2 , 2} , {2 , 3}},
    {{2 , 2} , {2 , 3} , {2 , 4}}
    };
    for (int i : {0, 1, 2, 3, 4, 5, 6})
    {
        if (board[winning[i][0][0]][winning[i][0][1]] == board[winning[i][1][0]][winning[i][1][1]]
            && board[winning[i][0][0]][winning[i][0][1]] == board[winning[i][2][0]][winning[i][2][1]]
            && board[winning[i][0][0]][winning[i][0][1]] == 'O')
            return true;
    }
    return false;
}
bool pyramid_X_O_Board::is_draw() {
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            if(board[i][j]==0 && !is_winnerO() && !is_winnerX() && !((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0))
                && !((i == 0 && j == 3) || (i == 0 && j == 4) || (i == 1 && j == 4))) return false;
        }
    }
    return true;
}

bool pyramid_X_O_Board::game_is_over () {
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            if(board[i][j]==0 && !((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0))
                && !((i == 0 && j == 3) || (i == 0 && j == 4) || (i == 1 && j == 4))) return false;
        }
    }
    return true;
}
int pyramid_X_O_Board::check_status() {
    if(is_winnerX()) return -2;
    else if(is_draw()) return 0;
    else if(is_winnerO()) return 2;
    else return 1;
}
int pyramid_X_O_Board::minimax(int& x, int& y, bool isMaximizing, bool firstTime)
{

    int res = pyramid_X_O_Board::check_status();
    if (res != 1) return res;

    int max = -10, min = 10;
    int finalI, finalJ;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0 && !((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0))
                && !((i == 0 && j == 3) || (i == 0 && j == 4) || (i == 1 && j == 4)))
            {
                if (isMaximizing) {
                    board[i][j] = 'O';
                    int sum = minimax(x, y, false, false);
                    board[i][j] = 0;
                    if (sum >= max) {
                        max = sum;
                        finalI = i;
                        finalJ = j;
                    }
                    if (firstTime)
                        cout << i << " , " << j << " : " << sum << endl;
                }
                else
                {
                    board[i][j] = 'X';
                    int sum = minimax(x, y, true, false);
                    board[i][j] = 0;
                    if (sum <= min) {
                        min = sum;
                        finalI = i;
                        finalJ = j;
                    }
                    if (firstTime)
                        cout << i << " , " << j << " : " << sum << endl;
                }
            }
        }
    }
    if (firstTime) {
        x = finalI;
        y = finalJ;
    }
    if (isMaximizing) return max;
    else return min;
}