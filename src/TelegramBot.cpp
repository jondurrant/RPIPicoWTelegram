/*
 * TelegramBot.cpp
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#include "TelegramBot.h"

TelegramBot::TelegramBot(char *buf, size_t len) {
	pBuffer = buf;
	xBufferLen = len;

	pRequest = new 	Request(pBuffer, xBufferLen);

	xCmds.addCmd(&xCmdTest);

}

TelegramBot::~TelegramBot() {
	delete(pRequest);
}



/***
* Run loop for the agent.
*/
void TelegramBot::run(){

	sendCommands();


	for (;;){
		vTaskDelay(10000);
	}

}


/***
* Get the static depth required in words
* @return - words
*/
configSTACK_DEPTH_TYPE TelegramBot::getMaxStackSize(){
	return 1024;
}


bool TelegramBot::sendCommands(){
	char url[] = "https://api.telegram.org/bot"
								TELEGRAMBOTKEY
							   "/setMyCommands";


	int res = pRequest->postJSON(url,  &xCmds);

	if ( res ){
		res = (pRequest->getStatusCode() == 200);
	}

	if (res){
		printf("WS: %.*s\n",
				pRequest->getPayloadLen(),
				pRequest->getPayload());
	} else {
		printf("WS Failed %d\n",
				pRequest->getStatusCode() );
	}

	return res;

}
