// HC-SR04 pinleri
#define trigPin 13
#define echoPin 12

// PIR sensörü pinleri
#define pirPin 8

// Ses sensörü pinleri
#define soundPin 2

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(soundPin, INPUT);
  
  Serial.println("Sensörler başlatıldı...");
  delay(2000); // Sensörlerin stabilize olması için bekle
}

void loop() {
  // Mesafe ölçümü
  long duration;
  float distance;
  
  // Trigger sinyali gönder
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Echo sinyalini oku (timeout 30ms = ~500cm)
  duration = pulseIn(echoPin, HIGH, 30000);
  
  if (duration == 0) {
    Serial.println("HC-SR04: Mesafe ölçülemedi (timeout)");
  } else {
    distance = (duration * 0.034) / 2; // Daha doğru hesaplama
    
    // Geçerli mesafe aralığını kontrol et
    if (distance < 2 || distance > 400) {
      Serial.println("HC-SR04: Mesafe geçerli aralık dışında");
    } else {
      Serial.print("Mesafe: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  }
  
  // PIR hareket sensörü
  int pirStatus = digitalRead(pirPin);
  if (pirStatus == HIGH) {
    Serial.println("PIR: Hareket algılandı!");
  }
  
  // Ses sensörü
  int soundStatus = digitalRead(soundPin);
  if (soundStatus == HIGH) {
    Serial.println("SES: Ses algılandı!");
  }
  
  Serial.println("---");
  delay(1000);
}