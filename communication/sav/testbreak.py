#from classLiddar import *
from time import time
print(time())
lid = Liddar()

x=0

while x<10000:
    lid.listener()
    
    ranges = lid.ranges
    angles = lid.angles
  
    if(angles != None and ranges != None):
        print(angles)
        print('-------------------------------')
        print(ranges)
        print('-------------------------------')
        break
    x+=1
