import remote_control, envois_array, liddar

# Format pour permettre aux données d'être envoyées
envois = ['600', '700', '14']
send_data(envois)

# Commande que vous voulez lancer.
com1 = "touch Desktop/preuve.txt"
send_command_to_raspberry(com1)

# Récupèration des données du liddar UNE FOIS LANCE SUR LE RASPB.
lid = Liddar()
for e in lid.get_values():
    print(e)
    print('\n --------------------------------------------- \n')