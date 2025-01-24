## ABOUT MiniTalk
This is a server/client system that uses UNIX signals for communication. The server displays its PID and receives decrypted signals as characters, while the client encrypts messages and sends true/false signals using SIGUSR1 or SIGUSR2 to the server's PID.

#### 1º - Enter the project folder and run `make` and `make bonus`

#### 2º - Run server or server_bonus and copy its PID
```bash
./server
./server_bonus
```

#### 3º - Open another terminal, run client or client_bonus, paste the PID and write a message
```bash
./client [SERVER PID] ["MESSAGE"]

./client_bonus [SERVER PID] ["MESSAGE"] [EMOTE]
```

#### 2º - Stop execution 
```bash
CTRL + C
```

#### MAKEFILE RULES

`make` - Compile minitalk **mandatory** files.

`make bonus` - Compile minitalk **bonus** files.

`make all` - Compile **mandatory** + **bonus** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
- [x] Produce server and client executables.
- [x] The Client must communicate a string passed as a parameter to the server (referenced by its process ID) and display it.
- [x] Use `SIGUSR1` and `SIGUSR2` signals only.

## BONUS
- [x] Add reception acknowledgement system.
- [x] Support Unicode characters.