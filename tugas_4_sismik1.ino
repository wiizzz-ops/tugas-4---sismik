// Utara
const int utaraM = 13; 
const int utaraK = 12; 
const int utaraH = 11;

// Timur
const int timurM = 4; 
const int timurK = 3;  
const int timurH = 2;

// Selatan
const int selatanM = 7; 
const int selatanK = 6; 
const int selatanH = 5;

// Barat
const int baratM = 10;   
const int baratK = 9;  
const int baratH = 8;

void setup() {
  for(int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    
    // Lampu Merah (pin 13, 10, 7, 4) nyala semua, sisanya mati
    if(i == 13 || i == 10 || i == 7 || i == 4) {
      digitalWrite(i, HIGH); 
    } else {
      digitalWrite(i, LOW);  
    }
  }
  delay(2000); 
}

void loop() {
  // Urutan menyala
  aktifkanSimpang(utaraM, utaraK, utaraH);
  aktifkanSimpang(timurM, timurK, timurH);
  aktifkanSimpang(selatanM, selatanK, selatanH);
  aktifkanSimpang(baratM, baratK, baratH);
}

void aktifkanSimpang(int pinMerah, int pinKuning, int pinHijau) {
  digitalWrite(pinMerah, LOW);

  digitalWrite(pinHijau, HIGH);
  delay(5000);
  digitalWrite(pinHijau, LOW);

  for(int i = 0; i < 3; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(200); 
    digitalWrite(pinKuning, LOW);
    delay(200); 
  }
  digitalWrite(pinKuning, HIGH);
  delay(2000);
  digitalWrite(pinKuning, LOW);

  digitalWrite(pinMerah, HIGH);
}