#include "OnelabDatabase.h"

OnelabServer *OnelabServer::_server = NULL;

#ifndef WIN32
void *OnelabDatabase_listen(void *arg)
#else
DWORD WINAPI OnelabDatabase_listen(LPVOID arg)
#endif
{
  std::string *client = (std::string *)arg;
  OnelabProtocol msg(-1);
  UInt8 buff[1024];
  int recvlen = 0;
  while(1) {
    recvlen = OnelabDatabase::instance()->listen(msg);
    if(recvlen <= 0)
      break; // invalid len
    switch(msg.msgType()) {
      case OnelabProtocol::OnelabStop:
        std::clog << "\033[0;35m" << "Client is going to stop" << "\033[0;0m" << std::endl;
        OnelabDatabase::instance()->networkClientHaveToStop(true);
        return NULL;
      case OnelabProtocol::OnelabMessage:
        Msg::Info("Message from onelab"); // TODO
        break;
      case OnelabProtocol::OnelabResponse:
      case OnelabProtocol::OnelabUpdate:
        std::clog << "\033[0;35m" << "Update " << msg.attrs.size() << " parameter(s) on client:" << "\033[0;0m" << std::endl;
        for(std::vector<OnelabAttr *>::iterator it = msg.attrs.begin() ; it != msg.attrs.end(); ++it) {
          std::clog << "  - " << ((onelab::parameter *)*it)->getName() << std::endl; // FIXME
          if((*it)->getAttributeType() == OnelabAttr::Number) {
            onelab::number *attr = (onelab::number *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttr::String) {
            onelab::string *attr = (onelab::string *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttr::Region) {
            onelab::region *attr = (onelab::region *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttr::Function) {
            onelab::function *attr = (onelab::function *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttrFileQuery::attributeType()) {
            OnelabAttrFileQuery *attr = (OnelabAttrFileQuery *)*it;
            const char *filename = attr->getFilename();
            // FIXME path/filename ?
            std::clog << "try to open " << filename << " for reading" << std::endl;
            FILE *fp = fopen(filename, "rb");
            if(fp != NULL){
              OnelabProtocol rep(OnelabProtocol::OnelabUpdate);
              rep.attrs.push_back(new OnelabAttrFile(std::string(filename), fp));
              recvlen = rep.encodeMsg(buff, 1024);
              OnelabDatabase::instance()->sendbytes(buff, recvlen);
              while((recvlen = fread(buff, 1, 1024, fp)) > 0)
                OnelabDatabase::instance()->sendbytes(buff, recvlen);
            }
          }
          else if((*it)->getAttributeType() == OnelabAttrFile::attributeType()) {
            OnelabAttrFile *attr = (OnelabAttrFile *)*it;
            const char *filename = attr->getFilename();
            std::clog << "try to open " << filename << " for writing" << std::endl;
            FILE *fp = fopen(filename, "wb");
            if(fp != NULL){
              unsigned int filesize = ((OnelabAttrFile *)attr)->getFileSize();
              unsigned int downloadsize = 0;
              while(downloadsize < filesize) {
                recvlen = OnelabDatabase::instance()->listen(buff, 1024);
                downloadsize += recvlen;
                fwrite(buff, 1, recvlen, fp);
              }
            }
          }
        }
        break;
      case OnelabProtocol::OnelabAction:
      {
        std::clog << "\033[0;35m" << "Client have to perform an action" << "\033[0;0m" << std::endl;
        // nothing to do ?
      }
    }
  }
}
#ifndef WIN32
void *OnelabDatabase_server(void *arg)
#else
DWORD WINAPI OnelabDatabase_server(LPVOID arg)
#endif
{
  OnelabServer::instance()->Run();
}
