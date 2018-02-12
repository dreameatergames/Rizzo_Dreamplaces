/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#ifndef SOUND_H
#define SOUND_H

#include "matrixlib.h"

#define DEFAULT_SOUND_PACKET_VOLUME 255
#define DEFAULT_SOUND_PACKET_ATTENUATION 1.0

#ifndef NO_SOUND

// ====================================================================
// Constants
// ====================================================================


// Channel flags
#define CHANNELFLAG_NONE		0
#define CHANNELFLAG_FORCELOOP	(1 << 0) // force looping even if the sound is not looped
#define CHANNELFLAG_LOCALSOUND	(1 << 1) // INTERNAL USE. Not settable by S_SetChannelFlag
#define CHANNELFLAG_PAUSED		(1 << 2)
#define CHANNELFLAG_FULLVOLUME	(1 << 3) // isn't affected by the general volume


// ====================================================================
// Types and variables
// ====================================================================

typedef struct sfx_s sfx_t;

extern cvar_t bgmvolume;
extern cvar_t volume;
extern cvar_t snd_initialized;
extern cvar_t snd_staticvolume;


// ====================================================================
// Functions
// ====================================================================

void S_Init (void);
void S_Terminate (void);

void S_Startup (void);
void S_Shutdown (void);
void S_Reload_f (void);

void S_Update(const matrix4x4_t *listenermatrix);
void S_ExtraUpdate (void);

sfx_t *S_PrecacheSound (const char *sample, qboolean complain, qboolean lock);
void S_ServerSounds (char serversound [][MAX_QPATH], unsigned int numsounds);
qboolean S_IsSoundPrecached (const sfx_t *sfx);

// S_StartSound returns the channel index, or -1 if an error occurred
int S_StartSound (int entnum, int entchannel, sfx_t *sfx, vec3_t origin, float fvol, float attenuation);
qboolean S_LocalSound (const char *s);

void S_StaticSound (sfx_t *sfx, vec3_t origin, float fvol, float attenuation);
void S_StopSound (int entnum, int entchannel);
void S_StopAllSounds (void);
void S_PauseGameSounds (qboolean toggle);

void S_StopChannel (unsigned int channel_ind);
qboolean S_SetChannelFlag (unsigned int ch_ind, unsigned int flag, qboolean value);
void S_SetChannelVolume (unsigned int ch_ind, float fvol);

void S_BlockSound (void);
void S_UnblockSound (void);

int S_GetSoundRate (void);

#else

#define S_GetSoundRate() 0
#define S_UnblockSound()
#define S_BlockSound()
#define S_SetChannelVolume(CHI,FV)
#define S_SetChannelFlag(CHI,FLG,VL) false
#define S_StopChannel(CHI)
#define S_PauseGameSounds(TG)
#define S_StopAllSounds()
#define S_StopSound(ENT,CH)
#define S_StaticSound(SF,OR,FVOL,ATT)
#define S_LocalSound(S) false
#define S_StartSound(ENT,CH,SF,OR,FV,ATT)
#define S_IsSoundPrecached(SF) false
#define S_ServerSounds(SV,NS)
#define S_PrecacheSound(SA,CM,LO) NULL
#define S_ExtraUpdate()
#define S_Update(MT)
#define S_Reload_f()
#define S_Shutdown()
#define S_Startup()
#define S_Terminate()
#define S_Init()
#endif
#endif
