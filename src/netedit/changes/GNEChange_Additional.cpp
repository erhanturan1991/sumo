/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2019 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    GNEChange_Additional.cpp
/// @author  Pablo Alvarez Lopez
/// @date    Nov 2015
/// @version $Id$
///
// A network change in which a busStop is created or deleted
/****************************************************************************/

// ===========================================================================
// included modules
// ===========================================================================
#include <config.h>

#include <netedit/GNENet.h>
#include <netedit/netelements/GNELane.h>
#include <netedit/netelements/GNEEdge.h>
#include <netedit/additionals/GNEShape.h>
#include <netedit/additionals/GNEAdditional.h>
#include <netedit/demandelements/GNEDemandElement.h>
#include <netedit/GNEViewNet.h>

#include "GNEChange_Additional.h"

// ===========================================================================
// FOX-declarations
// ===========================================================================
FXIMPLEMENT_ABSTRACT(GNEChange_Additional, GNEChange, nullptr, 0)

// ===========================================================================
// member method definitions
// ===========================================================================

GNEChange_Additional::GNEChange_Additional(GNEAdditional* additional, bool forward) :
    GNEChange(additional->getViewNet()->getNet(), forward),
    myAdditional(additional),
    myParentEdges(myAdditional->getParentEdges()),
    myParentLanes(myAdditional->getParentLanes()),
    myParentShapes(myAdditional->getParentShapes()),
    myParentAdditionals(myAdditional->getParentAdditionals()),
    myParentDemandElements(myAdditional->getParentDemandElements()),
    myEdgeChildren(myAdditional->getEdgeChildren()),
    myLaneChildren(myAdditional->getLaneChildren()),
    myShapeChildren(myAdditional->getShapeChildren()),
    myAdditionalChildren(myAdditional->getAdditionalChildren()),
    myDemandElementChildren(myAdditional->getDemandElementChildren()) {
    myAdditional->incRef("GNEChange_Additional");
}


GNEChange_Additional::~GNEChange_Additional() {
    assert(myAdditional);
    myAdditional->decRef("GNEChange_Additional");
    if (myAdditional->unreferenced()) {
        // show extra information for tests
        WRITE_DEBUG("Deleting unreferenced " + myAdditional->getTagStr() + " '" + myAdditional->getID() + "'");
        // make sure that additional isn't in net before removing
        if (myNet->additionalExist(myAdditional)) {
            myNet->deleteAdditional(myAdditional, false);
            // Remove additional from parent elements
            for (const auto& i : myParentEdges) {
                i->removeAdditionalChild(myAdditional);
            }
            for (const auto& i : myParentLanes) {
                i->removeAdditionalChild(myAdditional);
            }
            for (const auto& i : myParentShapes) {
                i->removeAdditionalChild(myAdditional);
            }
            for (const auto& i : myParentAdditionals) {
                i->removeAdditionalChild(myAdditional);
            }
            for (const auto& i : myParentDemandElements) {
                i->removeAdditionalChild(myAdditional);
            }
            // Remove additional from child elements
            for (const auto& i : myEdgeChildren) {
                i->removeParentAdditional(myAdditional);
            }
            for (const auto& i : myLaneChildren) {
                i->removeParentAdditional(myAdditional);
            }
            for (const auto& i : myShapeChildren) {
                i->removeAdditionalChild(myAdditional);
            }
            for (const auto& i : myAdditionalChildren) {
                i->removeParentAdditional(myAdditional);
            }
            for (const auto& i : myDemandElementChildren) {
                i->removeParentAdditional(myAdditional);
            }
        }
        delete myAdditional;
    }
}


