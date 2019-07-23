# Coding
Completed Assignments

DEPARTMENT DATABASE PROJECT:

1) User input. The user is asked (using cout and cin) to “Enter the Imperial membership
type [student or staff]: ”. If the user enters ‘student’, then the program asks the user to “Enter
their name: ”, “Enter their age: ”, and “Enter their year: ”. If the user enters
‘staff’, then the program asks the user to “Enter their name: ”, “Enter their age: ”, and “Enter
their position: ”. These values are sotred into a database.

2) Database. Each entry is stored in a list called DeptList with nodes of different
classes. Each class (Student and Staff) is derived from a base class called
Member. Templates and virtual functions are used to implement this.
 
3) Display list. Every time a new entry is added to the database, the output is displayed to the screen. A 'member' function in Student and Staff classes were created to print this. This was necessary, because each class has a different number of member values that needed to be printed.
  
  
  
TIC_TAC_TOE:

Tic Tac Toe is a game for two players, X and O, who take turns marking spaces on a 3×3 grid. The
objective of the game is to win by placing three of their marks in a horizontal, vertical, or diagonal
row. If neither player succeeds in doing this and all spaces are taken, then the result is a tie. 
My program will prompt a specific player (X or O) to enter the row and column of the space that
they want to mark. The program will evaluate whether the move is valid. If it is valid, the space on
the board will be updated with a mark corresponding to the player’s symbol. If it is invalid, the
player will be asked to enter the row and column again. The program runs until Player X
wins, Player O wins, or when there’s a tie. A tie occurs when the board is full and neither player
has won. The program ends with the announcement of the game’s outcome. 
