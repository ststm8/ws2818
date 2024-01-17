#ifndef __ws2818_h__
#define __ws2818_h__

#include <stm8spi.h>
#include <rgb.h>

void ws2818_send_byte(SPI_t spi, uint8_t B);
void ws2818_send_color(SPI_t spi, uint8_t r, uint8_t g, uint8_t b);
void ws2818_send_rgb(SPI_t spi, RGB_t c);
void ws2818_skip(SPI_t spi, int f);
void ws2818_reset(SPI_t spi);

#endif