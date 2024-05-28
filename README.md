
# Automated Attendance System using Node MCU

This project involves creating an automated attendance system using Node MCU and WiFi technology. The system is designed to streamline the process of marking attendance by detecting the presence of students through WiFi signals.

## Features

- **Automated Attendance**: Automatically marks attendance when a student connects to the WiFi network.
- **Node MCU Integration**: Utilizes Node MCU for managing WiFi connections and data transmission.
- **Real-Time Tracking**: Provides real-time updates on student attendance.

## Requirements

- Node MCU
- WiFi Module
- Arduino IDE
- Server for data storage (e.g., Firebase)

## Installation

1. **Set up Node MCU**:
   - Connect the Node MCU to your computer.
   - Install the necessary drivers.
   - Open Arduino IDE and configure it to recognize Node MCU.

2. **Install Required Libraries**:
   - Install the ESP8266WiFi library.
   - Install the Firebase library (or any other server library you are using).

3. **Upload Code to Node MCU**:
   - Write the Arduino sketch to manage WiFi connections and attendance data.
   - Upload the sketch to Node MCU using Arduino IDE.

4. **Set Up Server**:
   - Configure a server to receive and store attendance data.
   - Ensure the server is running and accessible to Node MCU.

## Usage

1. **Power the Node MCU**:
   - Connect the Node MCU to a power source.
   - Ensure it is within the range of the WiFi network.

2. **Connect to WiFi**:
   - Node MCU will automatically connect to the specified WiFi network.
   - Attendance will be marked when students’ devices connect to the WiFi.

3. **Monitor Attendance**:
   - Access the server to view real-time attendance data.
   - Use the data for record-keeping and analysis.

## Contributing

Feel free to fork this repository and contribute by submitting pull requests. For major changes, please open an issue first to discuss what you would like to change.



