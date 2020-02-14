#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *identity;
  edges = new_matrix(4, 4);
  print_matrix(edges);
  free_matrix( edges );
  printf("------------------------------------------------\n\n\n");
  identity = new_matrix(5,5);
  ident(identity);
  print_matrix(identity);
}
