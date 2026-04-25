#ifndef INPUT_H
#define INPUT_H

typedef struct {
    int code;
    int value;
} input_event;

typedef void (*input_handler)(input_event *e);

void input_init(void);
void input_set_handler(input_handler h);
void input_push(int code, int value);
void input_poll(void);

#endif
