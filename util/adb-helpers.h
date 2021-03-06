// -*- mode: C; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: nil -*-
// vim: set softtabstop=4 shiftwidth=4 tabstop=4 expandtab:

/*************************************************************************
 * Copyright 2009-2012 Eucalyptus Systems, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 * Please contact Eucalyptus Systems, Inc., 6755 Hollister Ave., Goleta
 * CA 93117, USA or visit http://www.eucalyptus.com/licenses/ if you need
 * additional information or have any questions.
 *
 * This file may incorporate work covered under the following copyright
 * and permission notice:
 *
 *   Software License Agreement (BSD License)
 *
 *   Copyright (c) 2008, Regents of the University of California
 *   All rights reserved.
 *
 *   Redistribution and use of this software in source and binary forms,
 *   with or without modification, are permitted provided that the
 *   following conditions are met:
 *
 *     Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer
 *     in the documentation and/or other materials provided with the
 *     distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *   COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE. USERS OF THIS SOFTWARE ACKNOWLEDGE
 *   THE POSSIBLE PRESENCE OF OTHER OPEN SOURCE LICENSED MATERIAL,
 *   COPYRIGHTED MATERIAL OR PATENTED MATERIAL IN THIS SOFTWARE,
 *   AND IF ANY SUCH MATERIAL IS DISCOVERED THE PARTY DISCOVERING
 *   IT MAY INFORM DR. RICH WOLSKI AT THE UNIVERSITY OF CALIFORNIA,
 *   SANTA BARBARA WHO WILL THEN ASCERTAIN THE MOST APPROPRIATE REMEDY,
 *   WHICH IN THE REGENTS' DISCRETION MAY INCLUDE, WITHOUT LIMITATION,
 *   REPLACEMENT OF THE CODE SO IDENTIFIED, LICENSING OF THE CODE SO
 *   IDENTIFIED, OR WITHDRAWAL OF THE CODE CAPABILITY TO THE EXTENT
 *   NEEDED TO COMPLY WITH ANY SUCH LICENSES OR RIGHTS.
 ************************************************************************/

//!
//! @file util/adb-helpers.h
//! Need to provide description
//!

#ifndef _INCLUDE_ADB_HELPERS_H_
#define _INCLUDE_ADB_HELPERS_H_

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                                  INCLUDES                                  |
 |                                                                            |
\*----------------------------------------------------------------------------*/

#include "sensor.h"
#include "euca_string.h"

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                                  DEFINES                                   |
 |                                                                            |
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                                  TYPEDEFS                                  |
 |                                                                            |
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                                ENUMERATIONS                                |
 |                                                                            |
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                                 STRUCTURES                                 |
 |                                                                            |
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                             EXPORTED VARIABLES                             |
 |                                                                            |
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                             EXPORTED PROTOTYPES                            |
 |                                                                            |
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                           STATIC INLINE PROTOTYPES                         |
 |                                                                            |
\*----------------------------------------------------------------------------*/

// Date / Time convertion helpers
static inline time_t datetime_to_unix(axutil_date_time_t * dt, const axutil_env_t * env);
static inline long long datetime_to_unixms(axutil_date_time_t * dt, const axutil_env_t * env);
static inline axutil_date_time_t *unixms_to_datetime(const axutil_env_t * env, long long timestampMs) __attribute__ ((__warn_unused_result__));

// ADB to and to ADB convertion helpers
static inline void copy_vm_type_from_adb(virtualMachine * params, adb_virtualMachineType_t * vm_type, const axutil_env_t * env);
static inline adb_virtualMachineType_t *copy_vm_type_to_adb(const axutil_env_t * env, virtualMachine * params)
    __attribute__ ((__warn_unused_result__));
static inline adb_serviceInfoType_t *copy_service_info_type_to_adb(const axutil_env_t * env, serviceInfoType * input)
    __attribute__ ((__warn_unused_result__));
static inline void copy_service_info_type_from_adb(serviceInfoType * input, adb_serviceInfoType_t * sit, const axutil_env_t * env);
static inline int copy_sensor_value_from_adb(sensorValue * sv, adb_metricDimensionsValuesType_t * value, axutil_env_t * env);
static inline int copy_sensor_dimension_from_adb(sensorDimension * sd, adb_metricDimensionsType_t * dimension, axutil_env_t * env);
static inline int copy_sensor_counter_from_adb(sensorCounter * sc, adb_metricCounterType_t * counter, axutil_env_t * env);
static inline int copy_sensor_metric_from_adb(sensorMetric * sm, adb_metricsResourceType_t * metric, axutil_env_t * env);
static inline sensorResource *copy_sensor_resource_from_adb(adb_sensorsResourceType_t * resource, axutil_env_t * env)
    __attribute__ ((__warn_unused_result__));
