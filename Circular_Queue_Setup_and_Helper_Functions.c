#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define QUEUE_SIZE 26
#define MAX_TEXT 1024

// Circular queue structure for the alphabet
typedef struct {
    char data[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;


// This part sets up the circular queue for the alphabet and has helper functions.


// Makes the alphabet A-Z in the queue.
void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    for (int i = 0; i < QUEUE_SIZE; i++) {
        q->rear = (q->rear + 1) % QUEUE_SIZE;
        q->data[q->rear] = 'A' + i;
        q->count++;
    }
}

// Adds a letter to the end of the queue.
void enqueue(CircularQueue *q, char ch) {
    if (q->count == QUEUE_SIZE) return;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = ch;
    q->count++;
}

// Removes a letter from the front of the queue.
char dequeue(CircularQueue *q) {
    if (q->count == 0) return '\0';
    char ch = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return ch;
}

// Rotates the queue by 'shift' spots.
void rotateQueue(CircularQueue *q, int shift) {
    shift = (shift % QUEUE_SIZE + QUEUE_SIZE) % QUEUE_SIZE;
    for (int i = 0; i < shift; i++) {
        char ch = dequeue(q);
        enqueue(q, ch);
    }
}

// Finds where a letter is in the queue.
int getIndex(CircularQueue *q, char ch) {
    for (int i = 0; i < QUEUE_SIZE; i++) {
        int idx = (q->front + i) % QUEUE_SIZE;
        if (q->data[idx] == ch) return i;
    }
    return -1;
}

// Gets the letter at a certain spot in the queue.
char getCharAt(CircularQueue *q, int idx) {
    idx = (q->front + idx) % QUEUE_SIZE;
    return q->data[idx];
}

//This part handles user input and output, and calls the encryption/decryption functions.

int main() {
    char message[MAX_TEXT];
    char result[MAX_TEXT];
    char mode;
    int shift;

    printf("Encryption (E) or Decryption (D)?: ");
    scanf(" %c", &mode);
    while (getchar() != '\n'); // clear bufferss

    printf("Enter your message: ");
    fgets(message, MAX_TEXT, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove new line

    printf("Enter shift key : ");
    scanf("%d", &shift);

    printf("*\n");

    if (mode == 'E' || mode == 'e') {
        encrypt(message, shift, result);
        printf("Encrypted Message: %s\n", result);
    } else if (mode == 'D' || mode == 'd') {
        decrypt(message, shift, result);
        printf("Original Message: %s\n", result);
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}