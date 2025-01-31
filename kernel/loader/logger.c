#include <drivers/screen.h>

void l_loginfo(char* message) {
    print("[INFO] ");
    print(message);
    print("\n");
}

void l_logok(char* message) {
    print("[");
    printWithColor("OK", GREEN_ON_BLACK);
    print("] ");
    print(message);
    print("\n");
}

void l_logwarn(char* message) {
    print("[");
    printWithColor("WARN", YELLOW_ON_BLACK);
    print("] ");
    print(message);
    print("\n");
}

void l_logerr(char* message) {
    print("[");
    printWithColor("ERROR", LIGHT_RED_ON_BLACK);
    print("] ");
    print(message);
    print("\n");
}