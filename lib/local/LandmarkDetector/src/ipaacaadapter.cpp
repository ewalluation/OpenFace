#include "ipaacaadapter.h"

using namespace ipaaca;

IpaacaAdapter::IpaacaAdapter()
{
    _ob = OutputBuffer::create("nodeventSender");
}

/*
void IpaacaAdapter::testMessage()
{
        /*
    ipaaca::IU::ptr iu = ipaaca::IU::create("EventCategory");
    iu->payload()["word"] = "OK";
    _ob->add(iu);

    ipaaca::Message::ptr msg = ipaaca::Message::create("EventCategory");
    msg->payload()["word"] = "OK";
    _ob->add(msg);
}
*/

void IpaacaAdapter::sendTerminate(const bool term)
{
    ipaaca::IU::ptr iu = ipaaca::Message::create("openface");
    iu->payload()["terminate"] = term;
    _ob->add(iu);
}

void IpaacaAdapter::sendMessage(const long timeStamp, const bool facedetected, const std::vector<double>& facerect, const std::vector<double>& landmarks, const std::vector<double> &angle3d, const std::vector<double> &derivates3d)
{
    ipaaca::IU::ptr iu = ipaaca::Message::create("openface");
    ///ipaaca::Message::ptr ipaacaMsg = ipaaca::Message::create(category);
    iu->payload()["timestamp"] = timeStamp;
    iu->payload()["facedetected"] = facedetected;
    iu->payload()["facerect"] = facerect;
    iu->payload()["landmarks"] = landmarks;
    iu->payload()["angle3d"] = angle3d;
    iu->payload()["derivates3d"] = derivates3d;
    ///_ob->add(ipaacaMsg);
    _ob->add(iu);
}
