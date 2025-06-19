# Minitalk - A Signal-Based Communication Program

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)
![Platform](https://img.shields.io/badge/Platform-UNIX%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)

## 📋 Table of Contents

1.  [About The Project](#-about-the-project)
2.  [Key Features](#-key-features)
3.  [How It Works](#-how-it-works)
4.  [Getting Started](#-getting-started)
5.  [Usage Demonstration](#-usage-demonstration)
6.  [License](#-license)
7.  [Contact](#-contact)

## 🚀 About The Project

Minitalk is a client-server program that demonstrates communication between two processes using only UNIX signals. The project's core challenge is to send a full string of text, including Unicode characters, from a client to a server by encoding each character into a sequence of bits and transmitting them via `SIGUSR1` and `SIGUSR2` signals.

This project showcases a deep understanding of low-level process communication, signal handling, and bitwise operations in C.

## ✨ Key Features

*   **Client-Server Architecture:** A robust server capable of handling messages from multiple clients sequentially.
*   **Signal-Only Communication:** All data transfer is performed using only two UNIX signals, without traditional sockets or pipes.
*   **Bit-by-Bit Transmission:** Characters are broken down into their binary representation and sent one bit at a time.
*   **Message Acknowledgement:** The server sends a confirmation signal back to the client upon successful receipt of a message, enabling two-way communication.
*   **Full Unicode Support:** The server can correctly receive and display multi-byte Unicode characters, such as emojis (e.g., "Hello 👋").

## 🧠 How It Works

1.  The **Server** starts and prints its Process ID (PID).
2.  The **Client** takes the server's PID and a string as arguments.
3.  The client iterates through each character of the string. For each character, it sends its 8 bits one by one.
4.  A `1` bit is sent as a `SIGUSR1` signal; a `0` bit is sent as `SIGUSR2`.
5.  The **Server** listens for these signals and reconstructs the bits back into bytes.
6.  Once the null-terminating character is received, the server prints the complete message.
7.  Finally, upon printing the message, the server sends a confirmation signal back to the client, completing the communication cycle.

## 🛠 Getting Started

### Prerequisites

You need a C compiler (like `gcc` or `clang`) and `make` installed on your system. This project is designed for UNIX-like operating systems.

### Installation & Compiling

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/beratbosnak/Minitalk.git
    cd Minitalk
    ```

2.  **Compile the project using `make`:**
    The following commands are available to manage the project:

    *   `make` or `make all`
        > Compiles the mandatory `client` and `server` executables.
    *   `make bonus`
        > Compiles the bonus `client_bonus` and `server_bonus` executables.
    *   `make clean`
        > Removes the temporary object files (`.o`).
    *   `make fclean`
        > Removes the object files and all executables (`client`, `server`, `client_bonus`, `server_bonus`).
    *   `make re`
        > Re-compiles the mandatory part from scratch by running `fclean` and `all` sequentially.

## 🖥 Usage Demonstration

The following GIFs demonstrate the program in action. You will need two separate terminal windows for the server and the client.

### Base Version

This shows the basic one-way communication. The client sends a message, and the server receives and displays it.

![Minitalk Base Version Demo](./assets/minitalk-base-version.apng)

### Full-Featured Version

This demonstrates the enhanced two-way communication. After the server receives and displays the message, it sends an acknowledgement signal back to the client. This version also handles multi-byte Unicode characters correctly.

![Minitalk Full-Featured Version Demo](./assets/minitalk-full-version.apng)

## 📄 License

This project is distributed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## 📬 Contact

**Berat Boşnak**

*   **LinkedIn:** [linkedin.com/in/beratbosnak](https://www.linkedin.com/in/beratbosnak)

---
