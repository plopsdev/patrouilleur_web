from paramiko import SSHClient, AutoAddPolicy
"""
result = Connection('web1.example.com').run('uname -s', hide=True)
msg = "Ran {0.command!r} on {0.connection.host}, got stdout:\n{0.stdout}"
print(msg.format(result))
from fabric import Connection
"""
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
"""
