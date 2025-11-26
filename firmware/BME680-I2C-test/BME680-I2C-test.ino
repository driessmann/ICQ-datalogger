#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

#define I2C_SDA 21
#define I2C_SCL 22

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme;

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  Serial.println("BME680 test using I2C");

// slave adress is dependant on pulling SDO min HIGH(3,3V) or LOW(GND)

  if (!bme.begin(0x77)) {           // <<< forced adress 
    Serial.println("No BME680 found on 0x77!");

    if (!bme.begin(0x76)) {        // <<< Backup adress
      Serial.println("No BME680 ON 0x76. Check wiring!");
      while (1);
    }
  }

  Serial.println("BME680 found!");

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150);
}

void loop() {
  if (!bme.performReading()) {
    Serial.println("Reading mislukt!");
    return;
  }

  Serial.print("Temp: "); Serial.print(bme.temperature); Serial.println(" *C");
  Serial.print("Hum: "); Serial.print(bme.humidity); Serial.println(" %");
  Serial.print("Press: "); Serial.print(bme.pressure / 100.0); Serial.println(" hPa");
  Serial.print("IAQ: "); Serial.print(bme.gas_resistance/1000.0); Serial.println(" kOhm");
  Serial.println();

  delay(1000);
}

