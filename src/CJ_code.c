#include "modding.h"
#include "global.h"
#include "gCJSkel.h"
#include "cj_lefthand_closed.h"
#include "cj_righthand_closed.h"
#include "cj_ocarina.h"
#include "cj_bow.h"
#include "cj_hookshot.h"
#include "gBigSmokeSkel.h"
#include "ultra64.h"
#include "eztr_api.h"
#include "anims/gCJSkel_ocarinaGcj_ocarina_startAnim.h"
#include "anims/gCJSkel_ocarinaGcj_ocarina_swingAnim.h"

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
extern Gfx* gPlayerWaistDLs[2 * PLAYER_FORM_MAX];

extern Gfx* sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_MAX];

extern Gfx* gLinkHumanGildedSwordHandleDL[];
extern Gfx* gLinkHumanGildedSwordBladeDL[];

extern Gfx* gPlayerRightHandBowDLs[2 * PLAYER_FORM_MAX];

extern Gfx* gLinkHumanMirrorShieldDL[];
extern Gfx* gLinkHumanHerosShieldDL[];
extern Gfx* gKokiriSwordDL[];
extern Gfx* gRazorSwordDL[];
extern Gfx* gLinkHumanBowDL[];

extern Gfx* D_801C018C[];

extern Gfx gCJSkel_handsclosed_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque_tri_0[];
extern Gfx gCJSkel_handsclosed_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque_tri_0[];

Gfx gCJRightHandHoldingMirrorShieldDL[] = {
    gsSPDisplayList(gCJSkel_handsclosed_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque_tri_0),
    gsSPBranchList(gLinkHumanMirrorShieldDL),
};

Gfx gCJRightHandHoldingHeroShieldDL[] = {
    gsSPDisplayList(gCJSkel_handsclosed_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque_tri_0),
    gsSPBranchList(gLinkHumanHerosShieldDL),
};

Gfx gCJLeftHandHoldingGildedSwordDL[] = {
    gsSPDisplayList(gCJSkel_handsclosed_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque_tri_0),
    gsSPDisplayList(gLinkHumanGildedSwordHandleDL),
    gsSPBranchList(gLinkHumanGildedSwordBladeDL),
};

Gfx gCJLeftHandHoldingKokiriSwordDL[] = {
    gsSPDisplayList(gCJSkel_handsclosed_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque_tri_0),
    gsSPBranchList(gKokiriSwordDL),
};

Gfx gCJLeftHandHoldingRazorSwordDL[] = {
    gsSPDisplayList(gCJSkel_handsclosed_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque_tri_0),
    gsSPBranchList(gRazorSwordDL),
};

Gfx gCJRightHandHoldingBowDL[] = {
    gsSPDisplayList(gCJSkel_handsclosed_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque_tri_0),
    gsSPBranchList(gLinkHumanBowDL),
};


extern PlayerAgeProperties sPlayerAgeProperties[PLAYER_FORM_MAX];
static PlayerAgeProperties savedAgeProperties[2];
extern Gfx* gPlayerHandHoldingShields[];

extern LinkAnimationHeader gPlayerAnim_link_normal_okarina_start[];
extern LinkAnimationHeader gPlayerAnim_link_normal_okarina_swing[];

RECOMP_HOOK("Player_Update") void on_Player_Update(Actor* thisx, PlayState* play) {
    PlayerAgeProperties CJProperties;
    Player* player = GET_PLAYER(play);

    CJProperties = sPlayerAgeProperties[PLAYER_FORM_ZORA];
    CJProperties.unk_28 = 44.8f;
    CJProperties.unk_3C = 15.0f;
    CJProperties.unk_44 = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_44;
    CJProperties.unk_4A->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->x;
    CJProperties.unk_4A->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->y;
    CJProperties.unk_4A->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->z;
    CJProperties.unk_62->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->x;
    CJProperties.unk_62->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->y;
    CJProperties.unk_62->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->z;
    CJProperties.unk_7A->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->x;
    CJProperties.unk_7A->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->y;
    CJProperties.unk_7A->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->z;
    CJProperties.voiceSfxIdOffset = SFX_VOICE_BANK_SIZE * 0;
    CJProperties.surfaceSfxIdOffset = 0x80;
    sPlayerAgeProperties[PLAYER_FORM_HUMAN] = CJProperties;
    *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_normal_okarina_start) = gCJSkel_ocarinaGcj_ocarina_startAnim;
    *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_normal_okarina_swing) = gCJSkel_ocarinaGcj_ocarina_swingAnim;
}

