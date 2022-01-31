#include <stdio.h>
#include <stdlib.h>

/* Implementa o movimento flip no vetor */
void Flip (long int pos, long int n, long int *array) {
  if (pos  == n - 1) 
    return;

  for (int i = 0; i < (n - pos) / 2; i++) {
    long int tmp = array[pos + i];
    array[pos + i] = array[n - 1 - i];
    array[n -1 - i] = tmp;
  }

  printf("%ld ", pos);
}

/* procura o maior elemento no vetor de "pos" em diante*/
long int Search (long int pos, long int n, long int *array) {
  int high = pos;
  for (int i = pos + 1; i < n; i++) 
    if (array[high] < array[i])
      high = i;

  return high;
}

/*detalhes do sort no relatorio */
void Sort (long int n, long int *array) {
  long int aux;
  for (int i = 0; i < n; i++) 
    if ((aux = Search (i, n, array)) != i) {
      Flip (aux, n, array);
      Flip (i, n, array);
    }
}

int main () {
  long int n, *array;
  
  //read input
  scanf ("%ld", &n);
  array = malloc (n * sizeof (long int));
  for (int i = 0; i < n; i ++)
    scanf ("%ld", &array[i]);

  //output
  Sort (n, array);
  printf("\n");

  free (array);
  return 0;
}
