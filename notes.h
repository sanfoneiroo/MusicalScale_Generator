#ifndef NOTES_H
#define NOTES_H

#include <Arduino.h>

// ----- CONFIG DAS NOTAS
static const char* noteLetters[] = { "C", "D", "E", "F", "G", "A", "B" };
static const char* noteChromatic[] = { "C", "C#", "D", "Eb", "E", "F", "F#", "G", "Ab", "A", "Bb", "B" };
const uint8_t TONE_COUNT = 12; 

// ----- TONS NATURAIS (C D E F G A B)
static const uint8_t naturalTones[] = {
  0,  // C
  2,  // D
  4,  // E
  5,  // F
  7,  // G
  9,  // A
  11  // B
};

// ----- ESTRUTURA DE GRAFIA MUSICAL
typedef struct {
  uint8_t letterIndex; // 0=C ... 6=B
  int8_t accidental;  // -1 = b, 0 = natural, +1 = #
} NoteSpelling;

// ----- MAPA CROMÁTICO (1 OITAVA)
static const NoteSpelling chromaticSpelling[12] = {
  {0,  0}, // C
  {0, +1}, // C#
  {1,  0}, // D
  {2, -1}, // Eb
  {2,  0}, // E
  {3,  0}, // F
  {3, +1}, // F#
  {4,  0}, // G
  {5, -1}, // Ab
  {5,  0}, // A
  {6, -1}, // Bb
  {6,  0}  // B
};

// ----- FREQUÊNCIAS (C4 :: B5)
static const uint16_t chromatic[] = {
  262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, // C4 → B4
  523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988  // C5 → B5
};

#endif
