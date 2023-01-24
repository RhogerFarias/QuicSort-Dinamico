#include <stdio.h>


void change(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int smaller, int bigger) {
  

  int pivo = array[bigger];  
  int i = (smaller - 1);
 
  for (int j = smaller; j < bigger; j++) {
    if (array[j] <= pivo) {
      i++;
      change(&array[i], &array[j]);
    }
  }
  change(&array[i + 1], &array[bigger]);
  return (i + 1);
}

void quickSort(int array[], int smaller, int bigger) {
  if (smaller < bigger) {
    int pi = partition(array, smaller, bigger);
    quickSort(array, smaller, pi - 1);
    quickSort(array, pi + 1, bigger);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Vetor desordenado:\n");
  printArray(data, n);
  
  quickSort(data, 0, n - 1);
  
  printf("Vetor ordenado: \n");
  printArray(data, n);
}
