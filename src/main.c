#include "functions.h"
#include "tomato.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *tomatoFile = "tomato.csv";
char *statsFile = "";

int main() {
  FILE *fd = NULL;
  FILE *fd2 = NULL;

  fd = fopen(tomatoFile, "r");
  fd2 = fopen(statsFile, "a");
  int m = 0;
  if (fd == NULL) {
    fd = fopen(tomatoFile, "a");
    int n = ask_Data(fd);
    while (n == 0) {
      printf("\nUps... Parece que algo ha salido mal.\n");
      n = ask_Data(fd);
    }
  }

  int resp;
  time_t tiempo = time(0);
  struct tm *tlocal = localtime(&tiempo);
  char output[128];
  strftime(output, 128, "%d/%m/%y %H:%M:%S", tlocal);
  printf("%s\n", output);
  printf("did you go to class today? (0 == yes, 1 == no)");
  scanf("%d", &resp);
  return resp;
  while (m != 3) {
    printf("1. Ver estadisticas.\n2. Usar Cronometro\n3.Salir\n");
    scanf("%d", m);
    if (m == 1) {
      printf("Asistencia a clase(hoy): %d %\nAsistencia a clase(general):%d "
             "%\nEstudio(hoy): %d %\nEstudio (General): %d %",
             50, 50, 50, 50);
    } else if (m == 2) {
      Krono(fd2);
    }
  }

  fclose(tomatoFile);
}

void Krono(FILE *file) {
  int i;
  int tiempo;
  file = fopen(statsFile, "w");
  printf("Introduce un tiempo en segundos: ");
  scanf("%d", &tiempo);
  fprintf(file, "%d\n", tiempo);
  for (i = 0; i < tiempo; i++) {
    delay(1 * 1000);
    printf("%d \n", i + 1);
  }
}
