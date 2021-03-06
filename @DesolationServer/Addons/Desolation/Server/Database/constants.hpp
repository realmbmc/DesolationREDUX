/* constants.hpp
 *
 * Copyright 2016-2018 Desolation Redux
 *
 * Author: Legodev <legodevgit@mailbox.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 */

#ifndef SOURCE_CONSTANTS_HPP_
#define SOURCE_CONSTANTS_HPP_

#define DLLVERSIONSTRING "[1,0,1,2]"
#define CONFIG_FILE_NAME "libredex.cfg"

/*
 * Magic Numbers
 */
#define MAXCHARS_FOR_PROTOCOL_OVERHEAD 128
#define STATIC_MULTIPART_MESSAGE_PROTOCOL_OVERHEAD 49
#define DEFAULT_THREAD_COUNT boost::thread::hardware_concurrency()
#define QUIET_MAGIC 4
#define ASYNC_MAGIC 0
#define SYNC_MAGIC 1

/*
 * Magic Strings for the Arma 3 Call Extension API
 */
// Libary Datatypes
#define PROTOCOL_IDENTIFIER_NAME "msguuid"
#define PROTOCOL_IDENTIFIER_DATATYPE std::string
#define PROTOCOL_IDENTIFIER_GENERATOR orderedUUID()

// Libary Functions
#define PROTOCOL_LIBARY_FUNCTION_TERMINATE_ALL "termall"
#define PROTOCOL_LIBARY_FUNCTION_RECEIVE_MESSAGE "rcvmsg"
#define PROTOCOL_LIBARY_FUNCTION_CHECK_MESSAGE_STATE "chkmsg"
#define PROTOCOL_LIBARY_FUNCTION_CHECK_VERSION "version"

// File IO Call Functions
#define PROTOCOL_IOCALL_FUNCTION_READ_FILE "readFile"
#define PROTOCOL_IOCALL_FUNCTION_WRITE_FILE "writeFile"
#define PROTOCOL_IOCALL_FUNCTION_APPEND_FILE "appendFile"
#define PROTOCOL_IOCALL_FUNCTION_PLUGINSYSTEM_GETINITORDER "GetInitOrder"
#define PROTOCOL_IOCALL_FUNCTION_PLUGINSYSTEM_GETCFGFILE "GetCfgFile"

// DateTime Call Functions
#define PROTOCOL_DTCALL_FUNCTION_GET_DATE_TIME_Array "getDateTimeArray"
#define PROTOCOL_DTCALL_FUNCTION_GET_EPOCH_TIME "getEpochTime"
#define PROTOCOL_DTCALL_FUNCTION_GET_UNIX_TIME "getUnixTime"

// Random Call Functions
#define PROTOCOL_RANDOM_FUNCTION_ADD_DISCRETE_LIST "addDiscreteItemList"
#define PROTOCOL_RANDOM_FUNCTION_GET_DISCRETE_LIST "getDiscreteItemList"
#define PROTOCOL_RANDOM_FUNCTION_GET_RANDOMNUMBER_LIST "getRandomNumberList"

// Database Call Functions
#define PROTOCOL_DBCALL_FUNCTION_EXECUTE_INIT_DB "initdb"
#define PROTOCOL_DBCALL_FUNCTION_EXECUTE_TERMINATE_DB "termdb"

#define PROTOCOL_DBCALL_FUNCTION_RETURN_UUID "getUUID"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_ECHO_STRING "echo"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_DB_VERSION "dbVersion"
#define PROTOCOL_DBCALL_FUNCTION_DEBUG_CALL "dbgCall"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_ASYNC_MSG "rcvasmsg"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_ASYNC_SATE "chkasmsg"

#define PROTOCOL_DBCALL_FUNCTION_LOAD_PLAYER "loadPlayer"
#define PROTOCOL_DBCALL_FUNCTION_AV_CHARS "loadAvChars"
#define PROTOCOL_DBCALL_FUNCTION_LINK_CHARS "linkChars"
#define PROTOCOL_DBCALL_FUNCTION_LOAD_CHAR "loadChar"
#define PROTOCOL_DBCALL_FUNCTION_CREATE_CHAR "createChar"
#define PROTOCOL_DBCALL_FUNCTION_UPDATE_CHAR "updateChar"
#define PROTOCOL_DBCALL_FUNCTION_LOCATIONUPDATE_CHAR "locupdateChar"
#define PROTOCOL_DBCALL_FUNCTION_DECLARE_CHAR_DEATH "killChar"

#define PROTOCOL_DBCALL_FUNCTION_LOAD_OBJECT "loadObject"
#define PROTOCOL_DBCALL_FUNCTION_CREATE_OBJECT "createObject"
#define PROTOCOL_DBCALL_FUNCTION_QUIET_CREATE_OBJECT "qcreateObject"
#define PROTOCOL_DBCALL_FUNCTION_UPDATE_OBJECT "updateObject"
#define PROTOCOL_DBCALL_FUNCTION_DECLARE_OBJECT_DEATH "killObject"
#define PROTOCOL_DBCALL_FUNCTION_DUMP_OBJECTS "dumpObjects"

