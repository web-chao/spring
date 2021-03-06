/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MeleeWeapon.h"
#include "WeaponDef.h"
#include "Sim/Units/Unit.h"

CR_BIND_DERIVED(CMeleeWeapon, CWeapon, (nullptr, nullptr))
CR_REG_METADATA(CMeleeWeapon, )

void CMeleeWeapon::FireImpl(const bool scriptCall)
{
	if (currentTarget.type == Target_Unit) {
		const float3 impulseVec = wantedDir * owner->mass * damages->impulseFactor;

		// the heavier the unit, the more impulse it does
		currentTarget.unit->DoDamage(*damages, impulseVec, owner, weaponDef->id, -1);
	}
}
