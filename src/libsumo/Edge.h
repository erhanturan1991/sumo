/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2017-2018 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    Edge.h
/// @author  Gregor Laemmel
/// @date    15.09.2017
/// @version $Id$
///
// C++ TraCI client API implementation
/****************************************************************************/

#ifndef SUMO_Edge_H
#define SUMO_Edge_H

// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <string>
#include <vector>
#include <libsumo/TraCIDefs.h>


// ===========================================================================
// class declarations
// ===========================================================================
class MSEdge;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class Edge
 * @brief C++ TraCI client API implementation
 */
namespace libsumo {

class Edge {
public:
    static std::vector<std::string> getIDList();
    static int getIDCount();
    static double getAdaptedTraveltime(const std::string& id, double time);
    static double getEffort(const std::string& id, double time);
    static double getTraveltime(const std::string& id);
    static double getWaitingSeconds(const std::string& id);
    static const std::vector<std::string> getLastStepPersonIDs(const std::string& id);
    static const std::vector<std::string> getLastStepVehicleIDs(const std::string& id);
    static double getCO2Emission(const std::string& id);
    static double getCOEmission(const std::string& id);
    static double getHCEmission(const std::string& id);
    static double getPMxEmission(const std::string& id);
    static double getNOxEmission(const std::string& id);
    static double getFuelConsumption(const std::string& id);
    static double getNoiseEmission(const std::string& id);
    static double getElectricityConsumption(const std::string& id);
    static int getLastStepVehicleNumber(const std::string& id);
    static double getLastStepMeanSpeed(const std::string& id);
    static double getLastStepOccupancy(const std::string& id);
    static int getLastStepHaltingNumber(const std::string& id);
    static double getLastStepLength(const std::string& id);
    static int getLaneNumber(const std::string& id);
    static std::string getParameter(const std::string& id, const std::string& paramName);
    static void setAllowedVehicleClasses(const std::string& id, std::vector<std::string> vector);
    static void setDisallowedVehicleClasses(const std::string& id, std::vector<std::string> classes);
    static void setAllowedSVCPermissions(const std::string& id, int permissions);
    static void adaptTraveltime(const std::string& id, double begTime, double endTime, double value);
    static void setEffort(const std::string& id, double begTime, double endTime, double value);
    static void setMaxSpeed(const std::string& id, double value);
    static void setParameter(const std::string& id, const std::string& name, const std::string& value);
private:
    static MSEdge* getEdge(const std::string& id);
};

}


#endif //SUMO_Edge_H

/****************************************************************************/
