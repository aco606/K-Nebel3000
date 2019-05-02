
long unterschied = 0;
long interval = 1000;
long start = 0;
int takt = 1846;      //LÃ¤nge des Takts festlegen. BPM von Clocks 130. -> 1846 ms Taktlänge
int resetT = 30;

byte rows = 0;
int ges = 0;
//Nummerierung für spalten und Reihen vereinfachen
byte sr1 = B01111111;
byte sr2 = B10111111;
byte sr3 = B11011111;
byte sr4 = B11101111;
byte sr5 = B11110111;
byte sr6 = B11111011;
byte sr7 = B11111101;
byte sr8 = B11111110;

byte reihen[8] = {sr1, sr2, sr3, sr4, sr5, sr6, sr7, sr8};

void setup() {
  DDRC = B00000000;       // Direction Register für Port C. Acht Nullen bedeuten, dass alle Pins auf Input gesetzt werden.
  DDRA = B11111111;       // Entsprechend für port A. Alle Pins  werden auf Output gesetzt.
}

void loop() {
 
clocks();
//lied(); 
//testen();
  
}

void ton(int reihe, int spalte, int val){
  unterschied = 0;                        
  start = millis();                       
  while(unterschied<=val) {               
    unterschied = millis()-start;         
    spielen(reihen[reihe],reihen[spalte]);                     
  }
}
//Dienst um einen Ton auszugeben mit den Ãœbergabeparametern reihe und spalte
void spielen(byte reihe, byte spalte) {
   if (PINC == reihe) {                 // PINC fragt den Zustand der auf Input gesetzten Pins am Port C ab.
   PORTA = spalte;                      // PORTA setzt den Zustand der auf Output gesetzten Pins am Port A auf 5V oder 0. 
  } else {
    PORTA = B11111111;
    }
  }
  
//Dienst um eine bestimmte Note mit bestimmter Reihe und Spalte auszugeben  mit dem Ãœbergabeparameter fÃ¼r die LÃ¤nge des zu spielenden Tons
void c2(int val) {
  unterschied = 0;                        //unterschied auf 0 setzten
  start = millis();                       //start vor beginn der while Schleife auf die Millisekunden seit start des Sketches setzen
  while(unterschied<=val) {               //ÃœberprÃ¼fen ob Unterschied kleiner oder gleich der lÃ¤nge der Note
    unterschied = millis()-start;         //unterschied auf die millisekunden-start setzen
    spielen(sr4,sr6);                     //mit den Reihen und Spalten der note, diese Ã¼ber den Dienst spielen aufrufen
  }
}

void d2(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr4,sr4);
  }
}

void e2(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr4,sr2);
  }
}

void f3(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr7);
  }
}

void g3(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr5);
  }
}

void g2(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr1,sr1);
  }
}

void a3(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr3);
  }
}

void b3(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr4);
  }
}
// ----- Noten für das Lied Clocks ------------
void es3(int val){
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr6,sr5);
  }
}

void ais3(int val){
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr4);
  }
}

void cis3(int val){
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr5,sr3);
  }
}

void as3(int val){
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr6);
  }
}

void c3(int val){
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr2);
  }
}

//Alle Spalten in allen Reihen auf 1 setzen
void set1(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr1,B11111111);
    spielen(sr2,B11111111);
    spielen(sr3,B11111111);
    spielen(sr4,B11111111);
    spielen(sr5,B11111111);
    spielen(sr6,B11111111);
    spielen(sr7,B11111111);
    spielen(sr8,B11111111); 
  }
}

//void spiele3(void note1,void note2,void note3, int t) {
  //ti = t/30;
  //for(int i = 0; i<=ti; i++) {
   // note1(10);
   // note2(10);
    //note3(10);
