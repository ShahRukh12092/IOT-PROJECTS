
#include <SPI.h>
#include <MFRC522.h>
#include <TimeLib.h>
#include <Servo.h>

#define SS_PIN 10 //RX slave select
#define RST_PIN 9
int pos = 0;  
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

byte card_ID[4]; //card UID size 4byte
byte Name1[4]={0xEC,0xAB,0xE0,0x38};
byte Name2[4]={0x0C,0x39,0x1E,0x4A};
//if you want the arduino to detect the cards only once
int NumbCard[2];//this array content the number of cards. in my case i have just two cards.
int j=0;        

String Name;//user name
long Number;//user number
int n ;//The number of card you want to detect (optional)  

void setup() {
  mfrc522.PCD_Init(); // Init MFRC522 card

  Serial.println("CLEARSHEET");                 // clears starting at row 1
  Serial.println("LABEL,Date,Time,Name,Number");// make four columns (Date,Time,[Name:"user name"]line 48 & 52,[Number:"user number"]line 49 & 53)

  setTime(20,0,0,3,30,2019);
  Serial.begin(9600);
  SPI.begin();  
  mfrc522.PCD_Init(); 
  

   }
    
void loop() {
  
   
  //look for new card
   if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;//got to start of loop if there is no card present
 }
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;//if read card serial(0) returns 1, the uid struct contians the ID of the read card.
 }
 
 for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID[i]=mfrc522.uid.uidByte[i];

       if(card_ID[i]==Name1[i]){
       Name="shahrukh";//user name
       Number="030325435";//user number
       j=0;//first number in the NumbCard array : NumbCard[j]
      
      }
      else if(card_ID[i]==Name2[i]){
      
       Name="Zeeshan";//user name
       Number="03032323";//user number
       j=1;//Second number in the NumbCard array : NumbCard[j]
       
      } 
      else{
          
          delay(30);
          goto cont;//go directly to line 85
     }
}
      if(NumbCard[j] == 1){//to check if the card already detect
      //if you want to use LCD
      //Serial.println("Already Exist");
      }
      else{
      NumbCard[j] = 1;//put 1 in the NumbCard array : NumbCard[j]={1,1} to let the arduino know if the card was detecting 
      n++;//(optional)
      Serial.print("DATA,DATE,TIME," + Name);//send the Name to excel
      Serial.print(",");
      Serial.println(Number); //send the Number to excel
     
      Serial.println("SAVEWORKBOOKAS,Names");
      }
cont:
delay(200);


}
