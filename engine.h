#ifndef ENGINE_H
#define ENGINE_H

#include <Arduino.h>
#include "scales.h"
#include "notes.h"

// ----- CONFIGURAÇÃO
void engineBegin(uint8_t buzzerPin);

// ----- AÇÕES MUSICAIS
void enginePlayScale(uint8_t root, uint8_t scaleIndex);
void enginePrintScale(uint8_t root, uint8_t scaleIndex);
void enginePrintRoot(uint8_t root);

const char* engineGetScaleStr();


#endif
