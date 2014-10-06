#include <iostream>

#include "OnelabProtocol.h"
#include "onelab.h"
#include "NetworkUtils.h"

OnelabProtocol::OnelabProtocol(UInt16 type)
{
	_type = type;
	_size = 0;
}
void OnelabProtocol::clearAttrs()
{
	for (std::vector<OnelabAttr*>::iterator it = this->attrs.begin() ; it != this->attrs.end(); ++it) {
		if((*it) != NULL && !(*it)->isInDatabase()) delete *it;
	}
	this->attrs.clear();
}
unsigned short OnelabProtocol::encodeMsg(UInt8 *buff, UInt32 len)
{
	if(len < 4) throw ERROR_BUFFER_TOO_SMALL;
	UInt8 *ptr = encode(buff, (UInt8)ONELAB_VERSION);
	ptr = encode(ptr, _type);
  UInt8 *sizeptr = ptr;
	_size = 0;
	ptr = encode(sizeptr, _size);
	for (std::vector<OnelabAttr*>::iterator it = this->attrs.begin() ; it != this->attrs.end(); ++it) {
    UInt16 attrLen = (*it)->getAttributeLength();
    if(4+_size+attrLen > len) {
      // FIXME
	    encode(sizeptr, _size);
      return (unsigned short)(ptr-buff);
      // size = 0;
    }
		ptr = (*it)->encodeAttribute(ptr);
    _size+=attrLen+4;
  }

	encode(sizeptr, _size);
	return (unsigned short)(ptr-buff);
}
UInt32 OnelabProtocol::parseMsg(UInt8 *buff, UInt32 len)
{
	this->clearAttrs();
	if(len < 4) throw ERROR_BUFFER_TOO_SMALL;
	UInt8 *ptr = buff;
	UInt8 version = 0;
	ptr = parse(ptr, version);
	if(version != ONELAB_VERSION) throw ERROR_ONELAB_VERSION;
	ptr = parse(ptr, _type);
	ptr = parse(ptr, _size);
  std::cout << "current version is " << (int)ONELAB_VERSION << ", message version is " << (int)version << "(length is " << len << ", size is "<< _size <<" )" << std::endl; // TODO send to gmsh ?

	UInt8 *payload = ptr;
  unsigned short parsed = 4;
	unsigned short size = _size;

	while(size >= 4) {
		UInt16 attrType = 0;
		UInt16 attrSize = 0;
		ptr = parse(ptr, attrType);
		ptr = parse(ptr, attrSize);
		size -= 4;
		std::cout << "Try to parse an attribute of type 0x" << std::hex << (UInt16)attrType << std::dec << " and size : " << attrSize << std::endl;
		if(attrSize > size) throw ERROR_BUFFER_TOO_SMALL;
		switch(attrType) {
			case OnelabAttr::Message:
				this->attrs.push_back(new OnelabAttrMessage());
				((OnelabAttrMessage *)this->attrs.back())->parseAttribute(ptr, attrSize);
				break;
			case OnelabAttr::Number:
				this->attrs.push_back(new onelab::number());
				((onelab::number *)this->attrs.back())->parseAttribute(ptr, attrSize);
				break;
			case OnelabAttr::String:
				this->attrs.push_back(new onelab::string());
				((onelab::string *)this->attrs.back())->parseAttribute(ptr, attrSize);
				break;
      case OnelabAttr::Region:
        this->attrs.push_back(new onelab::region());
        ((onelab::region *)this->attrs.back())->parseAttribute(ptr, attrSize);
        break;
      case OnelabAttr::Function:
        this->attrs.push_back(new onelab::region());
        ((onelab::function *)this->attrs.back())->parseAttribute(ptr, attrSize);
        break;
			case OnelabAttr::Start:
				this->attrs.push_back(new OnelabAttrStart());
				((onelab::string *)this->attrs.back())->parseAttribute(ptr, attrSize);
				break;
			case OnelabAttr::Parameter:
				this->attrs.push_back(new OnelabAttrParameterQuery());
				((OnelabAttrParameterQuery *)this->attrs.back())->parseAttribute(ptr, attrSize);
				break;
      case 0x0b:
				this->attrs.push_back(new OnelabAttrFileQuery());
				((OnelabAttrFileQuery *)this->attrs.back())->parseAttribute(ptr, attrSize);
        break;
      case 0x0c:
				this->attrs.push_back(new OnelabAttrFile());
				((OnelabAttrFile *)this->attrs.back())->parseAttribute(ptr, attrSize);
        break;
			default:
        // FIXME unknown attribute
				//if(attrSize != 0) throw "Size of attr must be 0!";
				/*this->attrs.push_back(new OnelabAttr(attrType));
				this->attrs.back()->parseAttribute(ptr, &attrSize);*/
				break;
		}
		ptr += attrSize;
		size -= attrSize;
    parsed += attrSize+4;
	}
  // TODO the boundary of the packet is not correct, keep the last bytes in a buffer (the rest is comming)
  if(parsed != len) {std::cout << "parse - size left:"  << len-parsed << '-' << size << "(len is "<< len <<" and parsed is "<< parsed <<" )" << std::endl;}
  return len-parsed;
}
void OnelabProtocol::showMsg()
{
	std::cout << "\033[1m" << "\033[4m" << "Message type: 0x" << std::hex << (int)_type << "\033[0m" << std::endl
		<< "And have " << std::dec << this->attrs.size() << " attribute(s)" << std::endl;
	for (std::vector<OnelabAttr*>::iterator it = this->attrs.begin() ; it != this->attrs.end(); ++it)
		(*it)->showAttribute();
	std::cout << std::endl;
}
