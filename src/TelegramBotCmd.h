/*
 * TelegramBotCmd.h
 *
 * the  Abstract interface for  a Telegram command
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#ifndef SRC_TELEGRAMBOTCMD_H_
#define SRC_TELEGRAMBOTCMD_H_

#include "TelegramInterface.h"


class TelegramBotCmd  {
public:
	TelegramBotCmd();
	virtual ~TelegramBotCmd();


	/***
	 * Return the ID for the command.
	 * @return Something line "/test"
	 */
	virtual const char * getId() = 0;

	/***
	 * Return the human readable description of the command
	 * @return
	 */
	virtual const char * getDesc() = 0;

	/***
	 * Execute the command for the given chat session
	 * @param bot - Bot interface to send response through
	 * @param chatId - Chat ID of the session
	 */
	virtual void execute(TelegramInterface *bot, int64_t chatId)=0;


};

#endif /* SRC_TELEGRAMBOTCMD_H_ */
