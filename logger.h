#define ERROR_LOG 0
#define WARN_LOG 1
#define INFO_LOG 2

extern void log_print(int level, char *fmt,...);