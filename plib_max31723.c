#include "plib_max31723.h"
#include "plib_max31723_spi.h"

/**
 * @file plib_temperature.c
 * @author Ramiro Najera
 * @brief Fichier source principal pour les capteurs de température
 * 
 * Ce fichier en-tête est le point d'entrée principal pour la bibliothèque de gestion des capteurs
 * de température MAX31723. Il inclut les autres fichiers d'en-tête nécessaires pour la gestion
 * de la communication SPI et le contrôle du Chip Select (CS).
 * @version 0.1
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 */

void MAX31723_StartTranmission(SPIConfiguration_t *spi)
{
    spi->cs.set();
}

void MAX31723_EndTranmission(SPIConfiguration_t *spi)
{
    spi->cs.clear();
}

// Basic functions
void MAX31723_ReadRegister(SPIConfiguration_t *spi, unsigned char reg, unsigned int size, unsigned char* readData)
{
    // Start tranmission
    MAX31723_StartTranmission(spi);
    // Send register
    MAX31723_WriteByte(spi, &reg);
    // Read register 
    MAX31723_Read_Buffer(spi, readData, size);
    // Stop tranmission
    MAX31723_EndTranmission(spi);
}

void MAX31723_WriteRegister(SPIConfiguration_t *spi, unsigned char reg, unsigned char* writeData, unsigned int size)
{
    // Start tranmission
    MAX31723_StartTranmission(spi);
    // Populate register and send it
    MAX31723_WriteByte(spi, &reg);
    MAX31723_WriteBuffer(spi, writeData, size);
    // Stop tranmission
    MAX31723_EndTranmission(spi);
}

void MAX31723_ReadConfigurationReg(SPIConfiguration_t *spi, unsigned char* data)
{
    MAX31723_ReadRegister(spi, MAX31723_REG_CONF, 1, data);
}

void MAX31723_WriteConfigurationReg(SPIConfiguration_t *spi, unsigned char* data)
{
    MAX31723_WriteRegister(spi, (MAX31723_REG_CONF | MAX31723_WRITE_MODE), data, 1);
}

void MAX31723_ReadLSBTemperatureReg(SPIConfiguration_t *spi, unsigned char* data)
{
    MAX31723_ReadRegister(spi, MAX31723_REG_TEMP_LSB, 1, data);
}

void MAX31723_ReadMSBTemperatureReg(SPIConfiguration_t *spi, unsigned char* data)
{
    MAX31723_ReadRegister(spi, MAX31723_REG_TEMP_MSB, 1, data);
}

void MAX31723_ReadTemperatureReg(SPIConfiguration_t *spi, unsigned char* data)
{
    MAX31723_ReadLSBTemperatureReg(spi, &data[0]);
    MAX31723_ReadMSBTemperatureReg(spi, &data[1]);
}