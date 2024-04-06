def mywrite(mystr):
    #ser.write(bytes(mystr,'utf-8'))
    ser.write('Hello, ser!'.encode())


import serial
import time


ser = serial.Serial('COM4', 9600, timeout=10)
# ser = serial.Serial('/dev/ttyACM0', 9600)

time.sleep(5)

while(True):
    mywrite(input().strip())

ser.close()
