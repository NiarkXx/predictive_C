================== SMS PREDICTIVE - V1.0 - 15_04_2018 ==================
Contient :
- Makefile
- dictionnaire.txt
- main.c
- smsProf.txt
- smsRegister.txt
- bibli_doc.c
- bibli_doc.h
- bibli_pred.c
- bibli_pred.h
 
 
=================== DESCRIPTION ====================
 
Ce programme permet de simuler une saisie prédictive de texte en émulant la technologie T9.

Sur le menu, l'utilisateur plusieurs choix :
- Activer/Désactiver la saisie prédictive
- Ecrire un sms
- Lire ses sms
- Ajouter un mot dans le dictionnaire prédictif
- Supprimer un mot dans le dicionnaire prédictif
- Modifier un mot dans le dictionnaire prédictif
- Quitter le programme

A chaque lettre saisie, une liste de 3 mots est proposée à l'utilisateur. Il peut alors
sélectionner un des 3 mots. Sinon, l'utilisateur peut continuer à écrire.
Lorsque le programme détecte un espace entre 2 mots (signifiant la fin de l'écriture
du mot d'intérêt par l'utilisateur).
A la fin du sms, l'utilisateur appuie sur la toucge ENTER, qui simule l'envoie du sms. 
On lit alors chacun des mots contenus dans le sms pour les ajouter dans le dictionnaire prédictif, à 
condition que le mot existe dans le dictionnaire français. S'il est déjà présent dans le
dictionnaire prédictif, on incrémente alors l'occurence de ce mot. Sinon, on ajoute le mot avec
une occurence de 1.
 
 
=================== Utilisation ====================
1) Placez vous dans le dossier racine predictive_c
2) Ouvrez un terminal dans ce dossier
3) Tapez la commande : Make
4) Une fois la compilation terminée, tapez la commande : ./smspred
5) L'application démarre alors.
 
 
=================== Auteurs ====================
Ludovic Barbier     : ISMIN 1A
Tomas Barbe         : ISMIN 1A
