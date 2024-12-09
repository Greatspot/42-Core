# 📚 Libft

## 🛠️ Instructions de Test

Pour tester, j'ai utilisé [Normino de SLDDL](https://github.com/SLDDL/Normino), un testeur pratique qui ne nécessite aucune installation. Suivez ces étapes pour configurer et exécuter les tests :

### 1️⃣ **Assurez-vous que votre projet compile**

   Avant de commencer, assurez-vous que votre projet compile correctement en exécutant `make`. Il n'a pas besoin d'être complet ; tant qu'il compile sans erreurs, les testeurs fonctionneront. ✅

### 2️⃣ **Téléchargez les Testeurs (via Normino)**

   Dans votre répertoire **libft**, exécutez la commande suivante pour configurer Normino. Les tests seront téléchargés dans ce répertoire.

   ```bash
   curl smasse.xyz | bash
   ```
   
   Suivez les instructions affichées à l'écran pour télécharger le testeur **libft**.

### 3️⃣ **Ajoutez une Règle de Compilation pour la Bibliothèque Dynamique à votre Makefile**

   Ajoutez la règle suivante à votre Makefile pour activer la compilation de la bibliothèque dynamique :

   ```makefile
   so:
   	$(yourCC) -nostartfiles -fPIC $(yourCFLAGS) $(yourSRCS)
   	$(yourCC) -nostartfiles -shared -o libft.so $(yourOBJS) $(yourBONUS_OBJS `only if doing bonus`)
   ```

   🔍 **Astuce** : Les valeurs dans `$(...)` peuvent varier selon la configuration de votre Makefile. Mettez à jour ces valeurs en fonction de votre configuration.

### 4️⃣ **Nettoyez Avant d'Exécuter les Tests**

   Exécutez `make fclean` et supprimez tout fichier `libft.so` existant avant chaque exécution des tests pour éviter les conflits. 🧹

### 5️⃣ **Exécutez les Testeurs**

   Maintenant que vous avez les tests dans votre répertoire **libft**, naviguez dans le dossier du testeur que vous souhaitez utiliser et exécutez `make` pour commencer les tests. Assurez-vous de refaire **l'Étape 4** avant chaque exécution de test pour obtenir les meilleurs résultats.

### 6️⃣ **Nettoyez Après les Tests**

   Après avoir terminé les tests, exécutez le script suivant dans votre répertoire **libft** pour supprimer les fichiers de test et tout fichier `.o` :

   ```bash
   bash removetests.sh
   ```

   🗑️ **Nettoyage Supplémentaire** : Supprimez également le fichier `a.out` généré par les testeurs. Vérifiez toujours que votre dépôt ne contient pas de fichiers supplémentaires avant de soumettre votre projet !
