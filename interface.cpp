#include "interface.h"
#include <LiquidCrystal.h>
#include "engine.h"
#include "scales.h"

// ----- LCD Shield padrão
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// ----- PINOS
#define BUZZER_PIN     3
#define LED_DISPLAY   10
#define BUTTON_ANALOG A0

// ----- ESTADO DA INTERFACE
static uint8_t toneIndex  = 0;
static uint8_t scaleIndex = 0;

// ----- LEITURA DO SHIELD
enum {
  BTN_RIGHT,
  BTN_UP,
  BTN_DOWN,
  BTN_LEFT,
  BTN_SELECT,
  BTN_NONE
};

static int readButton() {
  int v = analogRead(BUTTON_ANALOG);

  if (v < 100) return BTN_RIGHT;
  if (v < 200) return BTN_UP;
  if (v < 400) return BTN_DOWN;
  if (v < 600) return BTN_LEFT;
  if (v < 800) return BTN_SELECT;

  return BTN_NONE;
}

// ----- TELAS
static void drawConfigScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(noteChromatic[toneIndex]);
  lcd.print(" ");
  lcd.print(scales[scaleIndex].name);
}

static void telaInicial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scale.gen");
  lcd.setCursor(0, 1);
  lcd.print("por Erwin");
  delay(2000);
}

// ----- PLAY
static void play() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(noteChromatic[toneIndex]);
  lcd.print(" ");
  lcd.print(scales[scaleIndex].name);

  enginePrintScale(toneIndex, scaleIndex);

  lcd.setCursor(0, 1);
  lcd.print(engineGetScaleStr());
  enginePlayScale(toneIndex, scaleIndex);

  delay(200);
}

// ----- API
void interfaceBegin() {
  lcd.begin(16, 2);

  pinMode(LED_DISPLAY, OUTPUT);
  digitalWrite(LED_DISPLAY, HIGH);

  engineBegin(BUZZER_PIN);

  telaInicial();
  drawConfigScreen();
}

void interfaceUpdate() {
  int btn = readButton();

  if (btn == BTN_NONE)
    return;

  switch (btn) {

    case BTN_UP:   // TONE +
      if (toneIndex < TONE_COUNT - 1)
        toneIndex++;
      drawConfigScreen();
      delay(200); //debounce
      break;

    case BTN_DOWN: // TONE -
      if (toneIndex > 0)
        toneIndex--;
      drawConfigScreen();
      delay(200); //debounce
      break;

    case BTN_RIGHT: // SCALE +
      if (scaleIndex < SCALE_COUNT - 1)
        scaleIndex++;
      drawConfigScreen();
      delay(200); //debounce
      break;

    case BTN_LEFT: // SCALE -
      if (scaleIndex > 0)
        scaleIndex--;
      drawConfigScreen();
      delay(200); //debounce
      break;

    case BTN_SELECT: // PLAY
      play();
      break;
  }

  delay(150); // debounce
}
