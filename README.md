# Go-Back-N ARQ Simulation

This project simulates the Go-Back-N Automatic Repeat reQuest (ARQ) protocol using C++. The simulation consists of two main components: a sender and a receiver. The sender transmits frames, while the receiver acknowledges the frames it receives. This implementation demonstrates how frames are sent, acknowledged, and how the sender handles timeouts and retransmissions.

## Features

- Simulates sending and receiving frames.
- Implements a sliding window protocol for the sender.
- Handles out-of-order frame reception and duplicate ACKs.
- Simulates network delays and timeouts.

## Requirements

- C++11 or higher
- A C++ compiler (e.g., g++, clang++)

## How to Build and Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/go-back-n-cpp.git
   cd go-back-n-arq-simulation
   ```

2. **Compile the code:**
   ```bash
   g++ -o go_back_n_cpp main.cpp -lpthread
   ```

3. **Run the simulation:**
   ```bash
      ./go_back_n_cpp
   ```

## Code Explanation

- **Sender Process:** 
- Sends frames while maintaining a window of frames that can be sent without waiting for an acknowledgment.
- Handles timeouts and retransmits frames if an acknowledgment is not received in time.

- **Receiver Process:**
- Receives frames and acknowledges them if they are in order.
- Discards out-of-order frames and handles duplicate ACKs.

## Constants

- `N`: The size of the sender's window (number of frames that can be sent without waiting for an ACK).
- `MAX_FRAMES`: The total number of frames to be sent in the simulation.


## License

This project is licensed under the MIT License

## Acknowledgment

- [Wikipedia - Go-Back-N ARQ](https://en.wikipedia.org/wiki/Go-Back-N_ARQ)
- [C++ Documentation](https://en.cppreference.com/)
