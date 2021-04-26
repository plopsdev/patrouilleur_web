 #!/usr/bin/env python
import rospy
from std_msgs.msg import String

class Publisher:
    def __init__(self, isBusy=False, key="", command=""):
        self.isBusy = isBusy
        self.key = key
        self.command = command

    def translator(self):
        if self.isBusy :
            if self.command == "z_up" and self.key == "z":
                self.isBusy = False
                return "k"
            elif self.command == "q_up" and self.key == "q":
                self.isBusy = False
                return "k"
            elif self.command == "s_up" and self.key == "s":
                self.isBusy = False
                return "k"
            elif self.command == "d_up" and self.key == "d":
                self.isBusy = False
                return "k"
        
        else : 
            if self.command == "z_down":
                self.key = "z"
                self.isBusy = True
                return "i"
            elif self.command == "q_down":
                self.key = "q"
                self.isBusy = True
                return "j"
            elif self.command == "s_down":
                self.key = "s"
                self.isBusy = True
                return "<"
            elif self.command == "d_down":
                self.key = "d"
                self.isBusy = True
                return "m"

    def talker(self):
        pub = rospy.Publisher('chatter', String, queue_size=10)
        rospy.init_node('talker', anonymous=True)
        rate = rospy.Rate(10) # 10hz
        while not rospy.is_shutdown():
            file = open("python/command.txt", "r")
            self.command = file.read()
            commandToSend = self.translator()
            rospy.loginfo(commandToSend)
            pub.publish(commandToSend)
            rate.sleep()

if __name__ == '__main__':
    try:
        publisher = Publisher()
        publisher.talker()
    except rospy.ROSInterruptException:
        pass

    #uio
    #jkl
    #,;: ou M<>
    #obligé d'appuyer sur k pour qu'il s'arrête (point mort)