static inline adb_sensorsResourceType_t *copy_sensor_resource_to_adb(const axutil_env_t * env, const sensorResource * sr, int history_size)
    __attribute__ ((__warn_unused_result__));

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                                   MACROS                                   |
 |                                                                            |
\*----------------------------------------------------------------------------*/

//! Macro to unmarshal a message from the server
#define EUCA_MESSAGE_UNMARSHAL(_thefunc, _theadb, _themeta)                                                             \
{                                                                                                                       \
	int i = 0;                                                                                                          \
	int j = 0;                                                                                                          \
	adb_serviceInfoType_t *sit = NULL;                                                                                  \
	bzero((_themeta), sizeof(ncMetadata));                                                                              \
	(_themeta)->correlationId = adb_##_thefunc##_get_correlationId((_theadb), env);                                     \
	(_themeta)->userId = adb_##_thefunc##_get_userId((_theadb), env);                                                   \
	(_themeta)->epoch = adb_##_thefunc##_get_epoch((_theadb), env);                                                     \
	(_themeta)->servicesLen = adb_##_thefunc##_sizeof_services((_theadb), env);                                         \
	for (i = 0; ((i < (_themeta)->servicesLen) && (i < 16)); i++) {                                                     \
		sit = adb_##_thefunc##_get_services_at((_theadb), env, i);                                                      \
		snprintf((_themeta)->services[i].type, 32, "%s", adb_serviceInfoType_get_type(sit, env));                       \
		snprintf((_themeta)->services[i].name, 32, "%s", adb_serviceInfoType_get_name(sit, env));                       \
		snprintf((_themeta)->services[i].partition, 32, "%s", adb_serviceInfoType_get_partition(sit, env));             \
		(_themeta)->services[i].urisLen = adb_serviceInfoType_sizeof_uris(sit, env);                                    \
		for (j = 0; ((j < (_themeta)->services[i].urisLen) && (j < 8)); j++) {                                          \
			snprintf((_themeta)->services[i].uris[j], 512, "%s", adb_serviceInfoType_get_uris_at(sit, env, j));         \
		}                                                                                                               \
	}                                                                                                                   \
	(_themeta)->disabledServicesLen = adb_##_thefunc##_sizeof_disabledServices((_theadb), env);                         \
	for (i = 0; ((i < (_themeta)->disabledServicesLen) && (i < 16)); i++) {                                             \
		sit = adb_##_thefunc##_get_disabledServices_at((_theadb), env, i);                                              \
		snprintf((_themeta)->disabledServices[i].type, 32, "%s", adb_serviceInfoType_get_type(sit, env));               \
		snprintf((_themeta)->disabledServices[i].name, 32, "%s", adb_serviceInfoType_get_name(sit, env));               \
		snprintf((_themeta)->disabledServices[i].partition, 32, "%s", adb_serviceInfoType_get_partition(sit, env));     \
		(_themeta)->disabledServices[i].urisLen = adb_serviceInfoType_sizeof_uris(sit, env);                            \
		for (j = 0; ((j < (_themeta)->disabledServices[i].urisLen) && (j < 8)); j++) {                                  \
			snprintf((_themeta)->disabledServices[i].uris[j], 512, "%s", adb_serviceInfoType_get_uris_at(sit, env, j)); \
		}                                                                                                               \
	}                                                                                                                   \
	(_themeta)->notreadyServicesLen = adb_##_thefunc##_sizeof_notreadyServices((_theadb), env);                         \
	for (i = 0; ((i < (_themeta)->notreadyServicesLen) && (i < 16)); i++) {                                             \
		sit = adb_##_thefunc##_get_notreadyServices_at((_theadb), env, i);                                              \
		snprintf((_themeta)->notreadyServices[i].type, 32, "%s", adb_serviceInfoType_get_type(sit, env));               \
		snprintf((_themeta)->notreadyServices[i].name, 32, "%s", adb_serviceInfoType_get_name(sit, env));               \
		snprintf((_themeta)->notreadyServices[i].partition, 32, "%s", adb_serviceInfoType_get_partition(sit, env));     \
		(_themeta)->notreadyServices[i].urisLen = adb_serviceInfoType_sizeof_uris(sit, env);                            \
		for (j = 0; ((j < (_themeta)->notreadyServices[i].urisLen) && (j < 8)); j++) {                                  \
			snprintf((_themeta)->notreadyServices[i].uris[j], 512, "%s", adb_serviceInfoType_get_uris_at(sit, env, j)); \
		}                                                                                                               \
	}                                                                                                                   \
}

