/*
 * TelegramBot.h
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#ifndef SRC_TELEGRAMBOT_H_
#define SRC_TELEGRAMBOT_H_

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "Agent.h"
#include "Request.h"
#include "TelegramInterface.h"
#include "TelegramBotCmds.h"
#include "CmdTest.h"


class TelegramBot : public Agent, public TelegramInterface {
public:
	TelegramBot(char *buf, size_t len);
	virtual ~TelegramBot();


	bool sendCommands();

	bool doUpdate();

	virtual bool sendMessage(int64_t chatId, const char * msg);


protected:

	/***
	 * Run loop for the agent.
	 */
	virtual void run();


	/***
	 * Get the static depth required in words
	 * @return - words
	 */
	virtual configSTACK_DEPTH_TYPE getMaxStackSize();

private:
	Request *pRequest  = NULL;
	Request *pMessage = NULL;

	TelegramBotCmds xCmds;
	char *pBuffer = NULL;
	size_t xBufferLen = 0;

	CmdTest xCmdTest;

	uint xOffset = 0;
};

#endif /* SRC_TELEGRAMBOT_H_ */
