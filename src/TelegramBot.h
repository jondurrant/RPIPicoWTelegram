/*
 * TelegramBot.h
 *
 * Telegram Bot Active Agent (Task).
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
	/***
	 * Constructor
	 * @param buf - Buffer for use in receiveing update. Needs to be large > 4k
	 * @param len - Length of the bugger
	 */
	TelegramBot(char *buf, size_t len);
	virtual ~TelegramBot();

	/***
	 * Send a message to a chat session
	 * @param chatId - Char session ID
	 * @param msg - Message to send
	 * @return
	 */
	virtual bool sendMessage(int64_t chatId, const char * msg);

	/***
	 * Add a command for the Bot to operate
	 * @param cmd
	 */
	virtual void addCmd(TelegramBotCmd *cmd);

	/***
	 * Remove the command
	 * @param cmd
	 */
	virtual void delCmd(TelegramBotCmd *cmd);


protected:
	/***
	 * Authorisation check to see if ID is able to use the bot
	 * Only where this responds yes will any response be given by the Bot
	 * @param fromId
	 * @return
	 */
	virtual bool isAuthorised(uint64_t fromId);

	/***
	 * Send the lsit of available commands to Telegram
	 * @return
	 */
	virtual bool sendCommands();

	/***
	 * Get an update and action any requests
	 * @return
	 */
	virtual bool doUpdate();

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
