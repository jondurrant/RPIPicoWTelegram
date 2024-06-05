/*
 * CmdTest.cpp
 *
 *  Created on: 5 Jun 2024
 *      Author: jondurrant
 */

#include "CmdTest.h"
#include <cstdio>

CmdTest::CmdTest() {
	// TODO Auto-generated constructor stub

}

CmdTest::~CmdTest() {
	// TODO Auto-generated destructor stub
}


const char * CmdTest::getId(){
	return xId;
}
const char * CmdTest::getDesc(){
	return xDesc;
}

void CmdTest::execute(Request *req){
	printf("Execute Cmd Test\n");
}


