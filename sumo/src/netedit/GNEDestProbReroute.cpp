/****************************************************************************/
/// @file    GNEDestProbReroute.cpp
/// @author  Pablo Alvarez Lopez
/// @date    Jan 2017
/// @version $Id: GNERerouter.cpp 22699 2017-01-25 14:56:03Z behrisch $
///
///
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2001-2017 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/

// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <utils/common/ToString.h>

#include "GNEDestProbReroute.h"

#ifdef CHECK_MEMORY_LEAKS
#include <foreign/nvwa/debug_new.h>
#endif

// ===========================================================================
// member method definitions
// ===========================================================================

GNEDestProbReroute::GNEDestProbReroute(GNERerouterInterval *rerouterIntervalParent, std::string newDestinationId, SUMOReal probability):
    myNewDestinationId(newDestinationId),
    myProbability(0),
    myRerouterIntervalParent(rerouterIntervalParent),
    myTag(SUMO_TAG_DEST_PROB_REROUTE) {
    // set probability manually to avoid non valid values
    setProbability(probability);
}


GNEDestProbReroute::~GNEDestProbReroute() {
}


const std::string&
GNEDestProbReroute::getNewDestinationId() const {
    return myNewDestinationId;
}


SUMOReal
GNEDestProbReroute::getProbability() const {
    return myProbability;
}


bool
GNEDestProbReroute::setProbability(SUMOReal probability) {
    if (probability >= 0 && probability <= 1) {
        myProbability = probability;
        return true;
    } else {
        return false;
    }
}


SumoXMLTag 
GNEDestProbReroute::getTag() const {
    return myTag;
}


GNERerouterInterval*
GNEDestProbReroute::getRerouterIntervalParent() const {
    return myRerouterIntervalParent;
}
/****************************************************************************/
