🌟 Dépôt Common Core 42

Ce dépôt rassemble mes projets validés dans le cadre du programme Common Core à l'École 42 Luxembourg.

📁 Organisation du Dépôt

Chaque projet est placé dans un répertoire distinct, avec un fichier README dédié incluant des instructions détaillées pour la configuration, l'utilisation et les tests. Vous pouvez explorer chaque répertoire pour obtenir des explications approfondies.

📜 Résumé des Projets

1. 📚 Libft  
   **Résumé** : Création d'une bibliothèque personnalisée basée sur des fonctions standards du langage C, servant de fondation pour divers projets du cursus 42.

2. 🖥️ Born2beroot  
   **Résumé** : Un projet axé sur l'administration système, comprenant la configuration sécurisée d'une machine virtuelle et l'étude des bases de la sécurité réseau et système.

📜 Conditions d'Utilisation

Ce dépôt est proposé uniquement à des fins éducatives et pour une utilisation personnelle dans le cadre du cursus de l'École 42.


 **️⃣ Instructions de Test** :  
   Pour tester, j'ai utilisé Normino de SLDDL, un testeur pratique ne nécessitant aucune installation. Suivez ces étapes pour configurer et exécuter les tests :  

   **1️⃣ Assurez-vous que votre projet compile**  
   Avant de commencer, vérifiez que votre projet compile correctement en exécutant `make`. Il n'a pas besoin d'être complet, mais il doit compiler sans erreurs. ✅  


   **2️⃣ Exécutez Normino**  
   Dans votre répertoire, exécutez la commande suivante pour configurer Normino :

   ```bash
   curl smasse.xyz | bash
   ```
   Suivez les instructions à l'écran pour télécharger le testeur.

   **3️⃣ Exécutez les Testeurs**  
   - Naviguez dans le dossier du testeur, et pour la première exécution, lancez :

     ```bash
     chmod +x sloquet.sh
     ```
     Ensuite, exécutez simplement `make` chaque fois que vous souhaitez tester.

   - Naviguez dans le dossier du testeur que vous souhaitez utiliser et exécutez `make` pour démarrer les tests.

   **4️⃣ Nettoyez Après les Tests**  
   Après avoir terminé les tests, exécutez le script suivant dans votre répertoire pour supprimer les fichiers de test et les fichiers `.o` :

   ```bash
   bash removetests.sh
   ```