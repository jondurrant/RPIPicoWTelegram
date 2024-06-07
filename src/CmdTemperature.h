/*
 * CmdTemperature.h
 *
 * Telegram command to get the temperature of the Pico
 *
 *  Created on: 7 Jun 2024
 *      Author: jondurrant
 */

#ifndef SRC_CMDTEMPERATURE_H_
#define SRC_CMDTEMPERATURE_H_

#include "TelegramBotCmd.h"

class CmdTemperature : public TelegramBotCmd{
public:
	CmdTemperature();
	virtual ~CmdTemperature();

	virtual const char * getId();
	virtual const char * getDesc();

	virtual void execute(TelegramInterface *bot, int64_t chatId);

private:

	const char xId[6] =  "/temp";
	const char xDesc[20] = "Pico's Temperature";
};

#endif /* SRC_CMDTEMPERATURE_H_ */
