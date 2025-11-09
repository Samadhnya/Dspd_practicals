#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int F = -1, R = -1;

void enqueue(int value) {
    if (F == -1) {
        F = 0;
    }
    R++;
    queue[R] = value;
    printf("%d inserted into queue\n", value);
}

void dequeue() {
    if (F == -1 || F > R) {
        printf("Queue is empty\n");
    } else {
        printf("%d deleted from queue\n", queue[F]);
        F++;
    }
}

void over_under() {
    if (R == SIZE - 1) {
        printf("Queue is overflow\n");
    } else if (F == -1 || F > R) {
        printf("Queue is underflow\n");
    } else {
        printf("Queue neither underflow nor overflow\n");
    }
}

void display() {
    int i;
    if (F == -1 || F > R) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (i = F; i <= R; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main() {
    int n, value;
    while (n) {
        printf("Enter your choice:\n");
        printf("1. For insert\n2. For delete\n3. overflow-underflow\n4. Display\n5. Exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                over_under();
                break;
            case 4:
                display();
                
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Enter valid choice\n");
        }
    }
}
