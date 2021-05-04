import time
from watchdog.observers import Observer
from watchdog.events import PatternMatchingEventHandler

# periph = '/dev/ttyACM0'
# baudrate = 9600
# ser = serial.Serial(periph, baudrate)


PATHTOBEOBSERVED = '/Users/jojom/Documents/robotic_project/patrouilleur_web/python'

class Test():
    def __init__(self):
        this.key="key"

    def on_modified(event):
        file = open("python/command.txt", "r")
        command = file.read()
        this.key=command

  
if __name__ == "__main__":

    test = Test()

    patterns = "*"
    ignore_patterns = ""
    ignore_directories = False
    case_sensitive = True
    my_event_handler = PatternMatchingEventHandler(patterns, ignore_patterns, ignore_directories, case_sensitive)
    
    my_event_handler.on_modified = on_modified
 
    path = PATHTOBEOBSERVED
    go_recursively = True

    my_observer = Observer()
    my_observer.schedule(my_event_handler, path, recursive=go_recursively)

    my_observer.start()
    try:
        while True:
            print(test.key)
            time.sleep(0.3)
    except KeyboardInterrupt:
        my_observer.stop()
    my_observer.join() 