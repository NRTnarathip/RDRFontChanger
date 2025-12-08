#pragma once

#include "enums.h"
#include "nativeCaller.h"
#include "types.h"

// Generated Thu, 09 Jan 2025 17:46:57 GMT
// https://therouletteboi.github.io/rdr/nativedb/

namespace ACTOR
{
	static void TELEPORT_ACTOR(Actor actor, Vector3* coords, BOOL xAxis, BOOL yAxis, BOOL zAxis) { invoke<void>(0x2D54B916, actor, coords, xAxis, yAxis, zAxis); } // 0x2D54B916
	static void TELEPORT_ACTOR_WITH_HEADING(Actor actor, Vector2 coordsXY, float coordsZ, float heading, BOOL xAxis, BOOL yAxis, BOOL zAxis) { invoke<void>(0xE4DE507C, actor, coordsXY, coordsZ, heading, xAxis, yAxis, zAxis); } // 0xE4DE507C
	static void TELEPORT_ACTOR_WITH_HEADING(Actor actor, Vector3 coordsxy, float heading, BOOL xAxis, BOOL yAxis, BOOL zAxis) { invoke<void>(0xE4DE507C, actor, Vector2(coordsxy.x, coordsxy.y), coordsxy.z, heading, xAxis, yAxis, zAxis); } // 0xE4DE507C
	static float GET_MAX_SPEED(Actor actor) { return invoke<float>(0x6B3A39A9, actor); } // 0x6B3A39A9
	static void GET_POSITION(Actor actor, Vector3* position) { invoke<void>(0x99BD9D6F, actor, position); } // 0x99BD9D6F
	static float GET_HEADING(Actor actor) { return invoke<float>(0x42DE39F0, actor); } // 0x42DE39F0
	static void GET_ACTOR_AXIS(Actor actor, Vector3* axis, int p2) { invoke<void>(0x294A5549, actor, axis, p2); } // 0x294A5549
	static void SET_ACTOR_HEADING(Actor actor, float heading, BOOL p2) { invoke<void>(0xECE8520B, actor, heading, p2); } // 0xECE8520B
	static void SET_ACTOR_ONE_SHOT_DEATH(Actor actor, BOOL toggle) { invoke<void>(0xCDC686B2, actor, toggle); } // 0xCDC686B2
	static BOOL GET_ACTOR_ONE_SHOT_DEATH_STATUS(Actor actor) { return invoke<BOOL>(0x0912622D, actor); } // 0x0912622D
	static int GET_PHYSINST_FROM_ACTOR(Actor actor) { return invoke<int>(0x758F993A, actor); } // 0x758F993A
	static BOOL CAN_ACTOR_HOGTIE_TARGET(Actor actor, Actor target) { return invoke<BOOL>(0x1AA3A0C0, actor, target); } // 0x1AA3A0C0
	static BOOL IS_ACTOR_PLAYER(Actor actor) { return invoke<BOOL>(0xB27E91E7, actor); } // 0xB27E91E7
	static BOOL IS_ACTOR_LOCAL_PLAYER(Actor actor) { return invoke<BOOL>(0x6542CF26, actor); } // 0x6542CF26
	// Not present in the retail version! It just returns -1.
	static int GET_DEBUG_PADINDEX() { return invoke<int>(0xB114332D); } // 0xB114332D
	static int GET_PLAYER_PADINDEX(Actor actor) { return invoke<int>(0x524F6981, actor); } // 0x524F6981
	static int GET_PLAYER_PADINDEX_NO_ACTOR() { return invoke<int>(0xCF02D1D6); } // 0xCF02D1D6
	static void SET_PLAYER_PADINDEX(int p0, int p1) { invoke<void>(0x8F82B7D4, p0, p1); } // 0x8F82B7D4
	static int SET_ENABLE_NAV_STICK_INPUT(Any p0, Any p1) { return invoke<int>(0xC733BC9A, p0, p1); } // 0xC733BC9A
	static void SET_PLAYER_CONTROL(Player player, BOOL toggle, int possiblyFlags, BOOL p3) { invoke<void>(0xD17AFCD8, player, toggle, possiblyFlags, p3); } // 0xD17AFCD8
	static void SET_PLAYER_ENABLE_MOUNT_USE_CONTEXTS(Player player, BOOL toggle) { invoke<void>(0xBEEDDD54, player, toggle); } // 0xBEEDDD54
	static void SET_PLAYER_ALLOW_PICKUP(Player player, BOOL toggle) { invoke<void>(0xEA08A934, player, toggle); } // 0xEA08A934
	static void SET_PLAYER_MELEE_MODE_SELECTED(Player player, int mode) { invoke<void>(0xAC1285A3, player, mode); } // 0xAC1285A3
	static void SET_PLAYER_DISABLE_TARGETING(Player player, BOOL toggle) { invoke<void>(0x0959C27A, player, toggle); } // 0x0959C27A
	static int IS_PLAYER_CONTROLLABLE(Player player) { return invoke<int>(0x9613C2D0, player); } // 0x9613C2D0
	static BOOL IS_PLAYER_IN_COMBAT(Player player) { return invoke<BOOL>(0x6576AD43, player); } // 0x6576AD43
	static BOOL IS_PLAYER_IN_COMBAT_WITHIN(Player player, float p0) { return invoke<BOOL>(0x48B7C279, player, p0); } // 0x48B7C279
	static int SET_RETICLE_DRAW_DISABLED_BY_SCRIPT(Any p0, Any p1) { return invoke<int>(0xCE7CE46D, p0, p1); } // 0xCE7CE46D
	static void SET_PLAYER_CONTROL_RUMBLE(Player player, Any p1) { invoke<void>(0x4590CE00, player, p1); } // 0x4590CE00
	static void RESET_RUMBLE() { invoke<void>(0xB3BE2F95); } // 0xB3BE2F95
	static Any GET_PLAYER_CONTROL_CONFIG(Player player) { return invoke<Any>(0x8421033D, player); } // 0x8421033D
	static void SET_PLAYER_CONTROL_CONFIG(Player player, Any p1) { invoke<void>(0x01B84BCA, player, p1); } // 0x01B84BCA
	static void PLAYER_RUMBLE(Any p0, Any p1, Any p2) { invoke<void>(0x2E0EC2F2, p0, p1, p2); } // 0x2E0EC2F2
	static int SET_PLAYER_CURRENT_NOTORIETY(Player player, float value) { return invoke<int>(0x4B0D6152, player, value); } // 0x4B0D6152
	static int SET_PLAYER_CURRENT_HONOR(Player player, float value) { return invoke<int>(0x4D918005, player, value); } // 0x4D918005
	static void SET_PLAYER_COMBATMODE(Player player, Any p1) { invoke<void>(0x57595189, player, p1); } // 0x57595189
	static int GET_PLAYER_COMBATMODE() { return invoke<int>(0x86E193B8); } // 0x86E193B8
	static void SET_PLAYER_COMBATMODE_OVERRIDE(Player player, Any p1) { invoke<void>(0xAFFBBE78, player, p1); } // 0xAFFBBE78
	static int SET_PLAYER_COMBATMODE_EXCLUSION(Any p0) { return invoke<int>(0x1184EC7B, p0); } // 0x1184EC7B
	static void SET_PLAYER_VEHICLE_INPUT(Player player, Any p1, Any p2, Any p3) { invoke<void>(0xE1160B04, player, p1, p2, p3); } // 0xE1160B04
	static int ADD_PLAYER_CONTROL_HORSE_FOLLOW(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0x900165CE, p0, p1, p2, p3, p4, p5, p6); } // 0x900165CE
	static int REM_PLAYER_CONTROL_HORSE_FOLLOW(Any p0, Any p1) { return invoke<int>(0xBFC8EF7C, p0, p1); } // 0xBFC8EF7C
	static void CLEAR_PLAYER_CONTROL_HORSE_FOLLOW(Any p0, Any p1) { invoke<void>(0x7C522386, p0, p1); } // 0x7C522386
	static BOOL IS_PLAYER_IN_HORSE_FOLLOW(Player player, Any p1) { return invoke<BOOL>(0xE44DCE87, player, p1); } // 0xE44DCE87
	static Actor GET_PLAYER_ACTOR(Player player) { return invoke<Actor>(0xE8CFDD53, player); } // 0xE8CFDD53
	static BOOL IS_LOCAL_PLAYER(Any p0) { return invoke<BOOL>(0x40EF1003, p0); } // 0x40EF1003
	static BOOL IS_LOCAL_PLAYER_VALID(Actor actor) { return invoke<BOOL>(0x0ADC17E9, actor); } // 0x0ADC17E9
	static BOOL IS_SLOT_VALID(int slot) { return invoke<BOOL>(0xD04480FE, slot); } // 0xD04480FE
	static Any GET_SLOT_ACTOR(Any p0) { return invoke<Any>(0xDB9B49D8, p0); } // 0xDB9B49D8
	static int GET_ACTOR_SLOT(Actor actor) { return invoke<int>(0xAABF3356, actor); } // 0xAABF3356
	static int GET_LOCAL_SLOT() { return invoke<int>(0xAD68A22E); } // 0xAD68A22E
	static const char* GET_SLOT_NAME(int slot) { return invoke<const char*>(0x34CBABAE, slot); } // 0x34CBABAE
	static Any GET_SLOT_POSITION(int slot, Vector3* position) { return invoke<Any>(0x3241158C, slot, position); } // 0x3241158C
	static int GET_SLOT_FACING(Any p0, Any p1) { return invoke<int>(0x34A9866B, p0, p1); } // 0x34A9866B
	static BOOL IS_PLAYER_TARGETTING_ACTOR(Any p0, Any p1, Any p2) { return invoke<BOOL>(0x87DDCA96, p0, p1, p2); } // 0x87DDCA96
	static BOOL IS_PLAYER_TARGETTING_OBJECT(Any p0, Any p1) { return invoke<BOOL>(0x622796D5, p0, p1); } // 0x622796D5
	static BOOL IS_PLAYER_DEADEYE(Any p0) { return invoke<BOOL>(0x6148423A, p0); } // 0x6148423A
	static void SET_PLAYER_DEADEYE_MODE(Any p0, Any p1) { invoke<void>(0xB6A47C37, p0, p1); } // 0xB6A47C37
	static void SET_FORCE_PLAYER_AIM_MODE(Any p0, Any p1) { invoke<void>(0x1CFAF2EA, p0, p1); } // 0x1CFAF2EA
	static void SET_PLAYER_ENDLESS_READYMODE(Any p0, Any p1) { invoke<void>(0xD0E08B5E, p0, p1); } // 0xD0E08B5E
	static int GET_PLAYER_ZOOM_STATE(Any p0) { return invoke<int>(0xBC521A38, p0); } // 0xBC521A38
	static BOOL IS_PLAYER_USING_COVER(Any p0) { return invoke<BOOL>(0x724A2931, p0); } // 0x724A2931
	static void ATTACH_PLAYER_TO_COVER(Any p0, Any p1, Any p2) { invoke<void>(0x45F2A70A, p0, p1, p2); } // 0x45F2A70A
	static void SIMULATE_PLAYER_INPUT_GAIT(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x0D77CC34, p0, p1, p2, p3); } // 0x0D77CC34
	static void ACTOR_POP_NEXT_GAIT(Any p0, Any p1, Any p2) { invoke<void>(0xEAE75C6F, p0, p1, p2); } // 0xEAE75C6F
	static int ACTOR_SET_MAX_GAIT(Any p0, Any p1) { return invoke<int>(0x1ABFBFA3, p0, p1); } // 0x1ABFBFA3
	static BOOL IS_ACTOR_USING_COVER(Actor actor) { return invoke<BOOL>(0xD39C4A9E, actor); } // 0xD39C4A9E
	static BOOL IS_ACTOR_USING_LEDGE(Actor actor) { return invoke<BOOL>(0xEBBE1CAC, actor); } // 0xEBBE1CAC
	// points between 0.0f - 100.0f
	static void SET_PLAYER_DEADEYE_POINTS(Actor actor, float points, int p2) { invoke<void>(0x50D8C840, actor, points, p2); } // 0x50D8C840
	static void ADD_PLAYER_DEADEYE_POINTS(Any p0, Any p1, Any p2) { invoke<void>(0xE2C4AEE7, p0, p1, p2); } // 0xE2C4AEE7
	static float GET_PLAYER_DEADEYE_POINTS(Actor actor) { return invoke<float>(0x86B5C9E1, actor); } // 0x86B5C9E1
	static void SET_DISABLE_DEADEYE(Actor actor, BOOL toggle) { invoke<void>(0x09716951, actor, toggle); } // 0x09716951
	static void SET_DEADEYE_POINT_MODIFIER(Any p0, Any p1) { invoke<void>(0x0486955B, p0, p1); } // 0x0486955B
	static void SET_MAX_DEADEYE_POINTS(Actor actor, float maxPoints) { invoke<void>(0x526D45B7, actor, maxPoints); } // 0x526D45B7
	static void SET_DEADEYE_MULTILOCK_ENABLE(Actor actor, BOOL toggle) { invoke<void>(0x4E6E5E78, actor, toggle); } // 0x4E6E5E78
	static void SET_DEADEYE_TARGETPAINT_ENABLE(Actor actor, BOOL toggle) { invoke<void>(0x5CD6E2C3, actor, toggle); } // 0x5CD6E2C3
	static void SET_DEADEYE_INVULNERABILITY(Actor actor, BOOL toggle) { invoke<void>(0xA671FF8E, actor, toggle); } // 0xA671FF8E
	static void SET_DEADEYE_DAMAGE_SCALING(Actor actor, float p1) { invoke<void>(0x0D583DAF, actor, p1); } // 0x0D583DAF
	static int SET_DEADEYE_TIME_LIMIT(Any p0, float p1) { return invoke<int>(0x863F0193, p0, p1); } // 0x863F0193
	static void SET_DEADEYE_REGENERATION_RATE(Actor actor, float rate, Any p2) { invoke<void>(0x0415EE4C, actor, rate, p2); } // 0x0415EE4C
	static void SET_DEADEYE_REGENERATION_RATE_MULTIPLIER(Any p0, Any p1) { invoke<void>(0x151741A2, p0, p1); } // 0x151741A2
	static void SET_DEADEYE_TIMESCALE(Any p0, float p1) { invoke<void>(0x5740CDC2, p0, p1); } // 0x5740CDC2
	static void SET_INFINITE_DEADEYE(Actor actor, BOOL toggle) { invoke<void>(0x0C0BC04E, actor, toggle); } // 0x0C0BC04E
	// sagActorScript::LastTimeShotNearby
	static float GET_TIME_PLAYER_SHOT_CLOSE(Any p0) { return invoke<float>(0x7F454A92, p0); } // 0x7F454A92
	static int SET_WAGON_TO_WAGON_JACK_ENABLE(Any p0, Any p1) { return invoke<int>(0xFA8D2B69, p0, p1); } // 0xFA8D2B69
	static void SET_PLAYER_POSTURE(int p0, int p1, int p2) { invoke<void>(0x3BD4426B, p0, p1, p2); } // 0x3BD4426B
	static void SET_ACTOR_ALLOW_DISMOUNT(Actor actor, Any p1) { invoke<void>(0xC550644A, actor, p1); } // 0xC550644A
	static void SET_ACTOR_INVULNERABILITY(Actor actor, BOOL toggle) { invoke<void>(0xE38EF526, actor, toggle); } // 0xE38EF526
	static BOOL GET_ACTOR_INVULNERABILITY(Actor actor) { return invoke<BOOL>(0xDB39D992, actor); } // 0xDB39D992
	static void SET_TOUGH_ACTOR(Actor actor, BOOL toggle) { invoke<void>(0x2A575132, actor, toggle); } // 0x2A575132
	static void SET_ACTOR_UNKILLABLE(Actor actor, BOOL toggle) { invoke<void>(0x0D9A35F6, actor, toggle); } // 0x0D9A35F6
	static int SET_ACTOR_PERMANENT(Any p0) { return invoke<int>(0xB4CD475D, p0); } // 0xB4CD475D
	static int SET_ACTOR_PERMANENT_DEAD(Any p0) { return invoke<int>(0x731F2C21, p0); } // 0x731F2C21
	static int SET_ACTOR_FROZEN_AFTER_CORPSIFY(Any p0) { return invoke<int>(0xED89D0E0, p0); } // 0xED89D0E0
	static void CLEAR_ACTOR_PROOF(Any p0, Any p1) { invoke<void>(0xF5B74E20, p0, p1); } // 0xF5B74E20
	static int CLEAR_ACTOR_PROOF_ALL(int result, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x9E7AE28B, result, p1, p2, p3, p4); } // 0x9E7AE28B
	static int GET_ACTOR_PROOF(Any p0) { return invoke<int>(0x147EA072, p0); } // 0x147EA072
	static void SET_ACTOR_PROOF(Any p0, Any p1) { invoke<void>(0xA5875DC8, p0, p1); } // 0xA5875DC8
	static int SET_ACTOR_OVERHEALTH_MODE(Any p0) { return invoke<int>(0xF2F77F44, p0); } // 0xF2F77F44
	static int ACTOR_REPAIR_INCAPACITATION(Any p0) { return invoke<int>(0x437588E6, p0); } // 0x437588E6
	static int GET_ACTOR_INCAPACITATED(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xEE4E2461, p0, p1, p2, p3); } // 0xEE4E2461
	static void SET_ALLOW_RIDE_BY_AI(Any p0, Any p1) { invoke<void>(0x2D9C0C0F, p0, p1); } // 0x2D9C0C0F
	static int GET_ALLOW_RIDE_BY_PLAYER(Any p0) { return invoke<int>(0x0318FF2A, p0); } // 0x0318FF2A
	static void SET_ALLOW_RIDE_BY_PLAYER(Actor actor, BOOL allowed) { invoke<void>(0xCF1A1BC5, actor, allowed); } // 0xCF1A1BC5
	static int SET_ALLOW_RIDE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xF83A8D2B, p0, p1, p2, p3, p4, p5); } // 0xF83A8D2B
	static BOOL GET_ALLOW_RIDE(Any p0) { return invoke<BOOL>(0x0111E8E0, p0); } // 0x0111E8E0
	static void SET_ALLOW_JACK(Any p0, Any p1) { invoke<void>(0x5D5BD1F0, p0, p1); } // 0x5D5BD1F0
	static void SET_ALLOW_EXECUTE(Any p0, Any p1) { invoke<void>(0x5896817B, p0, p1); } // 0x5896817B
	static void SET_ALLOW_DEADEYE_LOCKS(Any p0, Any p1) { invoke<void>(0xA1BFC1A5, p0, p1); } // 0xA1BFC1A5
	static void SET_DEADEYE_LOCKS_ON_HEAD_ONLY(Any p0, Any p1) { invoke<void>(0x9375946B, p0, p1); } // 0x9375946B
	static int SET_ALLOW_MELEE_SPECIAL_MOVE(Any p0, Any p1) { return invoke<int>(0x740B78A8, p0, p1); } // 0x740B78A8
	static int SET_ALLOW_LASSO_MINI_GAME(Any p0, Any p1) { return invoke<int>(0x7A11D611, p0, p1); } // 0x7A11D611
	static void ACTOR_DISMOUNT_NOW(Actor actor) { invoke<void>(0x0666B436, actor); } // 0x0666B436
	static BOOL IS_ACTOR_REACTING(Actor actor) { return invoke<BOOL>(0xBFD6AE3D, actor); } // 0xBFD6AE3D
	static int GET_ACTOR_UPDATE_PRIORITY(Actor actor) { return invoke<int>(0x6D322CD3, actor); } // 0x6D322CD3
	static void SET_ACTOR_UPDATE_PRIORITY(Actor actor, int priority) { invoke<void>(0x44C05EF6, actor, priority); } // 0x44C05EF6
	static int _SET_ACTOR_FORCE_HIGH_LOD_UPDATE(Any p0, Any p1) { return invoke<int>(0xA4E29C31, p0, p1); } // 0xA4E29C31
	static void ACTOR_FORCE_NEXT_UPDATE(Actor actor) { invoke<void>(0x5C7F63E3, actor); } // 0x5C7F63E3
	static int IS_ANY_ACTOR_IN_SPHERE(Any p0, float p1) { return invoke<int>(0x87C49DBD, p0, p1); } // 0x87C49DBD
	static Any SET_NPC_TO_NPC_CRIPPLE_DISABLE(Any result) { return invoke<Any>(0xB42EBC65, result); } // 0xB42EBC65
	static void SET_NPC_TO_NPC_DAMAGE_SCALE_FACTOR(float p0) { invoke<void>(0x135EA21D, p0); } // 0x135EA21D
	static void SET_PLAYER_TO_PLAYER_DAMAGE_SCALE_FACTOR(float p0) { invoke<void>(0xA393AC4E, p0); } // 0xA393AC4E
	static void SET_NPC_TO_ACTOR_DAMAGE_SCALE_FACTOR(Any p0, Any p1) { invoke<void>(0x05CFE1E9, p0, p1); } // 0x05CFE1E9
	static int SET_ACTOR_LOW_DROP_DAMAGE(int p0, float p1) { return invoke<int>(0x083903D1, p0, p1); } // 0x083903D1
	static int SET_ACTOR_MEDIUM_DROP_DAMAGE(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, float p8) { return invoke<int>(0x1540A309, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x1540A309
	static int SET_ACTOR_HIGH_DROP_DAMAGE(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, float p8) { return invoke<int>(0x7CC57FDA, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x7CC57FDA
	static void SET_ACTOR_DEATH_DROP_DISTANCE(Any p0, Any p1) { invoke<void>(0x9F6B04C8, p0, p1); } // 0x9F6B04C8
	static void SET_DAMAGE_SCALE_ENABLE(Any p0, Any p1) { invoke<void>(0xDA0CDC91, p0, p1); } // 0xDA0CDC91
	static void SET_CRIPPLE_ENABLE(Any p0, Any p1) { invoke<void>(0x3AD31762, p0, p1); } // 0x3AD31762
	static void SET_CRIPPLE_FLAG(Any p0, Any p1) { invoke<void>(0x0A9A99DF, p0, p1); } // 0x0A9A99DF
	static BOOL IS_ACTOR_CRIPPLED(Actor actor, int p1) { return invoke<BOOL>(0x38C5F63F, actor, p1); } // 0x38C5F63F
	static BOOL IS_ACTOR_HANDSUP(Actor actor) { return invoke<BOOL>(0xA5A24484, actor); } // 0xA5A24484
	static void SET_ALLOW_COLD_WEATHER_BREATH(Any p0, Any p1) { invoke<void>(0xA4677DD2, p0, p1); } // 0xA4677DD2
	static int SET_DLC_FALLBACK_AVATAR(Any p0) { return invoke<int>(0x1F0CD262, p0); } // 0x1F0CD262
	static void SET_EMOTION(Any p0, Any p1, Any p2) { invoke<void>(0x1D1D9387, p0, p1, p2); } // 0x1D1D9387
	static int SET_ACTOR_STOP_UPDATE(Actor actor, BOOL toggle) { return invoke<int>(0xC0F77310, actor, toggle); } // 0xC0F77310
	static BOOL GET_ACTOR_STOP_UPDATE(Actor actor) { return invoke<BOOL>(0x4EFC58BC, actor); } // 0x4EFC58BC
	static BOOL IS_ACTOR_IN_ROOM(Actor actor) { return invoke<BOOL>(0x22558E3F, actor); } // 0x22558E3F
	static void REGISTER_TRAFFIC_OBJECTSET(Any p0) { invoke<void>(0x398735FA, p0); } // 0x398735FA
	static void REGISTER_TRAFFIC_ACTOR(Any p0, Any p1) { invoke<void>(0x67FA18A1, p0, p1); } // 0x67FA18A1
	static void REGISTER_GPS_CURVE_OBJECTSET(Any p0) { invoke<void>(0x1444F022, p0); } // 0x1444F022
	static void SET_PLAYER_TARGET_WEIGHT(float p0) { invoke<void>(0x4B90D22A, p0); } // 0x4B90D22A
	static void RESET_PLAYER_TARGET_WEIGHT() { invoke<void>(0xF1779E65); } // 0xF1779E65
	static void SET_HARDLOCK_TARGET_ANGLE_WEIGHTING(float p0, float p1) { invoke<void>(0xA819497B, p0, p1); } // 0xA819497B
	static Any SET_ZOMBIE_TARGET_MODE(Any p0) { return invoke<Any>(0x8BE2D8B0, p0); } // 0x8BE2D8B0
	static int SET_ACTOR_SKIP_VISIBILITY_CHECK(Any p0, Any p1) { return invoke<int>(0x91BB8548, p0, p1); } // 0x91BB8548
	static BOOL GET_ACTOR_SKIP_VISIBILITY_CHECK(Any p0) { return invoke<BOOL>(0x8AE58EE1, p0); } // 0x8AE58EE1
	static void FEED_CODE_WARP_DIST(Any p0) { invoke<void>(0xDE0E96F3, p0); } // 0xDE0E96F3
	// PC only
	static Any GET_HOLD_TO_SPRINT(Any p0) { return invoke<Any>(0x968F0317, p0); } // 0x968F0317
	static void SET_ACTOR_STREAMING_HIGH_PRIORITY(Actor actor, BOOL toggle) { invoke<void>(0x0911BA31, actor, toggle); } // 0x0911BA31
}

namespace ACTORSET
{
	static ActorSet CREATE_ACTORSET_IN_LAYOUT(Layout layout, const char* layoutName, BOOL isActive) { return invoke<ActorSet>(0x009DFC82, layout, layoutName, isActive); } // 0x009DFC82
	static BOOL IS_ACTORSET_VALID(ActorSet actorSet) { return invoke<BOOL>(0x76E8975E, actorSet); } // 0x76E8975E
	static ActorSet FIND_NAMED_ACTORSET(const char* actorSetName) { return invoke<ActorSet>(0x5454B159, actorSetName); } // 0x5454B159
	static void DESTROY_ACTORSET(ActorSet actorSet) { invoke<void>(0x147A0BEE, actorSet); } // 0x147A0BEE
	static void DISBAND_ACTORSET(ActorSet actorSet) { invoke<void>(0x2739F04D, actorSet); } // 0x2739F04D
	static void ADD_ACTORSET_MEMBER(ActorSet actorSet, Actor actor) { invoke<void>(0xE09DB6C1, actorSet, actor); } // 0xE09DB6C1
	static void REMOVE_ACTORSET_MEMBER(ActorSet actorSet, Actor actor) { invoke<void>(0xD637E449, actorSet, actor); } // 0xD637E449
	static BOOL IS_ACTOR_IN_ACTORSET(ActorSet actorSet, Actor actor) { return invoke<BOOL>(0xC6FE68DF, actorSet, actor); } // 0xC6FE68DF
	static Actor GET_ACTOR_FROM_ACTORSET(ActorSet actorSet, BOOL isActive) { return invoke<Actor>(0xC5202810, actorSet, isActive); } // 0xC5202810
	static int GET_ACTORSET_SIZE(ActorSet actorSet) { return invoke<int>(0xA24F4799, actorSet); } // 0xA24F4799
}

namespace ACTOR_DRAW
{
	static void SET_DRAW_ACTOR(Actor actor, BOOL drawActor) { invoke<void>(0xE6644CE5, actor, drawActor); } // 0xE6644CE5
	static BOOL GET_DRAW_ACTOR(Actor actor) { return invoke<BOOL>(0x085A9CA6, actor); } // 0x085A9CA6
}

namespace AI_ANIMAL
{
	static void ANIMAL_SPECIES_FLOCK_AND_TUNING_CLEAR_ALL() { invoke<void>(0x5EFB415E); } // 0x5EFB415E
	static void ANIMAL_SPECIES_NEEDS_DOMESTICATION_LEVELS(int level) { invoke<void>(0x1FD8BA91, level); } // 0x1FD8BA91
	static void ANIMAL_SPECIES_SET_SPECIAL_USE_GRINGO(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x11DCCDAA, p0, p1, p2, p3, p4); } // 0x11DCCDAA
	static void ANIMAL_SPECIES_SET_UNALERTED_BEHAVIOR(int speciesId, int useCaseId, const char* scriptPath, const char* useCaseName, int priority) { invoke<void>(0x6B6191EE, speciesId, useCaseId, scriptPath, useCaseName, priority); } // 0x6B6191EE
	static void ANIMAL_SPECIES_FLOCK_SET_ENABLED(int speciesId, int flockType, BOOL isEnabled, int behaviorMode) { invoke<void>(0x4DF576A7, speciesId, flockType, isEnabled, behaviorMode); } // 0x4DF576A7
	static void ANIMAL_SPECIES_FLOCK_SET_PARAMETER(int speciesId, int flockType, int parameterId, float value, int behaviorMode) { invoke<void>(0xBF12100D, speciesId, flockType, parameterId, value, behaviorMode); } // 0xBF12100D
	static void ANIMAL_SPECIES_FLOCK_SET_BOOLEAN_PARAMETER(int speciesId, int flockType, int parameterId, int value, int behaviorMode) { invoke<void>(0x7C795382, speciesId, flockType, parameterId, value, behaviorMode); } // 0x7C795382
	static void ANIMAL_SPECIES_ADD_EXTERNAL_PATH_ATTRACTION(int speciesId, float* position, int reference, float distance, float parameter1, float parameter2, float parameter3, int behaviorMode) { invoke<void>(0x338D1CEC, speciesId, position, reference, distance, parameter1, parameter2, parameter3, behaviorMode); } // 0x338D1CEC
	static void ANIMAL_SPECIES_REMOVE_EXTERNAL_PATH_ATTRACTION(int speciesId, int reference, int behaviorMode) { invoke<void>(0xF2110753, speciesId, reference, behaviorMode); } // 0xF2110753
	static void ANIMAL_SPECIES_ADD_EXTERNAL_RANDOM_NOISE(int speciesId, float minNoise, float maxNoise, float baselineNoise, int behaviorMode) { invoke<void>(0x784C514C, speciesId, minNoise, maxNoise, baselineNoise, behaviorMode); } // 0x784C514C
	static void ANIMAL_SPECIES_ADD_EXTERNAL_REPULSION(int speciesId, float targetSpeciesId, float repulsionStrength, float repulsionRadius, int behaviorMode) { invoke<void>(0x4217D912, speciesId, targetSpeciesId, repulsionStrength, repulsionRadius, behaviorMode); } // 0x4217D912
	static void ANIMAL_SPECIES_ADD_EXTERNAL_INFLUENCE_FLOCK_REASONER(int speciesId, int reasoningType) { invoke<void>(0x9D8C2744, speciesId, reasoningType); } // 0x9D8C2744
	static float ANIMAL_SPECIES_TUNING_GET_ATTRIB_FLOAT(int speciesId, int attributeId, BOOL isSpecialCondition) { return invoke<float>(0x8020C45E, speciesId, attributeId, isSpecialCondition); } // 0x8020C45E
	static void ANIMAL_SPECIES_TUNING_SET_ATTRIB_BOOL(int speciesId, int attributeId, BOOL toggle, int context) { invoke<void>(0x651ACCB1, speciesId, attributeId, toggle, context); } // 0x651ACCB1
	static void ANIMAL_SPECIES_TUNING_SET_ATTRIB_FLOAT(int speciesId, int attributeId, float value, int context) { invoke<void>(0x20AD711E, speciesId, attributeId, value, context); } // 0x20AD711E
	static void ANIMAL_SPECIES_TUNING_MOVE_SET_ATTRIB(int speciesId, int attributeId, float value, int* context) { invoke<void>(0x10CC05F1, speciesId, attributeId, value, context); } // 0x10CC05F1
	static void ANIMAL_SPECIES_TUNING_SET_ATTACHMENT_WITH_OFFSET(const char* attachmentName, float posX, float posY, float posZ, float rotX, float rotY, float rotZ) { invoke<void>(0xA6A4651B, attachmentName, posX, posY, posZ, rotX, rotY, rotZ); } // 0xA6A4651B
	static void ANIMAL_SPECIES_TUNING_SET_ATTACHMENT_WITH_CHILDBONE(int attachmentId, int attachmentType, const char* parentBone, const char* childBone) { invoke<void>(0x168AAB9B, attachmentId, attachmentType, parentBone, childBone); } // 0x168AAB9B
	static void ANIMAL_SPECIES_TUNING_SET_HUNTING_PREY_PROP(int preyId, const char* preyPropName) { invoke<void>(0xD05DDBB6, preyId, preyPropName); } // 0xD05DDBB6
	static void ANIMAL_SPECIES_TUNING_SET_ATTRIB_FLOAT_FROM_TIME(int speciesId, int attribId, int timeOfDay, int flag) { invoke<void>(0x96B26945, speciesId, attribId, timeOfDay, flag); } // 0x96B26945
	static void ANIMAL_SPECIES_INIT_BEGIN(int speciesId) { invoke<void>(0xE228CC1A, speciesId); } // 0xE228CC1A
	// AnimalSpecies:
	// enum eAnimalSpecies
	// {
	// 	ANIMAL_SPECIES_HUMAN = 0,
	// 	ANIMAL_SPECIES_NARMADILLO = 1,
	// 	ANIMAL_SPECIES_BAT = 2,
	// 	ANIMAL_SPECIES_BEAR = 3,
	// 	ANIMAL_SPECIES_BEAVER = 4,
	// 	ANIMAL_SPECIES_BIGHORN = 5,
	// 	ANIMAL_SPECIES_BOAR = 6,
	// 	ANIMAL_SPECIES_BOBCAT = 7,
	// 	ANIMAL_SPECIES_BUFFALO = 8,
	// 	ANIMAL_SPECIES_BULL = 9,
	// 	ANIMAL_SPECIES_CHICKEN = 10,
	// 	ANIMAL_SPECIES_COUGAR = 11,
	// 	ANIMAL_SPECIES_COW = 12,
	// 	ANIMAL_SPECIES_COYOTE = 13,
	// 	ANIMAL_SPECIES_CROW = 14,
	// 	ANIMAL_SPECIES_DEER = 15,
	// 	ANIMAL_SPECIES_DOG = 16,
	// 	ANIMAL_SPECIES_DUCK = 17,
	// 	ANIMAL_SPECIES_EAGLE = 18,
	// 	ANIMAL_SPECIES_ELK = 19,
	// 	ANIMAL_SPECIES_FOX = 20,
	// 	ANIMAL_SPECIES_GOAT = 21,
	// 	ANIMAL_SPECIES_HAWK = 22,
	// 	ANIMAL_SPECIES_HORSE = 23,
	// 	ANIMAL_SPECIES_MULE = 24,
	// 	ANIMAL_SPECIES_OWL = 25,
	// 	ANIMAL_SPECIES_PIG = 26,
	// 	ANIMAL_SPECIES_RABBIT = 27,
	// 	ANIMAL_SPECIES_RACCOON = 28,
	// 	ANIMAL_SPECIES_SHEEP = 29,
	// 	ANIMAL_SPECIES_SKUNK = 30,
	// 	ANIMAL_SPECIES_SNAKE = 31,
	// 	ANIMAL_SPECIES_SONGBIRD = 32,
	// 	ANIMAL_SPECIES_NSTREETDOG = 33,
	// 	ANIMAL_SPECIES_VULTURE = 34,
	// 	ANIMAL_SPECIES_WOLF = 35
	// };
	static void ANIMAL_SPECIES_INIT_REGISTER(int speciesId, const char* speciesName) { invoke<void>(0xED6240F0, speciesId, speciesName); } // 0xED6240F0
	static void ANIMAL_SPECIES_INIT_END() { invoke<void>(0x00760C27); } // 0x00760C27
	static void ANIMAL_SPECIES_GRINGO_CLEAR_ALL() { invoke<void>(0xD4DDC119); } // 0xD4DDC119
	static void ANIMAL_SPECIES_GRINGO_LOAD_ALL() { invoke<void>(0xBFB65BE8); } // 0xBFB65BE8
	static void ANIMAL_SPECIES_REL_CLEAR_ALL() { invoke<void>(0x98073A48); } // 0x98073A48
	static void ANIMAL_SPECIES_REL_SET_ATTACK_GRAB_ENABLED(int speciesId, int actionId, BOOL toggle) { invoke<void>(0x1E02527F, speciesId, actionId, toggle); } // 0x1E02527F
	static void ANIMAL_SPECIES_REL_SET_PREDATOR_AND_PREY(int predatorId, int preyId) { invoke<void>(0x84B474ED, predatorId, preyId); } // 0x84B474ED
	static void ANIMAL_SPECIES_REL_SET_THREAT(int speciesId, int threatId, BOOL isThreatened) { invoke<void>(0x9D5C43C9, speciesId, threatId, isThreatened); } // 0x9D5C43C9
	static void ANIMAL_SPECIES_REL_SET_AVOID(int speciesId, int avoidSpeciesId, BOOL isAvoiding) { invoke<void>(0xBF8B1BD7, speciesId, avoidSpeciesId, isAvoiding); } // 0xBF8B1BD7
	static void ANIMAL_SPECIES_REL_SET_PLAY_HUNT(int predatorId, int preyId, BOOL isHunting) { invoke<void>(0x3F747178, predatorId, preyId, isHunting); } // 0x3F747178
	static void ANIMAL_SPECIES_REL_SET_PLAY_CHASE(int predatorId, int preyId, BOOL isChasing) { invoke<void>(0x586904BD, predatorId, preyId, isChasing); } // 0x586904BD
	static void ANIMAL_SPECIES_REL_SET_PLAY_BEG(int speciesId, int actionId, BOOL enable) { invoke<void>(0x70C48A1C, speciesId, actionId, enable); } // 0x70C48A1C
	static void ANIMAL_SPECIES_REL_SET_PLAY_GROWL(int speciesId, int targetSpeciesId, BOOL enable) { invoke<void>(0x70DE500E, speciesId, targetSpeciesId, enable); } // 0x70DE500E
	static void ANIMAL_SPECIES_REL_SET_PLAY_SNIFF(int speciesId, int targetSpeciesId, BOOL enable) { invoke<void>(0x6606A669, speciesId, targetSpeciesId, enable); } // 0x6606A669
	static int ANIMAL_SPECIES_REL_GET_CAN_ATTACK(int attackerSpeciesId, int targetSpeciesId) { return invoke<int>(0x3C5700DC, attackerSpeciesId, targetSpeciesId); } // 0x3C5700DC
	static void ANIMAL_SPECIES_REL_SET_CAN_ATTACK(int attackerSpeciesId, BOOL canAttack, BOOL isPredator) { invoke<void>(0xC8B4CD3F, attackerSpeciesId, canAttack, isPredator); } // 0xC8B4CD3F
	static void ANIMAL_SPECIES_REL_SET_CAN_WARN(int warningSpeciesId, int targetSpeciesId, BOOL canWarn) { invoke<void>(0x0482DD4E, warningSpeciesId, targetSpeciesId, canWarn); } // 0x0482DD4E
	static void ANIMAL_SPECIES_REL_SET_EAT_GRINGO(int animalSpeciesId, int foodId, int eatingIntensity) { invoke<void>(0xB5A63B67, animalSpeciesId, foodId, eatingIntensity); } // 0xB5A63B67
	static int ANIMAL_ACTOR_GET_DOMESTICATION(int animalId) { return invoke<int>(0xCE23118D, animalId); } // 0xCE23118D
	static void ANIMAL_ACTOR_SET_DOMESTICATION(int animalId, int domesticationStatus) { invoke<void>(0x58C36502, animalId, domesticationStatus); } // 0x58C36502
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eSpecies
	static int ANIMAL_ACTOR_GET_SPECIES(Actor actor) { return invoke<int>(0x7D0E25DF, actor); } // 0x7D0E25DF
	static void ANIMAL_TUNING_SET_ATTRIB_BOOL(int animalActor, int attribId, BOOL toggle) { invoke<void>(0x11150810, animalActor, attribId, toggle); } // 0x11150810
	static void ANIMAL_TUNING_SET_ATTRIB_FLOAT(int animalActor, int attribId, float value) { invoke<void>(0xE36EA080, animalActor, attribId, value); } // 0xE36EA080
	static void ANIMAL_ACTOR_SET_DOCILE(Actor actor, BOOL docileState) { invoke<void>(0xABFCFF01, actor, docileState); } // 0xABFCFF01
	static BOOL ANIMAL_ACTOR_GET_DOCILE(Actor actor) { return invoke<BOOL>(0xAAA8AF88, actor); } // 0xAAA8AF88
	static int ANIMAL_ACTOR_GET_GRABBED_BY(Actor actor) { return invoke<int>(0x57DF8CD0, actor); } // 0x57DF8CD0
}

namespace AI_ATTENTION
{
	static int ADD_FIXED_ATTENTION_TARGET(Any p0, Any p1, float p2, float p3, float p4, float p5, float p6) { return invoke<int>(0x945F518F, p0, p1, p2, p3, p4, p5, p6); } // 0x945F518F
}

namespace AI_COMBAT
{
	static void COMBAT_CLASS_AI_CLEAR_ALL_ATTRIBS(Any p0) { invoke<void>(0x13FA7128, p0); } // 0x13FA7128
	static int COMBAT_CLASS_AI_GET_ATTRIB_BOOL(Any p0, Any p1) { return invoke<int>(0xE39B4D25, p0, p1); } // 0xE39B4D25
	static int COMBAT_CLASS_AI_GET_ATTRIB_FLOAT(Any p0, Any p1) { return invoke<int>(0xAAD75024, p0, p1); } // 0xAAD75024
	static int COMBAT_CLASS_AI_GET_RANGE_ACCURACY(Any p0) { return invoke<int>(0x983DB127, p0); } // 0x983DB127
	static void COMBAT_CLASS_AI_SET_ATTRIB_BOOL(Any p0, Any p1, Any p2) { invoke<void>(0x69C5ADD2, p0, p1, p2); } // 0x69C5ADD2
	static void COMBAT_CLASS_AI_SET_ATTRIB_FLOAT(Any p0, Any p1, Any p2) { invoke<void>(0x80D51606, p0, p1, p2); } // 0x80D51606
	static void COMBAT_CLASS_AI_SET_FIGHT_ATTACK_DISTANCE(Any p0, Any p1, Any p2) { invoke<void>(0x6389CF4B, p0, p1, p2); } // 0x6389CF4B
	static void COMBAT_CLASS_AI_SET_FIGHT_DESIRED_DISTANCE(Any p0, Any p1, Any p2) { invoke<void>(0xE20587E7, p0, p1, p2); } // 0xE20587E7
	static int COMBAT_CLASS_AI_SET_FIGHT_TIME_BETWEEN_ATTACKS_MULTIPLIER(Any p0, float p1) { return invoke<int>(0x0EF1436B, p0, p1); } // 0x0EF1436B
	static void COMBAT_CLASS_AI_SET_FIGHT_TIME_BETWEEN_ATTACKS(Any p0, Any p1) { invoke<void>(0x1EF0E419, p0, p1); } // 0x1EF0E419
	static void COMBAT_CLASS_AI_SET_FRIENDLY_FIRE_CONSIDERATION(Any p0, Any p1) { invoke<void>(0xF1454677, p0, p1); } // 0xF1454677
	static void COMBAT_CLASS_AI_SET_RANGE_ACCURACY(Actor actor, float accuracy) { invoke<void>(0x60B705A5, actor, accuracy); } // 0x60B705A5
	static void COMBAT_CLASS_AI_SET_RANGE_BETWEEN_BURSTS_DELAY(Any p0, Any p1, Any p2) { invoke<void>(0xC30DB881, p0, p1, p2); } // 0xC30DB881
	static void COMBAT_CLASS_NAME_REGISTER_INT(Any p0, Any p1) { invoke<void>(0x8DE6AF29, p0, p1); } // 0x8DE6AF29
	static int COMBAT_CLASS_REQUEST_EXISTS() { return invoke<int>(0x629E2E88); } // 0x629E2E88
	static int COMBAT_CLASS_REQUEST_GET_ACTOR() { return invoke<int>(0x0EDD5D43); } // 0x0EDD5D43
	static int COMBAT_CLASS_REQUEST_GET_ENUM_INT() { return invoke<int>(0x76478D6E); } // 0x76478D6E
	static void COMBAT_CLASS_REQUEST_COMPLETED() { invoke<void>(0xE66AD206); } // 0xE66AD206
	static void COMBAT_CLASS_SERVER_SET_SCRIPT(Any p0) { invoke<void>(0xAD3877AF, p0); } // 0xAD3877AF
	static void AI_COMBAT_SET_NEW_STATE_MACHINE_ENABLED(Any p0, Any p1) { invoke<void>(0x7F73E1E8, p0, p1); } // 0x7F73E1E8
}

namespace AI_CONVERSE
{
	static Any AI_CONVERSE_SET_GREETING_CONTEXT(Any p0) { return invoke<Any>(0x30402375, p0); } // 0x30402375
	static Any AI_CONVERSE_SET_GOSSIP_AMBIENT_CONTEXT(Any p0) { return invoke<Any>(0x7922F870, p0); } // 0x7922F870
	static Any AI_CONVERSE_SET_GOSSIP_REPLY_CONTEXT(Any p0) { return invoke<Any>(0x663723A0, p0); } // 0x663723A0
	static Any AI_CONVERSE_SET_GOODBYE_START_CONTEXT(Any p0) { return invoke<Any>(0x93CFB180, p0); } // 0x93CFB180
	static Any AI_CONVERSE_SET_GOODBYE_CONTEXT(Any p0) { return invoke<Any>(0xA1FCBA24, p0); } // 0xA1FCBA24
	static int AI_CONVERSE_INIT_CAMPFIRE_CONTEXT_STORAGE() { return invoke<int>(0x7ED8B78C); } // 0x7ED8B78C
	static Any AI_CONVERSE_SET_CAMPFIRE_INVITE_CONTEXT(Any p0) { return invoke<Any>(0xD4871BDB, p0); } // 0xD4871BDB
	static int AI_CONVERSE_SET_CAMPFIRE_CONTEXT(Any p0, Any p1) { return invoke<int>(0xA88359B9, p0, p1); } // 0xA88359B9
	static int AI_CONVERSE_SET_CAMPFIRE_STORY_CONTEXT(Any p0, Any p1) { return invoke<int>(0xAD42EABC, p0, p1); } // 0xAD42EABC
	static Any AI_CONVERSE_SET_CAMPFIRE_STORY_DONE_CONTEXT(Any p0) { return invoke<Any>(0xC65F6751, p0); } // 0xC65F6751
	static Any AI_CONVERSE_SET_CAMPFIRE_STORY_LEAVE_CONTEXT(Any p0) { return invoke<Any>(0x83CBD612, p0); } // 0x83CBD612
	static Any AI_CONVERSE_SET_CAMPFIRE_RESPONSE_CONTEXT(Any p0) { return invoke<Any>(0x4AD2BC30, p0); } // 0x4AD2BC30
	static Any AI_SET_CAMPFIRE_STORY_ENABLED(Any p0) { return invoke<Any>(0xC1F9A360, p0); } // 0xC1F9A360
	static Any AI_CONVERSE_SET_GIDDYUP_CONTEXT(Any p0) { return invoke<Any>(0xFCD2DE48, p0); } // 0xFCD2DE48
	static Any AI_CONVERSE_SET_WOAH_CONTEXT(Any p0) { return invoke<Any>(0xB8F1D736, p0); } // 0xB8F1D736
	static int AI_CONVERSE_DISABLE(Any p0) { return invoke<int>(0xEA86A817, p0); } // 0xEA86A817
	static int AI_CONVERSE_ENABLE(Any p0) { return invoke<int>(0x43F59172, p0); } // 0x43F59172
	static int AI_CONVERSE_ADD_CAMPFIRE_CONVERSER(Any p0) { return invoke<int>(0x52D984AF, p0); } // 0x52D984AF
	static int AI_CONVERSE_REMOVE_CAMPFIRE_CONVERSER(Any p0) { return invoke<int>(0x1D4786CF, p0); } // 0x1D4786CF
	static Any AI_CONVERSE_SET_GREET_SAUCY_CONTEXT(Any p0) { return invoke<Any>(0x375BBD85, p0); } // 0x375BBD85
	static Any AI_CONVERSE_SET_SOLICIT_CONTEXT(Any p0) { return invoke<Any>(0x4819FB7C, p0); } // 0x4819FB7C
	static Any AI_CONVERSE_SET_REJECTION_CONTEXT(Any p0) { return invoke<Any>(0xC4F468AA, p0); } // 0xC4F468AA
	static void AI_CONVERSE_SET_COY_REJECTION_CONTEXT(Any p0) { invoke<void>(0xBD3A0E6D, p0); } // 0xBD3A0E6D
	static Any AI_CONVERSE_SET_GREET_PLAYER_CONTEXT(Any p0) { return invoke<Any>(0xD6BBC8AA, p0); } // 0xD6BBC8AA
}

namespace AI_MEMORY
{
	static void MEMORY_CLEAR_EVENTS(Any p0, Any p1) { invoke<void>(0x8CD37E9E, p0, p1); } // 0x8CD37E9E
	static void MEMORY_CLEAR_ALL(Any p0) { invoke<void>(0x4485B246, p0); } // 0x4485B246
	static void MEMORY_CONSIDER_ACCORDING_TO_FACTION(Any p0, Any p1) { invoke<void>(0xACD4084D, p0, p1); } // 0xACD4084D
	static void MEMORY_CONSIDER_AS(Any p0, Any p1, Any p2) { invoke<void>(0x296C01A4, p0, p1, p2); } // 0x296C01A4
	static void MEMORY_CONSIDER_AS_ENEMY(Any p0, Any p1) { invoke<void>(0x745A1BA3, p0, p1); } // 0x745A1BA3
	static int MEMORY_GET_IS_IDENTIFIED(Any p0, Any p1) { return invoke<int>(0x0810A7BA, p0, p1); } // 0x0810A7BA
	static int MEMORY_GET_IS_VISIBLE(Any p0, Any p1) { return invoke<int>(0x45CE40FD, p0, p1); } // 0x45CE40FD
	static int MEMORY_GET_WAS_VISIBLE_WITHIN_TIME(Any p0, Any p1, Any p2) { return invoke<int>(0xC407497F, p0, p1, p2); } // 0xC407497F
	static void MEMORY_IDENTIFY(Any p0, Any p1) { invoke<void>(0xBA09085C, p0, p1); } // 0xBA09085C
	static void MEMORY_REPORT_POSITION(Any p0, Any p1, Any p2) { invoke<void>(0x052CC7CE, p0, p1, p2); } // 0x052CC7CE
	static void MEMORY_REPORT_POSITION_AUTO(Any p0, Any p1, Any p2) { invoke<void>(0x2F589CDF, p0, p1, p2); } // 0x2F589CDF
	static int MEMORY_GET_MUST_IDENTIFY(Any p0, Any p1) { return invoke<int>(0x05B3D34F, p0, p1); } // 0x05B3D34F
	static void MEMORY_ATTACK_ON_SIGHT(Any p0, Any p1) { invoke<void>(0x5A83A1EA, p0, p1); } // 0x5A83A1EA
	static void MEMORY_CLEAR_RIDING_PREFERENCE(Any p0) { invoke<void>(0x48AA959E, p0); } // 0x48AA959E
	static void MEMORY_PREFER_RIDING(Any p0, Any p1) { invoke<void>(0x1B72B0DD, p0, p1); } // 0x1B72B0DD
	static void MEMORY_PREFER_WALKING(Any p0, Any p1) { invoke<void>(0x2F7B60A4, p0, p1); } // 0x2F7B60A4
	static void MEMORY_PREFER_MELEE(Any p0, Any p1) { invoke<void>(0x2F929ECD, p0, p1); } // 0x2F929ECD
	static void MEMORY_FORCE_MELEE(Any p0, Any p1) { invoke<void>(0xC175F2B5, p0, p1); } // 0xC175F2B5
	static void MEMORY_ALLOW_SHOOTING(Actor actor, BOOL toggle) { invoke<void>(0x937E1760, actor, toggle); } // 0x937E1760
	static void MEMORY_ALLOW_TAKE_COVER(Actor actor, BOOL toggle) { invoke<void>(0xE944E5F8, actor, toggle); } // 0xE944E5F8
	static void MEMORY_ALLOW_THROWING_EXPLOSIVES(Any p0, Any p1) { invoke<void>(0xDBDB57D0, p0, p1); } // 0xDBDB57D0
	static int MEMORY_ALLOW_PICKUP_WEAPONS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x5DD0AC4A, p0, p1, p2, p3, p4, p5); } // 0x5DD0AC4A
	static int MEMORY_GET_WEAPON_DRAW_PREFERENCE(Any p0) { return invoke<int>(0x009EB4C1, p0); } // 0x009EB4C1
	static void MEMORY_CLEAR_WEAPON_DRAW_PREFERENCE(Any p0) { invoke<void>(0xDD965D74, p0); } // 0xDD965D74
	static void MEMORY_SET_WEAPON_DRAW_PREFERENCE(Any p0, Any p1) { invoke<void>(0xF8CB6260, p0, p1); } // 0xF8CB6260
	static int MEMORY_GET_POSITION_LAST_KNOWN_TIME(Any p0, Any p1) { return invoke<int>(0x7E77DD6C, p0, p1); } // 0x7E77DD6C
	static void MEMORY_EVERYBODY_FORGET_ABOUT(Any p0) { invoke<void>(0x7EDD316C, p0); } // 0x7EDD316C
	static void MEMORY_EVERYBODY_FORGET_ABOUT_EVERYTHING() { invoke<void>(0xD1628C57); } // 0xD1628C57
	static void MEMORY_SHOULD_ALWAYS_PATHFIND_IN_FORMATION(Any p0, Any p1) { invoke<void>(0x052E865C, p0, p1); } // 0x052E865C
	static void AI_GLOBAL_CLEAR_ALL_DANGER() { invoke<void>(0xAF94B7D9); } // 0xAF94B7D9
	static void AI_GLOBAL_CLEAR_DANGER(Any p0) { invoke<void>(0xB6FCFFAA, p0); } // 0xB6FCFFAA
	static int AI_GLOBAL_GET_PERMANENT_DANGER(Any p0) { return invoke<int>(0xFF00B4E6, p0); } // 0xFF00B4E6
	static int AI_GLOBAL_IS_DANGER(Any p0, Any p1) { return invoke<int>(0x5EC098F2, p0, p1); } // 0x5EC098F2
	static void AI_GLOBAL_SET_PERMANENT_DANGER(Any p0, Any p1) { invoke<void>(0x64C177FB, p0, p1); } // 0x64C177FB
	static void AI_GLOBAL_REPORT_DANGER(Any p0) { invoke<void>(0xCF70330C, p0); } // 0xCF70330C
	static int MEMORY_SET_UNARMED_RETREAT(Any p0) { return invoke<int>(0xB4621962, p0); } // 0xB4621962
}

namespace AI_MISC
{
	static void AI_BEHAVIOR_SET_ALLOW(Any p0, Any p1, Any p2) { invoke<void>(0x4A69F264, p0, p1, p2); } // 0x4A69F264
	static BOOL AI_ACTION_IS_ACTIVE(Any p0, const char* p1) { return invoke<BOOL>(0x8F428EDF, p0, p1); } // 0x8F428EDF
	static int AI_GOAL_AIM_AT_COORD(Any p0, Any p1, const char* p2) { return invoke<int>(0x671851D4, p0, p1, p2); } // 0x671851D4
	static void AI_GOAL_AIM_AT_OBJECT(Any p0, Any p1, Any p2) { invoke<void>(0x3CD232B2, p0, p1, p2); } // 0x3CD232B2
	static void AI_GOAL_AIM_CLEAR(Any p0) { invoke<void>(0xD5100DC2, p0); } // 0xD5100DC2
	static void AI_GOAL_LOOK_AT_ACTOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x96928D25, p0, p1, p2, p3, p4, p5, p6); } // 0x96928D25
	static void AI_GOAL_LOOK_AT_COORD(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0xB162690D, p0, p1, p2, p3, p4, p5); } // 0xB162690D
	static int AI_GOAL_LOOK_AT_ACTOR_NEW(Any p0, Any p1, float p2) { return invoke<int>(0x15B7044B, p0, p1, p2); } // 0x15B7044B
	static int AI_GOAL_LOOK_AT_COORD_NEW(Any p0) { return invoke<int>(0x245D0CFD, p0); } // 0x245D0CFD
	static void AI_GOAL_LOOK_AT_NEUTRAL(Any p0, Any p1) { invoke<void>(0x8456676E, p0, p1); } // 0x8456676E
	static void AI_GOAL_LOOK_CLEAR(Any p0) { invoke<void>(0x6AF3E54E, p0); } // 0x6AF3E54E
	static int AI_GOAL_SHOOT_AT_OBJECT(Any p0, Any p1) { return invoke<int>(0x10674B4F, p0, p1); } // 0x10674B4F
	static void AI_GOAL_SHOOT_AT_COORD(Any p0, Any p1) { invoke<void>(0x6C65E46E, p0, p1); } // 0x6C65E46E
	static void AI_GOAL_SHOOT_CLEAR(Any p0) { invoke<void>(0xC43A9268, p0); } // 0xC43A9268
	static int AI_GOAL_STAND_AT_COORD(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xD9B27A9E, p0, p1, p2, p3); } // 0xD9B27A9E
	static int AI_GOAL_STAND_CLEAR(Any p0) { return invoke<int>(0xEADB58EB, p0); } // 0xEADB58EB
	static int AI_PREDICATE_FIND_NAMED(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x31D76951, p0, p1, p2, p3, p4); } // 0x31D76951
	static BOOL AI_PREDICATE_IS_VALID(Any p0) { return invoke<BOOL>(0x1FEECD4C, p0); } // 0x1FEECD4C
	static void AI_PREDICATE_OVERRIDE_CLEAR(Any p0, Any p1) { invoke<void>(0x1A137442, p0, p1); } // 0x1A137442
	static void AI_PREDICATE_OVERRIDE_CLEAR_ALL(Any p0) { invoke<void>(0x3CAC2441, p0); } // 0x3CAC2441
	static void AI_PREDICATE_OVERRIDE_SET_BOOL(Any p0, Any p1, Any p2) { invoke<void>(0x1117C85A, p0, p1, p2); } // 0x1117C85A
	static void AI_IGNORE_ACTOR(Actor actor) { invoke<void>(0x8D1FC73C, actor); } // 0x8D1FC73C
	static void AI_STOP_IGNORING_ACTOR(Actor actor) { invoke<void>(0x98790639, actor); } // 0x98790639
	static int AI_STOP_IGNORING_ACTORS() { return invoke<int>(0x4DF3C5D1); } // 0x4DF3C5D1
	static int AI_DONT_HARM_ACTOR(Any p0) { return invoke<int>(0xB421AFCA, p0); } // 0xB421AFCA
	static int AI_CLEAR_DONT_HARM_ACTOR(Any p0) { return invoke<int>(0xA737CCAC, p0); } // 0xA737CCAC
	static Any AI_SET_ALLOW_HOSTILE_ATTACK_AI(Any p0) { return invoke<Any>(0xBE17EB88, p0); } // 0xBE17EB88
	static Any AI_SET_ALLOW_HOSTILE_ATTACK_PLAYER(Any p0) { return invoke<Any>(0xABC78721, p0); } // 0xABC78721
	static int AI_SHOOT_TARGET_CLEAR_OFFSET(Any p0) { return invoke<int>(0x548541C1, p0); } // 0x548541C1
	static int AI_SHOOT_TARGET_SET_OFFSET(Any p0, Any p1) { return invoke<int>(0x039C69C4, p0, p1); } // 0x039C69C4
	static void AI_SHOOT_TARGET_SET_BONE(Any p0, Any p1, Any p2) { invoke<void>(0x47C2C7B0, p0, p1, p2); } // 0x47C2C7B0
	static int PLAYER_LOOK_AT_COORD(Any p0, Any p1, float p2) { return invoke<int>(0xFF36BAED, p0, p1, p2); } // 0xFF36BAED
	static int PLAYER_STOP_LOOK_AT_COORD(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x6F37F42C, p0, p1, p2, p3); } // 0x6F37F42C
	static BOOL SET_FORCED_LOOK_ENABLE(Any p0, BOOL p1) { return invoke<BOOL>(0xA90A13A5, p0, p1); } // 0xA90A13A5
	static BOOL GET_FORCED_LOOK_ENABLE(BOOL p0) { return invoke<BOOL>(0xF0511878, p0); } // 0xF0511878
	static int FORCE_LOOK_AT_COORD(Any p0, Any p1, float p2) { return invoke<int>(0xE56D3FCE, p0, p1, p2); } // 0xE56D3FCE
	static int STOP_FORCE_LOOK_AT_COORD(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x6C194C1F, p0, p1, p2, p3); } // 0x6C194C1F
	static int FORCE_LOOK_AT_ACTOR(Any p0, Any p1, float p2) { return invoke<int>(0xFE5715A1, p0, p1, p2); } // 0xFE5715A1
	static void SET_AUTO_CONVERSATION_LOOK(Any p0, Any p1) { invoke<void>(0xA29B9458, p0, p1); } // 0xA29B9458
	static void AI_GOAL_LOOK_AT_PLAYER_WHEN_WITHIN(Any p0, Any p1) { invoke<void>(0x1F07FC4C, p0, p1); } // 0x1F07FC4C
	static int AI_GOAL_LOOK_AT_PLAYER_WHEN_WITHIN_CLEAR(Any p0) { return invoke<int>(0x4DB11394, p0); } // 0x4DB11394
	static void CLEAR_ACTORS_HORSE(Actor actor) { invoke<void>(0xFEB74094, actor); } // 0xFEB74094
	static Actor GET_ACTORS_HORSE(Actor actor) { return invoke<Actor>(0x8DDE894F, actor); } // 0x8DDE894F
	static void SET_ACTORS_HORSE(Actor actor, Mount mount) { invoke<void>(0xCFFDF09D, actor, mount); } // 0xCFFDF09D
	static BOOL IS_AI_ACTOR_IN_COMBAT(Any p0) { return invoke<BOOL>(0x08D3CDF9, p0); } // 0x08D3CDF9
	static BOOL IS_AI_ACTOR_PERFORMING_TASK(Any p0) { return invoke<BOOL>(0x6718D199, p0); } // 0x6718D199
	static BOOL IS_AI_ACTOR_UNALERTED(Actor actor) { return invoke<BOOL>(0xC4D114A6, actor); } // 0xC4D114A6
	static void AI_SET_RANGE_ACCURACY_MODIFIER(Any p0, Any p1, Any p2) { invoke<void>(0x57F96655, p0, p1, p2); } // 0x57F96655
	static void AI_SET_DISARMED(Any p0, Any p1) { invoke<void>(0x2444577C, p0, p1); } // 0x2444577C
	static int AI_IMPAIRMENT_MASK_GET_CURRENT_FOR_ACTOR(Any p0) { return invoke<int>(0xAFB1CC55, p0); } // 0xAFB1CC55
	static int AI_IMPAIRMENT_MASK_MATCHES(Any p0, Any p1) { return invoke<int>(0xB4A15D17, p0, p1); } // 0xB4A15D17
	static void AI_ACTOR_FORCE_SPEED(Actor actor, Any p1) { invoke<void>(0x70B409D5, actor, p1); } // 0x70B409D5
	static void AI_ACTOR_SET_MATCH_WALK_SPEED_ENABLED(Any p0, Any p1) { invoke<void>(0x7387772C, p0, p1); } // 0x7387772C
	static void AI_SET_WEAPON_MAX_RANGE(Any p0, Any p1) { invoke<void>(0xD2BFA6E4, p0, p1); } // 0xD2BFA6E4
	static void AI_SET_WEAPON_MIN_RANGE(Any p0, Any p1) { invoke<void>(0xE067A925, p0, p1); } // 0xE067A925
	static void AI_SET_WEAPON_DESIRED_RANGE(Any p0, Any p1) { invoke<void>(0xDA005857, p0, p1); } // 0xDA005857
	static void AI_SET_BURST_DURATION(Any p0, Any p1) { invoke<void>(0x85F2DF87, p0, p1); } // 0x85F2DF87
	static void AI_SET_BURST_DURATION_RANDOMNESS(Any p0, Any p1) { invoke<void>(0x9E164C44, p0, p1); } // 0x9E164C44
	static void AI_SET_FIRE_DELAY(Any p0, Any p1) { invoke<void>(0x05861CF4, p0, p1); } // 0x05861CF4
	static void AI_SET_FIRE_DELAY_RANDOMNESS(Any p0, Any p1) { invoke<void>(0xC5873149, p0, p1); } // 0xC5873149
	static void AI_SET_SHOTS_PER_BURST(Any p0, Any p1) { invoke<void>(0xE0172E2D, p0, p1); } // 0xE0172E2D
	static void AI_CLEAR_BURST_DURATION(Any p0) { invoke<void>(0x01FD4402, p0); } // 0x01FD4402
	static void AI_CLEAR_BURST_DURATION_RANDOMNESS(Any p0) { invoke<void>(0xCA8EE2A4, p0); } // 0xCA8EE2A4
	static void AI_CLEAR_FIRE_DELAY(Any p0) { invoke<void>(0xD6886191, p0); } // 0xD6886191
	static void AI_CLEAR_FIRE_DELAY_RANDOMNESS(Any p0) { invoke<void>(0xE8511960, p0); } // 0xE8511960
	static void AI_CLEAR_SHOTS_PER_BURST(Any p0) { invoke<void>(0x58A7B2A1, p0); } // 0x58A7B2A1
	static void AI_RESET_FIRING_FSM(Any p0) { invoke<void>(0x46F51754, p0); } // 0x46F51754
	static void AI_SET_GATLING_MAX_HORIZONTAL_DEGREES(Any p0, Any p1) { invoke<void>(0xEA2A40BC, p0, p1); } // 0xEA2A40BC
	static int AI_IS_HOSTILE_OR_ENEMY(Any p0, Any p1) { return invoke<int>(0x9AB964F4, p0, p1); } // 0x9AB964F4
	static void AI_QUICK_EXIT_GRINGO(Actor actor, int p1) { invoke<void>(0x6FAF13C2, actor, p1); } // 0x6FAF13C2
	static int AI_IS_AGGROING(Any p0, Any p1) { return invoke<int>(0xC94F9499, p0, p1); } // 0xC94F9499
	static void AI_SET_ALLOWED_MOUNT_DIRECTIONS(Any p0, Any p1) { invoke<void>(0x7F07210F, p0, p1); } // 0x7F07210F
	static void AI_AVOID_IGNORE_ACTOR(Any p0, Any p1) { invoke<void>(0x68B268BE, p0, p1); } // 0x68B268BE
	static int AI_AVOID_CLEAR_IGNORE_ACTOR(Any p0) { return invoke<int>(0x1A96EFB9, p0); } // 0x1A96EFB9
	static BOOL IS_AI_ACTOR_ENGAGED_IN_COMBAT(Any p0) { return invoke<BOOL>(0x2DBCB78A, p0); } // 0x2DBCB78A
	static int WAS_AI_ACTOR_PLAYER_WEAPON_THREATENED_BY(Any p0, Any p1, Any p2) { return invoke<int>(0xF5752F72, p0, p1, p2); } // 0xF5752F72
	static void AI_SET_ALLOW_ATTACK_HOGTIED_ACTORS(Any p0, Any p1) { invoke<void>(0x2EBE540D, p0, p1); } // 0x2EBE540D
	static int AI_GET_IS_RETREATING(Any p0) { return invoke<int>(0x2FABB559, p0); } // 0x2FABB559
	static BOOL AI_HAS_PLAYER_FIRED_GUN_WITHIN(Any p0, float p1) { return invoke<BOOL>(0x1530A3DE, p0, p1); } // 0x1530A3DE
	static int AI_HAS_PLAYER_PROJECTILE_IMPACTED_WITHIN(Any p0, Any p1) { return invoke<int>(0x059F64B8, p0, p1); } // 0x059F64B8
	static int AI_HAS_PLAYER_PROJECTILE_NEAR_MISSED_WITHIN(Any p0, Any p1, Any p2) { return invoke<int>(0xD8574E09, p0, p1, p2); } // 0xD8574E09
	static void AI_SET_PLAYER_PROJECTILE_IMPACT_HEAR_RANGE(Any p0, Any p1) { invoke<void>(0xDCD2FC0F, p0, p1); } // 0xDCD2FC0F
	static int AI_DONT_SLOW_DOWN_TO_WALK_FOR_TURNS(Any p0, const char* p1) { return invoke<int>(0x0A421F94, p0, p1); } // 0x0A421F94
	static int AI_HAS_ACTOR_BUMPED_INTO_ME(Any p0, Any p1, Any p2) { return invoke<int>(0x6BCC744A, p0, p1, p2); } // 0x6BCC744A
	static int AI_WAS_PUSHED_OVER(Any p0, Any p1) { return invoke<int>(0x09493438, p0, p1); } // 0x09493438
	static BOOL AI_WAS_PUSHED_OVER_BY(Any p0, Any p1, Any p2, Any p3, Any p4, float p5) { return invoke<BOOL>(0x7AF8AFDC, p0, p1, p2, p3, p4, p5); } // 0x7AF8AFDC
	static BOOL AI_SELF_DEFENSE_GET_PLAYER_ATTACKED_FIRST(Any p0) { return invoke<BOOL>(0x04AEE21F, p0); } // 0x04AEE21F
	static int AI_SELF_DEFENSE_GET_ATTACKED_PLAYER_FIRST(Any p0) { return invoke<int>(0x68C50F50, p0); } // 0x68C50F50
	static int AI_SELF_DEFENSE_SET_PLAYER_ATTACKED_FIRST(Any p0) { return invoke<int>(0x0480D5BD, p0); } // 0x0480D5BD
	static int AI_SET_IGNORE_OPEN_AREA_MATERIAL(Any p0, const char* p1) { return invoke<int>(0x902C79A6, p0, p1); } // 0x902C79A6
	static int AI_GET_IGNORE_OPEN_AREA_MATERIAL(Any p0) { return invoke<int>(0x02FBBAD1, p0); } // 0x02FBBAD1
	static int AI_SET_ENABLE_REACTION_VO(Any p0, const char* p1) { return invoke<int>(0x7193449E, p0, p1); } // 0x7193449E
	static int AI_GET_TASK_RETREAT_FLAG(Any p0) { return invoke<int>(0x9B742D25, p0); } // 0x9B742D25
	static void PREVENT_DESPAWN_CLEAR() { invoke<void>(0x2E5F186B); } // 0x2E5F186B
	static void PREVENT_DESPAWN_SET_SPHERE(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x5C94F6EC, p0, p1, p2, p3); } // 0x5C94F6EC
	static int AI_HAS_ACTOR_THREATENED_RECENTLY(Any p0) { return invoke<int>(0x5D72FDB6, p0); } // 0x5D72FDB6
	static void AI_REPLACE_ALL_TR(Any p0) { invoke<void>(0x06B4A139, p0); } // 0x06B4A139
	static int AI_SET_TR_PROGRAM_FOR_ACTOR(Any p0, Any p1) { return invoke<int>(0x4D53AC21, p0, p1); } // 0x4D53AC21
}

namespace AI_NAV
{
	static void AI_CLEAR_NAV_MATERIAL_USAGE(Any p0) { invoke<void>(0x6ADF2927, p0); } // 0x6ADF2927
	static void AI_RESET_NAV_ACTOR_WIDTH(Any p0) { invoke<void>(0x660C85E5, p0); } // 0x660C85E5
	static void AI_SET_NAV_ACTOR_WIDTH(Any p0, Any p1) { invoke<void>(0x8404592D, p0, p1); } // 0x8404592D
	static void AI_SET_NAV_HAZARD_AVOIDANCE_ENABLED(Any p0, Any p1, Any p2) { invoke<void>(0x5D752432, p0, p1, p2); } // 0x5D752432
	static void AI_SET_NAV_MATERIAL_USAGE(Any p0, Any p1, Any p2) { invoke<void>(0x7B00615F, p0, p1, p2); } // 0x7B00615F
	static void AI_SET_NAV_PATHFINDING_ENABLED(Any p0, Any p1) { invoke<void>(0x4495F5FC, p0, p1); } // 0x4495F5FC
	static void AI_SET_NAV_PATHFINDING_ENABLED_WHEN_DRIVING(Any p0, Any p1) { invoke<void>(0x98966941, p0, p1); } // 0x98966941
	static int AI_SET_NAV_MAX_SLOPE(Any p0, float p1) { return invoke<int>(0xF64D5452, p0, p1); } // 0xF64D5452
	static void AI_SET_NAV_MAX_WATER_DEPTH_LEVEL(Any p0, Any p1) { invoke<void>(0x29D07F70, p0, p1); } // 0x29D07F70
	static void AI_SET_NAV_ACTOR_AVOIDANCE_MODE(Any p0, Any p1) { invoke<void>(0x5B483036, p0, p1); } // 0x5B483036
	static void AI_SET_NAV_ACTOR_AVOIDANCE_ALLOW_TURNS(Any p0, Any p1) { invoke<void>(0xFCB31704, p0, p1); } // 0xFCB31704
	static int AI_GET_NAV_ACTOR_AVOIDANCE_ALLOW_TURNS(Any p0) { return invoke<int>(0x7C13266C, p0); } // 0x7C13266C
	static void AI_RESET_NAV_SUBGRID_CELL_SIZE(Any p0) { invoke<void>(0x750A1EF6, p0); } // 0x750A1EF6
	static void AI_SET_NAV_SUBGRID_CELL_SIZE(Any p0, Any p1) { invoke<void>(0xFF3CEFE2, p0, p1); } // 0xFF3CEFE2
	static void AI_SET_NAV_FAILSAFE_MOVEMENT_ENABLED(Any p0, Any p1) { invoke<void>(0xC900F0E8, p0, p1); } // 0xC900F0E8
	static int AI_GET_NAV_FAILSAFE_MOVEMENT_ENABLED(Any p0) { return invoke<int>(0xD6F4FDAD, p0); } // 0xD6F4FDAD
	static int AI_SET_NAV_UNALERTED_PREFER_PEDPATH(Any p0, Any p1) { return invoke<int>(0xF1B3072D, p0, p1); } // 0xF1B3072D
	static int AI_SET_NAV_ALLOW_TWEAK_DESIRED_MOVEMENT(Any p0, const char* p1) { return invoke<int>(0xC84EF86B, p0, p1); } // 0xC84EF86B
	static int AI_GET_NAV_ALLOW_TWEAK_DESIRED_MOVEMENT(Any p0) { return invoke<int>(0xBAA2BA4F, p0); } // 0xBAA2BA4F
	static int AI_SWAP_NAV_DATA(Any p0, Any p1) { return invoke<int>(0xF435CCDE, p0, p1); } // 0xF435CCDE
}

namespace AI_PERCEPTION
{
	static void DISABLE_VERIFY_SS(Any p0) { invoke<void>(0x5C580036, p0); } // 0x5C580036
	static void AI_PERCEPTION_SET_VISUAL_ID_DISTANCE(Any p0, Any p1) { invoke<void>(0x66064774, p0, p1); } // 0x66064774
	static void AI_PERCEPTION_SET_VISUAL_ID_TIME(Any p0, Any p1) { invoke<void>(0xD786E8C7, p0, p1); } // 0xD786E8C7
	static void AI_DISABLE_PERCEPTION(Any p0) { invoke<void>(0x8BBB7B12, p0); } // 0x8BBB7B12
	static void AI_ENABLE_PERCEPTION(Any p0) { invoke<void>(0xAF77C42E, p0); } // 0xAF77C42E
}

namespace AI_RIDE
{
	static int AI_RIDING_SET_ATTRIBUTE(Any p0, Any p1, float p2) { return invoke<int>(0x9DDFA9CA, p0, p1, p2); } // 0x9DDFA9CA
	static int AI_RIDING_SET_ENABLED(Any p0, Any p1) { return invoke<int>(0xF8AFEFA1, p0, p1); } // 0xF8AFEFA1
}

namespace AI_SPEECH
{
	static int AI_SPEECH_ADD_PHRASE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0xD269F20B, p0, p1, p2, p3, p4, p5, p6); } // 0xD269F20B
	static void AI_SPEECH_ADD_TAG_FOR_PHRASE(Any p0, Any p1, Any p2) { invoke<void>(0x15CFAB4C, p0, p1, p2); } // 0x15CFAB4C
	static void AI_SPEECH_REGISTER_EVENT(Any p0, Any p1) { invoke<void>(0xDD925074, p0, p1); } // 0xDD925074
	static void AI_SPEECH_REGISTER_TAG(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xA08B3E4B, p0, p1, p2, p3); } // 0xA08B3E4B
	static void AI_SPEECH_REGISTER_TAGS_BEGIN(Any p0) { invoke<void>(0xAB297CCB, p0); } // 0xAB297CCB
	static void AI_SPEECH_REGISTER_TAGS_END() { invoke<void>(0x90B577F5); } // 0x90B577F5
	static int AI_SPEECH_GET_ALLOW_FOR_ACTOR(Any p0) { return invoke<int>(0xFF0BF292, p0); } // 0xFF0BF292
	static void AI_SPEECH_SET_ALLOW_CONTEXT_FOR_ACTOR(Any p0, Any p1, Any p2) { invoke<void>(0x6AAB4CD0, p0, p1, p2); } // 0x6AAB4CD0
	static void AI_SPEECH_SET_ALLOW_CONTEXT_GLOBAL(Any p0, Any p1) { invoke<void>(0x10DDB016, p0, p1); } // 0x10DDB016
	static void AI_SPEECH_SET_ALLOW_FOR_ACTOR(Any p0, Any p1) { invoke<void>(0x56421F1A, p0, p1); } // 0x56421F1A
	static void AI_SPEECH_SET_DEFAULT_PACKAGE(Any p0) { invoke<void>(0x829F3E70, p0); } // 0x829F3E70
	static int AI_GET_ACTOR_CONVERSATION_TARGET(Any p0) { return invoke<int>(0xD8C8BEA1, p0); } // 0xD8C8BEA1
	static int AI_IS_ACTOR_SOCIALIZING(Any p0) { return invoke<int>(0x679C5955, p0); } // 0x679C5955
}

namespace AI_SPEECH_CONTEXT
{
	static void SPEECH_CONTEXT_INIT_DATA(Any p0) { invoke<void>(0xD85BAFA8, p0); } // 0xD85BAFA8
	static void SPEECH_CONTEXT_ADD_CHILD(Any p0, Any p1, Any p2) { invoke<void>(0xEB99D1A9, p0, p1, p2); } // 0xEB99D1A9
	static void SPEECH_CONTEXT_SET_TIME_RESTRICTION(Any p0, Any p1, Any p2) { invoke<void>(0x0386C556, p0, p1, p2); } // 0x0386C556
	static void SPEECH_CONTEXT_SET_OPPOSITE_GENDER_RESTRICTION(Any p0) { invoke<void>(0xF63FA0A1, p0); } // 0xF63FA0A1
	static void SPEECH_CONTEXT_SET_ETHNICITY_RESTRICTION(Any p0, Any p1) { invoke<void>(0xB59AD5B1, p0, p1); } // 0xB59AD5B1
	static void SPEECH_CONTEXT_SET_RESTRICTION_IS_LAW(Any p0) { invoke<void>(0x4F64116B, p0); } // 0x4F64116B
	static void SPEECH_CONTEXT_SET_WEATHER_RESTRICTION_GOOD(Any p0) { invoke<void>(0xBAD8B9A8, p0); } // 0xBAD8B9A8
	static void SPEECH_CONTEXT_SET_WEATHER_RESTRICTION_RAINY(Any p0) { invoke<void>(0x6CBF76AB, p0); } // 0x6CBF76AB
	static void SPEECH_CONTEXT_SET_TARGET_PLAYER(Any p0) { invoke<void>(0xE0DD373F, p0); } // 0xE0DD373F
	static void SPEECH_CONTEXT_SET_TARGET_INITIAL_FACTION(Any p0, Any p1) { invoke<void>(0x3C6FE75D, p0, p1); } // 0x3C6FE75D
	static void SPEECH_CONTEXT_SET_PLAYER_IDENTITY_RESTRICTION(Any p0, Any p1) { invoke<void>(0x74E7F898, p0, p1); } // 0x74E7F898
	static void SPEECH_CONTEXT_SET_ALLOW_PHRASE_REUSE(Any p0, Any p1) { invoke<void>(0xA13D379B, p0, p1); } // 0xA13D379B
	static void DISABLE_NONCOMBAT_SPEECH_UNIVERSAL(Any p0, Any p1) { invoke<void>(0xAC72E757, p0, p1); } // 0xAC72E757
	static void DISABLE_NONCOMBAT_SPEECH_INDIVIDUAL(Any p0, Any p1, Any p2) { invoke<void>(0x99AFD2D1, p0, p1, p2); } // 0x99AFD2D1
}

namespace AI_VISION
{
	static BOOL CAN_ANYONE_OF_FACTION_SEE_OBJECT(Any p0, Any p1) { return invoke<BOOL>(0x656D3D26, p0, p1); } // 0x656D3D26
}

namespace AI_WORLD
{
	static void ENABLE_AMBIENT_SPAWNING(Any p0) { invoke<void>(0xA8ADCAEB, p0); } // 0xA8ADCAEB
	static void SET_AMBIENT_FORCE_WAIT_STATE(Any p0) { invoke<void>(0xB35C0660, p0); } // 0xB35C0660
	static int SET_POP_DENSITY_MULTIPLIER(float p0) { return invoke<int>(0xE9C41DFE, p0); } // 0xE9C41DFE
	static int DESTROY_AMBIENT_ACTORS_IF_POSSIBLE() { return invoke<int>(0xB09D5B43); } // 0xB09D5B43
	static BOOL FORCE_AMBIENT_NUM_ACTORS_REQUESTED_FOR_MISSIONS() { return invoke<BOOL>(0x5831679F); } // 0x5831679F
	static int SET_AMBIENT_NUM_ACTORS_REQUESTED_FOR_MISSIONS(Any p0) { return invoke<int>(0x2CCEA76C, p0); } // 0x2CCEA76C
	static int GET_AMBIENT_NUM_ACTORS_GRANTED_FOR_MISSIONS() { return invoke<int>(0xA607D290); } // 0xA607D290
	static int GET_AMBIENT_MAX_NUM_TOTAL_ACTORS() { return invoke<int>(0xC1A30BB5); } // 0xC1A30BB5
	static int SET_AMBIENT_MAX_NUM_TOTAL_ACTORS(Any p0) { return invoke<int>(0x2C4CBC25, p0); } // 0x2C4CBC25
	static int SET_AMBIENT_ACTOR_SPEED_SCALE_RANGE(float p0, float p1) { return invoke<int>(0x1C8CA53C, p0, p1); } // 0x1C8CA53C
	static int SET_AMBIENT_TUNING_MAX_VISIBLE_RANGE(float p0) { return invoke<int>(0xE8960298, p0); } // 0xE8960298
	static int CLEAR_AMBIENT_ALL_RESTRICTIONS() { return invoke<int>(0xC78B7436); } // 0xC78B7436
	static int CLEAR_AMBIENT_MOVE_RESTRICTIONS() { return invoke<int>(0x94DBC0C5); } // 0x94DBC0C5
	static int CLEAR_AMBIENT_SPAWN_RESTRICTIONS() { return invoke<int>(0xC738ED3E); } // 0xC738ED3E
	static int ADD_AMBIENT_SPAWN_TYPE_RESTRICTION(Any p0) { return invoke<int>(0xD1CF9793, p0); } // 0xD1CF9793
	static int CLEAR_AMBIENT_SPAWN_TYPE_RESTRICTION(Any p0) { return invoke<int>(0xA8BD64D1, p0); } // 0xA8BD64D1
	static int CLEAR_ALL_AMBIENT_SPAWN_TYPE_RESTRICTIONS() { return invoke<int>(0x6C7A3CE6); } // 0x6C7A3CE6
	static int SET_AMBIENT_STREAMING_REQUIRED_POP_ACTOR_SCALE(float p0) { return invoke<int>(0x95D0FC79, p0); } // 0x95D0FC79
	static int SET_AMBIENT_ANIMALS_AGRESSIVENESS(Any p0) { return invoke<int>(0xC519E3F3, p0); } // 0xC519E3F3
	static void ADD_AI_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME_SET(Any p0, Any p1) { invoke<void>(0xEBE88626, p0, p1); } // 0xEBE88626
	static void REMOVE_AI_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME_SET(Any p0, Any p1) { invoke<void>(0x1AED34CA, p0, p1); } // 0x1AED34CA
	static void ADD_AMBIENT_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(Any p0) { invoke<void>(0xCF50D509, p0); } // 0xCF50D509
	static void ADD_AMBIENT_SPAWN_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(Any p0) { invoke<void>(0xD1C09A22, p0); } // 0xD1C09A22
	static void REMOVE_AMBIENT_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(Any p0) { invoke<void>(0x515AC319, p0); } // 0x515AC319
	static void REMOVE_AMBIENT_SPAWN_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(Any p0) { invoke<void>(0xD65BAA71, p0); } // 0xD65BAA71
	static int DOES_AMBIENT_MOVE_RESTRICTION_VOLUME_EXIST(Any p0) { return invoke<int>(0x21C59F4C, p0); } // 0x21C59F4C
	static int DOES_AMBIENT_SPAWN_RESTRICTION_VOLUME_EXIST(Any p0) { return invoke<int>(0x02E15363, p0); } // 0x02E15363
	static void RELEASE_ACTOR_AS_AMBIENT(Any p0) { invoke<void>(0xC8AD4A8C, p0); } // 0xC8AD4A8C
	static int WOULD_ACTOR_BE_VISIBLE(Any p0, Any p1, Any p2) { return invoke<int>(0xD8BE8E0C, p0, p1, p2); } // 0xD8BE8E0C
	static int DEBUG_GET_AMBIENT_BANK_DISABLE_SPAWN_NEW_ACTORS(Any p0) { return invoke<int>(0x515E17DC, p0); } // 0x515E17DC
	static int ACTIVATE_EMERGENCY_TELEPORT_FOR_ACTOR(Any p0, Any p1, float p2, float p3, float p4) { return invoke<int>(0x8ED2B0BC, p0, p1, p2, p3, p4); } // 0x8ED2B0BC
	static int DEACTIVATE_EMERGENCY_TELEPORT_FOR_ACTOR(Any p0) { return invoke<int>(0x08FD1D81, p0); } // 0x08FD1D81
	static int IS_POINT_IN_AMBIENT_MOVE_RESTRICTION_VOLUME(Any p0) { return invoke<int>(0x257C73C5, p0); } // 0x257C73C5
	static void SET_ACTOR_OBEY_AMBIENT_MOVE_RESTRICTIONS(Any p0, Any p1) { invoke<void>(0xED3071A5, p0, p1); } // 0xED3071A5
	static int DOES_ACTOR_OBEY_AMBIENT_MOVE_RESTRICTIONS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14, Any p15, Any p16, Any p17) { return invoke<int>(0xFF642652, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17); } // 0xFF642652
	static void SET_AMBIENT_DEAD_COUNT_DECAY_RATE(float p0) { invoke<void>(0x851F88F6, p0); } // 0x851F88F6
}

namespace AMBIENCE
{
	static int AMBIENCE_AUDIO_ENTITY_UPDATE_TERRITORY(Any p0) { return invoke<int>(0x2A3B1045, p0); } // 0x2A3B1045
	static int AMBIENCE_AUDIO_ENTITY_UPDATE_LOCATION(const char* p0, const char* p1) { return invoke<int>(0x27A96719, p0, p1); } // 0x27A96719
	static int AMBIENCE_AUDIO_VALIDATE_REGION(Any p0, Any p1) { return invoke<int>(0xC0556FB8, p0, p1); } // 0xC0556FB8
}

namespace AMBIENT
{
	static void AMBIENT_SET_UPDATES_ENABLED() { invoke<void>(0xA8226DFF); } // 0xA8226DFF
	static void AMBIENT_SET_POINT_SPACING() { invoke<void>(0x831FC466); } // 0x831FC466
	static int AMBIENT_SET_SLOPE_VALUES(float x, float y, float z) { return invoke<int>(0xCC9E6F4C, x, y, z); } // 0xCC9E6F4C
	static int AMBIENT_RESET_USED_CELLS() { return invoke<int>(0x7B07D449); } // 0x7B07D449
	static int AMBIENT_SET_SCAN_CENTER(float x, float y, float z) { return invoke<int>(0x205E891C, x, y, z); } // 0x205E891C
	static void AMBIENT_SET_SCAN_CENTER_PLAYER() { invoke<void>(0x8B011F5D); } // 0x8B011F5D
	static int AMBIENT_RESET_FILTER(Any p0, Any p1) { return invoke<int>(0x19B26C78, p0, p1); } // 0x19B26C78
	static Any AMBIENT_SET_RANDOM_SEARCH_ORDER(Any p0) { return invoke<Any>(0xA337135A, p0); } // 0xA337135A
	static Any AMBIENT_SET_ONESHOT_QUERIES(Any p0) { return invoke<Any>(0x9A35520B, p0); } // 0x9A35520B
	static void AMBIENT_SET_SEARCH_CENTER() { invoke<void>(0x272D756C); } // 0x272D756C
	static void AMBIENT_SET_SEARCH_CENTER_ACTOR(Any p0) { invoke<void>(0x9A2B05F4, p0); } // 0x9A2B05F4
	static Any AMBIENT_SET_SEARCH_CENTER_PLAYER(Any p0) { return invoke<Any>(0x21E783AC, p0); } // 0x21E783AC
	static void AMBIENT_SET_SLOPE_FILTER(Any p0, Any p1, float p2) { invoke<void>(0x391F3607, p0, p1, p2); } // 0x391F3607
	static Any AMBIENT_ENABLE_SLOPE_FILTER(Any p0) { return invoke<Any>(0x2CCE1115, p0); } // 0x2CCE1115
	static int AMBIENT_SET_SLOPE_FILTER_PRECISE(float p0, float p1, float p2) { return invoke<int>(0x45190938, p0, p1, p2); } // 0x45190938
	static int AMBIENT_ENABLE_SLOPE_FILTER_PRECISE(Any p0) { return invoke<int>(0x561C9A6D, p0); } // 0x561C9A6D
	static int AMBIENT_SET_BUMP_FILTER(float p0, float p1, float p2) { return invoke<int>(0x912EEC43, p0, p1, p2); } // 0x912EEC43
	static Any AMBIENT_ENABLE_BUMP_FILTER(Any p0) { return invoke<Any>(0x528C7F3D, p0); } // 0x528C7F3D
	static Any* AMBIENT_SET_DISTANCE_FILTER(float p0, float p1) { return invoke<Any*>(0xA89B77A7, p0, p1); } // 0xA89B77A7
	static void AMBIENT_ENABLE_DISTANCE_FILTER(Any p0) { invoke<void>(0x762192EB, p0); } // 0x762192EB
	static void AMBIENT_SET_ELEVATION_FILTER(Any p0, Any p1) { invoke<void>(0x1900A97E, p0, p1); } // 0x1900A97E
	static void AMBIENT_SET_QUADRANT_FILTER(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x609514AE, p0, p1, p2, p3); } // 0x609514AE
	static void AMBIENT_ENABLE_QUADRANT_FILTER(Any p0) { invoke<void>(0xAA99E18E, p0); } // 0xAA99E18E
	static void AMBIENT_ENABLE_OFFSCREEN_FILTER(Any p0) { invoke<void>(0x76341F1A, p0); } // 0x76341F1A
	static void AMBIENT_ENABLE_MATERIAL_AT_POINT_FILTER(Any p0) { invoke<void>(0x309D058C, p0); } // 0x309D058C
	static void AMBIENT_SET_MATERIAL_AT_POINT_FILTER(Any p0) { invoke<void>(0xB1609063, p0); } // 0xB1609063
	static void AMBIENT_ENABLE_MATERIAL_IN_AREA_INCLUDES_FILTER(Any p0, Any p1) { invoke<void>(0x5A6418A2, p0, p1); } // 0x5A6418A2
	static void AMBIENT_SET_MATERIAL_IN_AREA_INCLUDES_FILTER(Any p0, Any p1, Any p2) { invoke<void>(0x9CD2B55F, p0, p1, p2); } // 0x9CD2B55F
	static const char* AMBIENT_ENABLE_MATERIAL_IN_AREA_EXCLUDES_FILTER(Any p0, Any p1) { return invoke<const char*>(0x1F7F1B79, p0, p1); } // 0x1F7F1B79
	static void AMBIENT_SET_MATERIAL_IN_AREA_EXCLUDES_FILTER(Any p0, Any p1, Any p2) { invoke<void>(0xBCD4979C, p0, p1, p2); } // 0xBCD4979C
	static void _AMBIENT_ENABLE_ELEVATION_IN_AREA_RANGE_FILTER(Any p0) { invoke<void>(0x30C67D05, p0); } // 0x30C67D05
	static void _AMBIENT_SET_ELEVATION_IN_AREA_RANGE_FILTER(Any p0, Any p1) { invoke<void>(0x0AC99007, p0, p1); } // 0x0AC99007
	static void AMBIENT_ENABLE_ELEVATION_DERIVATIVE_IN_AREA_FILTER(Any p0) { invoke<void>(0xC8B149B4, p0); } // 0xC8B149B4
	static void AMBIENT_SET_ELEVATION_DERIVATIVE_IN_AREA_FILTER(Any p0, Any p1) { invoke<void>(0x54BD1C65, p0, p1); } // 0x54BD1C65
	static void AMBIENT_SET_EXCLUSION_VOLUME(Any p0) { invoke<void>(0x90008899, p0); } // 0x90008899
	static int AMBIENT_GET_POINT(Any p0, Any p1) { return invoke<int>(0x0C6EF9E1, p0, p1); } // 0x0C6EF9E1
}

namespace ANIM
{
	static float GET_ACTOR_ANIM_CURRENT_TIME(Actor actor, Any p1) { return invoke<float>(0x8609F5E1, actor, p1); } // 0x8609F5E1
	static int SET_ACTOR_ANIM_CURRENT_TIME(Any p0, Any p1) { return invoke<int>(0x8626C1A0, p0, p1); } // 0x8626C1A0
	static BOOL IS_ACTOR_ANIM_PLAYING(Actor actor, const char* animation) { return invoke<BOOL>(0x1ADE21EB, actor, animation); } // 0x1ADE21EB
	static BOOL ACTOR_HAS_ANIM_LOADED(Any p0, Any p1) { return invoke<BOOL>(0x6B54BABD, p0, p1); } // 0x6B54BABD
	static int ACTOR_HAS_ANIM_SET(Any p0, Any p1) { return invoke<int>(0x31F5F57D, p0, p1); } // 0x31F5F57D
	static int SET_ANIMATION_OVERRIDE_SCALE(Any p0) { return invoke<int>(0x3E30A514, p0); } // 0x3E30A514
	static int SET_PANIM_PARAMS(Any p0, Any p1, Any p2) { return invoke<int>(0x5941295A, p0, p1, p2); } // 0x5941295A
	static Any SET_PANIM_PHASE(Any p0, Any p1) { return invoke<Any>(0x94431F5A, p0, p1); } // 0x94431F5A
	static void SET_ACTOR_ANIM_PHASE_LOCK(Any p0, Any p1) { invoke<void>(0xB03616C2, p0, p1); } // 0xB03616C2
	static void RELEASE_ACTOR_ANIM_PHASE_LOCK(Any p0) { invoke<void>(0xAEBAE989, p0); } // 0xAEBAE989
	static BOOL IS_ACTOR_ANIM_PHASE_LOCKED(Actor actor) { return invoke<BOOL>(0xE0AC4B86, actor); } // 0xE0AC4B86
	static void SET_ACTOR_CUTSCENE_MODE(Any p0, Any p1) { invoke<void>(0x76ECD5F1, p0, p1); } // 0x76ECD5F1
	static void REQUEST_ANIM_SET(Any p0, Any p1) { invoke<void>(0x2988B3FC, p0, p1); } // 0x2988B3FC
	static BOOL HAS_ANIM_SET_LOADED(Any p0) { return invoke<BOOL>(0x4FFF397D, p0); } // 0x4FFF397D
	static int REMOVE_ANIM_SET(Any p0) { return invoke<int>(0xD04A817A, p0); } // 0xD04A817A
	static Any SET_ANIM_SET_FOR_ACTOR(Any p0, Any p1, Any p2) { return invoke<Any>(0x39C1E1C0, p0, p1, p2); } // 0x39C1E1C0
	static void RESET_ANIM_SET_FOR_ACTOR(Any p0, Any p1) { invoke<void>(0x7A6C5C2F, p0, p1); } // 0x7A6C5C2F
	static int DLC_REPLACE_EXISTING_ANIM_SET() { return invoke<int>(0xB1B643E0); } // 0xB1B643E0
	static Any REQUEST_ACTION_TREE(Any p0) { return invoke<Any>(0xB3039DB7, p0); } // 0xB3039DB7
	static Any HAS_ACTION_TREE_LOADED(Any p0) { return invoke<Any>(0xEEECD85E, p0); } // 0xEEECD85E
	static int REMOVE_ACTION_TREE(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xBF4D0EFE, p0, p1, p2, p3, p4); } // 0xBF4D0EFE
	static Any SET_ACTION_NODE_FOR_ACTOR(Any p0, Any p1) { return invoke<Any>(0x5A795F3A, p0, p1); } // 0x5A795F3A
	static int SET_REACT_NODE_FOR_ACTOR(Any p0, Any p1) { return invoke<int>(0xF90F737E, p0, p1); } // 0xF90F737E
	static void RESET_REACT_NODE_FOR_ACTOR(Any p0) { invoke<void>(0x7B17C5C3, p0); } // 0x7B17C5C3
	static int RESET_ACTIONTREE_FOR_ACTOR(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x07EC142B, p0, p1, p2, p3, p4); } // 0x07EC142B
	static int SET_LINKED_ANIM_TARGET(Any p0, Any p1) { return invoke<int>(0x0A192D09, p0, p1); } // 0x0A192D09
	static int GET_LINKED_ANIM_TARGET(Any p0) { return invoke<int>(0xA4E9E7EE, p0); } // 0xA4E9E7EE
	static int CLEAR_LINKED_ANIM_TARGET(Any p0) { return invoke<int>(0xAC54E120, p0); } // 0xAC54E120
	static BOOL IS_ACTOR_PERFORMING_LINKED_ANIMATION(Actor actor) { return invoke<BOOL>(0xCA9364C5, actor); } // 0xCA9364C5
	static BOOL IS_ACTION_NODE_PLAYING(Any p0, Any p1) { return invoke<BOOL>(0x7B19DEC6, p0, p1); } // 0x7B19DEC6
	static int IS_ACTION_NODE_PLAYING_PARTIAL(Any p0, Any p1) { return invoke<int>(0x994F2BD1, p0, p1); } // 0x994F2BD1
	static BOOL IS_ACTOR_PLAYING_NODE_IN_TREE(Actor actor, const char* nodeString) { return invoke<BOOL>(0x4E0300E2, actor, nodeString); } // 0x4E0300E2
	static float GET_CURR_ACTION_NODE_PLAY_TIME(Any p0) { return invoke<float>(0x5E84F53E, p0); } // 0x5E84F53E
	static int TOUGH_ARMOUR_GET_TUNING_REGENERATION_RATE(Any p0) { return invoke<int>(0x4AD89F02, p0); } // 0x4AD89F02
	static void TOUGH_ARMOUR_SET_TUNING_HIT_DEDUCTION(Any p0, Any p1, Any p2) { invoke<void>(0x11542587, p0, p1, p2); } // 0x11542587
	static void TOUGH_ARMOUR_SET_TUNING_PAD_ARMOUR(Any p0, Any p1) { invoke<void>(0xDCB9C943, p0, p1); } // 0xDCB9C943
	static void TOUGH_ARMOUR_SET_TUNING_REGENERATION_RATE(Any p0, Any p1) { invoke<void>(0xB3F5EE8C, p0, p1); } // 0xB3F5EE8C
	static void SET_ACTOR_CHARACTER_CLOTH_SCALED_PINNING(Any p0, float p1) { invoke<void>(0xBEF6031B, p0, p1); } // 0xBEF6031B
	static int SET_ACTOR_TO_SEAT(int* p0, Any p1, int* p2) { return invoke<int>(0xF349D0B6, p0, p1, p2); } // 0xF349D0B6
}

namespace ANIMATOR
{
	static BOOL IS_OBJECT_ANIMATOR_VALID(Any p0) { return invoke<BOOL>(0x19BD222F, p0); } // 0x19BD222F
	static int CREATE_OBJECT_ANIMATOR(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x856D5842, p0, p1, p2, p3, p4); } // 0x856D5842
	static int CREATE_OBJECT_ANIMATOR_ON_OBJECT(int* p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x0D0A66B6, p0, p1, p2, p3, p4); } // 0x0D0A66B6
	static BOOL IS_OBJECT_ANIMATOR_READY(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14, Any p15, Any p16) { return invoke<BOOL>(0x554CF528, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16); } // 0x554CF528
	static int GET_OBJECT_ANIMATOR_ON_OBJECT(int* p0, Any p1) { return invoke<int>(0x5908F7FE, p0, p1); } // 0x5908F7FE
	static int SET_OBJECT_ANIMATOR_NODE(Any p0, Any p1) { return invoke<int>(0xB9D7B63B, p0, p1); } // 0xB9D7B63B
	static int SET_OBJECT_ANIMATOR_PHASE(Any p0, Any p1) { return invoke<int>(0xC0128653, p0, p1); } // 0xC0128653
	static int SET_OBJECT_ANIMATOR_RATE(Any p0, Any p1) { return invoke<int>(0x0B4D9AFA, p0, p1); } // 0x0B4D9AFA
	static float GET_OBJECT_ANIMATOR_PHASE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<float>(0xC5205015, p0, p1, p2, p3, p4, p5, p6); } // 0xC5205015
	static int SET_OBJECT_ANIMATOR_BONE_RANGE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x188B6431, p0, p1, p2, p3); } // 0x188B6431
	static int SET_OBJECT_ANIMATOR_ANIMATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0xB57D4110, p0, p1, p2, p3, p4, p5, p6); } // 0xB57D4110
	static BOOL IS_OBJECT_ANIMATOR_ANIMATION_PLAYING(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14, Any p15, Any p16) { return invoke<BOOL>(0x46A69DAF, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16); } // 0x46A69DAF
	static int DESTROY_OBJECT_ANIMATOR(Any p0) { return invoke<int>(0x1E5A227A, p0); } // 0x1E5A227A
	static Any GET_OBJECT_FROM_ANIMATOR(Any p0, Any p1) { return invoke<Any>(0x4F10FD5B, p0, p1); } // 0x4F10FD5B
	static Any LINK_OBJECT_ANIMATOR_TO_ACTOR(Any p0, Any p1, Any p2) { return invoke<Any>(0xBEDB066C, p0, p1, p2); } // 0xBEDB066C
}

namespace AUDIO
{
	static Any NEW_SCRIPTED_CONVERSATION() { return invoke<Any>(0x1CEA7FCE); } // 0x1CEA7FCE
	static void ADD_LINE_TO_CONVERSATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { invoke<void>(0x96CD0513, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x96CD0513
	static void ADD_NEW_CONVERSATION_SPEAKER(Any p0, Any p1, Any p2) { invoke<void>(0xF1C40BCA, p0, p1, p2); } // 0xF1C40BCA
	static void ADD_NEW_FRONTEND_CONVERSATION_SPEAKER(Any p0, Any p1) { invoke<void>(0x4FAD0D8F, p0, p1); } // 0x4FAD0D8F
	static void START_SCRIPT_CONVERSATION(Any p0, Any p1) { invoke<void>(0xE5DE7D9D, p0, p1); } // 0xE5DE7D9D
	static BOOL IS_SCRIPTED_CONVERSATION_ONGOING() { return invoke<BOOL>(0xCB8FD96F); } // 0xCB8FD96F
	static int PAUSE_SCRIPTED_CONVERSATION(Any p0, Any p1, Any p2) { return invoke<int>(0xE2C9C6F8, p0, p1, p2); } // 0xE2C9C6F8
	static int RESTART_SCRIPTED_CONVERSATION() { return invoke<int>(0x6CB24B56); } // 0x6CB24B56
	static int ABORT_SCRIPTED_CONVERSATION(Any p0) { return invoke<int>(0xC842F0C9, p0); } // 0xC842F0C9
	static void SET_MAX_SCRIPTED_CONVERSATION_DISTANCE(float p0) { invoke<void>(0x1CFC44F9, p0); } // 0x1CFC44F9
	static void RESET_MAX_SCRIPTED_CONVERSATION_DISTANCE() { invoke<void>(0xC1C29ABC); } // 0xC1C29ABC
	static int HAS_SCRIPTED_CONVERSATION_PLAYED_RECENTLY() { return invoke<int>(0x713519AB); } // 0x713519AB
	static void UNREGISTER_SCRIPT_WITH_AUDIO() { invoke<void>(0x66728EFE); } // 0x66728EFE
	static int REQUEST_MISSION_AUDIO_BANK(const char* p0) { return invoke<int>(0x916E37CA, p0); } // 0x916E37CA
	static void MISSION_AUDIO_BANK_NO_LONGER_NEEDED() { invoke<void>(0x4E92CC7A); } // 0x4E92CC7A
	static int AMBIENT_AUDIO_BANK_NO_LONGER_NEEDED() { return invoke<int>(0x6DCC98E9); } // 0x6DCC98E9
	static Any GET_SOUND_ID(Any p0) { return invoke<Any>(0x6AE0AD56, p0); } // 0x6AE0AD56
	static void RELEASE_SOUND_ID(Any p0) { invoke<void>(0x9C080899, p0); } // 0x9C080899
	static BOOL IS_SOUND_ID_VALID(Any p0) { return invoke<BOOL>(0xE1D265FA, p0); } // 0xE1D265FA
	static void PLAY_SOUND(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xB6E1917F, p0, p1, p2, p3); } // 0xB6E1917F
	static int PLAY_SOUND_INIT_PARAMS(Any p0, Any p1) { return invoke<int>(0x09DA2503, p0, p1); } // 0x09DA2503
	static int PLAY_SOUND_INIT_PARAMS_PERSISTENT(Any p0, Any p1, Any p2) { return invoke<int>(0x66763C4A, p0, p1, p2); } // 0x66763C4A
	static void PLAY_SOUND_FRONTEND(const char* audioName) { invoke<void>(0x2E458F74, audioName); } // 0x2E458F74
	static void PLAY_SOUND_FRONTEND_INITPARAMS(Any p0, Any p1) { invoke<void>(0x49053A94, p0, p1); } // 0x49053A94
	static void PLAY_SOUND_FRONTEND_PERSISTENT(Any p0, Any p1) { invoke<void>(0xB157BBB4, p0, p1); } // 0xB157BBB4
	static void PLAY_SOUND_FROM_POSITION(const char* audioName, Vector3* position) { invoke<void>(0x05BC72D7, audioName, position); } // 0x05BC72D7
	static int PLAY_SOUND_FROM_POSITION_INITPARAMS(Any p0, Vector3* position, Any p4, Any p5, Any p6) { return invoke<int>(0x19E5CF85, p0, position, p4, p5, p6); } // 0x19E5CF85
	static void PLAY_SOUND_FROM_POSITION_PERSISTENT(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x5B05E3E0, p0, p1, p2, p3, p4); } // 0x5B05E3E0
	static void PLAY_WALLA_SOUND_FROM_POSITION_PERSISTENT(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x3375FB38, p0, p1, p2, p3, p4); } // 0x3375FB38
	static void PLAY_SOUND_FROM_ACTOR(Any p0, const char* p1, Any p2) { invoke<void>(0x628832AD, p0, p1, p2); } // 0x628832AD
	static int PLAY_WALLA_SOUND_FROM_ACTOR(Any p0, Any p1, Any p2) { return invoke<int>(0x4634B6BE, p0, p1, p2); } // 0x4634B6BE
	static void PLAY_SOUND_FROM_OBJECT(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x6A515A49, p0, p1, p2, p3); } // 0x6A515A49
	static Any AUDIO_SET_VEHICLE_DAMAGED(Any p0) { return invoke<Any>(0xBD0E8EBA, p0); } // 0xBD0E8EBA
	static void STOP_SOUND(Any p0) { invoke<void>(0xCD7F4030, p0); } // 0xCD7F4030
	static BOOL HAS_SOUND_FINISHED(Any p0) { return invoke<BOOL>(0xE85AEC2E, p0); } // 0xE85AEC2E
	static void AUDIO_ATTACH_MICROPHONE_TO_ACTOR(Any p0) { invoke<void>(0x74CA8E22, p0); } // 0x74CA8E22
	static void AUDIO_SET_MISSION_NAME_FOR_JOURNAL(Any p0) { invoke<void>(0x66FCA3F7, p0); } // 0x66FCA3F7
	static void AUDIO_CLEAR_MISSION_NAME_FOR_JOURNAL() { invoke<void>(0x14ED45FB); } // 0x14ED45FB
	static void AUDIO_RESET_SPEECH_HISTORY() { invoke<void>(0x7D95325E); } // 0x7D95325E
	static void AUDIO_RESET_SCRIPTED_SPEECH_HISTORY() { invoke<void>(0x1BB84187); } // 0x1BB84187
	static int AUDIO_HAS_CONVERSATION_PLAYED_ALREADY(Any p0) { return invoke<int>(0x3DFD83DE, p0); } // 0x3DFD83DE
	static void AUDIO_CLEAR_CONVERSATION_HISTORY() { invoke<void>(0xDD0320CB); } // 0xDD0320CB
	static int SAY_SINGLE_LINE_CONTEXT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x31BAF169, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x31BAF169
	static int SAY_SINGLE_LINE_STRING(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xBA734A15, p0, p1, p2, p3); } // 0xBA734A15
	static int SAY_SINGLE_LINE_STRING_WITH_REPLY(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x031E983D, p0, p1, p2, p3, p4, p5); } // 0x031E983D
	static int SAY_SINGLE_LINE_CONTEXT_OVER_PAIN(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x0871084C, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x0871084C
	static int SAY_SINGLE_LINE_STRING_OVER_PAIN(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x12D077CA, p0, p1, p2, p3); } // 0x12D077CA
	static int SAY_SINGLE_LINE_STRING_WITH_REPLY_OVER_PAIN(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x91DE3A31, p0, p1, p2, p3, p4, p5); } // 0x91DE3A31
	static int SAY_SINGLE_LINE_STRING_THROUGH_BLOCKED_SPEECH(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xFDA41D54, p0, p1, p2, p3); } // 0xFDA41D54
	static int SAY_SINGLE_LINE_STRING_WITH_BACKUPS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x955E5EEB, p0, p1, p2, p3, p4, p5); } // 0x955E5EEB
	static int SAY_SINGLE_LINE_SCRIPTED(Any p0) { return invoke<int>(0x755382BC, p0); } // 0x755382BC
	static int SAY_SINGLE_LINE_STRING_BEAT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { return invoke<int>(0x84A909EC, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x84A909EC
	static int SAY_SINGLE_LINE_STRING_SCRIPTED_INTERRUPT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12) { return invoke<int>(0x3F226995, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0x3F226995
	static void AUDIO_PLAY_VOCAL_EFFECT(Any p0, Any p1, Any p2) { invoke<void>(0xC9D3A484, p0, p1, p2); } // 0xC9D3A484
	static int AUDIO_PLAY_VOCAL_EFFECT_EVEN_IF_DEAD(Any p0, Any p1) { return invoke<int>(0xE5F39107, p0, p1); } // 0xE5F39107
	static void AUDIO_PLAY_PAIN(Any p0, Any p1) { invoke<void>(0x123709E8, p0, p1); } // 0x123709E8
	static int AUDIO_TRIGGER_PLAYER_KILLED_EVERYONE_SPEECH(Any p0, Any p1, Any p2) { return invoke<int>(0xA7D08EE9, p0, p1, p2); } // 0xA7D08EE9
	static int TREAT_AMBIENT_SPEECH_AS_SCRIPTED(Any p0, Any p1) { return invoke<int>(0xC0E28BF0, p0, p1); } // 0xC0E28BF0
	static void SET_AMBIENT_VOICE_NAME(Any p0, Any p1) { invoke<void>(0xBD2EA1A1, p0, p1); } // 0xBD2EA1A1
	static int CLEAR_ALTERNATE_SPEECH_CONTEXT_FOR_PAIN(Any p0) { return invoke<int>(0x77402033, p0); } // 0x77402033
	static void CANCEL_CURRENTLY_PLAYING_AMBIENT_SPEECH(Actor actor) { invoke<void>(0x4DBD473B, actor); } // 0x4DBD473B
	static BOOL IS_AMBIENT_SPEECH_PLAYING(Any p0) { return invoke<BOOL>(0x1972E8AA, p0); } // 0x1972E8AA
	static BOOL IS_SCRIPTED_SPEECH_PLAYING(Any p0) { return invoke<BOOL>(0x2C653904, p0); } // 0x2C653904
	static BOOL IS_ANY_SPEECH_PLAYING(Any p0) { return invoke<BOOL>(0x2B74A6D6, p0); } // 0x2B74A6D6
	static void AUDIO_STOP_PAIN(Any p0) { invoke<void>(0x462B3A65, p0); } // 0x462B3A65
	static int AUDIO_PLAY_PLAYER_HOGTIE_LINE(Any p0, Any p1, Any p2) { return invoke<int>(0x96161235, p0, p1, p2); } // 0x96161235
	static int AUDIO_TRIGGER_PLAYER_LOOTING_MALE_SPEECH(Any p0, Any p1, Any p2) { return invoke<int>(0x3184B507, p0, p1, p2); } // 0x3184B507
	static int AUDIO_TRIGGER_PLAYER_LOOTING_FEMALE_SPEECH(Any p0, Any p1, Any p2) { return invoke<int>(0x489B3078, p0, p1, p2); } // 0x489B3078
	static int AUDIO_TRIGGER_PLAYER_LOOTING_FEMALE_ZOMBIE_SPEECH(Any p0, Any p1, Any p2) { return invoke<int>(0xAA565B11, p0, p1, p2); } // 0xAA565B11
	static int AUDIO_TRIGGER_PLAYER_LOOTING_MALE_ZOMBIE_SPEECH(Any p0, Any p1, Any p2) { return invoke<int>(0x2CA089EC, p0, p1, p2); } // 0x2CA089EC
	static int AUDIO_SHUT_OFF_WALLA() { return invoke<int>(0x43C5F320); } // 0x43C5F320
	static int AUDIO_TURN_ON_WALLA() { return invoke<int>(0xF7B747CA); } // 0xF7B747CA
	static void SET_LOCAL_PLAYER_VOICE(const char* name) { invoke<void>(0xF0D28043, name); } // 0xF0D28043
	static void SET_LOCAL_PLAYER_PAIN_VOICE(const char* name) { invoke<void>(0x33BD1A80, name); } // 0x33BD1A80
	static int AUDIO_TURN_OFF_PAIN_VOCALS(Any p0) { return invoke<int>(0x1F7F405C, p0); } // 0x1F7F405C
	static int AUDIO_TURN_ON_PAIN_VOCALS(Any p0) { return invoke<int>(0x2B1B76E8, p0); } // 0x2B1B76E8
	static int AUDIO_TURN_OFF_VOCALS_EFFECTS(Any p0) { return invoke<int>(0xE4D418D1, p0); } // 0xE4D418D1
	static int AUDIO_SET_PLAYER_MOOD(Any p0, Any p1) { return invoke<int>(0xAF6A3160, p0, p1); } // 0xAF6A3160
	static int AUDIO_ALLOW_PREDUEL_SPEECH(Any p0) { return invoke<int>(0x94A24A5C, p0); } // 0x94A24A5C
	static int AUDIO_DISALLOW_PREDUEL_SPEECH(Any p0) { return invoke<int>(0xD021B37F, p0); } // 0xD021B37F
	static int AUDIO_CLEAR_PLAYER_DISABLED_CONTEXT_LIST() { return invoke<int>(0xA343FDBB); } // 0xA343FDBB
	static int AUDIO_ADD_TO_PLAYER_DISABLED_CONTEXT_LIST() { return invoke<int>(0xA4F209D5); } // 0xA4F209D5
	static void ADD_COMPANION_PERMANENT() { invoke<void>(0x45E20057); } // 0x45E20057
	static void AUDIO_ENABLE_PLAYER_TAUNTS() { invoke<void>(0x15547025); } // 0x15547025
	static int AUDIO_INIT_CAUCASIAN_ARMY_AE_RANGE(int result, Any p1) { return invoke<int>(0xE0553D6B, result, p1); } // 0xE0553D6B
	static int AUDIO_INIT_MEXICAN_ARMY_AE_RANGE(int result, Any p1) { return invoke<int>(0xD68E04BB, result, p1); } // 0xD68E04BB
	static int AUDIO_INIT_MISSION_CHARACTER_AE_RANGE(Any p0, Any p1) { return invoke<int>(0x638EAF70, p0, p1); } // 0x638EAF70
	static int AUDIO_INIT_RCM_CHARACTER_AE_RANGE(Any p0, Any p1) { return invoke<int>(0xEA975A79, p0, p1); } // 0xEA975A79
	static int AUDIO_INIT_FAC_INVALID_VALUE(int result) { return invoke<int>(0x6BB42C21, result); } // 0x6BB42C21
	static int AUDIO_INIT_FAC_CATTLE_RUSTLER_VALUE(int result) { return invoke<int>(0x0E634931, result); } // 0x0E634931
	static int AUDIO_INIT_FAC_DRUNKNDIRTY_VALUE(int result) { return invoke<int>(0x567712E5, result); } // 0x567712E5
	static int AUDIO_INIT_FAC_GENERIC_CRIMINAL_VALUE(int result) { return invoke<int>(0xB888B369, result); } // 0xB888B369
	static int AUDIO_INIT_FAC_INDIAN_LAW_ENFORCEMENT_VALUE(int result) { return invoke<int>(0x306D9FEE, result); } // 0x306D9FEE
	static int AUDIO_INIT_FAC_INDIAN_RAIDER_VALUE(int result) { return invoke<int>(0xC3614E0A, result); } // 0xC3614E0A
	static int AUDIO_INIT_FAC_LAW_ENFORCEMENT_VALUE(int result) { return invoke<int>(0xF962F2B8, result); } // 0xF962F2B8
	static int AUDIO_INIT_FAC_MEXICAN_BANDITO_VALUE(int result) { return invoke<int>(0x22D0DF9B, result); } // 0x22D0DF9B
	static int AUDIO_INIT_FAC_MEXICAN_LAW_ENFORCEMENT_VALUE(int result) { return invoke<int>(0xA234C5D0, result); } // 0xA234C5D0
	static int AUDIO_INIT_FAC_MEXICAN_REBEL_VALUE(int result) { return invoke<int>(0x733BA9F5, result); } // 0x733BA9F5
	static int AUDIO_INIT_FAC_MEXICAN_SOLDIER_VALUE(int result) { return invoke<int>(0x79351E54, result); } // 0x79351E54
	static int AUDIO_INIT_FAC_SMUGGLERS_VALUE(int result) { return invoke<int>(0xCCBE7F0F, result); } // 0xCCBE7F0F
	static int AUDIO_INIT_FAC_FAC_U_S_LAW_ENFORCEMENT_VALUE(int result) { return invoke<int>(0x5FCF3B85, result); } // 0x5FCF3B85
	static int AUDIO_INIT_ZOMBIE_BRUISER_AE_RANGE(Any p0, Any p1) { return invoke<int>(0x9D886C2F, p0, p1); } // 0x9D886C2F
	static int AUDIO_INIT_ZOMBIE_FAST_AE_RANGE(Any p0, Any p1) { return invoke<int>(0x39F5EF0F, p0, p1); } // 0x39F5EF0F
	static int AUDIO_INIT_ZOMBIE_TOXIC_AE_RANGE(Any p0, Any p1) { return invoke<int>(0xD6CC6907, p0, p1); } // 0xD6CC6907
	static int AUDIO_INIT_ZOMBIE_MP_PLAYER_AE_RANGE(Any p0, Any p1) { return invoke<int>(0x714D5D09, p0, p1); } // 0x714D5D09
	static int AUDIO_INIT_ZOMBIE_MP_FEMALE_VALUE(Any p0) { return invoke<int>(0xBF959948, p0); } // 0xBF959948
	static int AUDIO_INIT_FAC_ZOMBIE_VALUE(Any p0) { return invoke<int>(0x3C163FDD, p0); } // 0x3C163FDD
	static Any AUDIO_SET_CURRENT_AREA_IS_UNDER_ZOMBIE_ATTACK(Any p0) { return invoke<Any>(0xDC330FB9, p0); } // 0xDC330FB9
	static int AUDIO_INIT_ZOMBIE_ZONE() { return invoke<int>(0x39EF8DA7); } // 0x39EF8DA7
	static int AUDIO_INIT_ZOMBIE_PACK_INFO() { return invoke<int>(0x0079FD0F); } // 0x0079FD0F
	static int AUDIO_INIT_NUN_AE_RANGE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x67770F4B, p0, p1, p2, p3); } // 0x67770F4B
	static int AUDIO_SET_MAX_CREATURE_FOOTSTEP_UPDATES(Any p0) { return invoke<int>(0x8A6D03BE, p0); } // 0x8A6D03BE
	static Any AUDIO_SET_GLOBAL_LAW_VALUES(Any p0, Any p1, Any p2) { return invoke<Any>(0x90DD37E7, p0, p1, p2); } // 0x90DD37E7
	static void STOP_PED_SPEAKING(Any p0, Any p1) { invoke<void>(0xFF92B49D, p0, p1); } // 0xFF92B49D
	static void AUDIO_MISSION_INIT() { invoke<void>(0xEB8A51C2); } // 0xEB8A51C2
	static void AUDIO_MISSION_RELEASE() { invoke<void>(0xD1FD31DE); } // 0xD1FD31DE
	static void AUDIO_PLAY_DISTANT_THUNDER() { invoke<void>(0xEB866555); } // 0xEB866555
	static void AUDIO_MUSIC_FORCE_TRACK(const char* p0, const char* p1, Any p2, Any p3, Any p4, float p5, Any p6) { invoke<void>(0xA2A356A7, p0, p1, p2, p3, p4, p5, p6); } // 0xA2A356A7
	static void AUDIO_MUSIC_FORCE_TRACK_HASH(int hash, const char* p1, float p2, float p3, Any p4, Any p5, Any p6) { invoke<void>(0x6CEFA97A, hash, p1, p2, p3, p4, p5, p6); } // 0x6CEFA97A
	static int AUDIO_MUSIC_SCRIPT_LOOPING(Any p0, const char* p1, float p2, float p3, Any p4, Any p5, Any p6) { return invoke<int>(0x2ACEE2ED, p0, p1, p2, p3, p4, p5, p6); } // 0x2ACEE2ED
	static int AUDIO_MUSIC_SCRIPT_LOOPING_HASH(Any p0, const char* p1, float p2, float p3, Any p4, Any p5, Any p6) { return invoke<int>(0x85A35B18, p0, p1, p2, p3, p4, p5, p6); } // 0x85A35B18
	static void AUDIO_MUSIC_SET_MOOD(const char* p0, Any p1, Any p2, Any p3) { invoke<void>(0x633B8905, p0, p1, p2, p3); } // 0x633B8905
	static void AUDIO_MUSIC_ONE_SHOT(const char* musicName, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x714DA5BB, musicName, p1, p2, p3, p4, p5); } // 0x714DA5BB
	static int AUDIO_MUSIC_PLAY_PREPARED() { return invoke<int>(0x7CC2738F); } // 0x7CC2738F
	static int AUDIO_MUSIC_GET_RANDOM_TRACK_FROM_PLAYLIST(Any p0) { return invoke<int>(0x704DBAC9, p0); } // 0x704DBAC9
	static int AUDIO_MUSIC_IS_PREPARED() { return invoke<int>(0xBF316157); } // 0xBF316157
	static void AUDIO_MUSIC_SET_STATE(Any p0) { invoke<void>(0x789C753C, p0); } // 0x789C753C
	static void AUDIO_MUSIC_RELEASE_CONTROL(Any p0, Any p1) { invoke<void>(0xA3A2984E, p0, p1); } // 0xA3A2984E
	static void AUDIO_MUSIC_SUSPEND(Any p0) { invoke<void>(0x56E3D235, p0); } // 0x56E3D235
	static void AUDIO_MUSIC_RESUME() { invoke<void>(0x5F48A85B); } // 0x5F48A85B
	static BOOL AUDIO_IS_MUSIC_PLAYING() { return invoke<BOOL>(0x84435231); } // 0x84435231
	static int AUDIO_IS_SCRIPTED_MUSIC_PLAYING() { return invoke<int>(0x86E995D1); } // 0x86E995D1
	static BOOL AUDIO_IS_FRONTEND_MUSIC_PLAYING() { return invoke<BOOL>(0x9EC502D6); } // 0x9EC502D6
	static void AUDIO_MUSIC_SET_SUSPENSE_ALLOWED() { invoke<void>(0xE0DE16BD); } // 0xE0DE16BD
	static void AUDIO_MUSIC_PLAY_UNSCRIPTED_NOW() { invoke<void>(0xE2A37056); } // 0xE2A37056
	static void AUDIO_PLAY_ALL_LINES_FOR_ACTOR() { invoke<void>(0x72168160); } // 0x72168160
	static void AUDIO_MG_START() { invoke<void>(0xB3C3FF5E); } // 0xB3C3FF5E
	static void AUDIO_MG_STOP() { invoke<void>(0xEA2B35DB); } // 0xEA2B35DB
	static int AUDIO_MG_FILLET_START(float p0, float p1, float p2) { return invoke<int>(0x0CCE435E, p0, p1, p2); } // 0x0CCE435E
	static int AUDIO_MG_FILLET_HIT_FINGER() { return invoke<int>(0x7784BB85); } // 0x7784BB85
	static int AUDIO_MG_FILLET_HIT_TABLE() { return invoke<int>(0x24AE7AFB); } // 0x24AE7AFB
	static int AUDIO_MG_FILLET_PULL_FROM_TABLE() { return invoke<int>(0xDE7C65CE); } // 0xDE7C65CE
	static int AUDIO_MG_FILLET_END() { return invoke<int>(0x338DF299); } // 0x338DF299
	static int AUDIO_ADD_ALTERNATE_CONTEXT(Any p0, Any p1, Any p2) { return invoke<int>(0x2D40E85C, p0, p1, p2); } // 0x2D40E85C
	static int AUDIO_CLEAR_ALL_ALTERNATE_CONTEXTS() { return invoke<int>(0x900C489A); } // 0x900C489A
	static int LOAD_AUDIO_METADATA() { return invoke<int>(0xE8FFE727); } // 0xE8FFE727
	static int UNLOAD_AUDIO_METADATA() { return invoke<int>(0xB73AC04A); } // 0xB73AC04A
	static int LOAD_AUDIO_SPEECH_DATA() { return invoke<int>(0xBFCF32D9); } // 0xBFCF32D9
	static int SET_AUDIO_SEARCH_PATH() { return invoke<int>(0x37FD00EA); } // 0x37FD00EA
	static BOOL GET_AUDIO_BANK_LOADING_STATUS(const char* p0, const char* p1) { return invoke<BOOL>(0x98CD7340, p0, p1); } // 0x98CD7340
	static void LOAD_AUDIO_BANK(const char* p0, const char* p1) { invoke<void>(0x08F4B5B8, p0, p1); } // 0x08F4B5B8
	static int MAKE_AUDIO_SLOT_STATIC() { return invoke<int>(0x176E921C); } // 0x176E921C
	static int _AUDIO_SET_MS_BETWEEN_PLAYER_TALKS_TO_SELF(Any p0) { return invoke<int>(0xBAEC56D1, p0); } // 0xBAEC56D1
}

namespace BUILTIN
{
	static void WAIT(int ms) { invoke<void>(0x7715C03B, ms); } // 0x7715C03B
	static void WAITUNWARPED(int ms) { invoke<void>(0x01185F9B, ms); } // 0x01185F9B
	static void WAITUNPAUSED(int ms) { invoke<void>(0x7C496803, ms); } // 0x7C496803
	static int START_NEW_SCRIPT(const char* scriptName, int stackSize) { return invoke<int>(0x3F166D0E, scriptName, stackSize); } // 0x3F166D0E
	static int START_NEW_SCRIPT_WITH_ARGS(const char* scriptName, Any* args, int argCount, int stackSize) { return invoke<int>(0x4A2100E4, scriptName, args, argCount, stackSize); } // 0x4A2100E4
	static void SETTIMERA(int value) { invoke<void>(0x35785333, value); } // 0x35785333
	static float TIMESTEP() { return invoke<float>(0x50597EE2); } // 0x50597EE2
	static void PRINTSTRING(const char* str) { invoke<void>(0xECF8EB5F, str); } // 0xECF8EB5F
	static void PRINTFLOAT(float value) { invoke<void>(0xD48B90B6, value); } // 0xD48B90B6
	static void PRINTINT(int value) { invoke<void>(0x63651F03, value); } // 0x63651F03
	static void PRINTNL() { invoke<void>(0x868997DA); } // 0x868997DA
	static void PRINTVECTOR(float x, float y, float z) { invoke<void>(0x085F31FB, x, y, z); } // 0x085F31FB
	static float SQRT(float value) { return invoke<float>(0x145C7701, value); } // 0x145C7701
	static float POW(float base, float exponent) { return invoke<float>(0x85D134F8, base, exponent); } // 0x85D134F8
	static float EXP(float base, float exponent) { return invoke<float>(0xE2313450, base, exponent); } // 0xE2313450
	static float VMAG(float x, float y, float z) { return invoke<float>(0x1FCF1ECD, x, y, z); } // 0x1FCF1ECD
	static float VDIST(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<float>(0x3C08ECB7, x1, y1, z1, x2, y2, z2); } // 0x3C08ECB7
	static float VDIST2(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<float>(0xC85DEF1F, x1, y1, z1, x2, y2, z2); } // 0xC85DEF1F
	static int SHIFT_LEFT(int value, int bitShift) { return invoke<int>(0x314CC6CD, value, bitShift); } // 0x314CC6CD
	static int SHIFT_RIGHT(int value, int bitShift) { return invoke<int>(0x352633CA, value, bitShift); } // 0x352633CA
	static int FLOOR(float value) { return invoke<int>(0x32E9BE04, value); } // 0x32E9BE04
	static int CEIL(float value) { return invoke<int>(0xD536A1DF, value); } // 0xD536A1DF
	static int ROUND(float value) { return invoke<int>(0x323B0E24, value); } // 0x323B0E24
	static float TO_FLOAT(int value) { return invoke<float>(0x67116627, value); } // 0x67116627
	static void SNAPSHOT_GLOBALS() { invoke<void>(0x5A25520E); } // 0x5A25520E
	static const char* GET_LATEST_CONSOLE_COMMAND() { return invoke<const char*>(0x2B547FE6); } // 0x2B547FE6
	static void RESET_LATEST_CONSOLE_COMMAND() { invoke<void>(0xAA3EC981); } // 0xAA3EC981
	static const char* GET_CONSOLE_COMMAND_TOKEN(int token) { return invoke<const char*>(0x9DE3DE24, token); } // 0x9DE3DE24
	static int GET_NUM_CONSOLE_COMMAND_TOKENS() { return invoke<int>(0x608F5BC6); } // 0x608F5BC6
}

namespace CAM
{
	static Cam GET_GAME_CAMERA() { return invoke<Cam>(0x6B7677BF); } // 0x6B7677BF
	static void CAMERA_RESET(int p0) { invoke<void>(0xCE956B28, p0); } // 0xCE956B28
	static void SET_GAME_CAMERA_DRIFTZ(Any p0) { invoke<void>(0x39E59CD8, p0); } // 0x39E59CD8
	static void CAMERA_MANUAL_CUT() { invoke<void>(0x5E07BF3F); } // 0x5E07BF3F
	static BOOL CAMERA_PROBE(Vector3* result, Vector3* source, Vector3* target, Actor owner, int flag) { return invoke<BOOL>(0x720F2CA7, result, source, target, owner, flag); } // 0x720F2CA7
	static int END_GAME_CAMERA_ARC_TRANSITIONS() { return invoke<int>(0xC783B9B9); } // 0xC783B9B9
	static int GET_GAME_CAMERA_RESET_POSITION(Any p0, Any p1, float p2, float p3, float p4, float p5, Any p6, Any p7, Any p8, const char* p9) { return invoke<int>(0x0B071844, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x0B071844
	static int SET_CAMERA_FOLLOW_ACTOR(Actor actor) { return invoke<int>(0x8EFDFE89, actor); } // 0x8EFDFE89
	static int SET_CAMERA_FOLLOW_ACTOR_EX(Any p0, Any p1) { return invoke<int>(0x457A0510, p0, p1); } // 0x457A0510
	static int GET_LOOKSTICK_INVERT_Y() { return invoke<int>(0x9B083FD2); } // 0x9B083FD2
	static int SET_LOOKSTICK_INVERT_Y(Any p0) { return invoke<int>(0x063F900A, p0); } // 0x063F900A
	static int SET_GAME_CAMERA_CURVE_OVERRIDE(Any p0, Any p1) { return invoke<int>(0x507BBD3A, p0, p1); } // 0x507BBD3A
	static int RESET_GAME_CAMERA_CURVE_OVERRIDES() { return invoke<int>(0xC93116B1); } // 0xC93116B1
	static void FORCE_VEHICLE_CINEMATIC_CAMERA(Any p0) { invoke<void>(0x09737AF7, p0); } // 0x09737AF7
	static int IS_VEHICLE_CINEMATIC_CAMERA_FORCED_ON() { return invoke<int>(0x72960AE2); } // 0x72960AE2
	static int SET_GAME_CAMERA_VEHICLE_MODE(Any p0) { return invoke<int>(0x382C47C5, p0); } // 0x382C47C5
	static int ALLOW_GAME_CAMERA_AUTO_CENTERING(Any p0, Any p1) { return invoke<int>(0x6E303287, p0, p1); } // 0x6E303287
	static int GET_GAME_CAMERA_AUTO_CENTERING_STATE(Any p0) { return invoke<int>(0xE13B49BD, p0); } // 0xE13B49BD
	static int ALLOW_GAME_CAMERA_AUTO_TILTING(Any p0, Any p1) { return invoke<int>(0x9603D3B2, p0, p1); } // 0x9603D3B2
	static int GET_GAME_CAMERA_AUTO_TILTING_STATE(Any p0) { return invoke<int>(0x4062688A, p0); } // 0x4062688A
	static void SET_GAME_CAMERA_FOCUS(float p0, float p1, float p2, Any p3, Any p4, Any p5) { invoke<void>(0x3AE77125, p0, p1, p2, p3, p4, p5); } // 0x3AE77125
	static int ENABLE_GAME_CAMERA_FOCUS(float p0, float p1, float p2, float p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x87E40FB8, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x87E40FB8
	static int DISABLE_GAME_CAMERA_FOCUS() { return invoke<int>(0x4FA19C01); } // 0x4FA19C01
	static int IS_GAME_CAMERA_FOCUS_ENABLED() { return invoke<int>(0x5BD2295E); } // 0x5BD2295E
	// Not present in the retail version! It's just a nullsub.
	static int SET_DEBUG_CAMERA_MODE() { return invoke<int>(0xF3623B64); } // 0xF3623B64
	static int IS_SWITCH_CAMERA_BUTTON_ENABLED() { return invoke<int>(0xAE168124); } // 0xAE168124
	static BOOL SET_SWITCH_CAMERA_BUTTON_ENABLED(BOOL p0) { return invoke<BOOL>(0x9F1F8669, p0); } // 0x9F1F8669
}

namespace CAMERA
{
	static Cam CREATE_CAMERA_IN_LAYOUT(Layout layout, const char* layoutName, int channel) { return invoke<Cam>(0x0B1569C5, layout, layoutName, channel); } // 0x0B1569C5
	static Cam GET_CURRENT_CAMERA_TYPE_FROM_CHANNEL(int channel) { return invoke<Cam>(0xBCC98808, channel); } // 0xBCC98808
	static void SET_CURRENT_CAMERA_ON_CHANNEL(Cam camera, int channel, float p2, float p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { invoke<void>(0x3EA55678, camera, channel, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x3EA55678
	static void REMOVE_CAMERA_FROM_CHANNEL(Cam camera, int channel) { invoke<void>(0x423DB420, camera, channel); } // 0x423DB420
	static int GET_CAMERA_CHANNEL_POSITION(Any p0, int channel) { return invoke<int>(0xE017E2F7, p0, channel); } // 0xE017E2F7
	static int GET_CAMERA_CHANNEL_DIRECTION(Any p0, int channel) { return invoke<int>(0x6ED00237, p0, channel); } // 0x6ED00237
	static BOOL IS_CURRENT_CAMERA_CHANNEL_TRANSITIONING(int channel) { return invoke<BOOL>(0x9A4CD54B, channel); } // 0x9A4CD54B
	static BOOL IS_CAMERA_ACTIVE_ON_CHANNEL(Cam camera, int channel) { return invoke<BOOL>(0x02BD5362, camera, channel); } // 0x02BD5362
	static void INIT_CAMERA_FROM_GAME_CAMERA(Cam camera) { invoke<void>(0x2615309A, camera); } // 0x2615309A
	static void INIT_CAMERA_FROM_CHANNEL(Cam camera, int channel) { invoke<void>(0x41EA7325, camera, channel); } // 0x41EA7325
	static void SET_CAMERA_POSITION(Cam camera, Vector2 positionXY, float positionZ) { invoke<void>(0x0B12CD8C, camera, positionXY, positionZ); } // 0x0B12CD8C
	static void SET_CAMERA_POSITION(Cam camera, Vector3 positionxy) { invoke<void>(0x0B12CD8C, camera, Vector2(positionxy.x, positionxy.y), positionxy.z); } // 0x0B12CD8C
	static void GET_CAMERA_POSITION(Cam camera, Vector3* position) { invoke<void>(0x4A65F0B7, camera, position); } // 0x4A65F0B7
	static void SET_CAMERA_DIRECTION(Cam camera, Vector3* direction, BOOL p0) { invoke<void>(0xA8642E5E, camera, direction, p0); } // 0xA8642E5E
	static void GET_CAMERA_DIRECTION(Cam camera, Vector3* direction) { invoke<void>(0xBBD1078A, camera, direction); } // 0xBBD1078A
	static void GET_CAMERA_UP_VECTOR(Cam camera, Vector3* vector) { invoke<void>(0x94A10ECD, camera, vector); } // 0x94A10ECD
	// Default game fov is 55.5f.
	static void SET_CAMERA_FOV(Cam camera, float fov) { invoke<void>(0x57E3242D, camera, fov); } // 0x57E3242D
	static float GET_CAMERA_FOV(Cam camera) { return invoke<float>(0x7B302F36, camera); } // 0x7B302F36
	static void SET_CAMERA_ASPECT_RATIO(Cam camera, float value) { invoke<void>(0xFAEE2667, camera, value); } // 0xFAEE2667
	static float GET_CAMERA_ASPECT_RATIO(Cam camera) { return invoke<float>(0xCE01609D, camera); } // 0xCE01609D
	static void SET_CAMERA_NEAR_CLIP_PLANE(Cam camera, float value) { invoke<void>(0x1D29E72A, camera, value); } // 0x1D29E72A
	static void SET_CAMERA_FAR_CLIP_PLANE(Cam camera, float value) { invoke<void>(0xD85EF521, camera, value); } // 0xD85EF521
	static void SET_CAMERA_ORIENTATION(Cam camera, Vector2 orientationXY, float orientationZ, BOOL p4) { invoke<void>(0x486F4461, camera, orientationXY, orientationZ, p4); } // 0x486F4461
	static void SET_CAMERA_ORIENTATION(Cam camera, Vector3 orientationxy, BOOL p4) { invoke<void>(0x486F4461, camera, Vector2(orientationxy.x, orientationxy.y), orientationxy.z, p4); } // 0x486F4461
	static void SET_CAMERA_TARGET_POSITION(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x298BCCA5, p0, p1, p2, p3, p4); } // 0x298BCCA5
	static void SET_CAMERA_TARGET_OBJECT(Cam camera, Object object, int p2) { invoke<void>(0xDBD1AE22, camera, object, p2); } // 0xDBD1AE22
	static void SET_CAMERA_COLLISION_PARAMETERS(Any p0, Any p1, Any p2) { invoke<void>(0xB8FAD252, p0, p1, p2); } // 0xB8FAD252
	static void ADD_CAMERA_COLLISION_EXCLUSION(Any p0, Any p1, Any p2) { invoke<void>(0x5BBFA4D7, p0, p1, p2); } // 0x5BBFA4D7
	static void REMOVE_CAMERA_COLLISION_EXCLUSION(Any p0, Any p1) { invoke<void>(0x781D5599, p0, p1); } // 0x781D5599
	static void RESET_CAMERA_TARGET(Any p0, Any p1) { invoke<void>(0x313A4E61, p0, p1); } // 0x313A4E61
	static void SET_CAMERA_COLLISION_ENABLED(Any p0, Any p1) { invoke<void>(0x7DA71AA7, p0, p1); } // 0x7DA71AA7
	static int SET_CAMERA_TARGETDOF_FOCAL_LENGTH(Any p0, float p1) { return invoke<int>(0x3010BBC2, p0, p1); } // 0x3010BBC2
	static void SET_CAMERA_TARGETDOF_USING_SOFT_DOF(Any p0, Any p1, Any p2) { invoke<void>(0x7F1C5102, p0, p1, p2); } // 0x7F1C5102
	static void RESET_CAMERA_TARGETDOF(Any p0) { invoke<void>(0x4643D2C7, p0); } // 0x4643D2C7
	static Any SET_CAMERA_LIGHTING_SCHEME(Any p0, Any p1) { return invoke<Any>(0x7C864F17, p0, p1); } // 0x7C864F17
	static int CAMERA_GET_CURRENT_TRANSITION_TYPE(Any p0) { return invoke<int>(0xE55B5ADB, p0); } // 0xE55B5ADB
	static int CAMERA_IS_VISIBLE_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0x965A4652, p0, p1, p2, p3, p4, p5, p6); } // 0x965A4652
	static int CAMERA_IS_VISIBLE_ACTOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0xBB6FDF5F, p0, p1, p2, p3, p4, p5, p6); } // 0xBB6FDF5F
	static int CAMERA_IS_VISIBLE_POINT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0xA97770FE, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xA97770FE
	static Cam CAMERA_IS_VISIBLE_VOLUME(Cam p0, Cam p1, Cam p2, Cam p3, Cam p4, Cam p5, Cam p6) { return invoke<Cam>(0xA161768C, p0, p1, p2, p3, p4, p5, p6); } // 0xA161768C
	static int CREATE_CAMERASHOT_IN_LAYOUT(Any p0, Any p1) { return invoke<int>(0x54A417F3, p0, p1); } // 0x54A417F3
	static void INIT_CAMERASHOT_FROM_GAME_CAMERA(Any p0) { invoke<void>(0x99314873, p0); } // 0x99314873
	static void FORCE_CAMERASHOT_UPDATE(Any p0) { invoke<void>(0xF5CA55D4, p0); } // 0xF5CA55D4
	static void SET_CAMERASHOT_POSITION(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x0EA022F5, p0, p1, p2, p3); } // 0x0EA022F5
	static void GET_CAMERASHOT_POSITION(Any p0, Any p1) { invoke<void>(0x4D05D470, p0, p1); } // 0x4D05D470
	static void SET_CAMERASHOT_DIRECTION(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x21B099AB, p0, p1, p2, p3, p4); } // 0x21B099AB
	static void GET_CAMERASHOT_DIRECTION(Any p0, Any p1) { invoke<void>(0x4670416D, p0, p1); } // 0x4670416D
	static int GET_CAMERASHOT_UP_VECTOR(Any p0, Any p1) { return invoke<int>(0x83F3336B, p0, p1); } // 0x83F3336B
	static int GET_CAMERASHOT_X_VECTOR(Any p0, Any p1) { return invoke<int>(0x7597BC24, p0, p1); } // 0x7597BC24
	static void SET_CAMERASHOT_FOV(Any p0, Any p1) { invoke<void>(0x635E5494, p0, p1); } // 0x635E5494
	static int GET_CAMERASHOT_FOV(Any p0) { return invoke<int>(0xEAD6167D, p0); } // 0xEAD6167D
	static void SET_CAMERASHOT_ASPECT_RATIO(Any p0, Any p1) { invoke<void>(0x3DEB0933, p0, p1); } // 0x3DEB0933
	static void SET_CAMERASHOT_NEAR_CLIP_PLANE(Any p0, Any p1) { invoke<void>(0x4387CDAB, p0, p1); } // 0x4387CDAB
	static void SET_CAMERASHOT_FAR_CLIP_PLANE(Any p0, Any p1) { invoke<void>(0x6BA86494, p0, p1); } // 0x6BA86494
	static int GET_CAMERASHOT_FAR_CLIP_PLANE(Any p0) { return invoke<int>(0xD86CB952, p0); } // 0xD86CB952
	static void SET_CAMERASHOT_ORIENTATION(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x4FD679BD, p0, p1, p2, p3, p4); } // 0x4FD679BD
	static void SET_CAMERASHOT_TARGET_POSITION(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x0D6EC5D5, p0, p1, p2, p3, p4); } // 0x0D6EC5D5
	static void SET_CAMERASHOT_TARGET_OBJECT(Any p0, Any p1, Any p2) { invoke<void>(0x3F719473, p0, p1, p2); } // 0x3F719473
	static void SET_CAMERASHOT_TARGET_OBJECT_OFFSETS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { invoke<void>(0x839E9502, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x839E9502
	static void SET_CAMERASHOT_TARGET_OBJECT_ROLL(Any p0, Any p1) { invoke<void>(0x8014323A, p0, p1); } // 0x8014323A
	static void SET_CAMERASHOT_TARGET_OBJECT_BONE(Any p0, Any p1, Any p2) { invoke<void>(0x4E6DDD27, p0, p1, p2); } // 0x4E6DDD27
	static void SET_CAMERASHOT_FROM_LENS(Any p0, Any p1) { invoke<void>(0x6F483443, p0, p1); } // 0x6F483443
	static void SET_CAMERASHOT_TARGETDOF_OBJECT(Any p0, Any p1) { invoke<void>(0xB6BDCF62, p0, p1); } // 0xB6BDCF62
	static void SET_CAMERASHOT_TARGETDOF_TARGET_OFFSET(Any p0, Any p1) { invoke<void>(0x087B8DCE, p0, p1); } // 0x087B8DCE
	static void SET_CAMERASHOT_TARGETDOF_FIXED_DISTANCE(Any p0, Any p1) { invoke<void>(0xEF0AB304, p0, p1); } // 0xEF0AB304
	static void SET_CAMERASHOT_TARGETDOF_FOCAL_LENGTH(Any p0, Any p1) { invoke<void>(0x0AD50615, p0, p1); } // 0x0AD50615
	static void SET_CAMERASHOT_TARGETDOF_CUTOFF_DISTANCE(Any p0, Any p1) { invoke<void>(0xEB9E1CB9, p0, p1); } // 0xEB9E1CB9
	static void SET_CAMERASHOT_TARGETDOF_SMOOTHING(Any p0, Any p1) { invoke<void>(0x74168B5F, p0, p1); } // 0x74168B5F
	static void SET_CAMERASHOT_TARGETDOF_USING_SOFT_DOF(Any p0, Any p1, Any p2) { invoke<void>(0x0370451C, p0, p1, p2); } // 0x0370451C
	static void SET_CAMERASHOT_TARGETDOF_FILTERTYPE(Any p0, Any p1) { invoke<void>(0x243CF01F, p0, p1); } // 0x243CF01F
	static void SET_CAMERASHOT_TARGETDOF_FSTOP(Any p0, Any p1) { invoke<void>(0x9E618676, p0, p1); } // 0x9E618676
	static void RESET_CAMERASHOT_TARGETDOF(Any p0) { invoke<void>(0x42327DAC, p0); } // 0x42327DAC
	static void SET_CAMERASHOT_COLLISION_PARAMETERS(Any p0, Any p1, Any p2) { invoke<void>(0xF70817E0, p0, p1, p2); } // 0xF70817E0
	static void ADD_CAMERASHOT_COLLISION_EXCLUSION(Any p0, Any p1, Any p2) { invoke<void>(0x58A0BFBF, p0, p1, p2); } // 0x58A0BFBF
	static void ADD_CAMERASHOT_COLLISION_BOUNDFLAG(Any p0, Any p1) { invoke<void>(0xCD28C63F, p0, p1); } // 0xCD28C63F
	static int RESET_CAMERASHOT_TARGET(Any p0, Any p1) { return invoke<int>(0xC3DDCE4D, p0, p1); } // 0xC3DDCE4D
	static void SET_CAMERASHOT_PERSPECTIVE(Any p0, Any p1) { invoke<void>(0xD8D27321, p0, p1); } // 0xD8D27321
	static void SET_CAMERASHOT_CONTROL_SEQUENCE_VEC3(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { invoke<void>(0x0229585E, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x0229585E
	static int ADD_CAMERA_SHOT_TRANSITION_HOLD(Any p0, Any p1, Any p2, float p3, Any p4, Any p5) { return invoke<int>(0x8F5BC02D, p0, p1, p2, p3, p4, p5); } // 0x8F5BC02D
	static int ADD_CAMERA_SHOT_TRANSITION_INDEFINITE(Any p0, Any p1, Any p2) { return invoke<int>(0xBF9B4FC6, p0, p1, p2); } // 0xBF9B4FC6
	static int ADD_CAMERA_SHOT_TRANSITION_EASE_OUT(Any p0, Any p1, Any p2, Any p3, Any p4, float p5, Any p6, Any p7, const char* p8) { return invoke<int>(0x6D72797D, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x6D72797D
	static int ADD_CAMERA_SHOT_TRANSITION_EASE_IN_OUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x6E10E587, p0, p1, p2, p3, p4, p5); } // 0x6E10E587
	static void SET_FIXED_TRANSITION_T(Any p0, Any p1) { invoke<void>(0x143A617C, p0, p1); } // 0x143A617C
	static void SET_TRANSITION_COLLISION_PARAMS(Any p0, Any p1, Any p2) { invoke<void>(0x22A746E1, p0, p1, p2); } // 0x22A746E1
	static int GET_CAMERA_SHOT_TRANSITION(Any p0) { return invoke<int>(0x7AC13DF5, p0); } // 0x7AC13DF5
	static BOOL IS_PROCESSING_CAMERA_SHOT_TRANSITION(Any p0) { return invoke<BOOL>(0xDDB64AA9, p0); } // 0xDDB64AA9
	static void END_CURRENT_CAMERA_SHOT_TRANSITION(Any p0) { invoke<void>(0x01C1F583, p0); } // 0x01C1F583
	static void SET_CAMERASHOT_COLLISION_ENABLED(Any p0, Any p1) { invoke<void>(0x3A07F60F, p0, p1); } // 0x3A07F60F
	static void SET_CUTSCENE_STREAMING_LOAD_SCENE(Any p0, Any p1) { invoke<void>(0x39D1CC17, p0, p1); } // 0x39D1CC17
	static int ATTACH_CAMERASHOT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11) { return invoke<int>(0x41514AA0, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x41514AA0
	static void DETACH_CAMERASHOT(Any p0) { invoke<void>(0x059BBAA8, p0); } // 0x059BBAA8
	static int CAMERASHOT_IS_VISIBLE_ACTOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0xCBA91134, p0, p1, p2, p3, p4, p5, p6); } // 0xCBA91134
	static void CAMERASHOT_ADD_ARC_BEHAVIOR(Any p0, Any p1) { invoke<void>(0xA1C665E0, p0, p1); } // 0xA1C665E0
	static void CAMERASHOT_ADD_LOOKSTICK_ROTATION_BEHAVIOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x59AE458A, p0, p1, p2, p3, p4, p5, p6); } // 0x59AE458A
	static int CREATE_AIMRAMP_IN_LAYOUT(Any p0, Any p1) { return invoke<int>(0xDA50B18B, p0, p1); } // 0xDA50B18B
	static void UPDATE_AIMRAMP(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x86066A65, p0, p1, p2, p3, p4); } // 0x86066A65
	static int CREATE_CUTSCENEOBJECT_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xA923A22D, p0, p1, p2, p3); } // 0xA923A22D
	static int GET_CAMERA_FROM_CUTSCENEOBJECT(Any p0) { return invoke<int>(0xFDBE95AE, p0); } // 0xFDBE95AE
	static void PLAY_CUTSCENEOBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { invoke<void>(0xFB28AE8D, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xFB28AE8D
	static Any GET_CAMERASHOT_FROM_CUTSCENEOBJECT(Any p0, Any p1) { return invoke<Any>(0x7E9CC966, p0, p1); } // 0x7E9CC966
	static int CUTSCENEOBJECT_ADD_TRANSITION_HOLD(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xC0CD3C96, p0, p1, p2, p3); } // 0xC0CD3C96
	static int CUTSCENEOBJECT_ADD_TRANSITION_LERP(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xFC676413, p0, p1, p2, p3, p4, p5); } // 0xFC676413
	static int CUTSCENEOBJECT_ADD_TRANSITION_EASE_IN(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xCC61CC5F, p0, p1, p2, p3, p4, p5); } // 0xCC61CC5F
	static int CUTSCENEOBJECT_ADD_TRANSITION_EASE_OUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x1AD38A53, p0, p1, p2, p3, p4, p5); } // 0x1AD38A53
	static int CUTSCENEOBJECT_ADD_TRANSITION_EASE_IN_OUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xDB07C72B, p0, p1, p2, p3, p4, p5); } // 0xDB07C72B
	static int CUTSCENEOBJECT_ADD_TRANSITION_INDEFINITE(Any p0, Any p1, Any p2) { return invoke<int>(0x94B288F9, p0, p1, p2); } // 0x94B288F9
	static int CUTSCENEOBJECT_ADD_TRANSITION_DECORATOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0xA9AB9A06, p0, p1, p2, p3, p4, p5, p6); } // 0xA9AB9A06
	static int CUTSCENEOBJECT_ADD_TRANSITION_FIXED(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x7A48EDDF, p0, p1, p2, p3, p4); } // 0x7A48EDDF
	static int CUTSCENEOBJECT_GET_CURRENT_TRANSITION_TYPE(Any p0) { return invoke<int>(0x0A776763, p0); } // 0x0A776763
	static void END_CURRENT_TRANSITION_FROM_CUTSCENEOBJECT(Any p0) { invoke<void>(0xBE3F0168, p0); } // 0xBE3F0168
	static void SET_CUTSCENEOBJECT_PAUSED(Any p0, Any p1) { invoke<void>(0x18643DC2, p0, p1); } // 0x18643DC2
	static BOOL IS_CUTSCENEOBJECT_PAUSED(Any p0) { return invoke<BOOL>(0xD5C66699, p0); } // 0xD5C66699
	static int CHECK_CUTSCENE_COLLISIONS(Any p0) { return invoke<int>(0xE147BA8E, p0); } // 0xE147BA8E
	static int GET_CUTSCENEOBJECT_SEQUENCE(Any p0) { return invoke<int>(0x3D26D852, p0); } // 0x3D26D852
	static void CUTSCENEOBJECT_SET_RECENTER_GAMECAM(Any p0, Any p1) { invoke<void>(0xDCD3A7DE, p0, p1); } // 0xDCD3A7DE
	static int SET_CUTSCENEINPUTS_TARGET_GUID(Any p0, Any p1, Any p2) { return invoke<int>(0xF74B5ADE, p0, p1, p2); } // 0xF74B5ADE
	static void ADD_CAMERATRANSITION_EVENT_HUDFADEIN(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x25A58402, p0, p1, p2, p3); } // 0x25A58402
	static void ADD_CAMERATRANSITION_EVENT_HUDFADEOUT(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x269F5C75, p0, p1, p2, p3); } // 0x269F5C75
	static int ADD_CAMERATRANSITION_EVENT_GAMECAMERARESET(Any p0, float p1, float p2, Any p3, Any p4) { return invoke<int>(0x699332B0, p0, p1, p2, p3, p4); } // 0x699332B0
	static void ADD_CAMERATRANSITION_EVENT_GAMECAMERARESETTILT(Any p0, Any p1) { invoke<void>(0x3A8487A6, p0, p1); } // 0x3A8487A6
	static void ADD_CAMERATRANSITION_EVENT_CUTGAMECAMERABEHINDPLAYER(Any p0, Any p1, Any p2) { invoke<void>(0x8D7070F3, p0, p1, p2); } // 0x8D7070F3
	static int IS_CUTSCENE_TUNER_PLAYINGBACK() { return invoke<int>(0xCDA6BB6C); } // 0xCDA6BB6C
	static void CANCEL_CUTSCENE_TUNER_PLAYBACK() { invoke<void>(0xE7A1C191); } // 0xE7A1C191
	static int GET_CUTSCENE_TUNER_CUTSCENEOBJECT() { return invoke<int>(0x93050734); } // 0x93050734
	static int GET_CUTSCENE_TUNER_INPUTSOBJECT() { return invoke<int>(0xFF1F1730); } // 0xFF1F1730
	static Any GET_CUTSCENE_TUNER_SCRIPT_NAME() { return invoke<Any>(0x74EE96B8); } // 0x74EE96B8
	static int GET_CUTSCENE_TUNER_CUTSCENE_INDEX() { return invoke<int>(0xD8218A5B); } // 0xD8218A5B
	static int CREATE_CAMERA_FOCUS_POINT(int* p0, Any p1, Any p2, float p3, float p4, float p5, float p6, float p7) { return invoke<int>(0x6AD6A400, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x6AD6A400
	static int CREATE_CAMERA_FOCUS_POINT_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x76876FEA, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x76876FEA
	static int CREATE_CAMERA_FOCUS_POINT_OBJECT_WITH_TUNING(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x7A6146DB, p0, p1, p2, p3, p4, p5); } // 0x7A6146DB
	static BOOL IS_CAMERA_FOCUS_ACTIVE(Any p0) { return invoke<BOOL>(0xCA8CC5CE, p0); } // 0xCA8CC5CE
	static void SET_CAMERA_FOCUS_ENABLED(Any p0, Any p1) { invoke<void>(0x78D29E49, p0, p1); } // 0x78D29E49
	static BOOL IS_CAMERA_FOCUS_ENABLED(Any p0) { return invoke<BOOL>(0x80D63DAC, p0); } // 0x80D63DAC
	static void SET_CAMERA_FOCUS_PROMPT_ENABLED(Any p0, Any p1) { invoke<void>(0x2148298D, p0, p1); } // 0x2148298D
	static BOOL IS_CAMERA_FOCUS_PROMPT_ENABLED(Any p0) { return invoke<BOOL>(0x52B9A693, p0); } // 0x52B9A693
	static void SET_CAMERA_FOCUS_PLAYER_INPUT_DISABLED(Any p0, Any p1) { invoke<void>(0x6FDE0A8C, p0, p1); } // 0x6FDE0A8C
	static void SET_CAMERA_FOCUS_PLAYER_INVULNERABLE(Any p0, Any p1) { invoke<void>(0x4A3AE626, p0, p1); } // 0x4A3AE626
	static void SET_CAMERA_FOCUS_PROMPT_TEXT(Any p0, Any p1) { invoke<void>(0x21633E5F, p0, p1); } // 0x21633E5F
	static void SET_CAMERA_FOCUS_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x48C3D85A, p0, p1, p2, p3, p4, p5); } // 0x48C3D85A
}

namespace CORE
{
	// PC only
	static Any OVERRIDE_BENCHMARK_POS(Any p0) { return invoke<Any>(0x14993D3B, p0); } // 0x14993D3B
	// PC only
	static Any OVERRIDE_BENCHMARK_DIR(Any p0) { return invoke<Any>(0xE8AB1D5B, p0); } // 0xE8AB1D5B
	// Not present in the retail version! It's just a nullsub.
	static void SET_DEBUG_DRAW(Any p0) { invoke<void>(0x505A8057, p0); } // 0x505A8057
	// This function is hard-coded to always return 0.
	static int GET_DEBUG_DRAW_STATE() { return invoke<int>(0xFF0B53EF); } // 0xFF0B53EF
	// This function is hard-coded to always return 0.
	static int _0x6DE957C6() { return invoke<int>(0x6DE957C6); } // 0x6DE957C6
	// Not present in the retail version! It's just a nullsub.
	static void SCRIPT_BREAKPOINT(Any p0) { invoke<void>(0xA81DABA3, p0); } // 0xA81DABA3
	// Not present in the retail version! It's just a nullsub.
	static void GRINGO_DEBUG_CHECK_SOUND(Any p0) { invoke<void>(0x5AC72FCC, p0); } // 0x5AC72FCC
	static void DISABLE_ACTOR_REFCOUNTING(Any p0) { invoke<void>(0x9FEFA743, p0); } // 0x9FEFA743
	static const char* GET_SCRIPT_NAME() { return invoke<const char*>(0x0BC52445); } // 0x0BC52445
	static const char* GET_SHORT_SCRIPT_NAME() { return invoke<const char*>(0x960DB7A5); } // 0x960DB7A5
	static void TERMINATE_THIS_SCRIPT() { invoke<void>(0x245B6AB6); } // 0x245B6AB6
	static int GET_THIS_SCRIPT_ID() { return invoke<int>(0x9C424E0D); } // 0x9C424E0D
	static BOOL IS_SCRIPT_VALID(ScrHandle script) { return invoke<BOOL>(0x45F7D589, script); } // 0x45F7D589
	static BOOL DOES_SCRIPT_EXIST(const char* scriptPath) { return invoke<BOOL>(0xDEAB87AB, scriptPath); } // 0xDEAB87AB
	static BOOL IS_EXITFLAG_SET() { return invoke<BOOL>(0x687ECC3C); } // 0x687ECC3C
	static int _IS_ANY_NAMED_SCRIPT_RUNNING(Any p0) { return invoke<int>(0x4417C9F2, p0); } // 0x4417C9F2
	static void _TERMINATE_ALL_NAMED_CHILD_SCRIPTS(Any p0) { invoke<void>(0x05719022, p0); } // 0x05719022
	static void TERMINATE_SCRIPT(Any p0) { invoke<void>(0x60A7FF09, p0); } // 0x60A7FF09
	static void ADD_PERSISTENT_SCRIPT(ScrHandle script) { invoke<void>(0x2F109475, script); } // 0x2F109475
	static void REMOVE_PERSISTENT_SCRIPT(Any p0) { invoke<void>(0xC605E92F, p0); } // 0xC605E92F
	static int SCRIPT_MAX_ALLOWED_INSTRUCTIONS() { return invoke<int>(0x4C48EA4D); } // 0x4C48EA4D
	static int SCRIPT_USED_INSTRUCTIONS() { return invoke<int>(0xD058BD70); } // 0xD058BD70
	static int SCRIPT_REMAINING_INSTRUCTIONS() { return invoke<int>(0x26884138); } // 0x26884138
	static void RAND_SET_SEED(Any p0) { invoke<void>(0xC0C6245E, p0); } // 0xC0C6245E
	static int RAND_INT_RANGE(int min, int max) { return invoke<int>(0xF8D0D165, min, max); } // 0xF8D0D165
	static float RAND_FLOAT_RANGE(float min, float max) { return invoke<float>(0xCA6229BF, min, max); } // 0xCA6229BF
	static Any RAND_INT_RANGE_DIFFERENT(Any min, Any max, Any p2) { return invoke<Any>(0x1D69F321, min, max, p2); } // 0x1D69F321
	static Any RAND_FLOAT_GAUSSIAN(Any p0) { return invoke<Any>(0x5D934CCB, p0); } // 0x5D934CCB
	static void FILE_START_PATH(Any p0) { invoke<void>(0x973BC454, p0); } // 0x973BC454
	static void FILE_ADD_TO_PATH(Any p0) { invoke<void>(0x63CDBB01, p0); } // 0x63CDBB01
	static void FILE_END_PATH() { invoke<void>(0x9A202E1B); } // 0x9A202E1B
	static int FILE_GET_CURRENT_PATH() { return invoke<int>(0x6F323C5F); } // 0x6F323C5F
	static float GET_X(Actor actor) { return invoke<float>(0x436CE75A, actor); } // 0x436CE75A
	static float GET_Y(Actor actor) { return invoke<float>(0x0B0FF6A1, actor); } // 0x0B0FF6A1
	static float GET_Z(Actor actor) { return invoke<float>(0x25A02BC1, actor); } // 0x25A02BC1
	static void VNORMALIZE(Any p0) { invoke<void>(0x836466F8, p0); } // 0x836466F8
	static void VCROSS(Any p0, Any p1, Any p2) { invoke<void>(0x4D629653, p0, p1, p2); } // 0x4D629653
	static int VDOT(Any p0, Any p1) { return invoke<int>(0x30A9FA0A, p0, p1); } // 0x30A9FA0A
	static void VSCALE(Vector3* p0, float p1) { invoke<void>(0x13530581, p0, p1); } // 0x13530581
	static int _VDIRECTION_VECTOR_FROM_EULERS(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xF1A53C41, p0, p1, p2, p3); } // 0xF1A53C41
	static void _VROTATE_VECTOR_FROM_EULERS(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xF76F2BB3, p0, p1, p2, p3); } // 0xF76F2BB3
	static void _VROTATE_EULER_FROM_EULERS(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x65DAA654, p0, p1, p2, p3, p4); } // 0x65DAA654
	static void ROTATE_VECTOR_XZ(Any p0, Any p1, Any p2) { invoke<void>(0x1BD78730, p0, p1, p2); } // 0x1BD78730
	static int _CONSTRUCT_MATRIX_AND_TRANSFORM(float p0, float p1, float p2, float p3, float p4, float p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x141201A3, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x141201A3
	static float FABS(float value) { return invoke<float>(0xACF9A5E4, value); } // 0xACF9A5E4
	static int ABS(int value) { return invoke<int>(0x5AABFA97, value); } // 0x5AABFA97
	static float SIN_DEGREE(float value) { return invoke<float>(0x55842354, value); } // 0x55842354
	static float COS_DEGREE(float value) { return invoke<float>(0x430207A4, value); } // 0x430207A4
	static float TAN_DEGREE(float value) { return invoke<float>(0x9BD37A3D, value); } // 0x9BD37A3D
	static float ATAN_DEGREE(float value) { return invoke<float>(0x69BE2817, value); } // 0x69BE2817
	static float ATAN2_DEGREE(float x, float y) { return invoke<float>(0x8A0D25F2, x, y); } // 0x8A0D25F2
	static float _GET_VECTOR_HEADING_DEGS(Vector3* vec) { return invoke<float>(0x9C40E671, vec); } // 0x9C40E671
	static float _GET_VECTOR_HEADING_RADS(float* p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8) { return invoke<float>(0xADF7D54B, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xADF7D54B
	static int GET_ANGLE_BETWEEN_VECTORS_DEGS(Any p0, Any p1) { return invoke<int>(0x3DD1DC3F, p0, p1); } // 0x3DD1DC3F
	static void VECTOR_FROM_HEADING_DEGS(Any p0, Any p1) { invoke<void>(0x44986367, p0, p1); } // 0x44986367
	static int _TRANSFORM_WORLD_TO_SCREEN(Vector3* position, float* screenX, float* screenY) { return invoke<int>(0xBB3CDF72, position, screenX, screenY); } // 0xBB3CDF72
	static float GET_CURRENT_GAME_TIME() { return invoke<float>(0x5842B9D1); } // 0x5842B9D1
	static float GET_CURRENT_UNWARPED_TIME() { return invoke<float>(0xF83666A6); } // 0xF83666A6
	static Any GET_SYSTEM_TIME() { return invoke<Any>(0x17CEE67A); } // 0x17CEE67A
	static int GET_TIMESTAMP() { return invoke<int>(0xD66B6C8E); } // 0xD66B6C8E
	static void GET_UTC_TIME(int* year, int* month, int* day, int* hour, int* minute, int* second) { invoke<void>(0xC589CD7D, year, month, day, hour, minute, second); } // 0xC589CD7D
	static float GET_UNWARPED_REALTIME_SECONDS() { return invoke<float>(0x49F96787); } // 0x49F96787
	static float GET_PROFILE_TIME() { return invoke<float>(0x6E189771); } // 0x6E189771
	static float GET_LAST_FRAME_TIME() { return invoke<float>(0x59466B4D); } // 0x59466B4D
	static void LOG_MESSAGE(const char* message) { invoke<void>(0x676167C3, message); } // 0x676167C3
	static void LOG_WARNING(const char* warning_message) { invoke<void>(0xFD25473E, warning_message); } // 0xFD25473E
	static void LOG_ERROR(const char* error_message) { invoke<void>(0x906C42FD, error_message); } // 0x906C42FD
	static int GET_TARGET_ACTOR() { return invoke<int>(0x0EF7427B); } // 0x0EF7427B
	static void GRINGO_SET_TARGET_OBJECT(Any p0, Any p1, Any p2) { invoke<void>(0x00776356, p0, p1, p2); } // 0x00776356
	static int GET_TARGET_OBJECT() { return invoke<int>(0x533AD3F2); } // 0x533AD3F2
	static BOOL IS_GRINGO_VALID(Any p0) { return invoke<BOOL>(0x7C858A47, p0); } // 0x7C858A47
	static Any GET_GRINGO_ACTIVATION_SPHERE(Any p0) { return invoke<Any>(0xADA2EA30, p0); } // 0xADA2EA30
	static void DISABLE_GRINGO_STREAMING_CHECKS() { invoke<void>(0xFD0AA999); } // 0xFD0AA999
	static void ENABLE_GRINGO_STREAMING_CHECKS() { invoke<void>(0x71BE51F4); } // 0x71BE51F4
	static void GRINGO_ALLOW_ACTIVATION(Any p0, Any p1) { invoke<void>(0x5E586923, p0, p1); } // 0x5E586923
	static int GRINGO_IS_ACTIVATION_ALLOWED(Any p0) { return invoke<int>(0x52261CE0, p0); } // 0x52261CE0
	static BOOL IS_DEBUGKEY_DOWN(Any p0) { return invoke<BOOL>(0x358F874F, p0); } // 0x358F874F
	static BOOL IS_DEBUGKEY_PRESSED(Any p0) { return invoke<BOOL>(0xCBC97619, p0); } // 0xCBC97619
	// controllerButton: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eControllerButton
	static BOOL IS_BUTTON_DOWN(int controller, int controllerButton, Any p2, Any p3) { return invoke<BOOL>(0xC3297B50, controller, controllerButton, p2, p3); } // 0xC3297B50
	// controllerButton: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eControllerButton
	static BOOL IS_BUTTON_PRESSED(int controller, int controllerButton, Any p2, Any p3) { return invoke<BOOL>(0x7BCB3F15, controller, controllerButton, p2, p3); } // 0x7BCB3F15
	// controllerButton: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eControllerButton
	static BOOL IS_BUTTON_RELEASED(int controller, int controllerButton, Any p2, Any p3) { return invoke<BOOL>(0xB04EB731, controller, controllerButton, p2, p3); } // 0xB04EB731
	static float GET_ANALOG_BUTTON_VALUE(Any p0, Any p1, Any p2) { return invoke<float>(0x23C9C74A, p0, p1, p2); } // 0x23C9C74A
	// PC only, inputString: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/InputStrings
	static BOOL IS_DIGITAL_ACTION_DOWN(const char* inputString, Any p1, Any p2) { return invoke<BOOL>(0x062C5047, inputString, p1, p2); } // 0x062C5047
	// PC only, inputString: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/InputStrings
	static BOOL IS_DIGITAL_ACTION_PRESSED(const char* inputString, Any p1, Any p2) { return invoke<BOOL>(0xDA674AE0, inputString, p1, p2); } // 0xDA674AE0
	// PC only, inputString: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/InputStrings
	static BOOL IS_DIGITAL_ACTION_RELEASED(const char* inputString, Any p1, Any p2) { return invoke<BOOL>(0x973F30EE, inputString, p1, p2); } // 0x973F30EE
	// PC only, inputString: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/InputStrings
	static float GET_ANALOGUE_ACTION(const char* inputString, Any p1) { return invoke<float>(0xC1F9AC6B, inputString, p1); } // 0xC1F9AC6B
	// PC only
	static Any _0x4586516D(Any p0) { return invoke<Any>(0x4586516D, p0); } // 0x4586516D
	// PC only
	static Any _0x7E452200(Any p0) { return invoke<Any>(0x7E452200, p0); } // 0x7E452200
	static float GET_STICK_X(int controller, BOOL isRightStick, Any p2) { return invoke<float>(0x9AAF7E28, controller, isRightStick, p2); } // 0x9AAF7E28
	static float GET_STICK_Y(int controller, BOOL isRightStick, Any p2) { return invoke<float>(0x7C6D41A4, controller, isRightStick, p2); } // 0x7C6D41A4
	static void RESET_TIME_SINCE_LAST_INPUT(Any p0) { invoke<void>(0x52B2F3F0, p0); } // 0x52B2F3F0
	static int GET_TIME_SINCE_LAST_INPUT(Any p0) { return invoke<int>(0xD4DEBC08, p0); } // 0xD4DEBC08
	static int GET_TIME_SINCE_LAST_MOVESTICK_INPUT(Any p0) { return invoke<int>(0xBEC2871A, p0); } // 0xBEC2871A
	static int GET_TIME_SINCE_LAST_BUTTON_INPUT(Any p0) { return invoke<int>(0xEF4F4F20, p0); } // 0xEF4F4F20
	// PC only
	static BOOL IS_RIGHT_MOUSE_DOWN() { return invoke<BOOL>(0x5598C970); } // 0x5598C970
	// PC only
	static BOOL IS_RIGHT_MOUSE_PRESSED() { return invoke<BOOL>(0xDC4B85A8); } // 0xDC4B85A8
	// PC only
	static BOOL IS_RIGHT_MOUSE_RELEASED() { return invoke<BOOL>(0xB59B352A); } // 0xB59B352A
	// PC only
	static BOOL IS_LEFT_MOUSE_DOWN() { return invoke<BOOL>(0x5AC5CE22); } // 0x5AC5CE22
	// PC only
	static BOOL IS_LEFT_MOUSE_PRESSED() { return invoke<BOOL>(0x7D4535A1); } // 0x7D4535A1
	// PC only
	static float GET_MOUSE_AXIS_X() { return invoke<float>(0x55ADBA8B); } // 0x55ADBA8B
	// PC only
	static float GET_MOUSE_AXIS_Y() { return invoke<float>(0x455A19E4); } // 0x455A19E4
	// PC only
	static float GET_MOUSE_DX() { return invoke<float>(0x88F07597); } // 0x88F07597
	// PC only
	static float GET_MOUSE_DY() { return invoke<float>(0x3A62D87D); } // 0x3A62D87D
	// PC only
	static float GET_MOUSE_SENSITIVITY() { return invoke<float>(0x5FE80264); } // 0x5FE80264
	static int DEBUG_DRAW_VECTOR(Any p0, Any p1) { return invoke<int>(0xF7974EBA, p0, p1); } // 0xF7974EBA
	static void DEBUG_DRAW_LINE(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x7C55C775, p0, p1, p2, p3); } // 0x7C55C775
	static int DEBUG_DRAW_SPHERE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0x4A1BAD30, p0, p1, p2, p3, p4, p5, p6); } // 0x4A1BAD30
	static void DEBUG_DRAW_STRING() { invoke<void>(0x993E45D8); } // 0x993E45D8
	// Name could be false positive
	static void DRAW_STRING_CURRENT_FONT(float x, float y, const char* text, float r, float g, float b, float a) { invoke<void>(0x3C2D93C1, x, y, text, r, g, b, a); } // 0x3C2D93C1
	static void SET_DEBUG_FADE_STATE(Any p0) { invoke<void>(0x73BE57AF, p0); } // 0x73BE57AF
	// No-op / nullsub
	static int _0xD1D88EB8(Any p0) { return invoke<int>(0xD1D88EB8, p0); } // 0xD1D88EB8
	// No-op / nullsub
	static int _0x21E19CD5(Any p0) { return invoke<int>(0x21E19CD5, p0); } // 0x21E19CD5
	// No-op / nullsub
	static int _0x1B6FE39B(Any p0) { return invoke<int>(0x1B6FE39B, p0); } // 0x1B6FE39B
	// No-op / nullsub
	static int _0xAAEBAC28(Any p0) { return invoke<int>(0xAAEBAC28, p0); } // 0xAAEBAC28
	// Returns -1
	static int SCRIPT_GETTESTREGION() { return invoke<int>(0x913A5CB6); } // 0x913A5CB6
	// Returns -1
	static int SCRIPT_GETTESTMISSION() { return invoke<int>(0xD34F7B3A); } // 0xD34F7B3A
	// Returns uint64 0
	static int SCRIPT_GETTESTSCRIPT() { return invoke<int>(0x191658C0); } // 0x191658C0
	// Returns uint64 0
	static int SCRIPT_GETTESTSCRIPTCONTINUEMARK() { return invoke<int>(0x95132289); } // 0x95132289
	// No-op / nullsub
	static void SCRIPT_SETTESTSCRIPTCONTINUEMARK(Any p0) { invoke<void>(0xEB8325B3, p0); } // 0xEB8325B3
	// Returns 0
	static int SCRIPT_WANTAUTOMATION() { return invoke<int>(0xD3FE15FB); } // 0xD3FE15FB
	// Returns uint64 0
	static int SCRIPT_GETTESTTYPE() { return invoke<int>(0x32D1DEB0); } // 0x32D1DEB0
	static void RETRIEVE_GAME_STATE(Any p0, Any p1, Any p2) { invoke<void>(0x48FBB83D, p0, p1, p2); } // 0x48FBB83D
	static void STORE_GAME_STATE(Any p0, Any p1, Any p2) { invoke<void>(0x800D6D89, p0, p1, p2); } // 0x800D6D89
	static void RESET_STORED_DATA() { invoke<void>(0xE1124E00); } // 0xE1124E00
	static void RESET_GAME() { invoke<void>(0x07045C4E); } // 0x07045C4E
	static int IS_GAME_RESETTING() { return invoke<int>(0x3B1B6407); } // 0x3B1B6407
	static int GET_CMD_LINE_PARAM(int* p0, Any p1, Any p2, Any p3) { return invoke<int>(0xC7612A79, p0, p1, p2, p3); } // 0xC7612A79
	static const char* GET_DISTRICTS_NAME() { return invoke<const char*>(0x0B2D5E4B); } // 0x0B2D5E4B
	static Any LOAD_GAME(Any p0) { return invoke<Any>(0x7C5901EF, p0); } // 0x7C5901EF
	static Any LOAD_SOFT_SAVE(Any p0) { return invoke<Any>(0x0234F932, p0); } // 0x0234F932
	static Any SAVE_GAME(Any p0) { return invoke<Any>(0x09C5D8D5, p0); } // 0x09C5D8D5
	static void SAVE_SOFT_SAVE(Any p0) { invoke<void>(0x1A3BAC68, p0); } // 0x1A3BAC68
	static void SAVE_MANAGER_HARD_SAVE(Any p0) { invoke<void>(0xED40F27D, p0); } // 0xED40F27D
	static int SAVE_MANAGER_HARD_LOAD() { return invoke<int>(0x8C710D3E); } // 0x8C710D3E
	static int SAVE_MANAGER_CREATE_SAVE_DISPLAY_NAME(int p0) { return invoke<int>(0x17F34613, p0); } // 0x17F34613
	static int SAVE_MANAGER_REGISTER_DATA(int p0, int p1, int p2, int p3, int p4) { return invoke<int>(0x20CE8AA8, p0, p1, p2, p3, p4); } // 0x20CE8AA8
	static int SAVE_MANAGER_SET_SAVE_VERSION(int p0) { return invoke<int>(0x8E867DDD, p0); } // 0x8E867DDD
	static int SAVE_MANAGER_SET_SAVE_VERSION_FOR_TYPE(int p0, int p1) { return invoke<int>(0x6E79F939, p0, p1); } // 0x6E79F939
	static int SAVE_MANAGER_CREATE_SAVE_FILE(int p0, int p1, int p2) { return invoke<int>(0x3E647734, p0, p1, p2); } // 0x3E647734
	static int SAVE_MANAGER_REGISTER_STATS(int p0, int p1, int p2, int p3, int p4) { return invoke<int>(0xE8637D2B, p0, p1, p2, p3, p4); } // 0xE8637D2B
	static int SAVE_MANAGER_REGISTER_PROFILE_STATS(int p0, int p1) { return invoke<int>(0x6D59A25F, p0, p1); } // 0x6D59A25F
	static int SAVE_MANAGER_IS_SAVING_DISABLED() { return invoke<int>(0x1D177160); } // 0x1D177160
	static int SAVE_MANAGER_IS_SP_SAVING_DISABLED() { return invoke<int>(0x1ADA1769); } // 0x1ADA1769
	// PC only
	static Any GET_EXTRAS_FILE_NAME(Any p0) { return invoke<Any>(0x580D21D9, p0); } // 0x580D21D9
	static BOOL DOES_FILE_EXIST(Any p0) { return invoke<BOOL>(0xAABE1330, p0); } // 0xAABE1330
	static void WRITE_TO_FILE() { invoke<void>(0xD44F7102); } // 0xD44F7102
	static BOOL IS_DEV_BUILD() { return invoke<BOOL>(0x6D9AA768); } // 0x6D9AA768
	static BOOL IS_PS3() { return invoke<BOOL>(0xA369B36F); } // 0xA369B36F
	// PS4/Switch/PC only
	static BOOL IS_PS4() { return invoke<BOOL>(0x99989FCD); } // 0x99989FCD
	// PS4/Switch/PC only
	static BOOL IS_SWITCH() { return invoke<BOOL>(0x92E03425); } // 0x92E03425
	// PC only
	static Any IS_30FPS(Any p0) { return invoke<Any>(0xFC7766A0, p0); } // 0xFC7766A0
	// PC only
	static Any IS_PC(Any p0) { return invoke<Any>(0x16C54BC5, p0); } // 0x16C54BC5
	static BOOL _ARE_BUMPER_BUTTONS_SWAPPED() { return invoke<BOOL>(0xB427CB25); } // 0xB427CB25
	static int IS_DISK_CACHE_PRIMED() { return invoke<int>(0x4BA92498); } // 0x4BA92498
	// PC only
	static BOOL IS_USING_KEYBOARD_AND_MOUSE() { return invoke<BOOL>(0xFB46B5D6); } // 0xFB46B5D6
	// PC only
	static Any GET_LAST_MOUSE_MOVEMENT(Any p0) { return invoke<Any>(0xFDDB1BFA, p0); } // 0xFDDB1BFA
	static BOOL IS_PLAYER_SIGNED_IN(Player player) { return invoke<BOOL>(0xC3C0F1F2, player); } // 0xC3C0F1F2
	static int GET_LOCAL_PLAYER_NAME() { return invoke<int>(0xA183D927); } // 0xA183D927
	static int GET_NUM_WORLD_CAMERAS() { return invoke<int>(0x8BD88B43); } // 0x8BD88B43
	static int GET_WORLD_CAMERA_AT_INDEX(int p0, int p1, int p2) { return invoke<int>(0x1C7C0F86, p0, p1, p2); } // 0x1C7C0F86
	static int GET_CLOSEST_WORLD_CAMERA(int p0, int p1, int p2, int p3) { return invoke<int>(0x836F42DA, p0, p1, p2, p3); } // 0x836F42DA
	static void PAUSE_GAME(Any p0) { invoke<void>(0x6F32A4E2, p0); } // 0x6F32A4E2
	static void UNPAUSE_GAME() { invoke<void>(0x0BF2CD82); } // 0x0BF2CD82
	static BOOL IS_GAME_PAUSED() { return invoke<BOOL>(0x57246C02); } // 0x57246C02
	static int SET_SCRIPT_CUTSCENE_ACTIVE(Any p0) { return invoke<int>(0xF0DDF83D, p0); } // 0xF0DDF83D
	// PS4/Switch/PC only
	static Any SET_TREE_COST_MODIFIER(Any p0) { return invoke<Any>(0x81A7CDB6, p0); } // 0x81A7CDB6
	// PS4/Switch/PC only
	static Any SET_USES_QUAD_IK_FIX(Any p0) { return invoke<Any>(0x2A04518E, p0); } // 0x2A04518E
	// PS4/Switch/PC only
	static Any SET_VISIBILITY_FOV_CLAMP(Any p0) { return invoke<Any>(0x4FC61E5F, p0); } // 0x4FC61E5F
	static void SET_MISSION_INFO(Any p0, Any p1) { invoke<void>(0x3B417D4E, p0, p1); } // 0x3B417D4E
	static void CLEAR_MISSION_INFO() { invoke<void>(0x02092A6E); } // 0x02092A6E
	static int GET_COMMANDLINE_START_POS(float* p0, float* p1) { return invoke<int>(0x6CD7DCE1, p0, p1); } // 0x6CD7DCE1
	static void SET_START_POS(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x0CB93120, p0, p1, p2, p3, p4); } // 0x0CB93120
	static BOOL IS_STARTPOS_IN_COMMANDLINE() { return invoke<BOOL>(0x814D97E8); } // 0x814D97E8
	static BOOL _WAS_LAST_RESET_FOR_MULTIPLAYER() { return invoke<BOOL>(0x3B004817); } // 0x3B004817
	static void SCRIPT_DONE_LOADING() { invoke<void>(0x5401F0CA); } // 0x5401F0CA
	static int LAUNCH_NEW_SCRIPT(const char* scriptPath, Any p1) { return invoke<int>(0x85A30503, scriptPath, p1); } // 0x85A30503
	static int LAUNCH_NEW_SCRIPT_WITH_ARGS(Any* p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xA602F586, p0, p1, p2, p3, p4); } // 0xA602F586
	static BOOL IS_LAUNCH_RETAIL() { return invoke<BOOL>(0x7CE2C2E1); } // 0x7CE2C2E1
	static BOOL IS_SIMULATE_START_PRESS() { return invoke<BOOL>(0xD8E31D42); } // 0xD8E31D42
	static BOOL IS_SIMULATE_START_MULTIPLAYER() { return invoke<BOOL>(0x9A73C2CD); } // 0x9A73C2CD
	static BOOL IS_D11_CUTSCENE_HACK() { return invoke<BOOL>(0xD90DB78D); } // 0xD90DB78D
	static BOOL IS_DISPLAY_WIDESCREEN() { return invoke<BOOL>(0x554FC5E0); } // 0x554FC5E0
	static int GET_EXP_MODE_PROMPT_STATE() { return invoke<int>(0x6226328F); } // 0x6226328F
	static int SET_EXP_MODE_PROMPT_STATE(Any p0) { return invoke<int>(0x59F98CA9, p0); } // 0x59F98CA9
	static int GET_GAME_EDITION() { return invoke<int>(0xB5401D4A); } // 0xB5401D4A
}

namespace COVER
{
	static int FIND_NEAREST_COVER_LOCATION(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x50AE988A, p0, p1, p2, p3, p4); } // 0x50AE988A
	static int FIND_COVER_LOCATIONS_IN_VOLUME(Any p0, Any p1, Any p2, float p3, float p4, Any p5, Any p6, Any p7) { return invoke<int>(0x9265B24B, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x9265B24B
	static int GET_COVER_LOCATION_BASE_POSITION(Any p0, Any p1) { return invoke<int>(0x8DFF31DF, p0, p1); } // 0x8DFF31DF
	static float GET_COVER_LOCATION_DIRECTION(Any p0) { return invoke<float>(0x620178B3, p0); } // 0x620178B3
	static int GET_COVER_LOCATION_POSITION(Any p0, Any p1) { return invoke<int>(0xA7F84C2F, p0, p1); } // 0xA7F84C2F
	static int IS_COVER_LOCATION_VALID(Any p0) { return invoke<int>(0x90AD2C2D, p0); } // 0x90AD2C2D
	static int ADD_AI_COVERSET_FOR_PROPSET(Any p0) { return invoke<int>(0x6BA6BC9B, p0); } // 0x6BA6BC9B
}

namespace CURVES
{
	static int ENABLE_CURVE(Any p0, Any p1) { return invoke<int>(0x0C46DAB3, p0, p1); } // 0x0C46DAB3
	static int ARE_CURVES_IN_RANGE(Any p0, float p1, float p2, float p3, float p4) { return invoke<int>(0xA5FF6076, p0, p1, p2, p3, p4); } // 0xA5FF6076
	static int START_CURVE_QUERY(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x0E018669, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x0E018669
	static int GET_CURVE_BY_NAME(Any p0, Any p1) { return invoke<int>(0x8C37CA1A, p0, p1); } // 0x8C37CA1A
	static int IS_CURVE_QUERY_VALID(Any p0) { return invoke<int>(0x9398BE8F, p0); } // 0x9398BE8F
	static int GET_NUM_POINTS_IN_CURVE_QUERY(Any p0) { return invoke<int>(0x8E551A7C, p0); } // 0x8E551A7C
	static int GET_NUM_CURVES_IN_CURVE_QUERY(Any p0) { return invoke<int>(0xBADCF1E9, p0); } // 0xBADCF1E9
	static int GET_POINT_FROM_CURVE_QUERY(Any p0, Any p1, Any p2) { return invoke<int>(0xE531DCAE, p0, p1, p2); } // 0xE531DCAE
	static int GET_CURVE_FROM_CURVE_INDEX_IN_CURVE_QUERY(Any p0, Any p1) { return invoke<int>(0xB4D1D8A3, p0, p1); } // 0xB4D1D8A3
	static int GET_CURVE_FROM_POINT_INDEX_IN_CURVE_QUERY(Any p0, Any p1) { return invoke<int>(0xBD4E48A6, p0, p1); } // 0xBD4E48A6
	static int GET_CLOSEST_POINT_TO_CURVE_CURVE_QUERY(Any p0, Any p1, Any p2) { return invoke<int>(0x90B514B9, p0, p1, p2); } // 0x90B514B9
	static int REMOVE_CURVE_FROM_CURVE_QUERY_USING_CURVE(Any p0, Any p1) { return invoke<int>(0x4F8FAF8F, p0, p1); } // 0x4F8FAF8F
	static void _TRAVEL_DISTANCE_ON_CURVE_FROM_CURVE_POINT(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x04D89A35, p0, p1, p2, p3, p4); } // 0x04D89A35
	static void _TRAVEL_DISTANCE_ON_CURVE_FROM_CURVE_POINT_2(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x19D652F9, p0, p1, p2, p3); } // 0x19D652F9
	static int CURVE_CALCULATE_DISTANCE_BY_STEP_SIZE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x39DA0B3A, p0, p1, p2, p3); } // 0x39DA0B3A
	static int CURVE_CALCULATE_DISTANCE_BY_FORCED_COMPONENT_SUBDIVISION_BOUNDS(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x49D2C1DA, p0, p1, p2, p3); } // 0x49D2C1DA
	static void RELEASE_CURVE(Any p0) { invoke<void>(0x8270CE81, p0); } // 0x8270CE81
	static int GET_CURVE_TYPE(Any p0) { return invoke<int>(0xE1007398, p0); } // 0xE1007398
	static Any GET_CURVE_NAME(Any p0) { return invoke<Any>(0x9A933060, p0); } // 0x9A933060
	static Any GET_CURVE_POINT(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x1CDF1EC4, p0, p1, p2, p3); } // 0x1CDF1EC4
	static void SET_CURVE_ACTIVE(Any p0, Any p1) { invoke<void>(0x74460602, p0, p1); } // 0x74460602
	static void SET_CURVE_WEIGHT(Any p0, Any p1) { invoke<void>(0xA7BB9E5E, p0, p1); } // 0xA7BB9E5E
	static int CURVE_NETWORK_POINT_GET_DISTANT_POINT(Any p0, Any p1, Any p2) { return invoke<int>(0xF0441E47, p0, p1, p2); } // 0xF0441E47
}

namespace CUTSCENE
{
	static int CUTSCENE_MANAGER_DOES_CUTSCENE_EXIST(Any p0) { return invoke<int>(0xD89902F1, p0); } // 0xD89902F1
	static int CUTSCENE_MANAGER_LOAD_CUTFILE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x99D215B4, p0, p1, p2, p3); } // 0x99D215B4
	static int CUTSCENE_MANAGER_IS_CUTFILE_LOADED() { return invoke<int>(0xA6CFA220); } // 0xA6CFA220
	static const char* CUTSCENE_MANAGER_GET_LOADED_CUTFILE() { return invoke<const char*>(0x0FE90DCB); } // 0x0FE90DCB
	static int CUTSCENE_MANAGER_RESUME_LOADING() { return invoke<int>(0x7716B12B); } // 0x7716B12B
	static int CUTSCENE_MANAGER_LOAD_CUTSCENE(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xFD300D15, p0, p1, p2, p3, p4); } // 0xFD300D15
	static int CUTSCENE_MANAGER_IS_CUTSCENE_LOADED() { return invoke<int>(0xEDF1D0B4); } // 0xEDF1D0B4
	static int CUTSCENE_MANAGER_UNLOAD_CUTSCENE() { return invoke<int>(0xE7F781B8); } // 0xE7F781B8
	static int CUTSCENE_MANAGER_PLAY_CUTSCENE() { return invoke<int>(0x98A9AC9E); } // 0x98A9AC9E
	static int CUTSCENE_MANAGER_STOP_CUTSCENE(Any p0, Any p1) { return invoke<int>(0x9E6CAD1D, p0, p1); } // 0x9E6CAD1D
	static int CUTSCENE_MANAGER_IS_CUTSCENE_PLAYING() { return invoke<int>(0xA61FA36B); } // 0xA61FA36B
	static int CUTSCENE_MANAGER_IS_CUTSCENE_FINISHED() { return invoke<int>(0xDE339CE1); } // 0xDE339CE1
	static int CUTSCENE_MANAGER_SET_TRANSITION_FROM_GAMECAMERA(Any p0) { return invoke<int>(0x82F80FEA, p0); } // 0x82F80FEA
	static int CUTSCENE_MANAGER_SET_TRANSITION_TO_GAMECAMERA(Any p0) { return invoke<int>(0xCBE7BE6A, p0); } // 0xCBE7BE6A
	static int CUTSCENE_MANAGER_RESET_GAMECAMERA_ON_EXIT(Any p0, Any p1) { return invoke<int>(0x9E6A776F, p0, p1); } // 0x9E6A776F
	static int CUTSCENE_MANAGER_ORIENT_GAMECAMERA_ON_EXIT(float p0, float p1, float p2, float p3) { return invoke<int>(0x47FAE768, p0, p1, p2, p3); } // 0x47FAE768
	static int CUTSCENE_MANAGER_SKIP_UI_STACK_POP() { return invoke<int>(0x93F356F4); } // 0x93F356F4
	static int CUTSCENE_MANAGER_SET_SKIP_UI_STACK_POP(Any p0) { return invoke<int>(0xE808BFFB, p0); } // 0xE808BFFB
	static const char* CUTSCENE_MANAGER_SET_HIDE_NONCUTSCENE_ACTORS(const char* p0) { return invoke<const char*>(0xE0BE8235, p0); } // 0xE0BE8235
	static BOOL CUTSCENE_MANAGER_CAN_SET_POST_CUTSCENE_POSES() { return invoke<BOOL>(0x7653788C); } // 0x7653788C
	static void CUTSCENE_MANAGER_CLEAR_CAN_SET_POST_CUTSCENE_POSES() { invoke<void>(0x98D0F458); } // 0x98D0F458
	static float CUTSCENE_MANAGER_GET_CURRENT_TIME() { return invoke<float>(0xAC5043C5); } // 0xAC5043C5
	static int CUTSCENE_MANAGER_GET_CURRENT_FRAME() { return invoke<int>(0x7263860F); } // 0x7263860F
	static int CUTSCENE_MANAGER_GET_TOTAL_FRAMES() { return invoke<int>(0x2DB208A1); } // 0x2DB208A1
	static int CUTSCENE_MANAGER_ENUMERATE_CUTXML_NAMES() { return invoke<int>(0x1501F924); } // 0x1501F924
	static int CUTSCENE_MANAGER_GET_NUM_CUTXML_NAMES() { return invoke<int>(0xC677BF51); } // 0xC677BF51
	static int CUTSCENE_MANAGER_GET_CUTXML_NAME() { return invoke<int>(0xC2B5BDDF); } // 0xC2B5BDDF
	static int CUTSCENE_MANAGER_GET_NUM_CUTSCENE_ACTORS() { return invoke<int>(0xA5691922); } // 0xA5691922
	static int CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR_NAME(Any p0) { return invoke<int>(0xC6557710, p0); } // 0xC6557710
	static int CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR(Any p0, Any p1) { return invoke<int>(0xED0BA189, p0, p1); } // 0xED0BA189
	static int CUTSCENE_MANAGER_GET_CUTSCENE_ACTORENUM(Any p0) { return invoke<int>(0xEA8E6112, p0); } // 0xEA8E6112
	static int CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR_BY_INDEX_START_ORIENT(Any p0, Any p1, Any p2) { return invoke<int>(0xB2F2A7F2, p0, p1, p2); } // 0xB2F2A7F2
	static int CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR_BY_INDEX_END_ORIENT(Any p0, Any p1, Any p2) { return invoke<int>(0x9410D992, p0, p1, p2); } // 0x9410D992
	static int CUTSCENE_MANAGER_GET_NUM_CUTSCENE_PROPS() { return invoke<int>(0xD9E4A8DA); } // 0xD9E4A8DA
	static int CUTSCENE_MANAGER_GET_CUTSCENE_PROP_NAME(Any p0) { return invoke<int>(0xEBAB5F62, p0); } // 0xEBAB5F62
	static int CUTSCENE_MANAGER_GET_CUTSCENE_PROP(Any p0) { return invoke<int>(0x5DB05BBC, p0); } // 0x5DB05BBC
	static int CUTSCENE_MANAGER_GET_CUTSCENE_PROP_BY_NAME(Any* p0, Any p1) { return invoke<int>(0x3BDB2ADF, p0, p1); } // 0x3BDB2ADF
	static int CUTSCENE_MANAGER_GET_CUTSCENE_PROP_BY_INDEX_START_ORIENT(Any p0, Any p1, Any p2) { return invoke<int>(0x79C748BE, p0, p1, p2); } // 0x79C748BE
	static int CUTSCENE_MANAGER_GET_CUTSCENE_PROP_BY_INDEX_END_ORIENT(Any p0, Any p1, Any p2) { return invoke<int>(0xA56DCCF2, p0, p1, p2); } // 0xA56DCCF2
	static BOOL CUTSCENE_MANAGER_HIDE_ACTOR(Any p0) { return invoke<BOOL>(0x3D014AB1, p0); } // 0x3D014AB1
	static int CUTSCENE_MANAGER_SHOW_ACTOR(Any p0) { return invoke<int>(0xB550D120, p0); } // 0xB550D120
	static int CUTSCENE_MANAGER_GET_INITIAL_STREAMING_LOAD_SCENE_EXT(Any p0, Any p1) { return invoke<int>(0xD79C7D6A, p0, p1); } // 0xD79C7D6A
	static int CUTSCENE_MANAGER_GET_FINAL_STREAMING_LOAD_SCENE_EXT(Any p0, Any p1) { return invoke<int>(0x5C553565, p0, p1); } // 0x5C553565
	static void CUTSCENE_MANAGER_SET_FINAL_STREAMING_LOAD_SCENE_EXT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0xB0479CB8, p0, p1, p2, p3, p4, p5); } // 0xB0479CB8
	static int CUTSCENE_MANAGER_SET_ASSET_OVERRIDE(Any p0, Any p1) { return invoke<int>(0x35DBDD67, p0, p1); } // 0x35DBDD67
	static int CUTSCENE_MANAGER_SET_ASSET_OVERRIDE_ACTORENUM(Any p0, Any p1) { return invoke<int>(0x250232CF, p0, p1); } // 0x250232CF
	static void CUTSCENE_MANAGER_SET_ASSET_OVERRIDE_ACTOR(Any p0, Any p1) { invoke<void>(0x7007019D, p0, p1); } // 0x7007019D
	static int CUTSCENE_MANAGER_GET_SCRIPT_EVENT_DATA() { return invoke<int>(0x24F97294); } // 0x24F97294
	static const char* CUTSCENE_MANAGER_GET_SCRIPT_EVENT_DESCRIPTION() { return invoke<const char*>(0xDE79FA4E); } // 0xDE79FA4E
	static void CUTSCENE_MANAGER_CLEAR_SCRIPT_EVENT() { invoke<void>(0x2B45FADE); } // 0x2B45FADE
	static void CUTSCENE_MANAGER_SET_WAS_JOHN_NOW_JACK_IN_RCM_CUTSCENE(Any p0) { invoke<void>(0x50A2051C, p0); } // 0x50A2051C
}

namespace DECORATOR
{
	static int DECOR_GET_BOOL_VERBOSE(Any p0, Any p1, Any p2) { return invoke<int>(0x9AC89564, p0, p1, p2); } // 0x9AC89564
	static int DECOR_GET_FLOAT_VERBOSE(Any p0, Any p1, Any p2) { return invoke<int>(0xFAC315B7, p0, p1, p2); } // 0xFAC315B7
	static int DECOR_GET_INT_VERBOSE(Any p0, Any p1, Any p2) { return invoke<int>(0x1F003E6C, p0, p1, p2); } // 0x1F003E6C
	static int DECOR_SET_BOOL(Actor actor, const char* propertyName, BOOL value) { return invoke<int>(0x8E101F5C, actor, propertyName, value); } // 0x8E101F5C
	static int DECOR_SET_FLOAT(Actor actor, const char* propertyName, float value) { return invoke<int>(0xBC7BD5CB, actor, propertyName, value); } // 0xBC7BD5CB
	static int DECOR_SET_INT(Actor actor, const char* propertyName, int value) { return invoke<int>(0xDB718B21, actor, propertyName, value); } // 0xDB718B21
	static int DECOR_SET_VECTOR(Actor actor, const char* propertyName, Any p2) { return invoke<int>(0xAAED0B69, actor, propertyName, p2); } // 0xAAED0B69
	static int DECOR_SET_STRING(Actor actor, const char* propertyName, const char* string) { return invoke<int>(0x53D3FB4A, actor, propertyName, string); } // 0x53D3FB4A
	static int DECOR_SET_OBJECT(Actor actor, const char* propertyName, Object object) { return invoke<int>(0x44F8BCC5, actor, propertyName, object); } // 0x44F8BCC5
	static int DECOR_CHECK_STRING(Actor actor, const char* propertyName, const char* eventName) { return invoke<int>(0xEDF99C77, actor, propertyName, eventName); } // 0xEDF99C77
	static int DECOR_GET_STRING_HASH(Any p0, Any p1) { return invoke<int>(0x6A0FE2A0, p0, p1); } // 0x6A0FE2A0
	static int DECOR_GET_BOOL(Any p0, Any p1) { return invoke<int>(0xDBCE51E0, p0, p1); } // 0xDBCE51E0
	static int DECOR_GET_FLOAT(Any p0, Any p1) { return invoke<int>(0x8DE5382F, p0, p1); } // 0x8DE5382F
	static int DECOR_GET_INT(Any p0, Any p1) { return invoke<int>(0xDDDE59B5, p0, p1); } // 0xDDDE59B5
	static int DECOR_GET_VECTOR(Any p0, Any p1, Any p2) { return invoke<int>(0x56E84C59, p0, p1, p2); } // 0x56E84C59
	static int DECOR_GET_OBJECT(Any p0, Any p1) { return invoke<int>(0x24F2E859, p0, p1); } // 0x24F2E859
	static int DECOR_CHECK_EXIST(Actor actor, const char* propertyName) { return invoke<int>(0xA0773F5C, actor, propertyName); } // 0xA0773F5C
	static int DECOR_REMOVE(Actor actor, const char* propertyName) { return invoke<int>(0xE0E2640B, actor, propertyName); } // 0xE0E2640B
	static int DECOR_REMOVE_ALL(Any p0) { return invoke<int>(0xFDB9E349, p0); } // 0xFDB9E349
}

namespace DLC
{
	static const char* DLC_PRE_INIT_CONTENT() { return invoke<const char*>(0x0728B211); } // 0x0728B211
	static int DLC_INIT_CONTENT() { return invoke<int>(0xEC86DB0E); } // 0xEC86DB0E
	static int DLC_PREINITIALIZE_FRAGMENT_STUBS(const char* p0) { return invoke<int>(0x57D9950B, p0); } // 0x57D9950B
	static int DLC_INIT_STRINGTABLE_STREAMABLES(Any p0, Any p1) { return invoke<int>(0xF4D0807E, p0, p1); } // 0xF4D0807E
	static BOOL DLC_IS_CONTENT_PURCHASED_FLAGS(Any p0) { return invoke<BOOL>(0x853F71F6, p0); } // 0x853F71F6
	// PS4/Switch/PC only
	static Any DLC_UNMOUNT_PACK(Any p0) { return invoke<Any>(0x2F78AEFA, p0); } // 0x2F78AEFA
}

namespace DOOR
{
	static Any FIND_NEAREST_DOOR(Any p0, Any p1) { return invoke<Any>(0x9CB5372B, p0, p1); } // 0x9CB5372B
	static int GET_DOOR_FROM_OBJECT(Any p0) { return invoke<int>(0x9CE0AA24, p0); } // 0x9CE0AA24
	static BOOL IS_DOOR_VALID(Any p0) { return invoke<BOOL>(0x7F0F079B, p0); } // 0x7F0F079B
	static BOOL IS_DOOR_LOCKED(Any p0) { return invoke<BOOL>(0x19FB9518, p0); } // 0x19FB9518
	static void SET_DOOR_LOCK(Any p0, Any p1) { invoke<void>(0x184924E2, p0, p1); } // 0x184924E2
	static BOOL IS_DOOR_CLOSED(Any p0) { return invoke<BOOL>(0x48659CD7, p0); } // 0x48659CD7
	static BOOL IS_DOOR_OPENED(Any p0) { return invoke<BOOL>(0x211DD9D2, p0); } // 0x211DD9D2
	static BOOL IS_DOOR_OPENING(Any p0) { return invoke<BOOL>(0x52BB0836, p0); } // 0x52BB0836
	static BOOL IS_DOOR_CLOSING(Any p0) { return invoke<BOOL>(0xCBA9F32C, p0); } // 0xCBA9F32C
	static void SET_DOOR_AUTO_CLOSE(Any p0, Any p1) { invoke<void>(0xD3300956, p0, p1); } // 0xD3300956
	static int SET_DOOR_CURRENT_SPEED(Any p0, Any p1, Any p2) { return invoke<int>(0x5BCFC899, p0, p1, p2); } // 0x5BCFC899
	static void OPEN_DOOR(Any p0, Any p1, Any p2) { invoke<void>(0x30503E81, p0, p1, p2); } // 0x30503E81
	static void OPEN_DOOR_DIRECTION(Any p0, Any p1) { invoke<void>(0xAACB4435, p0, p1); } // 0xAACB4435
	static void OPEN_DOOR_FAST(Any p0, Any p1) { invoke<void>(0xCF89BC95, p0, p1); } // 0xCF89BC95
	static void OPEN_DOOR_DIRECTION_FAST(Any p0, Any p1) { invoke<void>(0xBA51D02E, p0, p1); } // 0xBA51D02E
	static void CLOSE_DOOR(Any p0, Any p1) { invoke<void>(0x075B1736, p0, p1); } // 0x075B1736
	static void CLOSE_DOOR_FAST(Any p0) { invoke<void>(0xFEEC0767, p0); } // 0xFEEC0767
	static int SET_ALL_DOOR_LOCKS_VISIBLE(Any p0) { return invoke<int>(0x3B25299D, p0); } // 0x3B25299D
	static int SET_DOOR_LOCK_VISIBLE(Any p0) { return invoke<int>(0x468DDDB3, p0); } // 0x468DDDB3
	static BOOL IS_DOOR_OPEN_IN_DIRECTION(Any p0, Any p1) { return invoke<BOOL>(0xDAD47AE6, p0, p1); } // 0xDAD47AE6
}

namespace ENTITY
{
	static BOOL IS_ACTOR_VALID(Actor actor) { return invoke<BOOL>(0xBA6C3E92, actor); } // 0xBA6C3E92
	static int GET_ACTORENUM_FROM_STRING(const char* actorName) { return invoke<int>(0x8B217CAC, actorName); } // 0x8B217CAC
	static BOOL IS_ACTOR_ON_FOOT(Any p0) { return invoke<BOOL>(0x63D6551C, p0); } // 0x63D6551C
	static int GET_ACTOR_OFFSET_WORLD_COORDS(Any p0, Any p1, Any p2) { return invoke<int>(0xB7CE8FCC, p0, p1, p2); } // 0xB7CE8FCC
	static int TRANSFORM_ACTOR_TO_WORLD(Any p0, Any p1, Any p2) { return invoke<int>(0xB89CC342, p0, p1, p2); } // 0xB89CC342
	static int ACTORS_IN_RANGE(Any p0, Any p1, Any p2) { return invoke<int>(0x50A3BF5D, p0, p1, p2); } // 0x50A3BF5D
	static Any GET_ACTOR_VELOCITY(Actor actor, Vector3* velocity) { return invoke<Any>(0xAD6AF65C, actor, velocity); } // 0xAD6AF65C
	static float GET_ACTOR_HEIGHT(Actor actor) { return invoke<float>(0xE173CE48, actor); } // 0xE173CE48
	static void SET_GLOBAL_ACTOR_WEAPON_BIAS(float p0) { invoke<void>(0xAB8A1C15, p0); } // 0xAB8A1C15
	static const char* RESET_GLOBAL_ACTOR_WEAPON_BIAS() { return invoke<const char*>(0xDAD46FAB); } // 0xDAD46FAB
	static int LOCATE_ACTOR_OF_TYPE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xA2DEC153, p0, p1, p2, p3, p4, p5); } // 0xA2DEC153
	static BOOL IS_AREA_OBSTRUCTED(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<BOOL>(0x5F655C68, p0, p1, p2, p3, p4, p5); } // 0x5F655C68
	static BOOL IS_AREA_OBSTRUCTED2(float p0, float p1, float p2, float p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<BOOL>(0x0733E811, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x0733E811
	static int GET_ACTORENUM_SPECIES(Any p0) { return invoke<int>(0x6AC01FCB, p0); } // 0x6AC01FCB
	static int GET_ACTORENUM_ACTOR_BASE_TYPE(Any p0) { return invoke<int>(0xEE0AB3DD, p0); } // 0xEE0AB3DD
	static int GET_ACTORENUM_AVATAR_GROUP(Any p0) { return invoke<int>(0x6AFF3122, p0); } // 0x6AFF3122
	static int GET_ACTORENUM_MP_ANIM_SET_NAME(Any p0) { return invoke<int>(0x7D397CAA, p0); } // 0x7D397CAA
	static int GET_ACTORENUM_MP_VOICE_NAME(Any p0) { return invoke<int>(0x8DAC4359, p0); } // 0x8DAC4359
	static int SET_ACTOR_STAMINA(Any p0, float p1) { return invoke<int>(0xDE0B9673, p0, p1); } // 0xDE0B9673
	static int GET_ACTOR_GAIT_TYPE(Any p0) { return invoke<int>(0xAC232F6E, p0); } // 0xAC232F6E
	static Any GET_ACTOR_POSTURE(Any p0) { return invoke<Any>(0xDB993A4F, p0); } // 0xDB993A4F
	static void SET_ACTOR_POSTURE(Actor actor, Any p1) { invoke<void>(0x708D9BD3, actor, p1); } // 0x708D9BD3
	static int RESET_ACTOR_GAITS(Any p0, const char* p1) { return invoke<int>(0xDCC91F8C, p0, p1); } // 0xDCC91F8C
	static int GET_ACTOR_TYPE(Actor actor) { return invoke<int>(0xABFD3560, actor); } // 0xABFD3560
	static BOOL IS_ACTOR_MALE(Actor actor) { return invoke<BOOL>(0x2091F142, actor); } // 0x2091F142
	static void SET_ACTOR_SEX(Actor actor, Any p1) { invoke<void>(0x9C42B7A2, actor, p1); } // 0x9C42B7A2
	static void SET_ACTOR_IS_COMPANION(Actor actor, BOOL toggle) { invoke<void>(0x4C94EB9E, actor, toggle); } // 0x4C94EB9E
	static void SET_ACTOR_IS_THE_BEASTMASTER(Actor actor, BOOL toggle) { invoke<void>(0x8392855D, actor, toggle); } // 0x8392855D
	static void SET_ACTOR_TIME_OF_LAST_CRIME(Actor actor, Any p1) { invoke<void>(0xE9D86A7A, actor, p1); } // 0xE9D86A7A
	static int DESTROY_IMPAIRED_ACTORS() { return invoke<int>(0x2CB5D7AF); } // 0x2CB5D7AF
	static BOOL IS_PLAYER_WEAPON_ZOOMED(Actor actor) { return invoke<BOOL>(0x0A842786, actor); } // 0x0A842786
	static BOOL IS_ACTOR_ANIMAL(Actor actor) { return invoke<BOOL>(0x8E0769F3, actor); } // 0x8E0769F3
	static BOOL IS_ACTOR_CROUCHING(Actor actor) { return invoke<BOOL>(0xF6BF4242, actor); } // 0xF6BF4242
	static BOOL IS_ACTOR_FLYING(Actor actor) { return invoke<BOOL>(0x25670955, actor); } // 0x25670955
	static BOOL IS_ACTOR_HUMAN(Actor actor) { return invoke<BOOL>(0x882C84DC, actor); } // 0x882C84DC
	static BOOL IS_ACTOR_JUMPING(Actor actor) { return invoke<BOOL>(0xDFF96719, actor); } // 0xDFF96719
	static BOOL IS_ACTOR_SHOOTING(Actor actor) { return invoke<BOOL>(0x4B441DC4, actor); } // 0x4B441DC4
	static BOOL IS_ACTOR_BLINDFIRING(Actor actor) { return invoke<BOOL>(0x6396ABB7, actor); } // 0x6396ABB7
	static BOOL IS_ACTOR_RELOADING(Actor actor) { return invoke<BOOL>(0x39C518DB, actor); } // 0x39C518DB
	static BOOL IS_ACTOR_THROWING(Actor actor) { return invoke<BOOL>(0x886BD8AD, actor); } // 0x886BD8AD
	static BOOL IS_ACTOR_WHISTLING(Actor actor) { return invoke<BOOL>(0x3612AC73, actor); } // 0x3612AC73
	static BOOL IS_ACTOR_ON_LADDER(Actor actor) { return invoke<BOOL>(0xE975BE40, actor); } // 0xE975BE40
	static BOOL IS_ACTOR_OUTDOORS(Actor actor) { return invoke<BOOL>(0xE27EBCBD, actor); } // 0xE27EBCBD
	static void SUSPEND_MOVER(Any p0) { invoke<void>(0x017D270E, p0); } // 0x017D270E
	static void ENABLE_MOVER(Any p0) { invoke<void>(0xE29F0A39, p0); } // 0xE29F0A39
	static void SET_MOVER_FROZEN(Actor actor, BOOL frozen) { invoke<void>(0x13E6B5EE, actor, frozen); } // 0x13E6B5EE
	static BOOL IS_MOVER_FROZEN(Actor actor) { return invoke<BOOL>(0x9C12BD5A, actor); } // 0x9C12BD5A
	static int SET_ACTOR_USE_COARSE_BOUNDS(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x63925367, p0, p1, p2, p3); } // 0x63925367
	static int SUPRESS_MOVER_COLLISIONS(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x61664EC0, p0, p1, p2, p3); } // 0x61664EC0
	static BOOL IS_ACTOR_ON_GROUND(Actor actor) { return invoke<BOOL>(0x709EC06C, actor); } // 0x709EC06C
	static BOOL IS_ACTOR_ON_PATH(Actor actor, Any p1, Any p2, Any p3, Any p4) { return invoke<BOOL>(0x8ED9DAFC, actor, p1, p2, p3, p4); } // 0x8ED9DAFC
	static int IS_ACTOR_ON_VEHICLEPATH(Actor actor, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x4A2DE1D0, actor, p1, p2, p3, p4); } // 0x4A2DE1D0
	static BOOL IS_ACTOR_IN_WATER(Actor actor) { return invoke<BOOL>(0x7D65D9C7, actor); } // 0x7D65D9C7
	static BOOL IS_ACTOR_IN_WATER_OFDEPTH(Any p0, Any p1, Any p2, Any p3, float p5) { return invoke<BOOL>(0xA6AA7B9E, p0, p1, p2, p3, p5); } // 0xA6AA7B9E
	static int GET_ACTOR_STUCK_STATE(Any p0) { return invoke<int>(0x7B4F9EAC, p0); } // 0x7B4F9EAC
	static BOOL IS_ACTOR_IN_FIRE_VOLUME(Actor actor) { return invoke<BOOL>(0xE39E89BD, actor); } // 0xE39E89BD
	static BOOL IS_ACTOR_RIDEABLE(Actor actor) { return invoke<BOOL>(0x8842C62D, actor); } // 0x8842C62D
	static void SET_ACTOR_RIDEABLE(Actor actor, BOOL rideable) { invoke<void>(0x19F3CB6B, actor, rideable); } // 0x19F3CB6B
	static int GET_VEHICLE_BUMP_COUNT(Any p0) { return invoke<int>(0x04CF7C3E, p0); } // 0x04CF7C3E
	static void RESET_VEHICLE_BUMP_COUNT(Any p0) { invoke<void>(0x0E9BA223, p0); } // 0x0E9BA223
	static int SET_CUSTOM_ANIM_SPEED(Any p0) { return invoke<int>(0x5FEA3E61, p0); } // 0x5FEA3E61
	static Any ACTOR_RESET_ANIMS(Any p0, Any p1) { return invoke<Any>(0x35D8B4AA, p0, p1); } // 0x35D8B4AA
	static int _SCHEDULE_STOP_CUSTOM_UNFREEZE(Any p0) { return invoke<int>(0x817B6952, p0); } // 0x817B6952
	static int _SCHEDULE_STOP_CUSTOM_UNSUSPEND(Any p0) { return invoke<int>(0x4A1D2E25, p0); } // 0x4A1D2E25
	static int _SCHEDULE_STOP_REPLICATION(Any p0) { return invoke<int>(0xC17BAD12, p0); } // 0xC17BAD12
	static int SET_ACTOR_CAN_PLAY_BORED_IDLES(Any p0, Any p1) { return invoke<int>(0x0B5E1904, p0, p1); } // 0x0B5E1904
	static int SET_ACTOR_CAN_PLAY_GESTURES(Any p0, Any p1) { return invoke<int>(0x50ED77F1, p0, p1); } // 0x50ED77F1
	// variableMesh: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eVariableMesh
	static void ACTOR_ENABLE_VARIABLE_MESH(Actor actor, int variableMesh, BOOL enable) { invoke<void>(0xDA2F6203, actor, variableMesh, enable); } // 0xDA2F6203
	// variableMesh: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eVariableMesh
	static BOOL ACTOR_IS_VARIABLE_MESH_ENABLED(Actor actor, int variableMesh) { return invoke<BOOL>(0x5DE31288, actor, variableMesh); } // 0x5DE31288
	static void ACTOR_SET_GRABBED_BY_CUTSCENE(Any p0, Any p1) { invoke<void>(0x6D3E430D, p0, p1); } // 0x6D3E430D
	static int ACTOR_IS_GRABBED_BY_CUTSCENE(Actor actor) { return invoke<int>(0x776999DB, actor); } // 0x776999DB
	static BOOL ACTOR_IS_HIDDEN_BY_CUTSCENE(Any p0) { return invoke<BOOL>(0x488C95C4, p0); } // 0x488C95C4
	static BOOL IS_ACTOR_FULLY_FADED_EXT(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<BOOL>(0x0CC3D8F6, p0, p1, p2, p3, p4); } // 0x0CC3D8F6
	static int SET_ACTOR_HEARING_MAX_RANGE(Any p0, Any p1) { return invoke<int>(0x55AACDFD, p0, p1); } // 0x55AACDFD
	static float GET_ACTOR_VISION_FIELD_OF_VIEW(Any p0) { return invoke<float>(0x21CE712F, p0); } // 0x21CE712F
	static int SET_ACTOR_VISION_FIELD_OF_VIEW(Any p0, Any p1) { return invoke<int>(0xF8F3FE84, p0, p1); } // 0xF8F3FE84
	static int GET_ACTOR_VISION_MAX_RANGE(Any p0) { return invoke<int>(0x4A4B4B26, p0); } // 0x4A4B4B26
	static int SET_ACTOR_VISION_MAX_RANGE(Any p0, Any p1, Any p2) { return invoke<int>(0x4E3E9B70, p0, p1, p2); } // 0x4E3E9B70
	static int SET_UNIVERSAL_VISION_RANGE_MULTIPLIER(float p0) { return invoke<int>(0x5C8DD257, p0); } // 0x5C8DD257
	static int SET_ACTOR_VISION_XRAY(Any p0, Any p1) { return invoke<int>(0x8D5175A8, p0, p1); } // 0x8D5175A8
	static int GET_ACTOR_VISION_XRAY(Any p0) { return invoke<int>(0xBFABD82E, p0); } // 0xBFABD82E
	static int GET_ACTOR_CURRENT_WEAPON_AI_PARAMETERS(Any p0, Any p1) { return invoke<int>(0xAAC96EFF, p0, p1); } // 0xAAC96EFF
	static BOOL GET_ACTOR_ALLOW_BUMP_REACTIONS(Any p0) { return invoke<BOOL>(0x9CD3385E, p0); } // 0x9CD3385E
	static int SET_ACTOR_ALLOW_BUMP_REACTIONS(Actor actor, BOOL toggle) { return invoke<int>(0xC52B5F18, actor, toggle); } // 0xC52B5F18
	static int SET_ACTOR_ALLOW_NM_BUMP_REACTIONS(Any p0, Any p1) { return invoke<int>(0xEB7B0FAA, p0, p1); } // 0xEB7B0FAA
	static void SET_RCM_ACTOR_CALL_OVER_ENABLE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { invoke<void>(0x2C6A5FAC, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x2C6A5FAC
	static void SET_RCM_WAS_JOHN_NOW_JACK(Any p0, Any p1) { invoke<void>(0xE4AA7B35, p0, p1); } // 0xE4AA7B35
	static void SET_RCM_ACTOR_CALL_OVER_SUPPRESS(float p0) { invoke<void>(0xD15B53F8, p0); } // 0xD15B53F8
	static int SET_ACTOR_ALLOW_PLAYER_GREET_RESPONSES(Any p0) { return invoke<int>(0xC28A5950, p0); } // 0xC28A5950
	static void SET_ACTOR_ALLOW_WEAPON_REACTIONS(Actor actor, BOOL allowed) { invoke<void>(0x003D7C2F, actor, allowed); } // 0x003D7C2F
	static void SET_ACTOR_ALLOW_WEAPON_REACTION_FLEE(Actor actor, BOOL allowed) { invoke<void>(0xBAF9D599, actor, allowed); } // 0xBAF9D599
	static int GET_ACTOR_WEAPON_REACTION_ACTOR_TYPE(Actor p0) { return invoke<int>(0x78B7976E, p0); } // 0x78B7976E
	static void SET_ACTOR_WEAPON_REACTION_ACTOR_TYPE(Any p0, Any p1) { invoke<void>(0x18BA1216, p0, p1); } // 0x18BA1216
	static int SET_PLAYER_CAUSE_WEAPON_REACTIONS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { return invoke<int>(0x0634B4D1, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x0634B4D1
	static void SET_ACTOR_WEAPON_REACTION_NO_FLEE_HACK(Actor actor, BOOL toggle) { invoke<void>(0xD9934D6E, actor, toggle); } // 0xD9934D6E
	static int SET_ACTOR_OBSERVED_TARGETED_REACTIONS(Any p0, Any p1) { return invoke<int>(0x0A23F215, p0, p1); } // 0x0A23F215
	static void SET_PLAYER_CAUSE_WEAPON_REACTION_COMBAT(Any p0, Any p1) { invoke<void>(0xFFDA2D88, p0, p1); } // 0xFFDA2D88
	static int SET_ACTOR_REACT_TO_LASSO(Any p0, const char* p1) { return invoke<int>(0x7B7D1742, p0, p1); } // 0x7B7D1742
	static int SET_ACTOR_ALLOW_DISARM(Any p0, const char* p1) { return invoke<int>(0x76A72D9A, p0, p1); } // 0x76A72D9A
	static void SET_ANIMAL_CAN_ATTACK(Any p0, Any p1) { invoke<void>(0x2B403538, p0, p1); } // 0x2B403538
	static Any GET_CURRENT_GRINGO(Any p0) { return invoke<Any>(0x5D9DB7A5, p0); } // 0x5D9DB7A5
	static int SET_ACTOR_GRINGO_RESTRICTION(Any p0) { return invoke<int>(0x527CB774, p0); } // 0x527CB774
	static int CLEAR_ACTOR_GRINGO_RESTRICTION(Any p0) { return invoke<int>(0x660DBDDD, p0); } // 0x660DBDDD
	static void MAKE_ACTOR_READY_FOR_ACTION(Actor actor, BOOL isReady) { invoke<void>(0xF04335A6, actor, isReady); } // 0xF04335A6
	static BOOL IS_ACTOR_READY_FOR_ACTION(Actor actor) { return invoke<BOOL>(0xFB2B0CCF, actor); } // 0xFB2B0CCF
	static void REPORT_GRINGO_USE_PHASE(Any p0, Any p1) { invoke<void>(0xA41B161C, p0, p1); } // 0xA41B161C
	static int CLEAR_ALL_CORPSES() { return invoke<int>(0x9028B082); } // 0x9028B082
	static int CAN_PLAYER_DIE() { return invoke<int>(0x90F9555B); } // 0x90F9555B
	static void CLEAR_ACTOR_MAX_SPEED(Any p0) { invoke<void>(0xA9691E66, p0); } // 0xA9691E66
	static void SET_ACTOR_MAX_SPEED(Any p0, Any p1) { invoke<void>(0x9CB01B27, p0, p1); } // 0x9CB01B27
	static void SET_ACTOR_MAX_SPEED_ABSOLUTE(Any p0, Any p1) { invoke<void>(0x950B8870, p0, p1); } // 0x950B8870
	static void CLEAR_ACTOR_MIN_SPEED(Any p0) { invoke<void>(0x036D75D5, p0); } // 0x036D75D5
	static void SET_ACTOR_MIN_SPEED(Any p0, Any p1) { invoke<void>(0xA854EE99, p0, p1); } // 0xA854EE99
	static int SET_ACTOR_MIN_SPEED_ABSOLUTE(Any p0, float p1) { return invoke<int>(0x04D4A734, p0, p1); } // 0x04D4A734
	static int GET_ACTOR_MAX_SPEED(Any p0) { return invoke<int>(0x627E52EA, p0); } // 0x627E52EA
	static int GET_ACTOR_MAX_SPEED_ABSOLUTE(Any p0) { return invoke<int>(0x56DE7F21, p0); } // 0x56DE7F21
	static int GET_ACTOR_MIN_SPEED(Any p0) { return invoke<int>(0x8D0DCEB6, p0); } // 0x8D0DCEB6
	static void SET_ACTOR_SPEED(Any p0, Any p1) { invoke<void>(0x09D78931, p0, p1); } // 0x09D78931
	static void CLEAR_LAST_ATTACK(Any p0) { invoke<void>(0x68D4A021, p0); } // 0x68D4A021
	static int GET_LAST_ATTACK_TARGET(Any p0, Any p1) { return invoke<int>(0xEB40C2FC, p0, p1); } // 0xEB40C2FC
	static float GET_LAST_ATTACK_TIME(Any p0) { return invoke<float>(0x69FA5315, p0); } // 0x69FA5315
	static float GET_DAMAGE_BY_LOCAL_PLAYER(Any p0) { return invoke<float>(0x8C221B4D, p0); } // 0x8C221B4D
	static int GET_ACTOR_COMBAT_CLASS(Any p0) { return invoke<int>(0x0129B715, p0); } // 0x0129B715
	static int _DLC_SHOTGUN_SPREAD_OVERRIDE(Any p0, Any p1, float p2) { return invoke<int>(0x8062BD74, p0, p1, p2); } // 0x8062BD74
	static Any BEGIN_DUEL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12) { return invoke<Any>(0x44B7FF7E, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0x44B7FF7E
	static Any CANCEL_DUEL(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<Any>(0x4E86F0B5, p0, p1, p2, p3, p4); } // 0x4E86F0B5
	static int ADD_DUEL_HOSTAGE(Any p0, Any p1) { return invoke<int>(0x82A6B8FC, p0, p1); } // 0x82A6B8FC
	static int GET_CURRENT_DUEL_SCORE(Any p0) { return invoke<int>(0x33CE5435, p0); } // 0x33CE5435
	static int SET_DUEL_DIFFICULTY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x3E5C3C2D, p0, p1, p2, p3); } // 0x3E5C3C2D
	static BOOL GET_ACTOR_EXEMPT_FROM_AMBIENT_RESTRICTIONS(Actor actor) { return invoke<BOOL>(0x8007587C, actor); } // 0x8007587C
	static void SET_ACTOR_EXEMPT_FROM_AMBIENT_RESTRICTIONS(Actor actor, BOOL isExempt) { invoke<void>(0x4D0A87BF, actor, isExempt); } // 0x4D0A87BF
	static int ADD_CAPABILITY(Any p0) { return invoke<int>(0x6695E185, p0); } // 0x6695E185
	static int REMOVE_CAPABILITY(Any p0) { return invoke<int>(0x29AEB2DB, p0); } // 0x29AEB2DB
	static int HAS_CAPABILITY(Any p0) { return invoke<int>(0xD3D8E8ED, p0); } // 0xD3D8E8ED
	static float GET_LAST_ON_SCREEN_TIME_FOR_ACTOR(Any p0) { return invoke<float>(0x2B8C3258, p0); } // 0x2B8C3258
	static int NET_SET_NODE_REPLICATION(Any p0, Any p1, Any p2) { return invoke<int>(0xA4B5275C, p0, p1, p2); } // 0xA4B5275C
	static void SET_ACTOR_ACTION_SIGNAL(Any p0, Any p1, Any p2) { invoke<void>(0x382E7CCC, p0, p1, p2); } // 0x382E7CCC
	static void TOGGLE_ACTOR_ACTION_SIGNAL_ON(Any p0, Any p1, Any p2) { invoke<void>(0x415F9BC3, p0, p1, p2); } // 0x415F9BC3
	static void TOGGLE_ACTOR_ACTION_SIGNAL_OFF(Any p0) { invoke<void>(0x4F605632, p0); } // 0x4F605632
	static int GET_ACTOR_MELEE_TARGETED_BY(Any* p0, Any p1) { return invoke<int>(0x02365961, p0, p1); } // 0x02365961
	static int SET_ACTOR_CAN_DEADEYE_TAG_ANYTHING(Any p0, Any p1) { return invoke<int>(0xD079EB62, p0, p1); } // 0xD079EB62
	static void SET_ACTOR_AUTO_TRANSITION_TO_DRIVER_SEAT(Any p0, Any p1) { invoke<void>(0x47930AA4, p0, p1); } // 0x47930AA4
	static int SET_ACTOR_FLY_FX(Any p0, Any p1) { return invoke<int>(0xEDC806BA, p0, p1); } // 0xEDC806BA
	static void SET_ACTOR_MOVE_CONFLICT_HIGH_PRIORITY(Any p0, Any p1) { invoke<void>(0x7A746D3A, p0, p1); } // 0x7A746D3A
	static void SET_ACTOR_MOVE_CONFLICT_ALLOWED_TO_RUN_OVER_SMALL_ANIMALS(Any p0, Any p1) { invoke<void>(0x32CB0E86, p0, p1); } // 0x32CB0E86
	static void SET_ACTOR_IS_AMBIENT(Any p0, Any p1) { invoke<void>(0x4CB24141, p0, p1); } // 0x4CB24141
	static void SET_ACTOR_IS_SHOPKEEPER(Any p0, Any p1, Any p2) { invoke<void>(0x0880DBF5, p0, p1, p2); } // 0x0880DBF5
	static void SET_ACTOR_SHOULD_TAUNT(Any p0, Any p1) { invoke<void>(0x199600FA, p0, p1); } // 0x199600FA
	static void SET_ACTOR_CAN_BUMP(Any p0, Any p1) { invoke<void>(0xB9744BE7, p0, p1); } // 0xB9744BE7
	// maxValue between 0.0f - 100.0f
	static int SET_ACTOR_MAX_FRESHNESS(Actor actor, float maxValue) { return invoke<int>(0xBADB24FB, actor, maxValue); } // 0xBADB24FB
	static float GET_ACTOR_MAX_FRESHNESS(Actor actor) { return invoke<float>(0xF1D2A13E, actor); } // 0xF1D2A13E
	static void MAKE_BIRD_FLY_FROM_POINT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x5E54E254, p0, p1, p2, p3, p4, p5, p6); } // 0x5E54E254
}

namespace EVENT
{
	static BOOL IS_EVENT_VALID(Any p0) { return invoke<BOOL>(0x4911EB99, p0); } // 0x4911EB99
	static Object GET_EVENT_FROM_OBJECT(Object p0) { return invoke<Object>(0x184BD1BC, p0); } // 0x184BD1BC
	static Any GET_OBJECT_FROM_EVENT(int* p0, Any p1) { return invoke<Any>(0xB64DDA6F, p0, p1); } // 0xB64DDA6F
	static int COPY_EVENT(Any p0, Any p1) { return invoke<int>(0xF7DA8F09, p0, p1); } // 0xF7DA8F09
	static Layout GET_EVENT_LAYOUT() { return invoke<Layout>(0xD938B523); } // 0xD938B523
	static int GET_EVENT_TYPE(Any p0) { return invoke<int>(0x6D660453, p0); } // 0x6D660453
	static int GET_EVENT_TARGET_AS_OBJECT(Any p0) { return invoke<int>(0xE2ED95CC, p0); } // 0xE2ED95CC
	static int GET_EVENT_TARGET_AS_PHYSINST(Any p0) { return invoke<int>(0xBDD4D4D5, p0); } // 0xBDD4D4D5
	static int GET_EVENT_PERPETRATOR(Any p0) { return invoke<int>(0x0B5431C9, p0); } // 0x0B5431C9
	static int ADD_NEW_EVENT_RESPONSE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x17CF885F, p0, p1, p2, p3); } // 0x17CF885F
	static int ADD_NEW_RANGED_EVENT_RESPONSE(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x8DF144C2, p0, p1, p2, p3, p4); } // 0x8DF144C2
	static int REMOVE_EVENT_RESPONSE(Any p0, Any p1, Any p2) { return invoke<int>(0xFEE731AF, p0, p1, p2); } // 0xFEE731AF
	static void RANGED_EVENT_RESPONSE_INIT_COMPLETE() { invoke<void>(0x85D62384); } // 0x85D62384
	static void REGISTER_FOR_CREATION_EVENT(Any p0) { invoke<void>(0xFB227D11, p0); } // 0xFB227D11
	static int GET_EVENT_TIME(Any p0) { return invoke<int>(0x82112B85, p0); } // 0x82112B85
	static int GET_OBJECTSET_FOR_EVENT_TYPE(int setId) { return invoke<int>(0xBC58F1EA, setId); } // 0xBC58F1EA
	static int CREATE_EVENT_TRAP(Any p0, Any p1, Any p2) { return invoke<int>(0x24C18749, p0, p1, p2); } // 0x24C18749
	static void EVENT_TRAP_ON_VOLUME(Any p0, Any p1) { invoke<void>(0x88943B5B, p0, p1); } // 0x88943B5B
	static int EVENT_TRAP_ON_SPHERE(Any p0, float p1, float p2, float p3, float p4) { return invoke<int>(0x3D2786E5, p0, p1, p2, p3, p4); } // 0x3D2786E5
	static void EVENT_TRAP_ON_PERPETRATOR(Any p0, Any p1) { invoke<void>(0x6B5DF46D, p0, p1); } // 0x6B5DF46D
	static void EVENT_TRAP_ON_TARGET(Any p0, Any p1) { invoke<void>(0x0AA5D947, p0, p1); } // 0x0AA5D947
	static void EVENT_TRAP_ON_OWNER(Any p0, Any p1) { invoke<void>(0x1105FB64, p0, p1); } // 0x1105FB64
	static void EVENT_TRAP_STORE_EVENTS(Any p0, Any p1) { invoke<void>(0x08765C6B, p0, p1); } // 0x08765C6B
	static void EVENT_TRAP_CLEAR_EVENTS(Any p0) { invoke<void>(0xDE9AA6E5, p0); } // 0xDE9AA6E5
	static int EVENT_TRAP_SUCCESSFUL_TRAP(Any p0) { return invoke<int>(0x54F8EAA4, p0); } // 0x54F8EAA4
	static void EVENT_TRAP_CLEAR_TRAP_FLAG(Any p0) { invoke<void>(0xAA24E0CC, p0); } // 0xAA24E0CC
	static int GET_NUM_EVENT_RESPONSES() { return invoke<int>(0x19F62133); } // 0x19F62133
	static int GET_EVENT_RESPONSE_ID() { return invoke<int>(0xB573FF63); } // 0xB573FF63
	static int GET_EVENT_FOR_RESPONSE() { return invoke<int>(0x586714AE); } // 0x586714AE
}

namespace EXPLOSION
{
	// explosionName: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/ExplosionStrings
	static void _CREATE_EXPLOSION(Vector3* position, const char* explosionName, BOOL p2, Vector3* damage, BOOL p4) { invoke<void>(0xE7023D23, position, explosionName, p2, damage, p4); } // 0xE7023D23
	static const char* ENABLE_REPLICATION_SET_EXPLOSION(const char* p0) { return invoke<const char*>(0x651F6299, p0); } // 0x651F6299
}

namespace FACTION
{
	static void RELOAD_FACTIONS(const char* factionName) { invoke<void>(0x40ABFD17, factionName); } // 0x40ABFD17
	static void RESET_FACTIONS() { invoke<void>(0x28413943); } // 0x28413943
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eFaction
	static int GET_ACTOR_FACTION(Actor actor) { return invoke<int>(0x52E2A611, actor); } // 0x52E2A611
	// faction: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eFaction
	static void SET_ACTOR_FACTION(Actor actor, int faction) { invoke<void>(0xCC63951A, actor, faction); } // 0xCC63951A
	// faction: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eFaction
	static BOOL IS_FACTION_VALID(int faction) { return invoke<BOOL>(0x5E2F718D, faction); } // 0x5E2F718D
	static void VERIFY_FACTION_ENUM(const char* factionName, int faction) { invoke<void>(0x22424394, factionName, faction); } // 0x22424394
	static void SET_FACTION_IS_LAWFUL_TO_ATTACK(int faction, BOOL canAttack) { invoke<void>(0xDCB960C5, faction, canAttack); } // 0xDCB960C5
	static Any GET_FACTION_IS_LAWFUL_TO_ATTACK(Any p0) { return invoke<Any>(0xB58013D7, p0); } // 0xB58013D7
	static void SET_FACTIONS_STATUS_ONE_WAY(int factionAId, int factionBId, int relationshipStatus) { invoke<void>(0xD771AF0B, factionAId, factionBId, relationshipStatus); } // 0xD771AF0B
	static void SET_FACTIONS_STATUS_TWO_WAY(int factionAId, int factionBId, int relationshipStatus) { invoke<void>(0x4C28B11E, factionAId, factionBId, relationshipStatus); } // 0x4C28B11E
	static void SET_AMBIENT_FACTIONS_STATUS_TWO_WAY(int ambientFactionAId, int ambientFactionBId, int relationshipStatus) { invoke<void>(0x6118212B, ambientFactionAId, ambientFactionBId, relationshipStatus); } // 0x6118212B
	static void RESET_FACTIONS_STATUS_TWO_WAY(int factionAId, int factionBId) { invoke<void>(0x902781BF, factionAId, factionBId); } // 0x902781BF
	static void RESET_AMBIENT_FACTIONS_STATUS_TWO_WAY(int ambientFactionAId, int ambientFactionBId) { invoke<void>(0xF9C5DC76, ambientFactionAId, ambientFactionBId); } // 0xF9C5DC76
	static BOOL GET_FACTIONS_STATUS(int factionAId, int factionBId) { return invoke<BOOL>(0x8E56236D, factionAId, factionBId); } // 0x8E56236D
	static void SET_FACTION_TO_FACTION_ACCURACY_SCALE_FACTOR(int attackerFactionId, int targetFactionId, float accuracyFactor) { invoke<void>(0x463F75F8, attackerFactionId, targetFactionId, accuracyFactor); } // 0x463F75F8
	static void SET_FACTION_TO_FACTION_DAMAGE_SCALE_FACTOR(int attackerFactionId, int targetFactionId, float damageScaleFactor) { invoke<void>(0xA9A18E5A, attackerFactionId, targetFactionId, damageScaleFactor); } // 0xA9A18E5A
	static void CLEAR_FACTION_STATUS_TO_INDIVIDUAL_ACTOR(Any p0) { invoke<void>(0xEF639583, p0); } // 0xEF639583
	static int GET_FACTION_STATUS_TO_INDIVIDUAL_ACTOR(int faction, Actor actor) { return invoke<int>(0x784398CB, faction, actor); } // 0x784398CB
	static void SET_FACTION_STATUS_TO_INDIVIDUAL_ACTOR(int faction, Actor actor, int status) { invoke<void>(0xBC44D31D, faction, actor, status); } // 0xBC44D31D
}

namespace FX
{
	static void ENABLE_PIP(Any p0, Any p1, Any p2) { invoke<void>(0xA5A6A3E3, p0, p1, p2); } // 0xA5A6A3E3
	static int IS_PIP_ENABLED() { return invoke<int>(0x3736FF43); } // 0x3736FF43
	static int IS_PIP_RENDERING() { return invoke<int>(0x065B4197); } // 0x065B4197
	static void CLEAR_DECALS() { invoke<void>(0x43939FD8); } // 0x43939FD8
	static void CREATE_DECAL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x21588246, p0, p1, p2, p3, p4, p5, p6); } // 0x21588246
	static void CREATE_DIRECTION_DECAL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { invoke<void>(0xFB4CFBA0, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xFB4CFBA0
	static void CREATE_DECAL_WITH_NORMAL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { invoke<void>(0x7BCE4845, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x7BCE4845
	static int CREATE_FOOTPRINT(Any p0, Any p1, float p2, float p3, float p4, float p5, float p6, float p7) { return invoke<int>(0x9E54C297, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x9E54C297
	static void _SET_MELEE_MARKER_POS(Any p0, Any p1, Any p2) { invoke<void>(0x013A0D25, p0, p1, p2); } // 0x013A0D25
	static void _SET_MELEE_MARKER_SIZE(Any p0) { invoke<void>(0x1182C34F, p0); } // 0x1182C34F
	static void _SET_MELEE_MARKER_COLOR(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xD0FB6AF0, p0, p1, p2, p3); } // 0xD0FB6AF0
	static void _SET_MELEE_MARKER_STROBEINTENSITY(Any p0, float p1) { invoke<void>(0xC00F8181, p0, p1); } // 0xC00F8181
	static void _FX_ENABLE_SCRIPT_MELEE_MARKER(Any p0) { invoke<void>(0x4897DD37, p0); } // 0x4897DD37
	static void PPP_LOAD_PRESET(Any p0) { invoke<void>(0x6E946AF8, p0); } // 0x6E946AF8
	static void PPP_UNLOAD_PRESET(Any p0) { invoke<void>(0xB6CA7EBF, p0); } // 0xB6CA7EBF
	static void RESET_ANALOG_POSITIONS(Any p0, Any p1) { invoke<void>(0x4710FD93, p0, p1); } // 0x4710FD93
	static float PPP_GET_ELEMENT_MAGNITUDE(Any p0) { return invoke<float>(0x6A0A241A, p0); } // 0x6A0A241A
	static void CANCEL_DEADEYE() { invoke<void>(0xCB0BDCE9); } // 0xCB0BDCE9
	static void FIRE_SHOCK(Any p0) { invoke<void>(0xFA43DCC5, p0); } // 0xFA43DCC5
	static int SET_SHOCK_SPEED(float p0) { return invoke<int>(0xEC906A7A, p0); } // 0xEC906A7A
	static int SET_SHOCK_AMPLITUDE(float p0) { return invoke<int>(0xC9FCD3EC, p0); } // 0xC9FCD3EC
	static void DOF_PUSH() { invoke<void>(0xF665F9D1); } // 0xF665F9D1
	static void DOF_POP() { invoke<void>(0x5EBE0C41); } // 0x5EBE0C41
	static void DOF_SET(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xEA8964CC, p0, p1, p2, p3); } // 0xEA8964CC
	static void DOF_SET_KERNEL(Any p0) { invoke<void>(0x47A8DDED, p0); } // 0x47A8DDED
	static int ADD_GLOW_TO_OBJECT(Any p0, float p1, float p2, float p3) { return invoke<int>(0x3B32AB84, p0, p1, p2, p3); } // 0x3B32AB84
	static void REMOVE_GLOW_INDICATOR(Any p0) { invoke<void>(0xCBDD5832, p0); } // 0xCBDD5832
	static void CREATE_OBJECT_GLOW(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x1065D334, p0, p1, p2, p3, p4, p5); } // 0x1065D334
	static void DESTROY_OBJECT_GLOW(Any p0) { invoke<void>(0xFC261530, p0); } // 0xFC261530
	static void CLEAR_TUMBLEWEEDS() { invoke<void>(0x8852F896); } // 0x8852F896
	static void ALLOW_TUMBLEWEEDS(Any p0) { invoke<void>(0xFDE8DFCE, p0); } // 0xFDE8DFCE
	static int ADD_ZOMBIE_TO_ACTOR(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x1EE7153B, p0, p1, p2, p3); } // 0x1EE7153B
	static int ADD_BLOOD_TO_ACTOR(Any p0, float p1, float p2, float p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x5685A440, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x5685A440
	static int ADD_BLOOD_TO_CORPSE(Any p0, float p1, float p2, float p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x50904C66, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x50904C66
	static void CLEAR_CHARACTER_BLOOD() { invoke<void>(0x1A676EDF); } // 0x1A676EDF
	static void CLEAR_PLAYER_BLOOD() { invoke<void>(0x807C9D01); } // 0x807C9D01
	static void SET_PLAYER_BLOOD_FADE_RATE(Any p0) { invoke<void>(0x9D9E093E, p0); } // 0x9D9E093E
	static int PRICK_PLAYER_FINGER(Any p0) { return invoke<int>(0x32F2D6F1, p0); } // 0x32F2D6F1
	static void BURN_ACTOR(Any p0, Any p1, Any p2) { invoke<void>(0xA257C16D, p0, p1, p2); } // 0xA257C16D
	static int LIMIT_BLOOD_ON_ACTOR(Any p0, int a2) { return invoke<int>(0x3627F773, p0, a2); } // 0x3627F773
	static int LOAD_PTFX_DLC_ASSETS(Any p0) { return invoke<int>(0x48123591, p0); } // 0x48123591
	static void ADDSHADER(Any p0, Any p1) { invoke<void>(0xA0AE0C98, p0, p1); } // 0xA0AE0C98
}

namespace GAME
{
	static Any DISABLE_PLAYER_GRINGO_USE(Any p0, Any p1) { return invoke<Any>(0x6FCF6BC8, p0, p1); } // 0x6FCF6BC8
	static Any IS_MISSION_SCRIPT(Any p0) { return invoke<Any>(0x5A9D0738, p0); } // 0x5A9D0738
	static void SET_IS_MISSION_SCRIPT(Any p0) { invoke<void>(0x15040CD2, p0); } // 0x15040CD2
	static void SET_SCRIPT_AVOIDS_STRINGTABLE(Any p0) { invoke<void>(0x45589499, p0); } // 0x45589499
	static int GET_GAME_STATE() { return invoke<int>(0xDD9BD22B); } // 0xDD9BD22B
	static void SET_PAUSE_SCRIPT(Any p0) { invoke<void>(0x9B71351C, p0); } // 0x9B71351C
	static Any ENABLE_USE_CONTEXTS(Any p0) { return invoke<Any>(0xFEA58D57, p0); } // 0xFEA58D57
	static Any ARE_USE_CONTEXTS_ENABLED() { return invoke<Any>(0x2ADA3DD4); } // 0x2ADA3DD4
	static Any IS_SCRIPT_USE_CONTEXT_VALID(Any p0) { return invoke<Any>(0x115CD0CC, p0); } // 0x115CD0CC
	static Any ADD_SCRIPT_USE_CONTEXT_IN_VOLUME(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14, Any p15) { return invoke<Any>(0x039E7F1D, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15); } // 0x039E7F1D
	static int ADD_SCRIPT_USE_CONTEXT(const char* gxtName, Any p1, int button, Any p3, Any p4, Any p5, Any p6, int p7, Any p8) { return invoke<int>(0xD7591B0E, gxtName, p1, button, p3, p4, p5, p6, p7, p8); } // 0xD7591B0E
	static Any ADD_SCRIPT_USE_CONTEXT_STICK(Any p0) { return invoke<Any>(0xF48F8F09, p0); } // 0xF48F8F09
	static Any IS_SCRIPT_USE_CONTEXT_PRESSED(Any p0) { return invoke<Any>(0x45C1C061, p0); } // 0x45C1C061
	static Any WAS_SCRIPT_USE_CONTEXT_EVER_PRESSED(Any p0) { return invoke<Any>(0x971559CA, p0); } // 0x971559CA
	static Any SET_USE_CONTEXT_TEXT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<Any>(0x3ECD8FEE, p0, p1, p2, p3, p4, p5, p6); } // 0x3ECD8FEE
	static Any RELEASE_SCRIPT_USE_CONTEXT(Any p0) { return invoke<Any>(0x4F52CB58, p0); } // 0x4F52CB58
	static Any NET_MAILBOX_IS_SIGNED_INTO_SC() { return invoke<Any>(0xA3E1EF71); } // 0xA3E1EF71
	static Any NET_MAILBOX_GET_MAX_NUM_CHALLENGES() { return invoke<Any>(0x6B439149); } // 0x6B439149
	static Any NET_MAILBOX_GET_NUM_CHALLENGES() { return invoke<Any>(0x89F1B8CD); } // 0x89F1B8CD
	static Any NET_MAILBOX_GET_CHALLENGE_BY_INDEX(Any p0) { return invoke<Any>(0xE85942F0, p0); } // 0xE85942F0
	static Any NET_MAILBOX_GET_CHALLENGE_BY_ID(Any p0) { return invoke<Any>(0xD4FBCCE0, p0); } // 0xD4FBCCE0
	static Any NET_MAILBOX_IS_CHALLENGE_VALID(Any p0) { return invoke<Any>(0xC9E96F78, p0); } // 0xC9E96F78
	static Any SC_CHALLENGE_LAUNCH(Any p0) { return invoke<Any>(0xCBBE41DD, p0); } // 0xCBBE41DD
	static Any SC_CHALLENGE_CLEAN_UP(Any p0) { return invoke<Any>(0xB7DE2AF2, p0); } // 0xB7DE2AF2
	static Any SC_CHALLENGE_IS_RUNNING(Any p0) { return invoke<Any>(0x79F09AC7, p0); } // 0x79F09AC7
	static Any SC_CHALLENGE_IS_ACTIVE(Any p0, Any p1) { return invoke<Any>(0x5D7197BC, p0, p1); } // 0x5D7197BC
	static Any SC_CHALLENGE_GET_COMMUNITY_TOTAL(Any p0) { return invoke<Any>(0xFFC55DA4, p0); } // 0xFFC55DA4
	static Any SC_CHALLENGE_GET_COMMUNITY_VALUE(Any p0) { return invoke<Any>(0xCEEEAE1D, p0); } // 0xCEEEAE1D
	static Any SC_CHALLENGE_PROCESS_EXPIRATION(Any p0) { return invoke<Any>(0x1876B04E, p0); } // 0x1876B04E
	static Any SC_CHALLENGE_GET_EXPIRATION_STATE(Any p0) { return invoke<Any>(0x4BD61354, p0); } // 0x4BD61354
	static Any SC_CHALLENGE_RESET_EXPIRATION_STATE(Any p0) { return invoke<Any>(0xF5F97702, p0); } // 0xF5F97702
	static Any SC_CHALLENGE_IS_VAR_VALID(Any p0, Any p1) { return invoke<Any>(0xFD6197EB, p0, p1); } // 0xFD6197EB
	static Any SC_CHALLENGE_GET_VAR_FLOAT(Any p0, Any p1, Any p2) { return invoke<Any>(0xC322556E, p0, p1, p2); } // 0xC322556E
	static Any SC_CHALLENGE_GET_VAR_INT(Any p0, Any p1) { return invoke<Any>(0x2390DD18, p0, p1); } // 0x2390DD18
	static Any SC_CHALLENGE_GET_VAR_BOOL(Any p0, Any p1) { return invoke<Any>(0xB40622F1, p0, p1); } // 0xB40622F1
	static Any SC_CHALLENGE_RELEASE(Any p0) { return invoke<Any>(0xD2513200, p0); } // 0xD2513200
	static Any SC_CHALLENGE_GET_LEADERBOARD_ID(Any p0, Any p1, Any p2) { return invoke<Any>(0xC21048BF, p0, p1, p2); } // 0xC21048BF
	static Any SC_CHALLENGE_GET_MIN_LB_REFRESH_DELAY_SECS(Any p0) { return invoke<Any>(0x5725C84F, p0); } // 0x5725C84F
	static Any SC_CHALLENGE_GET_MIN_SUBMIT_DELAY_SECS(Any p0) { return invoke<Any>(0x2374C1E0, p0); } // 0x2374C1E0
}

namespace GATEWAY
{
	static Any GATEWAY_GET_ACTOR(Any p0) { return invoke<Any>(0x820699A8, p0); } // 0x820699A8
	static Any GATEWAY_SET_ACTOR(Any p0) { return invoke<Any>(0x26D24123, p0); } // 0x26D24123
	static Any GATEWAY_GET_VOLUME(Any p0) { return invoke<Any>(0x987AD426, p0); } // 0x987AD426
	static Any GATEWAY_GET_MARKER(Any p0) { return invoke<Any>(0xB62A4FB1, p0); } // 0xB62A4FB1
	static Any GATEWAY_UPDATE(Any p0) { return invoke<Any>(0x96BD89B6, p0); } // 0x96BD89B6
	static Any ACTOR_DATA_GRAVITY_LIMIT(Any p0) { return invoke<Any>(0xF03CC7A7, p0); } // 0xF03CC7A7
	static Any GATEWAY_DISABLE() { return invoke<Any>(0x620A3C17); } // 0x620A3C17
	static Any GATEWAYS_ARE_DISABLED() { return invoke<Any>(0x3AE1062C); } // 0x3AE1062C
	static Any GATEWAY_IS_DISABLED(Any p0) { return invoke<Any>(0xB9F2F8BB, p0); } // 0xB9F2F8BB
}

namespace GRAVESTONE
{
	static int IS_GRAVESTONE_SECTOR_READY() { return invoke<int>(0xF62EE158); } // 0xF62EE158
	static void SET_CURRENT_GRAVESTONE_SECTOR(Any p0) { invoke<void>(0x449D4A89, p0); } // 0x449D4A89
	static int CREATE_GRAVESTONE_TEXT_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xAEC955F8, p0, p1, p2, p3, p4, p5); } // 0xAEC955F8
	static int CREATE_WANTEDPOSTER_TEXT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { return invoke<int>(0x211DE185, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x211DE185
	static Any CREATE_MP_TEXT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<Any>(0x5BF5A39C, p0, p1, p2, p3, p4, p5); } // 0x5BF5A39C
}

namespace GREETING
{
	static void SET_GREETING_CONTEXT(int greetingContextId) { invoke<void>(0x9953D4FC, greetingContextId); } // 0x9953D4FC
	static void SET_NON_VERBAL_GREETING_PROBABILITY(float probability) { invoke<void>(0x751809BB, probability); } // 0x751809BB
	static void SET_GREETING_LOOK_AT_ANGLE_DEFAULT(float angle) { invoke<void>(0x25A42C69, angle); } // 0x25A42C69
	static void SET_GREETING_LOOK_AT_ANGLE_ACTOR_SPECIFIC(Any p0, Any p1) { invoke<void>(0x40121E4F, p0, p1); } // 0x40121E4F
	static void SET_GREETING_PROBABILITY_NPC_DEFAULT(float probability) { invoke<void>(0x86CB8CFB, probability); } // 0x86CB8CFB
	static void SET_GREETING_PROBABILITY_PLAYER_DEFAULT(float probability) { invoke<void>(0xD6AD0016, probability); } // 0xD6AD0016
	static void SET_GREETING_PROBABILITY_ACTOR_SPECIFIC(Actor actor, float probability) { invoke<void>(0xDE84B637, actor, probability); } // 0xDE84B637
	static void SET_GREETING_MIN_TIME_INTERVAL(float minInterval) { invoke<void>(0x8C00C0BE, minInterval); } // 0x8C00C0BE
	static void SET_GREETING_MIN_TIME_INTERVAL_SAME_TARGET(float minInterval) { invoke<void>(0x7CC67B30, minInterval); } // 0x7CC67B30
	static void SET_GREETING_MAX_DISTANCE(float maxDistance) { invoke<void>(0xD4ECD97D, maxDistance); } // 0xD4ECD97D
	static void SET_GREETING_MIN_MOVEMENT_SPEED(float minSpeed) { invoke<void>(0x826BB889, minSpeed); } // 0x826BB889
	static void SET_GREETING_MAX_MOVEMENT_ANGLE(float maxAngle) { invoke<void>(0x5473B93A, maxAngle); } // 0x5473B93A
	static void SET_GREETING_ANIM_SIGNAL_TIMEOUT_DURATION(float timeoutDuration) { invoke<void>(0x1B1EFCCB, timeoutDuration); } // 0x1B1EFCCB
}

namespace GRINGO
{
	static BOOL IS_GRINGO_ACTIVE() { return invoke<BOOL>(0x86F2C24D); } // 0x86F2C24D
	static BOOL IS_GRINGO_READY(Any p0) { return invoke<BOOL>(0xB9BFCB41, p0); } // 0xB9BFCB41
	static BOOL GRINGO_IS_ACTIVE(Any p0) { return invoke<BOOL>(0xB8A48688, p0); } // 0xB8A48688
	static int GRINGO_GET_TARGET(Any p0) { return invoke<int>(0xC70FDA39, p0); } // 0xC70FDA39
	static void GRINGO_WAIT(Any p0) { invoke<void>(0x738FA66B, p0); } // 0x738FA66B
	static int GRINGO_FORCE_UPDATE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x4B29AED2, p0, p1, p2, p3); } // 0x4B29AED2
	static void GRINGO_STOP() { invoke<void>(0x59647303); } // 0x59647303
	static int GRINGO_STAY_ACTIVE(Any p0, Any p1) { return invoke<int>(0x9175FCFA, p0, p1); } // 0x9175FCFA
	static int GRINGO_DEACTIVATE(Any p0) { return invoke<int>(0x25636669, p0); } // 0x25636669
	static int GRINGO_DEACTIVATE_AND_RESET_ACTORS(Any p0) { return invoke<int>(0xA9F5CDCB, p0); } // 0xA9F5CDCB
	static void GRINGO_ENABLE_TYPE(Any p0) { invoke<void>(0xCB58D301, p0); } // 0xCB58D301
	static void GRINGO_DISABLE_TYPE(Any p0) { invoke<void>(0xCB91CC6E, p0); } // 0xCB91CC6E
	static int GRINGO_ENABLE_SPAWN(Any p0, Any p1) { return invoke<int>(0xA5EDCA4A, p0, p1); } // 0xA5EDCA4A
	static int LOCATE_GRINGO_OF_TYPE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xB1FCFFDC, p0, p1, p2, p3); } // 0xB1FCFFDC
	static int LOCATE_GRINGO_OF_TYPE_BY_ID(Any p0, Any p1, Any p2) { return invoke<int>(0x99356925, p0, p1, p2); } // 0x99356925
	static int LOCATE_GRINGOS_OF_TYPE(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xBD269877, p0, p1, p2, p3, p4); } // 0xBD269877
	static int LOCATE_GRINGO_OF_NAME(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x08D76BB0, p0, p1, p2, p3); } // 0x08D76BB0
	static int LOCATE_GRINGOS_OF_NAME(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xE9612679, p0, p1, p2, p3, p4); } // 0xE9612679
	static int GRINGO_ACTOR_CAN_USE(Any p0, Any p1, Any p2) { return invoke<int>(0xFA37C0FA, p0, p1, p2); } // 0xFA37C0FA
	static int GRINGO_SETUP_PROP_ASSOCIATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x38771B89, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x38771B89
	static int GRINGO_SETUP_ATTR_ASSOCIATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11) { return invoke<int>(0xC426D16F, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0xC426D16F
	static int GRINGO_CLEAR_PROP_ASSOCIATION(Any p0, Any p1, Any p2) { return invoke<int>(0xF8F80679, p0, p1, p2); } // 0xF8F80679
	static void GRINGO_LOAD_ANIMATION(Any p0) { invoke<void>(0x78B655B1, p0); } // 0x78B655B1
	static void GRINGO_UNLOAD_ANIMATION(Any p0) { invoke<void>(0x777842E3, p0); } // 0x777842E3
	static int GRINGO_LOAD_ANIMATION_FOR_USER(Any p0, Any p1, Any p2) { return invoke<int>(0x7D600F2F, p0, p1, p2); } // 0x7D600F2F
	static int GRINGO_UNLOAD_ANIMATION_FOR_USER(Any p0, Any p1, Any p2) { return invoke<int>(0xBEF32D17, p0, p1, p2); } // 0xBEF32D17
	static int GRINGO_HAS_ANIMSET_LOADED(Any p0, Any p1, Any p2) { return invoke<int>(0x2C57A529, p0, p1, p2); } // 0x2C57A529
	static int GRINGO_LOAD_ANIMATION_FOR_ACTOR_ENUM_EXT(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x8EB5CE58, p0, p1, p2, p3); } // 0x8EB5CE58
	static int GRINGO_UNLOAD_ANIMATION_FOR_ACTOR_ENUM_EXT(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x7A759A53, p0, p1, p2, p3); } // 0x7A759A53
	static BOOL GRINGO_HAS_ANIMSET_LOADED_FOR_ACTOR_ENUM_EXT(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x0DC149BD, p0, p1, p2, p3); } // 0x0DC149BD
	static void GRINGO_ENABLE_PLAYER_CONTROL(Any p0, Any p1) { invoke<void>(0x0B853FD5, p0, p1); } // 0x0B853FD5
	static int GRINGO_IS_USABLE_BY_PLAYER(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xF8D9688A, p0, p1, p2, p3, p4, p5); } // 0xF8D9688A
	static void GRINGO_SET_USABLE_BY_PLAYER(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x80317230, p0, p1, p2, p3, p4); } // 0x80317230
	static int GRINGO_USABLE_BY_ACTOR_ENUM(Any p0, Any p1, Any p2) { return invoke<int>(0xE2DCFF34, p0, p1, p2); } // 0xE2DCFF34
	static int GRINGO_DEBUG_IS_SELECTED(Any p0) { return invoke<int>(0xF4015EFC, p0); } // 0xF4015EFC
	static int _GRINGO_PLAYER_OVERRIDE_ON() { return invoke<int>(0x0A0E660E); } // 0x0A0E660E
	static int GRINGO_GET_MY_OBJECT_REF() { return invoke<int>(0x5F7176D6); } // 0x5F7176D6
	static int GRINGO_GET_MY_GRINGO_ID() { return invoke<int>(0xAE7B3880); } // 0xAE7B3880
	static int _GRINGO_IS_BREAK_TOGGLE_SET() { return invoke<int>(0xBBB2780E); } // 0xBBB2780E
	static void GRINGO_SET_ALL_USES_OWNERSHIP(Any p0, Any p1) { invoke<void>(0x761BA4BD, p0, p1); } // 0x761BA4BD
	static void GRINGO_SET_USE_OWNERSHIP(Any p0, Any p1, Any p2) { invoke<void>(0x6E86FCB5, p0, p1, p2); } // 0x6E86FCB5
	static void GRINGO_SET_CHILD_USE_ACTIVATIONS(Any p0, Any p1) { invoke<void>(0x89DE8A75, p0, p1); } // 0x89DE8A75
	static void GRINGO_SET_COMMON_LAYER_USE_ACTIVATIONS(Any p0, Any p1) { invoke<void>(0x53B9569C, p0, p1); } // 0x53B9569C
	static int GRINGO_HANDLES_MOVEMENT(Any p0) { return invoke<int>(0xEDF3BF37, p0); } // 0xEDF3BF37
	static BOOL IS_GRINGO_COMPONENT_VALID(Any p0) { return invoke<BOOL>(0xBD503DC2, p0); } // 0xBD503DC2
	static int GRINGO_COMPONENT_CHECK_NAME(Any p0, Any p1) { return invoke<int>(0xA766EA5C, p0, p1); } // 0xA766EA5C
	static int GRINGO_GET_COMPONENT_HASH(Any p0) { return invoke<int>(0x14E53D6F, p0); } // 0x14E53D6F
	static int GRINGO_IS_COMPONENT_OF_TYPE(Any p0, Any p1) { return invoke<int>(0x284DD17C, p0, p1); } // 0x284DD17C
	static int GRINGO_GET_FIRST_NAMED_CHILD(Any p0, Any p1, Any p2) { return invoke<int>(0xE4C686BA, p0, p1, p2); } // 0xE4C686BA
	static int GRINGO_GET_FIRST_CHILD(Any p0, Any p1) { return invoke<int>(0x3E8F94BE, p0, p1); } // 0x3E8F94BE
	static int GRINGO_GET_INDEX_OF_NEXT_NAMED_CHILD(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xDD807723, p0, p1, p2, p3); } // 0xDD807723
	static int GRINGO_GET_INDEX_OF_NEXT_CHILD(Any p0, Any p1, Any p2) { return invoke<int>(0xD6EE9534, p0, p1, p2); } // 0xD6EE9534
	static int GRINGO_GET_CHILD_COMPONENT_COUNT(Any p0) { return invoke<int>(0x3FA5FC03, p0); } // 0x3FA5FC03
	static int GRINGO_GET_INDEXED_CHILD_COMPONENT(Any p0, Any p1) { return invoke<int>(0xAD313D88, p0, p1); } // 0xAD313D88
	static int GRINGO_GET_PROP_FROM_COMPONENT(Any p0) { return invoke<int>(0xA20141C0, p0); } // 0xA20141C0
	static int GRINGO_GET_PROP_FROM_COMPONENT_EXT(Any p0, Any p1) { return invoke<int>(0x9AD6D5B1, p0, p1); } // 0x9AD6D5B1
	static int GRINGO_GET_PARENT_COMPONENT(Any p0, Any p1) { return invoke<int>(0xD282013F, p0, p1); } // 0xD282013F
	static int GRINGO_GET_USER_POS_WITH_OFFSET(Any p0, Any p1, Any p2) { return invoke<int>(0xBC32DA9A, p0, p1, p2); } // 0xBC32DA9A
	static void GRINGO_SET_MESSAGE_RETURN(Any p0) { invoke<void>(0x37D0F3E9, p0); } // 0x37D0F3E9
	static int GRINGO_GET_MSG_COMPONENT_CONTEXT() { return invoke<int>(0xCA589BAB); } // 0xCA589BAB
	static int GRINGO_HAS_PENDING_MESSAGE() { return invoke<int>(0xF550F8E7); } // 0xF550F8E7
	static int GRINGO_GET_MESSAGE_TYPE() { return invoke<int>(0x54745DB0); } // 0x54745DB0
	static int GRINGO_GET_REQUESTING_ACTOR() { return invoke<int>(0x2F096285); } // 0x2F096285
	static void GRINGO_SET_REQUEST_STRING(Any p0) { invoke<void>(0x7F3020EB, p0); } // 0x7F3020EB
	static void GRINGO_SET_REQUEST_FAILURE_REASON(Any p0) { invoke<void>(0x8CAF5C5C, p0); } // 0x8CAF5C5C
	static int GRINGO_IS_FORCE_QUITTING() { return invoke<int>(0x926FD361); } // 0x926FD361
	static int GRINGO_IS_CAPABLE_OF_USE(Any p0, Any p1) { return invoke<int>(0x3DEA631B, p0, p1); } // 0x3DEA631B
	static int GRINGO_SHOULD_SUSPEND_MOVER(Any p0) { return invoke<int>(0x5CFBF505, p0); } // 0x5CFBF505
	static int GRINGO_SHOULD_FIX_MOVER(Any p0) { return invoke<int>(0x3A31175A, p0); } // 0x3A31175A
	static int GRINGO_GET_USE_COMPONENT_POSITION(Any p0, Any p1, Any p2) { return invoke<int>(0x405E3903, p0, p1, p2); } // 0x405E3903
	static int GRINGO_GET_USE_COMPONENT_POSITION_EXT(Any p0, Any p1, Any p2) { return invoke<int>(0xCE210220, p0, p1, p2); } // 0xCE210220
	static int GRINGO_GET_USE_COMPONENT_OFFSET_POSITION_EXT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xA9E00433, p0, p1, p2, p3, p4, p5); } // 0xA9E00433
	static int GRINGO_GET_USE_COMPONENT_EXT(Any p0, Any p1) { return invoke<int>(0xECD4F604, p0, p1); } // 0xECD4F604
	static int GRINGO_GET_USE_COMPONENT_POSITION_LOCAL(Any p0, Any p1) { return invoke<int>(0x5AF74E19, p0, p1); } // 0x5AF74E19
	static int GRINGO_GET_USE_REQUIRES_OBSTACLE(Any p0) { return invoke<int>(0x51581898, p0); } // 0x51581898
	// Name could be false positive
	static int GRINGO_IS_CHARACTER_BLEND_PAUSED(Any p0) { return invoke<int>(0xD62D413C, p0); } // 0xD62D413C
	static int GRINGO_GET_TASKED_USER_EXTERNAL(Any p0, Any p1) { return invoke<int>(0x92FE8D74, p0, p1); } // 0x92FE8D74
	static int GRINGO_SET_REUSE_DELAY(Any p0, Any p1) { return invoke<int>(0x8C2914C4, p0, p1); } // 0x8C2914C4
	static int GRINGO_GET_USE_COMPONENT_HEADING(Any p0) { return invoke<int>(0x5B46757F, p0); } // 0x5B46757F
	static int GRINGO_GET_USE_COMPONENT_HEADING_EXT(Any p0, Any p1) { return invoke<int>(0xD14515A3, p0, p1); } // 0xD14515A3
	static int GRINGO_SET_AVAILABILITY(Any p0, Any p1) { return invoke<int>(0xF95DDBF2, p0, p1); } // 0xF95DDBF2
	static int GRINGO_GET_AVAILABILITY(Any p0, Any p1) { return invoke<int>(0x6ADC74CE, p0, p1); } // 0x6ADC74CE
	static int GRINGO_SET_AVAILABILITY_EXT(Any p0, Any p1, Any p2) { return invoke<int>(0xB78BC233, p0, p1, p2); } // 0xB78BC233
	static int GRINGO_GET_REQUEST_MID_ACTION() { return invoke<int>(0x5388F37D); } // 0x5388F37D
	static void GRINGO_SET_COMPONENT_USER(Any p0, Any p1) { invoke<void>(0x94F442D0, p0, p1); } // 0x94F442D0
	static int GRINGO_GET_COMPONENT_USER(Any p0) { return invoke<int>(0x15A0E28B, p0); } // 0x15A0E28B
	static void GRINGO_CLEAR_COMPONENT_USER(Any p0) { invoke<void>(0x90FBBB8B, p0); } // 0x90FBBB8B
	static int GRINGO_QUERY_NAMED_COMPONENT_USER(Any p0, Any p1) { return invoke<int>(0x0208A8E0, p0, p1); } // 0x0208A8E0
	static int GRINGO_REWARD_ACTOR(Any p0, Any p1, Any p2) { return invoke<int>(0x217B4264, p0, p1, p2); } // 0x217B4264
	static int GRINGO_REPORT_USE_FINISHED(Any p0, Any p1) { return invoke<int>(0x5C11B011, p0, p1); } // 0x5C11B011
	static int GRINGO_WAS_USE_SUCCESSFUL(Any p0) { return invoke<int>(0x5F516FC3, p0); } // 0x5F516FC3
	static void GRINGO_SATISFY_MOTIVES_OF_ACTOR(Any p0, Any p1) { invoke<void>(0xB62FE25C, p0, p1); } // 0xB62FE25C
	static int GRINGO_PLAY_ANIM_ON_ACTOR(Any p0, Any p1, Any p2) { return invoke<int>(0xE18BCD70, p0, p1, p2); } // 0xE18BCD70
	static int GRINGO_IS_ACTOR_PLAYING_ANIM(Any p0, Any p1) { return invoke<int>(0x35279C3F, p0, p1); } // 0x35279C3F
	static int GRINGO_RETURN_ACTOR_TO_DEFAULT_ANIMS(Any p0) { return invoke<int>(0xB62D549E, p0); } // 0xB62D549E
	static int GRINGO_OWNS_ACTOR_ANIMS(Any p0) { return invoke<int>(0xE9C74577, p0); } // 0xE9C74577
	static int GRINGO_PLAY_ANIM_ON_ACTOR_WITH_PROP_COMPONENT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xB8C419C3, p0, p1, p2, p3, p4, p5); } // 0xB8C419C3
	static void GRINGO_ACTOR_DROP_ATTACHED_PROP(Any p0) { invoke<void>(0x0B9AE52F, p0); } // 0x0B9AE52F
	static int ATTACH_PROP_TO_ANIM(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x0436C0BF, p0, p1, p2, p3, p4, p5); } // 0x0436C0BF
	static int GRINGO_ATTACH_PROP_TO_ANIM(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x4DB7C61C, p0, p1, p2, p3, p4); } // 0x4DB7C61C
	static int GRINGO_GET_PROP_ATTACH_SLOT(Any p0) { return invoke<int>(0xB96874B4, p0); } // 0xB96874B4
	static int ATTACH_SLOT_FROM_STRING(Any p0) { return invoke<int>(0x4A61BD63, p0); } // 0x4A61BD63
	static int GRINGO_ANIM_GET_AST_FILENAME(Any p0) { return invoke<int>(0xADBF3ADF, p0); } // 0xADBF3ADF
	static int GRINGO_ANIM_GET_ACT_FILENAME(Any p0) { return invoke<int>(0x721FC9A4, p0); } // 0x721FC9A4
	static int GRINGO_GET_ACTOR_SPECIFIC_AST_FILENAME(Any p0, Any p1) { return invoke<int>(0x87BA5FE9, p0, p1); } // 0x87BA5FE9
	static int GRINGO_ANIM_GET_ACT_ROOTNODE(Any p0) { return invoke<int>(0x6263F909, p0); } // 0x6263F909
	static int GRINGO_ANIM_IS_SUBNODE_PLAYING_BY_HASH(Any p0, Any p1, Any p2) { return invoke<int>(0xB555A648, p0, p1, p2); } // 0xB555A648
	static int GRINGO_ANIM_PLAY_NODE_BY_HASH(Any p0, Any p1, Any p2) { return invoke<int>(0xAFD53217, p0, p1, p2); } // 0xAFD53217
	static int GRINGO_ACTOR_FACE(Any p0, Any p1, Any p2) { return invoke<int>(0x29C63CE6, p0, p1, p2); } // 0x29C63CE6
	static int GRINGO_ACTOR_MOVE_TO(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x698105FC, p0, p1, p2, p3, p4); } // 0x698105FC
	static int GRINGO_ACTOR_MOVE_TO_AND_FACE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x0AF4FCB9, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x0AF4FCB9
	static int GRINGO_ACTOR_MOVE_TO_AND_FACE_WITH_USER_OFFSET(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { return invoke<int>(0xEEE9C799, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xEEE9C799
	static void GRINGO_SET_PROP_COLLISIONS(Any p0, Any p1) { invoke<void>(0x98543454, p0, p1); } // 0x98543454
	static void GRINGO_REINIT_PROP(Any p0) { invoke<void>(0x6BA667B5, p0); } // 0x6BA667B5
	static int GRINGO_IS_PROP_READY(Any p0) { return invoke<int>(0x24BAABCA, p0); } // 0x24BAABCA
	static int GRINGO_GET_PHYSINST(Any p0) { return invoke<int>(0x5EC1CABF, p0); } // 0x5EC1CABF
	static void GRINGO_PROP_RESET_GRACEFULLY(Any p0) { invoke<void>(0x22D573D2, p0); } // 0x22D573D2
	static int GRINGO_IS_TARGET_OBJECT_READY() { return invoke<int>(0xFF1FC1EF); } // 0xFF1FC1EF
	static int GET_GRINGO_BOOL_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0xFACF08C7, p0, p1, p2); } // 0xFACF08C7
	static int GET_GRINGO_INT_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x8A86AF8B, p0, p1, p2); } // 0x8A86AF8B
	static int GET_GRINGO_OBJECT_REF_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x869D5D92, p0, p1, p2); } // 0x869D5D92
	static int GET_GRINGO_STRUCT_ATTR(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xFA22A365, p0, p1, p2, p3); } // 0xFA22A365
	static int GET_GRINGO_FLOAT_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x2EFD2B55, p0, p1, p2); } // 0x2EFD2B55
	static int GET_GRINGO_VECTOR_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x5851C408, p0, p1, p2); } // 0x5851C408
	static int GET_GRINGO_RELATIVE_POSITION_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x1F74EE6C, p0, p1, p2); } // 0x1F74EE6C
	static int GET_GRINGO_RELATIVE_ORIENTATION_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x7E4681E8, p0, p1, p2); } // 0x7E4681E8
	static int GET_GRINGO_STRING_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x6BA58AC7, p0, p1, p2); } // 0x6BA58AC7
	static int SET_GRINGO_BOOL_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0xCF6822D7, p0, p1, p2); } // 0xCF6822D7
	static int SET_GRINGO_INT_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x377B2C54, p0, p1, p2); } // 0x377B2C54
	static int SET_GRINGO_OBJECT_REF_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0xAFF7D382, p0, p1, p2); } // 0xAFF7D382
	static int SET_GRINGO_FLOAT_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0xBC3C401F, p0, p1, p2); } // 0xBC3C401F
	static int SET_GRINGO_VECTOR_ATTR(Any p0, Any p1, Any p2) { return invoke<int>(0x5C6831F9, p0, p1, p2); } // 0x5C6831F9
	static int GRINGO_QUERY_BOOL(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x5C2174C7, p0, p1, p2, p3); } // 0x5C2174C7
	static int GRINGO_QUERY_INT(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x6B1F2FEB, p0, p1, p2, p3); } // 0x6B1F2FEB
	static int GRINGO_QUERY_OBJECT_REF(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x15D6F3C7, p0, p1, p2, p3); } // 0x15D6F3C7
	static int GRINGO_QUERY_STRUCT(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x1528F08B, p0, p1, p2, p3, p4); } // 0x1528F08B
	static int GRINGO_QUERY_FLOAT(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x69CF9B75, p0, p1, p2, p3); } // 0x69CF9B75
	static int GRINGO_QUERY_STRING(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x30AF0FA8, p0, p1, p2, p3); } // 0x30AF0FA8
	static int GRINGO_QUERY_PROP(Any p0, Any p1) { return invoke<int>(0x2A7B1EFE, p0, p1); } // 0x2A7B1EFE
	static int GRINGO_UPDATE_BOOL(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x554330CA, p0, p1, p2, p3); } // 0x554330CA
	static Any GRINGO_UPDATE_INT(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x0744FEE8, p0, p1, p2, p3); } // 0x0744FEE8
	static int GRINGO_UPDATE_OBJECT_REF(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x4685D538, p0, p1, p2, p3); } // 0x4685D538
	static int GRINGO_UPDATE_STRUCT(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x4DE50AD9, p0, p1, p2, p3, p4); } // 0x4DE50AD9
	static int GRINGO_GET_ATTRIBUTE_COUNT(Any p0) { return invoke<int>(0x39B7D772, p0); } // 0x39B7D772
	static int GRINGO_GET_ATTRIBUTE(Any p0, Any p1) { return invoke<int>(0x19411B1F, p0, p1); } // 0x19411B1F
	static int GRINGO_IS_ATTRIBUTE_VALID(Any p0) { return invoke<int>(0xBED45A9A, p0); } // 0xBED45A9A
	static int GRINGO_GET_ATTRIBUTE_HASH(Any p0) { return invoke<int>(0xD2680017, p0); } // 0xD2680017
	static int GRINGO_GET_VECTOR_ATTR_BY_HANDLE(Any p0, Any p1) { return invoke<int>(0xF0991C9F, p0, p1); } // 0xF0991C9F
	static int GRINGO_GET_STRING_ATTR_BY_HANDLE(Any p0, Any p1) { return invoke<int>(0xD7BB1792, p0, p1); } // 0xD7BB1792
	static int GRINGO_GET_FLOAT_ATTR_BY_HANDLE(Any p0, Any p1) { return invoke<int>(0xF573B7DE, p0, p1); } // 0xF573B7DE
	static int GRINGO_GET_ATTR_TYPE_BY_HANDLE(Any p0) { return invoke<int>(0xBF322F5C, p0); } // 0xBF322F5C
}

namespace GUI
{
	// This function is hard-coded to always return 0.
	static int GUI_MAKE_WINDOW(int parent, Any p1, const char* windowName, const char* p3) { return invoke<int>(0xA20246AB, parent, p1, windowName, p3); } // 0xA20246AB
	// This function is hard-coded to always return 0.
	static int GUI_MAKE_TEXT(int guiHandle, float x, float y, float z, const char* menuTitle, const char* gxtText, float p4) { return invoke<int>(0x68FC1001, guiHandle, x, y, z, menuTitle, gxtText, p4); } // 0x68FC1001
	// This function is hard-coded to always return 0.
	static int GUI_MAKE_OVERLAY(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xA2A68BAD, p0, p1, p2, p3, p4, p5); } // 0xA2A68BAD
	// This function is hard-coded to always return 0.
	static int GUI_WINDOWS_WITH_VALUES(int guiHandle, const char* windowName) { return invoke<int>(0xF6207DF5, guiHandle, windowName); } // 0xF6207DF5
	// This function is hard-coded to always return 1.
	static int GUI_MOVE_WINDOW_ABS(Any p0, Any p1, Any p2) { return invoke<int>(0xA7FF2899, p0, p1, p2); } // 0xA7FF2899
	// This function is hard-coded to always return 1.
	static int GUI_CLOSE_WINDOW(Any p0) { return invoke<int>(0xFDED9B11, p0); } // 0xFDED9B11
	// This function is hard-coded to always return 1.
	static int GUI_WINDOW_VALID(int p0) { return invoke<int>(0xA2E6FECB, p0); } // 0xA2E6FECB
	// This function is hard-coded to always return 1.
	static int GUI_SET_TEXT(int textHandle, const char* menuName) { return invoke<int>(0x5F3A1C35, textHandle, menuName); } // 0x5F3A1C35
	// This function is hard-coded to always return 1.
	static int GUI_SET_TEXT_JUSTIFY(int textHandle, int JustifyType) { return invoke<int>(0x9CC6F183, textHandle, JustifyType); } // 0x9CC6F183
	// This function is hard-coded to always return 1.
	static int GUI_SET_TEXT_COLOR(int textHandle, float R, float G, float B, float A) { return invoke<int>(0x7600ED4B, textHandle, R, G, B, A); } // 0x7600ED4B
	// This function is hard-coded to always return 0.
	static int GUI_MAIN_WINDOW() { return invoke<int>(0x5405B8AA); } // 0x5405B8AA
	static int _0xB498108A() { return invoke<int>(0xB498108A); } // 0xB498108A
	static int _0xC7DEB717() { return invoke<int>(0xC7DEB717); } // 0xC7DEB717
	// Name could be false positive
	// This function is hard-coded to always return 0.
	static int GUI_MESSAGE_RELEASED_INPUT(Any p0) { return invoke<int>(0xD019FF37, p0); } // 0xD019FF37
	static const char* F2VSTR(float value) { return invoke<const char*>(0x4803C120, value); } // 0x4803C120
	static const char* F2STR(float value, Any p1, int precision) { return invoke<const char*>(0xFA6BDD8E, value, p1, precision); } // 0xFA6BDD8E
	static const char* I2STR(const char* p0) { return invoke<const char*>(0x47EF426D, p0); } // 0x47EF426D
	static const char* V2STR(Vector3* value) { return invoke<const char*>(0x52C10147, value); } // 0x52C10147
	static const char* FLOAT_TO_STRING_VERBOSE(float value) { return invoke<const char*>(0x5E339E16, value); } // 0x5E339E16
	static const char* FLOAT_TO_STRING_FORMATED(float value, Any p1, int precision) { return invoke<const char*>(0x8ED1FF95, value, p1, precision); } // 0x8ED1FF95
	static const char* INT_TO_STRING(int value) { return invoke<const char*>(0xA883AFCC, value); } // 0xA883AFCC
	static const char* VECTOR_TO_STRING(Vector3* value) { return invoke<const char*>(0x6B8E4CDD, value); } // 0x6B8E4CDD
}

namespace HEALTH
{
	static Any GET_LAST_ATTACKER(Any p0) { return invoke<Any>(0x2C0F211D, p0); } // 0x2C0F211D
	static Any GET_LAST_HIT_TIME(Any p0) { return invoke<Any>(0x3A207AF2, p0); } // 0x3A207AF2
	static Any GET_LAST_HIT_WEAPON(Any p0) { return invoke<Any>(0x07B7AA6B, p0); } // 0x07B7AA6B
	static Any GET_LAST_HIT_FLAGS(Any p0) { return invoke<Any>(0x08308EBA, p0); } // 0x08308EBA
	static Any GET_LAST_DAMAGE(Any p0) { return invoke<Any>(0x45556269, p0); } // 0x45556269
	static Any GET_LAST_HIT_ZONE(Any p0, Any* p1) { return invoke<Any>(0x855F9A3B, p0, p1); } // 0x855F9A3B
	static Any GET_CORPSE_LAST_HIT_WEAPON() { return invoke<Any>(0x4747F219); } // 0x4747F219
	static Any GET_CORPSE_LAST_HIT_ZONE() { return invoke<Any>(0xF75FE17F); } // 0xF75FE17F
	static Any CLEAR_LAST_HIT() { return invoke<Any>(0x8D696237); } // 0x8D696237
	static void KILL_ACTOR(Actor actor) { invoke<void>(0x8B08ECA2, actor); } // 0x8B08ECA2
	static void KILL_ACTOR_WITH_KILLER(Any p0, Any p1) { invoke<void>(0x6085F7AC, p0, p1); } // 0x6085F7AC
	static BOOL IS_ACTOR_ALIVE(Actor actor) { return invoke<BOOL>(0x2F232639, actor); } // 0x2F232639
	static BOOL IS_ACTOR_DEAD(Actor actor) { return invoke<BOOL>(0x0D798FFE, actor); } // 0x0D798FFE
	static BOOL IS_ACTOR_RAGDOLL(Actor actor) { return invoke<BOOL>(0x3918D335, actor); } // 0x3918D335
	static void SET_ACTOR_HEALTH(Actor actor, float health) { invoke<void>(0xFA090024, actor, health); } // 0xFA090024
	static float GET_ACTOR_HEALTH(Actor actor) { return invoke<float>(0xF246F15D, actor); } // 0xF246F15D
	static float GET_ACTOR_MAX_HEALTH(Actor actor) { return invoke<float>(0xB69A84AF, actor); } // 0xB69A84AF
	static void SET_ACTOR_MAX_HEALTH(Actor actor, float maxHealth) { invoke<void>(0x165BD4C5, actor, maxHealth); } // 0x165BD4C5
	static Any _ACTOR_HAS_KO_POINTS(Any p0) { return invoke<Any>(0x7A207FFE, p0); } // 0x7A207FFE
	static void SET_ACTOR_KO_POINTS(Actor actor, Any p1) { invoke<void>(0x3A2D7759, actor, p1); } // 0x3A2D7759
	static Any GET_ACTOR_KO_POINTS(Actor actor) { return invoke<Any>(0x44787A58, actor); } // 0x44787A58
	static Any GET_ACTOR_MAX_KO_POINTS(Actor actor) { return invoke<Any>(0xAFC96669, actor); } // 0xAFC96669
	static void SET_ACTOR_KNOCKOUTTIME(Actor actor, Any p1) { invoke<void>(0x4EEC6628, actor, p1); } // 0x4EEC6628
	static void SET_ACTOR_KNOCKOUTTIME_DEFAULT(Actor actor, Any p1) { invoke<void>(0x479B997B, actor, p1); } // 0x479B997B
	static BOOL IS_ACTOR_DRUNK(Actor actor) { return invoke<BOOL>(0xFF07D58C, actor); } // 0xFF07D58C
	static void SET_ACTOR_DRUNK(Actor actor, BOOL toggle) { invoke<void>(0x9F57742C, actor, toggle); } // 0x9F57742C
	static void SET_ACTOR_PASSED_OUT(Actor actor, Any p1) { invoke<void>(0x2A9FD09F, actor, p1); } // 0x2A9FD09F
	static void SET_ACTOR_HANGING_FROM_NOOSE(Actor actor, Any p1) { invoke<void>(0x5262C0F7, actor, p1); } // 0x5262C0F7
	static void _SET_HIT_INFO_DDA_LEVEL(Any p0) { invoke<void>(0x6287203C, p0); } // 0x6287203C
	static void _RESET_HIT_INFO_DDA_LEVEL() { invoke<void>(0x1082715D); } // 0x1082715D
}

namespace HOLSTER
{
	static Any ACTOR_HOLSTER_WEAPON(Any p0, Any p1) { return invoke<Any>(0xFE9903CC, p0, p1); } // 0xFE9903CC
	static int ACTOR_START_FORCE_HOLSTER(Any p0, Any p1, Any p2) { return invoke<int>(0x7957CA4F, p0, p1, p2); } // 0x7957CA4F
	static int ACTOR_END_FORCE_HOLSTER(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x231E7034, p0, p1, p2, p3, p4); } // 0x231E7034
	static int ACTOR_DRAW_LAST_WEAPON(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x8FFDCE5C, p0, p1, p2, p3, p4); } // 0x8FFDCE5C
	static int ACTOR_DRAW_ANY_WEAPON(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xD86BFBD8, p0, p1, p2, p3, p4); } // 0xD86BFBD8
	static void ACTOR_DRAW_WEAPON(Any p0, Any p1, Any p2) { invoke<void>(0x953FB7EE, p0, p1, p2); } // 0x953FB7EE
	static int ACTOR_IS_HOLSTERED(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x6426CCD6, p0, p1, p2, p3, p4); } // 0x6426CCD6
	static int SET_WEAPON_SELECTION_ENABLED(Any p0, Any p1) { return invoke<int>(0x2E84E682, p0, p1); } // 0x2E84E682
	static int SET_WEAPON_SELECTION_AI_MIN_RANGE_ACTOR(Any p0, Any p1, float p2) { return invoke<int>(0x261A4C0E, p0, p1, p2); } // 0x261A4C0E
	static int SET_WEAPON_SELECTION_AI_MIN_RANGE_DEFAULT(float p0) { return invoke<int>(0x79EFDF7E, p0); } // 0x79EFDF7E
	static int SET_WEAPON_SELECTION_AI_MAX_RANGE_ACTOR(Any p0, Any p1, float p2) { return invoke<int>(0x5D863C30, p0, p1, p2); } // 0x5D863C30
	static int SET_WEAPON_SELECTION_AI_BASE_PRIORITY_ACTOR(Any p0, Any p1, float p2) { return invoke<int>(0xF71A883A, p0, p1, p2); } // 0xF71A883A
	static int SET_WEAPON_SELECTION_AI_BASE_PRIORITY_DEFAULT(Any p0, float p1) { return invoke<int>(0xCA669478, p0, p1); } // 0xCA669478
	static int SET_WEAPON_SELECTION_AI_CAN_USE_INDOORS_DEFAULT(Any p0, Any p1) { return invoke<int>(0x7DA34015, p0, p1); } // 0x7DA34015
}

namespace HUD
{
	// promptString: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/InputStringsPrompts
	static void UI_SET_PROMPT_STRING(Prompt prompt, const char* promptString) { invoke<void>(0xFA0CF208, prompt, promptString); } // 0xFA0CF208
	// promptIcon: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eControllerPrompt
	static void UI_SET_PROMPT_ICON(Prompt prompt, int promptIcon) { invoke<void>(0xA77E0DDF, prompt, promptIcon); } // 0xA77E0DDF
	// PC only
	static int UI_SET_PROMPT_ICON_STRING(Prompt prompt, const char* inputString) { return invoke<int>(0x247348C5, prompt, inputString); } // 0x247348C5
	static void UI_HIDE_PROMPT(Prompt prompt) { invoke<void>(0x545EC471, prompt); } // 0x545EC471
	static int FLASH_SET_BOOL(const char* scaleformName, const char* scaleformVarName, BOOL toggle) { return invoke<int>(0x34F03EC7, scaleformName, scaleformVarName, toggle); } // 0x34F03EC7
	static int FLASH_SET_INT(const char* scaleformName, const char* scaleformVarName, int value) { return invoke<int>(0x4778A580, scaleformName, scaleformVarName, value); } // 0x4778A580
	static int FLASH_SET_FLOAT(const char* scaleformName, const char* scaleformVarName, float value) { return invoke<int>(0xDF024C94, scaleformName, scaleformVarName, value); } // 0xDF024C94
	static int FLASH_SET_ARRAY_INT(const char* scaleformName, const char* scaleformVarName, int value, int p3) { return invoke<int>(0x8A2A1A51, scaleformName, scaleformVarName, value, p3); } // 0x8A2A1A51
	static int FLASH_SET_STRING(const char* scaleformName, const char* scaleformVarName, const char* string, int p3) { return invoke<int>(0x9E31EEA7, scaleformName, scaleformVarName, string, p3); } // 0x9E31EEA7
	static int FLASH_SET_ARRAY_STRING(const char* scaleformName, const char* scaleformVarName, const char* promptString, Prompt prompt, int p4) { return invoke<int>(0x35CDFDC5, scaleformName, scaleformVarName, promptString, prompt, p4); } // 0x35CDFDC5
	static BOOL FLASH_GET_BOOL(const char* scaleformName, const char* scaleformVarName) { return invoke<BOOL>(0xFA266B15, scaleformName, scaleformVarName); } // 0xFA266B15
	static int FLASH_GET_INT(const char* scaleformName, const char* scaleformVarName) { return invoke<int>(0x03568B83, scaleformName, scaleformVarName); } // 0x03568B83
	static float FLASH_GET_FLOAT(const char* scaleformName, const char* scaleformVarName) { return invoke<float>(0xA332ACE3, scaleformName, scaleformVarName); } // 0xA332ACE3
	static int FLASH_SET_ARRAY_STRING_FORMATTED(const char* scaleformName, const char* scaleformVarName, const char* promptString, Prompt prompt, int p4, int p5, int p6, int p7, int p8) { return invoke<int>(0xE39B92B7, scaleformName, scaleformVarName, promptString, prompt, p4, p5, p6, p7, p8); } // 0xE39B92B7
	static void PRINT_BIG(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x637016C9, p0, p1, p2, p3, p4); } // 0x637016C9
	static int PRINT_SMALL_B(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any* p6) { return invoke<int>(0x04A38C60, p0, p1, p2, p3, p4, p5, p6); } // 0x04A38C60
	static void PRINT_HELP_B(const char* txt, float time, BOOL playSound, Any p3, Any p4, BOOL p5, const char* unk, const char* audioName) { invoke<void>(0xE42A8278, txt, time, playSound, p3, p4, p5, unk, audioName); } // 0xE42A8278
	static void PRINT_OBJECTIVE_B(const char* txt, float time, BOOL isStringLiteral, int printType, Any p4, Any p5, Any p6, Any p7) { invoke<void>(0x32394BB6, txt, time, isStringLiteral, printType, p4, p5, p6, p7); } // 0x32394BB6
	static void PRINT_MONEY(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x51948EA6, p0, p1, p2, p3, p4, p5); } // 0x51948EA6
	static void PRINT_BIG_FORMAT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { invoke<void>(0xBCB8D17F, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xBCB8D17F
	static void PRINT_SMALL_FORMAT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { invoke<void>(0xBBBDFF7C, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xBBBDFF7C
	static void PRINT_OBJECTIVE_FORMAT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { invoke<void>(0x283B4EFC, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x283B4EFC
	static void PRINT_HELP_FORMAT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { invoke<void>(0xD8AAF8E0, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xD8AAF8E0
	static int GET_LAST_PRINTED_OBJECTIVE() { return invoke<int>(0x14708CB1); } // 0x14708CB1
	static int CLEAR_PRINTED_OBJECTIVE() { return invoke<int>(0xB9D95B4C); } // 0xB9D95B4C
	static int HUD_IS_SHOWING_SMALL_TEXT() { return invoke<int>(0x710B3A83); } // 0x710B3A83
	static int HUD_IS_SHOWING_BIG_TEXT() { return invoke<int>(0x60135878); } // 0x60135878
	static BOOL HUD_IS_SHOWING_OBJECTIVE() { return invoke<BOOL>(0x2F0E7DE7); } // 0x2F0E7DE7
	static BOOL HUD_IS_SHOWING_HELP_TEXT() { return invoke<BOOL>(0x4B2FCAF6); } // 0x4B2FCAF6
	static void HUD_CLEAR_SMALL_TEXT() { invoke<void>(0x585F008A); } // 0x585F008A
	static void HUD_CLEAR_BIG_TEXT() { invoke<void>(0xD6DFA6FC); } // 0xD6DFA6FC
	static void HUD_CLEAR_COUNTER() { invoke<void>(0x050EFAAB); } // 0x050EFAAB
	static void HUD_CLEAR_OBJECTIVE() { invoke<void>(0x160BDC7A); } // 0x160BDC7A
	static void HUD_CLEAR_HELP() { invoke<void>(0x0095B908); } // 0x0095B908
	static int HUD_CLEAR_SMALL_TEXT_QUEUE() { return invoke<int>(0x02E1E708); } // 0x02E1E708
	static int HUD_CLEAR_BIG_TEXT_QUEUE() { return invoke<int>(0x777A1CA2); } // 0x777A1CA2
	static void HUD_CLEAR_OBJECTIVE_QUEUE() { invoke<void>(0xE4DACF40); } // 0xE4DACF40
	static void HUD_CLEAR_HELP_QUEUE() { invoke<void>(0x495164AD); } // 0x495164AD
	static const char* SET_RADAR_STREAMING(const char* p0) { return invoke<const char*>(0x0A07FE74, p0); } // 0x0A07FE74
	// blipID: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eBlipId
	static Blip ADD_BLIP_FOR_ACTOR(Actor actor, int blipID, float p2, int priority, int p4) { return invoke<Blip>(0xEFB9362F, actor, blipID, p2, priority, p4); } // 0xEFB9362F
	// blipID: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eBlipId
	static Blip ADD_BLIP_FOR_OBJECT(Object object, int blipID, float p2, int priority, int p4) { return invoke<Blip>(0x0E5372EC, object, blipID, p2, priority, p4); } // 0x0E5372EC
	// blipID: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eBlipId
	static Blip ADD_BLIP_FOR_COORD(Vector3* position, int blipID, float p2, int priority, int p4) { return invoke<Blip>(0xC6F43D0E, position, blipID, p2, priority, p4); } // 0xC6F43D0E
	// blipID: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eBlipId
	static void CHANGE_BLIP_ICON(Blip blip, int blipID) { invoke<void>(0xABD125F6, blip, blipID); } // 0xABD125F6
	static void SET_BLIP_POS(Blip blip, Vector3* position) { invoke<void>(0xB2EAF8DD, blip, position); } // 0xB2EAF8DD
	static void SET_BLIP_SCALE(Blip blip, float scale) { invoke<void>(0x1E6EC434, blip, scale); } // 0x1E6EC434
	static void SET_BLIP_COLOR(Blip blip, float r, float g, float b, float a) { invoke<void>(0xA2B8A736, blip, r, g, b, a); } // 0xA2B8A736
	static void SET_BLIP_PRIORITY(Blip blip, int priority) { invoke<void>(0xCE87DA6F, blip, priority); } // 0xCE87DA6F
	static void SET_BLIP_BLINK(Blip blip, int p1, int p2, int p3) { invoke<void>(0x04B8C8C6, blip, p1, p2, p3); } // 0x04B8C8C6
	static void SET_BLIP_FLAG(Blip blip, int flag, Any p2) { invoke<void>(0xA9A01C70, blip, flag, p2); } // 0xA9A01C70
	static void SET_BLIP_VISIBLE(Blip blip, BOOL toggle) { invoke<void>(0x9318D3D2, blip, toggle); } // 0x9318D3D2
	static BOOL IS_BLIP_VISIBLE(Blip blip) { return invoke<BOOL>(0x1E7A6623, blip); } // 0x1E7A6623
	static BOOL IS_BLIP_VALID(Blip blip) { return invoke<BOOL>(0xDCC10BA9, blip); } // 0xDCC10BA9
	static void REMOVE_BLIP(Blip blip) { invoke<void>(0xD8C3C1CD, blip); } // 0xD8C3C1CD
	static Blip GET_BLIP_ON_ACTOR(Actor actor) { return invoke<Blip>(0x1449EE9E, actor); } // 0x1449EE9E
	static Blip GET_BLIP_ON_OBJECT(Object object) { return invoke<Blip>(0xE3E30992, object); } // 0xE3E30992
	static int GET_BLIP_ICON(Blip blip) { return invoke<int>(0xEE4F4B7D, blip); } // 0xEE4F4B7D
	static int SET_CURRENT_MAP(Any p0) { return invoke<int>(0x014C7C29, p0); } // 0x014C7C29
	static void SET_STAMINA_BLINK(Any p0) { invoke<void>(0x39F2E5F1, p0); } // 0x39F2E5F1
	static void SET_DEADEYE_BLINK(Any p0) { invoke<void>(0xA543B120, p0); } // 0xA543B120
	static void SET_HUD_MAP_SCALE_WALK(Any p0) { invoke<void>(0x7FF20D84, p0); } // 0x7FF20D84
	static void SET_HUD_MAP_SCALE_DRIVE(Any p0) { invoke<void>(0x364450B1, p0); } // 0x364450B1
	static void SET_HUD_MAP_SCALE_OVERRIDE(Any p0, Any p1) { invoke<void>(0xB4614D11, p0, p1); } // 0xB4614D11
	static Any GET_RADAR_RADIUS() { return invoke<Any>(0x6B33CBCC); } // 0x6B33CBCC
	static void ABORT_HUD_MAP_SCALE_OVERRIDE() { invoke<void>(0x33CE49C9); } // 0x33CE49C9
	static int IS_HUD_MAP_SCALE_OVERRIDE_SET() { return invoke<int>(0x1D85FB58); } // 0x1D85FB58
	static void _0x2148AC15(Any p0, Any p1) { invoke<void>(0x2148AC15, p0, p1); } // 0x2148AC15
	static void _0x444C3C32(Any p0, Any p1, Any p2) { invoke<void>(0x444C3C32, p0, p1, p2); } // 0x444C3C32
	static void SET_BLIP_HUDMAP_ONLY(Blip blip, BOOL toggle) { invoke<void>(0x1E98AFEC, blip, toggle); } // 0x1E98AFEC
	static void SET_BLIP_PAUSEMAP_ONLY(Blip blip, BOOL toggle) { invoke<void>(0xFF3DB575, blip, toggle); } // 0xFF3DB575
	static int GET_BLIP_IMPAIRMENT_MASK(Blip blip) { return invoke<int>(0xD76F1E9A, blip); } // 0xD76F1E9A
	static void SET_BLIP_IMPAIRMENT_MASK(Blip blip, int p1) { invoke<void>(0xBC05EBB3, blip, p1); } // 0xBC05EBB3
	static void SET_BLIP_MAX_DISTANCE(Blip blip, float maxDistance) { invoke<void>(0xCE79F8E2, blip, maxDistance); } // 0xCE79F8E2
	static void SET_BLIP_MIN_DISTANCE(Blip blip, float minDistance) { invoke<void>(0xFBA76D7E, blip, minDistance); } // 0xFBA76D7E
	static void _SET_BLIP_HEIGHT_ENABLED(Blip blip, BOOL toggle) { invoke<void>(0x6077F3AE, blip, toggle); } // 0x6077F3AE
	static void SET_BLIP_NAME(Blip blip, const char* name) { invoke<void>(0xDC249B12, blip, name); } // 0xDC249B12
	static void CLEAR_REGIONS() { invoke<void>(0xB1DAEF0C); } // 0xB1DAEF0C
	static int APPEND_REGION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0x95666EE0, p0, p1, p2, p3, p4, p5, p6); } // 0x95666EE0
	static void SET_REGION_VISITED(Any p0, Any p1) { invoke<void>(0x970AC1F7, p0, p1); } // 0x970AC1F7
	static int IS_HUD_MAP_DRAW_ENABLED() { return invoke<int>(0xF5B7B208); } // 0xF5B7B208
	static void SET_HUD_MAP_DRAW_ENABLED(Any p0) { invoke<void>(0xA094152A, p0); } // 0xA094152A
	static void SET_HUD_MAP_DRAW_ENABLED_TIMED(Any p0, Any p1, Any p2) { invoke<void>(0x0DFF578A, p0, p1, p2); } // 0x0DFF578A
	static int IS_HUD_MAP_VISIBLE() { return invoke<int>(0xCE043618); } // 0xCE043618
	static void SET_RADAR_TILES_VISIBLE(Any p0) { invoke<void>(0x48DB367D, p0); } // 0x48DB367D
	static void HUD_SET_SHOOT_BLIP_MAX_DISTANCE(Any p0) { invoke<void>(0x4FCE7B9D, p0); } // 0x4FCE7B9D
	static void HUD_SET_SHOOT_BLIP_ENABLED_FOR_ACTOR(Any p0, Any p1) { invoke<void>(0x14585073, p0, p1); } // 0x14585073
	static void HUD_CLEAR_SHOOT_BLIP_ICON_FOR_ACTOR(Any p0) { invoke<void>(0x5EA2E02D, p0); } // 0x5EA2E02D
	static int HUD_GET_SHOOT_BLIP_ICON_FOR_ACTOR(Any p0) { return invoke<int>(0xE78A0469, p0); } // 0xE78A0469
	static void HUD_SET_SHOOT_BLIP_ICON_FOR_ACTOR(Any p0, Any p1) { invoke<void>(0x02755628, p0, p1); } // 0x02755628
	static void SET_STAT_MESSAGE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12) { invoke<void>(0x73DA6AF1, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0x73DA6AF1
	static void CLEAR_STAT_MESSAGE() { invoke<void>(0x906E0138); } // 0x906E0138
	static int IS_STAT_MESSAGE_SHOWING() { return invoke<int>(0x919142BE); } // 0x919142BE
	static void HUD_TIMER_DISPLAY(Any p0) { invoke<void>(0x149F9E46, p0); } // 0x149F9E46
	static int HUD_TIMER_GET() { return invoke<int>(0x1C6919EF); } // 0x1C6919EF
	static int HUD_TIMER_SET(float p0) { return invoke<int>(0xB6A24203, p0); } // 0xB6A24203
	static int HUD_TIMER_COUNTUP() { return invoke<int>(0x2395C147); } // 0x2395C147
	static void HUD_TIMER_COUNTDOWN(Any p0) { invoke<void>(0xF4209CCC, p0); } // 0xF4209CCC
	static void HUD_TIMER_PAUSE() { invoke<void>(0x3383E839); } // 0x3383E839
	static int HUD_TIMER_UNPAUSE() { return invoke<int>(0x983A7E4E); } // 0x983A7E4E
	static int WANTEDFX_ENABLED(Any p0) { return invoke<int>(0x31A55281, p0); } // 0x31A55281
	static int WANTEDFX_SET_LEVEL(float p0) { return invoke<int>(0x651C1FC2, p0); } // 0x651C1FC2
	static void HUD_COUNTER_DISPLAY(Any p0) { invoke<void>(0x9A35DFC6, p0); } // 0x9A35DFC6
	static void HUD_COUNTER_SET(Any p0) { invoke<void>(0x7D94675D, p0); } // 0x7D94675D
	static void HUD_ENABLE(BOOL toggle) { invoke<void>(0x0C180A3F, toggle); } // 0x0C180A3F
	static void HUD_SET_FADE_COLOR(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x4DA5F502, p0, p1, p2, p3); } // 0x4DA5F502
	static void HUD_FADE_OUT(Any p0, Any p1, Any p2) { invoke<void>(0x52963366, p0, p1, p2); } // 0x52963366
	static void HUD_FADE_TO_LOADING_SCREEN() { invoke<void>(0xB0B4296A); } // 0xB0B4296A
	static void HUD_FADE_IN(Any p0, Any p1) { invoke<void>(0xF90F6C51, p0, p1); } // 0xF90F6C51
	static int HUD_FADE_IN_NOW(Any p0, Any p1, Any p2) { return invoke<int>(0x7E4A92CF, p0, p1, p2); } // 0x7E4A92CF
	static int HUD_IS_FADED() { return invoke<int>(0x4EFFFC06); } // 0x4EFFFC06
	static int HUD_IS_FADING() { return invoke<int>(0xE5CC6F08); } // 0xE5CC6F08
	static int UI_SHOW_MISSION_LOADINGSCREEN(Any p0) { return invoke<int>(0xC6E36B1D, p0); } // 0xC6E36B1D
	static int UI_SHOW_RANDOM_LOADINGSCREEN() { return invoke<int>(0xEF270DC9); } // 0xEF270DC9
	static void FLASH_INTRO_SHUTDOWN() { invoke<void>(0x18346D88); } // 0x18346D88
	static void FLASH_INTRO_FADE_LOGO(Any p0) { invoke<void>(0xBB2EABF9, p0); } // 0xBB2EABF9
	static void FLASH_INTRO_FADE_PRESS_START(Any p0) { invoke<void>(0x9E6D7105, p0); } // 0x9E6D7105
	static int FLASH_INTRO_ARE_LEGALS_COMPLETED() { return invoke<int>(0x82A290D4); } // 0x82A290D4
	static int MOVIE_PLAYER_STOP_MOVIE() { return invoke<int>(0x0C197810); } // 0x0C197810
	static int UI_IS_SHOWING_DIALOG() { return invoke<int>(0xC64DF45D); } // 0xC64DF45D
	static void UI_TRANSITION_TO(Any p0) { invoke<void>(0xD0F2D2B6, p0); } // 0xD0F2D2B6
	static int UI_GET_REBOOT_REASON(Any p0) { return invoke<int>(0x111554E2, p0); } // 0x111554E2
	static void UI_SEND_EVENT(Any p0) { invoke<void>(0xB58825F5, p0); } // 0xB58825F5
	static void UI_ENTER(const char* uiLayer) { invoke<void>(0x594F2657, uiLayer); } // 0x594F2657
	// PC only
	static Any _0x8A8BDCF9(Any p0) { return invoke<Any>(0x8A8BDCF9, p0); } // 0x8A8BDCF9
	static void CLEAR_NEWSPAPER() { invoke<void>(0x4486E8C7); } // 0x4486E8C7
	static void SHOW_NEWSPAPER(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x175CD937, p0, p1, p2, p3); } // 0x175CD937
	static void SET_NEWSPAPER_INFO(Any p0, Any p1) { invoke<void>(0x47D2DE08, p0, p1); } // 0x47D2DE08
	static void SET_GPS_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { invoke<void>(0xD82F910C, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xD82F910C
	static int IS_GPS_RECOMPUTE(Any p0) { return invoke<int>(0xAA322DFC, p0); } // 0xAA322DFC
	static void CLEAR_GPS_PATH(Any p0) { invoke<void>(0xD077D8B6, p0); } // 0xD077D8B6
	static int GET_USER_DEFINED_WAYPOINT(Vector3* waypointCoords) { return invoke<int>(0x82F63365, waypointCoords); } // 0x82F63365
	static BOOL IS_USER_DEFINED_WAYPOINT_CLEARED() { return invoke<BOOL>(0x34711B59); } // 0x34711B59
	static int FIND_TRAFFIC_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xA5BDC21D, p0, p1, p2, p3, p4, p5); } // 0xA5BDC21D
	static int IS_TELEPORTATION(Any p0) { return invoke<int>(0x3E758743, p0); } // 0x3E758743
	static int GET_LAST_NEAREST_POINT(Any p0, Any p1) { return invoke<int>(0xB6E791F6, p0, p1); } // 0xB6E791F6
	static int HUD_SET_MINIGAME_TYPE_LAYOUT(Any p0) { return invoke<int>(0xD12802AF, p0); } // 0xD12802AF
	static void HUD_STAMINA_OVERRIDE(Any p0, Any p1, Any p2) { invoke<void>(0xADBD44F6, p0, p1, p2); } // 0xADBD44F6
	static int UI_CHEAT_GET_VALUE(Any p0) { return invoke<int>(0x94F5E63F, p0); } // 0x94F5E63F
	static void UI_CHEAT_SET_VALUE(Any p0, Any p1) { invoke<void>(0x9E88643A, p0, p1); } // 0x9E88643A
	static int UI_CHEAT_GET_STATE(Any p0) { return invoke<int>(0x01309706, p0); } // 0x01309706
	static void UI_CHEAT_SET_STATE(Any p0, Any p1) { invoke<void>(0x7D6A8D4A, p0, p1); } // 0x7D6A8D4A
	static void UI_CHEAT_SET_CODE(Any p0, Any p1) { invoke<void>(0x90CD8795, p0, p1); } // 0x90CD8795
	static void UI_SET_HAS_CHEATED(Any p0) { invoke<void>(0x7D0EFDD8, p0); } // 0x7D0EFDD8
	static int UI_HAS_CHEATED() { return invoke<int>(0xBAB151CB); } // 0xBAB151CB
	static void UI_DUMP_MESSAGE_QUEUE_TO_NOTES(Any p0) { invoke<void>(0x714D6F72, p0); } // 0x714D6F72
	static void UI_CLEAR_MESSAGE_QUEUE(Any p0) { invoke<void>(0x64DDB95D, p0); } // 0x64DDB95D
	static int UI_IS_MESSAGE_QUEUE_EMPTY(Any p0) { return invoke<int>(0x941FC468, p0); } // 0x941FC468
	static void UI_REMOVE_MESSAGE_IN_QUEUE(Any p0, Any p1, Any p2) { invoke<void>(0x7725001B, p0, p1, p2); } // 0x7725001B
	static void HUD_SET_CENTER_BLIP_SHOWN(Any p0) { invoke<void>(0xEB214384, p0); } // 0xEB214384
	static BOOL IS_DLC_ZOMBIEPACK_ACTIVE() { return invoke<BOOL>(0x6CC9CCE7); } // 0x6CC9CCE7
	static BOOL IS_HARDCORE_ACTIVE() { return invoke<BOOL>(0x8701F1F6); } // 0x8701F1F6
	static int _HUD_SET_ZOMBIE_THEME() { return invoke<int>(0x3842B89F); } // 0x3842B89F
	static int _HUD_SET_RED_DEAD_THEME() { return invoke<int>(0xFDB5FC03); } // 0xFDB5FC03
}

namespace INDICATOR
{
	static void SET_INDICATOR_DRAW(Any p0, Any p1) { invoke<void>(0x8E387228, p0, p1); } // 0x8E387228
}

namespace INTERSECTION
{
	static Any FIND_INTERSECTION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<Any>(0x9CD3AD70, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x9CD3AD70
	static Any FIND_GROUND_INTERSECTION(Vector3* inCoords, float startHeight, Vector3* outCoords, int* p3) { return invoke<Any>(0x6AD8EEAF, inCoords, startHeight, outCoords, p3); } // 0x6AD8EEAF
	static int FIND_GROUND_INTERSECTION_WITH_MATERIAL(Vector3* inCoords, float startHeight, Vector3* outCoords, int* p3, int* p4) { return invoke<int>(0x77964B0C, inCoords, startHeight, outCoords, p3, p4); } // 0x77964B0C
	static Any FIND_WATER_INTERSECTION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<Any>(0x4F193BE4, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x4F193BE4
	static Any GET_MATERIAL_AT_VECTOR(Vector3* p0) { return invoke<Any>(0x5219B7D0, p0); } // 0x5219B7D0
	static Any GET_ACTOR_GROUND_MATERIAL(Any p0) { return invoke<Any>(0x451A8EF2, p0); } // 0x451A8EF2
	static Any IS_POSITION_INDOORS(Any p0) { return invoke<Any>(0x1E81DB60, p0); } // 0x1E81DB60
}

namespace INVENTORY
{
	static int ADD_ITEM(const char* ItemName, Actor actor, Any p0) { return invoke<int>(0xBAA5D41B, ItemName, actor, p0); } // 0xBAA5D41B
	static void ADD_ITEM_BY_CRC(Actor actor, Any p1) { invoke<void>(0xAB2D8A68, actor, p1); } // 0xAB2D8A68
	static Any HAS_INVENTORY_COMPONENT() { return invoke<Any>(0x7609A328); } // 0x7609A328
	static int GET_ITEM_COUNT(const char* ItemName, Actor actor) { return invoke<int>(0xD91ED898, ItemName, actor); } // 0xD91ED898
	static Any GET_ITEM_COUNT_BY_CRC(Any p0) { return invoke<Any>(0x4BB2BC20, p0); } // 0x4BB2BC20
	static int GET_MAX_ITEM_COUNT(const char* ItemName) { return invoke<int>(0xF52BA99F, ItemName); } // 0xF52BA99F
	static void SET_MAX_ITEM_COUNT(const char* ItemName, int amount) { invoke<void>(0x0E712FCB, ItemName, amount); } // 0x0E712FCB
	static void ADD_ACCESSORY(const char* ItemName, Actor actor, int p2) { invoke<void>(0x5ACC0171, ItemName, actor, p2); } // 0x5ACC0171
	static void ADD_ACCESSORY_BY_CRC(Actor actor, Any p1) { invoke<void>(0xF750D150, actor, p1); } // 0xF750D150
	static void ADD_COLLECTABLE(const char* ItemName, Actor actor, int p2) { invoke<void>(0xF05D1566, ItemName, actor, p2); } // 0xF05D1566
	static void REMOVE_COLLECTABLE(const char* ItemName, Actor actor) { invoke<void>(0x5889EBB7, ItemName, actor); } // 0x5889EBB7
	static void READY_ITEM(const char* ItemName, Actor actor) { invoke<void>(0x2B00A643, ItemName, actor); } // 0x2B00A643
	static BOOL HAS_ITEM(const char* ItemName, Actor actor) { return invoke<BOOL>(0xB426267D, ItemName, actor); } // 0xB426267D
	static BOOL HAS_ACCESSORY(const char* ItemName, Actor actor) { return invoke<BOOL>(0x0C38F697, ItemName, actor); } // 0x0C38F697
	static void DELETE_ITEM(Any p0, Any p1, Any p2) { invoke<void>(0xEFECF4F9, p0, p1, p2); } // 0xEFECF4F9
	static void DELETE_ACCESSORY(const char* ItemName, Actor actor) { invoke<void>(0xD6A9C9D4, ItemName, actor); } // 0xD6A9C9D4
	static Any ACTOR_GET_ITEM_CRC_AT_INDEX(Any p0) { return invoke<Any>(0x7BF75BCE, p0); } // 0x7BF75BCE
	static Any ACTOR_GET_ACCESSORY_CRC_AT_INDEX(Any p0) { return invoke<Any>(0x7F4D5AE0, p0); } // 0x7F4D5AE0
	static Any ACTOR_GET_COLLECTABLE_CRC_AT_INDEX(Any p0) { return invoke<Any>(0x608DCAEF, p0); } // 0x608DCAEF
	static Any IS_ITEM_WEAPON_BY_CRC() { return invoke<Any>(0x50C0E83F); } // 0x50C0E83F
	static int GET_ITEM_IN_HAND_EQUIPSLOT(Actor actor) { return invoke<int>(0x3A899B0E, actor); } // 0x3A899B0E
	static int GET_ITEM_EQUIPSLOT(int itemEnum) { return invoke<int>(0x0E0EFB13, itemEnum); } // 0x0E0EFB13
	static void ACTOR_DISABLE_WEAPON_RENDER(Actor actor, Any p1) { invoke<void>(0x5E38B33C, actor, p1); } // 0x5E38B33C
	static void ACTOR_FORCE_WEAPON_RENDER(Actor actor, Any p1) { invoke<void>(0x1511D111, actor, p1); } // 0x1511D111
	static BOOL IS_WEAPON_DRAWN(Actor actor) { return invoke<BOOL>(0xAB5FB5AC, actor); } // 0xAB5FB5AC
	// weaponEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eWeapon
	static void GIVE_WEAPON_TO_ACTOR(Actor actor, int weaponEnum, float ammoCount, BOOL p3, Any p4) { invoke<void>(0x6AA0EAF2, actor, weaponEnum, ammoCount, p3, p4); } // 0x6AA0EAF2
	static void ACTOR_SET_NEXT_WEAPON(Any p0, Any p1, Any p2) { invoke<void>(0xBFD6D55F, p0, p1, p2); } // 0xBFD6D55F
	static void ACTOR_PUT_WEAPON_IN_HAND(Actor actor, int weaponEnum, int p2) { invoke<void>(0x8F4B473D, actor, weaponEnum, p2); } // 0x8F4B473D
	static BOOL ACTOR_HAS_WEAPON_IN_HAND(Actor actor, int weaponEnum) { return invoke<BOOL>(0x09950C1B, actor, weaponEnum); } // 0x09950C1B
	static Any ACTOR_PUT_ITEM_AWAY() { return invoke<Any>(0x13A63AA7); } // 0x13A63AA7
	static Any ACTOR_HAS_WEAPON_SET_AS_NEXT(Any p0, Any p1) { return invoke<Any>(0x78145528, p0, p1); } // 0x78145528
	static Any ACTOR_SET_NEXT_EQUIP_SLOT_FROM_WEAPON_ENUM() { return invoke<Any>(0x5CAFCBD4); } // 0x5CAFCBD4
	static Any ACTOR_SET_NEXT_EQUIP_SLOT() { return invoke<Any>(0x3417766E); } // 0x3417766E
	static Any ACTOR_GET_NEXT_EQUIP_SLOT() { return invoke<Any>(0xCC02BBD3); } // 0xCC02BBD3
	static Any ACTOR_GET_CURRENT_EQUIP_SLOT() { return invoke<Any>(0xA8040D70); } // 0xA8040D70
	static Any ACTOR_GET_BEST_WEAPON_OF_TYPE(Any p0, Any p1) { return invoke<Any>(0x659532FB, p0, p1); } // 0x659532FB
	static int DELETE_WEAPON_FROM_ACTOR(Actor actor, int weaponEnum) { return invoke<int>(0xCB017277, actor, weaponEnum); } // 0xCB017277
	static int GET_WEAPON_EQUIPPED(Actor actor, int weaponEnum) { return invoke<int>(0x42C0FAAA, actor, weaponEnum); } // 0x42C0FAAA
	static Any GET_WEAPON_IS_EXTERNALLY_CREATED(Any p0) { return invoke<Any>(0x6262DC5E, p0); } // 0x6262DC5E
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eWeapon
	static int GET_WEAPON_IN_HAND(Actor actor) { return invoke<int>(0xA4B2016D, actor); } // 0xA4B2016D
	static Any GET_WEAPON_IN_HAND_CRC(Any p0) { return invoke<Any>(0x0CDD6F94, p0); } // 0x0CDD6F94
	static Any GET_WEAPON_IN_HAND_NAME(Any p0) { return invoke<Any>(0x612066E5, p0); } // 0x612066E5
	static Any GET_WEAPON_ENUM_FROM_CRC(Any p0) { return invoke<Any>(0x2776B0F5, p0); } // 0x2776B0F5
	static Any ACTOR_USE_ITEM_NOW(Any p0) { return invoke<Any>(0xFD46B231, p0); } // 0xFD46B231
	static void SET_EQUIP_SLOT_ENABLED(Actor actor, int itemEquipSlot, BOOL enabled) { invoke<void>(0xE6604B39, actor, itemEquipSlot, enabled); } // 0xE6604B39
	static BOOL GET_EQUIP_SLOT_ENABLED(Actor actor, int itemEquipSlot) { return invoke<BOOL>(0xA3E18517, actor, itemEquipSlot); } // 0xA3E18517
	static void EQUIP_ACCESSORY(Actor actor, int accessoryEnum, int p2) { invoke<void>(0x5A80659D, actor, accessoryEnum, p2); } // 0x5A80659D
	static void DEEQUIP_ACCESSORY(Actor actor, int accessoryEnum) { invoke<void>(0xF7696B8B, actor, accessoryEnum); } // 0xF7696B8B
	static BOOL HAS_ACCESSORY_ENUM(Actor actor, int accessoryEnum) { return invoke<BOOL>(0x9B958A25, actor, accessoryEnum); } // 0x9B958A25
	static BOOL IS_ACCESSORY_EQUIPPPED(Actor actor, int accessoryEnum) { return invoke<BOOL>(0xE094DB31, actor, accessoryEnum); } // 0xE094DB31
	static void DROP_ACCESSORY_ENUM(Actor actor, int accessoryEnum) { invoke<void>(0x7FDDF876, actor, accessoryEnum); } // 0x7FDDF876
	static void ACTOR_SET_WEAPON_AMMO(Actor actor, int weaponEnum, Any p2) { invoke<void>(0x8266C617, actor, weaponEnum, p2); } // 0x8266C617
	static Any ACTOR_SET_WEAPON_AMMO_BY_CRC(Any p0) { return invoke<Any>(0xB008EF49, p0); } // 0xB008EF49
	static BOOL ACTOR_HAS_WEAPON(Actor actor, int weaponEnum) { return invoke<BOOL>(0x0D47CFBD, actor, weaponEnum); } // 0x0D47CFBD
	static void ACTOR_ADD_WEAPON_AMMO(Actor actor, int weaponEnum, int ammo) { invoke<void>(0xCC69DCC1, actor, weaponEnum, ammo); } // 0xCC69DCC1
	static float ACTOR_GET_WEAPON_AMMO(Actor actor, int weaponEnum) { return invoke<float>(0x43DEDFAE, actor, weaponEnum); } // 0x43DEDFAE
	static Any ACTOR_DISCARD_WEAPON_AMMO(Any p0) { return invoke<Any>(0xEEC81873, p0); } // 0xEEC81873
	// variableMesh: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eVariableMesh
	static BOOL ACTOR_HAS_VARIABLE_MESH(Actor actor, int variableMesh) { return invoke<BOOL>(0xA091179F, actor, variableMesh); } // 0xA091179F
	// returns ammo enum from weaponEnum. https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eWeapon
	static int GET_AMMOENUM_FOR_WEAPONENUM(int weaponEnum) { return invoke<int>(0x17883570, weaponEnum); } // 0x17883570
	// returns weapon enum from ammoEnum. https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAmmoEnum
	static int GET_WEAPONENUM_FOR_AMMOENUM(Actor actor, int ammoEnum) { return invoke<int>(0xA8F64D32, actor, ammoEnum); } // 0xA8F64D32
	static void SET_WEAPON_GOLD(Actor actor, int weaponEnum, BOOL toggle) { invoke<void>(0xAE44869D, actor, weaponEnum, toggle); } // 0xAE44869D
	static BOOL GET_WEAPON_GOLD(Actor actor, int weaponEnum) { return invoke<BOOL>(0x6DBD1DDB, actor, weaponEnum); } // 0x6DBD1DDB
	static BOOL IS_GOLDEN_GUNS_ON() { return invoke<BOOL>(0x80B30545); } // 0x80B30545
	static void FIRE_PROJECTILE(Actor actor, int weapGroup, float p2, Vector3* origin, Vector3* target) { invoke<void>(0x195A4286, actor, weapGroup, p2, origin, target); } // 0x195A4286
	// ammoEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAmmoEnum
	static int ACTOR_ADD_INV_AMMO(Actor actor, int ammoEnum, float ammoAmount, int p3, BOOL usePrintStat) { return invoke<int>(0x98B3ABFA, actor, ammoEnum, ammoAmount, p3, usePrintStat); } // 0x98B3ABFA
	static void ACTOR_SET_INV_AMMO(Any p0) { invoke<void>(0x4372593E, p0); } // 0x4372593E
	static void ACTOR_SET_INV_AMMO_MAX_AMOUNT(Any p0, Any p1) { invoke<void>(0x6ADAAD87, p0, p1); } // 0x6ADAAD87
	static void ACTOR_SET_INV_AMMO_INFINITE(Actor actor, int weaponGroup, BOOL toggle) { invoke<void>(0x4FE2B586, actor, weaponGroup, toggle); } // 0x4FE2B586
	// ammoEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAmmoEnum
	static float ACTOR_GET_INV_AMMO(Actor actor, int ammoEnum, BOOL p2) { return invoke<float>(0xE224AC6F, actor, ammoEnum, p2); } // 0xE224AC6F
	// ammoEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAmmoEnum
	static float ACTOR_GET_INV_AMMO_MAX_AMOUNT(Actor actor, int ammoEnum) { return invoke<float>(0x7AB368CF, actor, ammoEnum); } // 0x7AB368CF
	static BOOL ACTOR_GET_INV_AMMO_INFINITE(Actor actor, Any p1) { return invoke<BOOL>(0xC666B987, actor, p1); } // 0xC666B987
	static Any ACTOR_SHOULD_DROP_ITEMS_ON_DEATH(Any p0) { return invoke<Any>(0xBE39208A, p0); } // 0xBE39208A
	static Any ACTOR_SET_DROP_ITEM_ON_DEATH_ENUMERATED(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0xBC46E3E1, p0, p1, p2, p3); } // 0xBC46E3E1
	static Any CREATE_WEAPON_PICKUP(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<Any>(0xBF0235B0, p0, p1, p2, p3, p4, p5); } // 0xBF0235B0
	static void REMOVE_ALL_PICKUPS() { invoke<void>(0x04BF00F0); } // 0x04BF00F0
	static int GET_NUM_WEAPONS_IN_INVENTORY(Actor actor) { return invoke<int>(0x118D085E, actor); } // 0x118D085E
	static int GET_NUM_ACCESSORIES_IN_INVENTORY(Actor actor) { return invoke<int>(0x78A3CD3D, actor); } // 0x78A3CD3D
	static int GET_NUM_COLLECTABLES_IN_INVENTORY(Actor actor) { return invoke<int>(0x2C23CBE7, actor); } // 0x2C23CBE7
	static void DELETE_ALL_WEAPONS_FROM_ACTOR(Actor actor) { invoke<void>(0xD695F857, actor); } // 0xD695F857
	static void DELETE_ALL_ACCESSORIES_FROM_ACTOR(Actor actor) { invoke<void>(0x96AC812B, actor); } // 0x96AC812B
	static void DELETE_ALL_INVENTORY_FROM_ACTOR(Actor actor) { invoke<void>(0x5AEB2E4F, actor); } // 0x5AEB2E4F
	static Any SETUP_ASSOCIATED_FRAGMENTS(Any p0) { return invoke<Any>(0x3E8E7D7B, p0); } // 0x3E8E7D7B
	static Any GRINGOITEM_GET_ACTION() { return invoke<Any>(0x7BF01CCB); } // 0x7BF01CCB
	static Any GRINGOITEM_CLEAR_FOR_NEW_USE(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<Any>(0x8EA46104, p0, p1, p2, p3, p4); } // 0x8EA46104
	static Any SET_PICKUPS_ARENT_NEW() { return invoke<Any>(0xD2A140BC); } // 0xD2A140BC
}

namespace JOURNAL
{
	static int SET_EXCLUSIVE_JOURNAL_ID(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x6398AF9A, p0, p1, p2, p3); } // 0x6398AF9A
	static void RESET_EXCLUSIVE_JOURNAL_ID() { invoke<void>(0x45E34464); } // 0x45E34464
	static int TOGGLE_COOP_JOURNAL_UI(int result, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x44A1ED5C, result, p1, p2, p3, p4); } // 0x44A1ED5C
	static void TOGGLE_JOURNAL_UI(int journalId, BOOL isVisible) { invoke<void>(0xE6726EF4, journalId, isVisible); } // 0xE6726EF4
	static int GET_JOURNAL_ENTRY(const char* entryName) { return invoke<int>(0xC450C870, entryName); } // 0xC450C870
	static int CREATE_JOURNAL_ENTRY(const char* entryName, int entryType, int entryStatus, const char* entryText) { return invoke<int>(0x761FD935, entryName, entryType, entryStatus, entryText); } // 0x761FD935
	static int CREATE_JOURNAL_ENTRY_BY_HASH(int journal, int entryType, int entryStatus, const char* entryText) { return invoke<int>(0x619F1C3D, journal, entryType, entryStatus, entryText); } // 0x619F1C3D
	static BOOL IS_JOURNAL_ENTRY_IN_LIST(int entryId, BOOL checkVisibility) { return invoke<BOOL>(0xC17FE40A, entryId, checkVisibility); } // 0xC17FE40A
	static int GET_NUM_JOURNAL_ENTRIES_IN_LIST(BOOL includeHidden) { return invoke<int>(0x3E84D766, includeHidden); } // 0x3E84D766
	static int GET_JOURNAL_ENTRY_IN_LIST(int entryIndex, BOOL includeHidden) { return invoke<int>(0x49B02E18, entryIndex, includeHidden); } // 0x49B02E18
	static void PREPEND_JOURNAL_ENTRY(int entryId, BOOL markAsUnread) { invoke<void>(0x87DC7F5B, entryId, markAsUnread); } // 0x87DC7F5B
	static int APPEND_JOURNAL_ENTRY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x9C40CFAB, p0, p1, p2, p3); } // 0x9C40CFAB
	static int REMOVE_JOURNAL_ENTRY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x01BF35BD, p0, p1, p2, p3); } // 0x01BF35BD
	static int CLEAR_JOURNAL_ENTRY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xB8B7B818, p0, p1, p2, p3); } // 0xB8B7B818
	static int PREPEND_JOURNAL_ENTRY_DETAIL(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x81470AFE, p0, p1, p2, p3); } // 0x81470AFE
	static int APPEND_JOURNAL_ENTRY_DETAIL(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xF5DFD684, p0, p1, p2, p3); } // 0xF5DFD684
	static int CLEAR_JOURNAL_ENTRY_DETAIL_LIST(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xD0567D03, p0, p1, p2, p3); } // 0xD0567D03
	static int GET_JOURNAL_ENTRY_NUM_DETAILS(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xCF3A69FC, p0, p1, p2, p3); } // 0xCF3A69FC
	static int GET_JOURNAL_ENTRY_DETAIL_HASH_BY_INDEX(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x1630EFC5, p0, p1, p2, p3); } // 0x1630EFC5
	static int GET_JOURNAL_ENTRY_DETAIL_STYLE_BY_HASH(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xEBC9C2FD, p0, p1, p2, p3, p4); } // 0xEBC9C2FD
	static int SET_JOURNAL_ENTRY_DETAIL_STYLE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x539D0404, p0, p1, p2, p3); } // 0x539D0404
	static int SET_JOURNAL_ENTRY_DETAIL_STYLE_BY_HASH(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x5209C0C0, p0, p1, p2, p3); } // 0x5209C0C0
	static BOOL IS_JOURNAL_ENTRY_TARGETED(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0xF0C4E96F, p0, p1, p2, p3); } // 0xF0C4E96F
	static int GET_JOURNAL_ENTRY_TYPE(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xF6FEC269, p0, p1, p2, p3, p4); } // 0xF6FEC269
	static BOOL IS_JOURNAL_ENTRY_UPDATED(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x078F9B43, p0, p1, p2, p3); } // 0x078F9B43
	static int GET_JOURNAL_ENTRY_MISC_FLAG(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x8020011E, p0, p1, p2, p3); } // 0x8020011E
	static int GET_TARGETED_JOURNAL_ENTRY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x8A9B8F0C, p0, p1, p2, p3); } // 0x8A9B8F0C
	static int TARGET_JOURNAL_ENTRY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xC3DC9490, p0, p1, p2, p3); } // 0xC3DC9490
	static int SET_JOURNAL_ENTRY_UPDATED(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xCD4633BD, p0, p1, p2, p3); } // 0xCD4633BD
	static int SET_JOURNAL_ENTRY_TROPHY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x5CB9D376, p0, p1, p2, p3); } // 0x5CB9D376
	static int DEACTIVATE_JOURNAL_ENTRY(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x196A1EDE, p0, p1, p2, p3); } // 0x196A1EDE
	static int SET_JOURNAL_ENTRY_PROGRESS(Any p0, Any p1, Any p2, Any p3, float p4) { return invoke<int>(0x5DC073DE, p0, p1, p2, p3, p4); } // 0x5DC073DE
	static float GET_JOURNAL_ENTRY_PROGRESS(Any p0, Any p1, Any p2, Any p3) { return invoke<float>(0xF2C1D690, p0, p1, p2, p3); } // 0xF2C1D690
	static int SET_JOURNAL_ENTRY_DISALLOW_TRACKING(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xF7687D41, p0, p1, p2, p3); } // 0xF7687D41
	static BOOL GET_JOURNAL_ENTRY_DISALLOW_TRACKING(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x93CA45DE, p0, p1, p2, p3); } // 0x93CA45DE
	static int SET_JOURNAL_ENTRY_CURRENT_OBJECTIVE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x2AA8E2FA, p0, p1, p2, p3); } // 0x2AA8E2FA
	static int GET_LAST_NOTE_OBJECTIVE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xDC28C12F, p0, p1, p2, p3); } // 0xDC28C12F
	static int APPEND_JOURNAL_NOTE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x2B969E73, p0, p1, p2, p3); } // 0x2B969E73
}

namespace LASSO
{
	static Any GET_LASSO_TARGET(Any p0) { return invoke<Any>(0xAA364907, p0); } // 0xAA364907
	static Any GET_LASSO_USER(Any p0) { return invoke<Any>(0x3B775037, p0); } // 0x3B775037
	static Any GET_HOGTIED_MASTER(Any p0) { return invoke<Any>(0x1580F3BF, p0); } // 0x1580F3BF
	static Any GET_ATTACHED_HOGTIE_VICTIM(Any p0) { return invoke<Any>(0xF68C926F, p0); } // 0xF68C926F
	static void DETACH_LASSO(Any p0) { invoke<void>(0x32030E7C, p0); } // 0x32030E7C
	static void FREE_FROM_HOGTIE(Any p0) { invoke<void>(0x31AD57FE, p0); } // 0x31AD57FE
	static Any LASSO_EVENT(Any p0) { return invoke<Any>(0x98FAF5D7, p0); } // 0x98FAF5D7
	static Any SET_INTENDED_HOGTIE_MASTER(Any p0) { return invoke<Any>(0xFF5F7D2C, p0); } // 0xFF5F7D2C
	static BOOL IS_ACTOR_BEING_DRAGGED(Actor actor) { return invoke<BOOL>(0x5B792331, actor); } // 0x5B792331
	static BOOL IS_ACTOR_HOGTIED(Actor actor) { return invoke<BOOL>(0xA610DC79, actor); } // 0xA610DC79
	static BOOL IS_ACTOR_IN_HOGTIE(Actor actor) { return invoke<BOOL>(0xB24ADC7C, actor); } // 0xB24ADC7C
	static Any GET_ACTOR_HOGTIE_STATE(Any p0) { return invoke<Any>(0xF45D9723, p0); } // 0xF45D9723
	static void HOGTIE_ACTOR(Any p0) { invoke<void>(0x4440BCA5, p0); } // 0x4440BCA5
	static Any ATTACH_HOGTIE_ACTOR_TO_ACTOR(Any p0) { return invoke<Any>(0xCC04895F, p0); } // 0xCC04895F
	static void SET_HOGTIE_ATTACH_VICTIM(Any p0, Any p1) { invoke<void>(0xFA2B916E, p0, p1); } // 0xFA2B916E
	static void CLEAR_HOGTIE_ATTACH_VICTIM(Any p0, Any p1) { invoke<void>(0xB7A802C2, p0, p1); } // 0xB7A802C2
	static BOOL IS_ACTOR_HOGTIE_ATTACHED(Actor actor) { return invoke<BOOL>(0x16EB367C, actor); } // 0x16EB367C
	static Any IS_HOGTIE_PUTDOWN_OBSTRUCTED(Any p0) { return invoke<Any>(0xBCED635B, p0); } // 0xBCED635B
	static Any IS_HOGTIE_PICKUP_OBSTRUCTED(Any p0) { return invoke<Any>(0x60D10483, p0); } // 0x60D10483
	static Any IS_HOGTIE_CUTFREE_OBSTRUCTED(Any p0) { return invoke<Any>(0x9377291F, p0); } // 0x9377291F
	static Any IS_HOGTIE_HORSE_PICKUP_OBSTRUCTED(Any p0) { return invoke<Any>(0x9634D42E, p0); } // 0x9634D42E
	static Any IMMEDIATELY_LASSO_TARGET(Any p0) { return invoke<Any>(0x8F8EDCCF, p0); } // 0x8F8EDCCF
}

namespace LEASH
{
	static int CREATE_LEASH_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x9BCC06E2, p0, p1, p2, p3, p4, p5); } // 0x9BCC06E2
	static int LEASH_CONSTRAIN(Any p0) { return invoke<int>(0x8EA68EB5, p0); } // 0x8EA68EB5
	static Any LEASH_RESTART(Any p0) { return invoke<Any>(0xE58339B3, p0); } // 0xE58339B3
	static int LEASH_SET_CONSTRAINT_LENGTH(Any p0) { return invoke<int>(0x7F190CA3, p0); } // 0x7F190CA3
	static int LEASH_SET_LEASH_LENGTH(Any p0) { return invoke<int>(0x14BEC6F5, p0); } // 0x14BEC6F5
	static int LEASH_RELEASE_CONSTRAINT(Any p0) { return invoke<int>(0x7A1376B0, p0); } // 0x7A1376B0
	static int LEASH_ATTACH_TO_WORLD(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x0FCDB481, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x0FCDB481
	static int LEASH_ATTACH_TO_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { return invoke<int>(0x35D8B21E, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x35D8B21E
	static int LEASH_ATTACH_TO_FRAGMENT_LOCATOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0xE782EB20, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0xE782EB20
	static int LEASH_ATTACH_TO_OBJECT_BONE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11) { return invoke<int>(0x82A73B3D, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x82A73B3D
	static int LEASH_ATTACH_TO_OBJECT_BONE_VISUAL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11) { return invoke<int>(0x4B67B8BB, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x4B67B8BB
	static int LEASH_SET_LOCATOR_POSITION_VISUAL(Any p0, Any p1, float p2, float p3, float p4) { return invoke<int>(0xC1265E7F, p0, p1, p2, p3, p4); } // 0xC1265E7F
	static int LEASH_DETACH_OBJECT(Any p0) { return invoke<int>(0x951B8DF7, p0); } // 0x951B8DF7
	static int LEASH_IS_BROKEN(Any p0) { return invoke<int>(0x46BE1D43, p0); } // 0x46BE1D43
	static Any LEASH_BREAK(Any p0, Any p1) { return invoke<Any>(0x8640261B, p0, p1); } // 0x8640261B
	static int CREATE_ROPE_FOR_BRIDGE_LEFT(Any p0, Any p1, Any p2) { return invoke<int>(0xC039BBF1, p0, p1, p2); } // 0xC039BBF1
	static int CREATE_ROPE_FOR_BRIDGE_RIGHT(Any p0, Any p1, Any p2) { return invoke<int>(0x51CF9A54, p0, p1, p2); } // 0x51CF9A54
	static int LEASH_STAY_CONSTRAINED(Any p0, Any p1) { return invoke<int>(0x5A72DD49, p0, p1); } // 0x5A72DD49
	static int SET_LEASH_COLLIDES(Any p0, Any p1) { return invoke<int>(0x1A8494E6, p0, p1); } // 0x1A8494E6
}

namespace MINIGAME
{
	static void START_MINIGAME(Any p0) { invoke<void>(0xE8184916, p0); } // 0xE8184916
	static int PUSH_MINIGAME_INPUT(Any p0) { return invoke<int>(0xE2B894D1, p0); } // 0xE2B894D1
	static BOOL IS_MINIGAME_RUNNING() { return invoke<BOOL>(0x117D7E71); } // 0x117D7E71
	static void END_CURRENT_MINIGAME() { invoke<void>(0xCA746CD2); } // 0xCA746CD2
	static int _0x6AAD0420(Any p0, Any p1, float p2, Any p3, Any p4) { return invoke<int>(0x6AAD0420, p0, p1, p2, p3, p4); } // 0x6AAD0420
	static Any _0x655D350B(Any p0, Any p1, Any p2) { return invoke<Any>(0x655D350B, p0, p1, p2); } // 0x655D350B
	static int SET_CURRENT_MINIGAME_INT(Any p0, Any p1) { return invoke<int>(0x0627DDEC, p0, p1); } // 0x0627DDEC
	static int SET_MINIGAME_SCRIPT_OVERRIDE(const char* p0) { return invoke<int>(0x2DC768BB, p0); } // 0x2DC768BB
	static int SET_MINIGAME_WIN_STATE(Any p0) { return invoke<int>(0x8275FDD4, p0); } // 0x8275FDD4
}

namespace MISC
{
	static int CREATE_OBJECT_LOCATOR(Any p0, Any p1) { return invoke<int>(0x11069324, p0, p1); } // 0x11069324
	static int OBJECT_LOCATOR_ATTACH_TO_OBJECT_BONE(Any p0, Any p1, Any p2, float p3, float p4, float p5, float p6, float p7, float p8) { return invoke<int>(0x0B24362F, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x0B24362F
	static int OBJECT_LOCATOR_ATTACH_TO_FRAGMENT_LOCATOR(Any p0, Any p1, Any p2, float p3, float p4, float p5, float p6, float p7, float p8) { return invoke<int>(0xE25F407D, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xE25F407D
	static int OBJECT_LOCATOR_ATTACH_TO_OBJECT(Any p0, Any p1, float p2, float p3, float p4, float p5, float p6, float p7) { return invoke<int>(0xEB33480A, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xEB33480A
	static int OBJECT_LOCATOR_GET_LOCATOR_LOCAL_ORIENTATION(Any p0, Any p1) { return invoke<int>(0x88F7432C, p0, p1); } // 0x88F7432C
	static int OBJECT_LOCATOR_GET_LOCATOR_LOCAL_POSITION(Any p0, Any p1) { return invoke<int>(0x04507DBC, p0, p1); } // 0x04507DBC
}

namespace MIXER
{
	static void DYNAMICMIXER_TRIGGERSTATE(Any p0) { invoke<void>(0xECD8E116, p0); } // 0xECD8E116
	static void DYNAMICMIXER_TRIGGERSTATE_PERSISTENT(Any p0, int* p1) { invoke<void>(0xA82D893C, p0, p1); } // 0xA82D893C
	static void DYNAMICMIXER_DETRIGGERSTATE(Any p0) { invoke<void>(0xF86010D1, p0); } // 0xF86010D1
	static int _DYNAMICMIXER_TRIGGERSTATE_PREDUEL() { return invoke<int>(0xADCC16A2); } // 0xADCC16A2
}

namespace MOTIVE
{
	static int SET_MOTIVE_BY_ENUM(Any p0, Any p1, float p2) { return invoke<int>(0x1BED8493, p0, p1, p2); } // 0x1BED8493
}

namespace MOVIE
{
	// Not in PS4/Switch/PC
	static int WORLD_MOVIE_PLAYER(Any p0) { return invoke<int>(0x92028B49, p0); } // 0x92028B49
	// PS4/Switch/PC only
	static int _START_WORLD_MOVIE() { return invoke<int>(0x7614AEBA); } // 0x7614AEBA
	static int _STOP_WORLD_MOVIE() { return invoke<int>(0x69FC319E); } // 0x69FC319E
	static int _IS_WORLD_MOVIE_PLAYING() { return invoke<int>(0xD036DF91); } // 0xD036DF91
}

namespace NAVMESH
{
	static void STREAMING_IS_MOVABLE_NAV_MESH_RESIDENT(Any p0) { invoke<void>(0x8A0D3339, p0); } // 0x8A0D3339
	static void STREAMING_REQUEST_MOVABLE_NAV_MESH(Any p0) { invoke<void>(0x63334F63, p0); } // 0x63334F63
	static void STREAMING_UNREQUEST_MOVABLE_NAV_MESH(Any p0) { invoke<void>(0xC329E1DB, p0); } // 0xC329E1DB
	static void SET_ACTOR_MOVABLE_NAV_MESH(Any p0) { invoke<void>(0xECEE9E20, p0); } // 0xECEE9E20
}

namespace NAVQUERY
{
	static Any CREATE_NAV_QUERY(Any p0, Any p1) { return invoke<Any>(0xE2F41226, p0, p1); } // 0xE2F41226
	static int NAV_QUERY_IS_DONE(Any p0) { return invoke<int>(0xE96D01E5, p0); } // 0xE96D01E5
	static int NAV_QUERY_CAN_PATH_TO_POINT(Any p0) { return invoke<int>(0x5A511344, p0); } // 0x5A511344
	static void NAV_QUERY_RECEIVE_CAN_PATH_TO_POINT(Any p0, Any p1) { invoke<void>(0xAFA35FFA, p0, p1); } // 0xAFA35FFA
	static void NAV_QUERY_START_CAN_PATH_TO_POINT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { invoke<void>(0x07A777D7, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x07A777D7
	static void NAV_QUERY_STOP(Any p0) { invoke<void>(0x50290FB3, p0); } // 0x50290FB3
}

namespace NET
{
	static void NET_SET_TUNING_PARAM(Any p0, float p1) { invoke<void>(0x6BCFE549, p0, p1); } // 0x6BCFE549
	static void _0x50E637D7() { invoke<void>(0x50E637D7); } // 0x50E637D7
	static void NET_LOG(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x48275716, p0, p1, p2, p3, p4, p5, p6); } // 0x48275716
	static int NET_DUMP_STATE() { return invoke<int>(0xD164026F); } // 0xD164026F
	static int NET_ENABLE_MULTIPLAYER(Any p0) { return invoke<int>(0x9180FF1C, p0); } // 0x9180FF1C
	static int NET_IS_MANAGER_INITIALIZED() { return invoke<int>(0x84B0B5D6); } // 0x84B0B5D6
	static BOOL NET_IS_IN_SESSION() { return invoke<BOOL>(0x8CA54980); } // 0x8CA54980
	static BOOL NET_IS_ONLINE_AVAILABLE() { return invoke<BOOL>(0x5FF2BAE0); } // 0x5FF2BAE0
	static int NET_IS_CONNECTED_FOR_PLAY() { return invoke<int>(0x7AB722D8); } // 0x7AB722D8
	static int NET_GET_PLAYMODE() { return invoke<int>(0xBC4B6B74); } // 0xBC4B6B74
	static int NET_APPLY_PROTOCOL_MASK(Any p0) { return invoke<int>(0x18EC9CF0, p0); } // 0x18EC9CF0
	static const char* NET_SET_SOCIAL_CLUB_URLS(const char* result, const char* p1, Any* p2) { return invoke<const char*>(0x17D14553, result, p1, p2); } // 0x17D14553
	static BOOL NET_IS_SESSION_HOST() { return invoke<BOOL>(0xCDAC0F0E); } // 0xCDAC0F0E
	static BOOL NET_IS_SESSION_CLIENT(Any p0) { return invoke<BOOL>(0xFF65A07C, p0); } // 0xFF65A07C
	static void NET_GET_MAC_ADDRESS32(Any p0) { invoke<void>(0x75DD203B, p0); } // 0x75DD203B
	static Any NET_GET_NAT_TYPE() { return invoke<Any>(0x31700C0A); } // 0x31700C0A
	static BOOL NET_IS_BUSY() { return invoke<BOOL>(0x0678A865); } // 0x0678A865
	static void NET_GET_NET_TIME(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xFF8DA25D, p0, p1, p2, p3); } // 0xFF8DA25D
	static Any NET_ENABLE_KICKING(Any p0) { return invoke<Any>(0xB829A92D, p0); } // 0xB829A92D
	static BOOL NET_IS_LOCAL_GAMER_ONLINE() { return invoke<BOOL>(0x71D989BD); } // 0x71D989BD
	static Any NET_GET_LOCAL_GAMER_NAME() { return invoke<Any>(0x95CDCE7A); } // 0x95CDCE7A
	static void NET_APPLY_RELEVANCY_OVERRIDE() { invoke<void>(0xAD85A378); } // 0xAD85A378
	static void NET_CLEAR_RELEVANCY_OVERRIDE() { invoke<void>(0x72B03551); } // 0x72B03551
	static int GET_SLOT_FOR_HOST() { return invoke<int>(0x860FCDBD); } // 0x860FCDBD
	static Any GET_NUM_PLAYERS() { return invoke<Any>(0x0F99A8BC); } // 0x0F99A8BC
	static int NET_START_NEW_SCRIPT(Any p0, Any p1) { return invoke<int>(0x84D6F8A7, p0, p1); } // 0x84D6F8A7
	static Any NET_SCRIPTMSG_SEND(int channelId, int headerSize, int* buffer, int count, BOOL pushToQueue) { return invoke<Any>(0x5E985228, channelId, headerSize, buffer, count, pushToQueue); } // 0x5E985228
	static int NET_SCRIPTMSG_ISPENDING(Any p0, Any p1, Any p2) { return invoke<int>(0xE2163ECC, p0, p1, p2); } // 0xE2163ECC
	static int NET_SCRIPTMSG_GETNEXT(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xB13DD691, p0, p1, p2, p3); } // 0xB13DD691
	static int NET_SCRIPTMSG_REGISTER_HANDLER(Any p0, Any p1, Any p2) { return invoke<int>(0x9253CC79, p0, p1, p2); } // 0x9253CC79
	static int NET_SCRIPTMSG_QUERY_HANDLER(Any p0, Any p1, Any p2) { return invoke<int>(0x4957E482, p0, p1, p2); } // 0x4957E482
	static void REGISTER_HOST_BROADCAST_VARIABLES(Any p0, Any p1) { invoke<void>(0xBEDD194D, p0, p1); } // 0xBEDD194D
	static void REGISTER_CLIENT_BROADCAST_VARIABLES(Any p0, Any p1) { invoke<void>(0xF1732769, p0, p1); } // 0xF1732769
	static void UNREGISTER_HOST_BROADCAST_VARIABLES() { invoke<void>(0x2707F082); } // 0x2707F082
	static void UNREGISTER_CLIENT_BROADCAST_VARIABLES() { invoke<void>(0x0130DB5D); } // 0x0130DB5D
	static int _NET_IS_SLOT_VALID_IN_CLIENT_BROADCAST_VARIABLES(Any p0, Any p1) { return invoke<int>(0xF81E2097, p0, p1); } // 0xF81E2097
	static int _NET_IS_CLIENT_DATA_VALID_FOR_ALL_SLOTS(Any p0, Any p1) { return invoke<int>(0x64C2DD40, p0, p1); } // 0x64C2DD40
	static int IS_DATA_VALID_FOR_HOST_BROADCAST_VARIABLES(Any p0) { return invoke<int>(0xA80C6DE6, p0); } // 0xA80C6DE6
	static int NET_IS_OBJECT_LOCAL(Any p0) { return invoke<int>(0xD12C55A5, p0); } // 0xD12C55A5
	static Any NET_REQUEST_OBJECT(Any p0) { return invoke<Any>(0x68EC589D, p0); } // 0x68EC589D
	static int NET_OBJECT_REPLICATION_MODE_START(Any p0, Any p1) { return invoke<int>(0x47C5E353, p0, p1); } // 0x47C5E353
	static int NET_OBJECT_REPLICATION_MODE_END(int result) { return invoke<int>(0x3932B786, result); } // 0x3932B786
	static int NET_OBJECT_GET_REPLICATION_MODE(Any p0) { return invoke<int>(0x138F38AC, p0); } // 0x138F38AC
	static int NET_OBJECT_SET_REPLICATION_MODE(Any p0, Any p1) { return invoke<int>(0x3E509DF1, p0, p1); } // 0x3E509DF1
	static int NET_OBJECT_LOCK_OWNERSHIP(Any p0, Any p1) { return invoke<int>(0x8C7E41E2, p0, p1); } // 0x8C7E41E2
	static int _NET_SET_REPLICATE_ALWAYS_TO_LAYOUT(Any p0, Any p1) { return invoke<int>(0x1306549E, p0, p1); } // 0x1306549E
	static void _NET_SET_LAYOUT_OBJECTS_REPLICATE_TO_LAYOUT(Any p0) { invoke<void>(0x5C4CAE3A, p0); } // 0x5C4CAE3A
	static int NET_ACTOR_GET_SCRIPT_INT(Any p0) { return invoke<int>(0x579C2014, p0); } // 0x579C2014
	static void NET_ACTOR_SET_EQUIP_TYPE(Any p0) { invoke<void>(0x7837890B, p0); } // 0x7837890B
	static int NET_ACTOR_SET_SCRIPT_INT(int result, Any p1) { return invoke<int>(0xA6D794FE, result, p1); } // 0xA6D794FE
	static int NET_OBJECT_SET_SCRIPT_INT(int result, Any p1) { return invoke<int>(0x1C147E14, result, p1); } // 0x1C147E14
	static int NET_OBJECT_GET_SCRIPT_INT(Any p0) { return invoke<int>(0xCA6231C1, p0); } // 0xCA6231C1
	static int NET_ACTOR_SET_ALLOW_BLIP_SYNC(int result, Any p0) { return invoke<int>(0xC09B114B, result, p0); } // 0xC09B114B
	static int NET_ACTOR_SET_GRINGO_NAVIGATION_COMPLETE(int result, Any p0) { return invoke<int>(0x7284A71B, result, p0); } // 0x7284A71B
	static int NET_GET_SESSION_GAMER_COUNT() { return invoke<int>(0x7AB65B0C); } // 0x7AB65B0C
	static Any AWARD_ACHIEVEMENT(Any p0) { return invoke<Any>(0xCAA24B1A, p0); } // 0xCAA24B1A
	static Any HAS_ACHIEVEMENT_BEEN_PASSED(Any p0) { return invoke<Any>(0x136A5BE9, p0); } // 0x136A5BE9
	static int ARE_ACHIEVEMENTS_READY() { return invoke<int>(0xC792A9E0); } // 0xC792A9E0
	static Any AWARD_AVATAR(Any p0) { return invoke<Any>(0xDD33E221, p0); } // 0xDD33E221
	static Any NET_GET_POSSE_COUNT() { return invoke<Any>(0xC4F9DA6E); } // 0xC4F9DA6E
	static BOOL NET_IS_POSSE_LEADER() { return invoke<BOOL>(0x1CAD6D29); } // 0x1CAD6D29
	static int NET_GET_POSSE_LEADER_SLOT() { return invoke<int>(0x0D914C89); } // 0x0D914C89
	static int NET_GET_GAMER_POSSE_LEADER(Any p0) { return invoke<int>(0xFC52BD15, p0); } // 0xFC52BD15
	static Any NET_GET_GAMER_POSSE_SIZE(Any p0) { return invoke<Any>(0xB6006EA9, p0); } // 0xB6006EA9
	static int NET_POSSE_REMOVE_GAMER(Any p0) { return invoke<int>(0x98A5CDC5, p0); } // 0x98A5CDC5
	static int NET_POSSE_IS_INVITE_PRESENT(Any p0) { return invoke<int>(0x106CE441, p0); } // 0x106CE441
	static int NET_POSSE_IS_REQUEST_PRESENT(Any p0) { return invoke<int>(0x6A7B9FAD, p0); } // 0x6A7B9FAD
	static int NET_RUN_SEARCH_BOT(Any p0) { return invoke<int>(0x2037A74F, p0); } // 0x2037A74F
	static int NET_GET_NUMBER_OF_SESSIONS() { return invoke<int>(0x89D8FC30); } // 0x89D8FC30
	static BOOL NET_IS_SEARCHBOT_BUSY() { return invoke<BOOL>(0x2010ABE6); } // 0x2010ABE6
	static int NET_SEARCHBOT_FILTER_RESET(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xF6E40FF3, p0, p1, p2, p3, p4); } // 0xF6E40FF3
	static int NET_SEARCHBOT_USE_QUICKMATCH() { return invoke<int>(0xC0849D70); } // 0xC0849D70
	static int NET_SESSION_QUICK_JOIN_NATIVE(Any p0) { return invoke<int>(0x8DF05A4F, p0); } // 0x8DF05A4F
	static Any NET_SESSION_LEAVE_SESSION() { return invoke<Any>(0x4AE5DBB2); } // 0x4AE5DBB2
	static BOOL NET_IS_FACTION_SAFE(Any p0) { return invoke<BOOL>(0x80B20614, p0); } // 0x80B20614
	static int NET_SESSION_START_GAMEPLAY() { return invoke<int>(0x86FF3A9B); } // 0x86FF3A9B
	static int NET_SESSION_END_GAMEPLAY() { return invoke<int>(0x81FD9851); } // 0x81FD9851
	static int NET_SESSION_SET_INVITABLE(Any p0) { return invoke<int>(0x3A5C56E3, p0); } // 0x3A5C56E3
	static int NET_SET_SLOTS_PRIORITY_CLIENTS(Any p0) { return invoke<int>(0xFA0E1F8B, p0); } // 0xFA0E1F8B
	static int NET_SET_SESSION_CLOSED_FOR_JOIN(Any p0) { return invoke<int>(0xCC7D0431, p0); } // 0xCC7D0431
	static int NET_SESSION_IS_GAMEPLAY_STARTED() { return invoke<int>(0xDC88B308); } // 0xDC88B308
	static int NET_SET_QUICKMATCH_PLAYLIST_RANGE(Any p0, Any p1) { return invoke<int>(0xD923CD1B, p0, p1); } // 0xD923CD1B
	static int NET_SESSION_REQUEST_BECOME_HOST(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x7540959C, p0, p1, p2, p3); } // 0x7540959C
	static void NET_SET_THIS_SCRIPT_IS_NET_SCRIPT(Any p0) { invoke<void>(0xEE3B79EE, p0); } // 0xEE3B79EE
	static int NET_UNREGISTER_AS_NET_SCRIPT() { return invoke<int>(0x4238C471); } // 0x4238C471
	static Any NET_GET_SCRIPT_STATUS() { return invoke<Any>(0x667DA125); } // 0x667DA125
	static BOOL NET_IS_PLAYER_PARTICIPANT(Player player) { return invoke<BOOL>(0x110A9B2F, player); } // 0x110A9B2F
	static BOOL NET_IS_HOST_OF_THIS_SCRIPT() { return invoke<BOOL>(0x6D403720); } // 0x6D403720
	static Any NET_GET_HOST_OF_THIS_SCRIPT() { return invoke<Any>(0x9272C3BA); } // 0x9272C3BA
	static int NET_ALLOW_PLAYERS_TO_JOIN(Any p0) { return invoke<int>(0x408E28E2, p0); } // 0x408E28E2
	static int NET_IS_SCRIPT_REGISTERED_AS_NET_SCRIPT() { return invoke<int>(0xC0FC4B57); } // 0xC0FC4B57
	static int NET_SCRIPT_GET_NUM_PARTICIPANTS() { return invoke<int>(0xD9965A9A); } // 0xD9965A9A
	static void SET_RICH_PRESENCE(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x7BDCBD45, p0, p1, p2, p3, p4); } // 0x7BDCBD45
	static void NET_GAMERDATA_SET(Any p0, Any p1) { invoke<void>(0x50C18480, p0, p1); } // 0x50C18480
	static int NET_GET_KILL_EFFECT_ON() { return invoke<int>(0xE5645CB3); } // 0xE5645CB3
	static int _NET_SESSION_GET_NORMALIZE_POSITION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14, Any p15, Any p16, Any p17, Any p18) { return invoke<int>(0x79AFAB1F, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18); } // 0x79AFAB1F
	static int _NET_SESSION_GET_CURRENT_SEARCH_GENERATION() { return invoke<int>(0x581CAC89); } // 0x581CAC89
	static int _NET_SESSION_GET_GENERATION_FOR_NET_SESSION_OBJECT(Any p0) { return invoke<int>(0xA174152C, p0); } // 0xA174152C
	static int _NET_SESSION_GET_JOINED_GENERATION_FROM_NET_SESSION_OBJECT(Any p0) { return invoke<int>(0x0183A3F0, p0); } // 0x0183A3F0
	static int NET_JOIN_SESSION_FROM_OBJ(Any p0) { return invoke<int>(0x63034F52, p0); } // 0x63034F52
	static int _NET_GET_SESSION_GAMEMODE_TYPE(Any p0) { return invoke<int>(0xE9EAC45C, p0); } // 0xE9EAC45C
	static int IS_SESSION_CURRENTLY_JOINED_SESSION(Any p0) { return invoke<int>(0xBDF22FCA, p0); } // 0xBDF22FCA
	static int NET_SESSION_SET_GAME_LOCALE_EX(Any p0) { return invoke<int>(0x9EA132A3, p0); } // 0x9EA132A3
	static int NET_SESSION_SET_GAME_MODE_TYPE(Any p0) { return invoke<int>(0xCB0BCAE2, p0); } // 0xCB0BCAE2
	static int NET_VOICE_BROADCAST_ENABLE() { return invoke<int>(0x7A99E7DE); } // 0x7A99E7DE
	static int NET_VOICE_BROADCAST_DISABLE() { return invoke<int>(0x1D5E39A0); } // 0x1D5E39A0
	static int NET_ARE_UNLOCKS_READY() { return invoke<int>(0xEF6BF96E); } // 0xEF6BF96E
	static Any NET_IS_UNLOCKED(Any p0) { return invoke<Any>(0xC8B680B3, p0); } // 0xC8B680B3
	static int NET_GET_OVERLOAD_STATE_FOR_SLOT(Any p0) { return invoke<int>(0xBE0E275F, p0); } // 0xBE0E275F
	static Any NET_GET_AREA_OVERLOAD_STATE_FOR_SLOT(Any p0) { return invoke<Any>(0xCB42389E, p0); } // 0xCB42389E
	static int _NET_SET_OVERLOAD_REDUCTION_LEVEL() { return invoke<int>(0x842ADE0A); } // 0x842ADE0A
	static int NET_SET_SYNC_PRIORITY_LIMITS() { return invoke<int>(0xB7856424); } // 0xB7856424
	static void UPDATE_PROFILE_STAT(Any p0, Any p1, Any p2) { invoke<void>(0xF2FA1DE8, p0, p1, p2); } // 0xF2FA1DE8
	static int UPDATE_STRING_PROFILE_STAT(Any p0, Any p1) { return invoke<int>(0xCF674E31, p0, p1); } // 0xCF674E31
	static int _NET_AH_LAG_HACK_KILL_PROTECTION_ENABLE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x97F15B69, p0, p1, p2, p3); } // 0x97F15B69
	static int _NET_AH_LAG_HACK_MOVE_PROTECTION_ENABLE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xCA0739A8, p0, p1, p2, p3); } // 0xCA0739A8
	static int NET_BROADCAST_EXPLODE_TARGET_EVENT(Actor actor) { return invoke<int>(0x49BC0219, actor); } // 0x49BC0219
	static int DO_FILE_CRC(Any p0, Any p1, Any p2) { return invoke<int>(0xD6780B56, p0, p1, p2); } // 0xD6780B56
	static void FLAG_FILE_CRC_MISMATCH() { invoke<void>(0x9A5841E5); } // 0x9A5841E5
	// PS4/Switch/PC only
	static void NET_SET_UNLOCK() { invoke<void>(0x489A2B93); } // 0x489A2B93
}

namespace NET2
{
	static int _NET_GAMETYPE_ADD_GAMETYPE_ENTRY(Any p0) { return invoke<int>(0x55C5BB93, p0); } // 0x55C5BB93
	static int _NET_GAMETYPE_GET_GAMETYPE_ENTRY(Any p0, Any p1) { return invoke<int>(0xFAD5A270, p0, p1); } // 0xFAD5A270
	static BOOL GAME_INSTANCE_ITERATOR_START(Any p0) { return invoke<BOOL>(0x4A721118, p0); } // 0x4A721118
	static int GAME_INSTANCE_ITERATOR_NEXT(Any p0) { return invoke<int>(0x4500B98A, p0); } // 0x4500B98A
	static int GAME_INSTANCE_SET_REGION(Any p0, Any p1) { return invoke<int>(0x85049505, p0, p1); } // 0x85049505
	static int ADD_PLAYLIST_TO_DB(Any p0, Any p1) { return invoke<int>(0x5C51D43C, p0, p1); } // 0x5C51D43C
	static int GET_PLAYLIST_FROM_DB(Any p0, Any p1) { return invoke<int>(0x0E2C4B68, p0, p1); } // 0x0E2C4B68
	static int GET_PLAYLIST_FROM_DB_BY_NAME(Any p0, Any p1) { return invoke<int>(0xB514ECA7, p0, p1); } // 0xB514ECA7
}

namespace NET_STATS
{
	static void NET_UPDATE_LEADERBOARD(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x12304873, p0, p1, p2, p3); } // 0x12304873
	static int NET_START_LB_UPDATE(Any p0) { return invoke<int>(0x4D0C8AA4, p0); } // 0x4D0C8AA4
	static int NET_END_LB_UPDATE() { return invoke<int>(0x89277EA3); } // 0x89277EA3
	static int NET_CREATE_FRIEND_SCORE_READER(Any p0) { return invoke<int>(0x2B8F86ED, p0); } // 0x2B8F86ED
	static int NET_REPORT_FRIEND_SCORES(Any p0, Any p1, Any p2) { return invoke<int>(0x88249424, p0, p1, p2); } // 0x88249424
	static int NET_GET_LOCAL_GAMER_SCORE_INFO(Any p0) { return invoke<int>(0x87A3A38D, p0); } // 0x87A3A38D
	static int NET_GET_NEAREST_FRIEND_SCORE_INFO(Any p0) { return invoke<int>(0xD7572C68, p0); } // 0xD7572C68
	static int NET_GET_NEAREST_FRIEND_NAME() { return invoke<int>(0x76F09F04); } // 0x76F09F04
	static int NET_GET_SLOT_OF_NEAREST_FRIEND() { return invoke<int>(0xA684E813); } // 0xA684E813
	static int NET_IS_FRIEND_SCORE_INFO_AVAILABLE() { return invoke<int>(0xE5C5CE63); } // 0xE5C5CE63
	static int NET_GET_LOCAL_GAMER_RANK() { return invoke<int>(0x4F652A00); } // 0x4F652A00
	static int NET_GET_NEAREST_FRIEND_RANK() { return invoke<int>(0xFC564903); } // 0xFC564903
	static int NET_LB_FRIENDS_SELECT_NEAREST() { return invoke<int>(0x7154D15B); } // 0x7154D15B
	static int NET_CHALLENGE_LB_CREATE_READER(Any p0, Any p1) { return invoke<int>(0x86BC0A55, p0, p1); } // 0x86BC0A55
	static int NET_CHALLENGE_LB_DESTROY_READER() { return invoke<int>(0xEB4A6D85); } // 0xEB4A6D85
	static BOOL NET_CHALLENGE_LB_DOES_READER_EXIST() { return invoke<BOOL>(0x5FD52711); } // 0x5FD52711
	static BOOL NET_CHALLENGE_LB_IS_READ_COMPLETE() { return invoke<BOOL>(0xD0808C42); } // 0xD0808C42
	static int NET_CHALLENGE_LB_IS_LOCAL_GAMER_INFO_VALID() { return invoke<int>(0x097BB984); } // 0x097BB984
	static int NET_CHALLENGE_LB_GET_LOCAL_GAMER_NAME() { return invoke<int>(0xEA7ADF42); } // 0xEA7ADF42
	static int NET_CHALLENGE_LB_GET_LOCAL_GAMER_STATS(Any p0) { return invoke<int>(0x3A8C77AD, p0); } // 0x3A8C77AD
	static int NET_CHALLENGE_LB_IS_TOP_FRIEND_INFO_VALID() { return invoke<int>(0xE89C6E4F); } // 0xE89C6E4F
	static int NET_CHALLENGE_LB_GET_TOP_FRIEND_NAME() { return invoke<int>(0x0791F35A); } // 0x0791F35A
	static int NET_CHALLENGE_LB_GET_TOP_FRIEND_STATS(Any p0) { return invoke<int>(0x49C2B05F, p0); } // 0x49C2B05F
	static int NET_CHALLENGE_LB_IS_TOP_SCORER_INFO_VALID() { return invoke<int>(0xC813DBEF); } // 0xC813DBEF
	static int NET_CHALLENGE_LB_GET_TOP_SCORER_NAME() { return invoke<int>(0xE6B4F505); } // 0xE6B4F505
	static int NET_CHALLENGE_LB_GET_TOP_SCORER_STATS(Any p0) { return invoke<int>(0x70AF0351, p0); } // 0x70AF0351
	static int NET_CHALLENGE_LB_IS_SCORER_ABOVE_PLAYER_INFO_VALID() { return invoke<int>(0x293C3288); } // 0x293C3288
	static int NET_CHALLENGE_LB_GET_SCORER_ABOVE_PLAYER_NAME() { return invoke<int>(0xA7F231B0); } // 0xA7F231B0
	static int NET_CHALLENGE_LB_GET_SCORER_ABOVE_PLAYER_STATS(Any p0) { return invoke<int>(0x984749B4, p0); } // 0x984749B4
}

namespace NET_UI
{
	static int NET_GET_AND_CLEAR_GAME_MODE_REQUEST() { return invoke<int>(0x8808546E); } // 0x8808546E
	static int NET_GET_AND_CLEAR_PLAYLIST_REQUEST() { return invoke<int>(0x1A47001B); } // 0x1A47001B
	static int NET_GET_AND_CLEAR_QUIT_GAME_REQUEST() { return invoke<int>(0x0FF6B8F4); } // 0x0FF6B8F4
	static int NET_GET_FREE_ROAM_MODE() { return invoke<int>(0x81F24788); } // 0x81F24788
	static void NET_SET_FREE_ROAM_MODE(int mode) { invoke<void>(0x41921C98, mode); } // 0x41921C98
	static void NET_REGISTER_GAME_TYPE(Any p0, Any p1) { invoke<void>(0xE822010A, p0, p1); } // 0xE822010A
	static void NET_REGISTER_PLAYLIST_TYPE(Any p0, Any p1, Any p2) { invoke<void>(0xA9459BB6, p0, p1, p2); } // 0xA9459BB6
	static void NET_SET_PLAYLIST_LOCKED(Any p0, Any p1) { invoke<void>(0x9D9784B8, p0, p1); } // 0x9D9784B8
	static int NET_GET_JOINWISH_PAD() { return invoke<int>(0x03962973); } // 0x03962973
	static int NET_AUTHENTICATE_GAMER(Any p0, Any p1) { return invoke<int>(0x8E0D7219, p0, p1); } // 0x8E0D7219
	static int NET_GET_PLAYER_COLOR_IDX(Any p0) { return invoke<int>(0xC00C8C94, p0); } // 0xC00C8C94
	static int NET_GET_GAMER_HEX_COLOR(Any p0, Any p1) { return invoke<int>(0x9BC05C90, p0, p1); } // 0x9BC05C90
	static int NET_GET_GAMER_RGB_COLOR(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x97931B87, p0, p1, p2, p3); } // 0x97931B87
	static int NET_IS_GAMER_RADAR_BLIP_VISIBLE(Any p0) { return invoke<int>(0xFE83A4FE, p0); } // 0xFE83A4FE
	static int _NET_SYS_UI_SET_POSITION(Any p0) { return invoke<int>(0x8DEC3E03, p0); } // 0x8DEC3E03
	static int NET_PLAYER_BARKER_RESET(Any p0, Any p1, Any p2, float p3) { return invoke<int>(0xBECB3EEC, p0, p1, p2, p3); } // 0xBECB3EEC
	static BOOL NET_GET_USING_SPHERE_CURVES(Any p0) { return invoke<BOOL>(0x75F27D60, p0); } // 0x75F27D60
	static int NET_PLAYER_SHOW_CONTEXT_MENU(Any p0, Any p1) { return invoke<int>(0xA64A451E, p0, p1); } // 0xA64A451E
	static int NET_PLAYER_LIST_RESET() { return invoke<int>(0x67031EDA); } // 0x67031EDA
	static BOOL NET_PLAYER_LIST_ADD_ITEM(const char* text, int rowIndex) { return invoke<BOOL>(0xFD355ED1, text, rowIndex); } // 0xFD355ED1
	static int NET_PLAYER_LIST_ADD_GAMER_SLOT(Any p0, Any p1) { return invoke<int>(0x805AC16A, p0, p1); } // 0x805AC16A
	static int NET_PLAYER_LIST_SET_HIGHLIGHT(int highlightIndex) { return invoke<int>(0x0AAE9E6B, highlightIndex); } // 0x0AAE9E6B
	static int NET_PLAYER_LIST_SET_TOP_TEAM(Any p0) { return invoke<int>(0x20B684AB, p0); } // 0x20B684AB
	static int NET_PLAYER_LIST_SET_TEAM_SCORE(Any p0, Any p1, Any p2) { return invoke<int>(0x84CD0651, p0, p1, p2); } // 0x84CD0651
	static int NET_PLAYER_LIST_SET_TEAM_SORT(Any p0) { return invoke<int>(0xA56B459C, p0); } // 0xA56B459C
	static int NET_PLAYER_LIST_SET_TITLE(const char* gxtName) { return invoke<int>(0x0547A660, gxtName); } // 0x0547A660
	static int NET_PLAYER_LIST_SET_TEMPLATE(int menuTemplate) { return invoke<int>(0xD6111569, menuTemplate); } // 0xD6111569
	static int NET_PLAYER_LIST_SET_HEADER(int columnIndex, const char* entry) { return invoke<int>(0xFA382FCB, columnIndex, entry); } // 0xFA382FCB
	static int NET_PLAYER_LIST_SET_DESCRIPTION(const char* str) { return invoke<int>(0xCF065186, str); } // 0xCF065186
	static int NET_PLAYER_LIST_TIMER_SET(Any p0) { return invoke<int>(0xBE7965C8, p0); } // 0xBE7965C8
	static int NET_PLAYER_LIST_TIMER_ENABLE_FLASHING(Any p0) { return invoke<int>(0xD4C7E0D5, p0); } // 0xD4C7E0D5
	static int NET_PLAYER_LIST_SET_CURRENT_ITEM() { return invoke<int>(0x98FC68AF); } // 0x98FC68AF
	static int NET_PLAYER_LIST_SET_CURRENT_ITEM_BY_SLOT(Any p0) { return invoke<int>(0x95A543E2, p0); } // 0x95A543E2
	static int NET_PLAYER_LIST_SET_CURRENT_ITEM_MSCORE_STRING(int columnIndex, const char* text) { return invoke<int>(0xC673362C, columnIndex, text); } // 0xC673362C
	static int NET_PLAYER_LIST_SET_CURRENT_ITEM_MSCORE_INT(Any p0, Any p1) { return invoke<int>(0xEC6F465F, p0, p1); } // 0xEC6F465F
	static int NET_PLAYER_LIST_SET_CURRENT_ITEM_TEAM(int groupColor) { return invoke<int>(0x794F5C21, groupColor); } // 0x794F5C21
	static int NET_PLAYER_LIST_SET_CURRENT_ITEM_PRIORITY(Any p0) { return invoke<int>(0xBD42097A, p0); } // 0xBD42097A
	static int NET_PLAYER_LIST_SET_CURRENT_ITEM_DEAD(Any p0) { return invoke<int>(0xC09ACD5C, p0); } // 0xC09ACD5C
	static int NET_TICKER_REPORTF(const char* text1, const char* text2, const char* text3, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0xC73DAD2B, text1, text2, text3, p3, p4, p5, p6); } // 0xC73DAD2B
	static int NET_TICKER_CLEAR() { return invoke<int>(0x8A1D83F2); } // 0x8A1D83F2
	static int NET_XP_TOTAL_REPORT_CHANGE(Any p0, Any p1) { return invoke<int>(0xA6403262, p0, p1); } // 0xA6403262
	static int NET_SCOREGRAPH_SETUP(Any p0, Any p1, Any p2) { return invoke<int>(0x27D40FD1, p0, p1, p2); } // 0x27D40FD1
	static int NET_SCOREGRAPH_CLEAR_MARKERS() { return invoke<int>(0xA3AE09EF); } // 0xA3AE09EF
	static int NET_SCOREGRAPH_ADD_PLAYER_SCORE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x746897AB, p0, p1, p2, p3); } // 0x746897AB
	static int NET_SCOREGRAPH_ADD_PLAYER_LABEL() { return invoke<int>(0xB4C867BD); } // 0xB4C867BD
	static int NET_SCOREGRAPH_ADD_TEAM_SCORE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x12558DBD, p0, p1, p2, p3); } // 0x12558DBD
	static int NET_SCOREGRAPH_ADD_TEAM_LABEL(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x134AAF17, p0, p1, p2, p3); } // 0x134AAF17
}

namespace OBJECT
{
	static Any VERIFY_TYPE_COUNT(Hash p0) { return invoke<Any>(0x0B396DFF, p0); } // 0x0B396DFF
	static void VERIFY_EVENT_COUNT(Any p0) { invoke<void>(0x24F3A0DB, p0); } // 0x24F3A0DB
	static int _0x26011C78(Any p0) { return invoke<int>(0x26011C78, p0); } // 0x26011C78
	static int LOG_OBJECT2(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xC8C0C708, p0, p1, p2, p3, p4, p5); } // 0xC8C0C708
	static int LOG_OBJECT3(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0x9A756A72, p0, p1, p2, p3, p4, p5, p6); } // 0x9A756A72
	static BOOL IS_LAYOUTREF_VALID(Layout layout) { return invoke<BOOL>(0xFC8E55ED, layout); } // 0xFC8E55ED
	static BOOL IS_OBJECT_VALID(Object object) { return invoke<BOOL>(0xD7E7187B, object); } // 0xD7E7187B
	static BOOL IS_ITERATOR_VALID(Iterator iterator) { return invoke<BOOL>(0x5A9CC0B0, iterator); } // 0x5A9CC0B0
	static Any IS_PERS_CHAR_VALID() { return invoke<Any>(0x36CC24A4); } // 0x36CC24A4
	static BOOL IS_POPSET_VALID(Any p0) { return invoke<BOOL>(0x64BAF32C, p0); } // 0x64BAF32C
	static BOOL IS_ZONE_VALID(Any p0) { return invoke<BOOL>(0x262164F8, p0); } // 0x262164F8
	static BOOL IS_CRIME_VALID(Any p0) { return invoke<BOOL>(0x4CC5681D, p0); } // 0x4CC5681D
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eObjectType
	static int GET_OBJECT_TYPE(int p0) { return invoke<int>(0x261ECB20, p0); } // 0x261ECB20
	static int GET_NUM_OBJECTS_OF_TYPE(Any p0) { return invoke<int>(0xADB08F12, p0); } // 0xADB08F12
	static int GET_MAX_NUM_OBJECTS_OF_TYPE(Any p0) { return invoke<int>(0xA2866F3B, p0); } // 0xA2866F3B
	static Layout FIND_NAMED_LAYOUT(const char* layoutName) { return invoke<Layout>(0x5699DE7E, layoutName); } // 0x5699DE7E
	static const char* GET_ACTOR_NAME(Actor actor) { return invoke<const char*>(0x78CF43C1, actor); } // 0x78CF43C1
	static const char* GET_OBJECT_NAME(Object object) { return invoke<const char*>(0xDF40614F, object); } // 0xDF40614F
	static const char* GET_LAYOUT_NAME(Object object) { return invoke<const char*>(0xBADE22A2, object); } // 0xBADE22A2
	static const char* GET_OBJECT_MODEL_NAME(Object object) { return invoke<const char*>(0x5C4262F9, object); } // 0x5C4262F9
	static const char* GET_POPULATION_SET_NAME(Any p0) { return invoke<const char*>(0xF662EAE1, p0); } // 0xF662EAE1
	static int GET_COVER_LOCATION_FROM_OBJECT(Any p0) { return invoke<int>(0x2CF0010F, p0); } // 0x2CF0010F
	static int GET_GRINGO_FROM_OBJECT(Object object) { return invoke<int>(0x8A01B64B, object); } // 0x8A01B64B
	static int GET_PROP_FROM_OBJECT(Any p0) { return invoke<int>(0xA7E9DA22, p0); } // 0xA7E9DA22
	static int GET_OBJECT_FROM_GRINGO(Any p0) { return invoke<int>(0x111501F7, p0); } // 0x111501F7
	static Any GET_OBJECT_FROM_ACTOR(int* p0, Any p1) { return invoke<Any>(0x4A2063EC, p0, p1); } // 0x4A2063EC
	static Any GET_OBJECT_FROM_VOLUME(int* p0, Any p1) { return invoke<Any>(0xFADF0B96, p0, p1); } // 0xFADF0B96
	static Any GET_OBJECT_FROM_PERS_CHAR(int* p0, Any p1) { return invoke<Any>(0x35B5587D, p0, p1); } // 0x35B5587D
	static Any GET_OBJECT_FROM_SQUAD(int* p0, Any p1) { return invoke<Any>(0xEDA897FA, p0, p1); } // 0xEDA897FA
	static Any GET_OBJECT_FROM_CRIME(int* p0, Any p1) { return invoke<Any>(0x831338D9, p0, p1); } // 0x831338D9
	static Any GET_OBJECT_FROM_PHYSINST(int* p0, Any p1) { return invoke<Any>(0x0550E178, p0, p1); } // 0x0550E178
	static int GET_ACTOR_FROM_OBJECT(Any p0) { return invoke<int>(0x34F0AD96, p0); } // 0x34F0AD96
	static int GET_VOLUME_FROM_OBJECT(Any p0) { return invoke<int>(0x502DAC62, p0); } // 0x502DAC62
	static int GET_PERS_CHAR_FROM_OBJECT(Any p0) { return invoke<int>(0x024B2FFC, p0); } // 0x024B2FFC
	static int GET_ITERATOR_FROM_OBJECT(Any p0) { return invoke<int>(0xF5EE5874, p0); } // 0xF5EE5874
	static int GET_SQUAD_FROM_OBJECT(Any p0) { return invoke<int>(0xD0C471FB, p0); } // 0xD0C471FB
	static int GET_LAYOUT_FROM_OBJECT(Any p0) { return invoke<int>(0x51D6DA2C, p0); } // 0x51D6DA2C
	static int GET_MOBILE_LAYOUT_FROM_OBJECT(Any p0) { return invoke<int>(0x6B72661F, p0); } // 0x6B72661F
	static int GET_CRIME_FROM_OBJECT(Any p0) { return invoke<int>(0xB578DB52, p0); } // 0xB578DB52
	static int GET_CAMERA_FROM_OBJECT(Any p0) { return invoke<int>(0xD4048969, p0); } // 0xD4048969
	static int GET_NAV_QUERY_FROM_OBJECT(Any p0) { return invoke<int>(0x50A7E334, p0); } // 0x50A7E334
	static Layout CREATE_LAYOUT(const char* layoutName) { return invoke<Layout>(0x6CA53214, layoutName); } // 0x6CA53214
	static int CREATE_MOBILE_LAYOUT(Any p0) { return invoke<int>(0x426828CB, p0); } // 0x426828CB
	static int CREATE_CORPSE_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0xE8C04F05, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0xE8C04F05
	static int CREATE_CORPSE_IN_LAYOUT_RANDOM(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { return invoke<int>(0x40856E8A, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x40856E8A
	static int CREATE_CORPSE_VARIATION_IN_LAYOUT(Any p0, Any p1) { return invoke<int>(0x2EC081E4, p0, p1); } // 0x2EC081E4
	static int CREATE_CORPSE_VARIATION_IN_LAYOUT_RANDOM(int* p0, Any p1) { return invoke<int>(0x8468286B, p0, p1); } // 0x8468286B
	static int CREATE_COVER_LOCATION_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x708C7D7B, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x708C7D7B
	static int CREATE_POINT_IN_LAYOUT(Layout layout, const char* layoutName, Vector2 positionXY, float positionZ, Vector2 orientationXY, float orientationZ) { return invoke<int>(0x44A34042, layout, layoutName, positionXY, positionZ, orientationXY, orientationZ); } // 0x44A34042
	static int CREATE_POINT_IN_LAYOUT(Layout layout, const char* layoutName, Vector3 positionxy, Vector3 orientationxy) { return invoke<int>(0x44A34042, layout, layoutName, Vector2(positionxy.x, positionxy.y), positionxy.z, Vector2(orientationxy.x, orientationxy.y), orientationxy.z); } // 0x44A34042
	static int CREATE_POINT_LIGHT_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0xF9CC7F63, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xF9CC7F63
	static int CREATE_VOLUME_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11) { return invoke<int>(0xA17311E4, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0xA17311E4
	static int CREATE_VOLUME_SET_IN_LAYOUT(Any p0, Any p1) { return invoke<int>(0x177A3843, p0, p1); } // 0x177A3843
	static int CREATE_GRINGO_IN_LAYOUT(Layout layout, const char* layoutName, const char* gringoPath, Vector2 positionXY, float positionZ, Vector2 orientationXY, float orientationZ) { return invoke<int>(0x025C9845, layout, layoutName, gringoPath, positionXY, positionZ, orientationXY, orientationZ); } // 0x025C9845
	static int CREATE_GRINGO_IN_LAYOUT(Layout layout, const char* layoutName, const char* gringoPath, Vector3 positionxy, Vector3 orientationxy) { return invoke<int>(0x025C9845, layout, layoutName, gringoPath, Vector2(positionxy.x, positionxy.y), positionxy.z, Vector2(orientationxy.x, orientationxy.y), orientationxy.z); } // 0x025C9845
	static int CREATE_GRINGO_ON_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x88087384, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x88087384
	static int CREATE_GRINGO_IN_LAYOUT_BY_ID(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x66A8AF91, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x66A8AF91
	static int CREATE_GRINGO_ON_OBJECT_BY_ID(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x80FB8BDE, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x80FB8BDE
	static int CREATE_PROPSET_IN_LAYOUT(Layout layout, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x779267C3, layout, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x779267C3
	static Object CREATE_PROP_IN_LAYOUT(Layout layout, const char* layoutName, const char* propPath, Vector2 positionXY, float positionZ, Vector2 orientationXY, float orientationZ, BOOL p7) { return invoke<Object>(0xE351587D, layout, layoutName, propPath, positionXY, positionZ, orientationXY, orientationZ, p7); } // 0xE351587D
	static Object CREATE_PROP_IN_LAYOUT(Layout layout, const char* layoutName, const char* propPath, Vector3 positionxy, Vector3 orientationxy, BOOL p7) { return invoke<Object>(0xE351587D, layout, layoutName, propPath, Vector2(positionxy.x, positionxy.y), positionxy.z, Vector2(orientationxy.x, orientationxy.y), orientationxy.z, p7); } // 0xE351587D
	static int CREATE_PROP_IN_LAYOUT_BY_ID(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { return invoke<int>(0xD92BA5B6, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xD92BA5B6
	static Any CREATE_COVER_PROP_IN_LAYOUT(Any p0, Any p1) { return invoke<Any>(0xAF4F1910, p0, p1); } // 0xAF4F1910
	static int CREATE_SPAWN_POINT_IN_LAYOUT(int* p0, Any p1, Any p2, Any p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10) { return invoke<int>(0xB20CA4DF, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0xB20CA4DF
	static int CREATE_PATH_IN_LAYOUT(Any p0, Any p1, Any p2) { return invoke<int>(0x80B8A1BE, p0, p1, p2); } // 0x80B8A1BE
	static int CREATE_PATH_IN_LAYOUT_FROM_TABLE(Any p0, Any p1, Any p2) { return invoke<int>(0xB6709FF4, p0, p1, p2); } // 0xB6709FF4
	static int CREATE_OBSTACLE_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x2703760F, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x2703760F
	static int CREATE_OBSTACLE_ON_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x7E81694C, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x7E81694C
	static int CREATE_SQUAD_IN_LAYOUT(Layout layout, const char* squadName) { return invoke<int>(0xF7277A0F, layout, squadName); } // 0xF7277A0F
	static int CREATE_FORMATION_IN_LAYOUT(Layout layout, const char* formationName, int p2) { return invoke<int>(0x91C6AC0E, layout, formationName, p2); } // 0x91C6AC0E
	static int CREATE_CRIME_IN_LAYOUT(Any p0) { return invoke<int>(0xD60032F6, p0); } // 0xD60032F6
	static int CREATE_AI_SPEECH_PACKAGE_IN_LAYOUT(Any p0, Any p1) { return invoke<int>(0xE77F61B2, p0, p1); } // 0xE77F61B2
	static int MARK_LAYOUT_CONSIDER_WHOLE(Any p0, Any p1) { return invoke<int>(0xA936E73B, p0, p1); } // 0xA936E73B
	static void RELEASE_LAYOUT_REF(Layout layout) { invoke<void>(0xD9AC8830, layout); } // 0xD9AC8830
	static void RELEASE_LAYOUT_OBJECTS(Layout layout) { invoke<void>(0xE78E66F0, layout); } // 0xE78E66F0
	static void DESTROY_LAYOUT_OBJECTS(Layout layout) { invoke<void>(0x28A2A4CC, layout); } // 0x28A2A4CC
	static int INIT_MOBILE_LAYOUT_OBJECTS(Any p0) { return invoke<int>(0x000079CB, p0); } // 0x000079CB
	static int STORE_MOBILE_LAYOUT_TRANSFORMS(Any p0) { return invoke<int>(0x3CD2C250, p0); } // 0x3CD2C250
	static int MAKE_LAYOUT_OBJECTS_RELATIVE(Any p0, Any p1, Any p2) { return invoke<int>(0x7EEC1F40, p0, p1, p2); } // 0x7EEC1F40
	static int TRANSFORM_OBJECT_RELATIVE(Any p0, Any p1) { return invoke<int>(0xC15C3361, p0, p1); } // 0xC15C3361
	static void MARK_OBJECT_FOR_AGGRESSIVE_CLEANUP(Any p0, Any p1) { invoke<void>(0x8212247D, p0, p1); } // 0x8212247D
	static void RELEASE_OBJECT_REF(Object object) { invoke<void>(0x67DB5ABF, object); } // 0x67DB5ABF
	static void RELEASE_ACTOR(Actor actor) { invoke<void>(0x32489AFB, actor); } // 0x32489AFB
	static void RELEASE_VOLUME(Volume volume) { invoke<void>(0x81F984F8, volume); } // 0x81F984F8
	static void RELEASE_PERS_CHAR(PersChar persChar) { invoke<void>(0x19C3CF93, persChar); } // 0x19C3CF93
	static void DESTROY_VOLUME(Volume volume) { invoke<void>(0x8CAB944F, volume); } // 0x8CAB944F
	static void DESTROY_ACTOR(Actor actor) { invoke<void>(0x8BD21869, actor); } // 0x8BD21869
	static void DESTROY_LAYOUT(Layout layout) { invoke<void>(0xC1756F39, layout); } // 0xC1756F39
	static void DESTROY_OBJECT(Object object) { invoke<void>(0x21144994, object); } // 0x21144994
	static void DESTROY_ITERATOR(Iterator iterator) { invoke<void>(0xE284A10C, iterator); } // 0xE284A10C
	static int DESTROY_PERS_CHAR(PersChar persChar) { return invoke<int>(0x4028CE77, persChar); } // 0x4028CE77
	static void DESTROY_POINT_LIGHT(int pointLight) { invoke<void>(0x6BC96263, pointLight); } // 0x6BC96263
	static void DESTROY_POPULATION_SET(int populationSet) { invoke<void>(0xD064878D, populationSet); } // 0xD064878D
	static void DESTROY_ZONE(int zone) { invoke<void>(0xD62F3D27, zone); } // 0xD62F3D27
	static void DESTROY_CRIME(int crime) { invoke<void>(0xE9AB08C0, crime); } // 0xE9AB08C0
	static int GIVE_OBJECT_TO_ACTOR(Any p0, Any p1) { return invoke<int>(0xCBB2267A, p0, p1); } // 0xCBB2267A
	static int GIVE_OBJECT_TO_LAYOUT(Any p0, Any p1) { return invoke<int>(0x2D160228, p0, p1); } // 0x2D160228
	static int GET_OBJECT_OWNER(Any p0) { return invoke<int>(0x48B36E07, p0); } // 0x48B36E07
	static void DESTROY_GC_OBJECTS(Any p0, Any p1) { invoke<void>(0x86B0B004, p0, p1); } // 0x86B0B004
	static int _WAS_LAST_OBJECT_ALREADY_IN_GAME() { return invoke<int>(0x65C3D8F6); } // 0x65C3D8F6
	static Layout GET_AMBIENT_LAYOUT() { return invoke<Layout>(0xB52A3D48); } // 0xB52A3D48
	static Any GET_ART_GRINGO_LAYOUT(Any p0) { return invoke<Any>(0x76FBF412, p0); } // 0x76FBF412
	static Layout GET_GC_LAYOUT(Any p0) { return invoke<Layout>(0xADE13224, p0); } // 0xADE13224
	static int CREATE_OBJECTSET_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x921B5F2B, p0, p1, p2, p3); } // 0x921B5F2B
	static BOOL IS_OBJECTSET_VALID(Any p0) { return invoke<BOOL>(0x552189FD, p0); } // 0x552189FD
	static int ADD_OBJECT_TO_OBJECTSET(Any p0, Any p1) { return invoke<int>(0x43FBBDE1, p0, p1); } // 0x43FBBDE1
	static int GET_OBJECTSET_SIZE(Any p0) { return invoke<int>(0xE09DE8A0, p0); } // 0xE09DE8A0
	static Any GET_OBJECT_FROM_OBJECTSET(Any p0, Any p1) { return invoke<Any>(0xBF680846, p0, p1); } // 0xBF680846
	static int GET_OBJECTSET_FROM_OBJECT(Any p0) { return invoke<int>(0x2CB3B980, p0); } // 0x2CB3B980
	static int GET_INDEXED_OBJECT_IN_OBJECTSET(Any p0, Any p1) { return invoke<int>(0x50D39153, p0, p1); } // 0x50D39153
	static BOOL IS_OBJECT_IN_OBJECTSET(Any p0, Any p1) { return invoke<BOOL>(0x0114FCBD, p0, p1); } // 0x0114FCBD
	static void REMOVE_OBJECT_FROM_OBJECTSET(Any p0, Any p1) { invoke<void>(0xA3E05BAE, p0, p1); } // 0xA3E05BAE
	static void CLEAN_OBJECTSET(Any p0) { invoke<void>(0x11EE07B5, p0); } // 0x11EE07B5
	static void DISBAND_OBJECTSET(Any p0) { invoke<void>(0x179A07DD, p0); } // 0x179A07DD
	static void DESTROY_OBJECTSET(Any p0) { invoke<void>(0x3A71A589, p0); } // 0x3A71A589
	static int SET_CORPSE_PERMANENT(Any p0, Any p1) { return invoke<int>(0x5720BF8A, p0, p1); } // 0x5720BF8A
	static BOOL IS_POINT_LIGHT_VALID(int p0) { return invoke<BOOL>(0x44C07DA5, p0); } // 0x44C07DA5
	static int SET_ENABLE_POINT_LIGHT(int p0, int p1) { return invoke<int>(0x5F66B23E, p0, p1); } // 0x5F66B23E
	static BOOL IS_OBJECT_IN_VOLUME(Any p0, Any p1) { return invoke<BOOL>(0x2ECF04F3, p0, p1); } // 0x2ECF04F3
	static int LOCATE_NAMED_POINT(int* p0, float p1, float p2, float p3, float p4, int p5, int p6, int p7, int p8, BOOL p9) { return invoke<int>(0xCB3F7DA5, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xCB3F7DA5
	static int LOCATE_NAMED_ACTOR(int* p0, float p1, float p2, float p3, float p4, int p5, int p6, int p7, int p8, BOOL p9) { return invoke<int>(0xA36ED4A6, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xA36ED4A6
	static int LOCATE_NAMED_VOLUME(int* p0, int p1, int p2, int p3, int p4, int p5, float p6, float p7, float p8, float p9) { return invoke<int>(0x6F513950, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x6F513950
	static int LOCATE_ACTORS_IN_VOLUME(int p0, int p1, int p2, int p3, int p4, int p5, int p6) { return invoke<int>(0x35C8FD4A, p0, p1, p2, p3, p4, p5, p6); } // 0x35C8FD4A
	static int LOCATE_GRINGOS_IN_VOLUME(int p0, int p1, int p2, int p3, int p4, int p5, int p6) { return invoke<int>(0x0F701FF7, p0, p1, p2, p3, p4, p5, p6); } // 0x0F701FF7
	static void SET_VOLUME_PARAMS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { invoke<void>(0xFEC1CBC6, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xFEC1CBC6
	static int ADD_TO_VOLUME_SET(int p0, int p1) { return invoke<int>(0xB104FF3E, p0, p1); } // 0xB104FF3E
	static int COPY_VOLUME(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x122C916E, p0, p1, p2, p3); } // 0x122C916E
	static void SCALE_VOLUME(Any p0, Any p1) { invoke<void>(0x14DCF1EF, p0, p1); } // 0x14DCF1EF
	static void SET_ACTOR_STAY_OUTSIDE_OF_VOLUME(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x1229C536, p0, p1, p2, p3); } // 0x1229C536
	static void ADD_ACTOR_STAY_OUTSIDE_OF_VOLUME(Any p0, Any p1) { invoke<void>(0x617C9630, p0, p1); } // 0x617C9630
	static void SET_ACTOR_STAY_WITHIN_VOLUME(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x6A4A1699, p0, p1, p2, p3); } // 0x6A4A1699
	static void ADD_ACTOR_STAY_WITHIN_VOLUME(Any p0, Any p1) { invoke<void>(0xCDEF4316, p0, p1); } // 0xCDEF4316
	static int CLEAR_ACTOR_STAY_WITHIN_VOLUME(int p0, int p1, int p2, int p3) { return invoke<int>(0xED6D63FE, p0, p1, p2, p3); } // 0xED6D63FE
	static void SET_ACTOR_VOLUME_PARAMETERS(Actor actor, float value) { invoke<void>(0x8B46B294, actor, value); } // 0x8B46B294
	static void REMOVE_ACTOR_STAY_WITHIN_VOLUME(Actor actor) { invoke<void>(0x2974CAF6, actor); } // 0x2974CAF6
	static void REMOVE_ACTOR_STAY_OUTSIDE_OF_VOLUME(Actor actor) { invoke<void>(0x42EF7DB7, actor); } // 0x42EF7DB7
	static int ADD_CORPSE_RETAINMENT_VOLUME_OBJ(int p0) { return invoke<int>(0x0E41A6AC, p0); } // 0x0E41A6AC
	static int REMOVE_CORPSE_RETAINMENT_VOLUME_OBJ(int p0) { return invoke<int>(0x983ED842, p0); } // 0x983ED842
	static int ADD_CORPSE_REMOVAL_VOLUME_OBJ(int p0) { return invoke<int>(0x43E2808B, p0); } // 0x43E2808B
	static int REMOVE_CORPSE_REMOVAL_VOLUME_OBJ(int p0) { return invoke<int>(0xE9E8C31A, p0); } // 0xE9E8C31A
	static int ADD_CORPSE_PREVENT_INTERFERENCE_VOLUME_OBJ(int p0) { return invoke<int>(0x0ACF7E75, p0); } // 0x0ACF7E75
	static int REMOVE_CORPSE_PREVENT_INTERFERENCE_VOLUME_OBJ(int p0) { return invoke<int>(0x80FF115A, p0); } // 0x80FF115A
	static void TOGGLE_COVER_PROPS(Any p0) { invoke<void>(0x288E4BFB, p0); } // 0x288E4BFB
	static int TOGGLE_COVER_PROP(Object p0, int p1) { return invoke<int>(0x35E78298, p0, p1); } // 0x35E78298
	static int CREATE_ZONE_VOLUME(Any p0) { return invoke<int>(0xBB05B731, p0); } // 0xBB05B731
	static int CREATE_VOLUME_SPAWNING_ZONE_VOLUME(int* p0, int p1) { return invoke<int>(0x9189EB8B, p0, p1); } // 0x9189EB8B
	static int CREATE_POPULATION_SET(Any p0) { return invoke<int>(0xAF1D570B, p0); } // 0xAF1D570B
	static int CREATE_POPULATION_SET_IN_LAYOUT(int* p0, int p1) { return invoke<int>(0x0B40BBE3, p0, p1); } // 0x0B40BBE3
	static int CREATE_NAMED_POPULATION_SET(Any p0, Any p1) { return invoke<int>(0xB0882841, p0, p1); } // 0xB0882841
	static int CREATE_GATEWAY_IN_LAYOUT(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) { return invoke<int>(0x4251BF6C, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x4251BF6C
	static int CREATE_GATEWAY_FROM_PARAMS_IN_LAYOUT(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17) { return invoke<int>(0x64BEDDEA, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17); } // 0x64BEDDEA
	static void CREATE_GATEWAY_TYPE(Any p0, Any p1) { invoke<void>(0x92CC441F, p0, p1); } // 0x92CC441F
	static void SNAP_ACTOR_TO_GRINGO(Actor actor) { invoke<void>(0xD0A845E9, actor); } // 0xD0A845E9
	static int _RMPTFX_EFFECT_START(int p0, float p1, float p2, float p3) { return invoke<int>(0x6745191B, p0, p1, p2, p3); } // 0x6745191B
	static int _RMPTFX_EFFECT_START_AND_FADE_IN(int p0, float p1, float p2, float p3) { return invoke<int>(0x276EFF8E, p0, p1, p2, p3); } // 0x276EFF8E
	static int _RMPTFX_EFFECT_STOP(int p0) { return invoke<int>(0xE18028C1, p0); } // 0xE18028C1
	static int _RMPTFX_EFFECT_STOP_AND_RESET(int p0) { return invoke<int>(0x7246F438, p0); } // 0x7246F438
	static int _RMPTFX_EFFECT_STOP_AND_FADE_OUT(int p0) { return invoke<int>(0x1A59E608, p0); } // 0x1A59E608
	static int RESET_RMPTFX_ALL() { return invoke<int>(0x0AFC0B99); } // 0x0AFC0B99
	static int RESET_RMPTFX_IN_VOLUME(int p0) { return invoke<int>(0x547166A7, p0); } // 0x547166A7
	static int CREATE_RMPTFX_EMITTER_IN_LAYOUT(int* p0, int p1, int p2, const char* p3, float p4, float p5, float p6) { return invoke<int>(0xF1F8AFCA, p0, p1, p2, p3, p4, p5, p6); } // 0xF1F8AFCA
	static int CREATE_RMPTFX_EMITTER_ON_OBJECT(int* p0, int p1, int p2, float p3, float p4, float p5) { return invoke<int>(0xFF8CBD07, p0, p1, p2, p3, p4, p5); } // 0xFF8CBD07
	static int CREATE_RMPTFX_EMITTER_ON_BONE(int* p0, int p1, int p2, int p3, float p4, float p5, float p6) { return invoke<int>(0x2A902148, p0, p1, p2, p3, p4, p5, p6); } // 0x2A902148
	static int CREATE_RMPTFX_EMITTER_ON_CURVE(int* p0, int p1, int p2, float p3) { return invoke<int>(0x39286DE5, p0, p1, p2, p3); } // 0x39286DE5
	static int IS_RMPTFX_FINISHED(int p0) { return invoke<int>(0xD3A523FD, p0); } // 0xD3A523FD
	static int SET_RMPTFX_SCALE(int p0) { return invoke<int>(0x1A4C98C1, p0); } // 0x1A4C98C1
	static int HIDE_RMPTFX_EFFECT(int p0) { return invoke<int>(0x21BCC0A9, p0); } // 0x21BCC0A9
	static int SHOW_RMPTFX_EFFECT(int p0) { return invoke<int>(0x5B417C9C, p0); } // 0x5B417C9C
	static int START_RECORDING_SHOOT_EVENTS_FOR_ACTOR(int p0) { return invoke<int>(0x1E56BAFD, p0); } // 0x1E56BAFD
	static int STOP_RECORDING_SHOOT_EVENTS_FOR_ACTOR(int p0) { return invoke<int>(0xCFE22435, p0); } // 0xCFE22435
	static int ADD_FORMATION_LOCATION(Any p0, Any p1) { return invoke<int>(0xFBB1BCDF, p0, p1); } // 0xFBB1BCDF
	static void GET_FORMATION_LOCATION(Any p0, Any p1, Any p2) { invoke<void>(0x17FC65A4, p0, p1, p2); } // 0x17FC65A4
	static int GET_NUM_FORMATION_LOCATIONS(int p0) { return invoke<int>(0xBE5D84BF, p0); } // 0xBE5D84BF
	static Any GET_CRIME_POSITION(Any p0) { return invoke<Any>(0x391475E3, p0); } // 0x391475E3
	static Any GET_CRIME_TYPE(Any p0) { return invoke<Any>(0xDB2BDEA8, p0); } // 0xDB2BDEA8
	static float GET_CRIME_BEGIN_TIMESTAMP(int p0) { return invoke<float>(0xA2DA4D24, p0); } // 0xA2DA4D24
	static float GET_CRIME_END_TIMESTAMP(int p0) { return invoke<float>(0xD96DBABD, p0); } // 0xD96DBABD
	static int GET_CRIME_WITNESSED(int p0) { return invoke<int>(0xE07C2D99, p0); } // 0xE07C2D99
	static Any GET_CRIME_CRIMINAL(Any p0) { return invoke<Any>(0xEC2C34A4, p0); } // 0xEC2C34A4
	static int GET_CRIME_VICTIM(Any p0) { return invoke<int>(0xD2FD7CB6, p0); } // 0xD2FD7CB6
	static int GET_CRIME_WORLD_REGION(Any* p0, int p1) { return invoke<int>(0x67F224B4, p0, p1); } // 0x67F224B4
	static int GET_CRIME_FACTION(Any p0) { return invoke<int>(0xE2FE0673, p0); } // 0xE2FE0673
	static Any GET_CRIME_COUNTER(Any p0) { return invoke<Any>(0xB52BA7E6, p0); } // 0xB52BA7E6
	static BOOL IS_CRIME_TALLIED(int p0) { return invoke<BOOL>(0x72A048B7, p0); } // 0x72A048B7
	static BOOL IS_CRIME_IN_PROGRESS(int p0) { return invoke<BOOL>(0x85C58BE1, p0); } // 0x85C58BE1
	static Any GET_CRIME_OBJECTSET(Any p0) { return invoke<Any>(0x72C52B55, p0); } // 0x72C52B55
	static Any SET_CRIME_OBJECTSET(Any p0, Any p1) { return invoke<Any>(0xD60B8F77, p0, p1); } // 0xD60B8F77
	static Any SET_CRIME_POSITION(Any p0, Any p1) { return invoke<Any>(0xB3F4043B, p0, p1); } // 0xB3F4043B
	static Any SET_CRIME_TYPE(Any p0, Any p1) { return invoke<Any>(0x85425011, p0, p1); } // 0x85425011
	static int SET_CRIME_BEGIN_TIMESTAMP(Any p0, float p1) { return invoke<int>(0x2AE7D51F, p0, p1); } // 0x2AE7D51F
	static int SET_CRIME_END_TIMESTAMP(int p0, float p1) { return invoke<int>(0x898B00F4, p0, p1); } // 0x898B00F4
	static int SET_CRIME_WITNESSED(int p0, int p1) { return invoke<int>(0x6761D53A, p0, p1); } // 0x6761D53A
	static Any SET_CRIME_CRIMINAL(Any p0, Any p1) { return invoke<Any>(0xBA02916B, p0, p1); } // 0xBA02916B
	static void SET_CRIME_VICTIM(Any p0, Any p1) { invoke<void>(0x7B917033, p0, p1); } // 0x7B917033
	static int SET_CRIME_WORLD_REGION(int p0, int p1) { return invoke<int>(0x8521A685, p0, p1); } // 0x8521A685
	static void SET_CRIME_FACTION(Any p0, Any p1) { invoke<void>(0x1E552B26, p0, p1); } // 0x1E552B26
	static Any SET_CRIME_COUNTER(Any p0, Any p1) { return invoke<Any>(0xCC14DC8D, p0, p1); } // 0xCC14DC8D
	static int SET_CRIME_TALLIED(int p0, int p1) { return invoke<int>(0x54E7F26B, p0, p1); } // 0x54E7F26B
	static int SET_CRIME_IN_PROGRESS(int p0, int p1) { return invoke<int>(0x2D6CD106, p0, p1); } // 0x2D6CD106
	static int CREATE_OBJECT_ITERATOR(Layout layout) { return invoke<int>(0xD8A12B74, layout); } // 0xD8A12B74
	static int CREATE_NAMED_OBJECT_ITERATOR(Any* p0, int p1, int p2, int p3, int p4, int p5) { return invoke<int>(0x2F358B89, p0, p1, p2, p3, p4, p5); } // 0x2F358B89
	static Object START_OBJECT_ITERATOR(Iterator iterator) { return invoke<Object>(0xE96A0318, iterator); } // 0xE96A0318
	static int OBJECT_ITERATOR_NEXT(Iterator iterator) { return invoke<int>(0xD88DC865, iterator); } // 0xD88DC865
	static int OBJECT_ITERATOR_PREV(Iterator iterator) { return invoke<int>(0x91A3A831, iterator); } // 0x91A3A831
	static int OBJECT_ITERATOR_CURRENT(Iterator iterator) { return invoke<int>(0x191E32C0, iterator); } // 0x191E32C0
	static void OBJECT_ITERATOR_RESET(Any p0) { invoke<void>(0x351A482F, p0); } // 0x351A482F
	static void ITERATE_ON_PARTIAL_NAME(Any p0, Any p1) { invoke<void>(0x9624A938, p0, p1); } // 0x9624A938
	static void ITERATE_ON_PARTIAL_MODEL_NAME(Any p0, Any p1) { invoke<void>(0xD117DF0D, p0, p1); } // 0xD117DF0D
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eObjectType
	static void ITERATE_ON_OBJECT_TYPE(int iterator, int objectType) { invoke<void>(0xBE553F84, iterator, objectType); } // 0xBE553F84
	static int ITERATE_IN_AREA(Any p0, float p1, float p2, float p3, float p4, float p5, float p6) { return invoke<int>(0xD7A370D5, p0, p1, p2, p3, p4, p5, p6); } // 0xD7A370D5
	static void ITERATE_IN_SPHERE(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x2243FA6E, p0, p1, p2, p3, p4); } // 0x2243FA6E
	static void ITERATE_IN_VOLUME(Any p0, Any p1) { invoke<void>(0x6914D904, p0, p1); } // 0x6914D904
	static void ITERATE_EVERYWHERE(Any p0) { invoke<void>(0xF35C5859, p0); } // 0xF35C5859
	static void ITERATE_IN_LAYOUT(Any p0, Any p1) { invoke<void>(0xF3ABE99C, p0, p1); } // 0xF3ABE99C
	static void ITERATE_IN_SET(Iterator iterator, int iterationSet) { invoke<void>(0xDF6B5E94, iterator, iterationSet); } // 0xDF6B5E94
	static void ITERATE_IN_EVENT_TRAP(int p0, int p1) { invoke<void>(0x0D8BA78E, p0, p1); } // 0x0D8BA78E
	static void ITERATE_IN_VOLUME_SET(int p0, int p1) { invoke<void>(0x8BCB6B86, p0, p1); } // 0x8BCB6B86
	static int GET_ITERATOR_PARENT(Any p0) { return invoke<int>(0x12AA009F, p0); } // 0x12AA009F
	static int GET_NUM_ITERATOR_MATCHES(Iterator iterator) { return invoke<int>(0xA3874D8A, iterator); } // 0xA3874D8A
	static int FIND_OBJECT_IN_OBJECT(Any p0, Any p1) { return invoke<int>(0x070F9693, p0, p1); } // 0x070F9693
	static Object FIND_OBJECT_IN_LAYOUT(Layout layout, const char* layoutName) { return invoke<Object>(0xCF875EFA, layout, layoutName); } // 0xCF875EFA
	static Actor FIND_ACTOR_IN_LAYOUT(Layout layout, const char* layoutName) { return invoke<Actor>(0x53A761DE, layout, layoutName); } // 0x53A761DE
	static Volume FIND_VOLUME_IN_LAYOUT(Layout layout, const char* layoutName) { return invoke<Volume>(0xAC830865, layout, layoutName); } // 0xAC830865
	static int CLEAR_AMBIENT_OBJECTS_SPHERE(float p0, float p1, float p2, float p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0xC9365FBC, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xC9365FBC
	static int CLEAR_AMBIENT_OBJECTS_VOLUME(Any p0, Any p1) { return invoke<int>(0xBB77E597, p0, p1); } // 0xBB77E597
	static int GET_OBJECT_POSITION(Object object, Vector3* position) { return invoke<int>(0x31201B4C, object, position); } // 0x31201B4C
	static int ROTATE_OBJECT_AROUND_AXIS(Any p0, Any p1, float p2) { return invoke<int>(0x3C45D66A, p0, p1, p2); } // 0x3C45D66A
	// rotationOrder 0, 1, 2 - (0 = x, y, z), (1 = ), (2 = z, y, x)
	static int GET_OBJECT_AXIS(Object object, Vector3* axis, int rotationOrder) { return invoke<int>(0xCE412E46, object, axis, rotationOrder); } // 0xCE412E46
	static int GET_OBJECT_RELATIVE_POSITION(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x2243EA59, p0, p1, p2, p3, p4); } // 0x2243EA59
	static int GET_OBJECT_RELATIVE_OFFSET(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x15CDF203, p0, p1, p2, p3, p4); } // 0x15CDF203
	static int GET_OBJECT_RELATIVE_ORIENTATION(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x919583DC, p0, p1, p2, p3, p4); } // 0x919583DC
	static int GET_OBJECT_RELATIVE_ORIENTATION_IN_OBJECT_SPACE(Any p0, float p1, float p2, float p3, Any p4, Any p5, Any p6) { return invoke<int>(0x6689F85C, p0, p1, p2, p3, p4, p5, p6); } // 0x6689F85C
	static int PREPARE_CORPSE_FOR_ANIMAL_CONSUMPTION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xFC718FC5, p0, p1, p2, p3, p4, p5); } // 0xFC718FC5
	static int GET_POSITION_OBJECT_SPACE(Any p0, float p1, float p2, float p3, Any p4, Any p5, Any p6) { return invoke<int>(0x663F1464, p0, p1, p2, p3, p4, p5, p6); } // 0x663F1464
	static void GET_OBJECT_ORIENTATION(Object object, Vector3* orientation) { invoke<void>(0x27B7D6D6, object, orientation); } // 0x27B7D6D6
	static float GET_OBJECT_HEADING(Object object) { return invoke<float>(0x1C02D2F8, object); } // 0x1C02D2F8
	static int SET_OBJECT_POSITION(Object object, Vector2 positionXY, float positionZ) { return invoke<int>(0xC5D796F8, object, positionXY, positionZ); } // 0xC5D796F8
	static int SET_OBJECT_POSITION(Object object, Vector3 positionxy) { return invoke<int>(0xC5D796F8, object, Vector2(positionxy.x, positionxy.y), positionxy.z); } // 0xC5D796F8
	static int SET_OBJECT_POSITION_ON_GROUND(Object object, Vector3* position) { return invoke<int>(0x5AB0BBA6, object, position); } // 0x5AB0BBA6
	static int SET_OBJECT_ORIENTATION(Object object, Vector2 orientationXY, float orientationZ) { return invoke<int>(0xC8A4EE74, object, orientationXY, orientationZ); } // 0xC8A4EE74
	static int SET_OBJECT_ORIENTATION(Object object, Vector3 orientationxy) { return invoke<int>(0xC8A4EE74, object, Vector2(orientationxy.x, orientationxy.y), orientationxy.z); } // 0xC8A4EE74
	static int SNAP_OBJECT_TO_GROUND(Object object, float p1, int p2, int p3) { return invoke<int>(0xF437B3D9, object, p1, p2, p3); } // 0xF437B3D9
	static int GET_OBJECT_NAMED_BONE_POSITION(Any p0, Any p1, Any p2) { return invoke<int>(0x30516389, p0, p1, p2); } // 0x30516389
	static Any GET_OBJECT_NAMED_BONE_ORIENTATION(Any p0, Any p1) { return invoke<Any>(0xCAD543AD, p0, p1); } // 0xCAD543AD
	static int TELEPORT_OBJECT_TO_OBJECT(Any p0, Any p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8) { return invoke<int>(0x8C0E3E29, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x8C0E3E29
	static BOOL IS_OBJECT_ATTACHED(Any p0) { return invoke<BOOL>(0xAD08BA79, p0); } // 0xAD08BA79
	static int GET_OBJECT_ATTACHEMENT(Any* p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x78B73E47, p0, p1, p2, p3, p4, p5); } // 0x78B73E47
	static int GET_OBJECT_ATTACHED_TO(Any p0) { return invoke<int>(0x533475AE, p0); } // 0x533475AE
	static int ATTACH_OBJECTS(Object object1, Object object2, const char* locator, Vector2 positionXY, float positionZ, Vector2 orientationXY, float orientationZ, int p9) { return invoke<int>(0xE1421B42, object1, object2, locator, positionXY, positionZ, orientationXY, orientationZ, p9); } // 0xE1421B42
	static int ATTACH_OBJECTS(Object object1, Object object2, const char* locator, Vector3 positionxy, Vector3 orientationxy, int p9) { return invoke<int>(0xE1421B42, object1, object2, locator, Vector2(positionxy.x, positionxy.y), positionxy.z, Vector2(orientationxy.x, orientationxy.y), orientationxy.z, p9); } // 0xE1421B42
	static int ATTACH_OBJECTS_NO_DRV(Any* p0, Any p1, Any p2, Any p3, float p4, float p5, float p6, float p7, float p8, float p9) { return invoke<int>(0xCC277C0A, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xCC277C0A
	static int ATTACH_OBJECTS_USING_LOCATOR(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xB6506558, p0, p1, p2, p3, p4); } // 0xB6506558
	static int ATTACH_OBJECTS_CONTINUOUS(Any p0, Any p1, Any p2) { return invoke<int>(0x319D70BD, p0, p1, p2); } // 0x319D70BD
	static int ATTACH_OBJECTS_PHYSICAL(Any* p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x1D711058, p0, p1, p2, p3, p4); } // 0x1D711058
	static int ATTACH_SET_ROTATIONAL_CONSTRAINT(Any p0, float p1, float p2, float p3, float p4, float p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x325F7E50, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x325F7E50
	static Any IS_ATTACHMENT_VALID(Any p0) { return invoke<Any>(0x50305244, p0); } // 0x50305244
	static void REMOVE_OBJECT_ATTACHMENT(Any p0) { invoke<void>(0xE894DC13, p0); } // 0xE894DC13
	static int REMOVE_OBJECT_FROM_ATTACHMENT(Any p0) { return invoke<int>(0x67FC68DB, p0); } // 0x67FC68DB
	static int REMOVE_ALL_OBJECT_ATTACHMENTS(Any p0) { return invoke<int>(0x8FB32562, p0); } // 0x8FB32562
	static int SET_ATTACHMENT_LOCAL_ROTATION(int p0, float p1, float p2, float p3) { return invoke<int>(0x2F7B457B, p0, p1, p2, p3); } // 0x2F7B457B
	static int SET_ATTACHMENT_LOCAL_OFFSET(int p0, float p1, float p2, float p3) { return invoke<int>(0xD4A54348, p0, p1, p2, p3); } // 0xD4A54348
	static int SET_ATTACHMENT_IGNORE_ROTATION(int p0, Any p1) { return invoke<int>(0xA870B28E, p0, p1); } // 0xA870B28E
	static void REFERENCE_OBJECT(Any p0) { invoke<void>(0x3EEA78A8, p0); } // 0x3EEA78A8
	static void REFERENCE_ACTOR(Any p0) { invoke<void>(0xE9AABF2F, p0); } // 0xE9AABF2F
	static void DEREFERENCE_OBJECT(Any p0) { invoke<void>(0xCEA40973, p0); } // 0xCEA40973
	static void DEREFERENCE_ACTOR(Any p0) { invoke<void>(0x92339B5E, p0); } // 0x92339B5E
	static int INIT_NATIVE_ACTORENUM_PLAYER(int p0, int p1, int p2) { return invoke<int>(0xCBA75200, p0, p1, p2); } // 0xCBA75200
	static int INIT_NATIVE_ACTORENUM_HUMAN(int p0, int p1, int p2) { return invoke<int>(0x88FD9623, p0, p1, p2); } // 0x88FD9623
	static int INIT_NATIVE_ACTORENUM_ANIMAL(int p0, int p1, int p2) { return invoke<int>(0x192973A0, p0, p1, p2); } // 0x192973A0
	static int INIT_NATIVE_ACTORENUM_RIDEABLE_ANIMAL(int p0, int p1, int p2) { return invoke<int>(0x4D42E285, p0, p1, p2); } // 0x4D42E285
	static int INIT_NATIVE_ACTORENUM_FLYING_ANIMAL(int p0, int p1, int p2) { return invoke<int>(0xE694F53A, p0, p1, p2); } // 0xE694F53A
	static int INIT_NATIVE_ACTORENUM_VEHICLE(int p0, int p1, int p2) { return invoke<int>(0x6D0B8619, p0, p1, p2); } // 0x6D0B8619
	static int INIT_NATIVE_ACTORENUM_TRAIN(int p0, int p1, int p2) { return invoke<int>(0x807B9519, p0, p1, p2); } // 0x807B9519
	static int INIT_NATIVE_ACTORENUM_DLC_PLAYER(int p0, int p1, int p2) { return invoke<int>(0x1904CC1D, p0, p1, p2); } // 0x1904CC1D
	static int INIT_NATIVE_ACTORENUM_DLC_HUMAN(int p0, int p1, int p2) { return invoke<int>(0x1957B498, p0, p1, p2); } // 0x1957B498
	static int INIT_NATIVE_ACTORENUM_DLC_ANIMAL(int p0, int p1, int p2) { return invoke<int>(0x05195632, p0, p1, p2); } // 0x05195632
	static int INIT_NATIVE_ACTORENUM_DLC_RIDEABLE_ANIMAL(int p0, int p1, int p2) { return invoke<int>(0x10BD98C9, p0, p1, p2); } // 0x10BD98C9
	static int INIT_NATIVE_ACTORENUM_DLC_FLYING_ANIMAL(int p0, int p1, int p2) { return invoke<int>(0x8A4F9046, p0, p1, p2); } // 0x8A4F9046
	static int INIT_NATIVE_ACTORENUM_DLC_VEHICLE(int p0, int p1, int p2) { return invoke<int>(0x495026DA, p0, p1, p2); } // 0x495026DA
	static int INIT_NATIVE_ACTORENUM_DLC_TRAIN(int p0, int p1, int p2) { return invoke<int>(0x8C9721D6, p0, p1, p2); } // 0x8C9721D6
	static int IS_ACTORENUM_DLC(int p0) { return invoke<int>(0xF2140DEE, p0); } // 0xF2140DEE
	static BOOL IS_ACTORENUM_INSTALLED(int p0) { return invoke<BOOL>(0x9B903F45, p0); } // 0x9B903F45
	static int IS_ACTORENUM_PLACEHOLDER(int p0) { return invoke<int>(0x16D1E1B4, p0); } // 0x16D1E1B4
	// gohActorEnumAnimal::SetLockPositionActorEnumAnimal
	static int SET_LOCK_OFFSET_ACTORENUM_ANIMAL(int p0) { return invoke<int>(0xC741F051, p0); } // 0xC741F051
	// actorEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eActorEnum
	static Actor CREATE_ACTOR_IN_LAYOUT(Layout layout, const char* layoutName, int actorEnum, Vector2 positionXY, float positionZ, Vector2 orientationXY, float orientationZ) { return invoke<Actor>(0x8D67F397, layout, layoutName, actorEnum, positionXY, positionZ, orientationXY, orientationZ); } // 0x8D67F397
	static Actor CREATE_ACTOR_IN_LAYOUT(Layout layout, const char* layoutName, int actorEnum, Vector3 positionxy, Vector3 orientationxy) { return invoke<Actor>(0x8D67F397, layout, layoutName, actorEnum, Vector2(positionxy.x, positionxy.y), positionxy.z, Vector2(orientationxy.x, orientationxy.y), orientationxy.z); } // 0x8D67F397
	static int CREATE_PLAYER_ACTOR_IN_LAYOUT(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) { return invoke<int>(0x6A307D5F, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x6A307D5F
	static Any CREATE_PERS_CHAR_IN_LAYOUT(Any p0, Any p1, Any p2, Any p3, Any p5, Any p6) { return invoke<Any>(0x013B3937, p0, p1, p2, p3, p5, p6); } // 0x013B3937
	static Any CREATE_ACTOR_VARIATION_IN_LAYOUT(Any p0) { return invoke<Any>(0xCCC0A3F3, p0); } // 0xCCC0A3F3
	// actorEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eActorEnum
	static Actor RESPAWN_PLAYER_ACTOR_IN_LAYOUT(Layout layout, Actor actor, const char* layoutName, int actorEnum, Vector2 positionXY, float positionZ, Vector2 orientationXY, float orientationZ, int unk0) { return invoke<Actor>(0x637E446B, layout, actor, layoutName, actorEnum, positionXY, positionZ, orientationXY, orientationZ, unk0); } // 0x637E446B
	static Actor RESPAWN_PLAYER_ACTOR_IN_LAYOUT(Layout layout, Actor actor, const char* layoutName, int actorEnum, Vector3 positionxy, Vector3 orientationxy, int unk0) { return invoke<Actor>(0x637E446B, layout, actor, layoutName, actorEnum, Vector2(positionxy.x, positionxy.y), positionxy.z, Vector2(orientationxy.x, orientationxy.y), orientationxy.z, unk0); } // 0x637E446B
	static BOOL IS_ACTOR_INITED(Actor actor) { return invoke<BOOL>(0x24F4DAB2, actor); } // 0x24F4DAB2
	static int GET_ACTOR_ENUM(Actor actor) { return invoke<int>(0x0B28E9EC, actor); } // 0x0B28E9EC
	static const char* GET_ACTOR_ENUM_STRING(Actor actor) { return invoke<const char*>(0xD98CB6F6, actor); } // 0xD98CB6F6
	static int GET_ACTOR_ENUM_FROM_STRING(const char* actorEnumString) { return invoke<int>(0xC739D1D2, actorEnumString); } // 0xC739D1D2
	// actorEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eActorEnum
	static const char* GET_ACTOR_ENUM_STRING_FROM_ENUM(int actorEnum) { return invoke<const char*>(0x990614C1, actorEnum); } // 0x990614C1
	static int GET_ACTOR_ENUM_VARIATION_COUNT(int actorEnum) { return invoke<int>(0xB50E95D7, actorEnum); } // 0xB50E95D7
	static int GET_ACTOR_ENUM_FACTION() { return invoke<int>(0x2803BDA8); } // 0x2803BDA8
	// outfitId: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eOutfit
	static int SWITCH_ACTOR_ENUM_VARIATION(Actor actor, int outfitId) { return invoke<int>(0x7AB17813, actor, outfitId); } // 0x7AB17813
	static void SWITCH_PLAYER_TO_ENUM(Actor actor, float value) { invoke<void>(0x95FBA0B0, actor, value); } // 0x95FBA0B0
	static void TURN_ACTOR_INTO_ZOMBIE(Actor actor, Any p1) { invoke<void>(0x39928706, actor, p1); } // 0x39928706
	static void SET_ACTOR_HARD_LOCK_AQUIRE_BONE_CASUAL(int p0) { invoke<void>(0x12A86E9D, p0); } // 0x12A86E9D
	static void SET_ACTOR_HARD_LOCK_AQUIRE_BONE(int p0) { invoke<void>(0x5613615B, p0); } // 0x5613615B
	// outfitId: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eOutfit
	static int GET_CURRENT_ACTOR_ENUM_VARIATION(Actor actor) { return invoke<int>(0xB54567B9, actor); } // 0xB54567B9
	// assetType: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAssetType
	static int REQUEST_ASSET(const char* assetPath, int assetType) { return invoke<int>(0x9AA02DA7, assetPath, assetType); } // 0x9AA02DA7
	// assetType: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAssetType
	static int GET_ASSET_ID(const char* assetPath, int assetType) { return invoke<int>(0x6005B514, assetPath, assetType); } // 0x6005B514
	static int REMOVE_ASSET(Any p0, Any p1) { return invoke<int>(0xE7829D28, p0, p1); } // 0xE7829D28
	// rdr2GOH::GetTypeIDUsingActorEnum
	static Any AE_GET_ASSET_ID(Any p0) { return invoke<Any>(0x55E6227E, p0); } // 0x55E6227E
	static Any GET_ASSET_NAME(Any p0) { return invoke<Any>(0x9EDBBB84, p0); } // 0x9EDBBB84
	static BOOL IS_ASSETTYPEID_VALID(int p0) { return invoke<BOOL>(0x214AFB8C, p0); } // 0x214AFB8C
	static BOOL IS_ASSETTYPEID_VALID_BY_STRING(Any p0, int p1, int p2, int p3, int p4) { return invoke<BOOL>(0xFDF42AAC, p0, p1, p2, p3, p4); } // 0xFDF42AAC
	static int GET_CORPSE_ACTOR_ENUM(int p0) { return invoke<int>(0x1FCC8FEF, p0); } // 0x1FCC8FEF
	static int GET_PREVIOUS_ACTOR_FROM_CORPSE(int p0, int p1) { return invoke<int>(0xAF2597E8, p0, p1); } // 0xAF2597E8
	static int REQUEST_ARTICULATED_CORPSE(int p0) { return invoke<int>(0x97951004, p0); } // 0x97951004
	static int REQUEST_FIXED_CORPSE(Any p0, Any p1) { return invoke<int>(0x0D447878, p0, p1); } // 0x0D447878
	static int SET_PROP_COLLIDE_WITH_WORLD(int p0, int p1) { return invoke<int>(0xCEC355CE, p0, p1); } // 0xCEC355CE
	static int SET_PROP_COLLIDE_WITH_MOVABLES(int p0, int p1) { return invoke<int>(0x418A22D5, p0, p1); } // 0x418A22D5
	static int SET_PROP_COLLIDE_WITH_OBJECT(int p0, int p1, int p2) { return invoke<int>(0x77403213, p0, p1, p2); } // 0x77403213
	static int SET_OBJECT_COLLIDE_WITH_WORLD(int p0, int p1) { return invoke<int>(0x601FC9F4, p0, p1); } // 0x601FC9F4
	static int SET_OBJECT_COLLIDE_WITH_MOVABLES(int p0, int p1) { return invoke<int>(0x05D69EA6, p0, p1); } // 0x05D69EA6
	static int SET_OBJECT_COLLIDE_WITH_OBJECT(int p0, int p1, int p2) { return invoke<int>(0x9AC1CA75, p0, p1, p2); } // 0x9AC1CA75
	static int SET_PROP_AI_OBSTACLE_ENABLED(Any p0, Any p1) { return invoke<int>(0x0DC83543, p0, p1); } // 0x0DC83543
	static int GET_CURVE_FROM_OBJECT(Any p0) { return invoke<int>(0x49D0DF2E, p0); } // 0x49D0DF2E
	static void DESTROY_CURVEQUERY(Any p0) { invoke<void>(0xDF93BD7C, p0); } // 0xDF93BD7C
	static void DESTROY_CAMERA(Cam camera) { invoke<void>(0x767E08D0, camera); } // 0x767E08D0
	static void DESTROY_CAMERA_SHOT(Cam camera) { invoke<void>(0x59C2DC62, camera); } // 0x59C2DC62
	static Any CREATE_WORLD_SECTOR(Any p0, Any p1) { return invoke<Any>(0xC94CC336, p0, p1); } // 0xC94CC336
	static BOOL IS_WORLD_SECTOR_LOADED(Any p0) { return invoke<BOOL>(0xBF81A6C4, p0); } // 0xBF81A6C4
	static void MARK_REGION_READY(Any p0) { invoke<void>(0x276A420B, p0); } // 0x276A420B
	static int GET_WORLD_SECTOR_CHILD_OBJECT(Any p0, Any p1, Any p2) { return invoke<int>(0xA5F229C9, p0, p1, p2); } // 0xA5F229C9
	static int DEBUG_SELECT_OBJECT(Any p0) { return invoke<int>(0x0F146D2C, p0); } // 0x0F146D2C
	static int DEBUG_ASSERT_ON_SELECTED_DESTRUCTION() { return invoke<int>(0xF46FC138); } // 0xF46FC138
	static int SAVE_POP_SET_BIRDS_SPAWNING_FROM_TREES(Any p0) { return invoke<int>(0x03B2D067, p0); } // 0x03B2D067
	static void SET_TOWN_VOLUME_FOR_AMBIENT_PEDS(Any p0) { invoke<void>(0x6C526E7B, p0); } // 0x6C526E7B
	static int SAVE_POP_SET_HUMAN_SPAWNING_IN_TOWN(Any p0) { return invoke<int>(0xC1195126, p0); } // 0xC1195126
	static int SAVE_POP_SET_HUMAN_SPAWNING_IN_TOWN_CONVERSATION_FULL(Any p0) { return invoke<int>(0x00CDD849, p0); } // 0x00CDD849
	static int SAVE_POP_SET_HUMAN_SPAWNING_IN_TOWN_CONVERSATION_RESPONSE(Any p0) { return invoke<int>(0x6138B1B8, p0); } // 0x6138B1B8
	static int SET_AGRESSIVE_EVENT_TOWN_BBX(Any p0) { return invoke<int>(0xCE081203, p0); } // 0xCE081203
	static int SET_AGRESSIVE_EVENT_TIME_RANGE() { return invoke<int>(0xBF6E9855); } // 0xBF6E9855
	static int SET_AGRESSIVE_EVENT_LOOP() { return invoke<int>(0x4193D42F); } // 0x4193D42F
	static void SET_AGRESSIVE_EVENT_ON(Any p0) { invoke<void>(0xF037DCA2, p0); } // 0xF037DCA2
	static void SET_TOWN_DENSITY(Any p0) { invoke<void>(0x3748F199, p0); } // 0x3748F199
	static void SET_WEATHER_POP_DENSITY(Any p0, Any p1) { invoke<void>(0x03CD9C87, p0, p1); } // 0x03CD9C87
	static int SET_SPAWN_PEDS_ON_SIDEWALK(Any p0) { return invoke<int>(0x43FF4632, p0); } // 0x43FF4632
}

namespace PATH
{
	static int SET_PATH_LOOPING(Any p0, Any p1) { return invoke<int>(0x44930268, p0, p1); } // 0x44930268
	static int ADD_POINT_TO_PATH(Any p0, float p1, float p2, float p3) { return invoke<int>(0xECC40138, p0, p1, p2, p3); } // 0xECC40138
	static int SET_POINT_IN_PATH(Any p0, Any p1, float p2, float p3, float p4) { return invoke<int>(0xCD89FB70, p0, p1, p2, p3, p4); } // 0xCD89FB70
	static int GET_NUM_PATH_POINTS(Any p0) { return invoke<int>(0xBD374C00, p0); } // 0xBD374C00
	static int GET_PATH_NUM_POINTS(Any p0) { return invoke<int>(0x42A4CCD5, p0); } // 0x42A4CCD5
	static void GET_PATH_POINT(Any p0, Any p1, Any p2) { invoke<void>(0x415F635C, p0, p1, p2); } // 0x415F635C
	static float ESTIMATE_PATH_LENGTH(Any p0) { return invoke<float>(0x2B02A877, p0); } // 0x2B02A877
	static int ESTIMATE_DISTANCE_ALONG_PATH(Any p0, Any p1, Any p2, float p3, Any p4) { return invoke<int>(0x7A00433F, p0, p1, p2, p3, p4); } // 0x7A00433F
	static void ESTIMATE_TWO_DISTANCES_ALONG_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0xA1D9AF6B, p0, p1, p2, p3, p4, p5); } // 0xA1D9AF6B
}

namespace PC
{
	// PC only, used by lassogringo.wsc
	static Any SET_HOGTYING(Any p0) { return invoke<Any>(0x8CF09BD7, p0); } // 0x8CF09BD7
	// PC only, used by passenger_camp.wsc / player_z.wsc / player.wsc
	static Any SET_FASTTRAVEL(Any p0) { return invoke<Any>(0xBAE0A3F8, p0); } // 0xBAE0A3F8
	// PC only, used by blackwater_z.wsc
	static Any _0x9F832205(Any p0) { return invoke<Any>(0x9F832205, p0); } // 0x9F832205
	// PC only, used by event_treasurehunter_intro.wsc
	static Any _0xF413FDB2(Any p0) { return invoke<Any>(0xF413FDB2, p0); } // 0xF413FDB2
	// PC only, used by event_law_repsonse_*.wsc
	static Any _0x63D3AAFC(Any p0) { return invoke<Any>(0x63D3AAFC, p0); } // 0x63D3AAFC
	// PC only, used by *_z.wsc
	static Any _0x3B93B981(Any p0) { return invoke<Any>(0x3B93B981, p0); } // 0x3B93B981
	// PC only, used by job_horsebreaking.wsc
	static Any SET_HORSE_BREAK_INTRO(Any p0) { return invoke<Any>(0x854ACCFE, p0); } // 0x854ACCFE
	// PC only, used by event_bountyhunter.wsc
	static Any _0xEB0F9F0C(Any p0) { return invoke<Any>(0xEB0F9F0C, p0); } // 0xEB0F9F0C
	// PC only, used by player_sleep_to_save.wsc
	static Any SET_SAVING_GAME(Any p0) { return invoke<Any>(0xFD198D8B, p0); } // 0xFD198D8B
	// PC only, used by zombiepack_sleepgringo.wsc
	static Any SET_SAVING_GAME_ZOMBIE(Any p0) { return invoke<Any>(0xA62D75BA, p0); } // 0xA62D75BA
	// PC only, used by event_first_pay_cutscene.wsc
	static Any SET_FIRST_PAY_CUTSCENE(Any p0) { return invoke<Any>(0x7C730896, p0); } // 0x7C730896
	// PC only, used by merchant05.wsc
	static Any _0x02859CE6(Any p0) { return invoke<Any>(0x02859CE6, p0); } // 0x02859CE6
	// PC only, used by armadillo.wsc
	static Any SET_ARMADILLO_MOVIE_PLAYING(Any p0) { return invoke<Any>(0x5B47E49A, p0); } // 0x5B47E49A
	// PC only, used by blackwater.wsc
	static Any SET_BLACKWATER_MOVIE_PLAYING(Any p0) { return invoke<Any>(0x97609434, p0); } // 0x97609434
	// PC only, used by event_player_in_jail.wsc
	static Any SET_IN_PRISON(Any p0) { return invoke<Any>(0x0920DB21, p0); } // 0x0920DB21
	// PC only, used by ranch02.wsc
	static Any _0x9CED1C7E(Any p0) { return invoke<Any>(0x9CED1C7E, p0); } // 0x9CED1C7E
	// PC only, used by gun01.wsc
	static Any _0xD9DDA7E2(Any p0) { return invoke<Any>(0xD9DDA7E2, p0); } // 0xD9DDA7E2
	// PC only, used by binoculars.wsc
	static Any SET_USING_BINOCULARS(Any p0) { return invoke<Any>(0x14664FF4, p0); } // 0x14664FF4
	// PC only, used by event_pay_bounty.wsc
	static Any SET_PAYING_BOUNTY(Any p0) { return invoke<Any>(0xB0E60B63, p0); } // 0xB0E60B63
}

namespace PERSCHAR
{
	static void ACTIVATE_ACTOR_FOR_PERS_CHAR(PersChar persChar) { invoke<void>(0x2CA16327, persChar); } // 0x2CA16327
	static void DEACTIVATE_ACTOR_FOR_PERS_CHAR(PersChar persChar) { invoke<void>(0x9B2A39BC, persChar); } // 0x9B2A39BC
	static void DEACTIVATE_ACTORS_FOR_PERS_CHARS_IN_VOLUME(PersChar persChar) { invoke<void>(0x6F8C238B, persChar); } // 0x6F8C238B
	static Actor GET_ACTOR_FROM_PERS_CHAR(PersChar persChar) { return invoke<Actor>(0xE04ED21E, persChar); } // 0xE04ED21E
	static int GET_PERS_CHAR_DEATH_TIMESTAMP(Vector3* deathInfo) { return invoke<int>(0xD78D1B4F, deathInfo); } // 0xD78D1B4F
	static PersChar GET_PERS_CHAR_FROM_ACTOR(Actor actor) { return invoke<PersChar>(0x69DA275F, actor); } // 0x69DA275F
	static void SET_PERS_CHAR_SAFE_ZONE(PersChar persChar, float safeZoneRadius) { invoke<void>(0x67258116, persChar, safeZoneRadius); } // 0x67258116
	static BOOL IS_PERS_CHAR_ALIVE(PersChar persChar) { return invoke<BOOL>(0x5F3A1B81, persChar); } // 0x5F3A1B81
	static void REVIVE_PERS_CHAR(PersChar persChar, BOOL fullRevive) { invoke<void>(0xEDA4B02B, persChar, fullRevive); } // 0xEDA4B02B
	static void SET_PERS_CHAR_EXEMPT_FROM_AMBIENT_RESTRICTIONS(PersChar persChar, BOOL exemptFromRestrictions) { invoke<void>(0x2A709F33, persChar, exemptFromRestrictions); } // 0x2A709F33
	static void SET_PERS_CHAR_ENABLED(PersChar persChar, BOOL toggle) { invoke<void>(0xC85CFEA9, persChar, toggle); } // 0xC85CFEA9
	static void SET_PERS_CHAR_ALLOW_SPAWN_ELSEWHERE(PersChar persChar, BOOL allowSpawnElsewhere) { invoke<void>(0x366B0AD1, persChar, allowSpawnElsewhere); } // 0x366B0AD1
}

namespace PHYSICS
{
	static void GET_PHYSINST_VELOCITY(Any p0, Any p1) { invoke<void>(0x17B69196, p0, p1); } // 0x17B69196
	static BOOL IS_PHYSINST_ACTIVE(int physinst) { return invoke<BOOL>(0xAFB1DFA2, physinst); } // 0xAFB1DFA2
	static void SET_PHYSINST_COLLIDES_AGAINST_INACTIVE(Any p0, Any p1) { invoke<void>(0x38636EBF, p0, p1); } // 0x38636EBF
	static void SET_PHYSINST_FROZEN(int physinst, BOOL toggle) { invoke<void>(0x2C0AF634, physinst, toggle); } // 0x2C0AF634
	static BOOL IS_PHYSINST_FROZEN(int physinst) { return invoke<BOOL>(0x789AA2B2, physinst); } // 0x789AA2B2
	static int SET_PHYSINST_HIDE(int physinst, BOOL toggle) { return invoke<int>(0xEBD9DFE6, physinst, toggle); } // 0xEBD9DFE6
	static BOOL IS_PHYSINST_HIDE(int physinst) { return invoke<BOOL>(0x445990D8, physinst); } // 0x445990D8
	static void BREAK_OFF_ABOVE(Any p0, Any p1) { invoke<void>(0xB5F9F4CF, p0, p1); } // 0xB5F9F4CF
	static int GET_LOCATOR_OFFSETS(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x0BA5E579, p0, p1, p2, p3); } // 0x0BA5E579
	static int SET_INFINITE_MASS_VS_MOVERS(Any p0, Any p1) { return invoke<int>(0xFD759593, p0, p1); } // 0xFD759593
	static int SET_GLOBAL_DISABLE_SPU_COLLIDER_UPDATE(const char* p0) { return invoke<int>(0x87A2C1D5, p0); } // 0x87A2C1D5
	static int SET_GLOBAL_AGGRESSIVE_CORPSE_RECYCLING(Any p0) { return invoke<int>(0x374DE883, p0); } // 0x374DE883
	static int LIQUID_TEST_SET_VELOCITY_SCALE(float p0) { return invoke<int>(0x89B45C7D, p0); } // 0x89B45C7D
	static int CLEAN_CACHE_ENTRIES() { return invoke<int>(0x4C02E1E5); } // 0x4C02E1E5
}

namespace PHYSINST
{
	static BOOL IS_PROP_BROKEN(Any p0) { return invoke<BOOL>(0x25277BBC, p0); } // 0x25277BBC
	static Any GET_PROP_VELOCITY(Any p0, Any p1) { return invoke<Any>(0x5AEA8801, p0, p1); } // 0x5AEA8801
	static int SET_PROP_VELOCITY(Any p0, Any p1) { return invoke<int>(0x28425D8C, p0, p1); } // 0x28425D8C
	static int SET_PROP_ANGULAR_VELOCITY_DEGS(Any p0, Any p1) { return invoke<int>(0x544BCE48, p0, p1); } // 0x544BCE48
	static int SET_PROP_VELOCITY_ON_AXIS(Any p0, Any p1, Any p2) { return invoke<int>(0xC9F3981D, p0, p1, p2); } // 0xC9F3981D
	static Any IS_PHYSINST_VALID(Any p0) { return invoke<Any>(0x16C0A6CB, p0); } // 0x16C0A6CB
	static BOOL IS_PHYSINST_READY(Any p0) { return invoke<BOOL>(0xE83E6A41, p0); } // 0xE83E6A41
	static BOOL IS_PHYSINST_IN_LEVEL(Any p0) { return invoke<BOOL>(0x6243A6AF, p0); } // 0x6243A6AF
	static void SET_SLEEP_TOLERANCE(Any p0, Any p1) { invoke<void>(0x750ADBE5, p0, p1); } // 0x750ADBE5
	static void SET_BRIDGE_STIFFNESS(Any p0, Any p1) { invoke<void>(0x987FD4F6, p0, p1); } // 0x987FD4F6
	static void ACTIVATE_PHYSINST(Any p0) { invoke<void>(0xC0961D18, p0); } // 0xC0961D18
	static int HAS_PHYSINST_BROKEN_APART(Any p0) { return invoke<int>(0x65CA3037, p0); } // 0x65CA3037
	static int LOCATE_PHYSINST_OF_TYPE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x734CC17B, p0, p1, p2, p3, p4, p5); } // 0x734CC17B
	static int LOCATE_PHYSINST_OF_PARTIAL_TYPE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x4FF36FA7, p0, p1, p2, p3, p4, p5); } // 0x4FF36FA7
	static int LOCATE_PHYSINSTS_OF_PARTIAL_TYPE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xC5E372BC, p0, p1, p2, p3); } // 0xC5E372BC
	static int ATTACH_PHYSINST_TO_WORLD2(Any p0, Any p1, Any p2, Any p3, Any p4, float p5) { return invoke<int>(0x441CDD55, p0, p1, p2, p3, p4, p5); } // 0x441CDD55
	static int ATTACH_PHYSINST_TO_WORLD2_HIGH_QUALITY(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x4A05AA7D, p0, p1, p2, p3, p4); } // 0x4A05AA7D
	static void RELEASE_CONSTRAINT(Any p0) { invoke<void>(0x8B9659EF, p0); } // 0x8B9659EF
	static void HIDE_PHYSINST(int physinst) { invoke<void>(0x0D6BFDD9, physinst); } // 0x0D6BFDD9
	static void SHOW_PHYSINST(int physinst) { invoke<void>(0x342FDCD6, physinst); } // 0x342FDCD6
	static void SET_SECTOR_PROPS_SUPER_LOCKED(Any p0, Any p1) { invoke<void>(0xED3ADF67, p0, p1); } // 0xED3ADF67
	static void LIGHTS_SET_ON_TIME(Any p0, Any p1) { invoke<void>(0x3774465F, p0, p1); } // 0x3774465F
	static void LIGHTS_SET_OFF_TIME(Any p0, Any p1) { invoke<void>(0xD0CDEED4, p0, p1); } // 0xD0CDEED4
	static int SET_PROP_NO_FADE(Any p0) { return invoke<int>(0x1260ACCC, p0); } // 0x1260ACCC
}

namespace PLAYERNAMES
{
	static void NET_GAMER_SET_ACTOR_OVERRIDE(Any p0, Any p1) { invoke<void>(0x77D6ABF5, p0, p1); } // 0x77D6ABF5
	static void NET_GAMER_SET_TEAM(Any p0, Any p1) { invoke<void>(0xE79F6CD4, p0, p1); } // 0xE79F6CD4
	static int NET_GAMER_SETMY_JPN_TITLE(Any p0) { return invoke<int>(0xFD91BE0D, p0); } // 0xFD91BE0D
	static int NET_GAMER_GET_JPN_TITLE(Any p0) { return invoke<int>(0xE2E6C722, p0); } // 0xE2E6C722
	static int NET_GAMER_BARKER_ACCEPT(Any p0) { return invoke<int>(0xCE8F6304, p0); } // 0xCE8F6304
	static int NET_GAMER_BARKER_REJECT(Any p0) { return invoke<int>(0xAB32D5D9, p0); } // 0xAB32D5D9
	static void NET_GAMER_SET_TITLE(Any p0, Any p1, Any p2) { invoke<void>(0x7BD7A465, p0, p1, p2); } // 0x7BD7A465
	static int NET_GAMER_ICON_SET_LIFE(Any p0, float p1, float p2) { return invoke<int>(0x2357CA74, p0, p1, p2); } // 0x2357CA74
	static int NET_GAMER_ICON_FORCE_VISIBILITY(Any p0, Any p1) { return invoke<int>(0x160E79C6, p0, p1); } // 0x160E79C6
	static int NET_GAMER_ICON_RESET_TIMER(Any p0, float p1) { return invoke<int>(0xB5DDEF68, p0, p1); } // 0xB5DDEF68
	static int NET_GAMER_ICON_FORCE_HIDDEN(Any p0, Any p1) { return invoke<int>(0x34960D06, p0, p1); } // 0x34960D06
	static Any NET_GAMER_ICON_FORCE_TEXT_VISIBLE(Any p0) { return invoke<Any>(0xE783219A, p0); } // 0xE783219A
	static void NET_GAMER_ICON_FORCE_VISIBLE(Any p0) { invoke<void>(0x1958F478, p0); } // 0x1958F478
	static Any NET_GAMER_ICONS_SHOW_LOCAL(Any p0) { return invoke<Any>(0x2FB85996, p0); } // 0x2FB85996
	static int NET_GAMER_ICONS_SET_STEALTH(Any p0) { return invoke<int>(0xF34B8448, p0); } // 0xF34B8448
	static int NET_GAMER_BLIPS_SET_STEALTH(Any p0) { return invoke<int>(0x796E66E7, p0); } // 0x796E66E7
	static int NET_HUD_TUNE_VALUE(Any p0, Any p1) { return invoke<int>(0x650A7440, p0, p1); } // 0x650A7440
	static int NET_GAMER_SET_ICON_STEALTH_OVERRIDE(Any p0, Any p1) { return invoke<int>(0xA0A5FF80, p0, p1); } // 0xA0A5FF80
	static int NET_GAMER_SET_BLIP_STEALTH_OVERRIDE(Any p0, Any p1) { return invoke<int>(0x2634F265, p0, p1); } // 0x2634F265
	static void NET_GAMER_SET_BLIP_OVERRIDE(Any p0, Any p1) { invoke<void>(0x4A2E7533, p0, p1); } // 0x4A2E7533
	static Any NET_GAMER_BLIPS_FORCE_VISIBLE(Any p0) { return invoke<Any>(0x08D84437, p0); } // 0x08D84437
	static Any NET_GAMER_BLIPS_SHOW_POSSE_MEMBERS(Any p0) { return invoke<Any>(0x784F04DD, p0); } // 0x784F04DD
	static int NET_GAMER_SET_BLIP_FORCE_HIDDEN(Any p0, Any p1) { return invoke<int>(0x3DD6E36A, p0, p1); } // 0x3DD6E36A
	static int NET_GAMER_BLIPS_SHOW_ON_FULL_MAP(Any p0) { return invoke<int>(0xE5FE0A6A, p0); } // 0xE5FE0A6A
	static int NET_GAMER_IS_BLIP_VISIBLE(Any p0) { return invoke<int>(0x25F8C46A, p0); } // 0x25F8C46A
	static Any NET_GAMER_BLIPS_TREAT_COVER_AS_ALIVE(Any p0) { return invoke<Any>(0x3248D20E, p0); } // 0x3248D20E
	static int NET_POSSE_GET_LEADER_WAYPOINT(Any p0) { return invoke<int>(0x9DDB29B1, p0); } // 0x9DDB29B1
	static int NET_POSSE_IS_LEADER_WAYPOINT_VALID() { return invoke<int>(0x24A1B923); } // 0x24A1B923
}

namespace PLAYSTATS
{
	static void PLAYSTAT_INT(const char* statName, int stat) { invoke<void>(0x2547029C, statName, stat); } // 0x2547029C
	static void PLAYSTAT_INT3(int stat, const char* axisNameX, int scaledValueX, const char* axisNameY, int scaledValueY, const char* axisNameZ, int scaledValueZ) { invoke<void>(0x6F6D942B, stat, axisNameX, scaledValueX, axisNameY, scaledValueY, axisNameZ, scaledValueZ); } // 0x6F6D942B
	static void PLAYSTAT_STRING(const char* statName, int stat) { invoke<void>(0x713B1D7F, statName, stat); } // 0x713B1D7F
	static void PLAYSTAT_DEED_NAMED(int deedId, int deedValue, const char* deedName, BOOL isCompleted, BOOL isSuccess) { invoke<void>(0x9C80A3A4, deedId, deedValue, deedName, isCompleted, isSuccess); } // 0x9C80A3A4
	static Any PLAYSTAT_MP_DEED_START(Any p0) { return invoke<Any>(0x27A00456, p0); } // 0x27A00456
	static Any PLAYSTAT_MP_DEED_COMPLETE(Any p0) { return invoke<Any>(0x120E6123, p0); } // 0x120E6123
	static Any PLAYSTAT_MP_DEED_COMPLETE_EX(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x4585821E, p0, p1, p2, p3); } // 0x4585821E
	static void PLAYSTAT_MP_COOP_COMPLETE(const char* missionName, int missionType, int numPlayers, int timeSpent, int totalScore, int rewardAmount, BOOL isMissionSuccessful) { invoke<void>(0x46C39437, missionName, missionType, numPlayers, timeSpent, totalScore, rewardAmount, isMissionSuccessful); } // 0x46C39437
}

namespace POPULATION
{
	static int BEGIN_POPULATION_DEFINITION() { return invoke<int>(0x1344515B); } // 0x1344515B
	static int END_POPULATION_DEFINITION() { return invoke<int>(0x364F41D6); } // 0x364F41D6
	static int LINK_ACTORENUM_TO_POPULATION(Any p0, Any p1, float p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x0C1B8DEA, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x0C1B8DEA
	static int LINK_ACTORENUM_TO_POPULATION_TIMED(Any p0, Any p1, float p2, Any p3) { return invoke<int>(0x93B6135B, p0, p1, p2, p3); } // 0x93B6135B
	static int UNLINK_ACTORENUM_FROM_POPULATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0x84F75008, p0, p1, p2, p3, p4, p5, p6); } // 0x84F75008
	static void SET_ACCESSORYSET_ON_SPAWN(Any p0, Any p1, Any p2) { invoke<void>(0xC79F2BD3, p0, p1, p2); } // 0xC79F2BD3
	static int SET_ZONE_POPULATION_ANIMAL_DOMESTICATION(Any p0, Any p1) { return invoke<int>(0x5996941F, p0, p1); } // 0x5996941F
	static void SET_ZONE_POPULATION_COUNT(Any p0, Any p1) { invoke<void>(0x1B271D85, p0, p1); } // 0x1B271D85
	static void SET_ZONE_POPULATION_COUNT_RANDOM(Any p0, Any p1, Any p2) { invoke<void>(0xE339719A, p0, p1, p2); } // 0xE339719A
	static void SET_ZONE_POPULATION_DENSITY(Any p0, Any p1) { invoke<void>(0x9381D459, p0, p1); } // 0x9381D459
	static void SET_ZONE_POPULATION_TYPE(Any p0, Any p1) { invoke<void>(0xFC30948B, p0, p1); } // 0xFC30948B
	static int SET_ZONE_POPULATION_SPAWN_MULTI_PER_POINT(Any p0, Any p1) { return invoke<int>(0x7D4FB8C8, p0, p1); } // 0x7D4FB8C8
	static int SET_ZONE_RESTRICT_ACTORS(Any p0, Any p1) { return invoke<int>(0xE0FDD026, p0, p1); } // 0xE0FDD026
	static int SET_ZONE_POPULATION_IS_FLOCK(Any p0, Any p1) { return invoke<int>(0x0B24CE10, p0, p1); } // 0x0B24CE10
	static int SET_ZONE_POPULATION_MAX_FLOCK_SIZE(Any p0, Any p1) { return invoke<int>(0x07FD0A76, p0, p1); } // 0x07FD0A76
	static int SET_ZONE_POPULATION_MIN_FLOCK_SIZE(Any p0, Any p1) { return invoke<int>(0xE4A789D8, p0, p1); } // 0xE4A789D8
	static int SET_ZONE_POPULATION_MAX_PER_CELL(Any p0, Any p1) { return invoke<int>(0x354DDFED, p0, p1); } // 0x354DDFED
	static int SET_FLOCK_DEFAULT_POPULATION_MAX_PER_CELL() { return invoke<int>(0x7ABDE1F0); } // 0x7ABDE1F0
	static int SET_INDIVIDUAL_DEFAULT_POPULATION_MAX_PER_CELL() { return invoke<int>(0x7D7F9770); } // 0x7D7F9770
	static void SET_ZONE_PRIORITY(Any p0, Any p1) { invoke<void>(0x4B8C0945, p0, p1); } // 0x4B8C0945
	static int SET_ZONE_FORCE_SPAWN_DISTANCE(Any p0, float p1) { return invoke<int>(0xE7F19909, p0, p1); } // 0xE7F19909
	static int SET_ZONE_RESERVE_GRINGOS(Any p0, Any p1) { return invoke<int>(0xC43C4D76, p0, p1); } // 0xC43C4D76
	static int SET_ZONE_SPAWN_ONLY_AT_GRINGOS(Any p0, Any p1) { return invoke<int>(0xD72DF5C6, p0, p1); } // 0xD72DF5C6
	static int CLEAR_ZONE_ALLOWED_GRINGO_TYPE_LIST(Any p0) { return invoke<int>(0x230AB95E, p0); } // 0x230AB95E
	static void ADD_TO_ZONE_ALLOWED_GRINGO_TYPE_LIST(Any p0, Any p1) { invoke<void>(0x64799CEE, p0, p1); } // 0x64799CEE
	static int SET_ZONE_RESPECT_VOLUME_RESTRICTIONS(Any p0, Any p1, Any p2) { return invoke<int>(0xFCA83D15, p0, p1, p2); } // 0xFCA83D15
	static int SET_DEFAULT_POPULATION_DENSITY(float p0) { return invoke<int>(0x04EFC113, p0); } // 0x04EFC113
	static int SET_DEFAULT_POPULATION_TYPE(Any p0) { return invoke<int>(0xD28A3706, p0); } // 0xD28A3706
	static int GET_RAND_ACTORENUM_FROM_POPULATION_NATIVE(Any p0, Any p1, Any p2, Any p3, Any p4, float p5, float p6, float p7) { return invoke<int>(0xD3503922, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xD3503922
	static void MAKE_NEXT_RAND_ACTORENUMS_UNIQUE(Any p0) { invoke<void>(0x1CE58D42, p0); } // 0x1CE58D42
	static Any IS_POPULATION_SET_READY(Any p0, Any p1, Any p2) { return invoke<Any>(0xFA5EA974, p0, p1, p2); } // 0xFA5EA974
	static BOOL IS_POPULATION_SET_REQUIRED_RESIDENT(Any p0) { return invoke<BOOL>(0x76E416FD, p0); } // 0x76E416FD
	static Any FIND_NAMED_POPULATION_SET(Any p0) { return invoke<Any>(0x4646C335, p0); } // 0x4646C335
	static int GET_NUM_ACTORENUMS_IN_POPULATION(Any p0) { return invoke<int>(0x8FD12F97, p0); } // 0x8FD12F97
	static Any GET_ACTORENUM_IN_POPULATION(Any p0, Any p1) { return invoke<Any>(0xABEC5676, p0, p1); } // 0xABEC5676
	static Any GET_ACTORENUM_IN_POPULATION_WEIGHT(Any p0, Any p1) { return invoke<Any>(0xEDD44891, p0, p1); } // 0xEDD44891
	static int MARKETING_GET_AMBIENT_DENSITY_LEVEL() { return invoke<int>(0x72F6EED0); } // 0x72F6EED0
	static int SET_ZONE_ALLOWED_SPAWN_READY_TOO_CLOSE(Any p0, Any p1) { return invoke<int>(0x84FB15FA, p0, p1); } // 0x84FB15FA
	static void AMBIENT_SPAWN_PRESTREAM_SET(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x687545BF, p0, p1, p2, p3, p4, p5); } // 0x687545BF
	static int AMBIENT_SPAWN_PRESTREAM_CLEAR() { return invoke<int>(0x2B75F13E); } // 0x2B75F13E
}

namespace PPPELEMENTS
{
	static void WANTEDFX_SET_OPACITY(float p0) { invoke<void>(0x598815BD, p0); } // 0x598815BD
	static const char* FIRE_BLOODSPLATFX(float p0, float p1, float p2, float p3) { return invoke<const char*>(0xD1C91A7F, p0, p1, p2, p3); } // 0xD1C91A7F
	static int CLEAR_DEATHFX() { return invoke<int>(0x7E0CDD87); } // 0x7E0CDD87
	static int BINOCULARSFX_ENABLED(Any p0) { return invoke<int>(0xE6C1DBD9, p0); } // 0xE6C1DBD9
	static int BINOCULARSFX_ISLOADED() { return invoke<int>(0x00EF33EF); } // 0x00EF33EF
	static Any ZOMBIEMODE_ENABLED(Any result) { return invoke<Any>(0xDF505043, result); } // 0xDF505043
	static void TEXTUREFX_SET_OPACITY(float p0) { invoke<void>(0xE613AE52, p0); } // 0xE613AE52
	static void TEXTUREFX_SET_POSITION(float p0, float p1) { invoke<void>(0x84F3DD81, p0, p1); } // 0x84F3DD81
	static Any TEXTUREFX_ENABLED(Any result) { return invoke<Any>(0xF55B50ED, result); } // 0xF55B50ED
	static int TEXTUREFX_SET_NAME(Any p0) { return invoke<int>(0x6336182D, p0); } // 0x6336182D
	static void TEXTUREFX_SET_SCALE(float p0) { invoke<void>(0x3A6960B2, p0); } // 0x3A6960B2
}

namespace PROBE
{
	static void ROTATE_OBJECT_UPRIGHT_TO_GROUND(Object object, int rotationSpeed, float groundAngle) { invoke<void>(0x7080E24A, object, rotationSpeed, groundAngle); } // 0x7080E24A
	// Name could be false positive, function is empty
	static void VISIBLE_RECTS_BOOLEAN(Any p0) { invoke<void>(0x1D7845B7, p0); } // 0x1D7845B7
}

namespace PROP
{
	static int GET_PHYSINST_FROM_OBJECT(Object object) { return invoke<int>(0xDB70DF0C, object); } // 0xDB70DF0C
	static int GET_NEW_PHYSINST_IN_SPHERE(Any p0) { return invoke<int>(0x6517FF1B, p0); } // 0x6517FF1B
	static BOOL IS_PROP_FIXED(Object object) { return invoke<BOOL>(0xBD2FFD8C, object); } // 0xBD2FFD8C
	static void SET_PROP_FIXED(Object object, BOOL toggle) { invoke<void>(0x7DBB277A, object, toggle); } // 0x7DBB277A
	static int REMOVE_PHYSINST(Any p0) { return invoke<int>(0x2E5A224C, p0); } // 0x2E5A224C
	static int GET_CENTER_OF_GRAVITY(Any p0, Any p1) { return invoke<int>(0x31940E4C, p0, p1); } // 0x31940E4C
	static int HAS_PROP_BEEN_DAMAGED(Any p0) { return invoke<int>(0x7151E7F0, p0); } // 0x7151E7F0
	static float GET_PROP_HEALTH(Any p0) { return invoke<float>(0xFDC6E853, p0); } // 0xFDC6E853
	static void SET_PROP_HEALTH(Any p0, Any p1) { invoke<void>(0xC6D12FF5, p0, p1); } // 0xC6D12FF5
	static void RESET_PROPS_IN_WORLD() { invoke<void>(0xB3E331AC); } // 0xB3E331AC
	static void RESET_PROPS_IN_VOLUME(Any p0, Any p1) { invoke<void>(0xCF1B9B11, p0, p1); } // 0xCF1B9B11
	static void RESET_PROP(Any p0) { invoke<void>(0x5E7A7E9B, p0); } // 0x5E7A7E9B
	static void SET_PROP_TARGETABLE(Any p0, Any p1, Any p2) { invoke<void>(0x32C810BF, p0, p1, p2); } // 0x32C810BF
	static void SET_PROP_TARGETABLE_ACQUISITION_RADIUS(Any p0, Any p1) { invoke<void>(0xE84EB2D5, p0, p1); } // 0xE84EB2D5
	static void SET_PROP_TARGETABLE_TARGET_BOX_SIZE(Any p0, Any p1, Any p2) { invoke<void>(0x6A937CBB, p0, p1, p2); } // 0x6A937CBB
	static void SET_PROP_TARGETABLE_SCORE_BIAS(Any p0, Any p1) { invoke<void>(0x0E2B0212, p0, p1); } // 0x0E2B0212
	static void SET_PROP_TARGETABLE_AS_ENEMY(Any p0, Any p1) { invoke<void>(0x5895EBBE, p0, p1); } // 0x5895EBBE
	static int SET_PROP_CAUSE_ARM_UP(Any p0, Any p1) { return invoke<int>(0xCC004171, p0, p1); } // 0xCC004171
	static BOOL IS_PROP_STREAMED_IN(Any p0) { return invoke<BOOL>(0x5131AEF1, p0); } // 0x5131AEF1
	static BOOL GRAVE_IS_DUG_UP(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<BOOL>(0x935F80FF, p0, p1, p2, p3, p4, p5); } // 0x935F80FF
	static void GRAVE_SET_DUG_UP(Any p0, Any p1) { invoke<void>(0x674156BB, p0, p1); } // 0x674156BB
	static int GET_GRAVE_FROM_OBJECT(Any p0) { return invoke<int>(0xA90E602F, p0); } // 0xA90E602F
	static int PLAY_SIMPLE_PROP_ANIMATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xDC3FBAE6, p0, p1, p2, p3, p4, p5); } // 0xDC3FBAE6
	static void SET_DRAW_OBJECT(Object object, BOOL drawObject) { invoke<void>(0xC5A886DC, object, drawObject); } // 0xC5A886DC
	static BOOL GET_DRAW_OBJECT(Object object) { return invoke<BOOL>(0xCED86AF7, object); } // 0xCED86AF7
	static BOOL PROP_IS_VARIABLE_MESH_ENABLED(Object object, int variableMesh) { return invoke<BOOL>(0x375A33F0, object, variableMesh); } // 0x375A33F0
	static int PROP_ENABLE_VARIABLE_MESH(Object object, int variableMesh, BOOL toggle) { return invoke<int>(0x8287F8B3, object, variableMesh, toggle); } // 0x8287F8B3
	static int SET_PROP_REMAP(Any p0, Any p1) { return invoke<int>(0x4BCFADB1, p0, p1); } // 0x4BCFADB1
	static int CLEAR_PROP_REMAP(Any p0) { return invoke<int>(0x6D555332, p0); } // 0x6D555332
}

namespace RENDER
{
	static void RENDERING_ENABLE_CHARACTER_CLIPPING(BOOL enableClipping) { invoke<void>(0x6AF07F86, enableClipping); } // 0x6AF07F86
	static void PRINT_FRAME_TIME(int frameIndex) { invoke<void>(0xB84DE79E, frameIndex); } // 0xB84DE79E
	// PS4/Switch/PC only
	static void SET_MAXIMUM_SPOTLIGHT_CASCADE_COUNT(int maxCascadeCount) { invoke<void>(0x09D4CDEF, maxCascadeCount); } // 0x09D4CDEF
}

namespace RIDING
{
	static void SET_MOST_RECENT_MOUNT(Actor actor, Mount mount) { invoke<void>(0x00AF2CB0, actor, mount); } // 0x00AF2CB0
	static Mount GET_MOST_RECENT_MOUNT(Actor actor) { return invoke<Mount>(0x708E450F, actor); } // 0x708E450F
	static Actor GET_MOST_RECENT_RIDER(Actor actor) { return invoke<Actor>(0x668E55C3, actor); } // 0x668E55C3
	static BOOL IS_ACTOR_HORSE(Actor actor) { return invoke<BOOL>(0xDB0D0478, actor); } // 0xDB0D0478
	static BOOL IS_ACTOR_MULE(Actor actor) { return invoke<BOOL>(0x1F739295, actor); } // 0x1F739295
	static BOOL IS_ACTOR_RIDING(Actor actor) { return invoke<BOOL>(0xA6BBE769, actor); } // 0xA6BBE769
	static BOOL IS_ACTOR_RIDING_AND_IN_SADDLE(Actor actor) { return invoke<BOOL>(0xF270EAC1, actor); } // 0xF270EAC1
	static BOOL IS_ACTOR_MOUNTED(Actor actor) { return invoke<BOOL>(0xA3AB3708, actor); } // 0xA3AB3708
	static Actor GET_RIDER(Mount mount) { return invoke<Actor>(0x88A283E5, mount); } // 0x88A283E5
	static Mount GET_MOUNT(Actor actor) { return invoke<Mount>(0xDD31EC4E, actor); } // 0xDD31EC4E
	static void SET_MOUNTS_AS_PASSENGER(Any p0, Any p1) { invoke<void>(0xDC6DEE92, p0, p1); } // 0xDC6DEE92
	static void ACTOR_MOUNT_ACTOR(Actor actor, Actor mountActor) { invoke<void>(0xC28242F4, actor, mountActor); } // 0xC28242F4
	static void REMOVE_HORSE_ACCESSORY(Mount mount, int accessory) { invoke<void>(0x374D047A, mount, accessory); } // 0x374D047A
	static BOOL DOES_HORSE_HAVE_ACCESSORY(Mount mount, int accessory) { return invoke<BOOL>(0x75D4E33F, mount, accessory); } // 0x75D4E33F
	static int ACCESSORIZE_HORSE(Mount mount, int accessory) { return invoke<int>(0x6C939AA7, mount, accessory); } // 0x6C939AA7
	static Any HORSE_ENABLE_AUTO_JUMP_FOR_AI_RIDERS(Any p0, Any p1) { return invoke<Any>(0x6B6E05A8, p0, p1); } // 0x6B6E05A8
	static Any HORSE_AUTO_JUMP_ENABLED_FOR_AI_RIDERS(Any p0, Any p1) { return invoke<Any>(0xCA7CB126, p0, p1); } // 0xCA7CB126
	static Any HORSE_ADD_REPULSION_EXCLUSION_VOLUME(Any p0) { return invoke<Any>(0x28FCBDF2, p0); } // 0x28FCBDF2
	static Any HORSE_REMOVE_REPULSION_EXCLUSION_VOLUME(Any p0) { return invoke<Any>(0x5DE07F18, p0); } // 0x5DE07F18
	// Stamina between 0.0f - 1.0f
	static int HORSE_SET_CURR_FRESHNESS(Mount mount, float stamina) { return invoke<int>(0xF3976D70, mount, stamina); } // 0xF3976D70
	static float HORSE_GET_CURR_FRESHNESS(Mount mount) { return invoke<float>(0xB8665D8A, mount); } // 0xB8665D8A
	static int HORSE_LOCK_FRESHNESS(Mount mount) { return invoke<int>(0x8754817D, mount); } // 0x8754817D
	static int HORSE_UNLOCK_FRESHNESS(Mount mount) { return invoke<int>(0x6AFA044B, mount); } // 0x6AFA044B
	static void HORSE_SET_INFINITE_FRESHNESS_CHEAT(BOOL toggle) { invoke<void>(0xB731EB45, toggle); } // 0xB731EB45
}

namespace SHOP
{
	static void SHOP_CLEAR() { invoke<void>(0xCEBD595A); } // 0xCEBD595A
	static void SHOP_REFRESH(BOOL toggle) { invoke<void>(0xE7F6AA5D, toggle); } // 0xE7F6AA5D
	static void SHOP_SET_PLAYER_BANK(int bankBalance) { invoke<void>(0xB75FAD6A, bankBalance); } // 0xB75FAD6A
	static int SHOP_ADD_ITEM(int itemId, BOOL isItemAvailable, int price, int quantity, int categoryId, BOOL isDiscounted, BOOL isFreeItem) { return invoke<int>(0x2FCD8CCA, itemId, isItemAvailable, price, quantity, categoryId, isDiscounted, isFreeItem); } // 0x2FCD8CCA
	static void SHOP_SET_ITEM_QUANTITY(int itemId, int quantity, Any p2) { invoke<void>(0x777CF9FA, itemId, quantity, p2); } // 0x777CF9FA
	static int SHOP_GET_ITEM_QUANTITY(BOOL isDetailedCheck) { return invoke<int>(0xFAF37414, isDetailedCheck); } // 0xFAF37414
	static int SHOP_SET_ITEM_PURCHASE_PRICE(BOOL isDiscounted, int purchasePrice) { return invoke<int>(0xA40EFFFF, isDiscounted, purchasePrice); } // 0xA40EFFFF
	static int SHOP_GET_ITEM_PURCHASE_PRICE(Any p0) { return invoke<int>(0x94D8F49E, p0); } // 0x94D8F49E
	static int SHOP_GET_ITEM_SELL_PRICE(BOOL IsSale) { return invoke<int>(0x42CBA241, IsSale); } // 0x42CBA241
	static void SHOP_SET_ITEM_BLOCKED(int itemId, BOOL isBlocked) { invoke<void>(0x7A34C33D, itemId, isBlocked); } // 0x7A34C33D
	static BOOL SHOP_IS_ITEM_BLOCKED(int itemId) { return invoke<BOOL>(0xB954DE78, itemId); } // 0xB954DE78
	static int SHOP_GET_ITEM_MISC_FLAG(int itemId) { return invoke<int>(0x1BF8FD6D, itemId); } // 0x1BF8FD6D
	static BOOL SHOP_IS_SELL_SELECTED() { return invoke<BOOL>(0x5A12BB48); } // 0x5A12BB48
	static void SHOP_SET_CURRENT_TAB(BOOL isTabSelected) { invoke<void>(0x3601E3E2, isTabSelected); } // 0x3601E3E2
	static void SHOP_LOCK_INPUT(BOOL isInputLocked) { invoke<void>(0xB84DE662, isInputLocked); } // 0xB84DE662
	static void SATCHEL_SET_ENABLED(BOOL toggle) { invoke<void>(0x2692B771, toggle); } // 0x2692B771
	static void SATCHEL_TOGGLE_NO_PAUSE_OUTFIT(BOOL toggle) { invoke<void>(0xEB046CD9, toggle); } // 0xEB046CD9
	static void SATCHEL_CREATE_OUTFIT(const char* outfitName, const char* outfitCategory, int quantity) { invoke<void>(0x427F4D58, outfitName, outfitCategory, quantity); } // 0x427F4D58
	static int SATCHEL_SET_OUTFIT_STATE(int outfitId, int state) { return invoke<int>(0x0A87A573, outfitId, state); } // 0x0A87A573
	static int SATCHEL_GET_OUTFIT_STATE(int outfitId) { return invoke<int>(0x25EF49AD, outfitId); } // 0x25EF49AD
	static void SATCHEL_SET_OUTFIT_TEXTURE(int p0, const char* textureName) { invoke<void>(0x23EB81F0, p0, textureName); } // 0x23EB81F0
	static void SATCHEL_ALLOW_OUTFIT_CHANGE(BOOL isOutfitChangeAllowed) { invoke<void>(0x58018D83, isOutfitChangeAllowed); } // 0x58018D83
	static void SATCHEL_SET_CURRENT_OUTFIT(int outfitId) { invoke<void>(0x1C462085, outfitId); } // 0x1C462085
}

namespace SOCIALCLUB
{
	static void UI_CHALLENGE_CREATE(int challengeId, const char* challengeName, const char* description) { invoke<void>(0x1EB9AF29, challengeId, challengeName, description); } // 0x1EB9AF29
	static void UI_CHALLENGE_SET_DESCRIPTION(Any p0, Any p1) { invoke<void>(0x2A39FD8A, p0, p1); } // 0x2A39FD8A
	static void UI_CHALLENGE_SET_TITLE_TEXTURE(int challengeId, const char* textureName) { invoke<void>(0xD5ED5FCB, challengeId, textureName); } // 0xD5ED5FCB
	static void UI_CHALLENGE_SET_PROGRESS(int challengeId, float currentProgress, float maxProgress, float threshold, const char* progressText) { invoke<void>(0x10F5386D, challengeId, currentProgress, maxProgress, threshold, progressText); } // 0x10F5386D
	static void UI_CHALLENGE_SET_PROGRESS_DETAIL(int challengeId, const char* detailText) { invoke<void>(0x9D9CDCE3, challengeId, detailText); } // 0x9D9CDCE3
	// trophyType:
	// enum eTrophyType
	// {
	// 	TROPHY_NONE = 0,
	// 	TROPHY_BRONZE = 4,
	// 	TROPHY_GOLD = 8,
	// 	// todo
	// };
	static void UI_CHALLENGE_SET_TROPHY_TYPE(int challengeId, int trophyType) { invoke<void>(0x3731AC9F, challengeId, trophyType); } // 0x3731AC9F
	static void UI_CHALLENGE_SET_OBJECTIVE(int challengeId, int objectiveId, const char* objectiveDescription) { invoke<void>(0x9CF5C747, challengeId, objectiveId, objectiveDescription); } // 0x9CF5C747
	static void UI_CHALLENGE_SET_OBJECTIVE_STYLE(int challengeId, int objectiveId, int style) { invoke<void>(0x4A598723, challengeId, objectiveId, style); } // 0x4A598723
	static void UI_CHALLENGE_SET_OBJECTIVE_STYLE_B(int challengeId, int objectiveId, int style) { invoke<void>(0x9272926C, challengeId, objectiveId, style); } // 0x9272926C
	static void UI_CHALLENGE_SET_COLUMN_HEADER(int challengeId, int columnIndex, const char* headerText) { invoke<void>(0xAFC9071D, challengeId, columnIndex, headerText); } // 0xAFC9071D
	static void UI_CHALLENGE_SET_TIME_HEADER(int challengeId, const char* timeHeaderText) { invoke<void>(0x761A6750, challengeId, timeHeaderText); } // 0x761A6750
	static void UI_CHALLENGE_SET_TIME_INFO(int challengeId, BOOL isTimeElapsed, const char* timeInfoText) { invoke<void>(0xC201524D, challengeId, isTimeElapsed, timeInfoText); } // 0xC201524D
	static void UI_CHALLENGE_MAKE_CURRENT(int challengeId) { invoke<void>(0x04A3022E, challengeId); } // 0x04A3022E
}

namespace SPEECH
{
	static BOOL CAN_ACTOR_ENUM_PLAY_SPEECH_CONTEXT(int actor, int speechContextId) { return invoke<BOOL>(0xD02757C1, actor, speechContextId); } // 0xD02757C1
	static void REGISTER_ACTOR_SPEECH_CONTEXT(int speechId, const char* speechText, BOOL isEnabled, int contextType, BOOL isUrgent, int languageId, int voiceId) { invoke<void>(0x886E06C2, speechId, speechText, isEnabled, contextType, isUrgent, languageId, voiceId); } // 0x886E06C2
	static void FINISH_REGISTERING_ACTOR_SPEECH_CONTEXTS() { invoke<void>(0xB6839756); } // 0xB6839756
	static void REGISTER_NUM_SPEECH_CONTEXTS(int numContexts) { invoke<void>(0xCB139D15, numContexts); } // 0xCB139D15
	static void REGISTER_NUM_CONTEXT_TYPES(int numContextTypes) { invoke<void>(0xF07F5E41, numContextTypes); } // 0xF07F5E41
}

namespace SQUADS
{
	static int SQUAD_GET(Any p0) { return invoke<int>(0xB3732081, p0); } // 0xB3732081
	static Any SQUAD_IS_VALID(Any p0) { return invoke<Any>(0xBDB3061E, p0); } // 0xBDB3061E
	static void SQUAD_JOIN(Any p0, Any p1) { invoke<void>(0xB14302C8, p0, p1); } // 0xB14302C8
	static void SQUAD_LEAVE(Any p0) { invoke<void>(0x077591FF, p0); } // 0x077591FF
	static void SQUAD_MAKE_EMPTY(Any p0) { invoke<void>(0x90D92CF1, p0); } // 0x90D92CF1
	static void SQUADS_MERGE(Any p0, Any p1) { invoke<void>(0x320E2604, p0, p1); } // 0x320E2604
	static Any SQUAD_GET_ACTOR_BY_INDEX(Any p0, Any p1) { return invoke<Any>(0x5126039A, p0, p1); } // 0x5126039A
	static Any SQUAD_GET_SIZE(Any p0) { return invoke<Any>(0xEEC83187, p0); } // 0xEEC83187
	static int SQUAD_COMPUTE_CENTROID(Any p0, Any p1) { return invoke<int>(0x142D9F3A, p0, p1); } // 0x142D9F3A
	static void SQUAD_SET_FACTION(Any p0, Any p1) { invoke<void>(0xAEA4E9AE, p0, p1); } // 0xAEA4E9AE
	static int SQUAD_GOAL_ADD_BATTLE_ALLIES(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x65888454, p0, p1, p2, p3); } // 0x65888454
	static int SQUAD_GOAL_ADD_BATTLE_DEFEND_VOLUME(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xD52A28F0, p0, p1, p2, p3); } // 0xD52A28F0
	static int SQUAD_GOAL_ADD_COMBAT(int* p0, Any p1, Any p2, Any p3) { return invoke<int>(0x4DD06256, p0, p1, p2, p3); } // 0x4DD06256
	static int SQUAD_GOAL_ADD_FACTION_STATUS_WITHIN_GOAL(int* p0, Any p1, Any p2) { return invoke<int>(0xA4BC2A1B, p0, p1, p2); } // 0xA4BC2A1B
	static int SQUAD_GOAL_ADD_FLOCK(Any p0, Any p1, Any p2) { return invoke<int>(0x9D3B103C, p0, p1, p2); } // 0x9D3B103C
	static int SQUAD_GOAL_ADD_FOLLOW_OBJECT_IN_FORMATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x1AC03C80, p0, p1, p2, p3, p4, p5); } // 0x1AC03C80
	static int SQUAD_GOAL_ADD_FOLLOW_PATH_IN_FORMATION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x750C1A2B, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x750C1A2B
	static int SQUAD_GOAL_ADD_FOLLOW_TRAFFIC_CURVE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0xE77B9FC0, p0, p1, p2, p3, p4, p5, p6); } // 0xE77B9FC0
	static int SQUAD_GOAL_ADD_GENERAL_TASK(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x83D78A49, p0, p1, p2, p3); } // 0x83D78A49
	static int SQUAD_GOAL_ADD_GUARD_POSITION(int* p0, Any p1, Any p2, float p3) { return invoke<int>(0x8BA55E8D, p0, p1, p2, p3); } // 0x8BA55E8D
	static int SQUAD_GOAL_ADD_HUNT_ENEMIES(int* p0, Any p1, float p2, float p3, float p4) { return invoke<int>(0x96DB0BA1, p0, p1, p2, p3, p4); } // 0x96DB0BA1
	static int SQUAD_GOAL_ADD_MEET_AT_POSITION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xA2AE53BD, p0, p1, p2, p3, p4, p5); } // 0xA2AE53BD
	static int SQUAD_GOAL_ADD_RESTRICT_INVESTIGATION_DISTANCE_FROM_SQUAD(int* p0, Any p1, float p2) { return invoke<int>(0x35051831, p0, p1, p2); } // 0x35051831
	static int SQUAD_GOAL_ADD_SHARE_PERCEPTION(int* p0, Any p1) { return invoke<int>(0x435A982F, p0, p1); } // 0x435A982F
	static int SQUAD_GOAL_ADD_STAY_OUTSIDE_OF_VOLUME(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x5F4DEC49, p0, p1, p2, p3, p4); } // 0x5F4DEC49
	static int SQUAD_GOAL_ADD_STAY_WITHIN_VOLUME(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xE775EF0D, p0, p1, p2, p3, p4); } // 0xE775EF0D
	static int SQUAD_GOAL_ADD_ANIMAL_HERD(int* p0, Any p1, Any p2, Any p3) { return invoke<int>(0x48588CCB, p0, p1, p2, p3); } // 0x48588CCB
	static int SQUAD_GOAL_GET_STATUS(int* p0, Any p1) { return invoke<int>(0xC6AF3662, p0, p1); } // 0xC6AF3662
	static BOOL SQUAD_GOAL_IS_VALID(Any p0) { return invoke<BOOL>(0xFAD7A113, p0); } // 0xFAD7A113
	static int SQUAD_GOAL_REMOVE(Any p0, Any p1) { return invoke<int>(0xBB3A34B0, p0, p1); } // 0xBB3A34B0
	static Any SQUAD_GOALS_CLEAR(Any p0) { return invoke<Any>(0xCA950EF0, p0); } // 0xCA950EF0
	static int SQUAD_IS_GOAL_CONTROLLING_ACTOR(Any p0, Any p1, Any p2) { return invoke<int>(0x817AC6D6, p0, p1, p2); } // 0x817AC6D6
	static int SQUAD_GET_SINGLE_ACTOR_CONTROLLED_BY_GOAL(Any* p0, Any p1, Any p2) { return invoke<int>(0xF37E8A9E, p0, p1, p2); } // 0xF37E8A9E
	static int SQUAD_GOAL_LINK_MODIFIER_TO_OTHER_GOAL(Any p0, Any p1, Any p2) { return invoke<int>(0x1B74CCA1, p0, p1, p2); } // 0x1B74CCA1
	static void SQUAD_FLOCK_SET_EXTERNAL_MOVEMENT_TUNING(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x224CFE5B, p0, p1, p2, p3, p4); } // 0x224CFE5B
	static int SQUAD_FLOCK_SET_FLOCKING_PARAMETER(Any p0, Any p1, Any p2, Any p3, Any p4, float p5) { return invoke<int>(0x3F9736B8, p0, p1, p2, p3, p4, p5); } // 0x3F9736B8
	static int SQUAD_FLOCK_SET_BOOL_FLOCKING_PARAMETER(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0x5E24EAA0, p0, p1, p2, p3, p4, p5); } // 0x5E24EAA0
	static void SQUAD_FLOCK_ADD_EXTERNAL_ALERT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x1F0E5B88, p0, p1, p2, p3, p4, p5); } // 0x1F0E5B88
	static void SQUAD_FLOCK_ADD_EXTERNAL_ATTRACTION_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x895AA97B, p0, p1, p2, p3, p4, p5, p6); } // 0x895AA97B
	static void SQUAD_FLOCK_ADD_EXTERNAL_REPULSION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { invoke<void>(0x53609885, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x53609885
	static void SQUAD_FLOCK_ADD_EXTERNAL_VELOCITY_MATCH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0xE8B7AA08, p0, p1, p2, p3, p4, p5); } // 0xE8B7AA08
	static void SQUAD_FLOCK_PLAYER_PROXIMITY_BOOST_SET_ENABLED(Any p0, Any p1, Any p2) { invoke<void>(0xE4E94286, p0, p1, p2); } // 0xE4E94286
	static void SQUAD_FLOCK_PLAYER_WHISTLE_BOOST_SET_ENABLED(Any p0, Any p1, Any p2) { invoke<void>(0x6770774F, p0, p1, p2); } // 0x6770774F
	static int SQUAD_FLOCK_EVENT_BOOST_SET_ENABLED(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x5A43D915, p0, p1, p2, p3); } // 0x5A43D915
	static int SQUAD_ANIMAL_HERD_SET_FLOCKING_PARAMETER(Any p0, Any p1, Any p2, Any p3, float p4) { return invoke<int>(0x175BE678, p0, p1, p2, p3, p4); } // 0x175BE678
	static int SQUAD_ANIMAL_HERD_CLEAR_EXTERNAL_INFLUENCES(Any p0, Any p1) { return invoke<int>(0x5AEA32D1, p0, p1); } // 0x5AEA32D1
	static int SQUAD_ANIMAL_HERD_CLEAR_EXTERNAL_INFLUENCES_FROM_OBJECT(Any p0, Any p1, Any p2) { return invoke<int>(0x484643F6, p0, p1, p2); } // 0x484643F6
	static int SQUAD_ANIMAL_HERD_ADD_EXTERNAL_ALERT(Any p0, Any p1, Any p2, float p3, float p4) { return invoke<int>(0x1CEB8BFF, p0, p1, p2, p3, p4); } // 0x1CEB8BFF
	static int SQUAD_ANIMAL_HERD_ADD_EXTERNAL_REPULSION(Any p0, Any p1, Any p2, float p3, float p4, float p5, float p6, float p7) { return invoke<int>(0xB4D9B233, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xB4D9B233
	static int SQUAD_FLOCK_SET_ALLOW_STRAGGLERS(Any p0, Any p1, Any p2) { return invoke<int>(0xFC24BB6A, p0, p1, p2); } // 0xFC24BB6A
	static int SQUAD_HUNT_ENEMIES_SET_DEFAULT_BLIP_ALERTED(Any p0) { return invoke<int>(0xE7A0A109, p0); } // 0xE7A0A109
	static int SQUAD_HUNT_ENEMIES_SET_DEFAULT_BLIP_INVESTIGATING(Any p0) { return invoke<int>(0x0073024E, p0); } // 0x0073024E
	static int SQUAD_HUNT_ENEMIES_SET_DEFAULT_BLIP_UNALERTED(Any p0, float p1) { return invoke<int>(0x82C54B8A, p0, p1); } // 0x82C54B8A
	static int SQUAD_GET_NUM_ELIMINATED_ACTORS(Any p0) { return invoke<int>(0x57C67E91, p0); } // 0x57C67E91
	static int SQUAD_GET_NUM_NOT_ELIMINATED_ACTORS(Any p0) { return invoke<int>(0x55DAC120, p0); } // 0x55DAC120
	static void SQUAD_SET_NOT_ELIMINATED_IMPAIRMENT_MASK(Any p0, Any p1) { invoke<void>(0xE7D45FB3, p0, p1); } // 0xE7D45FB3
	static int SQUAD_GET_NOT_ELIMINATED_IMPAIRMENT_MASK(Any p0) { return invoke<int>(0xAEDD7512, p0); } // 0xAEDD7512
	static int SQUAD_BATTLE_ALLIES_SET_OBJECTIVE(Any p0, Any p1, Any p2) { return invoke<int>(0x907D4081, p0, p1, p2); } // 0x907D4081
	static void SQUAD_BATTLE_ALLIES_SET_FORMATION_DENSITY(Any p0, Any p1, Any p2) { invoke<void>(0x6BC42101, p0, p1, p2); } // 0x6BC42101
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_GET_ALL_BEHAVIOR_FLAGS(Any p0, Any p1) { return invoke<int>(0xE21D4785, p0, p1); } // 0xE21D4785
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_ALL_BEHAVIOR_FLAGS(Any p0, Any p1, Any p2) { return invoke<int>(0xF3C07A17, p0, p1, p2); } // 0xF3C07A17
	static BOOL SQUAD_FOLLOW_TRAFFIC_CURVE_GET_BEHAVIOR_FLAG(Any p0, Any p1, Any p2) { return invoke<BOOL>(0x20009EB2, p0, p1, p2); } // 0x20009EB2
	static void SQUAD_FOLLOW_TRAFFIC_CURVE_SET_BEHAVIOR_FLAG(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x7FEE2B3C, p0, p1, p2, p3); } // 0x7FEE2B3C
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_CURVE(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x0031613E, p0, p1, p2, p3); } // 0x0031613E
	static void SQUAD_FOLLOW_TRAFFIC_CURVE_ENQUEUE_CURVE(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x041C0802, p0, p1, p2, p3); } // 0x041C0802
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_SPEED(Any p0, Any p1) { return invoke<int>(0x347616C9, p0, p1); } // 0x347616C9
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_SPEED_ABSOLUTE(Any p0, Any p1, float p2) { return invoke<int>(0xB00F188D, p0, p1, p2); } // 0xB00F188D
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_SPEED_NORMALIZED(Any p0, Any p1, float p2) { return invoke<int>(0x70E0654A, p0, p1, p2); } // 0x70E0654A
	static void SQUAD_FOLLOW_TRAFFIC_CURVE_SET_TASK_PRIORITY(Any p0, Any p1, Any p2) { invoke<void>(0x8C8EEEF2, p0, p1, p2); } // 0x8C8EEEF2
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_OFFSET_X(Any p0, Any p1, float p2) { return invoke<int>(0x0F163466, p0, p1, p2); } // 0x0F163466
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_ALLOW_PLAYER_JOIN(Any p0) { return invoke<int>(0x430993FC, p0); } // 0x430993FC
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_DESIRED_LEADER(int* p0, Any p1, Any p2) { return invoke<int>(0x27F7C1E4, p0, p1, p2); } // 0x27F7C1E4
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_CLEAR_DESIRED_LEADER(Any p0, Any p1) { return invoke<int>(0x5BADEFDC, p0, p1); } // 0x5BADEFDC
	static int SQUAD_FOLLOW_TRAFFIC_CURVE_IS_CURVE_ALREADY_IN_LIST(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x8DC095B0, p0, p1, p2, p3, p4); } // 0x8DC095B0
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_GET_ALL_BEHAVIOR_FLAGS(Any p0, Any p1) { return invoke<int>(0xE69AE6C5, p0, p1); } // 0xE69AE6C5
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_ALL_BEHAVIOR_FLAGS(Any p0, Any p1, Any p2) { return invoke<int>(0xFA63B0F7, p0, p1, p2); } // 0xFA63B0F7
	static BOOL SQUAD_FOLLOW_PATH_IN_FORMATION_GET_BEHAVIOR_FLAG(Any p0, Any p1, Any p2) { return invoke<BOOL>(0xC4D79095, p0, p1, p2); } // 0xC4D79095
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_BEHAVIOR_FLAG(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x5C14EC4E, p0, p1, p2, p3); } // 0x5C14EC4E
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_PATH(Any p0, Any p1, Any p2) { return invoke<int>(0x6FB2CADA, p0, p1, p2); } // 0x6FB2CADA
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_SPEED(Any p0) { return invoke<int>(0x437E2995, p0); } // 0x437E2995
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_SPEED_ABSOLUTE(Any p0, float p1) { return invoke<int>(0x7B681402, p0, p1); } // 0x7B681402
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_SPEED_NORMALIZED(Any p0, float p1) { return invoke<int>(0xD618C1C7, p0, p1); } // 0xD618C1C7
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_TASK_PRIORITY(Any p0, Any p1, Any p2) { return invoke<int>(0xF661D354, p0, p1, p2); } // 0xF661D354
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_OFFSET_X(Any p0, Any p1, float p2) { return invoke<int>(0x554EFABE, p0, p1, p2); } // 0x554EFABE
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_ALLOW_PLAYER_JOIN(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x3966E20B, p0, p1, p2, p3); } // 0x3966E20B
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_NONSTOP(Any p0, Any p1, Any p2) { return invoke<int>(0x8BE72016, p0, p1, p2); } // 0x8BE72016
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_DESIRED_LEADER(Any p0, Any p1, Any p2) { return invoke<int>(0xA8A50DF5, p0, p1, p2); } // 0xA8A50DF5
	static int SQUAD_FOLLOW_PATH_IN_FORMATION_CLEAR_DESIRED_LEADER(Any p0, Any p1) { return invoke<int>(0x47F31A41, p0, p1); } // 0x47F31A41
}

namespace STAT
{
	static void CREATE_STAT(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x32A3A7AE, p0, p1, p2, p3); } // 0x32A3A7AE
	static void HIDE_STAT(Any p0, Any p1) { invoke<void>(0x1CF1FCC4, p0, p1); } // 0x1CF1FCC4
	static void UPDATE_STAT(Any p0, Any p1, Any p2) { invoke<void>(0xC9212F76, p0, p1, p2); } // 0xC9212F76
	static void ENABLE_JOURNAL_REPLAY(Any p0) { invoke<void>(0x957F1618, p0); } // 0x957F1618
	static int SET_JOURNAL_INFO_LABEL(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0x40C2576F, p0, p1, p2, p3, p4); } // 0x40C2576F
	static float GET_SAGPLAYER_STAT_FLOAT(Any p0) { return invoke<float>(0x5545C218, p0); } // 0x5545C218
	static int GET_SAGPLAYER_STAT_INT(Any p0) { return invoke<int>(0xE623B382, p0); } // 0xE623B382
	static void SET_SAGPLAYER_STAT_FLOAT(Any p0, Any p1) { invoke<void>(0x2104B1C0, p0, p1); } // 0x2104B1C0
	static int SET_SAGPLAYER_STAT_INT(int result, float p1) { return invoke<int>(0xF1A723D0, result, p1); } // 0xF1A723D0
	static int GET_NUM_KILLS_LAST_DEADEYE() { return invoke<int>(0xBBF4F7E4); } // 0xBBF4F7E4
}

namespace STREAM
{
	// actorEnum: https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eActorEnum
	static void STREAMING_REQUEST_ACTOR(int actorEnum, BOOL p1, BOOL p2) { invoke<void>(0xB0A79FEE, actorEnum, p1, p2); } // 0xB0A79FEE
	static BOOL STREAMING_IS_ACTOR_LOADED(int actorEnum, int p1) { return invoke<BOOL>(0x7DF72579, actorEnum, p1); } // 0x7DF72579
	static void STREAMING_EVICT_ACTOR(int actorEnum, int p1) { invoke<void>(0x6661CF89, actorEnum, p1); } // 0x6661CF89
	static BOOL STREAMING_IS_WORLD_LOADED() { return invoke<BOOL>(0x87B74064); } // 0x87B74064
	static BOOL STREAMING_IS_WORLD_LOADED_PRIORITY() { return invoke<BOOL>(0x943BE053); } // 0x943BE053
	static Any STREAMING_ARE_BOUNDS_LOADED(Any p0, Any p1, Any p2) { return invoke<Any>(0xC07681C1, p0, p1, p2); } // 0xC07681C1
	static void STREAMING_REQUEST_PROP(int assetId, int p1) { invoke<void>(0x38DC1F50, assetId, p1); } // 0x38DC1F50
	static BOOL STREAMING_IS_PROP_LOADED(int assetId) { return invoke<BOOL>(0xD7F80035, assetId); } // 0xD7F80035
	static void STREAMING_EVICT_PROP(int assetId) { invoke<void>(0xA8D12960, assetId); } // 0xA8D12960
	static void STREAMING_REQUEST_PROPSET(int assetId) { invoke<void>(0xEC1F14C8, assetId); } // 0xEC1F14C8
	static BOOL STREAMING_IS_PROPSET_LOADED(int assetId) { return invoke<BOOL>(0xF7D65903, assetId); } // 0xF7D65903
	static void STREAMING_EVICT_PROPSET(int assetId) { invoke<void>(0x4A5E4C13, assetId); } // 0x4A5E4C13
	static void STREAMING_REQUEST_GRINGO(int assetId) { invoke<void>(0x563E2E79, assetId); } // 0x563E2E79
	static BOOL STREAMING_IS_GRINGO_LOADED(int assetId) { return invoke<BOOL>(0xA6C9DCEA, assetId); } // 0xA6C9DCEA
	static void STREAMING_EVICT_GRINGO(int assetId) { invoke<void>(0xA02B6AAE, assetId); } // 0xA02B6AAE
	static void STREAMING_REQUEST_GRINGO_DICTIONARY(Any p0) { invoke<void>(0x620649B4, p0); } // 0x620649B4
	static int STREAMING_IS_GRINGO_DICTIONARY_LOADED(Any p0) { return invoke<int>(0x67994764, p0); } // 0x67994764
	static void STREAMING_EVICT_GRINGO_DICTIONARY(Any p0) { invoke<void>(0x32FCA813, p0); } // 0x32FCA813
	static void STREAMING_REQUEST_SCRIPT(int assetId) { invoke<void>(0x11E57A92, assetId); } // 0x11E57A92
	static BOOL STREAMING_IS_SCRIPT_LOADED(int assetId) { return invoke<BOOL>(0xB5B4AEAD, assetId); } // 0xB5B4AEAD
	static void STREAMING_EVICT_SCRIPT(int assetId) { invoke<void>(0x570163E2, assetId); } // 0x570163E2
	static void STREAMING_LOAD_ALL_REQUESTS_NOW(Any p0) { invoke<void>(0x7B5C28F3, p0); } // 0x7B5C28F3
	static void STREAMING_LOAD_SCENE_EXT(float p0, float p1, float p2, float p3, float p4, float p5) { invoke<void>(0xCB1E8485, p0, p1, p2, p3, p4, p5); } // 0xCB1E8485
	static void STREAMING_UNLOAD_SCENE() { invoke<void>(0x39E69B1B); } // 0x39E69B1B
	static void STREAMING_GET_POI_POS(Any p0, Any p1) { invoke<void>(0x055EF7A3, p0, p1); } // 0x055EF7A3
	static void STREAMING_OVERRIDE_MAIN_POI(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x338F85D9, p0, p1, p2, p3, p4, p5); } // 0x338F85D9
	static void STREAMING_RELEASE_MAIN_POI() { invoke<void>(0x7D5C0C4D); } // 0x7D5C0C4D
	static int STREAMING_HAS_OVERRIDE_MAIN_POI() { return invoke<int>(0x5B404EDA); } // 0x5B404EDA
	static void STREAMING_GET_OVERRIDE_MAIN_POI_POS(Any p0) { invoke<void>(0xDF3DF05A, p0); } // 0xDF3DF05A
	static int STREAMING_ENABLE_POI_STREAMING(Any p0) { return invoke<int>(0x49E4EB10, p0); } // 0x49E4EB10
	static int STREAMING_PREVENT_SNIPER_MODE(Any p0) { return invoke<int>(0x5F4C08A2, p0); } // 0x5F4C08A2
	static void STREAMING_SET_CUTSCENE_MODE(Any p0) { invoke<void>(0x83088F62, p0); } // 0x83088F62
	static void STREAMING_ENABLE_BOUNDS(Any p0) { invoke<void>(0x0BEBB187, p0); } // 0x0BEBB187
	static void STREAMING_LOAD_BOUNDS(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x0F8FC4D0, p0, p1, p2, p3, p4); } // 0x0F8FC4D0
	static void STREAMING_LOAD_BOUNDS_EXT(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x1CD960B8, p0, p1, p2, p3, p4); } // 0x1CD960B8
	static void STREAMING_UNLOAD_BOUNDS() { invoke<void>(0x09A67EC6); } // 0x09A67EC6
	static int STREAMING_DISPLAY_DEBUG_INFO(Any p0) { return invoke<int>(0xF7BABE84, p0); } // 0xF7BABE84
	static void STREAMING_EVICT_ALL(Any p0) { invoke<void>(0x7D432781, p0); } // 0x7D432781
	static BOOL IS_PLAYER_TELEPORTING() { return invoke<BOOL>(0x8EB0B2AD); } // 0x8EB0B2AD
	static void DUMP_MEMORY_STATS() { invoke<void>(0xCA99D3B4); } // 0xCA99D3B4
	static void REPORT_METRICS_PERFORMANCE() { invoke<void>(0xE74C4851); } // 0xE74C4851
	static void STREAMING_SET_POI_LIMIT() { invoke<void>(0x6F9C399B); } // 0x6F9C399B
	static void STREAMING_ENABLE_FORCE_FRAGMENT_HIGH_LOD(Any p0) { invoke<void>(0xBEABC729, p0); } // 0xBEABC729
	static void STREAMING_DISABLE_FORCE_FRAGMENT_HIGH_LOD(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0xB226E8E3, p0, p1, p2, p3, p4, p5); } // 0xB226E8E3
	static int STREAMING_ENABLE_FORCE_CHILD_SECTOR_HIGH_LOD(Any p0) { return invoke<int>(0xE981992C, p0); } // 0xE981992C
	static int STREAMING_DISABLE_FORCE_CHILD_SECTOR_HIGH_LOD(Any p0) { return invoke<int>(0x8CC6066C, p0); } // 0x8CC6066C
	// PC only, hash generated at runtime
	static Any STREAMING_ENABLE_FORCE_CHILD_SECTOR_LOW_LOD(Any p0) { return invoke<Any>(0x5B4999C2, p0); } // 0x5B4999C2
	// PC only, hash generated at runtime
	static Any STREAMING_DISABLE_FORCE_CHILD_SECTOR_LOW_LOD(Any p0) { return invoke<Any>(0x3602DA93, p0); } // 0x3602DA93
	static int RESIZE_ACTOR_SET() { return invoke<int>(0x83E043A6); } // 0x83E043A6
}

namespace STRING
{
	static BOOL IS_STRING_VALID(const char* text) { return invoke<BOOL>(0xBDC61056, text); } // 0xBDC61056
	static BOOL STRINGS_ARE_EQUAL(const char* string1, const char* string2) { return invoke<BOOL>(0x8218D693, string1, string2); } // 0x8218D693
	static BOOL STRINGS_ARE_EQUAL_CLAMPED(const char* string1, const char* string2, int maxLength) { return invoke<BOOL>(0xEC28CA8E, string1, string2, maxLength); } // 0xEC28CA8E
	static BOOL STRING_CONTAINS_STRING(const char* string, const char* subString) { return invoke<BOOL>(0xFCAFC819, string, subString); } // 0xFCAFC819
	static float STRING_TO_FLOAT(const char* string) { return invoke<float>(0x43BE70B5, string); } // 0x43BE70B5
	static int STRING_TO_INT(const char* string) { return invoke<int>(0x590A8160, string); } // 0x590A8160
	static int STRING_TO_HASH(const char* string) { return invoke<int>(0x84415E28, string); } // 0x84415E28
	static int STRING_LENGTH(const char* string) { return invoke<int>(0x6CE4B233, string); } // 0x6CE4B233
	static int STRINGTABLE_LENGTH(const char* string) { return invoke<int>(0x71D550C6, string); } // 0x71D550C6
	static void STRING_LOWER(const char* inputString) { invoke<void>(0x3E785560, inputString); } // 0x3E785560
	static void STRING_UPPER(const char* inputString) { invoke<void>(0xBC5B2116, inputString); } // 0xBC5B2116
	static void STRING_TOKENIZE(const char* string, const char* token) { invoke<void>(0x346E91C2, string, token); } // 0x346E91C2
	static int STRING_NUM_TOKENS() { return invoke<int>(0x7FB72180); } // 0x7FB72180
	static const char* STRING_GET_TOKEN(int token) { return invoke<const char*>(0xEE2791E5, token); } // 0xEE2791E5
	static void STRING_CLEAR_TOKENIZER() { invoke<void>(0x10873616); } // 0x10873616
	static void SS_INIT(int config) { invoke<void>(0x8785E0CE, config); } // 0x8785E0CE
	static void SS_REGISTER(const char* registerName, int componentType, int registrationFlags) { invoke<void>(0xFD717A47, registerName, componentType, registrationFlags); } // 0xFD717A47
	static const char* SS_GET_STRING(int stringIndex, int fetchType) { return invoke<const char*>(0x20D34AC5, stringIndex, fetchType); } // 0x20D34AC5
	static int SS_GET_STRING_ID(const char* stringReference, int fetchType) { return invoke<int>(0xA2D27A1F, stringReference, fetchType); } // 0xA2D27A1F
	static void SS_FINALIZE() { invoke<void>(0xEC1E8210); } // 0xEC1E8210
	static void SS_UNFINALIZE() { invoke<void>(0xBEDF7AA8); } // 0xBEDF7AA8
	static void SS_SET_TABLE_SIZE(int tableCategory, int tableSize) { invoke<void>(0xAFFA5ABE, tableCategory, tableSize); } // 0xAFFA5ABE
}

namespace STRINGTABLE
{
	static void STRINGTABLE_APPEND_TABLE(const char* stringData) { invoke<void>(0xB3E44649, stringData); } // 0xB3E44649
	static void REQUEST_STRING_TABLE(const char* stringTable) { invoke<void>(0x82B4DCCE, stringTable); } // 0x82B4DCCE
	static BOOL HAS_STRING_TABLE_LOADED(const char* stringTable) { return invoke<BOOL>(0x12D77EEC, stringTable); } // 0x12D77EEC
	static void REMOVE_STRING_TABLE(const char* stringTable) { invoke<void>(0x6857E514, stringTable); } // 0x6857E514
}

namespace TARGETING
{
	static Actor GET_ACTOR_UNDER_RETICLE(Actor actor, int p1) { return invoke<Actor>(0x86BAAC6C, actor, p1); } // 0x86BAAC6C
	static int GET_RETICLE_TARGET_POINT(Actor actor, Vector3* coords) { return invoke<int>(0x8AE7281E, actor, coords); } // 0x8AE7281E
	static int SET_PLAYER_PERFECT_ACCURACY(Any p0, Any p1) { return invoke<int>(0x5F566576, p0, p1); } // 0x5F566576
	static int OVERRIDE_PLAYER_TARGETING_WEIGHTS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, float p8, float p9) { return invoke<int>(0xD95C01D2, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xD95C01D2
	static int SET_ACTOR_BASE_SCORE(Any p0, float p1, Any p2, Any p3) { return invoke<int>(0x91220723, p0, p1, p2, p3); } // 0x91220723
	static int SET_ACTOR_HARDLOCK_BIAS(Any p0, float p1, Any p2, Any p3) { return invoke<int>(0x856C3A8A, p0, p1, p2, p3); } // 0x856C3A8A
	static int SET_ACTOR_USE_FULLSCREEN_ACQUISITION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x6400E005, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x6400E005
	static int SET_ACTOR_CAN_BE_TARGETED(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0xF1607937, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xF1607937
	static int SET_ACTOR_CAN_BE_TARGETED_CASUAL_ONLY(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x0753A098, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x0753A098
	static int SET_ACTOR_CAN_BE_HARDLOCKED(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0xF4429710, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xF4429710
	static BOOL ACTOR_CAN_BE_HARDLOCKED(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<BOOL>(0x1468DD56, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x1468DD56
	static int SET_ACTOR_CAN_BE_SOFTLOCKED(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<int>(0x327E4426, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x327E4426
	static void SET_ACTOR_CAN_BE_AIMASSISTED(Any p0, Any p1) { invoke<void>(0xAC8D3A0C, p0, p1); } // 0xAC8D3A0C
	static void SET_ACTOR_CAN_BE_BUMPTARGETED(Any p0, Any p1) { invoke<void>(0x57055A7D, p0, p1); } // 0x57055A7D
	static void SET_ACTOR_ONLY_HARDLOCK_IF_HOSTILE(Any p0, Any p1) { invoke<void>(0x5CC16A49, p0, p1); } // 0x5CC16A49
	static void IS_ACTOR_IN_ACCURACY_RANGE() { invoke<void>(0x7E124E62); } // 0x7E124E62
	static void SET_CAN_ACTOR_HARDLOCK_NEUTRALS(Any p0, Any p1) { invoke<void>(0x1EEE7494, p0, p1); } // 0x1EEE7494
	static float CALCULATE_NORMALIZED_SCREEN_DISTANCE_FROM_RETICLE(Any p0, Any p1) { return invoke<float>(0xD19EFFC1, p0, p1); } // 0xD19EFFC1
}

namespace TASKS
{
	static void TASK_ACTION_PERFORM(Any p0, Any p1) { invoke<void>(0xE32F09B3, p0, p1); } // 0xE32F09B3
	static int TASK_ACTION_PERFORM_AT_POSITION(Any p0, Any p1, Any p2, float p3, float p4, float p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x3F20B619, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x3F20B619
	static int TASK_ACTION_PERFORM_ON_TARGET(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0xD7E582B1, p0, p1, p2, p3); } // 0xD7E582B1
	static void TASK_ANIMAL_PATROL(Any p0, Any p1) { invoke<void>(0xF54E4D45, p0, p1); } // 0xF54E4D45
	static void TASK_ANIMAL_CIRCLE_AGGRESSIVELY(Any p0, Any p1) { invoke<void>(0xEACE773D, p0, p1); } // 0xEACE773D
	static int TASK_ANIMAL_FOLLOW_AGGRESSIVELY(Any p0, Any p1, Any p2) { return invoke<int>(0x7ED7676D, p0, p1, p2); } // 0x7ED7676D
	static int TASK_ANIMAL_HUNT(Any p0, Any p1, Any p2) { return invoke<int>(0xD9B07798, p0, p1, p2); } // 0xD9B07798
	static int TASK_BE_DEAD(Any p0, Any p1, Any p2, Any p3) { return invoke<int>(0x23AFEB8A, p0, p1, p2, p3); } // 0x23AFEB8A
	static int TASK_BE_DEAD_RANDOM(Any p0, Any p1, Any p2) { return invoke<int>(0x8EB3D852, p0, p1, p2); } // 0x8EB3D852
	static int TASK_BIRD_FLY_NEAR_COORD(Any p0, Any p1, float p2, float p3, float p4, Any p5, Any p6, Any p7, Any p8) { return invoke<int>(0x4730AC93, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x4730AC93
	static int TASK_BIRD_LAND(Any p0, Any p1) { return invoke<int>(0x525B028A, p0, p1); } // 0x525B028A
	static void TASK_BIRD_LAND_AT_COORD(Any p0, Any p1) { invoke<void>(0xAD0E49E3, p0, p1); } // 0xAD0E49E3
	static int TASK_BIRD_SOAR(Any p0, float p1, float p2, Any p3, Any p4, Any p5) { return invoke<int>(0x2C5F5E1B, p0, p1, p2, p3, p4, p5); } // 0x2C5F5E1B
	static void TASK_BIRD_SOAR_AT_COORD(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x69CCFD7C, p0, p1, p2, p3); } // 0x69CCFD7C
	static void TASK_CROUCH(Any p0, Any p1) { invoke<void>(0x616C803C, p0, p1); } // 0x616C803C
	static void TASK_DISMOUNT(Any p0, Any p1) { invoke<void>(0x5DEF5C4A, p0, p1); } // 0x5DEF5C4A
	static void TASK_DIVE(Any p0, Any p1) { invoke<void>(0xECAD08C7, p0, p1); } // 0xECAD08C7
	static int TASK_DIVEAWAYFROM(Any p0, Any p1, Any p2) { return invoke<int>(0xF1A3F362, p0, p1, p2); } // 0xF1A3F362
	static int TASK_DIVETOWARD(Any p0, Any p1, Any p2) { return invoke<int>(0x342F21D2, p0, p1, p2); } // 0x342F21D2
	static int TASK_DOOR_ACTION(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xFDD2905C, p0, p1, p2, p3, p4); } // 0xFDD2905C
	static void TASK_DRAW_HOLSTER_WEAPON(Any p0, Any p1) { invoke<void>(0xDB5F6B35, p0, p1); } // 0xDB5F6B35
	static void TASK_FACE_ACTOR(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x9F3B5B47, p0, p1, p2, p3); } // 0x9F3B5B47
	static void TASK_FACE_COORD(Any p0, Any p1, Any p2) { invoke<void>(0x31B598FB, p0, p1, p2); } // 0x31B598FB
	static void TASK_FLEE_COORD(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x826D3459, p0, p1, p2, p3, p4, p5); } // 0x826D3459
	static void TASK_FLEE_ACTOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x2CF32A98, p0, p1, p2, p3, p4, p5, p6); } // 0x2CF32A98
	static void TASK_FLEE_ACTORSET(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0xCD5E23C3, p0, p1, p2, p3, p4, p5, p6); } // 0xCD5E23C3
	static void TASK_FOLLOW_ACTOR(Actor actor, Actor followActor) { invoke<void>(0x12F0911A, actor, followActor); } // 0x12F0911A
	static void TASK_FOLLOW_AND_ATTACK_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { invoke<void>(0xDA646464, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xDA646464
	static int TASK_FOLLOW_AND_ATTACK_OBJECT_ALONG_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, float p5, float p6) { return invoke<int>(0x467D0FD5, p0, p1, p2, p3, p4, p5, p6); } // 0x467D0FD5
	static void TASK_FOLLOW_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { invoke<void>(0xFF3E3DCE, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xFF3E3DCE
	static void TASK_FOLLOW_OBJECT_ALONG_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x626C97D5, p0, p1, p2, p3, p4, p5); } // 0x626C97D5
	static void TASK_FOLLOW_OBJECT_AT_DISTANCE(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x75A4E05E, p0, p1, p2, p3); } // 0x75A4E05E
	static int TASK_FOLLOW_OBJECT_IN_FORMATION(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<int>(0xE2104FED, p0, p1, p2, p3, p4); } // 0xE2104FED
	static void TASK_FOLLOW_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x973DCC5B, p0, p1, p2, p3, p4, p5, p6); } // 0x973DCC5B
	static void TASK_FOLLOW_PATH_FROM_NEAREST_POINT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0x9591A996, p0, p1, p2, p3, p4, p5, p6); } // 0x9591A996
	static int TASK_FOLLOW_PATH_FROM_POINT() { return invoke<int>(0xCC8B2ECC); } // 0xCC8B2ECC
	static void TASK_GO_NEAR_ACTORSET(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xF7B01E74, p0, p1, p2, p3); } // 0xF7B01E74
	static void TASK_GO_NEAR_COORD(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x55EC940B, p0, p1, p2, p3); } // 0x55EC940B
	static void TASK_GO_NEAR_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x5EA4F1FE, p0, p1, p2, p3, p4, p5); } // 0x5EA4F1FE
	static void TASK_GO_TO_COORD(Any p0, Any p1, Any p2) { invoke<void>(0x8C574832, p0, p1, p2); } // 0x8C574832
	static void TASK_GO_TO_COORD_AND_STAY(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x8636587A, p0, p1, p2, p3); } // 0x8636587A
	static void TASK_GO_TO_COORD_NONSTOP(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xD62D6CE5, p0, p1, p2, p3); } // 0xD62D6CE5
	static void TASK_GO_TO_COORD_PRECISELY(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { invoke<void>(0x6BDB3257, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x6BDB3257
	static int TASK_GO_TO_COORD_USING_MATERIAL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<int>(0xAA3E5851, p0, p1, p2, p3, p4, p5); } // 0xAA3E5851
	static void TASK_GO_TO_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x01BACD08, p0, p1, p2, p3, p4); } // 0x01BACD08
	static int TASK_GUARD_PATROL_AUTO(Any p0, Any p1, float p2, Any p3, Any p4) { return invoke<int>(0x1AF7CE0E, p0, p1, p2, p3, p4); } // 0x1AF7CE0E
	static void TASK_GUARD_PATROL_PATH(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<void>(0xFA5BB172, p0, p1, p2, p3, p4, p5, p6); } // 0xFA5BB172
	static void TASK_GUARD_STAND(Any p0, Any p1, Any p2) { invoke<void>(0x99F65CC0, p0, p1, p2); } // 0x99F65CC0
	static void TASK_HIDE_AT_COVER(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0xAB8B96A5, p0, p1, p2, p3, p4); } // 0xAB8B96A5
	static void TASK_HORSE_ACTION(Any p0, Any p1) { invoke<void>(0x916FF236, p0, p1); } // 0x916FF236
	static int TASK_JUMP_OVER_OBSTRUCTION(Any p0, Any p1, float p2, float p3, float p4, float p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<int>(0x97BDA4C8, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x97BDA4C8
	static int TASK_JUMP_TO_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<int>(0x46A326E6, p0, p1, p2, p3, p4, p5, p6); } // 0x46A326E6
	static void TASK_KILL_CHAR(Any p0, Any p1) { invoke<void>(0x1AE4B75B, p0, p1); } // 0x1AE4B75B
	static int TASK_LEDGE_ACTION(Any p0, Any p1, Any p2, Any p3, float p4, float p5, Any p6, Any p7, Any p8) { return invoke<int>(0x145B7C2B, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x145B7C2B
	static void TASK_MELEE_ATTACK(Any p0, Any p1, Any p2) { invoke<void>(0x4FEADDD9, p0, p1, p2); } // 0x4FEADDD9
	static void TASK_MOUNT(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0xB6131204, p0, p1, p2, p3, p4, p5); } // 0xB6131204
	static int TASK_PLAY_ANIM(Any p0) { return invoke<int>(0x5AB552C6, p0); } // 0x5AB552C6
	static void TASK_POINT_GUN_AT_COORD(Any p0, Any p1, Any p2) { invoke<void>(0xAD3729AD, p0, p1, p2); } // 0xAD3729AD
	static void TASK_POINT_GUN_AT_OBJECT(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x95C206C2, p0, p1, p2, p3); } // 0x95C206C2
	static void TASK_RESPOND_TO_HORSE_WHISTLE(Any p0, Any p1) { invoke<void>(0x69B924A7, p0, p1); } // 0x69B924A7
	static void TASK_SEARCH(Any p0, Any p1, Any p2) { invoke<void>(0x4E17E039, p0, p1, p2); } // 0x4E17E039
	static void TASK_SEARCH_FOR_OBJECT(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xD9B57910, p0, p1, p2, p3); } // 0xD9B57910
	static void TASK_SEEK_COVER_FROM_ACTOR(Any p0, Any p1) { invoke<void>(0xE1C8A1B3, p0, p1); } // 0xE1C8A1B3
	static int TASK_SEEK_COVER_FROM_COORD(Any p0, Any p1, Any p2) { return invoke<int>(0x3B0F53F4, p0, p1, p2); } // 0x3B0F53F4
	static void TASK_SEQUENCE_PERFORM(Any p0, Any p1) { invoke<void>(0x2DF2298C, p0, p1); } // 0x2DF2298C
	static void TASK_SEQUENCE_PERFORM_REPEATEDLY(Any p0, Any p1, Any p2) { invoke<void>(0xA7A50E4D, p0, p1, p2); } // 0xA7A50E4D
	static void TASK_SHOOT_AT_COORD(Any p0, Any p1, Any p2) { invoke<void>(0x601C22E3, p0, p1, p2); } // 0x601C22E3
	static void TASK_SHOOT_AT_COORD_FROM_POSITION(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x7B5FC704, p0, p1, p2, p3); } // 0x7B5FC704
	static void TASK_SHOOT_ENEMIES_FROM_ANY_COVER(Any p0, Any p1) { invoke<void>(0x3C9875E5, p0, p1); } // 0x3C9875E5
	static void TASK_SHOOT_ENEMIES_FROM_COVER(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xCE584BCF, p0, p1, p2, p3); } // 0xCE584BCF
	static void TASK_SHOOT_ENEMIES_FROM_POSITION(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xCF8DB984, p0, p1, p2, p3); } // 0xCF8DB984
	static int TASK_SHOOT_ENEMIES_FROM_PREFERRED_COVER(Any p0, Any p1, float p2, float p3, Any p4, Any p5, Any p6) { return invoke<int>(0x1813667D, p0, p1, p2, p3, p4, p5, p6); } // 0x1813667D
	static void TASK_SHOOT_FROM_COVER(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0x506B8205, p0, p1, p2, p3, p4); } // 0x506B8205
	static void TASK_SHOOT_FROM_POSITION(Any p0, Any p1, Any p2) { invoke<void>(0x326316DC, p0, p1, p2); } // 0x326316DC
	static int TASK_SIMPLE_BEHAVIOR() { return invoke<int>(0xDE18EDA3); } // 0xDE18EDA3
	static void TASK_STAND_STILL(Actor actor, float p1, int p2, int p3) { invoke<void>(0x6F80965D, actor, p1, p2, p3); } // 0x6F80965D
	static int TASK_STEALTH_ATTACK(Any p0, Any p1, Any p2) { return invoke<int>(0x86A98E99, p0, p1, p2); } // 0x86A98E99
	static void TASK_SURROUND_ACTOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x5DD80BEF, p0, p1, p2, p3, p4, p5); } // 0x5DD80BEF
	static void TASK_TAUNT_ACTOR(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0x9043D092, p0, p1, p2, p3, p4, p5); } // 0x9043D092
	static void TASK_TAUNT_ACTOR_IN_PLACE(Any p0, Any p1, Any p2) { invoke<void>(0x030FB1FA, p0, p1, p2); } // 0x030FB1FA
	static int TASK_TR_ACTION(Any p0, Any p1, float p2, Any p3, Any p4) { return invoke<int>(0x1C7834B1, p0, p1, p2, p3, p4); } // 0x1C7834B1
	static int TASK_TR_ACTION_ON_ACTOR(Any p0, Any p1, Any p2, float p3, Any p4, Any p5) { return invoke<int>(0x0CFA55B6, p0, p1, p2, p3, p4, p5); } // 0x0CFA55B6
	static void TASK_USE_GRINGO(Actor actor, int p1, const char* p2, int p3, int p4) { invoke<void>(0xA0E003A7, actor, p1, p2, p3, p4); } // 0xA0E003A7
	static int TASK_USE_GRINGO_GROUP(Any p0, Any p1, float p2, Any p3, Any p4) { return invoke<int>(0x065D93BD, p0, p1, p2, p3, p4); } // 0x065D93BD
	static void TASK_USE_LASSO(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<void>(0xC41AAF49, p0, p1, p2, p3, p4, p5); } // 0xC41AAF49
	static int TASK_USE_TURRET(Any p0, Any p1, float p2, Any p3, Any p4) { return invoke<int>(0x6484F21E, p0, p1, p2, p3, p4); } // 0x6484F21E
	static void TASK_USE_TURRET_AGAINST_COORD(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x3B8DBA13, p0, p1, p2, p3); } // 0x3B8DBA13
	static void TASK_USE_TURRET_AGAINST_OBJECT(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x49EC6A04, p0, p1, p2, p3); } // 0x49EC6A04
	static void TASK_VEHICLE_ENTER(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xB2CD5160, p0, p1, p2, p3); } // 0xB2CD5160
	static void TASK_VEHICLE_ENTER_SPECIFIC_LOCATION(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<void>(0xDC087173, p0, p1, p2, p3, p4); } // 0xDC087173
	static void TASK_VEHICLE_LEAVE(Any p0) { invoke<void>(0x6C1218A4, p0); } // 0x6C1218A4
	static void TASK_WANDER(Any p0, Any p1) { invoke<void>(0x17BCA08E, p0, p1); } // 0x17BCA08E
	static void TASK_WANDER_IN_BOX(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x6840D3C1, p0, p1, p2, p3); } // 0x6840D3C1
	static void TASK_WANDER_IN_VOLUME(Any p0, Any p1, Any p2) { invoke<void>(0xA5F2BFAA, p0, p1, p2); } // 0xA5F2BFAA
	static int TASK_WARN_CHAR(Any p0, Any p1, Any p2) { return invoke<int>(0x9ABE6BC0, p0, p1, p2); } // 0x9ABE6BC0
	static void TASK_GO_NEAR_ACTOR(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0x3EB7590C, p0, p1, p2, p3); } // 0x3EB7590C
	static int GET_TASK_STATUS(Any p0, Any p1) { return invoke<int>(0xCCE01E8A, p0, p1); } // 0xCCE01E8A
	static int IS_TASKED_TO_USE_GRINGO_FOREVER(Any p0, Any p1) { return invoke<int>(0x600A0EE4, p0, p1); } // 0x600A0EE4
	static int GET_NTH_TASK_STATUS(Any p0, Any p1) { return invoke<int>(0x016C6801, p0, p1); } // 0x016C6801
	static int GET_TASK_SEQUENCE_CURRENT_TASK_INDEX(Any p0, Any p1) { return invoke<int>(0xD062CBF6, p0, p1); } // 0xD062CBF6
	static int GET_TASK_NEXT_POINT_ON_PATH(Any p0, Any p1) { return invoke<int>(0xF726557C, p0, p1); } // 0xF726557C
	static void TASK_CLEAR(Actor actor) { invoke<void>(0x16876A25, actor); } // 0x16876A25
	static void TASK_OVERRIDE_CLEAR_MOVETYPE(Any p0) { invoke<void>(0x9B9C8628, p0); } // 0x9B9C8628
	static void TASK_OVERRIDE_CLEAR_POSTURE(Any p0) { invoke<void>(0x5394CF3B, p0); } // 0x5394CF3B
	static void TASK_OVERRIDE_SET_MOVETYPE(Any p0, Any p1) { invoke<void>(0x172477F0, p0, p1); } // 0x172477F0
	static void TASK_OVERRIDE_SET_MOVESPEED_ABSOLUTE(Any p0, Any p1) { invoke<void>(0xCE843315, p0, p1); } // 0xCE843315
	static void TASK_OVERRIDE_SET_MOVESPEED_NORMALIZED(Any p0, Any p1) { invoke<void>(0x96F3BD31, p0, p1); } // 0x96F3BD31
	static void TASK_OVERRIDE_SET_POSTURE(Any p0, Any p1) { invoke<void>(0x52D34567, p0, p1); } // 0x52D34567
	static void TASK_PRIORITY_SET(Any p0, Any p1) { invoke<void>(0x3A95A656, p0, p1); } // 0x3A95A656
	static int TASK_SEQUENCE_OPEN() { return invoke<int>(0x8DA34524); } // 0x8DA34524
	static void TASK_SEQUENCE_CLOSE() { invoke<void>(0x9EE3053B); } // 0x9EE3053B
	static void TASK_SEQUENCE_RELEASE(Any p0, Any p1) { invoke<void>(0xB2D35E22, p0, p1); } // 0xB2D35E22
	static void SET_ACTOR_FACE_STYLE(Any p0, Any p1) { invoke<void>(0x08654394, p0, p1); } // 0x08654394
	static void AI_SET_ENABLE_STICKUP_OVERRIDE(Any p0, Any p1) { invoke<void>(0x1436588F, p0, p1); } // 0x1436588F
	static void AI_SET_ENABLE_HORSE_CHARGE_REACTIONS(Any p0, Any p1) { invoke<void>(0xF3D88421, p0, p1); } // 0xF3D88421
	static void AI_SET_ENABLE_DEAD_BODY_REACTIONS(Any p0, Any p1) { invoke<void>(0x1978C111, p0, p1); } // 0x1978C111
	static void TASK_FAILURE_MODE_SET(Any p0, Any p1) { invoke<void>(0x26EBE467, p0, p1); } // 0x26EBE467
}

namespace TIME
{
	static int GET_MINUTES_FROM_TIME_OF_DAY(int timeOfDay) { return invoke<int>(0x7C3D1193, timeOfDay); } // 0x7C3D1193
	static Any GET_TIME_OF_DAY_AS_INT(Any p0) { return invoke<Any>(0x061A2A3C, p0); } // 0x061A2A3C
	static int GET_TOTAL_MINUTES(int timeInSeconds) { return invoke<int>(0xC52F07A8, timeInSeconds); } // 0xC52F07A8
	static int CONVERT_TIME_OF_DAY_TO_INT(int timeOfDay) { return invoke<int>(0x57FC0E16, timeOfDay); } // 0x57FC0E16
	static void SET_DAY(int dayOfWeek) { invoke<void>(0x0EBBDC34, dayOfWeek); } // 0x0EBBDC34
	static int GET_HOUR(int hour) { return invoke<int>(0x2765C37E, hour); } // 0x2765C37E
	static int GET_MINUTE(int minute) { return invoke<int>(0x1020BF6D, minute); } // 0x1020BF6D
	static int GET_SECOND(int second) { return invoke<int>(0xBA8077CF, second); } // 0xBA8077CF
	static int GET_DAY(int dayOfWeek) { return invoke<int>(0x63D13FB0, dayOfWeek); } // 0x63D13FB0
	static void ADD_TIME(int hours, int minutes, int seconds, int milliseconds, BOOL wrapAround) { invoke<void>(0xBA4FEEBC, hours, minutes, seconds, milliseconds, wrapAround); } // 0xBA4FEEBC
	static void ADD_TIME_USING_TIME_OF_DAY(int timeOfDay, int timeToAdd) { invoke<void>(0x2F7CB0E3, timeOfDay, timeToAdd); } // 0x2F7CB0E3
	static int GET_TIME_OF_DAY() { return invoke<int>(0x4E1DE7A5); } // 0x4E1DE7A5
	static int MAKE_TIME_OF_DAY(int hour, int minute, int second) { return invoke<int>(0xC09EAB6E, hour, minute, second); } // 0xC09EAB6E
	static int MAKE_TIME_OF_DAY_EX(int* hour, int* minute, int* second, int* milliseconds) { return invoke<int>(0x0E453CF0, hour, minute, second, milliseconds); } // 0x0E453CF0
	static BOOL IS_LATER_THAN(Any p0) { return invoke<BOOL>(0x2DB3AC0F, p0); } // 0x2DB3AC0F
	static Any IS_EARLIER_THAN(Any p0, Any p1) { return invoke<Any>(0x9C9529D8, p0, p1); } // 0x9C9529D8
	static Any TIME_IS_IN_RANGE(Any p0, Any p1) { return invoke<Any>(0x243AF970, p0, p1); } // 0x243AF970
	static Any ADVANCE_TIME_HOURS() { return invoke<Any>(0xD4FECCBC); } // 0xD4FECCBC
	static void SET_TIME_OF_DAY(int time) { invoke<void>(0xAD03186C, time); } // 0xAD03186C
	static Any SET_TIME_ACCELERATION() { return invoke<Any>(0xB98C7AA5); } // 0xB98C7AA5
	static Any GET_TIME_ACCELERATION() { return invoke<Any>(0xC87F16A8); } // 0xC87F16A8
	static Any SET_TIME_WARP(Any p0) { return invoke<Any>(0xD93E1BCB, p0); } // 0xD93E1BCB
	static Any CANCEL_TIME_WARP(Any p0) { return invoke<Any>(0xAF50E8A1, p0); } // 0xAF50E8A1
}

namespace TURRET
{
	static BOOL IS_USING_TURRET(int actor) { return invoke<BOOL>(0x2C5983E0, actor); } // 0x2C5983E0
}

namespace UI
{
	static int UI_STACKPOP(Any p0) { return invoke<int>(0x97A50E69, p0); } // 0x97A50E69
	static void UI_STACKPUSH(const char* uilayer) { invoke<void>(0xB1A2028A, uilayer); } // 0xB1A2028A
	static void UI_POP(const char* uiLayer) { invoke<void>(0xBEE5CF6C, uiLayer); } // 0xBEE5CF6C
	static void UI_PUSH(const char* uiLayer) { invoke<void>(0x97C5EFC8, uiLayer); } // 0x97C5EFC8
	static void UI_GOTO(const char* uiLayer) { invoke<void>(0xA0159C77, uiLayer); } // 0xA0159C77
	static void UI_EXIT(const char* uiLayer) { invoke<void>(0x2DF89C2E, uiLayer); } // 0x2DF89C2E
	static void UI_SHOW(const char* uiLayer) { invoke<void>(0xD1D1D467, uiLayer); } // 0xD1D1D467
	static void UI_REFRESH(const char* uiLayer) { invoke<void>(0xFAC3DF71, uiLayer); } // 0xFAC3DF71
	static void UI_HIDE(const char* uiLayer) { invoke<void>(0x7508E7F3, uiLayer); } // 0x7508E7F3
	static void UI_ENABLE(const char* uiLayer) { invoke<void>(0xE576DCAD, uiLayer); } // 0xE576DCAD
	static void UI_DISABLE(const char* uiLayer) { invoke<void>(0xC4532F84, uiLayer); } // 0xC4532F84
	static BOOL UI_ISACTIVE(const char* UiLayer) { return invoke<BOOL>(0xB1FDB70D, UiLayer); } // 0xB1FDB70D
	static void UI_ACTIVATE(const char* UiLayer) { invoke<void>(0xD11BD55A, UiLayer); } // 0xD11BD55A
	static void UI_DEACTIVATE(const char* UiLayer) { invoke<void>(0xCA35BB5E, UiLayer); } // 0xCA35BB5E
	static void UI_EXCLUDE(const char* uiLayer) { invoke<void>(0x4A005F2A, uiLayer); } // 0x4A005F2A
	static void UI_INCLUDE(const char* uiLayer) { invoke<void>(0x209255AD, uiLayer); } // 0x209255AD
	static BOOL UI_ISFOCUSED(const char* uiLayer) { return invoke<BOOL>(0x6F2509E8, uiLayer); } // 0x6F2509E8
	static void UI_FOCUS(const char* uiLayer) { invoke<void>(0x699CC85E, uiLayer); } // 0x699CC85E
	static void UI_UNFOCUS(const char* uiLayer) { invoke<void>(0x0ACEA059, uiLayer); } // 0x0ACEA059
	static void UI_RESTORE(const char* uiLayer) { invoke<void>(0x7ADB2BE7, uiLayer); } // 0x7ADB2BE7
	static void UI_SUPPRESS(const char* uiLayer) { invoke<void>(0x182EC44A, uiLayer); } // 0x182EC44A
	static int UI_SENDEVENT() { return invoke<int>(0xF10A56C5); } // 0xF10A56C5
	static int UI_GET_SELECTED_INDEX(const char* uiLayer, BOOL validateSelection) { return invoke<int>(0x8B63A008, uiLayer, validateSelection); } // 0x8B63A008
	static void UI_SET_STYLE(const char* uiLayer, BOOL enableStyle) { invoke<void>(0x1ECD8B18, uiLayer, enableStyle); } // 0x1ECD8B18
	static void UI_ADD_CHILD(const char* parentComponent, const char* childComponent) { invoke<void>(0x13F156A4, parentComponent, childComponent); } // 0x13F156A4
	static void UI_SET_DATA(const char* componentName, const char* dataKey, const char* dataValue) { invoke<void>(0x00B89B46, componentName, dataKey, dataValue); } // 0x00B89B46
	static int UI_GET_NUM_CHILDREN(const char* componentName) { return invoke<int>(0xD3C7AEFA, componentName); } // 0xD3C7AEFA
	static void UI_ANIM_SETUP(const char* animName, int animState, BOOL shouldAnimate, int duration) { invoke<void>(0xCBDE38C6, animName, animState, shouldAnimate, duration); } // 0xCBDE38C6
	static void UI_ANIM_RESTART(const char* animName) { invoke<void>(0x4068D2E4, animName); } // 0x4068D2E4
	static float UI_ANIM_GET_TIME(const char* animName) { return invoke<float>(0x7EB1ED99, animName); } // 0x7EB1ED99
	// textureConfig is a constant for texture grouping or streaming configuration, where '16' represents a specific group or setting.
	static void UI_REGISTER_STREAMING_TEXTURE(const char* texturePath, const char* textureName, BOOL isStreaming, int textureConfig) { invoke<void>(0x1F9EE9E1, texturePath, textureName, isStreaming, textureConfig); } // 0x1F9EE9E1
	static void UI_SET_STRING(const char* gxtName, const char* string) { invoke<void>(0xE457546C, gxtName, string); } // 0xE457546C
	static void UI_SET_STRING_FORMAT(const char* gxtName, const char* formatString, const char* string1, const char* string2, const char* string3) { invoke<void>(0xEDA84121, gxtName, formatString, string1, string2, string3); } // 0xEDA84121
	static void UI_SET_MONEY(const char* uiElement, const char* moneyType, int amount) { invoke<void>(0xF71BD93A, uiElement, moneyType, amount); } // 0xF71BD93A
	static const char* UI_GET_STRING(const char* gxtEntry) { return invoke<const char*>(0xCCCFF80B, gxtEntry); } // 0xCCCFF80B
	static const char* UI_GET_STRING_BY_HASH(Hash stringHash) { return invoke<const char*>(0xBA89F5EA, stringHash); } // 0xBA89F5EA
	static void UI_MESSAGEBOX_SET_DESCRIPTION(const char* messageBoxId, const char* messageDescription) { invoke<void>(0x591339B9, messageBoxId, messageDescription); } // 0x591339B9
	static void UI_LABEL_SET_TEXT(const char* labelID, const char* labelText) { invoke<void>(0xB3FC8CB7, labelID, labelText); } // 0xB3FC8CB7
	static void UI_LABEL_SET_VALUE(const char* labelId, int newValue) { invoke<void>(0xDF50D8DE, labelId, newValue); } // 0xDF50D8DE
	static void UI_LABEL_SET_VALUE_B(const char* areaId, int durationInSeconds) { invoke<void>(0xF53EB511, areaId, durationInSeconds); } // 0xF53EB511
	static void UI_BUTTON_SET_TEXT(const char* buttonId, const char* buttonText) { invoke<void>(0x3DB16A3D, buttonId, buttonText); } // 0x3DB16A3D
	static void UI_TEXTURE_SET_NAME(const char* textureId, const char* textureName) { invoke<void>(0x9A56C3F3, textureId, textureName); } // 0x9A56C3F3
	static int UI_TEXTURE_SET_HASH(Any p0) { return invoke<int>(0x573BEF3B, p0); } // 0x573BEF3B
	static void UI_SET_TEXT(const char* labelId, const char* text) { invoke<void>(0xC464D5DD, labelId, text); } // 0xC464D5DD
	static void UI_SET_TEXT_HASH(Any p0, Any p1) { invoke<void>(0x06FD03D2, p0, p1); } // 0x06FD03D2
	static void UI_SET_PROGRESS_BAR_VAL(const char* progressBarId, float value) { invoke<void>(0xE5D53722, progressBarId, value); } // 0xE5D53722
	static void UI_SET_PROGRESS_BAR_CHANGE(const char* progressBarId, int changeValue) { invoke<void>(0xDF4627D1, progressBarId, changeValue); } // 0xDF4627D1
	static void _UI_SET_AUTO_EXIT_TIME(const char* uiElementId, float exitTime) { invoke<void>(0xD792B93B, uiElementId, exitTime); } // 0xD792B93B
	static void UI_SET_ICON(const char* iconId, int value) { invoke<void>(0x191BA4DF, iconId, value); } // 0x191BA4DF
	static void UI_DISABLE_INPUT(const char* uiLayer) { invoke<void>(0x9E2C2701, uiLayer); } // 0x9E2C2701
	static BOOL UI_IS_FUIMOVIE_LOADED(const char* movieName) { return invoke<BOOL>(0x9D20BDC4, movieName); } // 0x9D20BDC4
	static int UI_DISABLE_USE_CONTEXT_PROMPT(Any p0, Any p1) { return invoke<int>(0x1E732914, p0, p1); } // 0x1E732914
	// PC only, hash generated at runtime
	static int SET_RUNNING_BENCHMARK(Any p0) { return invoke<int>(0xD116B520, p0); } // 0xD116B520
	// PC only, hash generated at runtime
	static int GET_RUNNING_BENCHMARK(Any p0) { return invoke<int>(0x2DFDDDD9, p0); } // 0x2DFDDDD9
}

namespace UI_HUD
{
	static void UI_ADDICON(int iconId, const char* iconName) { invoke<void>(0x724B4E9B, iconId, iconName); } // 0x724B4E9B
}

namespace VEHICLES
{
	static Vehicle GET_ACTOR_MOST_RECENT_VEHICLE(Actor actor) { return invoke<Vehicle>(0x58745E4B, actor); } // 0x58745E4B
	static BOOL IS_ACTOR_ON_TRAIN(Actor actor, BOOL p1) { return invoke<BOOL>(0xD36E2D54, actor, p1); } // 0xD36E2D54
	static BOOL IS_ACTOR_ON_BOAT(Actor actor) { return invoke<BOOL>(0x9EE8AB59, actor); } // 0x9EE8AB59
	static BOOL IS_ACTOR_VEHICLE(Actor actor) { return invoke<BOOL>(0x9751B167, actor); } // 0x9751B167
	static BOOL IS_ACTOR_DRAFT_VEHICLE(Actor actor) { return invoke<BOOL>(0x5D41D423, actor); } // 0x5D41D423
	static BOOL IS_ACTOR_DRIVING_VEHICLE(Actor actor) { return invoke<BOOL>(0xDC99C124, actor); } // 0xDC99C124
	static BOOL IS_ACTOR_JACKING_VEHICLE(Actor actor) { return invoke<BOOL>(0x1BA90C92, actor); } // 0x1BA90C92
	static BOOL IS_ACTOR_INSIDE_VEHICLE(Actor actor) { return invoke<BOOL>(0x12325AE7, actor); } // 0x12325AE7
	static BOOL IS_ACTOR_RIDING_VEHICLE(Actor actor) { return invoke<BOOL>(0xDE19A1F9, actor); } // 0xDE19A1F9
	static Vehicle GET_VEHICLE(Actor actor) { return invoke<Vehicle>(0xA0936EB6, actor); } // 0xA0936EB6
	static Any GET_ACTOR_VEHICLE_STATE(Any p0) { return invoke<Any>(0xCEA2449F, p0); } // 0xCEA2449F
	static int GET_NUM_DRAFTED_ACTORS(Actor actor) { return invoke<int>(0xDAB0D820, actor); } // 0xDAB0D820
	static BOOL SET_ACTOR_IN_VEHICLE(Actor actor, Vehicle vehicle, int seatId) { return invoke<BOOL>(0x32974F99, actor, vehicle, seatId); } // 0x32974F99
	static Actor GET_DRAFT_ACTOR(int harnessId, Actor actor) { return invoke<Actor>(0x48D5121D, harnessId, actor); } // 0x48D5121D
	static BOOL IS_ACTOR_DRAFTED(Actor actor) { return invoke<BOOL>(0xEF2C329D, actor); } // 0xEF2C329D
	static Any GET_ACTOR_DRAFTED_TO(Any p0) { return invoke<Any>(0xD89C14BA, p0); } // 0xD89C14BA
	static Any IS_SEAT_OCCUPIED(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0xF7400A47, p0, p1, p2, p3); } // 0xF7400A47
	static Any GET_ACTOR_IN_VEHICLE_SEAT(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<Any>(0xE8E94C3B, p0, p1, p2, p3, p4); } // 0xE8E94C3B
	static Any GET_NUM_AVAILABLE_SEATS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<Any>(0x3ACE659E, p0, p1, p2, p3, p4, p5, p6); } // 0x3ACE659E
	static Any GET_NUM_OCCUPIED_SEATS(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<Any>(0xF0354E46, p0, p1, p2, p3, p4, p5, p6); } // 0xF0354E46
	static BOOL ENABLE_VEHICLE_SEAT(Vehicle vehicle, int seatId, BOOL enable) { return invoke<BOOL>(0x6AC8234D, vehicle, seatId, enable); } // 0x6AC8234D
	static void STOP_VEHICLE(Vehicle vehicle) { invoke<void>(0xC2232D29, vehicle); } // 0xC2232D29
	static void START_VEHICLE(Vehicle vehicle) { invoke<void>(0xE4442AB2, vehicle); } // 0xE4442AB2
	static void ACCESSORIZE_VEHICLE_HORSES(Actor actor, int accessory) { invoke<void>(0xB12584C8, actor, accessory); } // 0xB12584C8
	static int GET_NUM_DRAFT_POSITIONS(Actor actor, int p1) { return invoke<int>(0xD85CA776, actor, p1); } // 0xD85CA776
	static void ATTACH_DRAFT_TO_VEHICLE(Actor actor, Vehicle vehicle, int harnessId, BOOL p3) { invoke<void>(0xB0A81226, actor, vehicle, harnessId, p3); } // 0xB0A81226
	static void DETACH_DRAFT_FROM_VEHICLE_BY_ACTOR(Any p0, Any p1, Any p2, Any p3) { invoke<void>(0xF763B06D, p0, p1, p2, p3); } // 0xF763B06D
	static void DETACH_DRAFT_FROM_VEHICLE_BY_INDEX(Any p0) { invoke<void>(0x8C3B533B, p0); } // 0x8C3B533B
	static void TRAIN_CREATE_NEW_TRAIN(Any p0) { invoke<void>(0x8533AC9D, p0); } // 0x8533AC9D
	static void TRAIN_DESTROY_TRAIN(Any p0) { invoke<void>(0x74CECEB3, p0); } // 0x74CECEB3
	static void TRAIN_RELEASE_TRAIN(Any p0) { invoke<void>(0x87082991, p0); } // 0x87082991
	static void TRAIN_IS_VALID(Any p0) { invoke<void>(0x7224CD9B, p0); } // 0x7224CD9B
	static Any TRAIN_ADD_TRAIN_CAR_FROM_ENUM(Any p0) { return invoke<Any>(0xA7A672FA, p0); } // 0xA7A672FA
	static Any TRAIN_GET_VELOCITY(Any p0) { return invoke<Any>(0xF2373407, p0); } // 0xF2373407
	static void TRAIN_SET_TARGET_POS(Any p0) { invoke<void>(0x9091E0A3, p0); } // 0x9091E0A3
	static void TRAIN_SET_SPEED(Any p0) { invoke<void>(0x9D93961C, p0); } // 0x9D93961C
	static void TRAIN_SET_TARGET_SPEED(Any p0) { invoke<void>(0xEA2A8B79, p0); } // 0xEA2A8B79
	static void TRAIN_SET_MAX_ACCEL(Any p0) { invoke<void>(0xB5383B93, p0); } // 0xB5383B93
	static void TRAIN_SET_MAX_DECEL(Any p0) { invoke<void>(0xB7A4D403, p0); } // 0xB7A4D403
	static void TRAIN_SET_ENGINE_ENABLED(Any p0, Any p1) { invoke<void>(0x6C62C522, p0, p1); } // 0x6C62C522
	static Any TRAIN_GET_NUM_CARS(Any p0) { return invoke<Any>(0xFB2F9989, p0); } // 0xFB2F9989
	static void TRAIN_SET_POSITION_DIRECTION(Any p0) { invoke<void>(0x9C488CB3, p0); } // 0x9C488CB3
	static Any TRAIN_SET_POSITION_DIRECTION_PRECISELY(Any p0) { return invoke<Any>(0x268D546D, p0); } // 0x268D546D
	static Any TRAIN_SET_FX(Any p0) { return invoke<Any>(0xBA1620AF, p0); } // 0xBA1620AF
	static Any TRAIN_PLAY_WHISTLE_SEQUENCE(Any p0) { return invoke<Any>(0x1440C806, p0); } // 0x1440C806
	static Any TRAIN_ENABLE_VISUAL_DEBUG(Any p0) { return invoke<Any>(0x4DF9283F, p0); } // 0x4DF9283F
	static Any TRAIN_DESTROY_CAR(Any p0) { return invoke<Any>(0x2040FB19, p0); } // 0x2040FB19
	static Any TRAIN_GET_LOD_LEVEL(Any p0) { return invoke<Any>(0xD8E0EF01, p0); } // 0xD8E0EF01
	static Any TRAIN_FORCE_HIGH_LOD(Any p0) { return invoke<Any>(0x43E6DCAC, p0); } // 0x43E6DCAC
	static Any TRAIN_GET_CAR(Any p0, Any p1) { return invoke<Any>(0x41EF2EED, p0, p1); } // 0x41EF2EED
	static Any TRAIN_SET_PARTICLE_EFFECTS_ENABLED(Any p0) { return invoke<Any>(0x7CFD539A, p0); } // 0x7CFD539A
	static Any TRAIN_SET_AUTOPILOT_ENABLE(Any p0, Any p1, Any p2) { return invoke<Any>(0xADE865AE, p0, p1, p2); } // 0xADE865AE
	static Any TRAIN_SET_AUDIO_ENABLE(Any p0) { return invoke<Any>(0x6A9C8E5B, p0); } // 0x6A9C8E5B
	static Any TRAIN_SET_JUNCTION_STATE(Any p0) { return invoke<Any>(0x1F9F8C04, p0); } // 0x1F9F8C04
	static Any TRAIN_GET_CURVE_NETWORK_POINT(Any p0, Any p1, Any p2) { return invoke<Any>(0xC5A04EC7, p0, p1, p2); } // 0xC5A04EC7
	static Any TRAIN_GET_NEAREST_POI_DISTANCE(Any p0, Any p1, Any p2) { return invoke<Any>(0x6FC1847D, p0, p1, p2); } // 0x6FC1847D
	static Any TRAIN_GET_POSITION(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x06D055AB, p0, p1, p2, p3); } // 0x06D055AB
	static void SET_BOAT_EXTRA_STEER(Any p0, Any p1) { invoke<void>(0x6BB8BCFB, p0, p1); } // 0x6BB8BCFB
	static void SET_VEHICLE_ENGINE_RUNNING(Vehicle vehicle, BOOL running) { invoke<void>(0x462B5FDF, vehicle, running); } // 0x462B5FDF
	static void IS_VEHICLE_ENGINE_RUNNING(Any p0, Any p1) { invoke<void>(0x8257A916, p0, p1); } // 0x8257A916
	static void SET_VEHICLE_ALLOWED_TO_DRIVE(Vehicle vehicle, BOOL allowed) { invoke<void>(0x55A56DF8, vehicle, allowed); } // 0x55A56DF8
	static BOOL IS_VEHICLE_ALLOWED_TO_DRIVE(Vehicle vehicle) { return invoke<BOOL>(0x1C391A44, vehicle); } // 0x1C391A44
	static void SET_VEHICLE_PASSENGERS_ALLOWED(Vehicle vehicle, BOOL allowed) { invoke<void>(0xBD0C1BEA, vehicle, allowed); } // 0xBD0C1BEA
	static void SET_VEHICLE_EJECTION_ENABLED(Vehicle vehicle, BOOL enabled) { invoke<void>(0x0ABD83C0, vehicle, enabled); } // 0x0ABD83C0
	static void VEHICLE_SET_HANDBRAKE(Vehicle vehicle, BOOL handbreak) { invoke<void>(0x384BB6AB, vehicle, handbreak); } // 0x384BB6AB
	static Any IS_ANY_VEHICLE_WHEEL_DETACHED(Any p0, Any p1, Any p2) { return invoke<Any>(0xF801CBD7, p0, p1, p2); } // 0xF801CBD7
	static Any GET_VEHICLE_WHEEL_COUNT_INITIAL(Any p0) { return invoke<Any>(0x71A3F193, p0); } // 0x71A3F193
	static Any GET_VEHICLE_WHEEL_COUNT_CURRENT(Any p0, Any p1, Any p2) { return invoke<Any>(0xFB252BA9, p0, p1, p2); } // 0xFB252BA9
}

namespace VOLUME
{
	static BOOL IS_VOLUME_VALID(Volume volume) { return invoke<BOOL>(0xBC33CEB5, volume); } // 0xBC33CEB5
	static BOOL IS_POINT_IN_VOLUME(float x, float y, float z, Volume volume) { return invoke<BOOL>(0xB85BB21B, x, y, z, volume); } // 0xB85BB21B
	static BOOL IS_ACTOR_IN_VOLUME(Actor actor, Volume volume) { return invoke<BOOL>(0xF5593A78, actor, volume); } // 0xF5593A78
	static void DELETE_PROJECTILES_IN_VOLUME(Volume volume) { invoke<void>(0x0F474297, volume); } // 0x0F474297
	static void GET_VOLUME_CENTER(Volume volume, float x, float y, float z) { invoke<void>(0x6729EEFE, volume, x, y, z); } // 0x6729EEFE
	static void SET_VOLUME_ENABLED(Volume volume, BOOL enabled) { invoke<void>(0x14D5CFC3, volume, enabled); } // 0x14D5CFC3
	static BOOL IS_VOLUME_ENABLED(Volume volume) { return invoke<BOOL>(0x29ED6F03, volume); } // 0x29ED6F03
	static float GET_VOLUME_HEADING(Volume volume) { return invoke<float>(0x8D5609F2, volume); } // 0x8D5609F2
	static void GET_VOLUME_SCALE(Volume volume, float x, float y, float z) { invoke<void>(0xE9C34ACC, volume, x, y, z); } // 0xE9C34ACC
	static void GENERATE_RANDOM_POINT_IN_VOLUME(Volume volume, Any p1) { invoke<void>(0x9FC69F27, volume, p1); } // 0x9FC69F27
	static void FIND_VOL_SURFACE_POINTS_FOR_POINT(Volume volume, Any p1, Any p2, Any p3) { invoke<void>(0x026F7060, volume, p1, p2, p3); } // 0x026F7060
}

namespace WEAPON
{
	static void INIT_NATIVE_WEAPONENUM_PISTOL(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xBAC27559, weaponEnum, weaponName, statValue); } // 0xBAC27559
	static void INIT_NATIVE_WEAPONENUM_RIFLE(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xA534CD14, weaponEnum, weaponName, statValue); } // 0xA534CD14
	static void INIT_NATIVE_WEAPONENUM_REPEATER(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xA72B6620, weaponEnum, weaponName, statValue); } // 0xA72B6620
	static void INIT_NATIVE_WEAPONENUM_SNIPERRIFLE(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0x92FE3677, weaponEnum, weaponName, statValue); } // 0x92FE3677
	static void INIT_NATIVE_WEAPONENUM_SHOTGUN(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xEA06907B, weaponEnum, weaponName, statValue); } // 0xEA06907B
	static void INIT_NATIVE_WEAPONENUM_THROWN(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xE0DF7B3B, weaponEnum, weaponName, statValue); } // 0xE0DF7B3B
	static void INIT_NATIVE_WEAPONENUM_THROWN_EXPLODING(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xA2597101, weaponEnum, weaponName, statValue); } // 0xA2597101
	static void INIT_NATIVE_WEAPONENUM_BOW(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0x2AD5D078, weaponEnum, weaponName, statValue); } // 0x2AD5D078
	static void INIT_NATIVE_WEAPONENUM_MELEE(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xA6C4E59F, weaponEnum, weaponName, statValue); } // 0xA6C4E59F
	static void INIT_NATIVE_WEAPONENUM_LASSO(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0xF82711CC, weaponEnum, weaponName, statValue); } // 0xF82711CC
	static void INIT_NATIVE_WEAPONENUM_TURRET(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0x82609DC7, weaponEnum, weaponName, statValue); } // 0x82609DC7
	static void INIT_NATIVE_WEAPONENUM_CANNON(int weaponEnum, const char* weaponName, float statValue) { invoke<void>(0x628E3173, weaponEnum, weaponName, statValue); } // 0x628E3173
	static void INIT_NATIVE_WEAPONENUM_AMMO(int weaponEnum, float ammoAttributes) { invoke<void>(0xCE5CCF2E, weaponEnum, ammoAttributes); } // 0xCE5CCF2E
	static const char* GET_WEAPON_ENUM_STRING_FROM_ENUM(int weaponEnum) { return invoke<const char*>(0x6A9CFA2A, weaponEnum); } // 0x6A9CFA2A
	static const char* GET_WEAPON_DISPLAY_NAME(int weaponEnum) { return invoke<const char*>(0x35CD589C, weaponEnum); } // 0x35CD589C
	static const char* GET_WEAPON_INTERNAL_NAME(int weaponEnum) { return invoke<const char*>(0x87C5471F, weaponEnum); } // 0x87C5471F
	static const char* _GET_WEAPON_ICON_NAME(int weaponEnum) { return invoke<const char*>(0xBE06C265, weaponEnum); } // 0xBE06C265
	static const char* GET_WEAPON_FRAGMENT_NAME(int weaponEnum) { return invoke<const char*>(0xE8739A48, weaponEnum); } // 0xE8739A48
	static void INIT_NATIVE_WEAPONENUM_CATEGORY(Any p0, Any p1) { invoke<void>(0x01C7193C, p0, p1); } // 0x01C7193C
	static void FINALIZE_WEAPONENUM_CATEGORIES() { invoke<void>(0x0A23A69C); } // 0x0A23A69C
	static void SET_WEAPONENUM_LOCKED(int weaponEnum, BOOL isLocked) { invoke<void>(0x0E4B7A33, weaponEnum, isLocked); } // 0x0E4B7A33
	static BOOL IS_WEAPONENUM_LOCKED(int weaponEnum) { return invoke<BOOL>(0xCCE4A339, weaponEnum); } // 0xCCE4A339
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eWeaponCategory
	static int GET_WEAPON_CATEGORY_FROM_ENUM(int weaponEnum) { return invoke<int>(0xDB679ED9, weaponEnum); } // 0xDB679ED9
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAmmoEnum
	static int GET_AMMO_ENUM(int weaponEnum) { return invoke<int>(0xD3E16075, weaponEnum); } // 0xD3E16075
	static int SET_AMMO_DROP_BIAS(Any p0, float p1) { return invoke<int>(0x08A655C5, p0, p1); } // 0x08A655C5
	// returns the ammoEnums string name. https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAmmoEnum
	static const char* GET_AMMO_ENUM_STRING_FROM_ENUM(int ammoEnum) { return invoke<const char*>(0xCCB57C38, ammoEnum); } // 0xCCB57C38
	// returns the ammoEnums icon name. https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eAmmoEnum
	static const char* GET_AMMO_ENUM_ICON_NAME(int ammoEnum) { return invoke<const char*>(0x2AF84928, ammoEnum); } // 0x2AF84928
	static float GET_WEAPON_MAX_AMMO(int weaponEnum) { return invoke<float>(0xA677B204, weaponEnum); } // 0xA677B204
	static void RESOLVE_DLC_WEAPONENUM(int weaponEnum) { invoke<void>(0xD291A820, weaponEnum); } // 0xD291A820
	static void ADD_IDLEFX_TO_WEAPON(const char* weaponName, float posX, float posY, float posZ) { invoke<void>(0xF4641CF4, weaponName, posX, posY, posZ); } // 0xF4641CF4
}

namespace WEATHER
{
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eWeather
	static void SET_WEATHER(int weatherType, int transitionSpeed) { invoke<void>(0x456D7F38, weatherType, transitionSpeed); } // 0x456D7F38
	// https://github.com/EvilBlunt/RDR-Strings-and-Enums/tree/main/eWeather
	static int GET_WEATHER() { return invoke<int>(0xEA026ED9); } // 0xEA026ED9
	static void SET_WEATHER_COMPLEX(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14) { invoke<void>(0xC157CA40, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14); } // 0xC157CA40
	static void SET_WIND(float direction, float intensity, float transitionSpeed) { invoke<void>(0xC6294698, direction, intensity, transitionSpeed); } // 0xC6294698
	static void SET_AUTO_WIND(Any p0) { invoke<void>(0x5D37C383, p0); } // 0x5D37C383
	static void SET_RAIN_AMOUNT(float rainIntensity) { invoke<void>(0xB788D24A, rainIntensity); } // 0xB788D24A
	static void SET_LIGHTNING_AMOUNT(float lightningIntensity) { invoke<void>(0xF0C9645A, lightningIntensity); } // 0xF0C9645A
	static void SET_WEATHER_TYPE_GOOD(BOOL isGoodWeather) { invoke<void>(0xC4C59CA4, isGoodWeather); } // 0xC4C59CA4
	// rainType:
	// enum eRainType
	// {
	// 	RAINY_LIGHT,
	// 	RAINY_MODERATE,
	// 	RAINY_HEAVY,
	// 	RAINY_TORRENTIAL
	// };
	static void SET_WEATHER_TYPE_RAINY(int rainType) { invoke<void>(0xA915DC46, rainType); } // 0xA915DC46
	static void TRIGGER_LIGHTNING_SEQUENCE() { invoke<void>(0x9B390724); } // 0x9B390724
	static void TRIGGER_CLOUD_LIGHTNING_SEQUENCE() { invoke<void>(0x858FD48D); } // 0x858FD48D
	static void ENABLE_WEATHER_SPHERE(BOOL enableWeather, BOOL allAreasAffected) { invoke<void>(0x17BCED9F, enableWeather, allAreasAffected); } // 0x17BCED9F
	static BOOL IS_WEATHER_SPHERE_ENABLED(BOOL toggle) { return invoke<BOOL>(0xFEEC4EE2, toggle); } // 0xFEEC4EE2
	static void _SET_SKY_IS_INTRO_RUNNING(BOOL isIntroRunning) { invoke<void>(0x21A68D47, isIntroRunning); } // 0x21A68D47
	// PC only
	static Any OVERRIDE_BENCHMARK_WEATHER(Any p0) { return invoke<Any>(0x8291ED47, p0); } // 0x8291ED47
	// PC only
	static Any OVERRIDE_BENCHMARK_TIME(Any p0) { return invoke<Any>(0xB288F455, p0); } // 0xB288F455
}

namespace WORLD
{
	static int CLEAR_AREA_OF_TREE_TYPE(float p0, float p1, float p2, float p3) { return invoke<int>(0x9A93E7CA, p0, p1, p2, p3); } // 0x9A93E7CA
	static int RESET_TREE_TYPE_CLEARING() { return invoke<int>(0x59A7835E); } // 0x59A7835E
	static int RESET_THIS_TREE_TYPE_CLEARING(Any p0) { return invoke<int>(0x25690082, p0); } // 0x25690082
	static int SET_DUST_LEVEL(Any p0) { return invoke<int>(0xE92C3435, p0); } // 0xE92C3435
	static int SET_DUST_LEVEL_MODIFIER(Any p0) { return invoke<int>(0xDB86F53B, p0); } // 0xDB86F53B
	static int SET_DUST_LEVEL_MID(Any p0) { return invoke<int>(0x8BA565F7, p0); } // 0x8BA565F7
	static int SET_DUST_LEVEL_FAR(Any p0) { return invoke<int>(0xB8E09389, p0); } // 0xB8E09389
	static int CLEAR_AREA_OF_GRASS(float p0, float p1, float p2, float p3) { return invoke<int>(0x9AA8A1B1, p0, p1, p2, p3); } // 0x9AA8A1B1
	static int CLEAR_AREA_OF_BREAKABLE_TREES(float p0, float p1, float p2, float p3, Any p4, Any p5, Any p6) { return invoke<int>(0x002B0698, p0, p1, p2, p3, p4, p5, p6); } // 0x002B0698
	static int RESET_THIS_BREAKABLE_TREE_CLEARING(Any p0) { return invoke<int>(0x57478561, p0); } // 0x57478561
	static int RESET_ALL_BREAKABLE_TREE_CLEARINGS() { return invoke<int>(0x39B0CFE5); } // 0x39B0CFE5
	static void RELOAD_SMICTIONARY_LIST() { invoke<void>(0xDCAE6935); } // 0xDCAE6935
	// PS4/Switch/PC only
	static void SET_ZOMBIE_DLC_IS_ACTIVE() { invoke<void>(0x28246500); } // 0x28246500
	static int ZOMBIE_DLC_IS_ACTIVE() { return invoke<int>(0x8CF15FCB); } // 0x8CF15FCB
	static int ZOMBIE_DLC_LOAD_ASSETS() { return invoke<int>(0x4A8066FB); } // 0x4A8066FB
	static int ZOMBIE_DLC_LOAD_ASSETS_MP() { return invoke<int>(0x1DDB57A6); } // 0x1DDB57A6
	static int ZOMBIE_DLC_UNLOAD_ASSETS() { return invoke<int>(0x88863344); } // 0x88863344
	static int ZOMBIE_DLC_IS_LOAD_COMPLETE() { return invoke<int>(0xE7371670); } // 0xE7371670
	static int ZOMBIE_DLC_IS_UNLOAD_COMPLETE() { return invoke<int>(0x03E2B631); } // 0x03E2B631
	static Any SET_PHOSPHORUS_AMMO_ACTIVE(Any p0) { return invoke<Any>(0xCA840DBB, p0); } // 0xCA840DBB
	static int IS_PHOSPHORUS_AMMO_ACTIVE() { return invoke<int>(0x4F3F3CA5); } // 0x4F3F3CA5
	static Any CREATE_FIRE_ON_OBJECT(Any p0) { return invoke<Any>(0xC587FA2B, p0); } // 0xC587FA2B
	static Any CREATE_FIRE_IN_VOLUME(int volume, FireHandle handle, int fireProperty, float x, float y, float z, BOOL isInfinite, BOOL shouldSpread) { return invoke<Any>(0xD4799325, volume, handle, fireProperty, x, y, z, isInfinite, shouldSpread); } // 0xD4799325
	static void STOP_ALL_FIRES() { invoke<void>(0x9544570A); } // 0x9544570A
	static void _STOP_ALL_FIRES_OLD() { invoke<void>(0x8011737F); } // 0x8011737F
	static int CREATE_FIRE_PROPERTY() { return invoke<int>(0x5402321A); } // 0x5402321A
	static Any* GET_FIRE_PROPERTY(Any p0) { return invoke<Any*>(0x2AC74780, p0); } // 0x2AC74780
	static void STOP_ALL_FIRE_IN_SPHERE(float x, float y, float z, float radius) { invoke<void>(0x466C02BA, x, y, z, radius); } // 0x466C02BA
	static void STOP_ALL_FIRE_IN_VOLUME() { invoke<void>(0xEC3A9EBB); } // 0xEC3A9EBB
	static int REPLACE_WORLD_SECTOR(Any p0, Any p1, Any p2) { return invoke<int>(0xADB3E8D9, p0, p1, p2); } // 0xADB3E8D9
	static void REPLACE_WORLD_SECTOR_LOAD_BOUNDING_BOX(const char* sectorName) { invoke<void>(0x08D06543, sectorName); } // 0x08D06543
	static void ENABLE_WORLD_SECTOR(const char* sectorName) { invoke<void>(0xAD5613FD, sectorName); } // 0xAD5613FD
	static void DISABLE_WORLD_SECTOR(const char* sectorName) { invoke<void>(0xB511D087, sectorName); } // 0xB511D087
	static void ENABLE_CHILD_SECTOR(const char* sectorName) { invoke<void>(0x7ECE15BE, sectorName); } // 0x7ECE15BE
	static void DISABLE_CHILD_SECTOR(const char* sectorName) { invoke<void>(0x9E1AE585, sectorName); } // 0x9E1AE585
	static void HIDE_CHILD_SECTOR(const char* sectorName) { invoke<void>(0x4E6A78B5, sectorName); } // 0x4E6A78B5
	static void SHOW_CHILD_SECTOR(const char* sectorName) { invoke<void>(0x63A83655, sectorName); } // 0x63A83655
	// PS4/Switch/PC only
	static void SET_USE_ACTOR_STAGGER(int actor) { invoke<void>(0xE437932A, actor); } // 0xE437932A
	static int FIRE_CREATE_HANDLE() { return invoke<int>(0xBBAE9CBD); } // 0xBBAE9CBD
	static BOOL FIRE_IS_HANDLE_VALID(FireHandle handle) { return invoke<BOOL>(0xA488E930, handle); } // 0xA488E930
	static void FIRE_RELEASE_HANDLE(FireHandle handle, BOOL deactivate) { invoke<void>(0xB14B936A, handle, deactivate); } // 0xB14B936A
	static void FIRE_RELEASE_INFINITE_HANDLE(FireHandle handle, float releaseStrength, float p2) { invoke<void>(0xD2BB733E, handle, releaseStrength, p2); } // 0xD2BB733E
	static int FIRE_FIND_HANDLE_FROM_ATTACHED_ACTOR(Any p0) { return invoke<int>(0x91396EB7, p0); } // 0x91396EB7
	static void FIRE_CREATE_ON_ACTOR(FireHandle handle, Actor actor) { invoke<void>(0x9679CF84, handle, actor); } // 0x9679CF84
	static void FIRE_CREATE_IN_VOLUME(FireHandle handle, float x, float y, float z, int heightFlag, int flag) { invoke<void>(0xB65ADFAC, handle, x, y, z, heightFlag, flag); } // 0xB65ADFAC
	static BOOL FIRE_IS_ACTOR_ON_FIRE(Actor actor) { return invoke<BOOL>(0x30C4CA99, actor); } // 0x30C4CA99
	static int FIRE_STOP_ALL_FIRES() { return invoke<int>(0x15001332); } // 0x15001332
	static void FIRE_STOP_ON_ACTOR(Actor actor) { invoke<void>(0xF635B9EA, actor); } // 0xF635B9EA
	static void FIRE_STOP_FLAMES_IN_VOLUME(Any p0) { invoke<void>(0x11A65FFB, p0); } // 0x11A65FFB
	static int FIRE_GET_OWNER(Any p0) { return invoke<int>(0x15683736, p0); } // 0x15683736
	static void FIRE_SET_OWNER(FireHandle handle, Actor actor) { invoke<void>(0xE5C7E4C9, handle, actor); } // 0xE5C7E4C9
	static void FIRE_SET_DAMAGE_ALLOWED(FireHandle handle, BOOL damageAllowed) { invoke<void>(0x3D5D3B26, handle, damageAllowed); } // 0x3D5D3B26
	static void FIRE_SET_CONTROL_VOLUME(Any p0, Any p1) { invoke<void>(0x03240324, p0, p1); } // 0x03240324
	static void FIRE_SET_MAX_FLAMES(FireHandle handle, int maxFlames) { invoke<void>(0xE5E04E83, handle, maxFlames); } // 0xE5E04E83
	static void FIRE_SET_TARGET_FILL_PERCENT(FireHandle handle, float targetFillPercent) { invoke<void>(0x9C471E7D, handle, targetFillPercent); } // 0x9C471E7D
	static void FIRE_SET_GROW_RATE(FireHandle handle, float growRate) { invoke<void>(0x1A82B949, handle, growRate); } // 0x1A82B949
	static void FIRE_SET_DECAY_RATE(FireHandle handle, float decayRate) { invoke<void>(0x7906A950, handle, decayRate); } // 0x7906A950
	static void FIRE_SET_EXPIRE_ALLOWED(FireHandle handle, BOOL allowExpire) { invoke<void>(0x6471D75C, handle, allowExpire); } // 0x6471D75C
	static void FIRE_SET_GROW_ALLOWED(Any p0, Any p1) { invoke<void>(0x53895856, p0, p1); } // 0x53895856
	static int COUNT_FLAMES_IN_SPHERE(float x, float y, float z, float radius) { return invoke<int>(0xDEE6523D, x, y, z, radius); } // 0xDEE6523D
	static int COUNT_FLAMES_IN_VOLUME(int volumeIndex) { return invoke<int>(0x3DD3E1EB, volumeIndex); } // 0x3DD3E1EB
	static int FIRE_ARE_ANY_FLAMES_IN_VOLUME(Any p0) { return invoke<int>(0x28DAED2A, p0); } // 0x28DAED2A
	static void FIRE_SET_GUNS_BLAZING_ACTIVE(BOOL isActive) { invoke<void>(0x3F67DEDB, isActive); } // 0x3F67DEDB
}