void
GNEChange_Additional::undo() {
    if (myForward) {
        // show extra information for tests
        WRITE_DEBUG("Removing " + myAdditional->getTagStr() + " '" + myAdditional->getID() + "' in GNEChange_Additional");
        // delete additional from net
        myNet->deleteAdditional(myAdditional, false);
        // Remove additional from parent elements
        for (const auto& i : myParentEdges) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentLanes) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentShapes) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentAdditionals) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentDemandElements) {
            i->removeAdditionalChild(myAdditional);
        }
        // Remove additional from child elements
        for (const auto& i : myEdgeChildren) {
            i->removeParentAdditional(myAdditional);
        }
        for (const auto& i : myLaneChildren) {
            i->removeParentAdditional(myAdditional);
        }
        for (const auto& i : myShapeChildren) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myAdditionalChildren) {
            i->removeParentAdditional(myAdditional);
        }
        for (const auto& i : myDemandElementChildren) {
            i->removeParentAdditional(myAdditional);
        }
    } else {
        // show extra information for tests
        WRITE_DEBUG("Adding " + myAdditional->getTagStr() + " '" + myAdditional->getID() + "' in GNEChange_Additional");
        // insert additional into net
        myNet->insertAdditional(myAdditional);
        // add additional in parent elements
        for (const auto& i : myParentEdges) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentLanes) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentShapes) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentAdditionals) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentDemandElements) {
            i->addAdditionalChild(myAdditional);
        }
        // add additional in child elements
        for (const auto& i : myEdgeChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myLaneChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myShapeChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myAdditionalChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myDemandElementChildren) {
            i->addParentAdditional(myAdditional);
        }
    }
    // Requiere always save additionals
    myNet->requireSaveAdditionals(true);
}


void
GNEChange_Additional::redo() {
    if (myForward) {
        // show extra information for tests
        WRITE_DEBUG("Adding " + myAdditional->getTagStr() + " '" + myAdditional->getID() + "' in GNEChange_Additional");
        // insert additional into net
        myNet->insertAdditional(myAdditional);
        // add additional in parent elements
        for (const auto& i : myParentEdges) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentLanes) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentShapes) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentAdditionals) {
            i->addAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentDemandElements) {
            i->addAdditionalChild(myAdditional);
        }
        // add additional in child elements
        for (const auto& i : myEdgeChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myLaneChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myShapeChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myAdditionalChildren) {
            i->addParentAdditional(myAdditional);
        }
        for (const auto& i : myDemandElementChildren) {
            i->addParentAdditional(myAdditional);
        }
    } else {
        // show extra information for tests
        WRITE_DEBUG("Removing " + myAdditional->getTagStr() + " '" + myAdditional->getID() + "' in GNEChange_Additional");
        // delete additional from net
        myNet->deleteAdditional(myAdditional, false);
        // Remove additional from parent elements
        for (const auto& i : myParentEdges) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentLanes) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentShapes) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentAdditionals) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myParentDemandElements) {
            i->removeAdditionalChild(myAdditional);
        }
        // Remove additional from child elements
        for (const auto& i : myEdgeChildren) {
            i->removeParentAdditional(myAdditional);
        }
        for (const auto& i : myLaneChildren) {
            i->removeParentAdditional(myAdditional);
        }
        for (const auto& i : myShapeChildren) {
            i->removeAdditionalChild(myAdditional);
        }
        for (const auto& i : myAdditionalChildren) {
            i->removeParentAdditional(myAdditional);
        }
        for (const auto& i : myDemandElementChildren) {
            i->removeParentAdditional(myAdditional);
        }
    }
    // Requiere always save additionals
    myNet->requireSaveAdditionals(true);
}


FXString
GNEChange_Additional::undoName() const {
    if (myForward) {
        return ("Undo create " + myAdditional->getTagStr()).c_str();
    } else {
        return ("Undo delete " + myAdditional->getTagStr()).c_str();
    }
}


FXString
GNEChange_Additional::redoName() const {
    if (myForward) {
        return ("Redo create " + myAdditional->getTagStr()).c_str();
    } else {
        return ("Redo delete " + myAdditional->getTagStr()).c_str();
    }
}
