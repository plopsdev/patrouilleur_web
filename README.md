# patrouilleur_web
Projet d'un robot patrouilleur ayant comme but de circuler dans un endroit fermé et de détecter une présence humaine.

## Arduino
Ce dossier regroupe l'ensemble des codes arduino qui permettent principelements de diriger le robot. Il contient le contrôle des moteurs via un pid, les capteurs et détecteurs pour connaître la position des roues ainsi que recevoir des informations.

## Client
Cette partie contient le code react gérant le serveur. La méthode pour démarrer le serveur ainsi que l'installation des dépendances pour son bon fonctoinnement y sont expliqué. 

## Communication
Dans cette section est regroupé l'ensemble des fichiers expliquant comment tuer un process ros, gérer le lidar, le remote control via python, la possibilité d'effectuer une com python/arduino ainsi que le démarrage automatique de fichier sous ubuntu.

## Python
Ici se trouve la partie gérant la réception, le traitement ainsi que la mise à jours des commandes envoyées à distance ainsi que le fichier sauvegardant la dernière envoyée.

## ros
Il contient un code python gérant la communication avec ros, consistant principalement en une classe de suscribtion à un noeud ros pour la réceptions de commande envoyées à distance.

## server
Observe quand le contenu du fichier de commande est modifier pour l'envoyer vers la partie front du serveur dans le dossier client.
