#include <iostream>
#define MAXSIZE 160
using namespace std;

// Stack using array
int arr[MAXSIZE];
int top = -1;

int isfull(int arr[]) {
    if (top == MAXSIZE - 1) {
        return 1;
    }
    return 0;
}

int isempty(int arr[]) {
    if (top == -1) {
        return 1;
    }
    return 0;
}

int push(int a) {
    if (isfull(arr)) {
        cout << "Stack overflow" << endl;
        return -1;
    }
    top++;
    arr[top] = a;
    return 0; // Indicating success
}

void display(int arr[]) {
    if (isempty(arr)) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
}

int pop(int arr[]) {
    if (isempty(arr)) {
        cout << "Stack is empty" << endl;
        return -1; // Indicating stack underflow
    }
    int popped_value = arr[top];
    top--;
    cout << "Popped element: " << popped_value << endl;
    return popped_value;
}
int main() {
    push(6);
    push(7);
    pop(arr);
    display(arr);
    return 0;
}

