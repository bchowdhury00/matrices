/*==========================================
  A matrix will be a 4xN array of doubles
  Each column will represent an [x, y, z, 1] point.
  For multiplication purposes, consider the rows like so:
  x0  x1      xn
  y0  y1      yn
  z0  z1  ... zn
  1  1        1
  ==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"


/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m

print the matrix such that it looks like
the template in the top comment
*/
void print_matrix(struct matrix *m) {
  int r;
  int c;
  for(r=0; r < m->rows; r++){
    for (c=0; c < m->cols; c++){
      printf("%lf  ",(m->m)[r][c]);
    }
    printf("\n");
  }
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix

turns m in to an identity matrix
*/
void ident(struct matrix *m) {
  int r;
  int c;
  for(r=0; r < m->rows; r++){
    for (c=0; c < m->cols; c++){
      if (r == c){
        m->m[r][c] = 1.0;
      }
    }
  }
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b

multiply a by b, modifying b to be the product
a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
  int c;
  for (c = 0; c < b->cols; c++){
    double x = a->m[0][0] * b->m[0][c] + a->m[0][1] * b->m[1][c]+ a->m[0][2] * b->m[2][c]+ a->m[0][3] * b->m[3][c];
    double y = a->m[1][0] * b->m[0][c] + a->m[1][1] * b->m[1][c]+ a->m[1][2] * b->m[2][c]+ a->m[1][3] * b->m[3][c];
    double z = a->m[2][0] * b->m[0][c] + a->m[2][1] * b->m[1][c]+ a->m[2][2] * b->m[2][c]+ a->m[2][3] * b->m[3][c];
    double m = a->m[3][0] * b->m[0][c] + a->m[3][1] * b->m[1][c]+ a->m[3][2] * b->m[2][c]+ a->m[3][3] * b->m[3][c];
    b->m[0][c] = x;
    b->m[1][c] = y;
    b->m[2][c] = z;
    b->m[3][c] = m;
  }
}
/*===============================================
  These Functions do not need to be modified
  ===============================================*/

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols

Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)...
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
      tmp[i]=(double *)malloc(cols * sizeof(double));
    }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m
Returns:

1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {
  int i;
  for (i=0;i<m->rows;i++) {
      free(m->m[i]);
    }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols
Returns:

Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {

  int i;
  for (i=0;i<m->rows;i++) {
      m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b
Returns:

copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

  for (r=0; r < a->rows; r++)
    for (c=0; c < a->cols; c++)
      b->m[r][c] = a->m[r][c];
}