RECOMP_HOOK("Player_Init") void on_Player_Init(Actor* thisx, PlayState* play) {
    gPlayerSkeletons[PLAYER_FORM_HUMAN] = &gCJSkel;
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_ocarina_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_ocarina_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
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

    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJRightHandHoldingBowDL;
    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJRightHandHoldingBowDL;

    sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_HUMAN] = gCJSkel_bone014_gLinkHumanLeftForearmLimb_mesh_layer_Opaque_tri_0;
    sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_HUMAN] = gCJSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque_tri_0;
    sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_HUMAN] = gCJSkel_bone017_gLinkHumanRightForearmLimb_mesh_layer_Opaque_tri_0;
    sPlayerFirstPersonRightHandDLs[PLAYER_FORM_HUMAN] = gCJSkel_bow_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_HUMAN] = gCJSkel_hookshot_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;


    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 0] = gCJSkel_bone001_gLinkHumanWaistLimb_mesh_layer_Opaque;
    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 1] = gCJSkel_bone001_gLinkHumanWaistLimb_mesh_layer_Opaque;

    gPlayerHandHoldingShields[0] = gCJRightHandHoldingHeroShieldDL;
    gPlayerHandHoldingShields[1] = gCJRightHandHoldingHeroShieldDL;
    gPlayerHandHoldingShields[2] = gCJRightHandHoldingMirrorShieldDL;
    gPlayerHandHoldingShields[3] = gCJRightHandHoldingMirrorShieldDL;


    D_801C018C[0] = gCJLeftHandHoldingKokiriSwordDL;
    D_801C018C[1] = gCJLeftHandHoldingKokiriSwordDL;
    D_801C018C[2] = gCJLeftHandHoldingRazorSwordDL;
    D_801C018C[3] = gCJLeftHandHoldingRazorSwordDL;
    D_801C018C[4] = gCJLeftHandHoldingGildedSwordDL;
    D_801C018C[5] = gCJLeftHandHoldingGildedSwordDL;
}

#define CJ_MASK_SCALE_MODIFIER 0.5f
#define CJ_MASK_DOWNWARDS_OFFSET -10.f
#define CJ_MASK_FORWARDS_OFSSEET 350.f
#define CJ_MASK_LATERAL_OFFSET 0.f
u8 gPushedMatrix;
extern Gfx* D_801C0B20[];
extern LinkAnimationHeader gPlayerAnim_cl_setmask;
RECOMP_HOOK("Player_PostLimbDrawGameplay") void on_Player_PostLimbDrawGameplay(PlayState* play, s32 limbIndex, Gfx** dList1, Gfx** dList2, Vec3s* rot, Actor* actor) {
    Player* player = (Player*)actor;
    if (limbIndex == PLAYER_LIMB_HEAD) {
        if (((*dList1 != NULL) && ((u32)player->currentMask != PLAYER_MASK_NONE)) &&
            (((player->transformation == PLAYER_FORM_HUMAN) &&
              ((player->skelAnime.animation != &gPlayerAnim_cl_setmask) || (player->skelAnime.curFrame >= 12.0f))) ||
             ((((player->transformation != PLAYER_FORM_HUMAN) && (player->currentMask >= PLAYER_MASK_FIERCE_DEITY)) &&
               ((player->transformation + PLAYER_MASK_FIERCE_DEITY) != player->currentMask)) &&
              (player->skelAnime.curFrame >= 10.0f)))) {   
                s32 maskMinusOne = player->currentMask - 1;
                OPEN_DISPS(play->state.gfxCtx);
                Matrix_Push();
                gPushedMatrix = 1;
                Matrix_Scale(CJ_MASK_SCALE_MODIFIER, CJ_MASK_SCALE_MODIFIER, CJ_MASK_SCALE_MODIFIER, MTXMODE_APPLY);
                Matrix_Translate(CJ_MASK_FORWARDS_OFSSEET, CJ_MASK_DOWNWARDS_OFFSET, CJ_MASK_LATERAL_OFFSET, MTXMODE_APPLY);
                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                CLOSE_DISPS(play->state.gfxCtx);
        } else {
            gPushedMatrix = 0;
        }    
    } else {
        gPushedMatrix = 0;
    }
}

