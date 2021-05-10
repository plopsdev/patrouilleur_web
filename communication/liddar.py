import rospy
from sensor_msgs.msg import LaserScan
from time import time


class Liddar:
    """
    Classe gérant le liddar et permettant de récupérer les valeurs 
    une fois le liddar lancé sur ros.
    
    Lancement du liddar, lancer les commandes suivantes une fois le liddar connecté :
        1) ls -l /dev | grep ttyUSB 
                si on a crw-rw-----, alors il faut lancer : sudo chmod 666 /dev/ttyUSB0
                sinon, on ne fait rien.
        2) cd ~/catkin_ws/
        3) catkin_make
        4) source devel/setup.bash
        5) roslaunch rplidar_ros rplidar.launch
        
        Diverse commmande lié à ros :
            - Pour vérifier qu'il fonctionne et afficher une suite de valeur : rostopic echo /scan
            - Pour voir les processus actif de ros : ps aux|grep ros
        
    """
    def __init__(self):
        self.angles = None
        self.ranges = None

    def __callback(self, data):
        angle_increment =(data.angle_max-data.angle_min)/(len(data.ranges)-1)
        # Angle without inf
        self.angles = [data.angle_min + angle_increment*i for i in range(len(data.ranges)) if data.ranges[i] != float("Inf")]
        # Range without inf
        self.ranges = [data.ranges[i]*1000 for i in range(len(data.ranges)) if data.ranges[i] != float("Inf")]


    def __listener(self):
        # In ROS, nodes are uniquely named. If two nodes with the same
        # name are launched, the previous one is kicked off. The
        # anonymous=True flag means that rospy will choose a unique
        # name for our 'listener' node so that multiple listeners can
        # run simultaneously.
        rospy.init_node('rplidarNode', anonymous=True)
        rospy.Subscriber('/scan', LaserScan, self.__callback)
     
    def get_values(self, waintingTime = 3):
        """ 
        Cette fonction permet d'obtenir les valeurs range et angle du liddar. 
      
        Parameters: 
            waintingTime (int) : Le temps d'attente max pour obtenir les données du capteur.
      
        Returns: 
            list[list[float], list[float]] : Retourne une liste contenant comme première argument 
            une liste de toutes les valeurs concernant les ranges et en second une liste des angles.      
        """
        oldTime, currentTime = time(), time()
        timeElapsed = currentTime - oldTime
        
        while waintingTime >= timeElapsed :
            currentTime = time()
            timeElapsed = currentTime - oldTime
            
            self.__listener()
            ranges = self.ranges
            angles = self.angles
            
            if(angles != None and ranges != None):
                return [ranges, angles]
            
