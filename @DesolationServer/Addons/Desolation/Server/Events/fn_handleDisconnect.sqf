/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 - 2018 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

params["_unit","_unitID","_unitUID","_unitName"];

_return = false;
if(alive _unit) then {
	//--- prevent on disconnect killed
	_unit allowDamage false;
	_unit hideObjectGlobal true;


    if !(isNil {_unit getVariable "DS_var_inCombat"}) then {
        diag_log format ["Desolation> Player %1 combat logged!", _unitName];
		
		[_unit] spawn {
			params["_unit"];
			_netId = netId _unit;
			
			_unitDir = getDir (objectFromNetId _netId);
			_unitPos = getposATL (objectFromNetId _netId);
			_unitLoadout = getunitloadout (objectFromNetId _netId);
		
			_group = createGroup Civilian;
			_ai = _group createUnit ["C_man_1",_unitPos,[],0,"FORM"];
			
			removeFromRemainsCollector [_ai];
			
			_ai setDir _unitDir;
			_ai setBehaviour "CARELESS";
			_ai disableAI "AUTOTARGET";
			_ai disableAI "MOVE";
			_ai setUnitPos "UP";
			_ai setSpeaker "NoVoice";
			
			// set ai gear
			removeGoggles _ai;
			removeAllWeapons _ai;
			removeVest _ai;
			removeUniform _ai;
			removeHeadgear _ai;
			removeBackpack _ai;
			removeAllAssignedItems _ai;
			removeallitems _ai;
        
			_ai setUnitLoadout _unitLoadout;
        
			[_ai,"ApanPknlMstpSnonWnonDnon_G01"] remoteExecCall ["switchMove",0];

			uiSleep 30;
			if (alive _ai) then {
				deletegroup _group;
				deleteVehicle _ai;

				_unit setVariable ["DCed",true];
				[_unit,false] spawn DS_fnc_requestSave;

				_return = true;
			} else {
				[_unit,objNull] spawn DB_fnc_KillPlayer;
			};
		};
	} else {
		diag_log ("Desolation> Saving Disconnected Player (" + _unitName + ")");

		_unit setVariable ["DCed",true];
		[_unit,false] spawn DS_fnc_requestSave;

		_return = true; //keep the body in game while saving happens
	};
};
_return;