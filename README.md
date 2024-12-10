![School 42 Banner](https://private-user-images.githubusercontent.com/176421120/394419017-e4708fe5-7157-4430-a765-deed65500a47.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzM4NTg3NzMsIm5iZiI6MTczMzg1ODQ3MywicGF0aCI6Ii8xNzY0MjExMjAvMzk0NDE5MDE3LWU0NzA4ZmU1LTcxNTctNDQzMC1hNzY1LWRlZWQ2NTUwMGE0Ny5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMjEwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTIxMFQxOTIxMTNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04ODc0OGJiNGZiM2E1MGRjNDMzOTUyOGJmZWIzZDJjOWQ0NDg0OWU2YTgzODRhY2QxNmY4MmE3OTc2MzJhYzZlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.li7lTn1CdrHVMBT7_fPhvdXPnhRXMmJL2W2WP3K8hoE)
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