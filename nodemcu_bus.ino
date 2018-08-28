





#include <ESP8266WiFi.h>
#include <string.h>
#include <WiFiClientSecure.h>

const char* ssid = "BUS_STOP";
const char* password = "tsrtcrocks";

const char* host = "175.101.12.206";
const int httpPort = 80;




void setup() {
  
  pinMode(D0,INPUT_PULLUP);
  pinMode(D1,INPUT_PULLUP);
  pinMode(D3,INPUT_PULLUP);
  pinMode(D4,INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  


 
}
char c;
char message[]= "GET /setsensor.php?login=Vishnu1&password=Vishnu1&data=        p\r\nHost:175.101.12.206\r\nUser-Agent:Arduino\r\nConnection: close\r\n\r\n";
char data[100];
int pcount=0,spcount=0;
char choice;
void loop() {
char mes[10];
c=Serial.read();
  if(c=='0')
  {
    pcount++;
  }
  else  if(c=='1')
  {
    spcount++;
  }
  
  else if(c=='2')
  {
   WiFiClient client;
 Serial.print("connecting to ");
 Serial.println(host);
 if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    delay(500);
  mes[0]='$';
  mes[1]='H';
  mes[2]='$';
  mes[3]=48  + pcount/10;
  mes[4]=48  + pcount%10;
  mes[5]='$';
  mes[6]=48  + spcount/10;
  mes[7]=48  + spcount%10;
  mes[8]=48  + '$';
  pcount=0;
  spcount=0;
  client.print(message);
 
  }
  
  

//////////////////////////////
  

