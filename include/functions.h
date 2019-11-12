#pragma once

#include <stdio.h>
#include "tomato.h"

char *to_csv_string(schedule_t *schedule);
int ask_Data(FILE *tomato_file);
void delay(int msec);
void ask_subject(subject_t *subject);
