# cub3d

# Roadmap

1. Finaliser le parsing
	- [x] Finir de tester parsing.c
	- [x] A la fin de cette partie, faire la premiere release 0.01
2. Workflow setup
	- [ ] Tout les pushs seront des itérations de la versions precédente a partir de 0.01
	- [ ] Création de la fenêtre et appel de la fonction *raycasting* dans le main.
	- [ ] Fermeture de la fenetre par ESC ou par la croix rouge.
	- [ ] Affichage d’une string par touche appuyer si -debug pour verifier que toute les touches sont bien détecté et géré.
	- [ ] Si KEY_DEBUG est appuyé, change l’état stock->debug
	- [ ] Push quand même une image avec un carré dessiné, C’est juste pour faire un push_img.
	- [ ] Si la resolution du .cub est plus grande que celle de l’écran, lancer la fenetre en full screen.
	- [ ] Faire un main qui appel la fonction qui va créer t_info. Si le premier argument est -debug, le main doit afficher t_info et la variable `t_bool debug` dans t_info sera mise à 1. Cette variable sera a copier dans t_stock.
	- [ ] Fonction qui va init la grosse structure t_stock a partir de t_info.
	- [ ] A la fin de cette partie faire la premiere release 0.1.
3. Raycasting
	- [ ] continuité des 0.X
	- [ ] rendu du sol et du plafond
	- [ ] rendu des murs en couleurs
	- [ ] collision contre les murs
	- [ ] Quand le rendu des murs, des couleurs, du background est sans fish-eye et sans probleme push la release 1.0
4. Reste de la partie obligatoire
	- [ ] chaque push sans feature sera un 0.0X
	- [ ] chaque push avec feature sera un 0.X
	- [ ] rendu des textures des murs
	- [ ] si debug == 1 ne pas afficher les textures.
	- [ ] rendu des sprites
5. Partie Bonus
	- [ ] texture des murs
	- [ ] collision avec les murs (Normalement faites dans la partie 3)
	- [ ] une mini-map
