params["_locationpos","_roamDist","_group"];


_waypoint = [];
for "_i" from 1 to 4 do {
	_wPos = [0,0,0];
	while{true} do {
		_wPos = _locationpos vectorAdd [random(_roamDist*2)-_roamDist,random(_roamDist*2)-_roamDist,0];
		if(!surfaceIsWater _wPos) exitWith {};
	};
	_waypoint = _group addWaypoint [_wPos,_i];
	_waypoint setWaypointBehaviour "CARELESS";
	_waypoint setWaypointSpeed "LIMITED";
	_waypoint setWaypointType "MOVE";
	_waypoint setWaypointCompletionRadius 10;
};
_waypoint setWaypointType "CYCLE"; 
