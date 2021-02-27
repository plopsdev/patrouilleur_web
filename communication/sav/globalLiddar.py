import rospy
from sensor_msgs.msg import LaserScan
import time

angles = None
ranges = None

def callback(data):
    global angles, ranges
    angle_increment =(data.angle_max-data.angle_min)/(len(data.ranges)-1)
    # Angle without inf
    angles = [data.angle_min + angle_increment*i for i in range(len(data.ranges)) if data.ranges[i] != float("Inf")]
    # Range without inf
    ranges = [data.ranges[i]*1000 for i in range(len(data.ranges)) if data.ranges[i] != float("Inf")]


def listener():
    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('rplidarNode', anonymous=True)
    rospy.Subscriber('/scan', LaserScan, callback)
    
   
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

#if __name__ == '__main__':

