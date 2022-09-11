## Connecting ESP32 to AWS IoTCore ##


### Solution overview ### 

To setup an IoT device, in this case the ESP32, to communicate securely with AWS IoTCore, follow the steps shown below. This involves the following steps.

- Create an AWS IoT device in AWS IoTCore. 
- Setup the Arduino IDE for ESP32
- Program the ESP32 with the device code
- Monitor and test ESP32 can send and receive data from IoTCore. 


### Step 1  Creating an AWS IoT device ### 


In the AWS IoT Core console, go to Manage -> Things. 
Choose "Create Things"
Choose "Create a single thing"
Under "Specify thing properties" give the thing a name, for example ESP32-00001. Leave the remaining values set to their default. Click "Next".
Under "Configure device certificate" select "Auto-generate a new certificate" and click "Next".
Under "Attach policies to certificate" select create a new policy. 








 Choose Create certificate. Only the thing cert, private key, and Amazon Root CA 1 downloads are necessary for the ESP32 to connect. Download and save them somewhere secure, as they are used when programming the ESP32 device.
Choose Activate, Attach a policy.
Skip adding a policy, and choose Register Thing.
In the AWS IoT console side menu, choose Secure, Policies, Create a policy.
Name the policy Esp32Policy. Choose the Advanced tab.
Paste in the following policy template.






### Step 2  Setup the Arduino IDE for ESP32 ### 

###  Step 3  Program the ESP32 with the device code ### 

###  Step 4  Monitor and test ESP32 ### 

