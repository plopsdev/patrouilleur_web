import fabric

def send_command_to_raspberry(command, host ="192.168.1.50", port=22, user="patrouilleur", connect_kwargs={'password': 'pat2021'}):
    c = fabric.Connection(host = host,
                          port=port,
                          user=user,
                          connect_kwargs=connect_kwargs)
    c.run(command)

"""
from paramiko import SSHClient, AutoAddPolicy

ip = 'patrouilleur@192.168.1.50'
port = 22
user = 'patrouilleur'
password = 'pat2021'

client = SSHClient()
#client.load_host_keys()
client.load_system_host_keys()
client.set_missing_host_key_policy(AutoAddPolicy())
client.connect(hostname=ip, port=port, username=user, password=password)
stdin, stdout, stderr = client.exec_command('ls -l')
client.close()
"""
