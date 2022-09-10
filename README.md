# aws-transcribe-iotcore-lego

![My Image](photo1.png)


This project connects AWS Transcribe, a service that converts voice audio to text, to AWS IoT Core, a service used for secure
communications with Iot devices. This means we can control our IoT device with voice commands. 
The ESP32 device is connected to an SG90 Servo motor, which in turn is used to control the lego rebot. The device can of course do any other action, just replace the robot part of the device code if required. For example you could just flash a LED instead of controlling a servo. But thats not as much fun ;-) The ESP32 uses WIFI for connectivity, the local WIFI network access details are stored in the ESP32 secrets.h file. Also stored in secrets.h file are the x.509 certificates used for the secure MQTT communication.

The following code will be provided in this project. The solution contains the following 3 components.

Device Code : The **esp32-device-code** folder contains the ESP32 device code, an Arduino C program to run on the ESP32 IoT device. The ESP32 device subsribes to a topic to listen for incoming messages. When it receives an incoming message, it performs the neccesary action to move the servo motor. It also publishes messages to an MQTT topic in IoTCore. For this excercise, we only need to receive messasges in the ESP32, feel free to disable the publising if you want. 

AWS Infrastructure : This is deployed with AWS Serverless Application Model (SAM). The **sam-lambda-iot-rule** folder contains the SAM deployment for AWS, see its readme for details on how to deploy. It sets up the complete backend infrastructure to handle both receiving and sending of IoT events. This includes provisioning API Gateway, DynamoDB database, 2 Lambda functions (one for receiving and one for publishing MQTT events), IoT rules and also the necessary policies/roles etc.   

Application : The **transcribe-python-app** folder contains the Python script to run on the computer that the users microphone is connected to. It streams the audio up to AWS transcribe using API, and processes the returned text version of the audio. It analises the returned text, and when it detects the key word has been said, it will send a HTTP Post request to the API Gateway which triggers an MQTT event for the ESP32. The ESP32 then turns the servo on to control the robot. 


Here is a digram of the overall architecture. Please read the readme file associated with each of the 3 components. 

![My Image](architectureAll.png)
