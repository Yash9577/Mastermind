/*This program is a simple version of Mastermind Game.
The computer generates four different digits between 1-9 and the user has to guess those numbers within 10 attempts.
After every attempt an output is provided to user in which number of correct digits at their right location are displayed.
If user guesses all digits correct the user wins the game.*/

#include<stdio.h> //This is standard input and output library
#include<stdlib.h> // This is standard library in c
#include<time.h> //This library introduce date and time fuctions

int a[4];
int found(int f[] , int size);      //declaration of function
int main (void) // Main function

{
    
  int j,k,l,m;
  // This variables store users guess  
  int t=1;
  //t = count and this variable is used to create a limit at which do-while loop will terminate
  int i = 0;
  //start of do while loop
  int e,f = -1;
  int counter;
    //counter is used to reduce the number of chances by 1 each time user guesses wrong number
do{
    
    printf("***************\n"); //This is the Welcome message    
    printf ("   Welcome to MasterMind - The Mind Game\n");
    //printf("You will have 100 chances to guess the number\n");
    printf("\t\tBest of luck\n");
    printf("***************\n");
 
 //if i is one it will again ask for number of chances
  if(i == 1)
  {
      printf("Enter the number of guesses you want(between 1 and 100) : ");
      scanf("%d",&f);
      //asks for the number of chances from user
  }
  //loop to check whether the guess is between the given limit 
  while(f > 101  || f < 0)
  {
      printf("Enter the number of guesses you want(between 1 and 100) : ");
      scanf("%d",&f);
      counter = f; 
      if(f<=0 || f>100)
      {
           printf("Enter a valid number\n");
           printf("Enter the number of guesses you want(between 1 and 100) : ");
           scanf("%d",&f);
      }
  }
    
  
      printf("You will have %d chances to guess the number\n",f);
    
     found(a,4);     //calling function
     
    // start of do-while loop
    do {
        
    
            int cnp = 0; //Number of correct digits and place and intilized to zero (cnp = correct number and place)
            int cn = 0; //Number of correct digits and intilized to zero (cn = correct number)


        printf ("You have %d remaing chances\n",f); // This counts the number of remaining chances
        printf ("Guess 4 numbers\n"); // This printf takes input from the user
        scanf ("%1d%1d%1d%1d",&j,&k,&l,&m);

       cnp = 0;cn = 0;
    /*The below if else statements are used to compare input variables
    with the randomly generated number 'a[1]','a[2]','a[3]' and 'a[4]'*/
         if(a[1] == j)
         cnp++;
         else
         {if(a[1] == k||a[1] == l||a[1] == m)
         cn++;}
           if(a[2] == k)
         cnp++;
         else
         {if(a[2] == j||a[2] == l||a[2] == m)
         cn++;}
         if(a[3] == l)
         cnp++;
         else
         {if(a[3] == j||a[3] == k||a[3] == m)
         cn++;} 
         if(a[4] == m)
         cnp++;
         else
         {if(a[4] == j||a[4] == k||a[4] == l)
         cn++;}
            
          f--; // Counter is decremented ecah time loop runs
          t++; // Attempts took is incremented each time loop runs 
          
          printf ("Correct number and place=%d\tCorrect number=%d\n",cnp, cn);
          
        /* This below if else condition checks whether the gussed number is correct 
           to the randomly genreated number or not*/
           
        if (j == a[1] && k == a[2] && l == a[3] && m == a[4])
	        {
	            printf ("Congratulations!!! You won the game\n"); //This printf shows the winning message
	            printf("\n");
	            break;
	        }
	        
	        
            if (f == 0)
	        {
	            printf ("You lose. Better luck next time. The corrct number was %d%d%d%d\n",a[1],a[2],a[3],a[4]);
	        }
            // This if statment is executed if attempts are more than 100 

    }
  while (f!=0);
  /* conditions inside the do while loop will continue untill the 
  condition inside the while loop is TRUE*/
  //end of do while loop
  
        printf("Press 1 to play again and 0 to exit\n"); //This printf checks whether the user wants to play to game again or not
        scanf("%d",&i);
        
}while(i==1);
//end of do-while loop(if user enters 1 than it starts again from beginning and if user enters 0 it exits from the loop )

printf("Goodbye!!!Hope you have a nice day"); // This printf shows a goodbye message to the user
return 0;
}
int found(int a[],int size) //This function generates rondom digits using arrays
{
    int x,e; // declaration of variables
    
    srand (time (0));
    for (x = 0;x<size;x++) //generating four random digits using array
        {
            a[x] = (rand() % ( 7 - 1 ) ) + 1;

        }
        printf("Do you want to change the randomly generated no. Press 1 for yes and 0 for no : ");
        scanf("%d",&e);          //This printf function asks whether to change the randomly generated number or not
        
        if(e==1)
        {
        if(a[1] == a[2] || a[1] == a[3] || a[1] == a[4])
            { a[1] = (rand() % (7 - 1)) + 1;}
        if(a[2] == a[1] || a[2] == a[3] || a[2] == a[4])  
            { a[2] = (rand() % (7 - 1)) + 1;}
        if(a[3] == a[1] || a[3] == a[2] || a[3] == a[4])
            { a[3] = (rand() % (7 - 1)) + 1;}
        if(a[4] == a[1] || a[4] == a[2] || a[4] == a[3])
            { a[4] = (rand() % (7 - 1)) + 1;}
        printf("The number is changed. All the best\n");
    }
    else
    {
        printf("All the best\n");
    }
    
    /*This if statements are used so that the value of random number generated is changed and not equal
    to any other values of random number generated before*/

}