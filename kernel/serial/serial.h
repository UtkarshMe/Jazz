#ifndef SERIAL_H_FT2N9HWC
#define SERIAL_H_FT2N9HWC

#define SERIAL_PORT1 0x3f8
#define SERIAL_PORT2 0x2f8
#define SERIAL_PORT3 0x3e8
#define SERIAL_PORT4 0x2e8

void serial_init    (int port);
void serial_write   (int port, int data);
int  serial_read    (int port);
void serial_printf  (int port, const char *format, ...);

#endif /* end of include guard: SERIAL_H_FT2N9HWC */
