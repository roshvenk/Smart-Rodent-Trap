#include <Adafruit_FONA.h>
#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4
#include <SoftwareSerial.h>
SoftwareSerial fonaSS = SoftwareSerial (FONA_TX, FONA_RX);
SoftwareSerial	*fonaSerial = &fonaSS;
Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
#define phoneNumber "18572538726"

int val = 0;
int relayState = 1;

void setup()
{
	Serial.begin(9600);
	while (!Serial)
	{
		;
	}
	
	Serial.println("SMS Messages Sender");
	
	fonaSerial -> begin(4800);
	if(! fona.begin(*fonaSerial))
	{
		Serial.println(F("Couldn't find FONA'"));
		while(l);
    }
    Serial.println(F("FONA is OK"));
    Serial.print(F("Found"));
    
    if(!fona.sendSMS(phoneNumber, "Hey, we got a rodent at Trap A"))
    {
    	Serial.println(F("Failed"));
	}
	else
	{
		Serial.println(F("Sent!"));
	}
	
	pinMode(4, INPUT);
	pinMode(6, OUTPUT);
	
	digitalWrite(6, HIGH);
	
}

void loop()
{
	val = digitalRead(4);
	Serial.println(val);
	if(val == LOW)
	{
		relayState == 0;
	}
	
	digitalWrite (6, relayState);
	if (relayState == 0)
	{
		delay(30000);
		relayState == 1;
		
	}
	relayState = 1;
}
