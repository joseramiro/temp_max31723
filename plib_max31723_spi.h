#ifndef PLIB_MAX31723_SPI_H
#define PLIB_MAX31723_SPI_H

#include "libs/common_c_libs/plib_comm_struct.h"

#define MAX31723_DUMMY_DATA      0xFF

void MAX31723_WriteByte(SPI_t *spi, unsigned char* data);
void MAX31723_WriteBuffer(SPI_t *spi, unsigned char* data, unsigned int size);
void MAX31723_Read_Byte(SPI_t *spi, unsigned char* data);
void MAX31723_Read_Buffer(SPI_t *spi, unsigned char* data, unsigned int size);

#endif  // PLIB_MAX31723_SPI_H