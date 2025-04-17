#ifndef PLIB_MAX31723_H
#define PLIB_MAX31723_H

/**
 * @file plib_temperature.h
 * @author Ramiro Najera
 * @brief Fichier en-tête principal pour les capteurs de température
 * 
 * Ce fichier en-tête est le point d'entrée principal pour la bibliothèque de gestion des capteurs
 * de température MAX31723. Il inclut les autres fichiers d'en-tête nécessaires pour la gestion
 * de la communication SPI et le contrôle du Chip Select (CS).
 * @version 0.1
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 */

 #include "libs/util/plibs_utils.h"  // used for SPI struct

/** 
 * @defgroup MAX31723_Registers Registres du MAX31723
 * @brief Définitions des registres du composant MAX31723 utilisés pour la communication SPI.
 * @{
 */

#define MAX31723_REG_CONF               0x00    /**< Registre de configuration/statut */
#define MAX31723_REG_TEMP_LSB           0x01    /**< Température LSB */
#define MAX31723_REG_TEMP_MSB           0x02    /**< Température MSB */
#define MAX31723_REG_ALARM_HIGH_LSB     0x03    /**< Température d'alarme max LSB */
#define MAX31723_REG_ALARM_HIGH_MSB     0x04    /**< Température d'alarme max MSB */
#define MAX31723_REG_ALARM_LOW_LSB      0x05    /**< Température d'alarme min LSB */
#define MAX31723_REG_ALARM_LOW_MSB      0x06    /**< Température d'alarme min MSB */
/** @} */ // Fin du groupe TLE9201SG_Registers

#define MAX31723_WRITE_MODE             0x80    /**< Masque pour écrire les registres */

/**
 * @struct TempSensorConf
 * @brief Configuration d'un capteur de température MAX31723
 * 
 * Cette structure définit les paramètres de configuration pour un module MAX31723
 */
typedef struct
{
    unsigned char id;   /**< Identifiant du module (voir @ref FansMax31723IdList) */
    SPIConfiguration_t spi;
}MAX31723Conf_t;

/**
 * @brief Démarre une transmission SPI avec le module MAX31723.
 * @param spi Pointeur vers la configuration SPI utilisée pour la communication.
 */
void MAX31723_StartTranmission(SPIConfiguration_t *spi);

/**
 * @brief Termine une transmission SPI avec le module MAX31723.
 * @param spi Pointeur vers la configuration SPI utilisée pour la communication.
 */
void MAX31723_EndTranmission(SPIConfiguration_t *spi);

/**
 * @brief Lit le contenu d'un registre du capteur de température
 * @param sensor Id du capteur de température. Voir @ref FansMax31723IdList
 * @param reg Registre à lire
 * @param size Nombre de bytes à lire
 * @param readData Données à lire
 */
void MAX31723_ReadRegister(SPIConfiguration_t *spi,
                           unsigned char reg,
                           unsigned int size,
                           unsigned char* readData);
/**
 * @brief Ecrit des données dans un registre du capteur de température
 * @param sensor Id du capteur de température. Voir @ref FansMax31723IdList
 * @param reg Registre à écrire
 * @param writeData Données à écrire
 * @param size Nombre de bytes à écrire
 */
void MAX31723_WriteRegister(SPIConfiguration_t *spi,
                            unsigned char reg,
                            unsigned char* writeData,
                            unsigned int size);
/**
 * @brief Lit le registre configuration/status du capteur
 * @param sensor Id du capteur de température. Voir @ref FansMax31723IdList
 * @param data Données à lire
 */
void MAX31723_ReadConfigurationReg(SPIConfiguration_t *spi, unsigned char* data);
/**
 * @brief Ecrire le registre configuration/status du capteur
 * @param sensor Id du capteur de température. Voir @ref FansMax31723IdList
 * @param data Données à écrire
 */
void MAX31723_WriteConfigurationReg(SPIConfiguration_t *spi, unsigned char* data);
/**
 * @brief Lit le LSB de la valeur de température du capteur
 * @param sensor Id du capteur de température. Voir @ref FansMax31723IdList
 * @param data Données à lire
 */
void MAX31723_ReadLSBTemperatureReg(SPIConfiguration_t *spi, unsigned char* data);
/**
 * @brief Lit le MSB de la valeur de température du capteur
 * @param sensor Id du capteur de température. Voir @ref FansMax31723IdList
 * @param data Données à lire
 */
void MAX31723_ReadMSBTemperatureReg(SPIConfiguration_t *spi, unsigned char* data);
/**
 * @brief Lit la valeur de température. Appelle les fonctions @ref MAX31723_ReadLSBTemperatureReg et
 * @ref MAX31723_ReadMSBTemperatureReg, puis fusionne le résultat
 * @param sensor Id du capteur de température. Voir @ref FansMax31723IdList
 * @param data Données à lire
 */
void MAX31723_ReadTemperatureReg(SPIConfiguration_t *spi, unsigned char* data);

#endif  // PLIB_MAX31723_H