#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <ctime>

using namespace std;

//consts
const int N = 4;
const int MAX_FRAMES = 10;

//sender
queue<int> senderWindow;
int expectedAck = 0;
int nextFrameToSend = 0;

//receiver
int lastAckedFrame = -1;
bool frames[MAX_FRAMES] = {false};

// Simulate sending of frame (transmission)
void sendFrame(int frameNumber) {
	cout << "Sending Frame" << frameNumber << endl;
}

// Simulate receiving a frame at the receiver
bool receiveFrame(int frameNumber) {
	if(frameNumber == lastAckedFrame+1) {
		lastAckedFrame = frameNumber;
		cout << "Receiver received frame " << frameNumber << ", sending ACK\n";
		return true;
	} else {
		cout << "Receiver discarded frame " << frameNumber << ". (Out of Order)\n";
		return false;
	}
}

// Simulate receiving an ACK (Acknowledgment)
void receiveAck(int ackNumber) {
	if (ackNumber == expectedAck) {
		cout << "Receiver sent ACK for frame " << ackNumber << endl;
		expectedAck++;
	} else {
		cout << "Receiver discarded duplicate ACK for frame " << ackNumber << endl;
	}
}
// Sender process
void sender() {
	while (nextFrameToSend < MAX_FRAMES) {
		// Send frames while there is space in the sender's window
		if (senderWindow.size() < N) {
			sendFrame(nextFrameToSend);
			senderWindow.push(nextFrameToSend);  // Add the frame to the sender's window
			nextFrameToSend++;
		}

		// Simulate receiving an ACK (this would be done asynchronously in a real protocol)
		if (rand() % 2 == 0) {  // Randomly simulate receiving an ACK or not
			int ackNumber = senderWindow.front();
			senderWindow.pop();
			receiveAck(ackNumber);  // Remove from window and acknowledge
		} else {
			cout << "Timeout for frame " << senderWindow.front() << ", retransmitting...\n";
		}

		this_thread::sleep_for(chrono::milliseconds(500));  // Simulate network delay
	}

	cout << "Sender finished sending all frames.\n";
}

// Receiver process
void receiver() {
	for (int i = 0; i < MAX_FRAMES; i++) {
		// Simulate receiving frames and process them
		if (receiveFrame(i)) {
			// If the frame is received correctly, send ACK for the last correctly received frame
			receiveAck(i);
		}
		this_thread::sleep_for(chrono::milliseconds(500));  // Simulate delay
	}
}

int main() {
	srand(time(0));  // Seed random number generator for simulation

	// Start sender and receiver in parallel
	thread senderThread(sender);
	thread receiverThread(receiver);

	// Wait for both threads to finish
	senderThread.join();
	receiverThread.join();

	return 0;
}