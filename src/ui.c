#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  puts("Welcome!");

  List* hist = init_history();
  char** tokens;
  char strIn[100];
  char c;
  
  while (1) {

    fputs("Enter a string to be tokenized or use !command to recall history : \n", stdout);
    fputs("$ ", stdout);

    fgets(strIn, 100, stdin);
    fflush(stdout);

    if (strIn[0] == '!' && strIn[1] != '\t' && strIn[1] != '\0') {
      tokens = tokenize(get_history(hist, strIn[1]));
    }
    else {
      puts("TEST$");
      tokens = tokenize(strIn);
      add_history(hist, strIn);
    }
    
    fputs("The tokens read are: \n", stdout);
    print_tokens(tokens);

    puts("Do you want to view history? (y/n) or exit with 'e' : \n$ ");
    c = getchar();
    switch (c) {
      
    case 'y':
    print_history(hist);
    break;

    case 'e':
    goto done;
    break;

    default:
    break;
    }
    
  }

  done: // exit
    return 0;

}


    
