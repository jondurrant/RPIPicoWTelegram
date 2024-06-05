/*
 * TelegramBotCmds.cpp
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#include "TelegramBotCmds.h"
#include "json-maker/json-maker.h"

TelegramBotCmds::TelegramBotCmds() {

}

TelegramBotCmds::~TelegramBotCmds() {
	// TODO Auto-generated destructor stub
}

char * TelegramBotCmds::json(){
	size_t remLen = JSON_BUF_LEN;
    char* s = json_objOpen( xJsonBuf,  NULL,  &remLen );
    s = json_arrOpen(s,  "commands", &remLen );

	std::map<std::string, TelegramBotCmd *>::iterator it = xCmds.begin();
	while (it != xCmds.end()){
		s = json_objOpen( s,  NULL,  &remLen );
		s = json_str( s,  "command", it->first.c_str(), &remLen );
		s = json_str( s,  "description", it->second->getDesc(), &remLen );
		s = json_objClose( s, &remLen );
		it++;
	}
	s = json_arrClose( s, &remLen );
	s = json_objClose( s, &remLen );
	s = json_end( s, &remLen );

	printf("JSON: %s\n", xJsonBuf);
	return xJsonBuf;
}

void TelegramBotCmds::addCmd(TelegramBotCmd *cmd){
	xCmds[cmd->getId()] = cmd;
}

void TelegramBotCmds::delCmd(TelegramBotCmd *cmd){
	xCmds.erase(cmd->getId());
}

TelegramBotCmd * TelegramBotCmds::getCmd(const char *id){
	TelegramBotCmd *res = xCmds[id];
	return res;
}
