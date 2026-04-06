// PIN KENDARAAN (JALAN RAYA) 
const int mobilM = 13;
const int mobilK = 12;
const int mobilH = 11;

// PIN PEJALAN KAKI (KIRI & KANAN DIPARALEL)
const int pedM = 10;
const int pedH = 9;

// PIN TOMBOL (INTERRUPT) 
const int pinTombol = 2; 

// Variabel penanda interrupt 
volatile bool tombolDitekan = false;

void setup() {
  // mengatur pin lampu sebagai OUTPUT
  pinMode(mobilM, OUTPUT);
  pinMode(mobilK, OUTPUT);
  pinMode(mobilH, OUTPUT);
  pinMode(pedM, OUTPUT);
  pinMode(pedH, OUTPUT);

  // mengaktifkan resistor pull-up internal untuk tombol
  pinMode(pinTombol, INPUT_PULLUP);

  // mendaftarkan fungsi interrupt pada Pin 2
  // mode FALLING: memicu program saat tombol ditekan
  attachInterrupt(digitalPinToInterrupt(pinTombol), isrPenyeberang, FALLING);

  // jalankan kondisi awal saat pertama kali menyala
  kondisiAwal();
}

void loop() {
  // siklus hanya akan berjalan JIKA tombol ditekan
  if (tombolDitekan) {
    delay(1000); // Jeda reaksi aman 1 detik sebelum lampu berubah

    // FASE 1: Kendaraan Merah (Berhenti), Pedestrian Hijau (Jalan)
    digitalWrite(mobilH, LOW);
    digitalWrite(mobilM, HIGH);
    digitalWrite(pedM, LOW);
    digitalWrite(pedH, HIGH);

    delay(5000); // Waktu untuk menyeberang jalan (contoh: 5 detik)

    // FASE 2: Pedestrian Merah (Berhenti), Kendaraan Kuning (Persiapan transisi)
    digitalWrite(pedH, LOW);
    digitalWrite(pedM, HIGH);
    digitalWrite(mobilM, LOW);
    digitalWrite(mobilK, HIGH); 

    delay(2000); // Waktu lampu kuning menyala (contoh: 2 detik)

    // FASE 3: Sistem kembali ke kondisi awal (Kendaraan Hijau, Pedestrian Merah)
    kondisiAwal();

    // Reset status tombol agar sistem siap menerima tekanan tombol berikutnya
    tombolDitekan = false;
  }
}

// Fungsi pembantu untuk mengatur kondisi default
void kondisiAwal() {
  digitalWrite(mobilM, LOW);
  digitalWrite(mobilK, LOW);
  digitalWrite(mobilH, HIGH); // Lampu jalan raya: Hijau
  
  digitalWrite(pedH, LOW);
  digitalWrite(pedM, HIGH);   // Lampu penyeberang: Merah
}

// Interrupt Service Routine (ISR) - Berjalan seketika saat tombol ditekan
void isrPenyeberang() {
  tombolDitekan = true;
}