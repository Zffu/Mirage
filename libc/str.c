/**
 * Compares the two strings and returns the delta value.
 * If ret == 0, the strings are equal.
 */
int strcmp(char* s1, char* s2) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

/**
 * Gives the length of the string until the first \0 is met.
 */
int strlen(char* s) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

/**
 * Appends a char at the end of the string buffer. (When \0 is met)
 */
void append(char* s, char n) {
    int len = strlen(s);
    s[len] = n;
    s[len+1] = '\0';
}

/**
 * Backspaces into the string.
 */
void backspace(char* s) {
    int len = strlen(s);
    s[len-1] = '\0';
}

/**
 * Splits the strings into segments (Delimited by \0).
 */
void strsplit(char* s, char sep) {
    int i = 0;
    char c = s[0];

    while(c != 0) {
        c = s[i];

        if(c == sep) {
            s[i] = '\0';
        }

        ++i;
    }
}

/**
 * Gets the next string segment
 */
char* strnextsegment(char* s) {
    int i = 0;
    char c = s[0];

    while(c != 0) {
        c = s[i];

        if(c == '\0') {
            return s + i + 1;
        }

        ++i;
    }

    return s;
}

/**
 * Converts an integer into ascii.
 */
void int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    /* TODO: implement "reverse" */
}