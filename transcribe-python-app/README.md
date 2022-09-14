# transcribe-python-app


Simple Python script to do real-time speech to text translation. Talk into microphone, the script will in realtime send the audio to AWS transcribe using the Transcribe API. The audio is converted into text and returned to the script for handling. Currtently the script prints all returned text to screen. It examines the returned text looking for the key work that will trigger an action to the ESP32 servo. Once it detects the key work has been spoken, it initilises the communication with the ESP32 device by sending a HTTP Post to the API gateway we have deployed by sam-lambda-iot-rule.

Based on this: https://github.com/awslabs/amazon-transcribe-streaming-sdk

## Prerequisites

You will need AWS CLI installed on your laptop. 

Ensure that the AWS CLI is configured with a user that has necessary IAM permissions to access Transcribe. 

I created a user in AWS IAM (with **Programmatic access**), and added the following policy. Configure AWS CLI with this user. 

Here is the user policy. 

```
{
    "Version": "2012-10-17",
    "Statement": [
        {
            "Effect": "Allow",
            "Action": [
                "transcribe:*"
            ],
            "Resource": "*"
        }
    ]
}
```






## Setup

The steps below will:

Install the AWS Transcribe SDK. 
Install other libraries required. 

```
python -m pip install amazon-transcribe aiofile

python -m pip install sounddevice

python -m pip install requests

```
*Note* I have tested this on Mac OS and windows terminals. 


## Test

Run the pything script and verify it runs without errors.

Talk into you laptop microphone, verify that your speech is being converted into text and returned to the python script. 

Update the python script if required, to reflect the voice command that you want to use to send the command to the Iot device. In the same script provided, I am checking for the word "balloon". When I detect that, you will see that the script then calls the API gateway via the HTTP request, which triggers an MQTT message to the IoT device. The IoT device will then perform the necessary action. 
Update the script to suit your requirements, for example you may want to change the key work. 


Congradulations, you have now used AWS Transcribe service, to control an IoT device. 










