// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;


X_O_Board::X_O_Board () {
   n_rows = n_cols = 3;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}
bool X_O_Board::update_board (int x, int y, char mark){

   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
      board[x][y] =  mark ;
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
   for (int i: {0,1,2}) {
      cout << "\n| ";
      for (int j: {0,1,2}) {
          if(board[i][j]==0){cout << " (" << i << "," << j << ")"<< " |";}
          else cout << "  ["<<  board [i][j] <<"]"<< "  |";
      }
      cout << "\n-------------------------------";
   }
   cout << endl;
}

bool X_O_Board::is_winnerX() {
    char row_win[3][3][2] = {
        {{0 , 0} , {0 , 1} , {0 , 2}},
        {{1 , 0} , {1, 1} , {1,2}},
        {{2,0} , {2,1} , {2 ,2}} },
        colm_col[3][3][2] = {
        {{0 , 0} , {1 , 0} , {2 , 0}},
        {{0 , 1} , {1, 1} , {2,1}},
        {{0,2} , {1,2} , {2 ,2}} },
        diag_win[2][3][2] = {
        {{0 , 0} , {1 , 1} , {2 , 2}},
        {{0 , 2} , {1, 1} , {2,0}}
    };
    for (int i=0 ; i<3 ; i++)
    {
        if (board[row_win[i][0][0]][row_win[i][0][1]] == board[row_win[i][1][0]][row_win[i][1][1]]
            && board[row_win[i][0][0]][row_win[i][0][1]] == board[row_win[i][2][0]][row_win[i][2][1]]
            && board[row_win[i][0][0]][row_win[i][0][1]] == 'X')
            return true;

        if (board[colm_col[i][0][0]][colm_col[i][0][1]] == board[colm_col[i][1][0]][colm_col[i][1][1]]
            && board[colm_col[i][0][0]][colm_col[i][0][1]] == board[colm_col[i][2][0]][colm_col[i][2][1]]
            && board[colm_col[i][0][0]][colm_col[i][0][1]] == 'X')
            return true;
    }
    for (int i : {0, 1})
    {
        if (board[diag_win[i][0][0]][diag_win[i][0][1]] == board[diag_win[i][1][0]][diag_win[i][1][1]]
            && board[diag_win[i][0][0]][diag_win[i][0][1]] == board[diag_win[i][2][0]][diag_win[i][2][1]]
            && board[diag_win[i][0][0]][diag_win[i][0][1]] == 'X') return true;
    }
    return false;
}
bool X_O_Board::is_winnerO() {
    char row_win[3][3][2] = {
        {{0 , 0} , {0 , 1} , {0 , 2}},
        {{1 , 0} , {1, 1} , {1,2}},
        {{2,0} , {2,1} , {2 ,2}} },
        colm_col[3][3][2] = {
        {{0 , 0} , {1 , 0} , {2 , 0}},
        {{0 , 1} , {1, 1} , {2,1}},
        {{0,2} , {1,2} , {2 ,2}} },
        diag_win[2][3][2] = {
        {{0 , 0} , {1 , 1} , {2 , 2}},
        {{0 , 2} , {1, 1} , {2,0}}
    };
    for (int i = 0; i < 3; i++)
    {
        if (board[row_win[i][0][0]][row_win[i][0][1]] == board[row_win[i][1][0]][row_win[i][1][1]]
            && board[row_win[i][0][0]][row_win[i][0][1]] == board[row_win[i][2][0]][row_win[i][2][1]]
            && board[row_win[i][0][0]][row_win[i][0][1]] == 'O')
            return true;

        if (board[colm_col[i][0][0]][colm_col[i][0][1]] == board[colm_col[i][1][0]][colm_col[i][1][1]]
            && board[colm_col[i][0][0]][colm_col[i][0][1]] == board[colm_col[i][2][0]][colm_col[i][2][1]]
            && board[colm_col[i][0][0]][colm_col[i][0][1]] == 'O')
            return true;
    }
    for (int i : {0, 1})
    {
        if (board[diag_win[i][0][0]][diag_win[i][0][1]] == board[diag_win[i][1][0]][diag_win[i][1][1]]
            && board[diag_win[i][0][0]][diag_win[i][0][1]] == board[diag_win[i][2][0]][diag_win[i][2][1]]
            && board[diag_win[i][0][0]][diag_win[i][0][1]] == 'O') return true;
    }
    return false;
}

bool X_O_Board::is_draw() {
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(board[i][j]==0 ) return false;
        }
    }
    return true;
}

bool X_O_Board::game_is_over () {
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(board[i][j]==0) return false;
        }
    }
    return true;
}
int X_O_Board::check_status() {
    if(is_winnerX()) return -2;
    else if(is_draw()) return 0;
    else if(is_winnerO()) return 2;
    else return 1;
}

int X_O_Board::minimax(int& x, int& y, bool isMaximizing, bool firstTime)
{
    int res = X_O_Board::check_status();
    if(res!=1) return res;

    int max = -10 , min = 10;
    int finalI , finalJ;
 
    for(int i=0 ; i<3 ; i++)
    {
        for(int j =0 ; j<3 ; j++)
        {
            if(board[i][j]==0)
            {
                if(isMaximizing) {
                    board[i][j] = 'O';
                    int sum = minimax(x, y, false, false);
                    board[i][j] = 0;
                    if (sum >= max) {
                        max = sum;
                        finalI = i;
                        finalJ = j;
                    }
                    if (firstTime)
                        cout << i << j << " : " << X_O_Board::check_status() << endl;
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
                        cout << i << j << " : " << X_O_Board::check_status() << endl;
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