//! Macro to marshal a message to the client
#define EUCA_MESSAGE_MARSHAL(_thefunc, _theadb, _themeta)                               \
{                                                                                       \
	int i = 0;                                                                          \
	int j = 0;                                                                          \
	adb_serviceInfoType_t *sit = NULL;                                                  \
	adb_##_thefunc##_set_correlationId((_theadb), env, (_themeta)->correlationId);      \
	adb_##_thefunc##_set_userId((_theadb), env, (_themeta)->userId);                    \
	adb_##_thefunc##_set_epoch((_theadb), env,  (_themeta)->epoch);                     \
	for (i = 0; ((i < (_themeta)->servicesLen) && (i < 16)); i++) {                     \
		sit = adb_serviceInfoType_create(env);                                          \
		adb_serviceInfoType_set_type(sit, env, (_themeta)->services[i].type);           \
		adb_serviceInfoType_set_name(sit, env, (_themeta)->services[i].name);           \
		adb_serviceInfoType_set_partition(sit, env, (_themeta)->services[i].partition); \
		for (j = 0; ((j < (_themeta)->services[i].urisLen) && (j < 8)); j++) {	        \
			adb_serviceInfoType_add_uris(sit, env, (_themeta)->services[i].uris[j]);    \
		}                                                                               \
		adb_##_thefunc##_add_services((_theadb), env, sit);                             \
	}                                                                                   \
}

/*----------------------------------------------------------------------------*\
 |                                                                            |
 |                          STATIC INLINE IMPLEMENTATION                      |
 |                                                                            |
\*----------------------------------------------------------------------------*/

//!
//! Helper to convert the AXIS date/time structure to unix time_t style.
//!
//! @param[in] dt a pointer to the AXIS date/time structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
//! @return the converted value.
//!
static inline time_t datetime_to_unix(axutil_date_time_t * dt, const axutil_env_t * env)
{
    time_t tsu = ((time_t) 0);
    time_t ts = ((time_t) 0);
    time_t tsdelta = ((time_t) 0);
    time_t tsdelta_min = ((time_t) 0);
    struct tm *tmu = NULL;
    struct tm t = { 0 };

    if ((dt == NULL) || (env == NULL)) {
        return ((time_t) 0);
    }

    ts = time(NULL);
    tmu = gmtime(&ts);
    tsu = mktime(tmu);
    tsdelta = (tsu - ts) / 3600;
    tsdelta_min = ((tsu - ts) - (tsdelta * 3600)) / 60;

    t.tm_sec = axutil_date_time_get_second(dt, env);
    t.tm_min = axutil_date_time_get_minute(dt, env) - tsdelta_min;
    t.tm_hour = axutil_date_time_get_hour(dt, env) - tsdelta;
    t.tm_mday = axutil_date_time_get_date(dt, env);
    t.tm_mon = axutil_date_time_get_month(dt, env) - 1;
    t.tm_year = axutil_date_time_get_year(dt, env) - 1900;
    return (mktime(&t));
}

//!
//! Helper to convert AXIS date/time to unix milliseconds
//!
//! @param[in] dt a pointer to the AXIS date/time structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
//! @return the converted value
//!
//! @todo test if this millisecond-precision conversion routine works
//!
static inline long long datetime_to_unixms(axutil_date_time_t * dt, const axutil_env_t * env)
{
    if ((dt == NULL) || (env == NULL))
        return (0L);
    return ((datetime_to_unix(dt, env) * 1000) + ((long long)axutil_date_time_get_msec(dt, env)));
}

//!
//! Helper to convert unix milliseconds to AXIS date/time
//!
//! @param[in] env pointer to the AXIS2 environment structure
//! @param[in] timestampMs the timestamp value to convert
//!
//! @return a pointer to the converted value or NULL if any error occured.
//!
//! @todo test if this millisecond-precision conversion routine works
//!
static inline axutil_date_time_t *unixms_to_datetime(const axutil_env_t * env, long long timestampMs)
{
    int msec = ((int)(timestampMs % 1000));
    time_t sec = ((time_t) (timestampMs / 1000));
    axutil_date_time_t *dt = NULL;
    struct tm t = { 0 };

    if (env != NULL) {
        tzset();
        sec += timezone;        // seconds west of UTC to account for TZ
        localtime_r(&sec, &t);
        dt = axutil_date_time_create(env);
        axutil_date_time_set_date_time(dt, env, (t.tm_year + 1900), (t.tm_mon + 1), t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, msec);
        return (dt);
    }

    return (NULL);
}

