#include <SparkFun_RV8803.h> //Get the library here:http://librarymanager/All#SparkFun_RV-8803
RV8803 rtc;
int sec = 2;
int minute = 47;
int hour = 14;
int date = 2;
int month = 3;
int year = 2020;
int weekday = 2;
//dont worry about whats above
void setup()
{
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Set Time on RTC");
  if (rtc.begin() == false)
  {
    Serial.println("Device not found. Please check wiring. Freezing.");
    while(1);
  }
  Serial.println("RTC online!");
  if (rtc.setToCompilerTime() == false)
    Serial.println("Something went wrong setting the time");
  else
    Serial.println("New time set!");
void loop()
{
  if (rtc.updateTime() == true)
  {
    String currentDate = rtc.stringDateUSA();
    //String currentDate = rtc.stringDate();
    String currentTime = rtc.stringTime();
    Serial.print(currentDate);
    Serial.print(" ");
    Serial.println(currentTime);
  }
  else
  {
    Serial.print("RTC read failed");
  }
  delay(1000);
}
white_check_mark
eyes
raised_hands





10:47
This function sets the time of the RTC to match your laptop. MAKE SURE ARDUINO IDE IS FRESHLY STARTED

#include <SparkFun_RV8803.h>
RV8803 rtc;
void setup()
{
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Read Time from RTC Example");
  if (rtc.begin() == false)
  {
    Serial.println("Something went wrong, check wiring");
    while(1);
  }
  Serial.println("RTC online!");
}
void loop()
{
  if (rtc.updateTime() == true) //Updates the time variables from RTC
  {
    String currentDate = rtc.stringDateUSA();
    //String currentDate = rtc.stringDate();
    String currentTime = rtc.stringTime();
    Serial.print(currentDate);
    Serial.print(" ");
    Serial.println(currentTime);
  }
  else
  {
    Serial.print("RTC read failed");
  }
  delay(1000);
}
10:48
This just prints the time for verification, no delay

#include <SparkFun_RV8803.h>
RV8803 rtc;
uint8_t minuteAlarmValue = 23
uint8_t hourAlarmValue = 0; //0-24
uint8_t weekdayAlarmValue = SUNDAY | SATURDAY;
uint8_t dateAlarmValue = 0; //1-31
int catchInterrupt = 10;
#define MINUTE_ALARM_ENABLE true
#define HOUR_ALARM_ENABLE false
#define WEEKDAY_ALARM_ENABLE false
#define DATE_ALARM_ENABLE false
void setup()
{
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Alarm from RTC Example");
  if (rtc.begin() == false)
  {
    Serial.println("Device not found. Please check wiring. Freezing.");
    while(1);
  }
  Serial.println("RTC online!");
  rtc.disableAllInterrupts();
  rtc.clearAllInterruptFlags();
  rtc.setItemsToMatchForAlarm(MINUTE_ALARM_ENABLE, HOUR_ALARM_ENABLE, WEEKDAY_ALARM_ENABLE, DATE_ALARM_ENABLE);
  rtc.setAlarmHours(hourAlarmValue);
  rtc.setAlarmWeekday(weekdayAlarmValue);
  rtc.enableHardwareInterrupt(ALARM_INTERRUPT);
  pinMode(10, OUTPUT);
}
void loop()
{
  if (rtc.getInterruptFlag(FLAG_ALARM))
  {
    Serial.println("Alarm Triggered, clearing flag");
    rtc.clearInterruptFlag(FLAG_ALARM);
    if (digitalRead(2) == HIGH)
    {
    digitalWrite(10, LOW);
    }
    else if (digitalRead(2) == LOW);
    {
     digitalWrite(10, HIGH);
     delay(1000);
     digitalWrite(10,LOW);
    }
  }
  else
  {
    Serial.println("Waiting for alarm...");
  }
  delay(1000);
}
white_check_mark
eyes
raised_hands