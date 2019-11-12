#pragma once

#include <stdint.h>
#include <time.h>

#define uint16_fast_t uint

typedef enum { monday, tuesday, wednesday, thursday, friday } day_t;
typedef enum { s08_10, s10_12, s12_02, s03_05, s05_07, s07_09 } dayslot_t;

typedef struct {
  day_t day;
  dayslot_t slot;
} slot_t;

typedef struct {
  char *name;
  slot_t slots[2];
} subject_t;

typedef struct {
  uint32_t n_subjects;
  subject_t *subjects;
} schedule_t;

