# Don't Repeat Yourself

```c
void info(char* message) {
	printf(%s - %s - %s, 'INFO', current_unix_timestamp, message);
}

void debug(char* message) {
	printf(%s - %s - %s, 'DEBUG', current_unix_timestamp, message);

}
```

This is a simple logger as it is used in many small applications. You see almost the same `printf` command in both functions with one different parameter. We can uniform this quite easy by creating a `log` function and redirect `info` and `debug` to the new `log` function, which handels the printing.

```c

void log(char* logLevel, char* message) {
	printf(%s - %s - %s, logLevel, current_unix_timestamp, message);
}

void info(char* message) {
	log('INFO', message);
}

void debug(char* message) {
	log('DEBUG', message);
}
```

