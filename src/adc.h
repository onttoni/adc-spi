#pragma once

#include <Arduino.h>
#include <SPI.h>

#define DEFAULT_PIN_CS 10
#define DEFAULT_SPI_CLK_FREQ 1000 * 1000L


// Base class for SPI AD-converters.
class ADCSPI
{
public:
	ADCSPI(uint8_t pin_cs = DEFAULT_PIN_CS, uint32_t max_value = 255)
	: max_value(max_value)
	, pin_cs(pin_cs)
	{}
	const uint32_t max_value;
	virtual uint16_t readChannel(uint8_t ch);
	void setDefaultChannel(uint8_t channel);
	uint16_t readDefaultChannel();

protected:
	const uint8_t pin_cs;
	uint8_t default_channel;
	SPISettings settingsSPI;
	SPISettings getSPISettings(uint32_t spi_clk_freq, uint8_t bit_order, uint8_t spi_mode);
};

