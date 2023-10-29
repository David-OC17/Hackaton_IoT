# IoT Hackathon
# Repository for Obstacle Avoidance and Fire Detection Robot

This GitHub repository contains the code and resources related to an exciting ESP32-based robot project designed to navigate a maze while searching for an infrared light source and avoiding obstacles. The project focuses on programming and controlling the robot using infrared and ultrasonic sensors to achieve its objective.

## Project Description

This project revolves around the creation of a robot that utilizes an ESP32 microcontroller and is equipped with two types of sensors: infrared and ultrasonic. The robot's challenge is to navigate through a maze and find the infrared light source while avoiding obstacles detected by the infrared sensors.

The maze that the robot has to solve consists of a space delimited with tall walls, as tall as the robt, a lumenecent objective at the end of the maze, and short obstacles the robot must avoid to get to the other side.

## Resources for users

The competitors will be given several libraries to simplify the development of the project, and so they can focus on building the algorithm that enables the robot to traverse the maze.

- **Cloud Connectivity Library:** A library that simplifies the robot's connection to the cloud, enabling data transmission and the possibility of remote control.

- **Motor control:** A library that contains functions for controlling the motors in simple ways the robot may move. Examples are moveForward and rotate90 (degrees*).

- **Sensor Reading Library:** A library that allows for reading data from the infrared and ultrasonic sensors, which is essential for the robot's operation.

- **Comprehensive Kit with Connection Diagrams:** We offer a complete kit that includes detailed connection diagrams required for assembling the robot. This makes replicating the project straightforward.

## Setting the project up

The project is programmed for a ESP32, but can be migrated (and will be for the hackathon) to the use of a ESP8266. The board connects via WiFi to Blynk, am IoT platform for remote monitoring and control of devices. This project was developed using PlatformIO in Vscode, and thus it is recomended for the user to that setup as well.

The most general steps needed to be able to use the code found in the repository are:
1. Download Vscode + PlatformIO
2. Set up C++ (compiler and such)
3. Set up a Blynk account and create a virtual device to which to connect
4. Set up the hardware
5. Compile and upload the code
6. Try the robot out on the maze!

I provide some scripts to test the individual components and functions (motors, sensors, and movement functions). Use them to fine-tune and adjust speeds, delays and pins as needed.