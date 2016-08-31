#include "gigasecond.h"
#include <boost/date_time/posix_time/posix_time.hpp>

namespace gigasecond{
  boost::gregorian::date advance(boost::gregorian::date d){
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    const auto period_to_advance = seconds(1e9);
    const ptime t(d,period_to_advance);

    return t.date();
  }
}
