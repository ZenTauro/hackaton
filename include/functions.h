#pragma once

#include "tomato.h"
#include <stdio.h>

char *to_csv_string(FILE *tomato_file, schedule_t *schedule);
void Krono(FILE *file);
int ask_Data(FILE *tomato_file);
void delay(int msec);
void ask_subject(subject_t *subject);
