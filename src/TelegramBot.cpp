/*
 * TelegramBot.cpp
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#include "TelegramBot.h"
#include "tiny-json.h"

#define MAX_TAGS 100

TelegramBot::TelegramBot(char *buf, size_t len) {
	pBuffer = buf;
	xBufferLen = len = 1024;

	pRequest = new 	Request(pBuffer, xBufferLen);
	pMessage = new Request(&pBuffer[xBufferLen], 1024);

	xCmds.addCmd(&xCmdTest);

}

TelegramBot::~TelegramBot() {
	delete(pRequest);
	delete(pMessage);

}




/***
* Run loop for the agent.
*/
void TelegramBot::run(){

	sendCommands();

	for (;;){
		doUpdate();

		vTaskDelay(10000);
	}

}


/***
* Get the static depth required in words
* @return - words
*/
configSTACK_DEPTH_TYPE TelegramBot::getMaxStackSize(){
	return 2048;
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

bool TelegramBot::doUpdate(){
	char url[] = "https://api.telegram.org/bot"
								TELEGRAMBOTKEY
								"/getUpdates";
	json_t pool[MAX_TAGS];
	char offset[20];
	int64_t chatId = 0;

	std::map<std::string, std::string> query;
	query["limit"] = "1";
	if (xOffset != 0){
		sprintf(offset, "%d", xOffset+1);
		query["offset"] = offset;
	}

	int res = pRequest->get(url, &query);

	if ( res ){
		res = (pRequest->getStatusCode() == 200);
	}

	if (res){
		printf("WS: %.*s\n",
				pRequest->getPayloadLen(),
				pRequest->getPayload());

		char *json = (char *) pRequest->getPayload();
		json[pRequest->getPayloadLen()] ='\0';
		json_t const* parent = json_create(
						json,
						pool,
						MAX_TAGS);
		if ( parent != NULL ){
			json_t const* result = json_getProperty( parent, "result" );
			if (result != NULL){
				json_t const * item = json_getChild(result);
				while (item != NULL){
					json_t const* update =  json_getProperty( item, "update_id" );
					if (update != NULL){
						xOffset = json_getInteger(update);
					}

					json_t const* msg =  json_getProperty( item, "message" );
					if (msg != NULL ){

						json_t const* chat =  json_getProperty( msg, "chat" );
						if (chat != NULL){
							json_t const* id =  json_getProperty( chat, "id" );
							if (id != NULL){
								chatId = json_getInteger(id);
							}
						}


						json_t const* text =  json_getProperty( msg, "text" );
						if (text != NULL){
							const char *txt = json_getValue(text);
							if (txt != NULL){
								printf("Text Command is %s\n", txt);

								TelegramBotCmd * cmd = xCmds.getCmd(txt);
								if (cmd != NULL){
									cmd->execute(this, chatId);
								} else {
									printf("Unknown cmd %s\n", txt);
									if (chatId != 0){
										sendMessage(chatId, "Unknown command");
										//printf("Chat ID %lld\n", chatId);
									}
								}
							}
						}
					}
					item = json_getSibling(item);
				}
			}
			printf("JSON OK\n");
		}


	} else {
		printf("WS Failed %d\n",
				pRequest->getStatusCode() );
	}

	return res;
}


bool TelegramBot::sendMessage(int64_t chatId, const char * msg){
	char url[] = "https://api.telegram.org/bot"
									TELEGRAMBOTKEY
									"/sendMessage";
		char chat[100];
		std::map<std::string, std::string> query;

		sprintf(chat,"%lld", chatId);
		query["chat_id"] = chat;
		query["text"]=msg;

		int res = pMessage->get(url, &query);

		if ( res ){
			res = (pMessage->getStatusCode() == 200);
		}

		if (res){
			printf("WS: %.*s\n",
					pMessage->getPayloadLen(),
					pMessage->getPayload());
		} else {
			printf("WS Failed %d\n", pMessage->getStatusCode() );
			printf("URL: %s\n", pMessage->getUriChar());
		}
		return res;
}
