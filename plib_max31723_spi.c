#include "plib_max31723_spi.h"
#include "peripheral/spi/spi_master/plib_spi2_master.h"
#include "peripheral/spi/spi_master/plib_spi1_master.h"

void MAX31723_WriteByte(SPI_t *spi, unsigned char* data)
{
    if(spi->channel == SPI_CH1)
        SPI1_Write(data, 1);
    else if(spi->channel == SPI_CH2)
        SPI2_Write(data, 1);
}

void MAX31723_WriteBuffer(SPI_t *spi, unsigned char* data, unsigned int size)
{
    unsigned int i = 0;

    if(spi->channel == SPI_CH1)
    {
        for(i = 0; i < size; i++)
            SPI1_Write(&data[i], 1);  
    }
    else if(spi->channel == SPI_CH2)
    {
        for(i = 0; i < size; i++)
            SPI2_Write(&data[i], 1);  
    }  
}

void MAX31723_Read_Byte(SPI_t *spi, unsigned char* data)
{
    if(spi->channel == SPI_CH1)
        SPI1_Read(data, 1);
    else if(spi->channel == SPI_CH2)
        SPI2_Read(data, 1);
}

void MAX31723_Read_Buffer(SPI_t *spi, unsigned char* data, unsigned int size)
{
    if(spi->channel == SPI_CH1)
        SPI1_Read(data, size);
    else if(spi->channel == SPI_CH2)
        SPI2_Read(data, size); 
}