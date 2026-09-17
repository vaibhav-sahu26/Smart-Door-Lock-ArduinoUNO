# Smart-Door-Lock-ArduinoUNO
# Smart Door Lock System 🔐

An Arduino UNO based smart door locking system that uses a
4×4 keypad for password authentication and a servo motor
to lock and unlock the door.

## Features

- 4×4 keypad password input
- Password authentication
- Servo-based door locking/unlocking
- Incorrect password detection
- Password reset using `*`
- Password submission using `#`
- Serial Monitor status messages

## Components Used

- Arduino UNO
- 4×4 Matrix Keypad
- Servo Motor
- Jumper Wires
- Breadboard

## Software

- Arduino IDE
- Keypad Library
- Servo Library

## How It Works

1. Enter the 4-digit password using the keypad.
2. Press `#` to submit.
3. If the password is correct, the servo unlocks the door.
4. Entering the correct password again toggles the lock.
5. Press `*` to clear the entered password.

## Default Password

`1237`

> For demonstration purposes only. Do not use this password
> for a real security system.

## Team

- Vaibhav Sahu
- Mudit Verma
- Wasi Mohammad
- Aditya Kushwaha

## Branch

Electronics and Communication Engineering
