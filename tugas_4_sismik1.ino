// DEKLARASI PIN
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
  // mengatur semua pin LED sebagai OUTPUT
  for(int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    
    // lampu Merah (pin 13, 10, 7, 4) nyala semua, sisanya mati
    if(i == 13 || i == 10 || i == 7 || i == 4) {
      digitalWrite(i, HIGH); 
    } else {
      digitalWrite(i, LOW);  
    }
  }
  // tahan sebentar 2 detik
  delay(2000); 
}

void loop() {
  // urutan menyala, dari utara, timur, selatan, barat, ke utara lagi
  aktifkanSimpang(utaraM, utaraK, utaraH);
  aktifkanSimpang(timurM, timurK, timurH);
  aktifkanSimpang(selatanM, selatanK, selatanH);
  aktifkanSimpang(baratM, baratK, baratH);
}

//fungsi modular untuk mengatur nyala lampu per simpang
void aktifkanSimpang(int pinMerah, int pinKuning, int pinHijau) {
  // matikan lampu merah
  digitalWrite(pinMerah, LOW);

  // lampu hijau menyala 5 detik
  digitalWrite(pinHijau, HIGH);
  delay(5000);
  digitalWrite(pinHijau, LOW);

  // lampu kuning kedip 3 kali
  for(int i = 0; i < 3; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(200); 
    digitalWrite(pinKuning, LOW);
    delay(200); 
  }
  // lampu kuning menyala 2 detik
  digitalWrite(pinKuning, HIGH);
  delay(2000);

  // lampu merah nyala lagi
  digitalWrite(pinKuning, LOW);

  digitalWrite(pinMerah, HIGH);
}
