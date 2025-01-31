int strcmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
};

void backspace(char* s) {
    int len = strlen(s);
    s[len-1] = '\0';
}

void append(char* s, char n) {
    int len = strlen(s);
    s[len] = n;
    s[len+1] = '\0';
}

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