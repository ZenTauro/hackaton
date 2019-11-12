#include <event2/event.h>
#include <functions.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tomato.h>

void delay(int msec) {
  // Converting time into milli_seconds
  int milli_seconds = 1000 * msec;

  // Stroing start time
  clock_t start_time = clock();

  // looping till required time is not acheived
  while (clock() < start_time + milli_seconds);
}

int ask_Data(FILE* tomato_file) {
  uint n_subjects=0, i=0;
  schedule_t thy_schedule;

  printf("How many subjects do you have: ");
  scanf("%d", &n_subjects);

  thy_schedule.subjects = calloc(n_subjects, sizeof(subject_t));

  if (thy_schedule.subjects == NULL) {
    fprintf(stderr, "Something went wrong\n");
    exit(1);
  }

  while(i < n_subjects) {
    ask_subject(thy_schedule.subjects + i);
    i++;
  }

  fprintf(tomato_file, "%s", );

  return 0;
}


void ask_subject(subject_t *subject) {
  uint temp=0;

  subject->name = calloc(100, sizeof(char));

  printf("Subject name: ");
  scanf("%s", subject->name);
  subject->name[99] = 0;

  for (uint u=0; u<2; u++){
    printf("Slot %d: ", u);
    printf("1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday\n");
    printf("Subject day: ");
    scanf("%d", &temp);
    subject->slots[u].day = temp - 1;

    printf("\n 1. 08:00-10:00\n 2. 10:00-12:00\n 3. 12:00-14:00\n 4. 15:00-17:00\n 5. 17:00-19:00\n 6. 19:00-21:00\n");
    printf("Subject slot: ");
    scanf("%d", &temp);
    subject->slots[u].slot = temp - 1;
  }
}

#define initial_buffer_size 300

char* to_csv_string(schedule_t *schedule) {
  char *buffer = calloc(initial_buffer_size, sizeof(char));
  uint buf_size = initial_buffer_size;

  for(uint i = 0; i<schedule->n_subjects; i++) {
    strncpy(buffer, schedule. );
  }
}