//!
//! Helper to conver the ADB information into our virtual machine structure
//!
//! @param[in] params a pointer to the virtual machine data
//! @param[in] vm_type a pointer to the ADB virtual machine info
//! @param[in] env pointer to the AXIS2 environment structure
//!
static inline void copy_vm_type_from_adb(virtualMachine * params, adb_virtualMachineType_t * vm_type, const axutil_env_t * env)
{
    int i = 0;
    adb_virtualBootRecordType_t *vbr_type = NULL;

    if ((vm_type != NULL) && (params != NULL) && (env != NULL)) {
        bzero(params, sizeof(virtualMachine));
        params->mem = adb_virtualMachineType_get_memory(vm_type, env);
        params->cores = adb_virtualMachineType_get_cores(vm_type, env);
        params->disk = adb_virtualMachineType_get_disk(vm_type, env);
        euca_strncpy(params->name, adb_virtualMachineType_get_name(vm_type, env), sizeof(params->name));
        params->virtualBootRecordLen = adb_virtualMachineType_sizeof_virtualBootRecord(vm_type, env);
        for (i = 0; ((i < EUCA_MAX_VBRS) && (i < params->virtualBootRecordLen)); i++) {
            if ((vbr_type = adb_virtualMachineType_get_virtualBootRecord_at(vm_type, env, i)) != NULL) {
                euca_strncpy(params->virtualBootRecord[i].resourceLocation, adb_virtualBootRecordType_get_resourceLocation(vbr_type, env),
                             CHAR_BUFFER_SIZE);
                logprintfl(EUCATRACE, "resource location: %s\n", params->virtualBootRecord[i].resourceLocation);
                euca_strncpy(params->virtualBootRecord[i].guestDeviceName, adb_virtualBootRecordType_get_guestDeviceName(vbr_type, env),
                             SMALL_CHAR_BUFFER_SIZE);
                logprintfl(EUCATRACE, "   guest dev name: %s\n", params->virtualBootRecord[i].guestDeviceName);
                params->virtualBootRecord[i].size = adb_virtualBootRecordType_get_size(vbr_type, env);
                logprintfl(EUCATRACE, "             size: %lld\n", params->virtualBootRecord[i].size);
                euca_strncpy(params->virtualBootRecord[i].formatName, adb_virtualBootRecordType_get_format(vbr_type, env), SMALL_CHAR_BUFFER_SIZE);
                logprintfl(EUCATRACE, "           format: %s\n", params->virtualBootRecord[i].formatName);
                euca_strncpy(params->virtualBootRecord[i].id, adb_virtualBootRecordType_get_id(vbr_type, env), SMALL_CHAR_BUFFER_SIZE);
                logprintfl(EUCATRACE, "               id: %s\n", params->virtualBootRecord[i].id);
                euca_strncpy(params->virtualBootRecord[i].typeName, adb_virtualBootRecordType_get_type(vbr_type, env), SMALL_CHAR_BUFFER_SIZE);
                logprintfl(EUCATRACE, "             type: %s\n", params->virtualBootRecord[i].typeName);
            }
        }
    }
}

//!
//! Helper to convert a virtual machine structure into an ADB structure
//!
//! @param[in] env pointer to the AXIS2 environment structure
//! @param[in] params a pointer to the virtual machine structure to convert
//!
//! @return a pointer to the converted value or NULL if any error occured.
//!
static inline adb_virtualMachineType_t *copy_vm_type_to_adb(const axutil_env_t * env, virtualMachine * params)
{
    int i = 0;
    virtualBootRecord *vbr = NULL;
    adb_virtualBootRecordType_t *vbr_type = NULL;
    adb_virtualMachineType_t *vm_type = NULL;

    if ((env != NULL) && (params != NULL)) {
        if ((vm_type = adb_virtualMachineType_create(env)) != NULL) {
            adb_virtualMachineType_set_memory(vm_type, env, params->mem);
            adb_virtualMachineType_set_cores(vm_type, env, params->cores);
            adb_virtualMachineType_set_disk(vm_type, env, params->disk);
            adb_virtualMachineType_set_name(vm_type, env, params->name);

            for (i = 0; ((i < EUCA_MAX_VBRS) && (i < params->virtualBootRecordLen)); i++) {
                vbr = &params->virtualBootRecord[i];
                if (strlen(vbr->resourceLocation) > 0) {
                    if ((vbr_type = adb_virtualBootRecordType_create(env)) != NULL) {
                        adb_virtualBootRecordType_set_resourceLocation(vbr_type, env, vbr->resourceLocation);
                        adb_virtualBootRecordType_set_guestDeviceName(vbr_type, env, vbr->guestDeviceName);
                        adb_virtualBootRecordType_set_size(vbr_type, env, vbr->size);
                        adb_virtualBootRecordType_set_format(vbr_type, env, vbr->formatName);
                        adb_virtualBootRecordType_set_id(vbr_type, env, vbr->id);
                        adb_virtualBootRecordType_set_type(vbr_type, env, vbr->typeName);
                        adb_virtualMachineType_add_virtualBootRecord(vm_type, env, vbr_type);
                    }
                }
            }

            return (vm_type);
        }
    }

    return (NULL);
}

