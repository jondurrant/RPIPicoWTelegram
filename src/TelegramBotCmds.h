/*
 * TelegramBotCmds.h
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#ifndef LIB_RPIPICOWWSCLIENT_RTOS_SRC_TELEGRAMBOTCMDS_H_
#define LIB_RPIPICOWWSCLIENT_RTOS_SRC_TELEGRAMBOTCMDS_H_

#include "TelegramBotCmd.h"
#include "JSONSerialisable.h"
#include <map>

#define JSON_BUF_LEN  256

class TelegramBotCmds : public JSONSerialisable {
public:
	TelegramBotCmds();
	virtual ~TelegramBotCmds();

	virtual char * json();

	void addCmd(TelegramBotCmd *cmd);
	void delCmd(TelegramBotCmd *cmd);
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
