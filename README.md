![School 42 Banner](https://github.com/Greatspot/banners/blob/main/github_piscine_and_common_core_banner_common_core.png)

# 🌟 42 Common Core Repository

The 42 Common Core was developed in Paris in 2013 and is continually evaluated and developed. Students progress through the program by completing projects and earning points to level up, making the learning experience feel like a game.
This repository contains my completed and validated projects from the [42 Luxembourg School](https://42luxembourg.lu/fr/accueil/) Common Core curriculum.


# ⚙️ How to Test Projects

For testing, I used [SLDDL's Normino](https://github.com/SLDDL/Normino), a convenient, no-installation-required tester. Follow these steps to set up and run the tests:

### 1️⃣ **Ensure Your Project Compiles**

- Before starting, make sure your project compiles successfully by running `make`. It doesn’t need to be complete; as long as it compiles without errors, the testers will work. ✅


### 2️⃣ **Run Normino**

In your directory, execute the following command to set up Normino:

   ```bash
   curl smasse.xyz | bash
   ```

Follow the on-screen instructions to download the tester you need.

### 3️⃣ **Run Testers**

- Navigate to the folder of the tester, first time you run it, run:

    ```plaintext
    chmod +x sloquet.sh
    ```
    after that you can just run `make` everytime you want to test.

- Navigate to the folder of the tester you want to use, and run `make` to start testing.

### 4️⃣ **Cleanup After Testing**

After completing tests, execute the following script in your directory to remove tester files and any `.o` files:

   ```bash
   bash removetests.sh
   ```


## 📜 License

This repository is intended for educational and personal reference as part of the 42 School program.