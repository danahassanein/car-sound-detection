##############
## Script listens to serial port and writes contents into a file
##############
## requires pySerial to be installed 
import serial
import os

serial_port = 'COM3';
baud_rate = 9600;
ser = serial.Serial(serial_port, baud_rate)

messageToSend = ""
while True:
    line = ser.readline();
    # print(line)
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    messageToSend = messageToSend + line
    messageToSend = messageToSend.split("\n")[0]
    # print(messageToSend)
    # here we can execute the command to publish the data and check if it was sent or not
    command = 'cmd /c "mosquitto_pub -p 1182 -t sensedData -m "{}""'.format(messageToSend)
    executed = os.system(command) 
    if executed == 0:
        print(command)
        messageToSend = ""
    else:
        messageToSend = messageToSend + " ConnectionError "
