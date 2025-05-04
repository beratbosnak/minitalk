# 📡 minitalk – Signal-based Communication Between Processes in C

![minitalk](https://img.shields.io/badge/minitalk-process%20communication-blue.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue)
![Made with C](https://img.shields.io/badge/made%20with-C-blue)

## 📑 Table of Contents

* [Project Description](#-project-description)
* [How It Works](#️-how-it-works)
* [Compilation](#️-compilation)
* [Usage](#-usage)
* [Expected Output](#-expected-output)
* [Bonus Part](#-bonus-part)
* [Expected Output (Bonus)](#-expected-output-bonus)
* [Project Structure](#-project-structure)
* [License](#-license)
* [Contact](#-contact)

---

## 📌 Project Description

**minitalk** is a project that implements simple client-server communication using UNIX signals (`SIGUSR1` and `SIGUSR2`).

The client sends a message to the server one bit at a time, using signals to encode characters. The server reconstructs the message from these signals and prints it to the standard output.

> 🧠 This project was built to strengthen my low-level programming skills in C by implementing signal-based inter-process communication using bitwise operations and asynchronous message handling.

---

## ⚙️ How It Works

* The **server** starts and displays its PID.
* The **client** sends a string message to the server by converting each character to binary:

  * Sends `SIGUSR1` for bit `1`
  * Sends `SIGUSR2` for bit `0`
* The server catches signals using `sigaction`, reconstructs characters, and prints the received message.

---

## ⚙️ Compilation

Run the following commands to build the project:

```bash
git clone https://github.com/valyriasteel/minitalk.git
cd minitalk
make
```

This will compile both `server` and `client` executables.

Other useful commands:

```bash
make clean   # Remove object files
make fclean  # Remove all binaries and object files
make re      # Rebuild everything from scratch
make bonus   # Compile the bonus version (with acknowledgments)
```

---

## 🚀 Usage

Start the server first:

```bash
./server
```

It will display its PID. Then, in another terminal, run the client with the server's PID and your message:

```bash
./client <server_pid> "Your message here"
```

> 🧪 Example:

```bash
./server
# Output: PID: 12345

./client 12345 "Hello, minitalk!"
```

---

## 📤 Expected Output

If you run the above example, the server will print:

```
Hello, minitalk!
```

---

## 🎁 Bonus Part

The bonus implementation includes:

* **Acknowledgment signals** from server to client after each byte
* **Unicode character support** (extended character sets)
* Separate source files:

  * `server_bonus.c`
  * `client_bonus.c`

Compile and run bonus version with:

```bash
make bonus
./server_bonus
./client_bonus <server_pid> "Unicode ✓ Test"
```

## 📤 Expected Output (Bonus)

```
Unicode ✓ Test
```

---

## 📁 Project Structure

All files are located in the root directory:

```
minitalk/
├── client.c           # Client implementation
├── server.c           # Server implementation
├── minitalk.h         # Header file
├── minitalk_utils.c   # Shared utility functions
├── client_bonus.c     # Bonus client with acknowledgments
├── server_bonus.c     # Bonus server
├── Makefile           # Build script
└── README.md          # Documentation
```

---

## 📜 License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

---

## 📬 Contact

For questions, issues, or contributions:

* GitHub: [valyriasteel](https://github.com/valyriasteel)
* Feel free to open an [issue](https://github.com/valyriasteel/minitalk/issues) or [pull request](https://github.com/valyriasteel/minitalk/pulls)!

> 📝 *This project and its documentation are written in English to ensure accessibility for a global audience.*

---

**Keywords**: minitalk, signals, IPC, process communication, bitwise operations, UNIX signals, 42 school project
