#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Team {
     public:
          Team() : current(0) {}
          vector<string> names;	
          int current;		
          string &currentPlayer(){
    	          return names[current]; 
          }
          void nextPlayer();
};






class TicTacToe{
     private:
          char Board[4][4];
          unsigned curTeam;
          Team teams[2];
     public:
          char mark();
          TicTacToe();
          void Game();
          void switchPlayer();
          void showBoard();
          void move(int, int, int);
          int conclusion();
};




void Team::nextPlayer(){ 
     current = (current+1) % names.size(); 
}



void TicTacToe::Game(){
     const int maxMoves = 16;
     int row = 0;
     int clmn = 0;
     int winner;
     int numberOfMoves = 0;	
     do {
	     switchPlayer();
	     showBoard();
	     cout << "\n\n" << mark() << " Team Member " << teams[curTeam].currentPlayer() << ". Enter your row: ";
	     cin >> row;
	     cout << "enter your column: ";
	     cin >> clmn;
	     move(row, clmn, teams[curTeam].current);
	     winner = conclusion();
	     numberOfMoves++;
     }
    while ((winner == 1) && (numberOfMoves < maxMoves));
    showBoard();

    if (winner != 1)
    	cout << "\n\nTeam " << mark()<<" won."<<endl;
    else
	cout << "\n\nThe game ended in a draw .";
}



char TicTacToe::mark(){
	if(curTeam){
		return 'O';
	}
	else{
		return 'X';
	}
}



TicTacToe::TicTacToe(){
     for (int row = 0; row < 4; row++) {
	     for (int col = 0; col < 4; col++) {
	          Board[row][col] = ' ';
	     }
     }
    
    
     string name;
     char symbol[] = {'X','O'};
     for (int i = 0; i<2; ++i) {
	     while (true) {
	          cout << teams[i].names.size()+1 <<".player of Team " << symbol[i] <<". Enter your name: ";
	          getline(cin, name);
	          if (name.size() == 0) break;
	          teams[i].names.push_back(name);
	          if (teams[i].names.size() == 2) break;
	     }
	     teams[i].current = teams[i].names.size()-1;
     }
     curTeam = 1;
}





void TicTacToe::switchPlayer(){
     curTeam = !curTeam;   
     teams[curTeam].nextPlayer();
}




void TicTacToe::showBoard(){
     for (int row = 0; row < 4; row++) {
	     for (int col = 0; col < 4; col++) {
	          cout << "[" << Board[row][col] << "]";
	}
	cout << endl;
     }

}




void TicTacToe::move(int row, int col,int kisi){
     char gelen = mark();
	if(kisi == 0){
	     Board[row - 1][col - 1] = gelen;    	
	}
	else{
		Board[row -1][col - 1] = tolower(gelen);
	}

}




int TicTacToe::conclusion(){
     int winner = 1;	
     for (int i = 0; i < 4; i++) {
	     if (toupper(Board[i][0]) == toupper(Board[i][1]) && toupper(Board[i][1]) == toupper(Board[i][2]) && toupper(Board[i][2]) == toupper(Board[i][3]) && Board[i][0] != ' ') {
	          return Board[i][0];
	     }
    }


     for (int i = 0; i < 4; i++) {
	     if (toupper(Board[0][i]) == toupper(Board[1][i]) && toupper(Board[1][i]) == toupper(Board[2][i]) && toupper(Board[2][i]) == toupper(Board[3][i]) && Board[0][i] != ' ') {
	          return Board[0][i];
	     }
     }


     if (toupper(Board[0][0]) == toupper(Board[1][1]) && toupper(Board[1][1]) == toupper(Board[2][2]) && toupper(Board[2][2]) == toupper(Board[3][3]) && Board[0][0] != ' ') {
	     return Board[0][0];
     }

     if (toupper(Board[3][0]) == toupper(Board[2][1]) && toupper(Board[2][1]) == toupper(Board[1][2]) && toupper(Board[1][2]) == toupper(Board[0][3]) && Board[3][0] != ' ') {
	     return Board[3][0];
     }
     return winner;
}





int main(){
     cout<<"\t\t\t\t TICTACTOE \n\n\n";
     TicTacToe play;
     play.Game();
     return 0;
}
