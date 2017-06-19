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
params["_data","_client"];
private["_unit","_anim","_dir","_x","_y","_z","_class","_hitpoints","_nonpersvars","_persvars","_textures","_invuniform","_invvest","_invbackpack","_uniform","_vest","_backpack","_headgear","_goggles","_primary","_secondary","_handgun","_tools","_currentWeapon","_loadout","_name","_damage"];

_uid = getPlayerUID _client;

_anim = _data deleteAt 0;
_dir = _data deleteAt 0;
_data deleteAt 0;
_x = _data deleteAt 0;
_y = _data deleteAt 0;
_z = _data deleteAt 0;
_class = _data deleteAt 0;
_hitpoints = _data deleteAt 0;

_nonpersvars = _data deleteAt 0;
_persvars = _data deleteAt 0;

_textures = _data deleteAt 0;
_invuniform = _data deleteAt 0;
_invvest = _data deleteAt 0;
_invbackpack = _data deleteAt 0;
_uniform = _data deleteAt 0;
_vest = _data deleteAt 0;
_backpack = _data deleteAt 0;
_headgear = _data deleteAt 0;
_goggles = _data deleteAt 0;
_primary = _data deleteAt 0;
_secondary = _data deleteAt 0;
_handgun = _data deleteAt 0;
_tools = _data deleteAt 0;
_currentWeapon = _data deleteAt 0;


_unit = (createGroup CIVILIAN) createUnit [_class, [_x,_y,_z], [],0, "NONE"];
_unit allowDamage false;
_unit hideObjectGlobal true;

{
	_unit setVariable [_x select 0,_x select 1,true];
	diag_log ("SETTING VARIABLE: " + str(_x select 0) + " VALUE: " + str(_x select 1));
} forEach _nonpersvars;
{
	_unit setVariable [_x select 0,_x select 1,true];
	diag_log ("SETTING VARIABLE: " + str(_x select 0) + " VALUE: " + str(_x select 1));
} forEach _persvars;


_unit setVariable ["pUUID",_client getVariable "pUUID"];
_unit setVariable ["cUUID",_client getVariable "cUUID"];

_unit setDir _dir;
_unit setPosATL [_x,_y,_z]; 

_loadout = [
	_primary,
	_secondary,
	_handgun,
	if(_uniform == "") then {[]} else {[_uniform,_invuniform]}, 
	if(_vest == "") then {[]} else {[_vest,_invvest]}, 
	if(_backpack == "") then {[]} else {[_backpack,_invbackpack]},
	_headgear,
	_goggles,
	_tools select 0,
	_tools select 1
];

[_unit,_anim] remoteExecCall ["switchMove",0];

{
	_name = _x;
	_damage = (_hitpoints select 2) select _forEachIndex;
	_unit setHitPointDamage [_name,_damage];
} forEach (_hitpoints select 0);

_unit addMPEventHandler ["MPKilled", DS_fnc_onPlayerKilled];
[_unit,_loadout,[]] call DS_fnc_setupLoadout;

{
	_unit setObjectTextureGlobal [_forEachIndex,_x];
} forEach _textures;

_unit hideObjectGlobal false;
_unit allowDamage true;

// Temp workaround for shotguns until config is fixed
_unit addEventHandler ["Fired",{
    params["_unit","_weapon","_muzzle","_mod","_ammo","_magazine","_projectile"];
    
    if(!isNull _projectile) then {
        if(_ammo == "12Guage_Buck" && _weapon == "dsr_sgun_m500") then {
            _velocity = velocity _projectile;
            
			_magnatude = vectorMagnitude _velocity;
			_velocityNormal = vectorNormalized  _velocity;
			
		
			_dir = asin(_velocityNormal select 0);
			if(_dir < 0) then {
				_dir = 360 + _dir;
			};	
			
			
            for "_i" from 1 to 9 do {
				_bDir = _dir + (random(5)*(if(random(1) < 0.5) then {-1} else {1}));
			
                _dX = sin(_bDir);
                _dY = cos(_bDir);
                _dZ = (_velocityNormal select 2) + (random(0.0871557*2)-0.0871557);
                
                
				_bVel = (vectorNormalized [_dX,_dY,_dZ]) vectorMultiply _magnatude;
				
                _bullet = "12Guage_Buck" createVehicle [0,0,1000];
                _bullet setShotParents [vehicle _unit,_unit];
                _bullet setVelocity _bVel;
                _bullet setposatl getposatl _projectile;
                
                
            };
            
            
        };
    };
}];


[_unit,_goggles] remoteExecCall ["DS_fnc_finishSpawn",_client];

waitUntil{getPlayerUID _unit == _uid && (tolower(goggles _unit) == toLower(_goggles))};
deleteVehicle _client;