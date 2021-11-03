import os

command = 'cmd /c "mosquitto_sub -p 1182 -t sensedData >> sensedData.txt"'
executed = os.system(command) 


