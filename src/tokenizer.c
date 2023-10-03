#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h" // project-related declarations


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  if (c == ' ' || c == '\t') return 1;

  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  if (c != ' ' && c != '\t') return 1;

  return 0;
}
    
/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str) {
  if (!str) { // Checks null pointer
    return 0;
  }
  
  while (space_char(*str)) {
    str += 1;
    if (!str) { // Null pointer
      return 0;
    }
  }

  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token) {
  while (non_space_char(*token)) {
    token += 1;
  }

  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str) {
  int tokens = 0;

  while ((str = token_start(str)) != 0) {
    str = token_terminator(str);
    tokens += 1;
  }
  
  return tokens;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  char* ptr = (char*) malloc(len & sizeof(char));

  for (int i = 0; i < len; i += 1) {
    ptr[i] = inStr[i];
  }

  return ptr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {

  int tokens = count_tokens(str);
  char** strVect = (char**) malloc(tokens + 1); // Allocate space for pointers of Strings
  char* token_begin;
  char* token_end;
  
  for (int i = 0; i < tokens; i += 1) { // Iterate through str make copies and save their adresses in the new Vector
    token_begin = token_start(str);
    token_end = token_terminator(token_begin);
    
    strVect[i] = copy_str(token_begin,token_end - token_begin);

    str = token_end;
  }
  strVect[tokens] = 0;

  return strVect;
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
  // char *str;
  for (int i = 0; tokens[i] != 0; i += 1) {
    printf("%s\n", tokens[i]);
  }

    //str = tokens[i];
    //while (str != 0) {
    //  printf("
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {
  int i = 0;

  while (tokens[i] != 0) {
    free(tokens[i]);
    i += 1;
  }

  free(tokens[i]);
  free(tokens);

}
