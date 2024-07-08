#include "env_adaptor.h"

using namespace Simulator;

EnvAdaptor::EnvAdaptor(Strategy& strat, Exchange& exch, int interval, long period)
           :strategy(strat),
            exchange(exch) {
}


bool EnvAdaptor::quote(int bid_spread, int ask_spread, const double& buyVolumeAngle, const double& sellVolumeAngle) {
    return this->strategy.quote(bid_spread, ask_spread, buyVolumeAngle, sellVolumeAngle);
}

void EnvAdaptor::reset(int time_index, const double& positionAmount, const double& averagePrice) {
    return this->strategy.reset(time_index, positionAmount, averagePrice);
}

PositionInfo EnvAdaptor::fetchPositionData() const {
    PositionInfo info;
    auto obs = exchange.getObs();
    strategy.fetchInfo(info, obs.getBestBidPrice(), obs.getBestAskPrice());
    return info;
}

std::vector<double> EnvAdaptor::getState() const { std::vector<double> retval; return retval; }

bool EnvAdaptor::hasFilled() const {
    return filled;
}
