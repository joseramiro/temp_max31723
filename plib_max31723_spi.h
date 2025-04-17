#ifndef PLIB_MAX31723_SPI_H
#define PLIB_MAX31723_SPI_H

#include "libs/util/plibs_utils.h"  // used for SPI struct

#define MAX31723_DUMMY_DATA      0xFF

void MAX31723_WriteByte(SPIConfiguration_t *spi, unsigned char* data);
void MAX31723_WriteBuffer(SPIConfiguration_t *spi, unsigned char* data, unsigned int size);
void MAX31723_Read_Byte(SPIConfiguration_t *spi, unsigned char* data);
void MAX31723_Read_Buffer(SPIConfiguration_t *spi, unsigned char* data, unsigned int size);

#endif  // PLIB_MAX31723_SPI_H