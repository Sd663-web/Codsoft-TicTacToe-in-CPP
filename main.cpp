#include<iostream>
#include<string>
#include<cctype>
using namespace std;

class TicTacToe{
    private:
        char board[3][3];
        string p1, p2;
        char m1, m2;
        int currPlayer;

    public:
        TicTacToe(){
            char c = '1';
            for(int i = 0;i<3; i++){
                for(int j = 0; j<3; j++){
                    board[i][j] = c++;
                }
            }
            currPlayer = 1;
        }

        void setPlayer(){
            cout<<"Enter player1: ";
            getline(cin, p1);
            cout<<"Enter player2: ";
            getline(cin, p2);

            do{
                cout<<p1<< "select X or O: ";
                cin>> m1;
                m1 = toupper(m1);

            }
            while(m1 != 'X' && m1 != 'O');

            m2 = (m1 == 'X') ? 'O' : 'X';
            cin.ignore();
        }

        void draw(){
            cout<<"\n";
            for(int i =0; i<3; i++){
                cout<<" ";
                for(int j=0; j<3; j++){
                    cout<<board[i][j];
                    if(j<2) cout<<" | ";
                }

                cout<<"\n";
                if(i<2) cout<<"---|---|---\n";
            }
            cout<<"\n";
        }


        bool placeMarker(int slot) {
            int row = (slot - 1) / 3;
            int col = (slot - 1) % 3;

            if(board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = (currPlayer == 1) ? m1 : m2;
                return true;
            }
            return false;
        }

        bool checkWinner() {
            for(int i = 0; i < 3; i++) {
                if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
                    return true;
                if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
                    return true;
            }

            if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
                return true;

            if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
                return true;

            return false;
        }

        void switchPlayer(){
            currPlayer = (currPlayer==1) ? 2 : 1;
        }

        void game(){
            int moves = 0;
            draw();

            while(moves < 9){
                string name = (currPlayer == 1) ? p1 : p2;
                cout<<name << " Enter your slot(1-9): ";
                int slot;
                cin>>slot;

                if(slot<1 || slot>9 || !placeMarker(slot)){
                    cout<<"Invalid Moves! Try again.\n";
                    continue;
                }

                draw();
                moves++;

                if(checkWinner()){
                    cout<<name << " wins the game!"<<endl;
                    return;
                }

                switchPlayer();
            }
            cout<<"It's Tie!"<<endl;
        }

};

int main(){
    char choice;
    do{
        TicTacToe game;
        game.setPlayer();
        game.game();

        cout<<"\nDo you want to play again? (y/n): ";
        cin>>choice;
        cin.ignore();
    }
    while(choice == 'y' || choice == 'Y');

    cout<<"Thanks for playing!"<<endl;

    return 0;
}