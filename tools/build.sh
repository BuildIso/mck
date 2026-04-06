#!/bin/sh

gcc -std=c89 -I include \
    src/main.c \
    src/core/core.c \
    src/drivers/drivers.c \
    src/modules/modules.c \
    -o build/mck.exe
