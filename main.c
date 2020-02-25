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
  struct matrix * part = new_matrix(4,4);
  int r,c;
  for (r = 0; r < 4; r++){
    for (c = 0; c < 4; c++){
      edges->m[r][c] = r + c;
    }
  }
  for (r = 0; r < 4; r++){
    for (c = 0; c < 4; c++){
      part->m[r][c] = r;
    }
  }
  print_matrix(edges);
  printf("------------------------------------------------\n\n\n");
  print_matrix(part);
  printf("------------------------------------------------\n\n\n");
  identity = new_matrix(4,4);
  ident(identity);
  print_matrix(identity);
  matrix_mult(part,edges);
  printf("------------------------------------------------\n\n\n");
  print_matrix(edges);
  free_matrix( edges );
  free_matrix(part);
  free_matrix(identity);
}
