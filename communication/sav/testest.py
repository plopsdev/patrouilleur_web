from rplidar import RPLidar
from time import sleep


lidar = RPLidar('/dev/ttyUSB0')


sleep(5)

for i in lidar.iter_scans():
    print('%d : measurments' % (i))




lidar.stop()
lidar.stop_motor()
lidar.disconnect()

