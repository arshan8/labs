#include <stdio.h>
#define maxsize 25

int arr[maxsize];

int front = -1;
int rear = -1;

int isempty() {
    if ((front == -1 && rear == -1) || front > rear) {
        return 1;
    }
    return 0;
}

int isfull() {
    if (rear == maxsize - 1) {
        return 1;
    }
    return 0;
}

int enque(int a) {
    if (isfull()) {
        printf("Queue overflow\n");
        return -1;
    }
    if (front == -1 && rear == -1) { // or empty
        front++;
        rear++;
        arr[rear] = a;
    } else {
        rear++;
        arr[rear] = a;
    }
    return 0;
}

int deque() {
    if (isempty()) {
        printf("Queue underflow\n");
        return -1;
    }
    int q = arr[front];
    if (front == rear) { // Now empty after deque
        printf("Now empty, it had %d\n", q);
        front = -1;
        rear = -1;
    } else {
        printf("Removed: %d\n", q);
        front++;
    }
    return q;
}

void print() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    enque(5);
    enque(10);
    enque(15);
    deque();
    print();
    return 0;
}
