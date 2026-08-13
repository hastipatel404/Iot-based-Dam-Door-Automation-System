#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 6

Servo gateServo;

long duration;
float distance;

// Adjust these values according to your model
const float HIGH_WATER_LEVEL = 10.0;
const float SAFE_WATER_LEVEL = 15.0;

void setup()
{
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    gateServo.attach(SERVO_PIN);

    // Initial gate position
    gateServo.write(0);

    Serial.println("Automatic Dam Gate System Started");
}

float getDistance()
{
    // Make sure trigger starts LOW
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send ultrasonic pulse
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read echo time
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calculate distance in centimeters
    float distance = duration * 0.034 / 2;

    return distance;
}

void loop()
{
    float currentDistance = getDistance();

    Serial.print("Distance: ");
    Serial.print(currentDistance);
    Serial.println(" cm");

    /*
       Smaller distance means the water surface
       is closer to the ultrasonic sensor.
    */

    if (currentDistance <= HIGH_WATER_LEVEL)
    {
        Serial.println("Water Level: HIGH");
        Serial.println("Opening Dam Gate...");

        gateServo.write(90);
    }
    else if (currentDistance >= SAFE_WATER_LEVEL)
    {
        Serial.println("Water Level: SAFE");
        Serial.println("Closing Dam Gate...");

        gateServo.write(0);
    }
    else
    {
        Serial.println("Water Level: MODERATE");
    }

    delay(1000);
}
