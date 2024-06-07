/*
 * TelegramInterface.h
 *
 * Interface to the Telegram Bot. Allows some decoupling in the observer interface.
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#ifndef SRC_TELEGRAMINTERFACE_H_
#define SRC_TELEGRAMINTERFACE_H_

#include "pico/stdlib.h"

class TelegramInterface {
public:
	TelegramInterface();
	virtual ~TelegramInterface();

	/***
	 * Send message to the chat session
	 * @param chatId - ID of the chat session
	 * @param msg - message to send
	 * @return
	 */
	virtual bool sendMessage(int64_t chatId, const char * msg) = 0;
};

#endif /* SRC_TELEGRAMINTERFACE_H_ */
