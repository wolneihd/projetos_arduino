/*
 * GET API Rest
 */

#include<WiFi.h>
#include <HTTPClient.h>

const char* ssid = "nome_rede";
const char* pass = "senha";

unsigned const long interval = 2000;
unsigned long zero = 0;

void setup(){
  Serial.begin(921600);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(100);
    Serial.println(".");
  }
  Serial.println("WiFi Connected!");
  Serial.println(WiFi.localIP());
}

void loop(){

  if(millis()-zero > interval){

    HTTPClient http;
    http.begin("https://viacep.com.br/ws/00000000/json/");
    int httpResponCode = http.GET();
    Serial.println(httpResponCode);
    if(httpResponCode > 0){
      String payload = http.getString();
      Serial.print(payload);
    }else{
      Serial.print("error ");
      Serial.println(httpResponCode);
    }

    zero = millis();
    delay(5000);
    Serial.println("Aguardando 5seg...");
  }
  
}