//!
//! Helper to convert a service info structure to its ADB format
//!
//! @param[in] env pointer to the AXIS2 environment structure
//! @param[in] input a pointer to the service info structure to convert
//!
//! @return a pointer to the converted value or NULL if any error occured.
//!
static inline adb_serviceInfoType_t *copy_service_info_type_to_adb(const axutil_env_t * env, serviceInfoType * input)
{
    int i = 0;
    adb_serviceInfoType_t *sit = adb_serviceInfoType_create(env);

    if ((env != NULL) && (input != NULL)) {
        if ((sit = adb_serviceInfoType_create(env)) != NULL) {
            adb_serviceInfoType_set_type(sit, env, input->type);
            adb_serviceInfoType_set_name(sit, env, input->name);
            adb_serviceInfoType_set_partition(sit, env, input->partition);
            for (i = 0; i < input->urisLen; i++) {
                adb_serviceInfoType_add_uris(sit, env, input->uris[i]);
            }

            return (sit);
        }
    }

    return (NULL);
}

//!
//! Helper to convert a service info ADB structure to our service info structure.
//!
//! @param[in] input a pointer to the service info structure to update
//! @param[in] sit a pointer to the ADS service info structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
static inline void copy_service_info_type_from_adb(serviceInfoType * input, adb_serviceInfoType_t * sit, const axutil_env_t * env)
{
    int i = 0;

    if ((input != NULL) && (sit != NULL) && (env != NULL)) {
        snprintf(input->type, 32, "%s", adb_serviceInfoType_get_type(sit, env));
        snprintf(input->name, 32, "%s", adb_serviceInfoType_get_name(sit, env));
        snprintf(input->partition, 32, "%s", adb_serviceInfoType_get_partition(sit, env));
        input->urisLen = adb_serviceInfoType_sizeof_uris(sit, env);
        for (i = 0; ((i < input->urisLen) && (i < 8)); i++) {
            snprintf(input->uris[i], 512, "%s", adb_serviceInfoType_get_uris_at(sit, env, i));
        }
    }
}

//!
//! Helper to convert an ADB metric dimension value to our sensor value structure.
//!
//! @param[in] sv a pointer to the sensor value to update
//! @param[in] value a pointer to the ADB metric dimension value structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
//! @return EUCA_OK on success or EUCA_ERROR on failure.
//!
static inline int copy_sensor_value_from_adb(sensorValue * sv, adb_metricDimensionsValuesType_t * value, axutil_env_t * env)
{
    axutil_date_time_t *dt = NULL;

    if ((sv != NULL) && (value != NULL) && (env != NULL)) {
        if ((dt = adb_metricDimensionsValuesType_get_timestamp(value, env)) != NULL) {
            sv->timestampMs = datetime_to_unixms(dt, env);
            if (adb_metricDimensionsValuesType_is_value_nil(value, env)) {
                // funky unset value to make it stand out
                sv->value = -99.99;
                sv->available = 0;
            } else {
                sv->value = (double)adb_metricDimensionsValuesType_get_value(value, env);
                sv->available = 1;
            }

            return (EUCA_OK);
        }
    }

    return (EUCA_ERROR);
}

//!
//! Helper to convert an ADB metric dimension value to our sensor dimension structure.
//!
//! @param[in] sd a pointer to the sensor dimension to update
//! @param[in] dimension a pointer to the ADB metric dimension value structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
//! @return EUCA_OK on success or proper error code. Known error code returned include: EUCA_ERROR
//!         and EUCA_OVERFLOW_ERROR.
//!
static inline int copy_sensor_dimension_from_adb(sensorDimension * sd, adb_metricDimensionsType_t * dimension, axutil_env_t * env)
{
    int i = 0;
    adb_metricDimensionsValuesType_t *value = NULL;

    if ((sd != NULL) && (dimension != NULL) && (env != NULL)) {
        sd->valuesLen = adb_metricDimensionsType_sizeof_values(dimension, env);
        if (sd->valuesLen > MAX_SENSOR_VALUES) {
            logprintfl(EUCAERROR, "overflow of 'values' array in 'sensorDimension'");
            return (EUCA_OVERFLOW_ERROR);
        }

        for (i = 0; i < sd->valuesLen; i++) {
            if ((value = adb_metricDimensionsType_get_values_at(dimension, env, i)) != NULL) {
                if (copy_sensor_value_from_adb(sd->values + i, value, env) != 0)
                    return (EUCA_ERROR);
            }
        }

        euca_strncpy(sd->dimensionName, (char *)adb_metricDimensionsType_get_dimensionName(dimension, env), sizeof(sd->dimensionName));
        return (EUCA_OK);
    }

    return (EUCA_ERROR);
}

