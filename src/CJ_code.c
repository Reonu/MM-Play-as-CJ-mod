#include "modding.h"
#include "global.h"
#include "CJ_model.h"
#include "ultra64.h"

RECOMP_IMPORT("*", int recomp_printf(const char* fmt, ...));

extern Gfx* gPlayerRightHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandBowDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandInstrumentDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandHookshotDLs[2 * PLAYER_FORM_MAX];

extern Gfx* gPlayerLeftHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandTwoHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandOneHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandBottleDLs[2 * PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_MAX];

extern Gfx* gPlayerWaistDLs[2 * PLAYER_FORM_MAX];

extern Gfx* gLinkHumanGildedSwordHandleDL[];
extern Gfx* gLinkHumanGildedSwordBladeDL[];

extern Gfx* D_801C018C[];

Gfx gCJLeftHandHoldingGildedSwordDL[] = {
    gsSPDisplayList(gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque),
    gsSPDisplayList(gLinkHumanGildedSwordHandleDL),
    gsSPBranchList(gLinkHumanGildedSwordBladeDL),
};

RECOMP_HOOK("Player_Init") void on_Player_Init() {
    recomp_printf("Loading superman\n");
    gPlayerSkeletons[PLAYER_FORM_HUMAN] = &gCJSkel;
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;


    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone001_gLinkHumanWaistLimb_mesh_layer_Opaque;
    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone001_gLinkHumanWaistLimb_mesh_layer_Opaque;

    D_801C018C[4] = gCJLeftHandHoldingGildedSwordDL;
    D_801C018C[5] = gCJLeftHandHoldingGildedSwordDL;
}