// Database Call Arguments
#define PROTOCOL_DBCALL_ARGUMENT_ACCESSCODE "accesscode"
#define PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE "animationstate"
#define PROTOCOL_DBCALL_ARGUMENT_ATTACKER "attackeruuid"
#define PROTOCOL_DBCALL_ARGUMENT_BACKPACK "backpack"
#define PROTOCOL_DBCALL_ARGUMENT_RESERVEDTWO "reservedtwo"
#define PROTOCOL_DBCALL_ARGUMENT_CHARUUID "charuuid"
#define PROTOCOL_DBCALL_ARGUMENT_CLASSNAME "classname"
#define PROTOCOL_DBCALL_ARGUMENT_CURRENTWEAPON "currentweapon"
#define PROTOCOL_DBCALL_ARGUMENT_DAMAGE "damage"
#define PROTOCOL_DBCALL_ARGUMENT_DIRECTION "direction"
#define PROTOCOL_DBCALL_ARGUMENT_DISTANCE "distance"
#define PROTOCOL_DBCALL_ARGUMENT_FUELCARGO "fuelcargo"
#define PROTOCOL_DBCALL_ARGUMENT_FUEL "fuel"
#define PROTOCOL_DBCALL_ARGUMENT_GOOGLES "googles"
#define PROTOCOL_DBCALL_ARGUMENT_HANDGUN "handgun"
#define PROTOCOL_DBCALL_ARGUMENT_HEADGEAR "headgear"
#define PROTOCOL_DBCALL_ARGUMENT_HITPOINTS "hitpoints"
#define PROTOCOL_DBCALL_ARGUMENT_INVENTORYBACKPACK "inventorybackpack"
#define PROTOCOL_DBCALL_ARGUMENT_GEAR "gear"
#define PROTOCOL_DBCALL_ARGUMENT_INVENTORYVEST "inventoryvest"
#define PROTOCOL_DBCALL_ARGUMENT_ITEMS "items"
#define PROTOCOL_DBCALL_ARGUMENT_LOCKED "locked"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONADVANCED "positionadvanced"
#define PROTOCOL_DBCALL_ARGUMENT_MAGAZINESTURRET "magazinesturret"
#define PROTOCOL_DBCALL_ARGUMENT_NICKNAME "nickname"
#define PROTOCOL_DBCALL_ARGUMENT_OBJECTUUID "objectuuid"
#define PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABLES "persistentvariables"
#define PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABUUID "persistentvariablesuuid"
#define PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID "playeruuid"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE "positiontype"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONX "positionx"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONY "positiony"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONZ "positionz"
#define PROTOCOL_DBCALL_ARGUMENT_PRIMARYWEAPON "primaryweapon"
#define PROTOCOL_DBCALL_ARGUMENT_PRIORITY "priority"
#define PROTOCOL_DBCALL_ARGUMENT_REPAIRCARGO "repaircargo"
#define PROTOCOL_DBCALL_ARGUMENT_SECONDARYWEAPON "secondaryweapon"
#define PROTOCOL_DBCALL_ARGUMENT_STEAMID "steamid"
#define PROTOCOL_DBCALL_ARGUMENT_TEXTURES "textures"
#define PROTOCOL_DBCALL_ARGUMENT_TOOLS "tools"
#define PROTOCOL_DBCALL_ARGUMENT_UNIFORM "uniform"
#define PROTOCOL_DBCALL_ARGUMENT_VARIABLES "variables"
#define PROTOCOL_DBCALL_ARGUMENT_VARIABUUID "variabuuid"
#define PROTOCOL_DBCALL_ARGUMENT_CHARSHAREUUID "charactershareablesuuid"
#define PROTOCOL_DBCALL_ARGUMENT_VEST "vest"
#define PROTOCOL_DBCALL_ARGUMENT_TYPE "type"
#define PROTOCOL_DBCALL_ARGUMENT_OBJECTTYPE "type"
#define PROTOCOL_DBCALL_ARGUMENT_RESERVEDONE "reservedone"
#define PROTOCOL_DBCALL_ARGUMENT_WEAPON "weapon"
#define PROTOCOL_DBCALL_ARGUMENT_WORLDUUID "worlduuid"

// Message Types
#define PROTOCOL_MESSAGE_TYPE_ERROR "ERROR"
#define PROTOCOL_MESSAGE_TYPE_MESSAGE "MSG"
#define PROTOCOL_MESSAGE_TYPE_MULTIPART "MPMSG"
#define PROTOCOL_MESSAGE_TYPE_NOT_READY "RSN"
#define PROTOCOL_MESSAGE_TYPE_ASYNC "ASYNC"
#define PROTOCOL_MESSAGE_TYPE_QUIET "QUIET"

// Complete Messages
#define PROTOCOL_MESSAGE_EXISTING "MESSAGE DOES EXIST"
#define PROTOCOL_MESSAGE_NOT_EXISTING "MESSAGE DOES NOT EXIST"
#define PROTOCOL_MESSAGE_EMPTY "EMPTY MESSAGE DOES EXIST"
#define PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG "DONE GETTING CONTENT"

#endif /* SOURCE_CONSTANTS_HPP_ */
