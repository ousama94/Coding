#include <stdio.h>



int main()
{
  int turn;                                     /*turn variable used as the counter for the game*/
  int i, j;                                     /*i corresponds to the number of rows for the 2D array of the board, j corresponds to the columns */
  int player ;                                  /*the variable for the player selection */
  int x ;                                       /*the variable for the row the player chooses  */
  int y;                                        /*the variable for the column the player chooses*/
  int winner = 0;                               /*the variable used to determine who the winner*/
  char tictactoe[3][3] = {
                       {'1','2','3'},           /*the 2D array of the board, the values inside each member are just used as a reference for the user*/
                       {'4','5','6'},
                       {'7','8','9'}
                     };


   for(turn = 0; turn<9 && winner==0; turn++)   /*The for loop of the game, it loops 9 times while there is no winner */
   {

         for (i=0; i<3; i++)
	  {
		  for (j=0;j<3; j++)                    /*a for loop nested within the game's for loop in order to display the 3x3 board  */
		  {
		  printf(" %c |", tictactoe[i][j]);
		  }
		  printf("\n");
	  }

      player = turn%2 + 1;                     /*the code used to alternate between player 1 and player 2 each time the game loops*/
                                                /*the '%2' of any value will return a remainder of 0 or 1, the further addition of 1 produces values of 1 or 2*/

      do
      {
         printf("\nPlayer %d, please enter the Row followed by the Enter Key followed by the Column of the square "
       "where you want to place your %c: \n" "for 1:(0,0) 2:(0,1) 3:(0,2) 4:(1,0) 5:(1,1) 6:(1,2) 7:(2,0) 8:(2,1) 9:(2,2)\n", player,(player==1)?'X':'O');
         scanf("%i", &x);                             /*the user input of the vector where they want to place their X or O */
         scanf("%i", &y);


      }while(turn<0 || turn>9 || tictactoe[x][y]>'9');  /*the do-while loop of the square selection */

      tictactoe[x][y] = (player == 1) ? 'X' : 'O';   /* the vector chosen by the user will correspond in an X during player 1's turn, otherwise it's a O  */

                                                     /*if statement to check for diagnols*/
      if((tictactoe[0][0] == tictactoe[1][1] && tictactoe[0][0] == tictactoe[2][2]) ||
         (tictactoe[0][2] == tictactoe[1][1] && tictactoe[0][2] == tictactoe[2][0]))
        winner = player;

      else if                                        /*else-if statement to check for rows*/
	         ((tictactoe[0][0] == tictactoe[0][1] && tictactoe[0][0] == tictactoe[0][2])||
             (tictactoe[1][0] == tictactoe[1][1] && tictactoe[1][0] == tictactoe[1][2])||
			 (tictactoe[2][0] == tictactoe [2][1] && tictactoe [2][0] == tictactoe[2][2]))
		winner = player;

	  else if                                         /*else-if statement to check for columns*/
	         ((tictactoe[0][0] == tictactoe[1][0] && tictactoe[0][0] == tictactoe[2][0])||
             (tictactoe[0][1] == tictactoe[1][1] && tictactoe[0][1] == tictactoe[2][1])||
			 (tictactoe[0][2] == tictactoe [1][2] && tictactoe [0][2] == tictactoe[2][2]))



            winner = player;                           /*results in the player becoming the winner*/


   }

       for (i=0; i<3; i++)       /*Displays final board*/
	  {
		  for (j=0;j<3; j++)
		  {
		  printf(" %c ", tictactoe[i][j]);
		  }
		  printf("\n");
	  }



   if(winner == 0)           /*if the winner variable is still 0, then the match ends in a draw*/
      printf("\nThe match has ended in a draw\n");
   else
      printf("\nPlayer %d has won\n", winner);
    return 0;
}
