#include "BoardGame_Classes.hpp"
#include <vector>
AI_Player::AI_Player(char symbol, Board* board) : Player(symbol) , board(board) {
    this->name = "AI ";
    cout<<"My Name is "<<name<<endl;
}
void AI_Player::get_move(int &x, int &y) {
    board->minimax(x, y , true , true);
}