# minitalk

![minitalk](https://img.shields.io/badge/minitalk-IPC%20Project-blue.svg)

## 📌 Project Description
`minitalk` is a project that demonstrates inter-process communication (IPC) using UNIX signals. It consists of a client and a server that communicate by sending signals (`SIGUSR1` and `SIGUSR2`) to transmit messages.

## 📂 Features
- Implements communication between two processes using signals.
- Supports sending string messages from the client to the server.
- Uses `SIGUSR1` and `SIGUSR2` to encode data.
- Handles signal interruptions and ensures correct message transmission.
- **Bonus:** Supports Unicode characters and additional features.

## ⚙️ Installation
Compile the project using the `Makefile`:

```sh
make
```

To compile the bonus version:
```sh
make bonus
```

## 🚀 Usage
### 1️⃣ Start the Server
Run the server first to obtain its process ID (PID):

```sh
./server
```

The server will display its PID, for example:
```
Server PID: 12345
```

### 2️⃣ Send a Message from the Client
Use the client to send a message to the server by providing the server's PID and the message:

```sh
./client 12345 "Hello, Minitalk!"
```

### Example Output
#### Server Output:
```
Received message: Hello, Minitalk!
```

### 🔥 Bonus Features
The bonus version extends the basic functionality by supporting:
- Unicode character transmission.
- More robust signal handling.
- Additional functionalities for enhanced communication.

#### Example Usage (Bonus):
```sh
./server_bonus
```

```
Server PID: 54321
```

```sh
./client_bonus 54321 "🚀 Minitalk Bonus!"
```

#### Bonus Server Output:
```
Received message: 🚀 Minitalk Bonus!
```

## 📜 License
This project is licensed under the **[MIT License](LICENSE)**.

## 📧 Contact
For any questions or feedback, feel free to reach out via GitHub!

