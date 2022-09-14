# transcribe-python-app


Simple Python script to do real-time speech to text translation. Talk into microphone, the script will in realtime send the audio to AWS transcribe using the Transcribe API. The audio is converted into text and returned to the script for handling. Currtently the script prints all returned text to screen. It examines the returned text looking for the key work that will trigger an action to the ESP32 servo. Once it detects the key work has been spoken, it initilises the communication with the ESP32 device by sending a HTTP Post to the API gateway we have deployed by sam-lambda-iot-rule.

Based on this: https://github.com/awslabs/amazon-transcribe-streaming-sdk

## Prerequisites

You will need AWS CLI installed on your laptop. 

Ensure that the AWS CLI is configured with a user that has necessary IAM permissions to access Transcribe. 

I created a user and enabled **Programmatic access**

Then use the created Access Key ID and Secret access key to configure the AWS CLI. 

Here is the policy I used to allow Transcribe access. Note you should add further restrictions to this for increased security.

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


* Note * I have tested this on Mac OS and windows terminals. 



