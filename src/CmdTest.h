/*
 * CmdTest.h
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#ifndef SRC_CMDTEST_H_
#define SRC_CMDTEST_H_

#include "TelegramBotCmd.h"

class CmdTest : public  TelegramBotCmd{
public:
	CmdTest();
	virtual ~CmdTest();

	virtual const char * getId();
	virtual const char * getDesc();

	virtual void execute(TelegramInterface *bot, int64_t chatId);

private:

	const char xId[6] =  "/test";
	const char xDesc[20] = "Just testing";
};

#endif /* SRC_CMDTEST_H_ */
