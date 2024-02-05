
#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'X');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout<<"1 - XO GAME \n";
    cout<<"2 - PYRAMID XO GAME \n";
    int ch;cin>>ch;
    if(ch==1) {
        X_O_Board pX_O;

        cout << "Press 1 if you want to play with computer: \n";
        cout << "Press 2 if you want to play with your freind: \n";
        cout << "Press 3 if you want to play with AI model: \n";
        cin >> choice;
        if (choice == 1) { players[1] = new RandomPlayer('O', 3); }
        else if (choice == 2)
            players[1] = new Player(2, 'O');
        else if (choice == 3) {
            players[1] = new AI_Player('O', &pX_O);
        }
        GameManager x_o_game(&pX_O, players);
        x_o_game.run();
    }
    else if(ch==2)
    {
        pyramid_X_O_Board p2X_O;

        cout << "Press 1 if you want to play with computer: \n";
        cout << "Press 2 if you want to play with your freind: \n";
        cout << "Press 3 if you want to play with AI model: \n";
        cin >> choice;
        if (choice == 1) { players[1] = new RandomPlayer('O', 3); }
        else if (choice == 2)
            players[1] = new Player(2, 'O');
        else if (choice == 3) {
            players[1] = new AI_Player('O', &p2X_O);
        }
        GameManager x_o_game(&p2X_O, players);
        x_o_game.run();
    }
    system ("pause");
}
