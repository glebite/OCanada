#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN     8

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  1

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50

#define LETTERS_IN_ALPHABET 26

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// lower case, no punctuation
char *lyrics = "o canada our home and native land true patriot love in all of us command with glowing hearts we see thee rise the true north strong and free from far and wide o canada, we stand on guard for thee god keep our land glorious and free o canada we stand on guard for thee o canada we stand on guard for thee o canada terre de nos aieux ton front est ceint de fleurons glorieux car ton bras sait porter l epee il sait porter la croix ton histoire est une epopee  des plus brillants exploits et ta valeur de foi trempee protegera nos foyers et nos droits protegera nos foyers et nos droits";
char* morse_codes[LETTERS_IN_ALPHABET] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int iPos = 0;
char current_char = '\0';
void loop() {
  current_char = lyrics[iPos];
  iPos = (iPos + 1) % strlen(lyrics);
  morse_out(current_char);
}

// using red out for .
void red_out() {
  strip.fill(strip.Color(255,0,0));
  strip.show();  
}

// using white out for -
void white_out() {
  strip.fill(strip.Color(255,255,255));
  strip.show();
}

// black?  blank?
void blank() {
  strip.fill(strip.Color(0,0,0));
  strip.show();  
}

void morse_out(char current_char) {
  int iPos;
  int offset;
  offset = current_char - 'a';
  if (current_char == ' ') {
    blank();
    delay(500);
  } else {
    for (iPos = 0; iPos < strlen(morse_codes[offset]); iPos++) {
      if (morse_codes[offset][iPos] == '.') {
        red_out();
        delay(200);
      } else {
        white_out();
        delay(400);
      }
      blank();
      delay(100);
    }
  }
}
