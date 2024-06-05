/*
 * TelegramBotCmd.h
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#ifndef SRC_TELEGRAMBOTCMD_H_
#define SRC_TELEGRAMBOTCMD_H_

#include "Request.h"

class TelegramBotCmd  {
public:
	TelegramBotCmd();
	virtual ~TelegramBotCmd();


	virtual const char * getId() = 0;
	virtual const char * getDesc() = 0;

	virtual void execute(Request *req)=0;


};

#endif /* SRC_TELEGRAMBOTCMD_H_ */
