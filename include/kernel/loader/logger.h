#ifndef KERNEL_LOADER_LOGGER
#define KERNEL_LOADER_LOGGER

void l_loginfo(char* message);

void l_logok(char* message);
void l_logwarn(char* message);
void l_logerr(char* message);

#endif