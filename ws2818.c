#include <ws2818.h>
#include <rgb.h>

#define WS2818_0 0b11000000
#define WS2818_1 0b11111100

void ws2818_send_byte(SPI_t spi, uint8_t B)
{
    int i;
    for (i = 0; i < 8; i++)
        spi_transfer(spi, B & (1 << i) ? WS2818_1 : WS2818_0);
}
void ws2818_send_color(SPI_t spi, uint8_t r, uint8_t g, uint8_t b)
{
    ws2818_send_byte(spi, g);
    ws2818_send_byte(spi, r);
    ws2818_send_byte(spi, b);
}

void ws2818_send_rgb(SPI_t spi, RGB_t c)
{
    ws2818_send_color(spi, c.r, c.g, c.b);
}

void ws2818_skip(SPI_t spi, int f)
{
    int i, n = f * 8 * 3;
    for (i = 0; i < n; i++)
        ws2818_send_byte(spi, 0);
}

void ws2818_reset(SPI_t spi)
{
    int i;
    // using 8mhz, getting 1bit ~ 1.25usec, so minimum delay 300usec, 300/1.25 ~ 240
    for (i = 0; i < 250; i++)
        spi_transfer(spi, 0);
}
