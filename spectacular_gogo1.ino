
// LED conectado ao pino 10
int ledPin = 10;

// Tabela Morse
String morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
  "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Função para piscar o LED
void blinkLED(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      digitalWrite(ledPin, HIGH);
      delay(150);
      digitalWrite(ledPin, LOW);
      delay(100);
    } else if (code[i] == '-') {
      digitalWrite(ledPin, HIGH);
      delay(400);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
    delay(100); // Espaço entre pontos e traços
  }
  delay(300); // Espaço entre letras
}

void setup() {
  // Define o pino como saída
  pinMode(ledPin, OUTPUT);
  // Inicia a comunicação Serial
  Serial.begin(9600);
}

void loop() {
  // Verifica se há dados disponíveis na Serial
  if (Serial.available() > 0) {
    // Lê a string digitada
    String input = Serial.readStringUntil('\n');
    input.toUpperCase(); // Converte para maiúsculas

    // Percorre cada caractere da string
    for (int i = 0; i < input.length(); i++) {
      if (input[i] >= 'A' && input[i] <= 'Z') {
        // Converte a letra para código Morse e pisca o LED
        blinkLED(morseCode[input[i] - 'A']);
      }
    }
  }
}
