#include <string>

const char *alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *reverseString(char *x) {
  uint8_t n = strlen(x), i;
  if (n == 1) return x;
  uint8_t j = n / 2;
  for (i = 0; i < j; i++) {
    char c = x[i];
    x[i] = x[n - i - 1];
    x[n - i - 1] = c;
  }
  return x;
}

char *dec2base(uint32_t num, uint8_t base, uint8_t padding = 4) {
  if (base < 2) base = 2;
  if (base > 36) base = 36;
  std::string rslt;
  uint32_t current = num;
  uint8_t remainder, ln = 0;
  while (current > 0) {
    remainder = current % base;
    //Serial.print(" . current = "); Serial.println(current);
    //Serial.print(" . remainder = "); Serial.println(remainder);
    //Serial.print(" . remainder = "); Serial.println(alphabet[remainder]);
    rslt.push_back(alphabet[remainder]);
    current = current / base;
    ln += 1;
  }
  while (ln < padding) {
    rslt.push_back('0');
    ln += 1;
  }
  return reverseString((char*)rslt.c_str());
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t i;
  uint32_t r = esp_random() % 1600000;
  Serial.print(r); Serial.print(" in base 36: ");
  Serial.println(dec2base(r, 36));
  delay(1000);
}
