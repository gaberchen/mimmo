/*---------------------------------------------------------------------------*\
 * 
 *  MiMMO
 *
 *  Copyright (C) 2015-2016 OPTIMAD engineering Srl
 *
 *  -------------------------------------------------------------------------
 *  License
 *  This file is part of MiMMO.
 *
 *  MiMMO is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License v3 (LGPL)
 *  as published by the Free Software Foundation.
 *
 *  MiMMO is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 *  License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with MiMMO. If not, see <http://www.gnu.org/licenses/>.
 *
 \ *---------------------------------------------------------------------------*/

#ifndef __CORESELECTIONPATCHES_HH
#define __CORESELECTIONPATCHES_HH

// local libs
#include "bitpit.hpp"
#include "BasicMeshes.hpp"

/*!
 *	\date			31/12/2015
 *	\authors		Gallizio Federico
 * 	\authors 		Sister Rosetta
 *	\authors		Arpa Rocco
 *	\copyright		Copyright 2015 Optimad engineering srl. All rights reserved.
 *	\par			License:\n
 *	This class version is released under .
 *
 *	\brief Virtual class for bitpit::Patch Selection Representation
 *
 *	Base class for Volumetric Core Element, suitable for interaction with Data Structure stored in a MimmoObject class.
 */
 
class BaseSelPatch {
  
protected:
  std::string m_patchType;
  
public:
    BaseSelPatch();
    ~BaseSelPatch();
    
    BaseSelPatch(const BaseSelPatch &);
    BaseSelPatch & operator=(const BaseSelPatch &);
    
    std::string getPatchType();
    
    ivector1D includeGeometry(bitpit::Patch * );
    ivector1D excludeGeometry(bitpit::Patch * );
    
    ivector1D includeCloudPoints(dvecarr3E &);
    ivector1D excludeCloudPoints(dvecarr3E &);
    
	ivector1D includeCloudPoints(bitpit::Patch * );
	ivector1D excludeCloudPoints(bitpit::Patch * );
	
//     ivector1D includePIDTriangulation(SHAPE *, int );
//     ivector1D excludePIDTriangulation(SHAPE *, int );
// 
//     ivector1D includePIDTriangulation(SHAPE *, ivector1D & );
//     ivector1D excludePIDTriangulation(SHAPE *, ivector1D & );
    
    bool isSimplexIncluded(dvecarr3E &);
	bool isSimplexIncluded(bitpit::Patch * , int indexT);
    
    virtual bool isPointIncluded(darray3E)=0;
	virtual bool isPointIncluded(bitpit::Patch * , int indexV)=0;
};


class HullCube : public BaseSelPatch, public UCubicMesh{
 
public:
    HullCube();
    HullCube(darray3E origin_, double spanX_, double spanY_, double spanZ_, int nx_, int ny_, int nz_); 
    ~HullCube();
    
    HullCube(const HullCube &);
    HullCube & operator=(const HullCube &);
   
    bool isPointIncluded(darray3E);
	bool isPointIncluded(bitpit::Patch * , int indexV);
};

/*!
 *	\date			31/12/2015
 *	\authors		Gallizio Federico
 * 	\authors 		Sister Rosetta
 *	\authors		Arpa Rocco
 *	\copyright		Copyright 2015 Optimad engineering srl. All rights reserved.
 *	\par			License:\n
 *	This class version is released under .
 *
 *	\brief Volumetric Cylindric HUll class  
 *
 *	Structured Mesh, of cylindrical shape and reference frame, suitable for interaction with Triangulation data Structure.
 */
 
class HullCylinder : public BaseSelPatch, public UCylindricalMesh{
 
public:
    HullCylinder();
    HullCylinder(darray3E origin_, double spanR_, double spanZ_, dvector1D & thetalim_, int nr_, int nt_, int nz_); 
    ~HullCylinder();
    
    HullCylinder(const HullCylinder &);
    HullCylinder & operator=(const HullCylinder &);
   
    bool isPointIncluded(darray3E);
	bool isPointIncluded(bitpit::Patch * , int indexV);
};

/*!
 *	\date			31/12/2015
 *	\authors		Gallizio Federico
 * 	\authors 		Sister Rosetta
 *	\authors		Arpa Rocco
 *	\copyright		Copyright 2015 Optimad engineering srl. All rights reserved.
 *	\par			License:\n
 *	This class version is released under .
 *
 *	\brief Volumetric Cylindric HUll class  
 *
 *	Structured Mesh, of cylindrical shape and reference frame, suitable for interaction with Triangulation data Structure.
 */
 
class HullSphere : public BaseSelPatch, public USphericalMesh{
 
public:
    HullSphere();
    HullSphere(darray3E origin_, double spanR_, dvector1D thetalim_, dvector1D philim_, int nr_, int nt_, int np_); 
    ~HullSphere();
    
    HullSphere(const HullSphere &);
    HullSphere & operator=(const HullSphere &);
   
    bool isPointIncluded(darray3E);
	bool isPointIncluded(bitpit::Patch * , int indexV);
};

#endif // __CORESELECTIONPATCHES_HH

