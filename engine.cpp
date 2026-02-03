#include "engine.h"

// ----- BUFFER
#define SCALE_STR_LEN  32

//static char rootStr[ROOT_STR_LEN];
static char scaleStr[SCALE_STR_LEN];


// ----- ESTADO INTERNO
static uint8_t ENGINE_BUZZER_PIN = 255;

// ----- INIT
void engineBegin(uint8_t buzzerPin) {
  ENGINE_BUZZER_PIN = buzzerPin;
  pinMode(ENGINE_BUZZER_PIN, OUTPUT);
}

// ----- TOCAR ESCALA
void enginePlayScale(uint8_t root, uint8_t scaleIndex) {

  const Scale* sc = &scales[scaleIndex];
  uint16_t noteDuration = 60000 / 120;

  for (uint8_t i = 0; i < sc->length; i++) {
    tone(ENGINE_BUZZER_PIN, chromatic[root + sc->semitones[i]]);
    delay(noteDuration * 0.9);
    noTone(ENGINE_BUZZER_PIN);
    delay(noteDuration * 0.1);
  }

  for (int8_t i = sc->length - 2; i >= 0; i--) {
    tone(ENGINE_BUZZER_PIN, chromatic[root + sc->semitones[i]]);
    delay(noteDuration * 0.9);
    noTone(ENGINE_BUZZER_PIN);
    delay(noteDuration * 0.1);
  }
}

// ----- IMPRESSÃO DA ESCALA
void enginePrintScale(uint8_t root, uint8_t scaleIndex) {

  const Scale* sc = &scales[scaleIndex];

  NoteSpelling tonic = chromaticSpelling[root];
  uint8_t baseLetter = tonic.letterIndex;

  uint8_t pos = 0;               // cursor do buffer
  scaleStr[0] = '\0';            // limpa buffer

  for (uint8_t i = 0; i < sc->length; i++) {

    uint8_t letter = (baseLetter + sc->letterSteps[i]) % 7;
    int target = (root + sc->semitones[i]) % 12;
    int natural = naturalTones[letter];

    int diff = target - natural;
    if (diff > 6) diff -= 12;
    if (diff < -6) diff += 12;

    // --- letra
    if (pos < SCALE_STR_LEN - 1)
      scaleStr[pos++] = noteLetters[letter][0];

    // --- acidente
    if (diff == 1) {
      if (pos < SCALE_STR_LEN - 1) scaleStr[pos++] = '#';
    }
    else if (diff == -1) {
      if (pos < SCALE_STR_LEN - 1) scaleStr[pos++] = 'b';
    }
    else if (diff == 2) {
      if (pos < SCALE_STR_LEN - 2) {
        scaleStr[pos++] = '#';
        scaleStr[pos++] = '#';
      }
    }
    else if (diff == -2) {
      if (pos < SCALE_STR_LEN - 2) {
        scaleStr[pos++] = 'b';
        scaleStr[pos++] = 'b';
      }
    }

    // --- espaço
    if (pos < SCALE_STR_LEN - 1)
      scaleStr[pos++] = ' ';
  }

  scaleStr[pos] = '\0';   // FINALIZA STRING
}


const char* engineGetScaleStr() {
  return scaleStr;
}