/*
 * CmdTemperature.cpp
 *
 *  Created on: 7 Jun 2024
 *      Author: jondurrant
 */

#include "CmdTemperature.h"
#include "pico/stdlib.h"
#include <cstdio>
#include "hardware/adc.h"

CmdTemperature::CmdTemperature() {
	adc_init();
	adc_set_temp_sensor_enabled(true);

}

CmdTemperature::~CmdTemperature() {
	// TODO Auto-generated destructor stub
}

const char * CmdTemperature::getId(){
	return xId;
}
const char * CmdTemperature::getDesc(){
	return xDesc;
}

void CmdTemperature::execute(TelegramInterface *bot, int64_t chatId){
	float temp;
	char buf[100];
	const float conversion_factor = 3.3f / (1 << 12);
	adc_select_input(4);

	float v = (float)adc_read() * conversion_factor;
	temp = 27.0 - ((v - 0.706)/0.001721);

	sprintf(buf, "Pico Temperature %.2fC", temp);
	bot->sendMessage(chatId,  buf);
}