//!
//! Helper to convert an ADB metric counter value to our sensor counter structure.
//!
//! @param[in] sc a pointer to the sensor counter to update
//! @param[in] counter a pointer to the ADB metric counter value structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
//! @return EUCA_OK on success or proper error code. Known error code returned include: EUCA_ERROR
//!         and EUCA_OVERFLOW_ERROR.
//!
static inline int copy_sensor_counter_from_adb(sensorCounter * sc, adb_metricCounterType_t * counter, axutil_env_t * env)
{
    int i = 0;
    adb_metricDimensionsType_t *value = NULL;

    if ((sc != NULL) && (counter != NULL) && (env != NULL)) {
        sc->dimensionsLen = adb_metricCounterType_sizeof_dimensions(counter, env);
        if (sc->dimensionsLen > MAX_SENSOR_DIMENSIONS) {
            logprintfl(EUCAERROR, "overflow of 'dimensions' array in 'sensorCounter'");
            return (EUCA_OVERFLOW_ERROR);
        }

        for (i = 0; i < sc->dimensionsLen; i++) {
            if ((value = adb_metricCounterType_get_dimensions_at(counter, env, i)) != NULL) {
                if (copy_sensor_dimension_from_adb(sc->dimensions + i, value, env) != 0)
                    return (EUCA_ERROR);
            }
        }

        sc->collectionIntervalMs = (long long)adb_metricCounterType_get_collectionIntervalMs(counter, env);
        sc->sequenceNum = (long long)adb_metricCounterType_get_sequenceNum(counter, env);
        sc->type = sensor_str2type((char *)adb_metricCounterType_get_type(counter, env));
        return (EUCA_OK);
    }

    return (EUCA_ERROR);
}

//!
//! Helper to convert an ADB metric resource structure to our sensor metric structure.
//!
//! @param[in] sm a pointer to the sensor metric to update
//! @param[in] metric a pointer to the ADB metric resource structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
//! @return EUCA_OK on success or proper error code. Known error code returned include: EUCA_ERROR
//!         and EUCA_OVERFLOW_ERROR.
//!
static inline int copy_sensor_metric_from_adb(sensorMetric * sm, adb_metricsResourceType_t * metric, axutil_env_t * env)
{
    int i = 0;
    adb_metricCounterType_t *value = NULL;

    if ((sm != NULL) && (metric != NULL) && (env != NULL)) {
        sm->countersLen = adb_metricsResourceType_sizeof_counters(metric, env);
        if (sm->countersLen > MAX_SENSOR_COUNTERS) {
            logprintfl(EUCAERROR, "overflow of 'counters' array in 'sensorMetric'");
            return (EUCA_OVERFLOW_ERROR);
        }

        for (i = 0; i < sm->countersLen; i++) {
            if ((value = adb_metricsResourceType_get_counters_at(metric, env, i)) != NULL) {
                if (copy_sensor_counter_from_adb(sm->counters + i, value, env) != 0)
                    return (EUCA_ERROR);
            }
        }

        euca_strncpy(sm->metricName, (char *)adb_metricsResourceType_get_metricName(metric, env), sizeof(sm->metricName));
        return (EUCA_OK);
    }

    return (EUCA_ERROR);
}