RECOMP_HOOK_RETURN("Player_PostLimbDrawGameplay") void return_Player_PostLimbDrawGameplay(void) {
    if (gPushedMatrix) {
        Matrix_Pop();
    }
    gPushedMatrix = 0;
}

typedef struct BunnyEarKinematics {
    /* 0x0 */ Vec3s rot;
    /* 0x6 */ Vec3s angVel;
} BunnyEarKinematics; // size = 0xC

extern BunnyEarKinematics sBunnyEarKinematics;

RECOMP_PATCH void Player_DrawBunnyHood(PlayState* play) {
    Mtx* mtx = GRAPH_ALLOC(play->state.gfxCtx, 2 * sizeof(Mtx));
    Vec3s earRot;

    OPEN_DISPS(play->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x0B, mtx);

    Matrix_Push();

    earRot.x = sBunnyEarKinematics.rot.y + 0x3E2;
    earRot.y = sBunnyEarKinematics.rot.z + 0xDBE;
    earRot.z = sBunnyEarKinematics.rot.x - 0x348A;
    Matrix_SetTranslateRotateYXZ(97.0f + CJ_MASK_DOWNWARDS_OFFSET, -1203.0f - CJ_MASK_DOWNWARDS_OFFSET, -240.0f, &earRot);
    Matrix_Scale(CJ_MASK_SCALE_MODIFIER, CJ_MASK_SCALE_MODIFIER, CJ_MASK_SCALE_MODIFIER, MTXMODE_APPLY);

    Matrix_ToMtx(mtx++);

    earRot.x = sBunnyEarKinematics.rot.y - 0x3E2;
    earRot.y = -sBunnyEarKinematics.rot.z - 0xDBE;
    earRot.z = sBunnyEarKinematics.rot.x - 0x348A;
    Matrix_SetTranslateRotateYXZ(97.0f + CJ_MASK_DOWNWARDS_OFFSET, -1203.0f - CJ_MASK_DOWNWARDS_OFFSET, 240.0f, &earRot);
    Matrix_Scale(CJ_MASK_SCALE_MODIFIER, CJ_MASK_SCALE_MODIFIER, CJ_MASK_SCALE_MODIFIER, MTXMODE_APPLY);

    Matrix_ToMtx(mtx);

    Matrix_Pop();

    CLOSE_DISPS(play->state.gfxCtx);
}
extern FlexSkeletonHeader gHappyMaskSalesmanSkel;
RECOMP_HOOK("EnOsn_Init") void on_EnOsn_Init(Actor* thisx, PlayState* play) {
    *(FlexSkeletonHeader*)Lib_SegmentedToVirtual(&gHappyMaskSalesmanSkel) = gBigSmokeSkel;

}

RECOMP_HOOK ("EnOsn_Draw") void on_EnOsn_Draw(Actor* thisx, PlayState* play) {
    OPEN_DISPS(play->state.gfxCtx);
    Matrix_Push();
    Matrix_Translate(0.f, 1000.f, 0.f, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    CLOSE_DISPS(play->state.gfxCtx);
}

RECOMP_HOOK_RETURN ("EnOsn_Draw") void return_EnOsn_Draw(Actor* thisx, PlayState* play) {
    Matrix_Pop();
}

Player *gOriginalPlayer;
u8 gOriginalPlayerTransformation;

RECOMP_HOOK ("Player_GetHeight") void on_Player_GetHeight(Player* player) {
    gOriginalPlayer = player;
    gOriginalPlayerTransformation = player->transformation;
    player->transformation = PLAYER_FORM_ZORA;
}

RECOMP_HOOK_RETURN ("Player_GetHeight") void return_Player_GetHeight(void) {
    gOriginalPlayer->transformation = gOriginalPlayerTransformation;
}
