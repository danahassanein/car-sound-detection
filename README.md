# car-sound-detection
  
  
The goal is to measure the sound of passing cars and determine how many cars passed based on the amount of sound produced and captured by the arduino microphone. The MQTT publish-subscribe model allows collects the sensed data sent by the arduino micro-controller and publishes a summary of these data on a MQTT broker. An average car makes about 70dBs of sound, however, in our case, we set the amount to 35 to be able to test it manually. If it sound exceeds the threashold, we assume that a car has passed. We collect this data, calculate the average and maximum noise levels recorded over the last 10 seconds, and publish it. After the data is recieved by the subscriber, we display the results along with the detected pulses on a graph respresented in webPage.html    
  
Tools:  
Arduino IDE  
Anaconda Spyder  
WampServer  
mosquitto on websockets  