//!
//! Helper to convert an ADB metric resource structure to our sensor metric structure.
//!
//! @param[in] resource a pointer to the ADB sensor resource structure to convert
//! @param[in] env pointer to the AXIS2 environment structure
//!
//! @return a pointer to the converted value or NULL if any error occured
//!
static inline sensorResource *copy_sensor_resource_from_adb(adb_sensorsResourceType_t * resource, axutil_env_t * env)
{
    int i = 0;
    sensorResource *sr = NULL;
    adb_metricsResourceType_t *value = NULL;

    if ((resource != NULL) && (env != NULL)) {
        if ((sr = EUCA_ZALLOC(1, sizeof(sensorResource))) == NULL)
            return (NULL);

        sr->metricsLen = adb_sensorsResourceType_sizeof_metrics(resource, env);
        if (sr->metricsLen > MAX_SENSOR_METRICS) {
            logprintfl(EUCAERROR, "overflow of 'metrics' array in 'sensorResource'");
            EUCA_FREE(sr);
            return (NULL);
        }

        for (i = 0; i < sr->metricsLen; i++) {
            if ((value = adb_sensorsResourceType_get_metrics_at(resource, env, i)) != NULL) {
                if (copy_sensor_metric_from_adb(sr->metrics + i, value, env) != 0) {
                    EUCA_FREE(sr);
                    return (NULL);
                }
            }
        }

        euca_strncpy(sr->resourceName, (char *)adb_sensorsResourceType_get_resourceName(resource, env), sizeof(sr->resourceName));
        euca_strncpy(sr->resourceType, (char *)adb_sensorsResourceType_get_resourceType(resource, env), sizeof(sr->resourceType));
        euca_strncpy(sr->resourceUuid, (char *)adb_sensorsResourceType_get_resourceUuid(resource, env), sizeof(sr->resourceUuid));
        return (sr);
    }

    return (NULL);
}

