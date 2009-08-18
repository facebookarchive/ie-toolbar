#include "StdAfx.h"
#include "ClientServiceEventsSink.h"

#include <boost/bind.hpp>

namespace facebook{

// ---------------------------------------------------------------------
// class ClientServiceEventsSink
// ---------------------------------------------------------------------

ClientServiceEventsSink::ClientServiceEventsSink():
   observers_() {}


ClientServiceEventsSink::~ClientServiceEventsSink() {}


STDMETHODIMP ClientServiceEventsSink::dataUpdated(ULONG dataId) {
  std::for_each(observers_.begin(), observers_.end(),
    boost::bind(&ClientServiceObserver::dataUpdated, _1, dataId));
   
  return S_OK;
}


void ClientServiceEventsSink::subscribe(ClientServiceObserverPtr observer) {
  observers_.insert(observer);
}


void ClientServiceEventsSink::unsubscribe(ClientServiceObserver* observer) {
  observers_.erase(observer);
}


size_t ClientServiceEventsSink::getObserversCount() const{
  return observers_.size();
}

} //!namespace facebook
