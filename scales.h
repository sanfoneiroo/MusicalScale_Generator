#ifndef SCALES_H
#define SCALES_H

#include <Arduino.h>

#define MAX_SCALE_LEN 9

struct Scale {
  const char* name;
  uint8_t length;
  int8_t semitones[MAX_SCALE_LEN];
  int8_t letterSteps[MAX_SCALE_LEN];
};

extern const Scale scales[];
extern const uint8_t SCALE_COUNT;


#endif
