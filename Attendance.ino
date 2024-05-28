#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <LittleFS.h>
#include <ZipFile.h>

const char* ssid = "IT Attendance";
const char* password = "vjit@123";
const char* adminPassword = "admin";

ESP8266WebServer server(80);

// Structure to store attendance records
struct AttendanceRecord {
  unsigned long timestamp;
  String name;
  String roll;
  String photo;
};

DynamicJsonDocument attendanceData(1024);

void setup() {
  // Start the serial connection
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize LittleFS (the file system on ESP8266)
  LittleFS.begin();

  // Serve the student attendance page
  server.on("/", HTTP_GET, serveStudentAttendancePage);

  // Handle student attendance form submission
  server.on("/submit", HTTP_POST, handleAttendanceForm);

  // Serve teacher view attendance page and provide attendance data
  server.on("/view", HTTP_GET, serveTeacherViewPage);
  server.on("/attendance", HTTP_GET, provideAttendanceData);

  // Handle attendance data and photos download
  server.on("/download", HTTP_GET, handleDownload);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void serveStudentAttendancePage() {
  File file = LittleFS.open("/student-attendance.html", "r");
  if (file) {
    server.streamFile(file, "text/html");
    file.close();
  } else {
    server.send(500, "text/plain", "Internal Server Error");
  }
}

void handleAttendanceForm() {
  // Your existing code for handling attendance form submissions
  // ...

  // Response to the student
  server.send(200, "text/plain", "Attendance recorded");
}

void serveTeacherViewPage() {
  File file = LittleFS.open("/teacher-view.html", "r");
  if (file) {
    server.streamFile(file, "text/html");
    file.close();
  } else {
    server.send(500, "text/plain", "Internal Server Error");
  }
}

void provideAttendanceData() {
  String data;
  serializeJson(attendanceData, data);
  server.send(200, "application/json", data);
}

void handleDownload() {
  if (server.hasArg("password") && server.arg("password") == adminPassword) {
    // Create a ZIP file to store the photos folder
    ZipFile zip = ZipFile(server);
    zip.addFolder(LittleFS, "/photos");

    // Set the HTTP headers for the ZIP file
    server.sendHeader("Content-Disposition", "attachment; filename=attendance-photos.zip");
    server.send(200, "application/zip", "");
  } else {
    server.send(403, "text/plain", "Access Denied");
  }
}