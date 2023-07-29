#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <WiFi.h>
 

// Replace with your network credentials
#define ssid  "farhana"
#define password "1234567890"

WiFiServer server(80);                                     // Set web server port number to 80

String header;                                             // Variable to store the HTTP request


String forward = "off";
String backward = "off";                            // Auxiliar variables to store the current output state
String left = "off";
String right = "off";

const int FBled = 2;
const int LRled = 23;                                 // Assign output variables to GPIO pins

void setup() {
  Serial.begin(115200);
  pinMode(FBled, OUTPUT);                               // Initialize the output variables as outputs
  digitalWrite(FBled, LOW);
  
  pinMode(LRled, OUTPUT);                               // Initialize the output variables as outputs
  digitalWrite(LRled, LOW);                               // Set outputs to LOW
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("forward on");
              forward = "on";
              digitalWrite(FBled, HIGH);
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("foward off");
              forward = "off";
              digitalWrite(FBled, LOW);
            }

            if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("backward on");
              backward = "on";
              digitalWrite(FBled, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("backward off");
              backward = "off";
              digitalWrite(FBled, LOW);
            }

            if (header.indexOf("GET /23/on") >= 0) {
              Serial.println("left on");
              left = "on";
              digitalWrite(LRled, HIGH);
            } else if (header.indexOf("GET /23/off") >= 0) {
              Serial.println("left off");
              left = "off";
              digitalWrite(LRled, LOW);
            }

            if (header.indexOf("GET /33/on") >= 0) {
              Serial.println("right on");
              right = "on";
              digitalWrite(LRled, HIGH);
            } else if (header.indexOf("GET /33/off") >= 0) {
              Serial.println("rght off");
              right = "off";
              digitalWrite(LRled, LOW);
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button1 { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button3 { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button4 {background-color: #555555;}</style></head>");

            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button5 { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button6 {background-color: #555555;}</style></head>");

            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button7 { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button8 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>Remote</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 2 
            client.println("<p>move " + forward + "</p>"); 

            // If the output2 State is off, it displays the ON button       
            if (forward=="off") {
              client.println("<p><a href=\"/2/on\"><button1 class=\"button1\">Forward</button1></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button1 class=\"button1 button2\">Forward</button1></a></p>");
            }

            client.println("<p>move " + backward + "</p>"); 

            if (backward=="off") {
              client.println("<p><a href=\"/27/on\"><button3 class=\"button3\">backward</button3></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button3 class=\"button3 button4\">backward</button3></a></p>");
            } 

            client.println("<p>move " + left + "</p>"); 

            if (left=="off") {
              client.println("<p><a href=\"/23/on\"><button5 class=\"button5\">left</button5></a></p>");
            } else {
              client.println("<p><a href=\"/23/off\"><button5 class=\"button5 button6\">left</button3></a></p>");
            } 

            client.println("<p>move " + right + "</p>"); 

            if (right=="off") {
              client.println("<p><a href=\"/33/on\"><button7 class=\"button7\">right</button7></a></p>");
            } else {
              client.println("<p><a href=\"/33/off\"><button3 class=\"button7 button8\">right</button7></a></p>");
            } 

            client.println("</body></html>");
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
