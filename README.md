Project Overview : 

🛡️ Caesar Cipher in C — Final Project
A simple Caesar Cipher encryption and decryption program written in C, using a circular queue to represent the alphabet (A–Z). Unlike traditional implementations that rely on arithmetic shifts, this version rotates a queue to simulate the Caesar cipher effect.

📌 Features
🔐 Choose to encrypt or decrypt a message

📝 Input a custom message

🔁 Provide a shift key (positive or negative)

❌ Non-letter characters (spaces, numbers, punctuation) remain unchanged

🔧 Project Structure
| Part | Description                             | Assigned To       |
| ---- | --------------------------------------- | ----------------- |
| 1️⃣  | Circular Queue Setup & Helper Functions | `W.K.V Sahansara` |
| 2️⃣  | Encryption & Decryption Functions       | `I.G.P.L.Inguruwaththa` |
| 3️⃣  | Main Program & User Interaction         | `W.A.R.P.Wickramasinghe  `|


🚀 How to Run the Program
1. 📄 Combine All Parts
Copy Part 1, Part 2, and Part 3 into a single .c file.

2. 📌 Add the Required Headers at the Top

        #include <stdio.h> <br>
        #include <string.h> <br>
        #include <ctype.h> <br>
        
        #define QUEUE_SIZE 26 <br>
        #define MAX_TEXT 1024 <br>
        
        // Circular queue structure for the alphabet <br>
        typedef struct { <br>
            char data[QUEUE_SIZE]; <br>
            int front; <br>
            int rear; <br>
            int count; <br>
        } CircularQueue; <br>

3. 🧪 Compile & Run
