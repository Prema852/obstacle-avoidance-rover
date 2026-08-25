// =====================================
// OBSTACLE AVOIDANCE ROVER
// Arduino UNO + L298N
// 2 DC Motors + 3 HC-SR04
// =====================================


// ---------- Ultrasonic Sensors ----------

// Front sensor
#define FRONT_TRIG 4
#define FRONT_ECHO 7

// Left sensor
#define LEFT_TRIG 2
#define LEFT_ECHO 3

// Right sensor
#define RIGHT_TRIG 12
#define RIGHT_ECHO 13


// ---------- L298N Motor Driver ----------

#define ENA 5
#define IN1 8
#define IN2 9

#define IN3 10
#define IN4 11
#define ENB 6


// ---------- Motor Speed ----------

int motorSpeed = 130;


// =====================================
// SETUP
// =====================================

void setup()
{
  // Ultrasonic sensor pins
  pinMode(FRONT_TRIG, OUTPUT);
  pinMode(FRONT_ECHO, INPUT);

  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(LEFT_ECHO, INPUT);

  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);


  // L298N motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);


  // Serial Monitor
  Serial.begin(9600);


  // Keep motors stopped initially
  stopMotors();

  delay(1000);
}


// =====================================
// MAIN LOOP
// =====================================

void loop()
{
  // Read all three ultrasonic sensors
  int frontDistance = getDistance(FRONT_TRIG, FRONT_ECHO);
  int leftDistance = getDistance(LEFT_TRIG, LEFT_ECHO);
  int rightDistance = getDistance(RIGHT_TRIG, RIGHT_ECHO);


  // Display distances in Serial Monitor

  Serial.print("Front: ");
  Serial.print(frontDistance);
  Serial.print(" cm");

  Serial.print(" | Left: ");
  Serial.print(leftDistance);
  Serial.print(" cm");

  Serial.print(" | Right: ");
  Serial.print(rightDistance);
  Serial.println(" cm");


  // =================================
  // NO OBSTACLE IN FRONT
  // =================================

  if (frontDistance > 23)
  {
    moveForward();
  }


  // =================================
  // OBSTACLE DETECTED
  // =================================

  else
  {
    // Stop first
    stopMotors();

    delay(200);


    // =================================
    // CHECK LEFT AND RIGHT
    // =================================

    if (leftDistance > rightDistance)
    {
      // More free space on LEFT
      turnLeft();

      delay(180);
    }
    else
    {
      // More free space on RIGHT
      turnRight();

      delay(180);
    }


    // Stop after turning
    stopMotors();

    delay(100);
  }
}


// =====================================
// ULTRASONIC DISTANCE FUNCTION
// =====================================

int getDistance(int trigPin, int echoPin)
{
  long duration;
  int distance;


  // Make sure trigger is LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  // Send ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  // Read echo
  duration = pulseIn(echoPin, HIGH, 30000);


  // If no echo is received
  if (duration == 0)
  {
    return 400;
  }


  // Calculate distance in cm
  distance = duration * 0.034 / 2;


  return distance;
}


// =====================================
// MOVE FORWARD
// =====================================

void moveForward()
{
  // LEFT MOTOR FORWARD
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);


  // RIGHT MOTOR FORWARD
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);


  // Motor speed
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}


// =====================================
// MOVE BACKWARD
// =====================================

void moveBackward()
{
  // LEFT MOTOR BACKWARD
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);


  // RIGHT MOTOR BACKWARD
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);


  // Motor speed
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}


// =====================================
// TURN LEFT
// =====================================

void turnLeft()
{
  // LEFT MOTOR FORWARD
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);


  // RIGHT MOTOR BACKWARD
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);


  // Motor speed
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}


// =====================================
// TURN RIGHT
// =====================================

void turnRight()
{
  // LEFT MOTOR BACKWARD
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);


  // RIGHT MOTOR FORWARD
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);


  // Motor speed
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}


// =====================================
// STOP MOTORS
// =====================================

void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);


  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
