/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) 2007 Manlio Perillo (manlio.perillo@gmail.com)
 * Copyright (C) 2010-2013 Phusion
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _PASSENGER_NGINX_MODULE_H_
#define _PASSENGER_NGINX_MODULE_H_

#include <ngx_config.h>
#include <ngx_core.h>
#include "common/AgentsStarter.h"
#include "common/ApplicationPool2/AppTypes.h"
#include "common/Utils/CachedFileStat.h"

/**
 * The Nginx version number as an integer.
 * For example, on nginx 1.7.30 this value is 1007030.
 */
#define NGINX_VERSION_NUM \
    (1000000 * PASSENGER_NGINX_MAJOR_VERSION + \
     1000   * PASSENGER_NGINX_MINOR_VERSION + \
     PASSENGER_NGINX_MICRO_VERSION)

extern ngx_module_t ngx_http_passenger_module;

/**
 * A static schema string to be assigned to Nginx 'upstream' strctures.
 */
extern ngx_str_t                passenger_schema_string;

extern ngx_str_t                passenger_placeholder_upstream_address;

/**
 * A CachedFileStat object used for caching stat() calls.
 */
extern PassengerCachedFileStat  *passenger_stat_cache;

extern PassengerAppTypeDetector *passenger_app_type_detector;

extern PSG_AgentsStarter        *passenger_agents_starter;

extern ngx_cycle_t              *passenger_current_cycle;

#endif /* _PASSENGER_NGINX_MODULE_H_ */

