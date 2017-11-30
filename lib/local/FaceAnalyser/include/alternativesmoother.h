#pragma once

#include <boost/optional.hpp>
#include <dlib/image_processing.h>

class AlternativeSmoother
{
public:
    AlternativeSmoother();
    ~AlternativeSmoother();
    AlternativeSmoother(int smooth_frames, double golay_factor);
    void refreshQueue(boost::optional<double> &value);
    void estimateDerivation(boost::optional<double> &value);
private:
    dlib::queue<double>::kernel_1a angleQueue;
    // 5-10, 7-28, 9-60
    int smooth_len = 7;
    double std_factor = 28;
};
