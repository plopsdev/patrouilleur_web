from paramiko import SSHClient, AutoAddPolicy

ip = "patrouilleur@192.168.1.50"
port = 22
user = "patrouilleur"
password = "pat2021"

client = SSHClient()
client.load_system_host_keys()
#client.set_missing_host_key_policy(AutoAddPolicy())
client.connect(hostname=ip, port=port, username=user, password=password)
stdin, stdout, stderr = client.exec_command('ls -l')
client.close()