//!
//! Helper to convert a sensor resource structure to an ADB sensor resource structure.
//!
//! @param[in] env pointer to the AXIS2 environment structure
//! @param[in] sr a pointer to the ADB sensor resource structure to convert
//! @param[in] history_size the size of the history to copy
//!
//! @return a pointer to the converted value or NULL if any error occured
//!
static inline adb_sensorsResourceType_t *copy_sensor_resource_to_adb(const axutil_env_t * env, const sensorResource * sr, int history_size)
{
    int m = 0;
    int c = 0;
    int d = 0;
    int v = 0;
    int v_adj = 0;
    int num_values = 0;
    int batch_size = 0;
    int array_offset = 0;
    int total_num_metrics = 0;
    int total_num_counters = 0;
    int total_num_dimensions = 0;
    int total_num_values = 0;
    double val = 0.0;
    axutil_date_time_t *ts = NULL;
    adb_sensorsResourceType_t *resource = NULL;
    adb_metricsResourceType_t *metric = NULL;
    adb_metricCounterType_t *counter = NULL;
    adb_metricDimensionsType_t *dimension = NULL;
    adb_metricDimensionsValuesType_t *value = NULL;
    const sensorValue *sv = NULL;
    const sensorMetric *sm = NULL;
    const sensorCounter *sc = NULL;
    const sensorDimension *sd = NULL;

    logprintfl(EUCATRACE, "invoked\n");

    if ((sr != NULL) && (env != NULL)) {
        if ((resource = adb_sensorsResourceType_create(env)) == NULL) {
            return (NULL);
        }

        adb_sensorsResourceType_set_resourceName(resource, env, sr->resourceName);
        adb_sensorsResourceType_set_resourceType(resource, env, sr->resourceType);
        adb_sensorsResourceType_set_resourceUuid(resource, env, sr->resourceUuid);
        if (sr->metricsLen < 0 || sr->metricsLen > MAX_SENSOR_METRICS) {
            logprintfl(EUCAERROR, "inconsistency in sensor database (metricsLen=%d for %s)\n", sr->metricsLen, sr->resourceName);
            return (resource);
        }

        for (m = 0; m < sr->metricsLen; m++) {
            sm = sr->metrics + m;
            if ((metric = adb_metricsResourceType_create(env)) == NULL) {
                logprintfl(EUCAERROR, "failed to create metric resource for %s:%s\n", sr->resourceName, sm->metricName);
                return (resource);
            }

            adb_metricsResourceType_set_metricName(metric, env, sm->metricName);
            if (sm->countersLen < 0 || sm->countersLen > MAX_SENSOR_COUNTERS) {
                logprintfl(EUCAERROR, "inconsistency in sensor database (countersLen=%d for %s:%s)\n", sm->countersLen, sr->resourceName,
                           sm->metricName);
                return (resource);
            }

            for (c = 0; c < sm->countersLen; c++) {
                sc = sm->counters + c;
                if ((counter = adb_metricCounterType_create(env)) == NULL) {
                    logprintfl(EUCAERROR, "failed to create metric counter for %s:%s:%s\n", sr->resourceName, sm->metricName,
                               sensor_type2str(sc->type));
                    return (resource);
                }

                adb_metricCounterType_set_type(counter, env, sensor_type2str(sc->type));
                adb_metricCounterType_set_collectionIntervalMs(counter, env, sc->collectionIntervalMs);
                if ((sc->dimensionsLen < 0) || (sc->dimensionsLen > MAX_SENSOR_DIMENSIONS)) {
                    logprintfl(EUCAERROR, "inconsistency in sensor database (dimensionsLen=%d for %s:%s:%s)\n", sc->dimensionsLen, sr->resourceName,
                               sm->metricName, sensor_type2str(sc->type));
                    return resource;
                }
                // First, sanity check the values. All dimensions must have same number of values.
                for (d = 0; d < sc->dimensionsLen; d++) {
                    sd = sc->dimensions + d;
                    if ((sd->valuesLen < 0) || (sd->valuesLen > MAX_SENSOR_VALUES)) {
                        logprintfl(EUCAERROR, "inconsistency in sensor database (valuesLen=%d is out of range for %s:%s:%s:%s)\n",
                                   sd->valuesLen, sr->resourceName, sm->metricName, sensor_type2str(sc->type), sd->dimensionName);
                        return (resource);
                    }

                    if (d == 0) {
                        num_values = sd->valuesLen;
                    } else {
                        if (num_values != sd->valuesLen) {
                            logprintfl(EUCAERROR,
                                       "inconsistency in sensor database (valuesLen=%d is not consistent across dimensions for %s:%s:%s)\n",
                                       sd->valuesLen, sr->resourceName, sm->metricName, sensor_type2str(sc->type));
                        }
                    }
                }

                // no measurements to include
                if (num_values == 0)
                    continue;

                // If requested history_size is smaller than the number of values in each array,
                // we need to select the batch of latest values of size history_size and adjust
                // the sequence number accordingly.
                if ((batch_size = num_values) > history_size) {
                    // have more values that the requested history
                    batch_size = history_size;
                }
                // index of first value in each dimension's array that we are using
                array_offset = num_values - batch_size;
                adb_metricCounterType_set_sequenceNum(counter, env, sc->sequenceNum + array_offset);

                for (d = 0; d < sc->dimensionsLen; d++) {
                    sd = sc->dimensions + d;
                    if ((dimension = adb_metricDimensionsType_create(env)) == NULL) {
                        logprintfl(EUCAERROR, "failed to create metric dimension type for %s:%s:%s:%s\n", sr->resourceName, sm->metricName,
                                   sensor_type2str(sc->type), sd->dimensionName);
                        return (resource);
                    }

                    adb_metricDimensionsType_set_dimensionName(dimension, env, sd->dimensionName);
                    for (v = array_offset; v < sd->valuesLen; v++) {
                        v_adj = (sd->firstValueIndex + v) % MAX_SENSOR_VALUES;
                        sv = sd->values + v_adj;
                        if ((value = adb_metricDimensionsValuesType_create(env)) == NULL) {
                            logprintfl(EUCAERROR, "failed to create metric dimension value for %s:%s:%s:%s\n", sr->resourceName, sm->metricName,
                                       sensor_type2str(sc->type), sd->dimensionName);
                            return (resource);
                        }

                        ts = unixms_to_datetime(env, sv->timestampMs);
                        adb_metricDimensionsValuesType_set_timestamp(value, env, ts);
                        if (sv->available) {
                            val = sv->value + sd->shift_value;
                            if (val < 0) {
                                logprintfl(EUCAERROR, "negative value in sensor database (%d for %s:%s:%s:%s)\n",
                                           sd->valuesLen, sr->resourceName, sm->metricName, sensor_type2str(sc->type), sd->dimensionName);
                            } else {
                                adb_metricDimensionsValuesType_set_value(value, env, val);
                            }

                            if (v == (sd->valuesLen - 1)) {
                                // last value
                                logprintfl(EUCATRACE, "sending sensor value [%d of %d] %s:%s:%s:%s %05lld %014lld %s %f\n",
                                           batch_size, num_values,
                                           sr->resourceName, sm->metricName, sensor_type2str(sc->type), sd->dimensionName, sc->sequenceNum + v,
                                           sv->timestampMs, sv->available ? "YES" : " NO", sv->available ? val : -1);
                            }
                        }

                        adb_metricDimensionsType_add_values(dimension, env, value);
                        total_num_values++;
                    }

                    adb_metricCounterType_add_dimensions(counter, env, dimension);
                    total_num_dimensions++;
                }

                adb_metricsResourceType_add_counters(metric, env, counter);
                total_num_counters++;
            }

            adb_sensorsResourceType_add_metrics(resource, env, metric);
            total_num_metrics++;
        }
    }

    logprintfl(EUCATRACE, "marshalled %d metrics %d counters %d dimensions %d sensor values\n",
               total_num_metrics, total_num_counters, total_num_dimensions, total_num_values);

    return (resource);
}

#endif /* ! _INCLUDE_ADB_HELPERS_H_ */
