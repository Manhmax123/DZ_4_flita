#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

void CountingSort(int * a, char * x, int n);
int main() {
  int n, i = 0, j = 0;                                
  int dem = 0, m[100][100]; 
  char * x, s;
  FILE *matr = fopen("D:\\Downloads\\graphs\\outputs\\adjacency_matrix_16.txt", "r");
  while(!feof(matr)){
    fscanf(matr, "%c", &s);
    if (s != '\n') {
      if (s != ' ' && s != '\t'){
          m[i][j] = s - '0';
          j++;
      }
    } else {
           j = 0;
           i++;
    }
 }
 
  n = i - 1;
  a = (int * ) calloc(n, sizeof(int));
  x = (char * ) calloc(n, sizeof(char));
  printf("\n");
  printf("\nEnter the names of the vertices: ");
  for (i = 0; i < n; i++)
  {
    printf("\nx[%d]= ", i + 1);
    scanf("%s", &x[i]);
  }
  printf("\n");
  
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) 
    {
      dem = dem + m[i][j];
    }
    a[i] = dem;
    dem = 0;
  }
/* for ( i = 0; i < n; i++) 
     printf("%d\n",a[i]);
*/
  printf("The vertices of the graph with odd degrees are arranged in descending order: \n");
  CountingSort(a, x, n);
  fclose(matr);
  free(a);
  free(x);
  return 0;
}

void CountingSort (int * Array, char *x, int len) {
    int * out = (int *) calloc(len, sizeof(int));
    int max = Array[0], min = Array[0];
    int i, * count_array, k; 
    for ( i = 1; i < len; i++) {
        if ( Array[i] > max) 
           max = Array[i];
        else if (Array[i] < min)
           min = Array[i];
    }
    k = max - min + 1;
    count_array = (int *) calloc(k, sizeof(int));
    
    for(i = 0; i < len; i++)
       count_array[Array[i] - min]++;
    for(i = 1; i < k; i++)
       count_array[i] += count_array[i - 1];
    for(i = 0; i < len; i++){
       out[count_array[Array[i]-min]-1] = Array[i];
        count_array[Array[i]- min]--;
    }
    for(i = len - 1; i >=0; i--) {
      if ((out[i] % 2 ) == 1) {
        for(k = 0; k < len; k++){
          if(out[i] == Array[k]){
            printf("%c\n", x[k]);
            Array[k] = '0';
          }
        }
      }
    }
} 
