#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/* ===================== BOARD CLASS ===================== */
class Board {
private:
    string grid[3][3];

public:
    Board() {
        int num = 1;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                grid[i][j] = to_string(num++);
    }

    void display() {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout << " " << grid[i][j] << " ";
                if(j<2) cout << "|";
            }
            if(i<2) cout << "\n-----------\n";
        }
        cout << "\n";
    }

    bool placeMove(int pos, string symbol) {
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if(grid[row][col] == "X" || grid[row][col] == "O")
            return false;

        grid[row][col] = symbol;
        return true;
    }

    bool checkWin(string s) {
        for(int i=0;i<3;i++){
            if(grid[i][0]==s && grid[i][1]==s && grid[i][2]==s) return true;
            if(grid[0][i]==s && grid[1][i]==s && grid[2][i]==s) return true;
        }
        if(grid[0][0]==s && grid[1][1]==s && grid[2][2]==s) return true;
        if(grid[0][2]==s && grid[1][1]==s && grid[2][0]==s) return true;

        return false;
    }
};

/* ===================== PLAYER CLASS ===================== */
class Player {
private:
    string name;
    string symbol;

public:
    Player(string n, string s) {
        name = n;
        symbol = s;
    }

    string getName() { return name; }
    string getSymbol() { return symbol; }
};

/* ===================== GAME CLASS ===================== */
class Game {
private:
    Board board;
    Player p1;
    Player p2;
    int moveCount;

public:
    Game() : p1("Player 1", "X"), p2("Player 2", "O") {
        moveCount = 0;
    }

    void start() {
        cout << "\n===== TIC TAC TOE GAME =====\n\n";

        while(true) {
            board.display();

            Player current = (moveCount % 2 == 0) ? p1 : p2;
            int pos;

            cout << current.getName() << " (" << current.getSymbol()
                 << ") choose position: ";
            cin >> pos;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT! ENTER A NUMBER\n\n";
                continue;
            }

            if(pos < 1 || pos > 9) {
                cout << "INVALID POSITION! (1–9 only)\n\n";
                continue;
            }

            if(!board.placeMove(pos, current.getSymbol())) {
                cout << "POSITION ALREADY OCCUPIED!\n\n";
                continue;
            }

            moveCount++;

            if(board.checkWin(current.getSymbol())) {
                board.display();
                cout << current.getName() << " WINS! 🎉\n";
                break;
            }

            if(moveCount == 9) {
                board.display();
                cout << "GAME DRAW 🤝\n";
                break;
            }
        }
    }
};

/* ===================== MAIN ===================== */
int main() {
    Game game;
    game.start();
    return 0;
}

