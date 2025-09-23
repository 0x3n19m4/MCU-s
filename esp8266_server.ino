#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
Servo servo1;

ESP8266WebServer server(80);

String html = "<h1>ESP Web Server</h1><p>Servo switch <a href=\"Servo_On\"><button>ON</button></a>&nbsp;<a href=\"Servo_Off\"><button>OFF</button></a></p>";
const char* ssid = "[REDACTED]";
const char* password = "[REDACTED]";

void setup(void) {
  servo1.attach(2);
  
  Serial.begin(115200);

  // WiFi Initialisation
  WiFi.begin(ssid, password);

  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", [] () {
    server.send(200, "text/html", html);
  });

  server.on("/Servo_On", [] () {
    server.send(200, "text/html", html);
    servo1.write(0);
    Serial.println("Changing Servo state to ON");
    delay(100);
  });

  server.on("/Servo_Off", [] () {
    server.send(200, "text/html", html);
    servo1.write(130);
    Serial.println("Changing Servo state to OFF");
    delay(100);
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
