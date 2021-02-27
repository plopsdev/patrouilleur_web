from classLiddar import *

lid = Liddar()

x=0

while x<10:
    y = 0
    while y<800:
            lid.listener()
            y+=1
    
    ranges = lid.ranges
    angles = lid.angles
    
    if(angles == None or ranges == None):
        ranges = 0
        angles = 0
        #if(len(angles) != 0 or len(ranges) != 0):
    print(ranges)
    print('---------------------------')
    #print(angles) 
    print('---------------------------')
    print('---------------------------')
    x+=1
