# transcribe-python-app


Simple Python script to do real-time speech to text translation. Talk into microphone, the script will in realtime send the audio to AWS transcribe using the Transcribe API. The audio is converted into text and returned to the script for handling. Currtently the script prints all returned text to screen. It examines the returned text looking for the key work that will trigger an action to the ESP32 servo. Once it detects the key work has been spoken, it initilises the communication with the ESP32 device by sending a HTTP Post to the API gateway we have deployed by sam-lambda-iot-rule.

Based on this: https://github.com/awslabs/amazon-transcribe-streaming-sdk

Setup

python -m pip install amazon-transcribe aiofile

python pip install sounddevice

Ensure AWS CLI configured with necessary IAM user details.

* Note * I have tested this on Mac OS terminal, but you can use any environment. 
