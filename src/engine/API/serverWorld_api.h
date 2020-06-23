////////////////////////////////////////////////////////////////////////////////////////
// Copyright(C) 2011 - 2019 Dusan Jocic <dusanjocic@msn.com>
//
// This file is part of OpenWolf.
//
// OpenWolf is free software; you can redistribute it
// and / or modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
//
// OpenWolf is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with OpenWolf; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110 - 1301  USA
//
// -------------------------------------------------------------------------------------
// File name:   serverGame_api.h
// Version:     v1.01
// Created:     11/24/2018
// Compilers:   Visual Studio 2019, gcc 7.3.0
// Description:
// -------------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////

#ifndef __SERVERWORLD_API_H__
#define __SERVERWORLD_API_H__

#ifdef GAMEDLL
typedef struct gclient_s gclient_t;
typedef struct gentity_s gentity_t;
#define sharedEntity_t gentity_t
#else
#define gentity_t sharedEntity_t
#endif


//
// idServerWorldSystem
//
class idServerWorldSystem
{
public:
    virtual void UnlinkEntity( sharedEntity_t* gEnt ) = 0;
    virtual void LinkEntity( sharedEntity_t* gEnt ) = 0;
    virtual sint AreaEntities( const vec3_t mins, const vec3_t maxs, sint* entityList, sint maxcount ) = 0;
    virtual sint PointContents( const vec3_t p, sint passEntityNum ) = 0;
    virtual void Trace( trace_t* results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, sint passEntityNum, sint contentmask, traceType_t type ) = 0;
};

extern idServerWorldSystem* serverWorldSystem;

#endif //!__SERVERWORLD_API_H__
