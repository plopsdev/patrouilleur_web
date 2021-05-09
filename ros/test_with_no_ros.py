import time

class PublishThread:
  def __init__(self):
    self.isBusy = False
    self.command_in = ""
    self.command_out = ""
    self.current_key = ""

  def getKey(self):
        file = open("C:/Users/jojom/Documents/robotic_project/patrouilleur_web/python/command.txt", "r")
        self.command_in = file.read()
        key = self.translator()
        time.sleep(0.1)
        return key

  def translator(self):
        if self.isBusy :
            if self.command_in == "z_up" and self.current_key == "z":
                self.isBusy = False
                self.command_out = "k"
            elif self.command_in == "q_up" and self.current_key == "q":
                self.isBusy = False
                self.command_out = "k"
            elif self.command_in == "s_up" and self.current_key == "s":
                self.isBusy = False
                self.command_out = "k"
            elif self.command_in == "d_up" and self.current_key == "d":
                self.isBusy = False
                self.command_out = "k"
        
        else: 
            if self.command_in == "z_down":
                self.current_key = "z"
                self.isBusy = True
                self.command_out = "i"
            elif self.command_in == "q_down":
                self.current_key = "q"
                self.isBusy = True
                self.command_out = "j"
            elif self.command_in == "s_down":
                self.current_key = "s"
                self.isBusy = True
                self.command_out = "<"
            elif self.command_in == "d_down":
                self.current_key = "d"
                self.isBusy = True
                self.command_out = "m"


if __name__=="__main__":
  pub_thread = PublishThread()

  while(1):
    pub_thread.getKey()
    key=pub_thread.command_out
    
    print(key)
