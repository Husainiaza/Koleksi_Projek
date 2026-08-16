void sensorCahaya(){

  int dataCahaya = analogRead(36);
  Serial.println(dataCahaya);

  dtostrf(dataCahaya, 1, 2, varPotString);
  client.publish("azman/cahaya", varPotString);
}

void sensorSuhu()
{ 
  sensors.requestTemperatures(); // Send the command to get temperatures
  float tempC = sensors.getTempCByIndex(0);

  Serial.print("Bacaan suhu: ");
  Serial.println(tempC);

  if(tempC > 26){
    digitalWrite(buzzer,HIGH);
    client.publish("azman/suhu/status", "alarm berbunyi");
  }
  else {
    digitalWrite(buzzer,LOW);
    client.publish("azman/suhu/status", "suhu normal");
  }

  dtostrf(tempC, 1, 2, varPotString);
  client.publish("azman/suhu", varPotString);

}
