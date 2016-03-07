#include "adc.h"


SPISettings ADCSPI::getSPISettings(uint32_t spi_clk_freq, uint8_t bit_order, uint8_t spi_mode)
{
	return SPISettings(spi_clk_freq, bit_order, spi_mode);
}


void ADCSPI::setDefaultChannel(uint8_t channel)
{
	default_channel = channel;
}


uint16_t ADCSPI::readChannel(uint8_t ch)
{}


uint16_t ADCSPI::readDefaultChannel()
{
	return readChannel(default_channel);
}

