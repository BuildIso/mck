#ifndef MCK_IO_H
#define MCK_IO_H

/* Generic I/O abstraction for mck */

typedef unsigned long mck_io_addr;
typedef unsigned long mck_io_val;

typedef mck_io_val (*mck_io_read_fn)(mck_io_addr addr);
typedef void (*mck_io_write_fn)(mck_io_addr addr, mck_io_val value);

void mck_io_set_read(mck_io_read_fn fn);
void mck_io_set_write(mck_io_write_fn fn);

mck_io_val mck_io_read(mck_io_addr addr);
void mck_io_write(mck_io_addr addr, mck_io_val value);

#endif
