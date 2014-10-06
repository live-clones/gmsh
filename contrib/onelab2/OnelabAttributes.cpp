#include <cstring>
#include <iostream>

#include "OnelabAttributes.h"

UInt8 *OnelabAttrStart::encodeAttribute(UInt8 *dst)
{
	dst = encode(dst, getAttributeType());
	dst = encode(dst, getAttributeLength());

	dst = encode(dst, (UInt8 *)_name.c_str(), _name.size());

	return dst;
}
UInt8 *OnelabAttrStart::parseAttribute(UInt8 *src, UInt32 length)
{
	_name.assign((char *)src, (int)length);

	return src+length;
}
void OnelabAttrStart::showAttribute()
{
	std::cout << "\033[1m" << "Attribute start:"<< getAttributeType() << "\033[0m"<< std::endl
		<< "name:   " << _name << std::endl;
}

UInt8 *OnelabAttrParameterQuery::encodeAttribute(UInt8 *dst)
{
	dst = encode(dst, getAttributeType());
	dst = encode(dst, getAttributeLength());

	dst = encode(dst, _ptype);
	dst = encode(dst, (UInt8 *)_pname.c_str(), _pname.size());

	return dst;
}
UInt8 *OnelabAttrParameterQuery::parseAttribute(UInt8 *src, UInt32 length)
{
	if(length < 1) throw ERROR_INVALID_ATTRIBUTE_SIZE;

	src = parse(src, _ptype);
	_pname.assign((char *)src, (int)(length-1));

	return src+length;
}
void OnelabAttrParameterQuery::showAttribute()
{
	std::cout << "\033[1m" << "Attribute parameter query:"<< getAttributeType() << "\033[0m"<< std::endl
		<< "type:   " << this->_ptype << std::endl
		<< "name:   " << this->_pname << std::endl;
}

UInt8 *OnelabAttrMessage::encodeAttribute(UInt8 *dst)
{
	dst = encode(dst, getAttributeType());
	dst = encode(dst, getAttributeLength());

	dst = encode(dst, _level);
	dst = encode(dst, _message, _messageLength);

	return dst;
}
UInt8 *OnelabAttrMessage::parseAttribute(UInt8 *src, UInt32 length)
{
	if(length < 1) throw ERROR_INVALID_ATTRIBUTE_SIZE;

	src = parse(src, _level);
	_messageLength = length-1;
	if(_message != NULL) free(_message);
	_message = (UInt8 *)malloc(_messageLength);
	src = parse(src, _message, _messageLength);

	return src;
}
void OnelabAttrMessage::showAttribute()
{
	std::cout << "Attribute message:" << std::endl
		<< "Level:   " << _level << std::endl
		<< "Message: " << _message << std::endl;
}

UInt8 *OnelabAttrAction::encodeAttibute(UInt8 *dst)
{
  dst = encode(dst, getAttributeType());
  dst = encode(dst, getAttributeLength());

  dst = encode(dst, (UInt8 *)_client.c_str(), _client.size()+1);
  dst = encode(dst, (UInt8 *)_action.c_str(), _action.size());

  return dst;
}

UInt8 *OnelabAttrAction::parseAttibute(UInt8 *src, UInt32 length)
{
  _client.assign((char *)src);
  src += _client.size()+1;
  _action.assign((char *)src, length-_client.size()-1);
  src += _action.size();
  return src;
}

UInt8 *OnelabAttrFileQuery::encodeAttribute(UInt8 *dst)
{
	dst = encode(dst, getAttributeType());
	dst = encode(dst, getAttributeLength());

  dst = encode(dst, (UInt8 *)_name, _length);
  dst = encode(dst, (UInt8 *)_client.c_str(), _client.length()+1);

  return dst;
}
UInt8 *OnelabAttrFileQuery::parseAttribute(UInt8 *src, UInt32 length)
{
  if(_name != NULL) free(_name);
  _length = length;
  _name = (char *)malloc(_length+1);
  src = parse(src, (UInt8 *)_name, _length);
  _name[_length] = '\0';

  return src;
}
void OnelabAttrFileQuery::setFilename(const std::string name)
{
  if(_name != NULL) free(_name);

  _length = name.size();
  _name = strndup(name.c_str(), _length);
}

UInt8 *OnelabAttrFile::encodeAttribute(UInt8 *dst)
{
	dst = encode(dst, getAttributeType());
	dst = encode(dst, getAttributeLength());

  dst = encode(dst, _filelength);
  dst = encode(dst, (UInt8 *)_name, strlen(_name)+1);
  return dst;
}
UInt8 *OnelabAttrFile::parseAttribute(UInt8 *src, UInt32 length)
{
  if(length < 5) throw ERROR_INVALID_ATTRIBUTE_SIZE;
  if(_name != NULL) free(_name);

  src = parse(src, _filelength);
  _name = strndup((char *)src, length-4);
  return  src+length-4;
}
