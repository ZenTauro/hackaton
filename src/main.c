#include <stdio.h>
#include "functions.h"
#include "tomato.h"

// Driver code to test above function
int main() {
  int i;
  int tiempo;

  printf("Introduce un tiempo en seconds: ");
  scanf("%d", &tiempo);

  for (i = 0; i < tiempo; i++) {
    delay(1 * 1000);
    printf("%d sec have passed\n", i + 1);
  }

  return 0;
}
