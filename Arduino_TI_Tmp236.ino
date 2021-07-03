/*
 * TMP236
 * https://www.ti.com.cn/cn/lit/ds/symlink/tmp236.pdf?ts=1625297282666&ref_url=https%253A%252F%252Fwww.google.com%252F
 * TMP236 Transfer Table 4
 * TMP236 
 * P1 > VCC(3.3V)
 * P2 > GND
 * P3(Vout) Arduono A0
 * Vout Minimum : 205 => 0.205
 * Vout maximum : 2838 => 2.083
 */
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);
  float voltage= sensorValue * (5.0 / 1023.0);
  float temp=0;

  // print out the value you read:
  
  temp=mapfloat(voltage,0.205,2.838,-10.000,125.000);
  Serial.print(voltage);
  Serial.print(",");
  Serial.println(temp);
  delay(1);        // delay in between reads for stability
}
