#pragma once
#include <ipaaca/ipaaca.h>
#include <chrono>

class IpaacaAdapter
{
  public:
    IpaacaAdapter();
    void testMessage();
    ///void sendMessage(const std::string& category, const std::string& payload, const std::string& msg);
    void sendTerminate(const bool term);
    void sendMessage(const long timeStamp, const bool facedetected, const std::vector<double>& facerect, const std::vector<double>& landmarks, const std::vector<double>& angle3d, const std::vector<double> &derivates3d);
  private:
    ipaaca::OutputBuffer::ptr _ob;
};
