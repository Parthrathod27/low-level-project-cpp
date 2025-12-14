#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <limits>
using namespace std;

string matrix[3][3] = {
    {"1","2","3"},
    {"4","5","6"},
    {"7","8","9"}
};

void loading(string text) {
    cout << "\n" << text;
    for(int i = 0; i < 3; i++){
        cout << ".";
        cout.flush();
        sleep(1);
    }
    cout << "\n";
}

void clear() {
    cout << "\033[2J\033[1;1H";
}

void header(){
    cout << setw(45) << "==== WELCOME ====\n";
    cout << setw(47) << ">>>> TIC TAC TOE <<<<\n\n";
}

void displayGame(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << " " << matrix[i][j] << " ";
            if(j<2) cout << "|";
        }
        if(i<2) cout << "\n-----------\n";
    }
    cout << "\n";
}

bool checkWin(string s){
    for(int i=0;i<3;i++){
        if(matrix[i][0]==s && matrix[i][1]==s && matrix[i][2]==s) return true;
        if(matrix[0][i]==s && matrix[1][i]==s && matrix[2][i]==s) return true;
    }
    if(matrix[0][0]==s && matrix[1][1]==s && matrix[2][2]==s) return true;
    if(matrix[0][2]==s && matrix[1][1]==s && matrix[2][0]==s) return true;

    return false;
}

bool placeMove(int pos, string symbol){
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if(matrix[row][col] == "X" || matrix[row][col] == "O"){
        cout << "POSITION ALREADY OCCUPIED! TRY AGAIN\n";
        return false;
    }

    matrix[row][col] = symbol;
    return true;
}

int main(){
    clear();
    header();

    int start;
    cout << "DO YOU WANT TO PLAY A GAME?\n";
    cout << "( PRESS 0 for YES & 1 for NO ): ";
    cin >> start;

    if(start == 1){
        cout << setw(48) << "THANK YOU! VISIT AGAIN :)\n";
        return 0;
    }

    loading("STARTING GAME");
    clear();
    header();

    cout << "RULES:\n";
    cout << "- Player 1 = X\n";
    cout << "- Player 2 = O\n";
    cout << "- Choose positions from 1 to 9\n";
    cout << "- First player to align wins\n\n";

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();

    clear();
    header();
    displayGame();

    int moveCount = 0;

    while(true){
        int pos;
        string symbol = (moveCount % 2 == 0) ? "X" : "O";
        string player = (symbol == "X") ? "Player 1" : "Player 2";

        cout << player << " choose position: ";
        cin >> pos;

        // non-integer input
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID INPUT! ENTER A NUMBER\n";
            continue;
        }

        // range check
        if(pos < 1 || pos > 9){
            cout << "INVALID NUMBER! RANGE IS 1–9\n";
            continue;
        }

        // place move
        if(!placeMove(pos, symbol)){
            continue;
        }

        moveCount++;
        clear();
        header();
        displayGame();

        // win check
        if(checkWin(symbol)){
            cout << player << " WINS THE GAME! 🎉\n";
            break;
        }

        // draw check
     
