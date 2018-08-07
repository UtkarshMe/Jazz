#include "serial.h"
#include "util/portio.h"

#define SERIAL_RECEIVED(_PORT)    (read_port(_PORT + 5) & 1)
#define SERIAL_SEND_EMPTY(_PORT)  (read_port(_PORT + 5) & 0x20)

void serial_init(int port)
{
  write_port(port + 1, 0x00);    // Disable all interrupts
  write_port(port + 3, 0x80);    // Enable DLAB (set baud rate divisor)
  write_port(port + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
  write_port(port + 1, 0x00);    //                  (hi byte)
  write_port(port + 3, 0x03);    // 8 bits, no parity, one stop bit
  write_port(port + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
  write_port(port + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}

void serial_write(int port, int data)
{
  while (SERIAL_SEND_EMPTY(port) == 0)
    ; /* nop */

  write_port(port, data);
}

int serial_read(int port)
{
  while (SERIAL_RECEIVED(port) == 0)
    ; /* nop */

  return read_port(port);
}

void serial_printf(int port, const char *format, ...)
{
  int *args;
  char *format_p = (char *)format;
  args = (int *)&format;
  args++;

  while (*format_p != '\0') {
    if (*format_p == '%') {
      format_p++;
      int x = *args++;
      if (*format_p == 'c') {
        serial_write(port, x);
      } else if (*format_p == 's') {
        for (int i = 0; format_p[i] != '\0'; i++) write_port(port, *format_p);
      } else if (*format_p == 'd') {
        /*kputd(port, x);*/
      } else if (*format_p == 'x') {
        /*kputhex(port, x);*/
      } else {
        /*error();*/
      }
    } else {
      serial_write(port, *format_p);
    }
    format_p++;
  }
}
