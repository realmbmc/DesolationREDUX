/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

_found = false;
if(toLower(["Enabled","SUR"] call BASE_fnc_getCfgValue) == "true") then {
	if(vehicle player == player && alive player) then {
		if(animationState player == "amovpercmstpssurwnondnon") then {
			player switchMove "AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon";
		} else {
			player playAction "Surrender";
		};
		_found = true;
	};
};
_found;