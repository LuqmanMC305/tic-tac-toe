#include <iostream>
#include <time.h>

using namespace std;

const int row=3, col=3;

//Function headers
void printBoard (char[row][col]);
void playerMove(char [row][col]);
void placeSymbol(char[row][col], int, char);
void computerMove(char[row][col]);
bool isValidMove(char [row][col], int);
bool isGameOver(char[row][col]);
bool hasConstestantWon(char[row][col], char);



int main(){	
	

   
   char board [row][col]={{ '1', '2', '3'},
                          { '4', '5', '6'},
                          { '7', '8', '9'}};
   
   // call printBoard function (show the numbers)
   printBoard(board);
   
  
  // Remove the numbers inside the board
  
  for (int i=0; i<row; i++){
  	for (int j=0; j<col; j++){
  		board[i][j]=' ';
	  }
  }  
 
  
  // Function call for player & computer inputs; print board
  
  while (true){
   playerMove(board);
   if (isGameOver(board)){
   	 break;
   }
   
   printBoard(board);
   cout << "\n\n";
   computerMove(board);
   
   if(isGameOver(board)){
   	break;
   }
   
   printBoard(board);
   cout << "\n";
   
 }
}


void printBoard (char board[row][col]){
	

   cout << board[0][0] << "    |   "	<< board[0][1] << "   |   "  << board[0][2] << endl;
   cout <<  "-----|-------|-------" << endl;
   cout << board[1][0] << "    |   "	<< board[1][1] << "   |   "  << board[1][2] << endl;
   cout <<  "-----|-------|-------" << endl; 	 	    
   cout << board[2][0] << "    |   "	<< board[2][1] << "   |   "  << board[2][2] << endl;
   	     	 	    

	
}

void playerMove(char board[row][col]){
  int playerInput;
  	
  while (true){
  	cout << "\nEnter where do you want to place: (1-9) " << endl;
    cin >> playerInput;
    if (isValidMove(board, playerInput)) {
       break;	
	}
	else {
		cout << "Your input is invalid. Try again. " << endl;
	}
    
   
   }
   
   placeSymbol(board, playerInput, 'X');	
}

void placeSymbol(char board[row][col], int userInput, char Symbol){
	
  
  switch (userInput){
  	 case 1:
  	  board[0][0]=Symbol;
  	  break;
  	 	
  	 case 2:
  	  board[0][1]=Symbol;
  	  break;
		   
	 case 3:
  	  board[0][2]=Symbol;
  	  break;	    	
  	 
	 case 4:
  	  board[1][0]=Symbol;
  	  break;
		
	 case 5:
  	  board[1][1]=Symbol;
  	  break;
		
	 case 6:
  	  board[1][2]=Symbol;
  	  break;
	
	 case 7:
  	  board[2][0]=Symbol;
  	  break;
		
	 case 8:
  	  board[2][1]=Symbol;
  	  break;
		
	 case 9:
  	  board[2][2]=Symbol;
  	  break;
		
	 default:
	  cout << "Your input is invalid. " << endl;
	  				   	
  }
  

	
}


bool isValidMove(char board [row][col], int position){
	
	switch (position){
  	 case 1:
  	  return (board[0][0] == ' ');
  	 	
  	 case 2:
  	  return (board[0][1] == ' ');
		   
	 case 3:
  	  return (board[0][2] == ' ');
  	  	    	
	 case 4:
  	  return (board[1][0] == ' ');
  	  
	 case 5:
  	  return (board[1][1] == ' ');
  	  
	 case 6:
  	  return (board[1][2] == ' ');
  	 
	 case 7:
  	  return (board[2][0] == ' ');
  	
	 case 8:
  	  return (board[2][1] == ' ');
		
	 case 9:
  	  return (board[2][2] == ' ');
		
	 default:
	  return false;
	  				   	
  }
  
	
	
}

void computerMove(char board[row][col]){
	
  srand(time(NULL));
  int computerPlay;
  
   while(true) {
    computerPlay = rand() % 10;
  	if (isValidMove(board, computerPlay)){ // The loop will be exited if the computer input is valid.
  		break;
	  }
  }
  
  placeSymbol(board, computerPlay, 'O');
	
}

bool isGameOver(char board[row][col]){
	
	// Check if there's a winner
	if (hasConstestantWon(board, 'X')){
		printBoard(board);
	    cout << "\nPlayer wins! " << endl;
	    return true;
	    	
	}
	
	if (hasConstestantWon(board, 'O')){
		printBoard(board);
	    cout << "\nComputer wins! " << endl;
	    return true;
	    	
	}
	
	// Check if there's an empty position, if all positions are full, end the game
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if(board[i][j]== ' '){
				return false;
			}
		}
	}
	printBoard(board);
	cout << "\nThe game ended. It's a tie! " << endl;
	return true;
	
}

bool hasConstestantWon(char board[row][col], char Symbol){
	
		if ((board[0][0]== Symbol && board[0][1]== Symbol && board[0][2]== Symbol) ||
	        (board[1][0]== Symbol && board[1][1]== Symbol && board[1][2]== Symbol) ||
	        (board[2][0]== Symbol && board[2][1]== Symbol && board[2][2]== Symbol) ||
		 
	        (board[0][0]== Symbol && board[1][0]== Symbol && board[2][0]== Symbol) ||
	        (board[0][1]== Symbol && board[1][1]== Symbol && board[2][1]== Symbol) ||
	        (board[0][2]== Symbol && board[1][2]== Symbol && board[2][2]== Symbol) ||
	    
	        (board[0][0]== Symbol && board[1][1]== Symbol&& board[2][2]== Symbol) ||
	        (board[0][2]== Symbol && board[1][1]== Symbol&& board[2][0]== Symbol) ) {
	    	
	      return true;
		}
	
	return false;
	
}


