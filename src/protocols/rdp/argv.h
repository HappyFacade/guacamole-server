/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef GUAC_RDP_ARGV_H
#define GUAC_RDP_ARGV_H

#include "config.h"

#include <guacamole/argv.h>

/**
 * The name of the connection parameter which contains the RDP domain.
 */
#define GUAC_RDP_ARGV_DOMAIN "domain"

/**
 * The name of the connection parameter which contains the RDP username.
 */
#define GUAC_RDP_ARGV_USERNAME "username"

/**
 * The name of the connection parameter which contains the RDP password.
 */
#define GUAC_RDP_ARGV_PASSWORD "password"

/**
 * Callback which populates the RDP credentials with the values submitted by
 * the user with "argv" instructions.
 */
guac_argv_callback guac_rdp_receive_credentials;

#endif

