
#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int LMT1=3,LMT2=4;           
int RMT1=5,RMT2=6;




void setup()
{
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif
  Serial.begin(9600);// giao tiếp Serial với baudrate 9600
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  Serial.println("Ready.........");
  
 pinMode(LMT1,OUTPUT);          // Motors are declared as output
 pinMode(LMT2,OUTPUT);
 pinMode(RMT1,OUTPUT);
 pinMode(RMT2,OUTPUT);
  
}

void loop()
{
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  if ((ay < 9000) and (ay > -9000) and (ax < 12000) and (ax > -3000))
  {
    
   
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(LMT1,LOW);
  digitalWrite(LMT2,LOW);
  digitalWrite(RMT1,HIGH);
  digitalWrite(RMT2,HIGH);

  }

  if (ax < -3800)
   {
   if (ay < -13000)
    {
      
      Serial.println("");
  Serial.println("Forward");
  digitalWrite(LMT1,HIGH);
  digitalWrite(LMT2,LOW);
  digitalWrite(RMT1,HIGH);
  digitalWrite(RMT2,LOW); 
    }
    else if (ay > 8000)
    {
      
     Serial.println("");
  Serial.println("Forward");
  digitalWrite(LMT1,HIGH);
  digitalWrite(LMT2,LOW);
  digitalWrite(RMT1,HIGH);
  digitalWrite(RMT2,LOW); 
    }
    else
    {
     
     Serial.println("");
  Serial.println("Forward");
  digitalWrite(LMT1,HIGH);
  digitalWrite(LMT2,LOW);
  digitalWrite(RMT1,HIGH);
  digitalWrite(RMT2,LOW); 
    }
  }

  if (ay < -13000)
  {
    if (ax < -3800)
    {
      
      Serial.println("");
  Serial.println("Forward");
  digitalWrite(LMT1,HIGH);
  digitalWrite(LMT2,LOW);
  digitalWrite(RMT1,HIGH);
  digitalWrite(RMT2,LOW); 
    }
    else
    {
      
    Serial.println("");
  Serial.println("Left");
  digitalWrite(LMT1,HIGH);
  digitalWrite(LMT2,LOW);
  digitalWrite(RMT1,LOW);
  digitalWrite(RMT2,HIGH);
    }
  }

  if (ay > 7000)
  {
    if (ax < -3800)
    {
     
      Serial.println("");
  Serial.println("Forward");
  digitalWrite(LMT1,HIGH);
  digitalWrite(LMT2,LOW);
  digitalWrite(RMT1,HIGH);
  digitalWrite(RMT2,LOW);
    }
    else
    {
     
  Serial.println("");
  Serial.println("Right");
  digitalWrite(LMT1,LOW);
  digitalWrite(LMT2,HIGH);
  digitalWrite(RMT1,HIGH);
  digitalWrite(RMT2,LOW);
    }
  }

  if (ax > 14000)
  {
   
  Serial.println("");
  Serial.println("Backward");
  digitalWrite(LMT1,LOW);
  digitalWrite(LMT2,HIGH);
  digitalWrite(RMT1,LOW);
  digitalWrite(RMT2,HIGH);
  }

}
