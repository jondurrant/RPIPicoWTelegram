/*
 * TelegramInterface.h
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

	virtual bool sendMessage(int64_t chatId, const char * msg) = 0;
};

#endif /* SRC_TELEGRAMINTERFACE_H_ */
