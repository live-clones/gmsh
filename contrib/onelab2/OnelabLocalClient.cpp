#include "OnelabLocalClient.h"
#include "OnelabServer.h"


template <class T> bool OnelabLocalClient::set(const T &p)
{
  return OnelabServer::instance->set(p, _name);
}
template <class T> bool OnelabLocalClient::get(std::vector<T> &ps, const std::string &name)
{
  return OnelabServer::instance->get(ps, name, _name);
}
