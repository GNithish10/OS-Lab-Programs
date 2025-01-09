#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_buffer
{
    long msg_type;
    int msg_number;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = flok("msgqueue.c", 65);

    if (key == -1)
    {
        perror("flok failed");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1)
    {
        perror("msgget failed");
        exit(1);
    }

    printf("Enter message number:");
    scanf("%d", &message.msg_number);
    getchar();

    printf("Enter the message:");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    message.msg_text[strcspn(message.msg_text, "\n")] = '\0';
    message.msg_type = 1;

    if (msgsnd(msgid, &message, sizeof(message) - sizeof(long), 0) == -1)
    {
        perror("msgsnd failed");
        exit(1);
    }

    printf("Message sent: Type=%ld, Number=%d,text=%s\n", message.msg_type, message.msg_number, message.msg_text);
    printf("Receiving message...\n");

    if (msgrcv(msgid, &message, sizeof(message) - sizeof(long), 1, 0) == -1)
    {
        perror("msgrcv failed");
        exit(1);
    }

    printf("Message received: Type=%ld, Number=%d, Text=%s\n", message.msg_type, message.msg_number, message.msg_text);

    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl failed");
        exit(1);
    }

    return 0;
}