#ifndef _ONELAB_PROTOCOL_H
#define _ONELAB_PROTOCOL_H

#define ERROR_ONELAB_VERSION 20
#define ONELAB_VERSION 0x01

#include <vector>

#include "OnelabAttributes.h"

class OnelabProtocol
{
private:
	//UInt8 _version;
	UInt8 _type;
	UInt16 _size;
public:
	std::vector<OnelabAttr*> attrs;
	OnelabProtocol(UInt16 type);
	~OnelabProtocol() {clearAttrs();}
	void clearAttrs();
	unsigned short encodeMsg(UInt8 *buff, UInt32 len);
	UInt32 parseMsg(UInt8 *buff, UInt32 len);
  int parseHeader(UInt8 *buff, UInt32 len);
  UInt32 parseMessage(UInt8 *buff, UInt32 len);
	void showMsg();

	short msgType() {return _type;}
	void msgType(short type) {this->clearAttrs(); _type = type;}

	static const UInt8 BindRequestMsg	= 0x01;
	static const UInt8 BindResponseMsg	= 0x02;
	static const UInt8 BindMessageMsg	= 0x03;

	static const UInt8 OnelabStart		= 0x10;
	static const UInt8 OnelabStop		= 0x11;
	static const UInt8 OnelabMessage	= 0x12;
	static const UInt8 OnelabRequest	= 0x13;
	static const UInt8 OnelabResponse	= 0x14;
	static const UInt8 OnelabUpdate		= 0x15;
};
#endif
