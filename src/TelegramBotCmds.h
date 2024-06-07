/*
 * TelegramBotCmds.h
 *
 * Command List container. Commands for Telegram Bot to respond to
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#ifndef LIB_RPIPICOWWSCLIENT_RTOS_SRC_TELEGRAMBOTCMDS_H_
#define LIB_RPIPICOWWSCLIENT_RTOS_SRC_TELEGRAMBOTCMDS_H_

#include "TelegramBotCmd.h"
#include "JSONSerialisable.h"
#include <map>
#include <string>

#ifndef JSON_BUG_LEN
#define JSON_BUF_LEN  256
#endif

class TelegramBotCmds : public JSONSerialisable {
public:
	TelegramBotCmds();
	virtual ~TelegramBotCmds();

	/***
	 * JSON structure of the commands and description in Telegram format
	 * @return
	 */
	virtual char * json();

	/***
	 * Add a new command
	 * @param cmd
	 */
	void addCmd(TelegramBotCmd *cmd);

	/****
	 * Delete a command
	 * @param cmd
	 */
	void delCmd(TelegramBotCmd *cmd);

	/***
	 * Get a command from the list
	 * @param id Something like "/temp"
	 * @return
	 */
	TelegramBotCmd * getCmd(const char *id);

private:
	std::map<std::string, TelegramBotCmd *> xCmds;

	char xJsonBuf[JSON_BUF_LEN];
	//= "{\"commands\": ["
	//		"{\"command\": \"/test\", "
	//		"\"description\": \"Just testing\"}"
	//		"]}";

};

#endif /* LIB_RPIPICOWWSCLIENT_RTOS_SRC_TELEGRAMBOTCMDS_H_ */
