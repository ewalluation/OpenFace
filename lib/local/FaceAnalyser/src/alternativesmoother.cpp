#include "alternativesmoother.h"

AlternativeSmoother::AlternativeSmoother(int smooth_frames, double golay_factor)
{
    smooth_len = smooth_frames;
    std_factor = golay_factor;
}

AlternativeSmoother::AlternativeSmoother()
{

}


AlternativeSmoother::~AlternativeSmoother()
{

}


void AlternativeSmoother::refreshQueue(boost::optional<double>& value) {
    if (value.is_initialized()) {
        double buf = value.get();
        angleQueue.enqueue(buf);
        double dequeued_value;
        if (angleQueue.size()>smooth_len) angleQueue.dequeue(dequeued_value);
        ///std::cout << "RA: " << *angVector.at(angVector.size()-1) << std::endl;
    }
}

void AlternativeSmoother::estimateDerivation(boost::optional<double>& value) {

    if (angleQueue.size()>=smooth_len) {
        double dif = 0;
        int i=0;
        while (angleQueue.move_next()) {
            double v = ((smooth_len-1)/2-i) * angleQueue.element();
            dif -= v;
            i++;
        }
        dif /= std_factor;
        value = dif;
    } else value = 0.1;


}
