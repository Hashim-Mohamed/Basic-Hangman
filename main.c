#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <string.h>

char fileLoc[500]; // The backup file location
void showLogo() {

      printf("--------------------------------------------\n");
      printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
      printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
      printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
      printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
      printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
      printf("--------------------------------------------\n\n");
}
void prn_galg(int i) {
 switch (i) {
     case 0 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("____________\n\n");
     break;
     case 1 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 2 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 3 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 4 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 5 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |    |\n");
      printf("  |    |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 6 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|\n");
      printf("  |    | \n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 7 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 8 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   /\n");
      printf("__|_________\n\n");
     break;
     case 9 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   / \\\n");
      printf("__|_________\n\n");
     break;
     case 10 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    X \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   / \\\n");
      printf("__|_________\n\n");
     break;
 }
}
char* getWord() {// Randomly chooses a word from hangword.txt
    char hangword[100];
    FILE * word;
    int n,o;// randomly chosen number for the list in text file
    srand(time(NULL));
    word = fopen("Hangword.txt","r");
    if (word == NULL){
        printf("Error: cannot find Hangword.txt ");
        exit(-1);
    }
    n = rand() % 213;// a random number is picked that will determine the word to guess
    //printf("%i!\n",n);// the random number chosen to pick a word
    while (n!=o){
        fscanf(word,"%i %s",&o, hangword);
        if(n==o){
            //printf("%s\n",hangword);//the word the console has chosen
        }
    }
    fclose(word);
    return (hangword);
}
int main(void) {
char udi[] = "EMPTY";
while ((strcmp(udi, "END") != 0) && ((strcmp(udi, "AGAIN") == 0) || (strcmp(udi, "EMPTY") == 0))) {
 strcpy(udi, "EMPTY");
 /* Declaring variables */
 /* Random deciding which word is chosen to be guessed:
 guessWord is the word that needs to be guessed
 currentWord is the word that is filled with dots */
 /* Retrieving the word that matches with the wordNumber */
 /* Check which number was chosen: printf("%d", wordNumber); */
 char *tempWord = getWord();
 /* Declaring the guessWord with the length of dkljafoue */
 char guessWord[strlen(tempWord)+1];
 /* Copying the string of dkljafoue into guessWord */
 strcpy(guessWord, tempWord);
 /* Freeing the pointer */
 free(tempWord);
 /* Calculate the length of the guessWord */
 int wordlength = strlen(guessWord);
 /* Creating the dotword (name: currentWord) */
 char* currentWord = malloc( wordlength );
 int t,x;
 for (t = 0; t <= wordlength; t++) {
  if (t == wordlength) {
      currentWord[t] = '\0';
  } else {
      currentWord[t] =  '.';
  }
 }
 /* Currentword check: printf("Currentword: \"%s\"", currentWord); */
 /* Declaring variables */
 int errors = 0; /* Error amount, if its higher than 10 the loop stops */
 int guessedLetter = 0; /* Boolean Integer used to check wether the player entered a correct letter 0 = false, 1 = true */
 int i,n = 1;
 char c, in[10];
 /* Printing logo */
 showLogo();
 /* Printing introduction message */
 printf("%s\n\n%s\n%s\n%s\n%s\n\n%s%s\n\n",
 "Welcome to the game Hangman!",
 "The objective in this game is to guess the word.",
 "You can enter both uppercase and lowercase letters.",
 "If you think you know the word, you can type it in.",
 "You will loose if you have guessed 10 letters wrong.",
 "This is the word you need to guess: ",
 currentWord);
 printf("%d.     %s", n, "Enter the letter(s) you want to guess: ");
 /* As long as the word hasn't been guessed or the errors are lower than 10: */
 while( (strcmp(currentWord, guessWord) != 0) && (errors < 10) ){
 scanf("%c", &c); /* Retrieving the user entry */
 c = tolower(c); /* Removing caps */
 if (c != '\n') {
 if (isalpha(c)) { /* Making sure that the letter is alphanumeric */
 /* Checking wether the letter that has been entered (c) occurs in the guessWord */
 for (i = 0; i < wordlength; i++) {
  if (guessWord[i] == c) {
   currentWord[i] = c;
   guessedLetter = 1;
  }
 }
 /* Actions taken if the letter c doesn't occur in the guessWord and when it does */
 if (guessedLetter == 0) {
  errors++;
  printf("\nThat letter was incorrect.\n\n");
 } else {
 guessedLetter = 0;
  printf("\nThat letter was correct.\n\n");
 }
 /* Showing the galg and the amount of errors */
 //printf("You have guessed these letters incorrectly: %s\n",wronganswer);
 printf("%s%s\n\n", "The word including the letters you guessed: ", currentWord);
 prn_galg(errors);
 n++; /* Increasing attempt amount */
 /* Showing header if the word has not been guessed and the errors are lower than 10 */
 if ( (strcmp(currentWord, guessWord) != 0) && (errors < 10) ) {
  printf("%d.     %s", n, "Enter the letter(s) you want to guess: ");
 }
 /* If the letter isn't alphanumeric (isalpha()) */
 } else {
  printf("Only alphanumeric symbols are allowed (a-z, A-Z), try again:\n");
 }
 }
 }
 /* Showing the results, wether the player won or not  */
 printf("---------------\n");
 printf("--- Results ---\n");
 printf("---------------\n\n");
 if (errors < 10) {
  if (strcmp(currentWord, guessWord) == 0) {
      printf("Congratulations you have guessed the right word!\n\n");
  } else {
      printf("You have guessed the wrong word, better luck next time!\n\n");
  }
 } else {
     printf("You have guessed the wrong word, better luck next time!\n\n");
 }
 printf("\nLetters guessed wrong: %d\nThe word that needed to be guessed: %s\nThe word you guessed: %s\n", errors, guessWord, currentWord);
 printf("\nEnter 'end' to end the game or enter 'again' to guess another word:\n");
 // Making sure that the user doesn't enter strange things
 while ((strcmp(udi, "END") != 0) && (strcmp(udi, "AGAIN") != 0)) {
  if (strcmp(udi, "EMPTY") != 0) {
      printf("\n\nIt is not allowed to enter anything else than 'again' or 'end', try again:\n");
  }
  // Retrieving the udi (udi = user determined input)
  scanf("%s", udi);
  // Converting the udi to uppercase
  int x;
  for (x = 0; x < 5; x++) {
      udi[x] = toupper(udi[x]);
  }
 }
 printf("\n\n--------------------------------------------\n\n");
}
return 0;
}
