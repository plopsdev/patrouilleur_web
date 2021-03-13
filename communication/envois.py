from time import sleep
from serial import *

def sendData(data, periph = "/dev/ttyACM0", baudrate = 9600):
    # Encode en binaire chaque éléments de data séparément pour l'envoyer
    # à l'arduino car impossible de faire cette opération sur toute une liste en même temps.
    ser = Serial(periph, baudrate)        
    ser.write(data.encode('ascii'))# https://roboticsbackend.com/raspberry-pi-       arduino-serial-communication/
avant = 'a'
tourner = 'b'


x=0
t = 2
while(x<3):
    sleep(t)
    print(avant)
    sendData(avant)
    sleep(t)
    sendData(tourner)
    print(tourner)
    x += 1
